#ifndef PS2_H
#define PS2_H

/**
 * @file
 * @brief PS/2 mouse and keyboard support.
 * @author http://www.nedopc.com
 *
 * PS/2 keyboard support (read only).
 *
 * PS/2 mouse support (read/write).
 * ZX Kempston mouse interface emulation.
 *
 * Support PS/2 mouses:
 * - "microsoft" mouses with wheel (4bytes data);
 * - classic mouses (3bytes data).
 */

/**
 * Decode received data.
 * @return decoded data.
 * @param count - counter.
 * @param shifter - received bits.
 */
UBYTE ps2_decode(UBYTE count, UWORD shifter);

/**
 * Encode (prepare) sended data.
 * @return encoded data.
 * @param data - data to send.
 */
UWORD ps2_encode(UBYTE data);

/** Timeout value for PS/2 keyboard. */
#define PS2KEYBOARD_TIMEOUT 20

/** Received PS/2 keyboard data register. */
extern volatile UWORD ps2keyboard_shifter;
/** Counter of current PS/2 keyboard data bit. */
extern volatile UBYTE ps2keyboard_count;
/** Timeout register for detecting PS/2 keyboard timeouts. */
extern volatile UBYTE ps2keyboard_timeout;

/** PS/2 keyboard task. */
void ps2keyboard_task(void);

/**
 * Parsing PS/2 keboard recived bytes .
 * @param recbyte [in] - received byte.
 */
void ps2keyboard_parse(UBYTE recbyte);

/** Timeout for waiting response from mouse. */
#define PS2MOUSE_TIMEOUT 20
/** Received/sended PS/2 mouse data register. */
extern volatile UWORD ps2mouse_shifter;
/** Counter of current PS/2 mouse data bit. */
extern volatile UBYTE ps2mouse_count;
/** Timeout register for detecting PS/2 mouse timeouts. */
extern volatile UBYTE ps2mouse_timeout;
/** Index of PS/2 mouse initialization step (@see ps2mouse_init_sequence). */
extern volatile UBYTE ps2mouse_initstep;
/** Counter of PS/2 mouse response bytes. */
extern volatile UBYTE ps2mouse_resp_count;

/** PS/2 mouse task. */
void ps2mouse_task(void);

#endif //PS2_H

