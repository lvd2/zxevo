#include "_global.h"

//-----------------------------------------------------------------------------

const u8 BlahBlah[] PROGMEM =
  "\0\0\0\0================  Test&Service  ================";

//-----------------------------------------------------------------------------

const u8 msg_title1[] PROGMEM =
                 "          ZX Evolution Test&Service ";
//               |          ZX Evolution Test&Service (110203)         |
//width limited! "01234567890123456789012345678901234567890123456789012"

//-----------------------------------------------------------------------------

const u8 msg_title2[] PROGMEM = "http://www.NedoPC.com/";

//-----------------------------------------------------------------------------

const u8 msg_pintest_rus[] PROGMEM = "\r\n\n�஢�ઠ �뢮��� ATMEGA128... ";
const u8 msg_pintest_eng[] PROGMEM = "\r\n\nATMEGA128 pins check... ";
PGM_U8_P mlmsg_pintest[] PROGMEM = {msg_pintest_rus, msg_pintest_eng};

//-----------------------------------------------------------------------------

const u8 msg_pintest_ok_rus[] PROGMEM = "�஡��� �� �����㦥��.";
const u8 msg_pintest_ok_eng[] PROGMEM = "No problems found.";
PGM_U8_P mlmsg_pintest_ok[] PROGMEM = {msg_pintest_ok_rus, msg_pintest_ok_eng};

//-----------------------------------------------------------------------------

const u8 msg_pintest_error_rus[] PROGMEM = "\r\n�����㦥�� �஡���� �� �����(-��): ";
const u8 msg_pintest_error_eng[] PROGMEM = "\r\nHave a problem at port(s): ";
PGM_U8_P mlmsg_pintest_error[] PROGMEM = {msg_pintest_error_rus, msg_pintest_error_eng};

//-----------------------------------------------------------------------------

const u8 msg_pintest_pa[] PROGMEM = "PAx ";
const u8 msg_pintest_pb[] PROGMEM = "PBx ";
const u8 msg_pintest_pc[] PROGMEM = "PCx ";
const u8 msg_pintest_pd[] PROGMEM = "PD5 ";
const u8 msg_pintest_pe[] PROGMEM = "PEx ";
const u8 msg_pintest_pg[] PROGMEM = "PGx ";

//-----------------------------------------------------------------------------

const u8 msg_halt_rus[] PROGMEM = "\r\n�ணࠬ�� ��⠭������!";
const u8 msg_halt_eng[] PROGMEM = "\r\nProgram is halted!";
PGM_U8_P mlmsg_halt[] PROGMEM = {msg_halt_rus, msg_halt_eng};

//-----------------------------------------------------------------------------

const u8 msg_statusof_rus[] PROGMEM = "\n\r����ﭨ� ";
const u8 msg_statusof_eng[] PROGMEM = "\n\rStatus of ";
PGM_U8_P mlmsg_statusof_crlf[] PROGMEM = {msg_statusof_rus,  msg_statusof_eng  };
PGM_U8_P mlmsg_statusof_cr[] PROGMEM   = {msg_statusof_rus+1,msg_statusof_eng+1};

const u8 msg_power_pg[] PROGMEM = "POWERGOOD=";
const u8 msg_power_vcc5[] PROGMEM = ", VCC5=";

const u8 msg_power_on_rus[] PROGMEM = "\r\n����祭�� ��⠭�� ATX...\n";
const u8 msg_power_on_eng[] PROGMEM = "\r\nATX power up...\n";
PGM_U8_P mlmsg_power_on[] PROGMEM = {msg_power_on_rus, msg_power_on_eng};

//-----------------------------------------------------------------------------

const u8 msg_cfgfpga_rus[] PROGMEM = "\r\n����㧪� ���䨣��樨 � FPGA... ";
const u8 msg_cfgfpga_eng[] PROGMEM = "\r\nSet FPGA configuration... ";
PGM_U8_P mlmsg_cfgfpga[] PROGMEM = {msg_cfgfpga_rus, msg_cfgfpga_eng};

//-----------------------------------------------------------------------------

const u8 msg_done1_rus[] PROGMEM = "�����襭�.\r\n�஢�ઠ ������ � FPGA... ";
const u8 msg_done1_eng[] PROGMEM = "Done.\r\nFPGA data exchange test... ";
PGM_U8_P mlmsg_done1[] PROGMEM = {msg_done1_rus, msg_done1_eng};

