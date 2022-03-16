#ifndef _SCREEN_H
#define _SCREEN_H

#include "_types.h"

typedef struct {
 u8 x;                                  // ����.���.���� 㣮�� ����
 u8 y;                                  //
 u8 width;                              // �ਭ� (��� ���� ⥭�)
 u8 height;                             // ���� (��� ���� ⥭�)
 u8 attr;                               // ��ਡ�� ����
 u8 flag;                               // 䫠��: .0 - "� ⥭��/��� ⥭�"
} WIND_DESC, * const P_WIND_DESC;

typedef struct {
 u8 x;                                  // ����.���.���� 㣮�� ����
 u8 y;                                  //
 u8 width;                              // �����_��ப� + 2 = �ਭ� ��� ���� ࠬ�� � ⥭�
 u8 items;                              // ������⢮ �㭪⮢ ����
 PBKHNDL bkgnd_task;                    // ��뫪� �� 䮭���� ������
 u16 bgtask_period;                     // ��ਮ� �맮�� 䮭���� �����, �� (1..16383)
 const PITEMHNDL * const handlers;      // 㪠��⥫� �� �������� 㪠��⥫�� �� ��ࠡ��稪�
 const u8 *strings;                     // 㪠��⥫� �� ⥪�� ����
} MENU_DESC, * const P_MENU_DESC;


void scr_set_attr(u8 attr);
void scr_set_cursor(u8 x, u8 y);
void scr_print_msg(const u8 *msg);
void scr_print_mlmsg(const u8 * const *mlmsg);
void scr_print_msg_n(const u8 *msg, u8 size);
void scr_print_rammsg_n(u8 *msg, u8 size);
void scr_putchar(u8 ch);
void scr_fill_char(u8 ch, u16 count);
void scr_fill_char_attr(u8 ch, u8 attr, u16 count);
void scr_fill_attr(u8 attr, u16 count);
void scr_backgnd(void);
void scr_fade(void);
void scr_window(const P_WIND_DESC pwindesc);
void scr_menu(const P_MENU_DESC pmenudesc);

#endif
