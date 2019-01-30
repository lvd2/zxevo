#include "std.h"

#include "resource.h"
#include "emul.h"
#include "vars.h"
#include "debug.h"
#include "dbgpaint.h"
#include "dbgoth.h"
#include "gui.h"
#include "fdd.h"
#include "util.h"

namespace z80dbg
{
__int64 __cdecl delta();
__int64 __cdecl delta()
{
    return comp.t_states + cpu.t - cpu.debug_last_t;
}
}

void show_time()
{
   Z80 &cpu = CpuMgr.Cpu();
   tprint(time_x, time_y, "time delta:", W_OTHEROFF);
   char text[32];
   sprintf(text, "%14I64d", cpu.Delta());
   tprint(time_x+11, time_y, text, W_OTHER);
   tprint(time_x+25, time_y, "t", W_OTHEROFF);
   frame(time_x, time_y, 26, 1, FRAME);
}

static void wtline(const char *name, unsigned ptr, unsigned y)
{
   char line[40];
   if(name)
       sprintf(line, "%3s: ", name);
   else
       sprintf(line, "%04X ", ptr);

   Z80 &cpu = CpuMgr.Cpu();
   for (unsigned dx = 0; dx < 8; dx++)
   {
      unsigned char c = cpu.DirectRm(ptr++);
      sprintf(line+5+3*dx, "%02X", c);
      line[7+3*dx] = ' ';
      line[29+dx] = char(c ? c : '.');
   }

   line[37] = 0;
   tprint(wat_x, wat_y+y, line, W_OTHER);
}

void showwatch()
{
   if (show_scrshot)
   {
      for (unsigned y = 0; y < wat_sz; y++)
         for (unsigned x = 0; x < 37; x++)
            txtscr[80*30 +  (wat_y+y)*80 + (wat_x+x)] = 0xFF;
   }
   else 
   {
      Z80 &cpu = CpuMgr.Cpu();
      wtline("PC", cpu.pc, 0);
      wtline("SP", cpu.sp, 1);
      wtline("BC", cpu.bc, 2);
      wtline("DE", cpu.de, 3);
      wtline("HL", cpu.hl, 4);
      wtline("IX", cpu.ix, 5);
      wtline("IY", cpu.iy, 6);
      wtline("BC'", cpu.alt.bc, 7);
      wtline("DE'", cpu.alt.de, 8);
      wtline("HL'", cpu.alt.hl, 9);
      wtline(nullptr, user_watches[0], 10);
      wtline(nullptr, user_watches[1], 11);
      wtline(nullptr, user_watches[2], 12);
   }
   const char *text = "watches";
   if (show_scrshot == 1) text = "screen memory";
   if (show_scrshot == 2) text = "ray-painted";
   tprint(wat_x, wat_y-1, text, W_TITLE);
   if(comp.flags & CF_DOSPORTS)
       tprint(wat_x+34, wat_y-1, "DOS", W_DOS);
   frame(wat_x,wat_y,37,wat_sz,FRAME);
}

void mon_setwatch()
{
   if (show_scrshot) show_scrshot = 0;
   for (unsigned i = 0; i < 3; i++) {
      debugscr();
      int addr = input4(wat_x, wat_y+wat_sz-3+i, user_watches[i]);
      if (addr == -1) return;
      user_watches[i] = unsigned(addr);
   }
}

void showstack()
{
   Z80 &cpu = CpuMgr.Cpu();
   for (unsigned i = 0; i < stack_size; i++)
   {
      char xx[10]; //-2:1234
                   //SP:1234
                   //+2:
      if (!i) *(unsigned*)xx = WORD2('-','2');
      else if (i==1) *(unsigned*)xx = WORD2('S','P');
      else sprintf(xx, (i > 8) ? "%X" : "+%X", (i-1)*2);
      sprintf(xx+2, ":%02X%02X", cpu.DirectRm(cpu.sp+(i-1)*2+1), cpu.DirectRm(cpu.sp+(i-1)*2));
      tprint(stack_x, stack_y+i, xx, W_OTHER);
   }
   tprint(stack_x, stack_y-1, "stack", W_TITLE);
   frame(stack_x, stack_y, 7, stack_size, FRAME);
}