//-----------------------------------------------------------------------------

const u8 msg_ok[] PROGMEM = "Ok.";

//-----------------------------------------------------------------------------

const u8 msg_someerrors_rus[] PROGMEM = "���� �訡��!";
const u8 msg_someerrors_eng[] PROGMEM = "We have some errors!";
PGM_U8_P mlmsg_someerrors[] PROGMEM = {msg_someerrors_rus, msg_someerrors_eng};

//-----------------------------------------------------------------------------

const u8 msg_spi_test_rus[] PROGMEM = "\r\n������⢮ ���ࠢ����� ���� �� 50000 -";
const u8 msg_spi_test_eng[] PROGMEM = "\r\nQuantity wrong byte from 50000 -";
PGM_U8_P mlmsg_spi_test[] PROGMEM = {msg_spi_test_rus, msg_spi_test_eng};

//-----------------------------------------------------------------------------

const u8 msg_kbd_detect_rus[] PROGMEM = "\r\n�஢�ઠ ���������� PS/2...\r\n";
const u8 msg_kbd_detect_eng[] PROGMEM = "\r\nPS/2 keyboard check...\r\n";
PGM_U8_P mlmsg_kbd_detect[] PROGMEM = {msg_kbd_detect_rus, msg_kbd_detect_eng};

//-----------------------------------------------------------------------------

const u8 msg_noresponse_rus[] PROGMEM = " ...��� �⢥�\r\n";
const u8 msg_noresponse_eng[] PROGMEM = " ...no response\r\n";
PGM_U8_P mlmsg_noresponse[] PROGMEM = {msg_noresponse_rus, msg_noresponse_eng};

//-----------------------------------------------------------------------------

const u8 msg_unwanted_rus[] PROGMEM = " <- ���������� �⢥�\r\n";
const u8 msg_unwanted_eng[] PROGMEM = " <- unwanted response\r\n";
PGM_U8_P mlmsg_unwanted[] PROGMEM = {msg_unwanted_rus, msg_unwanted_eng};

//-----------------------------------------------------------------------------

const u8 msg_txfail_rus[] PROGMEM = " ...ᡮ� �� ��।��\r\n";
const u8 msg_txfail_eng[] PROGMEM = " ...fail to transmit\r\n";
PGM_U8_P mlmsg_txfail[] PROGMEM = {msg_txfail_rus, msg_txfail_eng};

//-----------------------------------------------------------------------------

const u8 msg_ready[] PROGMEM = "---\r\n";

//-----------------------------------------------------------------------------

const u8 msg_menu_help_rus[] PROGMEM =
 "\x16\x05\x0e"  "�᭮��� ������ �ࠢ�����:"
 "\x16\x05\x0f"  "<>, <>"
 "\x16\x05\x10"  "<Enter> - \"��\", �롮�"
 "\x16\x05\x11"  "<Esc> - \"���\", �⬥��, ��室"
 "\x16\x05\x12"  "����稥 ������ (⮫쪮 � ����):"
 "\x16\x05\x13"  "<ScrollLock> - ०�� TV/VGA"
 "\x16\x05\x14"  "<CapsLock> - �� ����䥩�";
const u8 msg_menu_help_eng[] PROGMEM =
 "\x16\x05\x0e"  "Usage:"
 "\x16\x05\x0f"  "<>, <>"
 "\x16\x05\x10"  "<Enter> - \"Yes\", select"
 "\x16\x05\x11"  "<Esc> - \"No\", cancel, exit"
 "\x16\x05\x12"  "Hot-keys (in menu only):"
 "\x16\x05\x13"  "<ScrollLock> - toggle TV/VGA mode"
 "\x16\x05\x14"  "<CapsLock> - language switch";
//width limited! "567890123456789012345678901234567"
PGM_U8_P mlmsg_menu_help[] PROGMEM = {msg_menu_help_rus, msg_menu_help_eng};

//-----------------------------------------------------------------------------

const u8 msg_tbeep_rus[] PROGMEM =
 "\x16\x1a\x0a"  "��"  "\x16\x0a\x0c"  "<>, <> - ��������� �����"  "\x15\x0f";
