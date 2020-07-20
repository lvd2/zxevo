#include "std.h"

#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "emul.h"
#include "vars.h"
#include "bass.h"
#include "snd_bass.h"
#include "gshle.h"
#include "gs.h"
#include "init.h"
#include "util.h"

#ifdef MOD_GSBASS
void GSHLE::reportError(const char *err, bool fatal)
{
   color(CONSCLR_ERROR);
   printf("BASS library reports error in %s\n", err);
   color(CONSCLR_ERRCODE);
   printf("error code is 0x%04X\n", BASS::ErrorGetCode());
   if(fatal)
   {
       exit();
   }
}

void GSHLE::runBASS()
{
   if(BASS::Initialized)
       return;

   if (BASS::Init(-1, conf.sound.fq, BASS_DEVICE_LATENCY, wnd, nullptr))
   {
      DWORD len = BASS::GetConfig(BASS_CONFIG_UPDATEPERIOD);
      BASS_INFO info;
      BASS::GetInfo(&info);
      BASS::SetConfig(BASS_CONFIG_BUFFER, len + info.minbuf);
      color(CONSCLR_HARDITEM);
      printf("BASS device latency is ");
      color(CONSCLR_HARDINFO);
      printf("%lums\n", len + info.minbuf);
   }
   else
   {
      color(CONSCLR_WARNING);
      reportError("warning: can't use default BASS device, trying silence\n", false);
      if (!BASS::Init(-2, 11025, 0, wnd, nullptr))
          errexit("can't init BASS");
   }

   BASS::Initialized = true;
   hmod = 0;
   for (int ch = 0; ch < 4; ch++)
       chan[ch].bass_ch = 0;

   DebugCh.bass_ch = 0;
}

void GSHLE::reset_sound()
{
  // runBASS();
  // BASS_Stop(); // todo: move to silent state?
}


DWORD CALLBACK gs_render(HSTREAM handle, void *buffer, DWORD length, void *user);

void GSHLE::initChannels()
{
   if (chan[0].bass_ch)
       return;
   for (int ch = 0; ch < 4; ch++)
   {
      chan[ch].bass_ch = BASS::StreamCreate(conf.sound.fq, 1, BASS_SAMPLE_8BITS, gs_render, &chan[ch]);
      if (!chan[ch].bass_ch)
          reportError("BASS_StreamCreate()");
   }

   DebugCh.bass_ch = BASS::StreamCreate(conf.sound.fq, 1, BASS_SAMPLE_8BITS, gs_render, &DebugCh);
   if(!DebugCh.bass_ch)
       reportError("BASS_StreamCreate()");
}

void GSHLE::setmodvol(unsigned vol)
{
   if (!hmod)
       return;
   runBASS();
   float v = (int(vol) * conf.sound.bass_vol) / float(8192 * 64);
   assert(v <= 1.0f);
   if (!BASS::ChannelSetAttribute(hmod, BASS_ATTRIB_VOL, v))
       reportError("BASS_ChannelSetAttribute() [music volume]");
}

void GSHLE::SetModSpeed()
{
// Функция не отлажена, неизвестно в каких программах данная команда используется
    if(!hmod)
        return;
    runBASS();

    // printf("%s, speed=%u\n", __FUNCTION__, speed);

    if(!BASS::ChannelSetAttribute(hmod, BASS_ATTRIB_MUSIC_SPEED, speed))
        reportError("BASS_ChannelSetAttribute() [music speed]");
}


void GSHLE::init_mod()
{
   runBASS();
   if (hmod)
       BASS::MusicFree(hmod);
   hmod = 0;
   hmod = BASS::MusicLoad(1, mod, 0, modsize, BASS_MUSIC_LOOP | BASS_MUSIC_POSRESET | BASS_MUSIC_RAMP, 0);
   if (!hmod)
       reportError("BASS_MusicLoad()", false);

   setmodvol(modvol); // Установка начальной громкости
}

void GSHLE::restart_mod(unsigned order, unsigned row)
{
   if (!hmod)
       return;
   SetModSpeed();
   if (!BASS::ChannelSetPosition(hmod, QWORD(MAKELONG(order,row)), BASS_POS_MUSIC_ORDER))
       reportError("BASS_ChannelSetPosition() [music]");
   if (!BASS::ChannelFlags(hmod, BASS_MUSIC_LOOP | BASS_MUSIC_POSRESET | BASS_MUSIC_RAMP, -1U))
       reportError("BASS_ChannelFlags() [music]");
   BASS::Start();
   if (!BASS::ChannelPlay(hmod, FALSE/*TRUE*/))
       reportError("BASS_ChannelPlay() [music]"); //molodcov_alex 0.36.2

   mod_playing = 1;
}

