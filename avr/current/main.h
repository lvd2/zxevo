#ifndef __MAIN_H__
#define __MAIN_H__

/**
 * @mainpage  General program for ATMEGA128 ZX Evolution.
 *
 * @section history Revision history
 *
 * @subsection current Current version.
 *
 * - Fix PS/2 mouse error handler (analize error and reinit mouse if need it).
 * - Add support for get version info (via Gluk cmos extra registers 0xF0..0xFF).
 * - Optimize sources, some correction (log, fpga load).
 * - Fix PS/2 timeout error handler.
 *
 * @subsection ver_2010_03_24 Version 24.03.2010
 *
 * - Fix Power Led behavior (it off while atx power off).
 * - "Print Screen" PS2 keyboard key set NMI on ZX.
 * - Soft reset (Z80 only) to service (0) page if pressed "softreset" key <5 seconds.
 *
 * @subsection ver_2010_03_10 Version 10.03.2010
 *
 * - Add PS2 keyboard led controlling: "Scroll Lock" led equal VGA mode.
 * - Fix mapping gluk (DS12887) nvram to PCF8583.
 * - Fix Update Flag in register C (emulation Gluk clock).
 * - Add modes register and save/restore it to RTC NVRAM.
 * - Add support for zx (mechanical) keyboard.
 * - Add support for Kempston joystick.
 *
 * @subsection ver_2010_02_04 Version 04.02.2010 - base version (1.00 in SVN).
 *
 */

/**
 * @file
 * @brief Main module.
 * @author http://www.nedopc.com
 */

/** Common flag register. */
extern volatile UBYTE flags_register;
/** Direction for ps2 mouse data (0 - Receive/1 - Send). */
#define FLAG_PS2MOUSE_DIRECTION 0x01
/** Type of ps2 mouse (0 - classical [3bytes in packet]/1 - msoft [4bytes in packet]). */
#define FLAG_PS2MOUSE_TYPE      0x02
/** Ps2 mouse data for zx (0 - not ready/1 - ready). */
#define FLAG_PS2MOUSE_ZX_READY  0x04
/** Spi interrupt detected (0 - not received/1 - received). */
#define FLAG_SPI_INT            0x08
/** Direction for ps2 keyboard data (0 - Receive/1 - Send). */
#define FLAG_PS2KEYBOARD_DIRECTION  0x10
/** Version type (0 - BaseConf /1 - BootLoader). */
#define FLAG_VERSION_TYPE       0x20

/** Common modes register. */
extern volatile UBYTE modes_register;
/** VGA mode (0 - not set/1 - set). */
#define MODE_VGA 0x01

/** Data buffer. */
extern UBYTE dbuf[];

/** FPGA data index. */
ULONG curFpga;

/** FPGA data pointer [far address] (linker symbol). */
extern const ULONG fpga;

/**
 * Writes specified length of buffer to SPI.
 * @param size [in] - size of buffer.
 */
void put_buffer(UWORD size);


#endif //__MAIN_H__