void show_ay()
{
   if (!conf.sound.ay_scheme) return;
   const char *ayn = comp.active_ay ? "AY1" : "AY0";
   if(conf.sound.ay_scheme < AY_SCHEME_QUADRO)
   {
       ayn = "AY:";
       comp.active_ay = 0;
   }
   tprint(ay_x-3, ay_y, ayn, W_TITLE);
   SNDCHIP *chip = &ay[comp.active_ay];
   char line[32];
   for (unsigned i = 0; i < 16; i++) {
      line[0] = "0123456789ABCDEF"[i]; line[1] = 0;
      tprint(ay_x + i*3, ay_y, line, W_AYNUM);
      sprintf(line, "%02X", chip->get_reg(i));
      tprint(unsigned(ay_x + i*3 + 1), unsigned(ay_y), line, i == (chip->get_activereg()) ? W_AYON : W_AYOFF);
   }
   frame(ay_x, ay_y, 48, 1, FRAME);
}

void mon_switchay()
{
   comp.active_ay ^= 1;
}

void __cdecl BankNames(int i, char *Name)
{
    unsigned rom_bank;
    unsigned ram_bank;

    bool IsRam = (RAM_BASE_M <= bankr[i]) && (bankr[i] < RAM_BASE_M + PAGE * MAX_RAM_PAGES);
    bool IsRom = (ROM_BASE_M <= bankr[i]) && (bankr[i] < ROM_BASE_M + PAGE * MAX_ROM_PAGES);

    if(IsRam)
        ram_bank = ULONG((bankr[i] - RAM_BASE_M)/PAGE);

    if(IsRom)
        rom_bank = ULONG((bankr[i] - ROM_BASE_M)/PAGE);

    if (IsRam)
        sprintf(Name, "RAM%2X", ram_bank);

    if (IsRom)
        sprintf(Name, "ROM%2X", rom_bank);

    if (bankr[i] == base_sos_rom)
        strcpy(Name, "BASIC");
    if (bankr[i] == base_dos_rom)
        strcpy(Name, "TRDOS");
    if (bankr[i] == base_128_rom)
        strcpy(Name, "B128K");
    if (bankr[i] == base_sys_rom && (conf.mem_model == MM_PROFSCORP || conf.mem_model == MM_SCORP))
        strcpy(Name, "SVM  ");
    if ((conf.mem_model == MM_PROFSCORP || conf.mem_model == MM_SCORP) && IsRom && rom_bank > 3)
        sprintf(Name, "ROM%2X", rom_bank);

    if (bankr[i] == CACHE_M)
        strcpy(Name, (conf.cache!=32)?"CACHE":"CACH0");
    if (bankr[i] == CACHE_M+PAGE)
        strcpy(Name, "CACH1");
}

void showbanks()
{
   Z80 &cpu = CpuMgr.Cpu();
   for (int i = 0; i < 4; i++)
   {
      char ln[64]; sprintf(ln, "%d:", i);
      tprint(unsigned(banks_x), unsigned(banks_y+i+1), ln, W_OTHEROFF);
      strcpy(ln, "?????");
      cpu.BankNames(i, ln);
      tprint(unsigned(banks_x+2), unsigned(banks_y+i+1), ln, bankr[i]!=bankw[i] ? W_BANKRO : W_BANK);
   }
   frame(banks_x, banks_y+1, 7, 4, FRAME);
   tprint(banks_x, banks_y, "pages", W_TITLE);
}

