#ifndef __ATX_H__
#define __ATX_H__

/**
 * @file
 * @brief ATX power support.
 * @author http://www.nedopc.com
 *
 * ATX power switching:
 * - switch on ATX power on start by press "soft reset" button;
 * - switch off ATX power by press "soft reset" button on 5 seconds.
 */


// constant for how long to hold soft reset or F12 to poweroff
#define PWROFF_KEY_TIME (1000)

// soft reset debouncing constant (in 20ms increments)
#define SOFT_RST_DEBOUNCE (2)

// ATX poweroff wait time (in 20ms increments)
#define PWROFF_WAIT (100)


/** Counter for atx power off delay. */
extern volatile UWORD atx_counter;

/** Wait for press "soft reset" to ATX power on. */
void wait_for_atx_power(void);

/**
 * Check for atx power off switch.
 */
void atx_power_task(void);

#endif //__ATX_H__