const u8 msg_tbeep_eng[] PROGMEM =
 "\x16\x1a\x0a"  "Hz"  "\x16\x0e\x0c"      "<>, <> - frequence"      "\x15\x0f";
//width limited!                       "0123456789012345678901234567"
PGM_U8_P mlmsg_tbeep[] PROGMEM = {msg_tbeep_rus, msg_tbeep_eng};

//-----------------------------------------------------------------------------

const u8 msg_tzxk1_rus[] PROGMEM = "\x16\x0e\x07��������� ZX\x16\x23\x07�����⨪";
const u8 msg_tzxk1_eng[] PROGMEM = "\x16\x0f\x07ZX Keyboard\x16\x23\x07Joystick";
PGM_U8_P mlmsg_tzxk1[] PROGMEM = {msg_tzxk1_rus, msg_tzxk1_eng};

//-----------------------------------------------------------------------------

const u8 msg_tzxk2[] PROGMEM =
 "\x16\x0b\x09"  "1 2 3 4 5 6 7 8 9 0"
 "\x16\x0b\x0a"  "Q W E R T Y U I O P"
 "\x16\x0b\x0b"  "A S D F G H J K L e"
 "\x16\x0b\x0c"  "c Z X C V B N M s s"
 "\x16\x26\x0a"  "\x18"
 "\x16\x24\x0b"  "\x1b F \x1a"
 "\x16\x26\x0c"  "\x19"
 "\x16\x0e\x0f"  "SoftReset"
 "\x16\x1e\x0f"  "TurboKey";

//-----------------------------------------------------------------------------

const u8 msg_tps2k0_rus[] PROGMEM =
 "\x16\x05\x13"  "�����⭮� ����⨥ <ESC> - ��室 �� ���.";
const u8 msg_tps2k0_eng[] PROGMEM =
 "\x16\x0a\x13"       "Press <ESC> three times to exit.";
//width limited! "5678901234567890123456789012345678901234567"
PGM_U8_P mlmsg_tps2k0[] PROGMEM = {msg_tps2k0_rus, msg_tps2k0_eng};

//-----------------------------------------------------------------------------

const u8 msg_tps2k1[] PROGMEM =
 "\x16\x05\x07"  "e   1 2 3 4 5 6 7 8 9 0 1 2  p s p  \x07 \x07 \x07"
 "\x16\x05\x09"  "` 1 2 3 4 5 6 7 8 9 0 - = \x1b  i h u  n / * -"
 "\x16\x05\x0a"  "t Q W E R T Y U I O P [ ] \\  d e d  7 8 9"
 "\x16\x05\x0b"  "c A S D F G H J K L ; '   e         4 5 6 +"
 "\x16\x05\x0c"  "s Z X C V B N M , . /     s    \x18    1 2 3"
 "\x16\x05\x0d"  "c w a       s       a w m c  \x1b \x19 \x1a  0   . e"
 "\x16\x05\x10"  "Raw data:\x16\x04\x0f";

//-----------------------------------------------------------------------------

const u8 msg_mouse_test_rus[] PROGMEM = "\r\n����஢���� ���... ";
const u8 msg_mouse_test_eng[] PROGMEM = "\r\nMouse test... ";
PGM_U8_P mlmsg_mouse_test[] PROGMEM = {msg_mouse_test_rus, msg_mouse_test_eng};

//-----------------------------------------------------------------------------

const u8 msg_mouse_detect_rus[] PROGMEM = "�����㦥��� ���...  ";
const u8 msg_mouse_detect_eng[] PROGMEM = "Detecting mouse...  ";
PGM_U8_P mlmsg_mouse_detect[] PROGMEM = {msg_mouse_detect_rus, msg_mouse_detect_eng};

//-----------------------------------------------------------------------------

const u8 msg_mouse_setup_rus[] PROGMEM = "����ன��... ";
const u8 msg_mouse_setup_eng[] PROGMEM = "Customization... ";
PGM_U8_P mlmsg_mouse_setup[] PROGMEM = {msg_mouse_setup_rus, msg_mouse_setup_eng};

//-----------------------------------------------------------------------------