void showports()
{
   char ln[64];
   sprintf(ln, "  FE:%02X", comp.pFE);
   tprint(ports_x, ports_y, ln, W_OTHER);
   sprintf(ln, "7FFD:%02X", comp.p7FFD);
   tprint(ports_x, ports_y+1, ln, (comp.p7FFD & 0x20) && 
   !((conf.mem_model == MM_PENTAGON && conf.ramsize == 1024) ||
     (conf.mem_model == MM_PROFI && (comp.pDFFD & 0x10))) ? W_48K : W_OTHER);

   switch (conf.mem_model)
   {
      case MM_KAY:
      case MM_SCORP:
      case MM_PROFSCORP:
      case MM_PLUS3:
         dbg_extport = 0x1FFD; dbg_extval = comp.p1FFD;
      break;
      case MM_PROFI:
         dbg_extport = 0xDFFD; dbg_extval = comp.pDFFD;
      break;
      case MM_ATM450:
         dbg_extport = 0xFDFD; dbg_extval = comp.pFDFD;
      break;
      case MM_ATM710:
      case MM_ATM3:
         dbg_extport = (comp.aFF77 & 0xFFFF);
         dbg_extval = comp.pFF77;
      break;
      case MM_QUORUM:
         dbg_extport = 0x0000; dbg_extval = comp.p00;
      break;
      default:
         dbg_extport = -1U;
   }
   if (dbg_extport != -1U)
       sprintf(ln, "%04X:%02X", dbg_extport, dbg_extval);
   else
       sprintf(ln, "cmos:%02X", comp.cmos_addr);
   tprint(ports_x, ports_y+2, ln, W_OTHER);

   sprintf(ln, "EFF7:%02X", comp.pEFF7);
   tprint(ports_x, ports_y+3, ln, W_OTHER);
   frame(ports_x, ports_y, 7, 4, FRAME);
   tprint(ports_x, ports_y-1, "ports", W_TITLE);
}

void showdos()
{
//    CD:802E
//    STAT:24
//    SECT:00
//    T:00/01
//    S:00/00
//[vv]   if (conf.trdos_present) comp.wd.process();
   char ln[64]; unsigned char atr = conf.trdos_present ? W_OTHER : W_OTHEROFF;
   sprintf(ln, "CD:%02X%02X", comp.wd.cmd, comp.wd.data);
   tprint(dos_x, dos_y, ln, atr);
   sprintf(ln, "STAT:%02X", comp.wd.RdStatus());
   tprint(dos_x, dos_y+1, ln, atr);
   sprintf(ln, "SECT:%02X", comp.wd.sector);
   tprint(dos_x, dos_y+2, ln, atr);
   sprintf(ln, "T:%02X/%02X", comp.wd.seldrive->track, comp.wd.track);
   tprint(dos_x, dos_y+3, ln, atr);
   sprintf(ln, "S:%02X/%02X", comp.wd.system, comp.wd.rqs);
   tprint(dos_x, dos_y+4, ln, atr);
   frame(dos_x, dos_y, 7, 5, FRAME);
#if 1
   tprint(dos_x, dos_y-1, "beta128", W_TITLE);
#else
   sprintf(ln, "%X-%X %d", comp.wd.state, comp.wd.state2, comp.wd.seldrive->track);
   tprint(dos_x,dos_y-1, ln, atr);
#endif
/*
//    STAT:00101010
//    CMD:80,STA:2A
//    DAT:22,SYS:EE
//    TRK:31,SEC:01
//    DISK:A,SIDE:0

   char ln[64]; unsigned char atr = conf.trdos_present ? 0x20 : 0x27;
   sprintf(ln, "STAT:00000000"); unsigned char stat = in_trdos(0x1F);
   for (int i = 0; i < 7; i++) ln[i+5] = (stat & (0x80 >> i)) ? '1':'0';
   tprint(dos_x, dos_y+1, ln, atr);
   sprintf(ln, "CMD:%02X,STA:%02X", comp.trdos.cmd, stat);
   tprint(dos_x, dos_y+2, ln, atr);
   sprintf(ln, "DAT:%02X,SYS:%02X", comp.trdos.data, in_trdos(0xFF));
   tprint(dos_x, dos_y+3, ln, atr);
   sprintf(ln, "TRK:%02X,SEC:%02X", comp.trdos.track, comp.trdos.sector);
   tprint(dos_x, dos_y+4, ln, atr);
   sprintf(ln, "DISK:%c,SIDE:%c", 'A'+(comp.trdos.system & 3), (comp.trdos.system & 0x10) ? '0':'1');
   tprint(dos_x, dos_y+5, ln, atr);
   frame(dos_x, dos_y+1, 13, 5, FRAME);
   tprint(dos_x, dos_y, "beta128", 0x83);
*/
}

