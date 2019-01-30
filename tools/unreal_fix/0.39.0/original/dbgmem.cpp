#include "std.h"

#include "emul.h"
#include "vars.h"
#include "debug.h"
#include "dbgpaint.h"
#include "dbgcmd.h"
#include "dbgmem.h"
#include "wd93crc.h"
#include "util.h"

static TRKCACHE edited_track;

static unsigned sector_offset, sector;

static void findsector(unsigned addr)
{
   for (sector_offset = sector = 0; sector < edited_track.s; sector++, sector_offset += edited_track.hdr[sector].datlen)
      if (addr >= sector_offset && addr < sector_offset + edited_track.hdr[sector].datlen)
         return;
   errexit("internal diskeditor error");
}

unsigned char *editam(unsigned addr)
{
   Z80 &cpu = CpuMgr.Cpu();
   if (editor == ED_CMOS) return &cmos[addr & (sizeof(cmos)-1)];
   if (editor == ED_NVRAM) return &nvram[addr & (sizeof(nvram)-1)];
   if(editor == ED_COMP_PAL) return &comp.comp_pal[addr & (sizeof(comp.comp_pal) - 1)];
   if (editor == ED_MEM) return cpu.DirectMem(addr);
   if (!edited_track.trkd) return nullptr;
   if (editor == ED_PHYS) return edited_track.trkd + addr;
   // editor == ED_LOG
   findsector(addr); return edited_track.hdr[sector].data + addr - sector_offset;
}

static void editwm(unsigned addr, unsigned char byte)
{
   if (editrm(addr) == byte) return;
   unsigned char *ptr = editam(addr);
   if (!ptr) return; *ptr = byte;
   if(editor == ED_MEM || editor == ED_CMOS || editor == ED_NVRAM || editor == ED_COMP_PAL)
   {
       if(editor == ED_COMP_PAL)
       {
           temp.comp_pal_changed = 1;
       }
       return;
   }
   if (editor == ED_PHYS) { comp.wd.fdd[mem_disk].optype |= 2; return; }
   comp.wd.fdd[mem_disk].optype |= 1;
   // recalc sector checksum
   findsector(addr);
   *(unsigned short*)(edited_track.hdr[sector].data + edited_track.hdr[sector].datlen) =
      u16(wd93_crc(edited_track.hdr[sector].data - 1, edited_track.hdr[sector].datlen + 1));
}

unsigned memadr(unsigned addr)
{
   if (editor == ED_MEM) return (addr & 0xFFFF);
   if (editor == ED_CMOS) return (addr & (sizeof(cmos)-1));
   if (editor == ED_NVRAM) return (addr & (sizeof(nvram)-1));
   if (editor == ED_COMP_PAL) return (addr & (sizeof(comp.comp_pal) - 1));
   // else if (editor == ED_PHYS || editor == ED_LOG)
   if (!mem_max) return 0;
   while ((int)addr < 0) addr += mem_max;
   while (addr >= mem_max) addr -= mem_max;
   return addr;
}

