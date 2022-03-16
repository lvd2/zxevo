#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include <util/delay.h>

#include "mytypes.h"
#include "depacker_dirty.h"
#include "getfaraddress.h"
#include "pins.h"
#include "main.h"
#include "ps2.h"
#include "zx.h"
#include "spi.h"
#include "rs232.h"
#include "rtc.h"
#include "atx.h"
#include "joystick.h"
#include "tape.h"
#include "kbmap.h"
void pff_test(void);
/*
uint8_t disk_initialize (void);
uint8_t disk_readp (uint8_t* buff, uint32_t sector, uint16_t offser, uint16_t count);
uint8_t disk_writep (const uint8_t* buff, uint32_t sc);
*/
//if want Log than comment next string
//#undef LOGENABLE
#define LOGENABLE

/** FPGA data pointer [far address] (linker symbol). */
extern const ULONG fpga PROGMEM;

// FPGA data index..
volatile ULONG curFpga;

// Common flag register.
volatile UBYTE flags_register;
volatile UBYTE flags_ex_register;

// Common modes register.
volatile UBYTE modes_register;

// Type extensions of gluk registers
volatile UBYTE ext_type_gluk;

// Buffer for depacking FPGA configuration.
// You can USED for other purposed after setup FPGA.
UBYTE dbuf[DBSIZE];

void put_buffer(UWORD size)
{
	// writes specified length of buffer to the output
	UBYTE * ptr = dbuf;

	do
	{
		spi_send( *(ptr++) );

	} while(--size);
}

void hardware_init(void)
{
	//Initialized AVR pins

	cli(); // disable interrupts

	// configure pins
    WDTCR = 0B00011111;
    WDTCR = 0x00;
	PORTG = 0b11111111;
	DDRG  = 0b00000000; // inputs pulled up

	// reset value for PORTF is zero (incl. ATX poweron pin),
	// if no HW reset happens, it keeps previous value
	//
	///PORTF = 0b11110000; // ATX off (zero output), fpga config/etc inputs
	
	MCUCSR |= 0x80;
	MCUCSR |= 0x80;
	PORTF |=   0b11110000 ;
	PORTF &= ~(0b00000111);
	DDRF   =   0b10111000;
	MCUCSR |= 0x80;

	PORTE = 0b11110011;
	DDRE  = 0b00000000; // PLL to 2X [E2=Z,E3=Z], inputs pulled up

	PORTD = 0b11111111; // inputs pulled up
	DDRD  = 0b00100000; // RTS out


	PORTC = 0b11011111;
	DDRC  = 0b00000000; // PWRGOOD input, other pulled up

	PORTB = 0b11000001;
	DDRB  = 0b10000111; // LED off, spi outs inactive

	PORTA = 0b11111111;
	DDRA  = 0b00000000; // pulled up

	ACSR = 0x80; // DISABLE analog comparator
}

