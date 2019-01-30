#pragma once

extern char load_errors;

void addpath(char *dst, const char *fname = nullptr);
void load_ula_preset();
void save_nv();
void load_romset(CONFIG *conf, const char *romset);
void applyconfig(bool Init = true);
void load_config(const char *fname);
void autoload();
void load_ay_vols();
void load_ay_stereo();
void load_atm_font();
