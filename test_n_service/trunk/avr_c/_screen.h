#ifndef _SCREEN_H
#define _SCREEN_H

#include "_types.h"

typedef struct {
 const u8 x;                    // ����.���.���� 㣮�� ����
 const u8 y;                    //
 const u8 width;                // �ਭ� (��� ���� ⥭�)
 const u8 height;               // ���� (��� ���� ⥭�)
 const u8 attr;                 // ��ਡ�� ����
 const u8 flag;                 // 䫠��: .0 - "� ⥭��/��� ⥭�"
} WIND_DESC;

typedef struct {
 const u8 x;                    // ����.���.���� 㣮�� ����
 const u8 y;                    //
 const u8 width;                // �����_��ப� + 2 = �ਭ� ��� ���� ࠬ�� � ⥭�
 const u8 items;                // ������⢮ �㭪⮢ ����
 PGM_VOID_P bkgnd_task;         // ��뫪� �� 䮭���� ������
 const u16 bgtask_period;       // ��ਮ� �맮�� 䮭���� �����, �� (1..16383)
 PGM_VOID_P handlers;           // 㪠��⥫� �� �������� 㪠��⥫�� �� ��ࠡ��稪�
 PGM_U8_P strings;              // 㪠��⥫� �� ⥪�� ����
} MENU_DESC;


void scr_set_attr(u8 attr);
void scr_set_cursor(u8 x, u8 y);
void scr_print_msg(PGM_U8_P msg);
void scr_print_mlmsg(PGM_U8_P *mlmsg);
void scr_print_msg_n(PGM_U8_P msg, u8 size);
void scr_print_rammsg_n(u8 *msg, u8 size);
void scr_putchar(u8 ch);
void scr_fill_char(u8 ch, u16 count);
void scr_fill_char_attr(u8 ch, u8 attr, u16 count);
void scr_fill_attr(u8 attr, u16 count);
void scr_backgnd(void);
void scr_fade(void);
void scr_window(PGM_VOID_P ptr);
void scr_menu(PGM_VOID_P ptr);

#endif