const u8 msg_mouse_letsgo_rus[] PROGMEM = "���堫�!";
const u8 msg_mouse_letsgo_eng[] PROGMEM = "Let's go!";
PGM_U8_P mlmsg_mouse_letsgo[] PROGMEM = {msg_mouse_letsgo_rus, msg_mouse_letsgo_eng};

//-----------------------------------------------------------------------------

const u8 msg_mouse_fail0_rus[] PROGMEM = "      ��� �⢥� �� ���.";
const u8 msg_mouse_fail0_eng[] PROGMEM = "      No mouse response.";
//width limited!                         "1234567890123456789012345678901"
PGM_U8_P mlmsg_mouse_fail0[] PROGMEM = {msg_mouse_fail0_rus, msg_mouse_fail0_eng};

//-----------------------------------------------------------------------------

const u8 msg_mouse_fail1_rus[] PROGMEM = "   ������� ������� �஡����.";
const u8 msg_mouse_fail1_eng[] PROGMEM = "    There are some problems.";
//width limited!                         "1234567890123456789012345678901"
PGM_U8_P mlmsg_mouse_fail1[] PROGMEM = {msg_mouse_fail1_rus, msg_mouse_fail1_eng};

//-----------------------------------------------------------------------------

const u8 msg_mouse_restart_rus[] PROGMEM = "  <Enter> - ��१������� ���.";
const u8 msg_mouse_restart_eng[] PROGMEM = "     <Enter> - restart test.";
//width limited!                           "1234567890123456789012345678901"
PGM_U8_P mlmsg_mouse_restart[] PROGMEM = {msg_mouse_restart_rus, msg_mouse_restart_eng};

//-----------------------------------------------------------------------------

const u8 msg_tpsm_1[] PROGMEM =
 "\x16\x25\x0f"  "Wheel ="
 "\x16\x25\x0c"  "L   M   R"
 "\x16\x25\x11"  "X  ="
 "\x16\x25\x12"  "Y  =";

//-----------------------------------------------------------------------------

const u8 msg_mtst_rus[] PROGMEM =
 "\x16\x23\x12"     " ���� DRAM "
 "\x16\x20\x13"  "�஢����� 横���"
 "\x16\x20\x14"  "��� �訡��"
 "\x16\x20\x15"  "� �訡����";
const u8 msg_mtst_eng[] PROGMEM =
 "\x16\x23\x12"     " DRAM test "
//width limited! "23456789012345678"
 "\x16\x20\x13"  "Loops"
//width limited! "23456789012345678"
 "\x16\x20\x14"  "Pass"
//width limited! "2345678901"
 "\x16\x20\x15"  "Fail";
//width limited! "2345678901"
PGM_U8_P mlmsg_mtst[] PROGMEM = {msg_mtst_rus, msg_mtst_eng};

//-----------------------------------------------------------------------------

const u8 msg_menu_swlng_rus[] PROGMEM = "\x16\x17\x0c"          "���᪨�";
const u8 msg_menu_swlng_eng[] PROGMEM = "\x16\x17\x0c"          "English";
//width limited!                                       "456789012345678901234567"
PGM_U8_P mlmsg_menu_swlng[] PROGMEM = {msg_menu_swlng_rus, msg_menu_swlng_eng};

//-----------------------------------------------------------------------------

const u8 msg_fl_menu_rus[] PROGMEM =
 "\x16\x02\x02"  "��室"
 "\x16\x02\x03"  "��� ᭮��"
 "\x16\x02\x04"  "����� �/��."
 "\x16\x02\x05"  "�����.�������"
 "\x16\x02\x06"  "�믮�����";
const u8 msg_fl_menu_eng[] PROGMEM =
 "\x16\x02\x02"  "Exit"
 "\x16\x02\x03"  "Retrieve all"
 "\x16\x02\x04"  "Erase chip"
 "\x16\x02\x05"  "Add job"
 "\x16\x02\x06"  "Execute jobs";
//width limited! "2345678901234"
PGM_U8_P mlmsg_fl_menu[] PROGMEM = {msg_fl_menu_rus, msg_fl_menu_eng};

//-----------------------------------------------------------------------------

const u8 msg_fp_nofiles_rus[] PROGMEM = "\x15\x9f"  " ��� 䠩��� ";
const u8 msg_fp_nofiles_eng[] PROGMEM = "\x15\x9f"  "  No files  ";
//width fixed!                                      "123456789012"
PGM_U8_P mlmsg_fp_nofiles[] PROGMEM = {msg_fp_nofiles_rus, msg_fp_nofiles_eng};

