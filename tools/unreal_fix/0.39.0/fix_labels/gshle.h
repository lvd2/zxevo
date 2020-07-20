#pragma once

struct GSHLE
{
   unsigned char gsstat;// command and data bits
   unsigned char gscmd;
   unsigned char busy;  // don't play fx
   unsigned char mod_playing;

   unsigned modvol, fxvol; // module and FX master volumes
   unsigned used;       // used memory
   unsigned char *mod; unsigned modsize; // for modplayer
   unsigned total_fx;      // samples loaded
   unsigned cur_fx;        // selected sample

   u8 speed;
   u8 tempo;

   unsigned char data_in[8];// data register
   unsigned char gstmp[8], *resptr; unsigned resmode; // from GS
   unsigned char *to_ptr; unsigned resmod2; // to GS

   unsigned char *streamstart; unsigned streamsize;

   // 0 - close, 1 - load module, 2 - load unsigned sample, 3 - load signed sample
   // 4 - covox
   unsigned char load_stream;

   unsigned char loadmod, loadfx; // leds flags

   unsigned char badgs[0x100]; // unrecognized commands
   float note2rate[0x100];

   struct SAMPLE {
      unsigned char *start; // Адрес начала сэмпла в памяти GS
      unsigned loop;
      unsigned end; // Размер сэмпла в байтах
      unsigned char volume, note;
      u8 Priority;
      u8 SeekFirst;
      u8 SeekLast;
      u8 FineTune;

      // GS0,1 - Левые
      // GS2,3 - Правые
      //     3210 - Номера каналов GS (используются в масках SeekFirst/SeekLast)
      //     ||||
      // 00001111
      //     ||||
      //     3241 - Номера каналов Amiga (используются внутри модулей)
   } sample[64];

   struct CHANNEL {
      unsigned char *start;
      unsigned loop, end, ptr;
      unsigned volume;
      float freq;
      u8 Priority;
      u8 FineTune;
      HSTREAM bass_ch;
      unsigned char busy;
   } chan[4];

   CHANNEL DebugCh; // Канал для проигрывания сэмплов из отладчика


   unsigned char in(unsigned char port);
   void out(unsigned char port, unsigned char byte);
   void reset();
   void reset_sound();
   void applyconfig();

   void set_busy(unsigned char newval);
   void start_fx(unsigned fx, unsigned chan, unsigned char vol, unsigned char note);
   void flush_gs_frame(); // calc volume values for leds

   HMUSIC hmod;

   void runBASS();
   void initChannels();
   void setmodvol(unsigned vol);
   void SetModSpeed();
   void init_mod();
   void restart_mod(unsigned order, unsigned row);
   void startfx(CHANNEL *ch, float pan);
   void resetmod();
   void resetfx();
   DWORD modgetpos();
   void stop_mod();
   void cont_mod();
   void debug_note(unsigned i);
   void debug_save_note(unsigned i, const char *FileName);
   void debug_save_mod(const char *FileName);

   void reportError(const char *err, bool fatal = false);
};
