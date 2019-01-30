#include "std.h"

#include "emul.h"
#include "vars.h"
#include "bass.h"
#include "snd_bass.h"
#include "gshle.h"
#include "gs.h"
#include "sndrender/sndcounter.h"
#include "sound.h"
#include "util.h"

#ifdef MOD_GSBASS
void GSHLE::set_busy(unsigned char newval)
{
   busy = chan[0].busy = chan[1].busy = chan[2].busy = chan[3].busy = newval;
}

void GSHLE::reset()
{
//    printf("%s, speed=6\n", __FUNCTION__);
   fxvol = modvol = 0x3F;
   speed = 6;
   make_gs_volume(fxvol);
   to_ptr = data_in; mod_playing = 0;
   used = 0; mod = nullptr; modsize = 0; set_busy(0);
   resetmod(); total_fx = 1;
   memset(sample, 0, sizeof sample);
   memset(chan,  0, sizeof chan);
   memset(&DebugCh, 0, sizeof(DebugCh));
   out(0xBB, 0x23); // send 'get pages' command
}

void GSHLE::applyconfig()
{
    // Пересчет нот в герцы для равномерно темперированного строя
    // https://ru.wikipedia.org/wiki/Равномерно_темперированный_строй
    // f = f0 * 2^(i/12)
    // f0 = 440Hz (A4) - Базовая частота (i=0)
    // Нота | Индекс степени | Нота GS
    // -----+----------------+---------
    // C0:  | i=-9-4*12=-57  | 0
    // C1:  | i=-9-3*12=-45  | 12
    // C2:  | i=-9-2*12=-33  | 24
    // C3:  | i=-9-1*12=-21  | 36
    // C4:  | i=-9+0*12=-9   | 48
    // C5:  | i=-9+1*12=3    | 60 // Этой ноте соответствует стандартная скорость проигрывания 214 периодов генератора на Amiga
    // C6:  | i=-9+2*12=15   | 72
    // C7:  | i=-9+3*12=27   | 84


    // Расчет частот всех нот
    int i;
    for(i = -57; i <= 27; i++)
    {
        note2rate[i + 57] = float(440.0 * pow(2.0, double(i) / 12.0));
    }
    for(; i + 57 < int(_countof(note2rate)); i++)
    {
        note2rate[i + 57] = note2rate[57+27];
    }

    const double C5 = double(note2rate[60]);

    // Пеерсчет частот в sample rate относительно стандартной ноты C5 с индексом 60
    for(i = 0; i < int(_countof(note2rate)); i++)
    {
        // 7093789.2 / 2 - clock rate PAL Amiga
        // 214.0 (периодов внутреннего генератора) - С3 на Amiga (соответствует C5 на GS)
        note2rate[i] *= float(7093789.2 / (2.0 * 214.0 * C5));
    }
    setmodvol(modvol);
}

unsigned char GSHLE::in(unsigned char port)
{
   if (port == 0xBB) return gsstat;
   if (!resptr) return 0xFF; // no data available
   unsigned char byte = *resptr;
   if(resmode)
   {
       resptr++;
       resmode--;
   } // goto next byte
   return byte;
}