#ifdef MOD_GSBASS
static INT_PTR CALLBACK gsdlg(HWND dlg, UINT msg, WPARAM wp, LPARAM lp)
{
    (void)lp;

    char tmp[0x200];
    unsigned i; //Alone Coder 0.36.7
    HWND lv = GetDlgItem(dlg, IDC_GSLIST);

    if(msg == WM_INITDIALOG)
    {
        ListView_SetExtendedListViewStyleEx(lv, LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);
        LVCOLUMN Col = { };

        static const char *Cols[] = { "", "smp", "v", "n", "p", "f", "l" };
        static const int Width[] = { 30, 100, 40, 40, 40, 70, 70 };

        Col.mask = LVCF_TEXT | LVCF_WIDTH;

        for(i = 0; i < _countof(Cols); i++)
        {
            Col.pszText = LPSTR(Cols[i]);
            Col.cx = Width[i];
            ListView_InsertColumn(lv, i, &Col);
        }

        if(gs.modsize)
        {
            sprintf(tmp, "(%s)", gs.mod_playing ? "P" : "S");
            LVITEM Item = { };
            Item.mask = LVIF_TEXT;
            Item.iItem = 0;
            Item.iSubItem = 0;
            Item.pszText = tmp;
            ListView_InsertItem(lv, &Item);

            sprintf(tmp, "%.20s", gs.mod);
            tmp[20] = 0;
            Item.iSubItem++;
            Item.pszText = tmp;
            ListView_SetItem(lv, &Item);
        }
        for(i = 1; i < gs.total_fx; i++)
        {
            sprintf(tmp, "%s%s", gs.cur_fx == i ? "*" : "", gs.sample[i].loop < gs.sample[i].end ? "(L)" : "");
            LVITEM Item = { };
            Item.mask = LVIF_TEXT;
            Item.iItem = int(i);
            Item.iSubItem = 0;
            Item.pszText = tmp;
            ListView_InsertItem(lv, &Item);

            sprintf(tmp, "%u", i);
            Item.iSubItem++;
            ListView_SetItem(lv, &Item);

            sprintf(tmp, "%u", unsigned(gs.sample[i].volume));
            Item.iSubItem++;
            ListView_SetItem(lv, &Item);

            sprintf(tmp, "%u", unsigned(gs.sample[i].note));
            Item.iSubItem++;
            ListView_SetItem(lv, &Item);

            sprintf(tmp, "%u", unsigned(gs.sample[i].Priority));
            Item.iSubItem++;
            ListView_SetItem(lv, &Item);

            sprintf(tmp, "%.2f", double(gs.note2rate[gs.sample[i].note]));
            Item.iSubItem++;
            ListView_SetItem(lv, &Item);

            sprintf(tmp, "%u", gs.sample[i].end);
            Item.iSubItem++;
            ListView_SetItem(lv, &Item);
        }
        int Sel = ListView_GetItemCount(lv);
        if(Sel > 0)
        {
            LVITEM Item = { };
            Item.stateMask = LVIS_SELECTED;
            Item.state = LVIS_SELECTED;
            SendMessage(lv, LVM_SETITEMSTATE, WPARAM(0), LPARAM(&Item));
            SetFocus(lv);
        }

        *tmp = 0;
        for(i = 0; i < 0x100; i++)
        {
            if(gs.badgs[i])
            {
                sprintf(tmp + strlen(tmp), "%02X ", i);
            }
        }
        Edit_SetText(GetDlgItem(dlg, IDE_GS), tmp);

        return Sel ? FALSE : TRUE;
    }

    if(msg == WM_SYSCOMMAND && (wp & 0xFFF0) == SC_CLOSE)
    {
        EndDialog(dlg, 0);
    }

    unsigned id;
    unsigned nc;

    switch(msg)
    {
    case WM_NOTIFY:
        {
            LPNMHDR Hdr = LPNMHDR(lp);
            id = unsigned(Hdr->idFrom);
            nc = Hdr->code;
        }
        break;

    case WM_COMMAND:
        id = LOWORD(wp);
        nc = HIWORD(wp);
        break;

    default:
        return FALSE;
    }

    if((id == IDCANCEL || id == IDOK) && (nc == BN_CLICKED))
    {
        EndDialog(dlg, 0);
    }

    if((id == IDB_GS_CLEAR) && (nc == BN_CLICKED))
    {
        memset(gs.badgs, 0, sizeof gs.badgs);
        Edit_SetText(GetDlgItem(dlg, IDE_GS), "");
        return TRUE;
    }

    if((id == IDB_GS_RESET) && (nc == BN_CLICKED))
    {
        gs.reset();
        ListView_DeleteAllItems(lv);
        return TRUE;
    }

    if(((id == IDB_GS_PLAY) && (nc == BN_CLICKED)) || ((id == IDC_GSLIST) && (nc == NM_DBLCLK)))
    {
        unsigned i = unsigned(ListView_GetSelectionMark(lv));
        if(i > 0x100)
        {
            return TRUE;
        }

        if(!i && gs.modsize)
        {
            gs.mod_playing ^= 1;
            if(gs.mod_playing)
            {
                gs.restart_mod(0, 0);
            }
            else
            {
                gs.stop_mod();
            }

            sprintf(tmp, "(%s)", gs.mod_playing ? "P" : "S");
            LVITEM Item = { };
            Item.mask = LVIF_TEXT;
            Item.pszText = tmp;
            ListView_SetItem(lv, &Item);

            return TRUE;
        }

        if(!gs.modsize)
        {
            i++;
        }
        gs.debug_note(i);
        return TRUE;
    }

    if((id == IDB_GS_SAVE) && (nc == BN_CLICKED))
    {
        unsigned i = unsigned(ListView_GetSelectionMark(lv));
        if((i == 0) && (gs.modsize != 0))
        {
            SaveModDlg(wnd);
            return TRUE;
        }

        if(i > 0x100)
        {
            return TRUE;
        }

        OPENFILENAME ofn = { };
        char sndsavename[MAX_PATH];
        *sndsavename = 0;
        ListView_GetItemText(lv, i, 1, sndsavename, _countof(sndsavename));
        strcat(sndsavename, ".pcm");

        ofn.lStructSize = (WinVerMajor < 5) ? OPENFILENAME_SIZE_VERSION_400 : sizeof(OPENFILENAME);
        ofn.lpstrFilter = "PCM sample (.pcm)\0*.pcm\0";
        ofn.lpstrFile = sndsavename;
        ofn.lpstrDefExt = "pcm";
        ofn.nMaxFile = _countof(sndsavename);
        ofn.lpstrTitle = "Save Sample";
        ofn.Flags = OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR | OFN_EXPLORER | OFN_ENABLESIZING;
        ofn.hwndOwner = wnd;
        ofn.nFilterIndex = 1;
        if(GetSaveFileName(&ofn))
        {
            gs.debug_save_note(i, sndsavename);
        }
        return TRUE;
    }
    return FALSE;
}

void mon_gsdialog()
{
   if (conf.gs_type == 2)
      DialogBox(hIn, MAKEINTRESOURCE(IDD_GS), wnd, gsdlg);
   else MessageBox(wnd, "high-level GS emulation\nis not initialized", nullptr, MB_OK | MB_ICONERROR);
}
#else
void mon_gsdialog() {}
#endif
