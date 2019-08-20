
/* last update: 20.08.2019 savelij */

#define HDD_MASTER			0
#define HDD_SLAVE			1

// нумерация устройств
#define _FDD_A				0
#define _FDD_B				1
#define _FDD_C				2
#define _FDD_D				3
#define _HDD_NEMO_MASTER		4
#define _HDD_NEMO_SLAVE			5
#define _HDD_SMUC_MASTER		6
#define _HDD_SMUC_SLAVE			7
#define _HDD_DIVIDE_MASTER		8
#define _HDD_DIVIDE_SLAVE		9
#define _HDD_PROFI_MASTER		0x0A
#define _HDD_PROFI_SLAVE		0x0B
#define _HDD_TURBO2_MASTER		0x0C
#define _HDD_TURBO2_SLAVE		0x0D
#define _SD_SDG				0x0E
#define _SD_SDZ				0x0F
#define _SL_USBF			0x10


// номера функций RST 8
#define _AY_PRN_INIT			0x40
#define _AY_PRN_A_			0x41
#define _AY_PRN_TOKEN			0x42
#define _AY_PRN_SCR			0x43
#define _TAPE_INIT			0x44
#define _TAPE_EMUL			0x45
#define _WINW				0x46
#define _PRINT_MESSAGE			0x47
#define _PRINT_A			0x48
#define _SCROLL_UP			0x49
#define _SCROLL_DOWN			0x4A
#define _SET_MODE			0x4B
#define _MATH				0x4C
#define _VERSION			0x4D

#define _BIOS				0x4F
#define _COM_DEV			0x50
#define _COM_FAT			0x51
#define _SORT_FINDFILES			0x52
#define _MOUNTER			0x53
#define _INST_FATBOOT			0x54
#define _CMOS_RW			0x55
#define _SETUP_PAL			0x56
#define _SETUP_FONT			0x57

// функции изменения режимов работы
#define _ZXSCR_MODE			0x03	// %00000001	;ZX SCREEN
#define _TXTSCR_MODE			0x06	// %00000010	;TXT SCREEN
#define _TURBO_LOW			0x10	// %00010000	;TURBO 3,5 MHZ
#define _TURBO_HIGH			0x20	// %00100000	;TURBO 7,0 MHZ
#define _TURBO_MAX			0x30	// %00110000	;TURBO 14,0 MHZ
#define _MEM_MODE_48			0x40	// %01000000	;MEMORY MODE 48 KB
#define _MEM_MODE_128			0x80	// %10000000	;MEMORY MODE 128 KB
#define _MEM_MODE_PENT			0xC0	// %11000000	;MEMORY MODE PENT 1024 KB

#define _SET_VIDEOMODE			0x08	// для включения при установке видео режима

// функции деления, умножения, преобразования числа в текст
#define _DIVIDE16			0x00
#define _MULTIPLY16			0x01
#define _DIVIDE32			0x02
#define _MULTIPLY32			0x03
#define _HEX4DECTXT			0x04
#define _HEX2DECTXT			0x05
#define _HEX1DECTXT			0x06

// функции работы с CMOS
#define _INIT_CMOS			0x00
#define _READ_CMOS			0x01
#define _WRITE_CMOS			0x02
#define _CLEAR_CMOS			0x03

// функции монтировщика образов
#define _OPEN_MOUNT			0x00	// монтирование образа
#define _RDWR_MOUNT			0x01	// чтение/запись примонтированных образов
#define _FIND_MOUNTED			0x02	// поиск монтируемых образов прописанных в IMAGE.FNT
#define _GET_MOUNTED			0x03	// получение буфера описателей примонтированных образов
#define _CLOSEMOUNT			0x04	// демонтирование образа
#define _LOADIMAGE			0x05	// загрузка образа в рамдиск
#define _REST_NAMELOAD			0x06	// получение описателя файла загруженного в рамдиск
#define _CMP_DRIVE			0x07	// проверка примонтированного образа на указанной букве
#define _GET_VIRT_BITS			0x08	// получение битов смонтированных дисков
#define _MOUNT_RAMDISK			0x09	// монтирование рамдиска