//-----------------------------------------------------------------------------

const u8 msg_fl_readrom_rus[] PROGMEM =
 "\x16\x02\x0a"  "�⥭�� Flash"
 "\x16\x02\x0b"  "<ESC> - ��室";
const u8 msg_fl_readrom_eng[] PROGMEM =
 "\x16\x02\x0a"  "Read Flash..."
 "\x16\x02\x0b"  "<ESC> - exit";
//width limited! "2345678901234"
PGM_U8_P mlmsg_fl_readrom[] PROGMEM = {msg_fl_readrom_rus, msg_fl_readrom_eng};

//-----------------------------------------------------------------------------

const u8 msg_fl_sdinit_rus[] PROGMEM =
 "\x16\x02\x0b\x15\x9f"  "����.SD �����";
const u8 msg_fl_sdinit_eng[] PROGMEM =
 "\x16\x02\x0b\x15\x9f"  "SDcard init. ";
//width limited!         "2345678901234"
PGM_U8_P mlmsg_fl_sdinit[] PROGMEM = {msg_fl_sdinit_rus, msg_fl_sdinit_eng};

//-----------------------------------------------------------------------------

const u8 msg_fl_sderror1_rus[] PROGMEM = " ��� SD �����! ";
const u8 msg_fl_sderror1_eng[] PROGMEM = "  No SD-card!  ";
//width fixed!                           "123456789012345"
PGM_U8_P mlmsg_fl_sderror1[] PROGMEM = {msg_fl_sderror1_rus, msg_fl_sderror1_eng};

//-----------------------------------------------------------------------------

const u8 msg_fl_sderror2_rus[] PROGMEM = " �訡�� ��. SD ";
const u8 msg_fl_sderror2_eng[] PROGMEM = " SD read error ";
//width fixed!                           "123456789012345"
PGM_U8_P mlmsg_fl_sderror2[] PROGMEM = {msg_fl_sderror2_rus, msg_fl_sderror2_eng};

//-----------------------------------------------------------------------------

const u8 msg_fl_sderror3_rus[] PROGMEM = "   ��� FAT !   ";
const u8 msg_fl_sderror3_eng[] PROGMEM = " FAT no found! ";
//width fixed!                           "123456789012345"
PGM_U8_P mlmsg_fl_sderror3[] PROGMEM = {msg_fl_sderror3_rus, msg_fl_sderror3_eng};

//-----------------------------------------------------------------------------

const u8 msg_fl_sderror4_rus[] PROGMEM = "  �訡�� FAT ! ";
const u8 msg_fl_sderror4_eng[] PROGMEM = "  FAT error !  ";
//width fixed!                           "123456789012345"
PGM_U8_P mlmsg_fl_sderror4[] PROGMEM = {msg_fl_sderror4_rus, msg_fl_sderror4_eng};

//-----------------------------------------------------------------------------

//const u8 msg_fl_sderrorx_rus[] PROGMEM = " �, ���㫮! ";
//const u8 msg_fl_sderrorx_eng[] PROGMEM = " Great glitch! ";
////width fixed!                           "123456789012345"
//PGM_U8_P mlmsg_fl_sderrorx[] PROGMEM = {msg_fl_sderrorx_rus, msg_fl_sderrorx_eng};

//-----------------------------------------------------------------------------

const u8 msg_fl_sure_rus[] PROGMEM =
 "\x16\x02\x0c\x15\x9e"  " ���७? <Y> ";
const u8 msg_fl_sure_eng[] PROGMEM =
 "\x16\x02\x0c\x15\x9e"  "You sure? <Y>";
//width fixed!           "2345678901234"
PGM_U8_P mlmsg_fl_sure[] PROGMEM = {msg_fl_sure_rus, msg_fl_sure_eng};

//-----------------------------------------------------------------------------

const u8 msg_fl_erase_rus[] PROGMEM =
 "\x16\x02\x0c\x15\x9e"  "��࠭��...  ";
const u8 msg_fl_erase_eng[] PROGMEM =
 "\x16\x02\x0c\x15\x9e"  "Erase...     ";