void GSHLE::out(unsigned char port, unsigned char byte)
{
   if (port == 0xB3) {
      if (!load_stream) {
         *to_ptr = byte;
         if(resmod2)
         {
             to_ptr++;
             resmod2--;
         }
         if (!resmod2) {
            if ((gscmd & 0xF8) == 0x88) start_fx(data_in[0], gscmd & 3, 0xFF, data_in[1]);
            if ((gscmd & 0xF8) == 0x90) start_fx(data_in[0], gscmd & 3, data_in[1], 0xFF);
            if ((gscmd & 0xF8) == 0x98) start_fx(data_in[0], gscmd & 3, data_in[2], data_in[1]);
            to_ptr = data_in;
         }
      } else {
         if (load_stream == 4) { // covox
            flush_dig_snd();
            covFB_vol = byte*conf.sound.gs_vol/0x100;
            return;
         }
         streamstart[streamsize++] = byte;
         if (load_stream == 1) loadmod = 1;
         else loadfx = u8(cur_fx);
      }
      return;
   }
   // else command
   unsigned i;
   gsstat = 0x7E; resmode = 0; // default - 1 byte ready
   resptr = gstmp; to_ptr = data_in; resmod2 = 0;
   gscmd = byte;
   if (load_stream == 4) load_stream = 0; // close covox mode
   switch (byte) {
      case 0x0E: // LPT covox
         load_stream = 4;
         break;
      case 0xF3: case 0xF4: // reset
         reset_gs();
         break;
      case 0xF5:
         set_busy(1); break;
      case 0xF6:
         set_busy(0); break;
      case 0x20: // get total memory
         *(unsigned*)gstmp = conf.gs_ramsize*1024-32768-16384;
         resmode = 2; gsstat = 0xFE;
         break;
      case 0x21: // get free memory
         *(unsigned*)gstmp = (conf.gs_ramsize*1024-32768-16384) - used;
         resmode = 2; gsstat = 0xFE;
         break;
      case 0x23: // get pages
         *gstmp = u8(((conf.gs_ramsize*1024)/32768)-1);
          gsstat = 0xFE;
         break;
      case 0x2A: // set module vol
      case 0x35:
         *gstmp = u8(modvol);
         modvol = *data_in;
         setmodvol(modvol);
         break;
      case 0x2B: // set FX vol
      case 0x3D:
         *gstmp = u8(fxvol);
         fxvol = *data_in;
         make_gs_volume(fxvol);
         break;
      case 0x2E: // set FX
          // printf("%u: %s, set fx = %u\n", unsigned(rdtsc()), __FUNCTION__, *data_in);
          if(*data_in == 0)
          { // COM_H.a80, COM2E
              cur_fx = total_fx - 1;
          }
          else
          {
              if(*data_in > total_fx - 1)
              {
                  cur_fx = 0;
              }
              else
              {
                  cur_fx = *data_in;
              }
          }
         break;
      case 0x30: // load MOD
         resetmod();
         streamstart = mod = GSRAM_M + used;
         streamsize = 0;
         *gstmp = 1; load_stream = 1;
         break;
      case 0x31: // play MOD
         restart_mod(0,0);
         break;
      case 0x32: // stop MOD
         mod_playing = 0;
         stop_mod();
         break;
      case 0x33: // continue MOD
         if (mod)
         {
             mod_playing = 1;
             cont_mod();
         }
         break;
      case 0x36: // data = #FF
         *gstmp = 0xFF;
         break;
      case 0x38: // load FX (unsigned samples)
      case 0x3E: // (signed samples)
          if(total_fx >= 64)
          {
              cur_fx = 0; // COM_H.a80, COM38_9
              break;
          }
         cur_fx = *gstmp = total_fx;
         load_stream = (byte == 0x38) ? 2 : 3;
         streamstart = GSRAM_M + used;
         sample[total_fx].start = streamstart;
         streamsize = 0;
         break;
      case 0x39: // play FX
          // printf("%u: %s, start fx = %u\n", unsigned(rdtsc()), __FUNCTION__, *data_in);
         start_fx(*data_in, 0xFF, 0xFF, 0xFF);
         break;
      case 0x3A: // stop fx
          // printf("%u: %s, stop fx = %u\n", unsigned(rdtsc()), __FUNCTION__, *data_in);
          for(i = 0; i < 4; i++)
          {
              if(*data_in & (1 << i))
              {
                  chan[i].start = nullptr;
              }
          }
         break;
      case 0x40: // set note
          if(cur_fx == 0)
          {
              break;
          }
         sample[cur_fx].note = *data_in <= 95 ? *data_in : 95;
         break;
      case 0x41: // set vol
         sample[cur_fx].volume = *data_in;
         break;
      case 0x42: // Set FX Sample Finetune
          sample[cur_fx].FineTune = *data_in;
          break;
      case 0x45: // set fx priority
          sample[cur_fx].Priority = *data_in;
          break;
      case 0x46: // Set FX Sample Seek First parameter
          sample[cur_fx].SeekFirst = *data_in;
          break;
      case 0x47: // Set FX Sample Seek Last parameter
          sample[cur_fx].SeekLast = *data_in;
          break;
      case 0x48: // set loop start
         resmod2 = 2;
         *(unsigned char*)&sample[cur_fx].loop = *data_in;
         to_ptr = 1+(unsigned char*)&sample[cur_fx].loop;
         break;
      case 0x49: // set loop end
         resmod2 = 2;
         *(unsigned char*)&sample[cur_fx].end = *data_in;
         to_ptr = 1+(unsigned char*)&sample[cur_fx].end;
         break;
      case 0x60: // get song pos
         *gstmp = (unsigned char)modgetpos();
         break;
      case 0x61: // get pattern pos
         *gstmp = (unsigned char)(modgetpos() >> 16);
         break;
      case 0x62: // get mixed pos
         i = modgetpos();
         *gstmp = u8(((i>>16) & 0x3F) | (i << 6));
         break;
      case 0x63: // get module notes
        resmode = 3; gsstat = 0xFE;
        break;
      case 0x64: // get module vols
        *(unsigned*)gstmp = 0;
        resmode = 3; gsstat = 0xFE;
        break;
     case 0x65: // jmp to pos
        restart_mod(*data_in,0);
        break;
     case 0x66: // Set speed/tempo
         if(*data_in <= 0x1F)
         {
             speed = *data_in;
             //printf("%s, speed=%u\n", __FUNCTION__, speed);
             SetModSpeed();
         }
         else
         {
             tempo = *data_in;
         }
         break;
     case 0x67:
         // Get speed value
         *gstmp = speed;
         break;
     case 0x68: // Get tempo value
         *gstmp = tempo;
         break;
     case 0x80: // direct play 1
     case 0x81:
     case 0x82:
     case 0x83:
        start_fx(*data_in, byte & 3, 0xFF, 0xFF);
        break;
     case 0x88: // direct play 2
     case 0x89:
     case 0x8A:
     case 0x8B:
     case 0x90: // direct play 3
     case 0x91:
     case 0x92:
     case 0x93:
        resmod2 = 1; to_ptr++;
        break;
     case 0x98: // direct play 4
     case 0x99:
     case 0x9A:
     case 0x9B:
        resmod2 = 2; to_ptr++;
        break;

      case 0xD2: // close stream
         if (!load_stream) break;
         // bug?? command #3E loads unsigned samples (REX 1,2)
//         if (load_stream == 3) // unsigned sample -> convert to unsigned
//            for (unsigned ptr = 0; ptr < streamsize; sample[total_fx].start[ptr++] ^= 0x80);
         if(load_stream == 1)
         {
             modsize = streamsize;
             init_mod();
         }
         else {
            sample[total_fx].end = streamsize;
            sample[total_fx].loop = 0xFFFFFF;
            sample[total_fx].volume = 0x40;
            sample[total_fx].note = 60;
            sample[total_fx].Priority = 0x80;
            sample[total_fx].SeekFirst = 0x0F;
            sample[total_fx].SeekLast = 0x0F;
            sample[total_fx].FineTune = 0;
            //{char fn[200];sprintf(fn,"s-%d.raw",total_fx); FILE*ff=fopen(fn,"wb");fwrite(sample[total_fx].start,1,streamsize,ff);fclose(ff);}
            total_fx++;
         }
         used += streamsize;
         load_stream = 0;
         break;

      case 0x00: // reset flags - already done
      case 0x08:
      case 0xD1: // start stream
         break;
      default:
         badgs[byte] = 1;
         break;
   }
}