void showmem()
{
   Z80 &cpu = CpuMgr.Cpu();
   char line[80]; unsigned ii;
   unsigned cursor_found = 0;
   if(mem_dump)
   {
       mem_ascii = 1;
       mem_sz = 32;
   }
   else mem_sz = 8;

   if (editor == ED_LOG || editor == ED_PHYS)
   {
      edited_track.clear();
      edited_track.seek(comp.wd.fdd+mem_disk, mem_track/2, mem_track & 1, (editor == ED_LOG)? LOAD_SECTORS : JUST_SEEK);
      if (!edited_track.trkd) { // no track
         for (ii = 0; ii < mem_size; ii++) {
            sprintf(line, (ii == mem_size/2)?
               "          track not found            ":
               "                                     ");
            tprint(mem_x, mem_y+ii, line, (activedbg == WNDMEM) ? W_SEL : W_NORM);
         }
         mem_max = 0;
         goto title;
      }
      mem_max = edited_track.trklen;
      if (editor == ED_LOG)
         for (mem_max = ii = 0; ii < edited_track.s; ii++)
            mem_max += edited_track.hdr[ii].datlen;
   }
   else if(editor == ED_MEM)
       mem_max = 0x10000;
   else if(editor == ED_CMOS)
       mem_max = sizeof(cmos);
   else if(editor == ED_NVRAM)
       mem_max = sizeof(nvram);
   else if(editor == ED_COMP_PAL)
       mem_max = sizeof(comp.comp_pal);

   unsigned div;
   div = mem_dump ? 32 : 8;
   unsigned dx;
   dx = (mem_max + div - 1) / div;
   unsigned mem_lines;
   mem_lines = min(dx, unsigned(mem_size));
redraw:
   cpu.mem_curs = memadr(cpu.mem_curs);
   cpu.mem_top = memadr(cpu.mem_top);
   for (ii = 0; ii < mem_lines; ii++)
   {
      unsigned ptr = memadr(cpu.mem_top + ii*mem_sz);
      sprintf(line, "%04X ", ptr);
      unsigned cx = 0;
      if (mem_dump)
      {  // 0000 0123456789ABCDEF0123456789ABCDEF
         for (unsigned dx = 0; dx < 32; dx++)
         {
            if (ptr == cpu.mem_curs) cx = dx+5;
            unsigned char c = editrm(ptr); ptr = memadr(ptr+1);
            line[dx+5] = char(c ? c : '.');
         }
      }
      else 
      {  // 0000 11 22 33 44 55 66 77 88 abcdefgh
         for (unsigned dx = 0; dx < 8; dx++)
         {
            if (ptr == cpu.mem_curs) cx = (mem_ascii) ? dx+29 : dx*3 + 5 + cpu.mem_second;
            unsigned char c = editrm(ptr); ptr = memadr(ptr+1);
            sprintf(line+5+3*dx, "%02X", c); line[7+3*dx] = ' ';
            line[29+dx] = char(c ? c : '.');
         }
      }
      line[37] = 0;
      tprint(mem_x, mem_y+ii, line, (activedbg == WNDMEM) ? W_SEL : W_NORM);
      cursor_found |= cx;
      if (cx && (activedbg == WNDMEM))
         txtscr[(mem_y+ii)*80+mem_x+cx+80*30] = W_CURS;
   }
   if (!cursor_found) { cursor_found=1; cpu.mem_top=cpu.mem_curs & ~(mem_sz-1); goto redraw; }
title:
   const char *MemName = nullptr;
   if (editor == ED_MEM)
       MemName = "memory";
   else if (editor == ED_CMOS)
       MemName = "cmos";
   else if (editor == ED_NVRAM)
       MemName = "nvram";
   else if(editor == ED_COMP_PAL)
       MemName = "comppal";

   if(editor == ED_MEM || editor == ED_CMOS || editor == ED_NVRAM || editor == ED_COMP_PAL)
   {
       sprintf(line, "%s: %04X gsdma: %06X", MemName, cpu.mem_curs & 0xFFFF, temp.gsdmaaddr);
   }
   else if (editor == ED_PHYS)
       sprintf(line, "disk %c, trk %02X, offs %04X", int(mem_disk+'A'), mem_track, cpu.mem_curs);
   else
   { // ED_LOG
      if (mem_max)
          findsector(cpu.mem_curs);
      sprintf(line, "disk %c, trk %02X, sec %02X[%02X], offs %04X",
        int(mem_disk+'A'), mem_track, sector, edited_track.hdr[sector].n,
        cpu.mem_curs-sector_offset);
   }
   tprint(mem_x, mem_y-1, line, W_TITLE);
   frame(mem_x,mem_y,37,mem_size,FRAME);
}

      /* ------------------------------------------------------------- */
void mstl()
{
    Z80 &cpu = CpuMgr.Cpu();
    if(mem_max)
    {
        cpu.mem_curs &= ~(mem_sz - 1);
        cpu.mem_second = 0;
    }
}
void mendl()
{
    Z80 &cpu = CpuMgr.Cpu();
    if(mem_max)
    {
        cpu.mem_curs |= (mem_sz - 1);
        cpu.mem_second = 1;
    }
}
void mup()
{
    Z80 &cpu = CpuMgr.Cpu();
    if (mem_max) cpu.mem_curs -= mem_sz;
}
void mpgdn()
{
    Z80 &cpu = CpuMgr.Cpu();
    if(mem_max)
    {
        cpu.mem_curs += mem_size * mem_sz;
        cpu.mem_top += mem_size * mem_sz;
    }
}

void mpgup()
{
    Z80 &cpu = CpuMgr.Cpu();
    if(mem_max)
    {
        cpu.mem_curs -= mem_size * mem_sz;
        cpu.mem_top -= mem_size * mem_sz;
    }
}

void mdown()
{
   if (!mem_max) return;

   Z80 &cpu = CpuMgr.Cpu();
   cpu.mem_curs += mem_sz;
   if (((cpu.mem_curs - cpu.mem_top + mem_max) % mem_max) / mem_sz >= mem_size) cpu.mem_top += mem_sz;
}