//width fixed!           "2345678901234"
PGM_U8_P mlmsg_fl_erase[] PROGMEM = {msg_fl_erase_rus, msg_fl_erase_eng};

//-----------------------------------------------------------------------------

const u8 msg_fl_write_rus[] PROGMEM =
 "\x16\x02\x0c\x15\x9e"  "������...    ";
const u8 msg_fl_write_eng[] PROGMEM =
 "\x16\x02\x0c\x15\x9e"  "Write...     ";
//width fixed!           "2345678901234"
PGM_U8_P mlmsg_fl_write[] PROGMEM = {msg_fl_write_rus, msg_fl_write_eng};

//-----------------------------------------------------------------------------

const u8 msg_fl_verify_rus[] PROGMEM =
 "\x16\x02\x0c\x15\x9e"  "�஢�ઠ...  ";
const u8 msg_fl_verify_eng[] PROGMEM =
 "\x16\x02\x0c\x15\x9e"  "Verify...    ";
//width fixed!           "2345678901234"
PGM_U8_P mlmsg_fl_verify[] PROGMEM = {msg_fl_verify_rus, msg_fl_verify_eng};

//-----------------------------------------------------------------------------

const u8 msg_fl_complete_rus[] PROGMEM =
 "\x16\x02\x0c\x15\x9e"  "�����襭�.   ";
const u8 msg_fl_complete_eng[] PROGMEM =
 "\x16\x02\x0c\x15\x9e"  "Complete.    ";
//width fixed!           "2345678901234"
PGM_U8_P mlmsg_fl_complete[] PROGMEM = {msg_fl_complete_rus, msg_fl_complete_eng};

//-----------------------------------------------------------------------------

const u8 msg_flres0_rus[] PROGMEM =
 "\x16\x0d\x06"  "������ � FlashROM �����襭�";
const u8 msg_flres0_eng[] PROGMEM =
 "\x16\x12\x06"        "Job(s) completed.";
//width limited! "23456789012345678901234567890"
PGM_U8_P mlmsg_flres0[] PROGMEM = {msg_flres0_rus, msg_flres0_eng};

//-----------------------------------------------------------------------------

const u8 msg_flres1_rus[] PROGMEM =
 "\x16\x15\x07"           "��� �訡��.";
const u8 msg_flres1_eng[] PROGMEM =
 "\x16\x11\x07"       "No errors detected.";
//width limited! "23456789012345678901234567890"
PGM_U8_P mlmsg_flres1[] PROGMEM = {msg_flres1_rus, msg_flres1_eng};

//-----------------------------------------------------------------------------

const u8 msg_flres2_rus[] PROGMEM =
 "\x16\x15\x07"           "� �訡����!";
const u8 msg_flres2_eng[] PROGMEM =
 "\x16\x0e\x07"    "Some errors are detected!";
//width limited! "23456789012345678901234567890"
PGM_U8_P mlmsg_flres2[] PROGMEM = {msg_flres2_rus, msg_flres2_eng};

//-----------------------------------------------------------------------------

const u8 msg_sensors_rus[] PROGMEM = "   ���稪�: ";
const u8 msg_sensors_eng[] PROGMEM = "   Sensors: ";
//width fixed!                       "012345678901"
PGM_U8_P mlmsg_sensors[] PROGMEM = {msg_sensors_rus, msg_sensors_eng};

//-----------------------------------------------------------------------------

const u8 msg_s_nocard_rus[] PROGMEM = "     ��� �����     ";
const u8 msg_s_nocard_eng[] PROGMEM = "      No card      ";
//width fixed!                        "2345678901234567890"
PGM_U8_P mlmsg_s_nocard[] PROGMEM = {msg_s_nocard_rus, msg_s_nocard_eng};

//-----------------------------------------------------------------------------

const u8 msg_s_inserted_rus[] PROGMEM = " ���� ��⠭������ ";
const u8 msg_s_inserted_eng[] PROGMEM = "   Card inserted   ";
//width fixed!                          "2345678901234567890"
PGM_U8_P mlmsg_s_inserted[] PROGMEM = {msg_s_inserted_rus, msg_s_inserted_eng};

//-----------------------------------------------------------------------------

