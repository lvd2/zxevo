#pragma once
extern int spkr_dig;
extern int mic_dig;
extern int covFB_vol;
extern int covDD_vol;
extern int sd_l;
extern int sd_r;

extern SNDRENDER sound;
extern SNDCHIP ay[2];
extern SNDCOUNTER sndcounter;

void apply_sound();
void restart_sound();
void flush_dig_snd();
void init_snd_frame();
void flush_snd_frame();