void mleft()
{
   if (!mem_max) return;
   Z80 &cpu = CpuMgr.Cpu();
   if (mem_ascii || !cpu.mem_second) cpu.mem_curs--;
   if (!mem_ascii) cpu.mem_second ^= 1;
}

void mright()
{
   Z80 &cpu = CpuMgr.Cpu();
   if (!mem_max) return;
   if (mem_ascii || cpu.mem_second) cpu.mem_curs++;
   if (!mem_ascii) cpu.mem_second ^= 1;
   if (((cpu.mem_curs - cpu.mem_top + mem_max) % mem_max) / mem_sz >= mem_size) cpu.mem_top += mem_sz;
}

char dispatch_mem()
{
   Z80 &cpu = CpuMgr.Cpu();
   if (!mem_max)
       return 0;

   u8 Kbd[256];
   GetKeyboardState(Kbd);
   unsigned short k = 0;
   if (ToAscii(input.lastkey,0,Kbd,&k,0) != 1)
       return 0;

   if (mem_ascii)
   {
      k &= 0xFF;
      if (k < 0x20 || k >= 0x80)
          return 0;
      editwm(cpu.mem_curs, (unsigned char)k);
      mright();
      return 1;
   }
   else
   {
      u8 u = u8(toupper(k));
      if ((u >= '0' && u <= '9') || (u >= 'A' && u <= 'F'))
      {
         unsigned char k = (u >= 'A') ? u - 'A'+10 : u - '0';
         unsigned char c = editrm(cpu.mem_curs);
         if (cpu.mem_second) editwm(cpu.mem_curs, (c & 0xF0) | k);
         else editwm(cpu.mem_curs, u8(c & 0x0F) | u8(k << 4));
         mright();
         return 1;
      }
   }
   return 0;
}

void mtext()
{
   Z80 &cpu = CpuMgr.Cpu();
   int rs = find1dlg(cpu.mem_curs);
   if (rs != -1) cpu.mem_curs = unsigned(rs);
}

void mcode()
{
   Z80 &cpu = CpuMgr.Cpu();
   int rs = find2dlg(cpu.mem_curs);
   if (rs != -1) cpu.mem_curs = unsigned(rs);
}

void mgoto()
{
   Z80 &cpu = CpuMgr.Cpu();
   int v = input4(mem_x, mem_y, cpu.mem_top);
   if(v != -1)
   {
       cpu.mem_top = (unsigned(v) & ~(mem_sz - 1));
       cpu.mem_curs = unsigned(v);
   }
}

void mswitch() { mem_ascii ^= 1; }

void msp()
{
    Z80 &cpu = CpuMgr.Cpu();
    cpu.mem_curs = cpu.sp;
}
void mpc()
{
    Z80 &cpu = CpuMgr.Cpu();
    cpu.mem_curs = cpu.pc;
}

void mbc()
{
    Z80 &cpu = CpuMgr.Cpu();
    cpu.mem_curs = cpu.bc;
}

void mde()
{
    Z80 &cpu = CpuMgr.Cpu();
    cpu.mem_curs = cpu.de;
}

void mhl()
{
    Z80 &cpu = CpuMgr.Cpu();
    cpu.mem_curs = cpu.hl;
}

void mix()
{
    Z80 &cpu = CpuMgr.Cpu();
    cpu.mem_curs = cpu.ix;
}

void miy()
{
    Z80 &cpu = CpuMgr.Cpu();
    cpu.mem_curs = cpu.iy;
}

void mmodemem() { editor = ED_MEM; }
void mmodephys() { editor = ED_PHYS; }
void mmodelog() { editor = ED_LOG; }

void mdiskgo()
{
   Z80 &cpu = CpuMgr.Cpu();
   if (editor == ED_MEM) return;
   for (;;) {
      *(unsigned*)str = mem_disk + 'A';
      if (!inputhex(mem_x+5, mem_y-1, 1, true)) return;
      if (*str >= 'A' && *str <= 'D') break;
   }
   mem_disk = unsigned(*str-'A'); showmem();
   int x = input2(mem_x+12, mem_y-1, mem_track);
   if (x == -1) return;
   mem_track = unsigned(x);
   if (editor == ED_PHYS) return;
   showmem();
   // enter sector
   for (;;) {
      findsector(cpu.mem_curs); x = input2(mem_x+20, mem_y-1, sector);
      if (x == -1) return; if (unsigned(x) < edited_track.s) break;
   }
   for (cpu.mem_curs = 0; x; x--) cpu.mem_curs += edited_track.hdr[x-1].datlen;
}
