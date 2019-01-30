#pragma once

extern const char *lastpage;

void setcheck(int ID, unsigned char state = 1);
unsigned char getcheck(int ID);
void setup_dlg();

void SaveModDlg(HWND dlg);