const u8 msg_s_readonly_rus[] PROGMEM = "  ���� �� ����� ";
const u8 msg_s_readonly_eng[] PROGMEM = "     Read only     ";
//width fixed!                          "1234567890123456789"
PGM_U8_P mlmsg_s_readonly[] PROGMEM = {msg_s_readonly_rus, msg_s_readonly_eng};

//-----------------------------------------------------------------------------

const u8 msg_s_writeen_rus[] PROGMEM = "  ������ ࠧ�襭� ";
const u8 msg_s_writeen_eng[] PROGMEM = "   Write enabled   ";
//width fixed!                         "1234567890123456789"
PGM_U8_P mlmsg_s_writeen[] PROGMEM = {msg_s_writeen_rus, msg_s_writeen_eng};

//-----------------------------------------------------------------------------

const u8 msg_tsd_init_rus[] PROGMEM = "���樠������ ����窨...";
const u8 msg_tsd_init_eng[] PROGMEM = "Card initialization...";
PGM_U8_P mlmsg_tsd_init[] PROGMEM = {msg_tsd_init_rus, msg_tsd_init_eng};

//-----------------------------------------------------------------------------

const u8 msg_tsd_nocard_rus[] PROGMEM = "SD/MMC ���� �� �����㦥��.";
const u8 msg_tsd_nocard_eng[] PROGMEM = "No SD/MMC card found.";
PGM_U8_P mlmsg_tsd_nocard[] PROGMEM = {msg_tsd_nocard_rus, msg_tsd_nocard_eng};

//-----------------------------------------------------------------------------

const u8 msg_tsd_foundcard_rus[] PROGMEM = "�����㦥�� ����: ";
const u8 msg_tsd_foundcard_eng[] PROGMEM = "Found card: ";
PGM_U8_P mlmsg_tsd_foundcard[] PROGMEM = {msg_tsd_foundcard_rus, msg_tsd_foundcard_eng};

//-----------------------------------------------------------------------------

const u8 msg_tsd_menu_rus[] PROGMEM =
 "\x16\x10\x0b"      "����� �������⨪�"
 "\x16\x0c\x0c"  "[ ] ���஡�� ����� � RS-232";
const u8 msg_tsd_menu_eng[] PROGMEM =
 "\x16\x11\x0b"       "Start diagnostic"
 "\x16\x0c\x0c"  "[ ] Detailed log to RS-232";
//width limited! "2345678901234567890123456789"
PGM_U8_P mlmsg_tsd_menu[] PROGMEM = {msg_tsd_menu_rus, msg_tsd_menu_eng};

//-----------------------------------------------------------------------------

const u8 msg_tsd_foundfat_rus[] PROGMEM = "�����㦥�� FAT";
const u8 msg_tsd_foundfat_eng[] PROGMEM = "Found FAT";
PGM_U8_P mlmsg_tsd_foundfat[] PROGMEM = {msg_tsd_foundfat_rus, msg_tsd_foundfat_eng};

//-----------------------------------------------------------------------------

const u8 msg_tsd_detect_rus[] PROGMEM = "���� 䠩����� ��⥬�...";
const u8 msg_tsd_detect_eng[] PROGMEM = "Detecting of file system...";
PGM_U8_P mlmsg_tsd_detect[] PROGMEM = {msg_tsd_detect_rus, msg_tsd_detect_eng};

//-----------------------------------------------------------------------------

const u8 msg_tsd_readfile_rus[] PROGMEM = "�⥭�� ��⮢��� 䠩��...";
const u8 msg_tsd_readfile_eng[] PROGMEM = "Reading of test file...";
PGM_U8_P mlmsg_tsd_readfile[] PROGMEM = {msg_tsd_readfile_rus, msg_tsd_readfile_eng};

//-----------------------------------------------------------------------------

const u8 msg_tsd_complete_rus[] PROGMEM = "�������⨪� �����襭�.";
const u8 msg_tsd_complete_eng[] PROGMEM = "Diagnostic is complete.";
PGM_U8_P mlmsg_tsd_complete[] PROGMEM = {msg_tsd_complete_rus, msg_tsd_complete_eng};

//-----------------------------------------------------------------------------