void GSHLE::resetmod()
{
   if (hmod)
       BASS::MusicFree(hmod);
   hmod = 0;
}

void GSHLE::resetfx()
{
   runBASS();
   for (int i = 0; i < 4; i++)
   {
       if (chan[i].bass_ch)
       {
         BASS::StreamFree(chan[i].bass_ch);
         chan[i].bass_ch = 0;
       }
   }
}

DWORD GSHLE::modgetpos()
{
   runBASS();
   return (DWORD)BASS::ChannelGetPosition(hmod, BASS_POS_MUSIC_ORDER);
//   return BASS_MusicGetOrderPosition(hmod);
}

void GSHLE::stop_mod()
{
   runBASS();
   if (!hmod)
       return;
   if(BASS::ChannelIsActive(hmod) != BASS_ACTIVE_PLAYING)
       return;
   if (!BASS::ChannelPause(hmod))
       reportError("BASS_ChannelPause() [music]");
}

void GSHLE::cont_mod()
{
   runBASS();
   if (!hmod)
       return;
   if (!BASS::ChannelPlay(hmod, TRUE))
       reportError("BASS_ChannelPlay() [music]");
}

void GSHLE::startfx(CHANNEL *ch, float pan)
{
   initChannels();

   float vol = (int(ch->volume) * conf.sound.gs_vol) / float(8192*64);
   assert(vol <= 1.0f);

   if(BASS::ChannelIsActive(ch->bass_ch) == BASS_ACTIVE_PLAYING)
   {
       if(!BASS::ChannelStop(ch->bass_ch))
           reportError("BASS_ChannelStop()");
   }

   if (!BASS::ChannelSetAttribute(ch->bass_ch, BASS_ATTRIB_VOL, vol))
       reportError("BASS_ChannelSetAttribute() [vol]");
   if (!BASS::ChannelSetAttribute(ch->bass_ch, BASS_ATTRIB_FREQ, ch->freq))
       reportError("BASS_ChannelSetAttribute() [freq]");
   if (!BASS::ChannelSetAttribute(ch->bass_ch, BASS_ATTRIB_PAN, pan))
       reportError("BASS_ChannelSetAttribute() [pan]");

   {
       DWORD len = BASS::GetConfig(BASS_CONFIG_UPDATEPERIOD);
       BASS_INFO info;
       BASS::GetInfo(&info);
       BASS::SetConfig(BASS_CONFIG_BUFFER, len + info.minbuf);
   }
   if (!BASS::ChannelPlay(ch->bass_ch, FALSE))
       reportError("BASS_ChannelPlay()");
}

void GSHLE::flush_gs_frame()
{
   unsigned lvl;
   if (!hmod || (lvl = BASS::ChannelGetLevel(hmod)) == -1U) lvl = 0;

   gsleds[0].level = LOWORD(lvl) >> (15-4);
   gsleds[0].attrib = 0x0D;
   gsleds[1].level = HIWORD(lvl) >> (15-4);
   gsleds[1].attrib = 0x0D;

   for (int ch = 0; ch < 4; ch++)
   {
      if (chan[ch].bass_ch && (lvl = BASS::ChannelGetLevel(chan[ch].bass_ch)) != -1U)
      {
         lvl = max(HIWORD(lvl), LOWORD(lvl));
         lvl >>= (15-4);
      }
      else
         lvl = 0;
      gsleds[ch+2].level = lvl;
      gsleds[ch+2].attrib = 0x0F;
   }
}

void GSHLE::debug_note(unsigned i)
{
    if(BASS::ChannelIsActive(DebugCh.bass_ch) == BASS_ACTIVE_PLAYING)
    {
        if(!BASS::ChannelStop(DebugCh.bass_ch))
        {
            reportError("BASS_ChannelStop()");
        }
    }

    DebugCh.volume = sample[i].volume;
    DebugCh.ptr = 0;
    DebugCh.start = sample[i].start;
    DebugCh.loop = sample[i].loop;
    DebugCh.end = sample[i].end;
    unsigned note = sample[i].note;
    DebugCh.freq = note2rate[note];

    startfx(&DebugCh, 0);
}

void GSHLE::debug_save_note(unsigned i, const char *FileName)
{
    int f = open(FileName, O_CREAT | O_TRUNC | O_BINARY | O_WRONLY, S_IREAD | S_IWRITE);
    if(f >= 0)
    {
        write(f, sample[i].start, sample[i].end);
        close(f);
    }
}

void GSHLE::debug_save_mod(const char *FileName)
{
    int f = open(FileName, O_CREAT | O_TRUNC | O_BINARY | O_WRONLY, S_IREAD | S_IWRITE);
    if(f >= 0)
    {
        write(f, mod, modsize);
        close(f);
    }
}
#endif
