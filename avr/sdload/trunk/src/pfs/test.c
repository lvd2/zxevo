#include "pff.h"		/* Petit FatFs configurations and declarations */
#include <avr/io.h>
#include <util/delay.h>
#include "../pins.h"

extern BYTE dbuf[];

void rs232_transmit(BYTE data);
void to_log(char* ptr);
void put_buffer(WORD size);

FATFS fs;
DIR dir;
FILINFO fi;
void pff_test(void){
	UINT res;
	to_log("\r\npf_mount: ");
	rs232_transmit(pf_mount(&fs)+'0');
	do
	{
		// power led OFF
		LED_PORT |= 1<<LED;

		DDRF |= (1<<nCONFIG); // pull low for a time
		_delay_ms(20);
		DDRF &= ~(1<<nCONFIG);
		while( !(PINF & (1<<nSTATUS)) ); // wait ready
		to_log("\r\npf_open: ");
		rs232_transmit(pf_open("TOP.RBF")+'0');
		to_log("\r\npf_read");
		while(pf_read(dbuf, 2048, &res)==0x00){
			rs232_transmit('.');
			if(res == 0x0000) break;
			put_buffer(res);
		}
		LED_PORT &= ~(1<<LED);
		_delay_ms(20);
	} while( !(CONF_DONE_PIN & (1<<CONF_DONE)) );
		
	/*
	rs232_transmit(pf_opendir(&dir,"")+'0');
	to_log("\r\nread dir:\r\n");
	while(1){
		pf_readdir(&dir, &fi);
		if(fi.fname[0]==0x00) break;
		to_log(fi.fname);
	to_log("\r\n");
	}
	*/
}