// номера функций менеджера устройств
#define _DEVFIND			0x00	// поиск устройств
#define _SET_VOL			0x01	// выбор раздела
#define _KOL_VOL			0x02	// запрос найденого
#define _GET_FNDVOLUME			0x03	// получить таблицу найденных разделов
#define _TO_DRV				0x04	// вызов драйвера выбранного устройства
#define _SET_DEVICE			0x05	// установка битов устройства и lba режима
#define _CONTROL_SD			0x06	// контроль наличия sd карт
#define _COMHDDN			0x07	// прямой вызов драйвера hdd nemo
#define _FREINIT_VOL			0x08	// полная переинициализация раздела

// номера функций вызова драйвера устройства
#define _DEV_INIT			0x00	// ПОИСК И ИНИЦИАЛИЗАЦИЯ УСТРОЙСТВА
#define _DEV_STATUS			0x01	// запрос статуса устройства. пока заглушена
#define _DEV_READ			0x02	// чтение секторов
#define _DEV_WRITE			0x03	// запись секторов
#define _DEV_READID			0x04	// чтение ID сектора

// номера вызываемых функций FAT драйвера
#define _INIT_FATVARS			0x00	// инициализация переменных FAT
#define _READ_DIR			0x01	// получение описателя файла
#define _ENTER_DIR			0x02	// вход/выход в дириректорию
#define _GET_PATH			0x03	// получение текущего пути
#define _GET_LONGNAME			0x04	// получение длинного имени файла
#define _FIND_NAME			0x05	// поиск по имени
#define _FIND_FILEITEM			0x06	// поиск всех описателей с выдачей номеров найденного
#define _SET_MASK_EXT			0x07	// установка маски расширений для поиска
#define _OPEN_FILE			0x08	// открытие файла
#define _READ_FILE			0x09	// последовательное чтение открытого файла
#define _INIT_TEKDIR			0x0A	// создание таблицы кластеров текущей директории
#define _POS_FILES			0x0B	// работа с текущей позицией

// подфункции функции _POS_FILES
#define _POSTF00			0x00	// сохранение текущей позиции файла
#define _POSTF01			0x01	// восстановление текущей позиции файла
#define _POSTF02			0x02	// сброс текущей позиции в 0 и поиск первой "легальной" записи
#define _POSTF03			0x03	// перемотать на "B" файлов назад
#define _POSTF04			0x04	// перемотать на "B" файлов вперед
#define _POSTF05			0x05	// подсчет количества "легальных" записей
#define _POSTF06			0x06	// установить номер "легальной" записи из "BC"
#define _POSTF07			0x07	// вернуть в "BC" текущий номер "легальной" записи

// номера поддерживаемых расширений для RST 8
// "TRDSCLFDITAPSPG$C FNTBMPROM"	;RST 8
// "TRDSCLFDITAPSPG$C BMPSNA"		;MAINMENU
#define _TRD				0x01	// TRD
#define _SCL				0x02	// SCL
#define _FDI				0x03	// FDI
#define _TAP				0x04	// TAP
#define _SPG				0x05	// SPG
#define _HOB				0x06	// $C
#define _FNT				0x07	// FNT
#define _BMP				0x08	// BMP
#define _ROM				0x09	// ROM
//#define _HOB1				0x0A	// $??
//#define _HOB2				0x0B	// !??

// внутренние номера типов разделов
#define _NO_INIT			0x00
#define _FAT12				0x01	// 00 = 01		FAT12
#define _FAT16				0x02	// 01 = 04,06,0E	FAT16
#define _FAT32				0x03	// 02 = 0B,0C		FAT32
#define _TRDOS				0x04	// TR-DOS диск
#define _UNKNOWN			0x05	// файловая система еще не определена или неизвестна

// описатели для рисования окна
#define _X_COORD			0x00
#define _Y_COORD			0x01
#define _V_SIZE				0x02
#define _H_SIZE				0x03
#define _COLOR_WIN			0x04
#define _COLOR_CUR			0x05
#define _FLAGS				0x06
#define _NUM_PKT			0x07
#define _TEK_PKT_L			0x08
#define _TEK_PKT_H			0x09
#define _NUM_KOL_L			0x0A
#define _NUM_KOL_H			0x0B
#define _ADR_TXT_L			0x0C
#define _ADR_TXT_H			0x0D
#define _ADR_PRG_L			0x0E
#define _ADR_PRG_H			0x0F
#define _ADR_MOUSE_L			0x10
#define _ADR_MOUSE_H			0x11
#define _ADR_HOTKEY_L			0x12
#define _ADR_HOTKEY_H			0x13