const u8 msg_tsd_out[] PROGMEM = "\r\nout ";
const u8 msg_tsd_in[] PROGMEM = ", in ";
const u8 msg_tsd_cmd[] PROGMEM = "\r\n;CMD";
const u8 msg_tsd_acmd41[] PROGMEM = "\r\n;ACMD41";
const u8 msg_tsd_csup[] PROGMEM = "\r\nCS up";
const u8 msg_tsd_csdown[] PROGMEM = "\r\nCS down";
const u8 msg_tsd_mmc[] PROGMEM = "MMC";
const u8 msg_tsd_sdv1[] PROGMEM = "SD v1";
const u8 msg_tsd_sdsc[] PROGMEM = "SD v2+ Standard Capacity";
const u8 msg_tsd_sdhc[] PROGMEM = "SD v2+ High Capacity";
const u8 msg_tsd_ocr[] PROGMEM = "OCR: ";
const u8 msg_tsd_csd[] PROGMEM = "CSD: ";
const u8 msg_tsd_cid0[] PROGMEM = "CID: ";
const u8 msg_tsd_cid1[] PROGMEM = "Manufacturer ID    ";
const u8 msg_tsd_cid2[] PROGMEM = "OEM/Application ID ";
const u8 msg_tsd_cid3[] PROGMEM = "Product name       ";
const u8 msg_tsd_cid4[] PROGMEM = "Product revision   ";
const u8 msg_tsd_cid5[] PROGMEM = "Product serial #   ";
const u8 msg_tsd_cid6[] PROGMEM = "Manufacturing date ";
const u8 msg_tsd_cid6b[] PROGMEM = ".20";
const u8 msg_tsd_cid6c[] PROGMEM = ".19";
const u8 msg_tsd_crc[] PROGMEM = "CRC=";
const u8 msg_tsd_readsector[] PROGMEM = "\r\n;Read sector ";
const u8 msg_tsd_skip[] PROGMEM = "\r\n;512 operations is skiped";

//-----------------------------------------------------------------------------

const u8 msg_trs_1[] PROGMEM =
 "\x16\x14\x03"  "�"
 "\x16\x0b\x04"  "pc/win32"
 "\x16\x17\x04"  "TESTCOM"
 "\x16\x09\x05"  "�"
 "\x16\x0b\x06"  "Bit rate 115200   No parity"
 "\x16\x0b\x07"  "Data bits 8"
 "\x16\x1d\x07"  "Flow control"
 "\x16\x0b\x08"  "Stop bits 2"
 "\x16\x1e\x08"  "� RTS/CTS"
 "\x16\x1d\x09"  "DSR - Ignored"
 "\x16\x15\x0a"  "Start BERT "
 "\x16\x19\x0b"  "�"
 "\x16\x19\x0c"  "�COM port"
 "\x16\x19\x0d"  "�"
 "\x16\x13\x0e"  "RS-232�"
 "\x16\x0c\x0f"  "�"
 "\x16\x19\x0f"  "�"
 "\x16\x05\x10"  "ZX Evo"
 "\x16\x10\x10"  "Last sec"
 "\x16\x26\x10"  "sec"
 "\x16\x03\x11"  "�"
 "\x16\x05\x12"  "RxBuff"
 "\x16\x2d\x12"  "RTS"
 "\x16\x05\x13"  "TxBuff"
 "\x16\x2d\x13"  "CTS";

//-----------------------------------------------------------------------------

//const u8 msg__rus[] PROGMEM = "";
//const u8 msg__eng[] PROGMEM = "";
//PGM_U8_P mlmsg_[] PROGMEM = {msg__rus, msg__eng};

//-----------------------------------------------------------------------------

const u8 str_menu_main[] PROGMEM =
  "���� ���������� PS/2      "
  "���� ���������� ZX � ��.  "
  "���� ���                 "
  "���� BEEP/TAPEOUT/COVOX   "
  "���� �����                "
  "���� RS-232               "
  "�������⨪� SD/MMC        "
  "�ணࠬ��஢���� Flash-ROM"

  "PS/2 keyboard test        "
  "ZX keyboard test and etc  "
  "Mouse test                "
  "BEEP/TAPEOUT/COVOX test   "
  "Video test                "
  "RS-232 test               "
  "SD/MMC diagnostic         "
  "Write Flash-ROM           ";
//"12345678901234567890123456"  width fixed!

//-----------------------------------------------------------------------------