int main()
{
start:

	hardware_init();

	rs232_init();
#ifdef LOGENABLE
	to_log("VER:");
	{
	 	UBYTE b,i;
		ULONG version = 0x1DFF0;
	 	char VER[]="..";
	 	for( i=0; i<12; i++)
	 	{
			dbuf[i] = pgm_read_byte_far(version+i);
	 	}
	 	dbuf[i]=0;
	 	to_log((char*)dbuf);
	 	to_log(" ");
	 	UBYTE b1 = pgm_read_byte_far(version+12);
	 	UBYTE b2 = pgm_read_byte_far(version+13);
	 	UBYTE day = b1&0x1F;
	 	UBYTE mon = ((b2<<3)+(b1>>5))&0x0F;
	 	UBYTE year = (b2>>1)&0x3F;
	 	VER[0] = '0'+(day/10);
	 	VER[1] = '0'+(day%10);
     	to_log(VER);
     	to_log(".");
	 	VER[0] = '0'+(mon/10);
	 	VER[1] = '0'+(mon%10);
     	to_log(VER);
     	to_log(".");
	 	VER[0] = '0'+(year/10);
	 	VER[1] = '0'+(year%10);
     	to_log(VER);
     	to_log("\r\n");
	 	//
	 	for( i=0; i<16; i++)
	 	{
	 		b = pgm_read_byte_far(version+i);
	 		VER[0] = ((b >> 4) <= 9 )?'0'+(b >> 4):'A'+(b >> 4)-10;
	 		VER[1] = ((b & 0x0F) <= 9 )?'0'+(b & 0x0F):'A'+(b & 0x0F)-10;
	 		to_log(VER);
	 	}
	 	to_log("\r\n");
	}
#endif

	wait_for_atx_power();

	spi_init();


	pff_test();
	// config loop
#if 0
	do
	{
		// power led OFF
		LED_PORT |= 1<<LED;

		DDRF |= (1<<nCONFIG); // pull low for a time
		_delay_ms(20);
		DDRF &= ~(1<<nCONFIG);
		while( !(PINF & (1<<nSTATUS)) ); // wait ready

		curFpga = GET_FAR_ADDRESS(fpga); // prepare for data fetching
#ifdef LOGENABLE
		{
		char log_fpga[]="F........\r\n";
		UBYTE b = (UBYTE)((curFpga>>24)&0xFF);
		log_fpga[1] = ((b >> 4) <= 9 )?'0'+(b >> 4):'A'+(b >> 4)-10;
		log_fpga[2] = ((b & 0x0F) <= 9 )?'0'+(b & 0x0F):'A'+(b & 0x0F)-10;
		b = (UBYTE)((curFpga>>16)&0xFF);
		log_fpga[3] = ((b >> 4) <= 9 )?'0'+(b >> 4):'A'+(b >> 4)-10;
		log_fpga[4] = ((b & 0x0F) <= 9 )?'0'+(b & 0x0F):'A'+(b & 0x0F)-10;
		b = (UBYTE)((curFpga>>8)&0xFF);
		log_fpga[5] = ((b >> 4) <= 9 )?'0'+(b >> 4):'A'+(b >> 4)-10;
		log_fpga[6] = ((b & 0x0F) <= 9 )?'0'+(b & 0x0F):'A'+(b & 0x0F)-10;
		b = (UBYTE)(curFpga&0xFF);
		log_fpga[7] = ((b >> 4) <= 9 )?'0'+(b >> 4):'A'+(b >> 4)-10;
		log_fpga[8] = ((b & 0x0F) <= 9 )?'0'+(b & 0x0F):'A'+(b & 0x0F)-10;
	 	to_log(log_fpga);
		}
#endif
		depacker_dirty();
#ifdef LOGENABLE
		to_log("depacker_dirty OK\r\n");
#endif

		// power led ON
		LED_PORT &= ~(1<<LED);

		// wait a bit and check CONF_DONE
		_delay_ms(20);
	} while( !(CONF_DONE_PIN & (1<<CONF_DONE)) );
#endif


	//power led OFF
	LED_PORT |= 1<<LED;

	// start timer (led dimming and timeouts for ps/2)
	TCCR2 = 0b01110011; // FOC2=0, {WGM21,WGM20}=01, {COM21,COM20}=11, {CS22,CS21,CS20}=011
	                    // clk/64 clocking,
	                    // 1/512 overflow rate, total 11.059/32768 = 337.5 Hz interrupt rate
	TIFR = (1<<TOV2);
	TIMSK = (1<<TOIE2);


	//init some counters and registers
	ps2keyboard_init();

	ps2mouse_count = 12;
	ps2mouse_initstep = 0;
	ps2mouse_resp_count = 0;
	ps2mouse_cmd = PS2MOUSE_CMD_SET_RESOLUTION;
	flags_register = 0;
	flags_ex_register = 0;
	modes_register = 0;
	ext_type_gluk = 0;

	//reset ps2 keyboard log
	ps2keyboard_reset_log();

	//enable mouse
	zx_mouse_reset(1);

	//set external interrupt
	//INT4 - PS2 Keyboard  (falling edge)
	//INT5 - PS2 Mouse     (falling edge)
	//INT6 - SPI  (falling edge)
	//INT7 - RTC  (falling edge)
	EICRB = (1<<ISC41)+(0<<ISC40) + (1<<ISC51)+(0<<ISC50) + (1<<ISC61)+(0<<ISC60) + (1<<ISC71)+(0<<ISC70); // set condition for interrupt
	EIFR = (1<<INTF4)|(1<<INTF5)|(1<<INTF6)|(1<<INTF7); // clear spurious ints there
	EIMSK |= (1<<INT4)|(1<<INT5)|(1<<INT6)|(1<<INT7); // enable

	kbmap_init();
	zx_init();
	rtc_init();

#ifdef LOGENABLE
	to_log("zx_init OK\r\n");
#endif

	sei(); // globally go interrupting

	//set led on keyboard
	ps2keyboard_send_cmd(PS2KEYBOARD_CMD_SETLED);
#ifdef LOGENABLE
/*
	if(disk_initialize()) to_log("sd_init ERR\r\n");
	else {
		static uint8_t buf[512];
		to_log("sd_init OK\r\n");
		disk_readp(buf,1,0,512);
		uint16_t i = 0;
		rs232_transmit('$');
		while(i != 512){
			rs232_transmit(buf[i]);
			i++;
		}
		rs232_transmit('$');
		rs232_transmit(disk_writep(0,1)+'0');
		rs232_transmit(disk_writep("test223456OK",12)+'0');
		rs232_transmit(disk_writep(0,0)+'0');
		rs232_transmit(disk_readp(buf,1,0,512)+'0');
		i = 0;
		rs232_transmit('#');
		while(i != 60){
			rs232_transmit(buf[i]);
			i++;
		}
		rs232_transmit('#');
		
	}
*/
#endif

	//main loop
	do
	{
		tape_task();
		ps2mouse_task();
		ps2keyboard_task();
		zx_task(ZX_TASK_WORK);
		zx_mouse_task();
		joystick_task();
		rs232_task();

		//event from SPI
		if ( flags_register&FLAG_SPI_INT )
		{
			//get status byte
			UBYTE status;
			nSPICS_PORT &= ~(1<<nSPICS);
			nSPICS_PORT |= (1<<nSPICS);
			status = spi_send(0);
			zx_wait_task( status );
		}

		atx_power_task(); // must be last in loop!
	}
	while( (flags_register&FLAG_HARD_RESET) == 0 );

	goto start;
}