void GSHLE::start_fx(unsigned fx, unsigned ch, unsigned char vol, unsigned char note)
{  
   unsigned i; //Alone Coder 0.36.7
   if (!fx) fx = cur_fx; // fx=0 - use default
   if (vol == 0xFF) vol = sample[fx].volume;
   if (note == 0xFF) note = sample[fx].note;
   if(ch == 0xFF) // find free channel
   {
       unsigned SeekFirst = sample[fx].SeekFirst;
       for(/*unsigned*/ i = 0; i < 4; i++)
       {
           if((SeekFirst & (1 << i)) && !chan[i].start)
           {
               ch = i;
           }
       }

       if(ch == 0xFF)
       {
           unsigned SeekLast = sample[fx].SeekLast;
           for(i = 0; i < 4; i++)
           {
               if((SeekLast & (1 << i)) && !chan[i].start)
               {
                   ch = i;
               }
           }
       }

       if(ch == 0xFF)
       { // Обработка приоритетов
           unsigned SeekLast = sample[fx].SeekLast;
           unsigned MinPrio = 0xFF;
           unsigned MinPrioIdx = 0xFF;
           for(i = 0; i < 4; i++)
           {
               if((SeekLast & (1 << i)) && (chan[i].Priority < MinPrio))
               {
                   MinPrio = chan[i].Priority;
                   MinPrioIdx = i;
               }
           }

           if(MinPrioIdx == 0xFF)
           {
               return;
           }

           if(sample[fx].Priority >= MinPrio)
           {
               ch = MinPrioIdx;
           }
       }
   }

   if(ch == 0xFF) // Подходящий свободный канал не найден
   {
       return;
   }
   chan[ch].volume = vol;
   chan[ch].start = sample[fx].start;
   chan[ch].loop = sample[fx].loop;
   chan[ch].end = sample[fx].end;
   chan[ch].Priority = sample[fx].Priority;
   chan[ch].FineTune = sample[fx].FineTune;
   chan[ch].ptr = 0;
   chan[ch].freq = note2rate[note];
   // ch0,1 - left, ch2,3 - right
   startfx(&chan[ch], (ch & 2)? 1.0f : -1.0f);
}

DWORD CALLBACK gs_render(HSTREAM handle, void *buffer, DWORD length, void *user);

DWORD CALLBACK gs_render(HSTREAM handle, void *buffer, DWORD length, void *user)
{
    (void)handle;

   GSHLE::CHANNEL *ch = (GSHLE::CHANNEL*)user;

   if (!ch->start)
       return BASS_STREAMPROC_END;
   if (ch->busy)
   {
       memset(buffer, 0, length);
       return length;
   }
   for (unsigned i = 0; i < length; i++)
   {
      ((BYTE*)buffer)[i] = ch->start[ch->ptr++];
      if (ch->ptr >= ch->end)
      {
         if (ch->end < ch->loop)
         {
             ch->start = nullptr;
             return i + BASS_STREAMPROC_END;
         }
         else
             ch->ptr = ch->loop;
      }
   }
   return length;
}
#endif
