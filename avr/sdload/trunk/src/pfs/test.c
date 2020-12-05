#include "pff.h"		/* Petit FatFs configurations and declarations */
#include <avr/io.h>
#include <util/delay.h>
#include "../pins.h"
#include <string.h>

extern BYTE dbuf[];
//BYTE spi_io(BYTE spi);
void rs232_transmit(BYTE data);
BYTE rs232_receive(void);
void to_log(char* ptr);
void put_buffer(WORD size);

FATFS fs;
DIR dir;
FILINFO fi;
void pff_test(void){
	UINT res;
	do
	{
		//PORTF &= 0b11011111;
		//while(spi_io(0xff)) {}
		res = pf_mount(&fs);
		to_log("\r\npf_mount: ");
		rs232_transmit(res + '0');
		if(res){
			continue;
		}
		to_log("\r\npf_opendir: ");
		rs232_transmit(pf_opendir(&dir,"")+'0');
		to_log("\r\nselect conf:\r\n");
		res = 1;
		while(1){
			pf_readdir(&dir, &fi);
			if(fi.fname[0]==0x00) break;
			if(strstr(fi.fname, ".RBF") == ((void*) 0x0000)) continue;
			rs232_transmit(res+'0');
			to_log(": ");
			to_log(fi.fname);
			to_log("\r\n");
			res++;
		}
		unsigned char i = 0;
		while(--i){
			if((res = rs232_receive())!=0x00) break;
			_delay_ms(20);
		}
		//rs232_transmit(res);
		if(res) {
			res = res - '0';
		}
		
		pf_opendir(&dir,"");
		while(res){
			pf_readdir(&dir, &fi);
			if(fi.fname[0]==0x00) break;
			if(strstr(fi.fname, ".RBF") == ((void*) 0x0000)) continue;
			res--;
		}
		to_log(fi.fname);
		
		
		// power led OFF 
		LED_PORT |= 1<<LED;

		DDRF |= (1<<nCONFIG); // pull low for a time
		_delay_ms(20);
		DDRF &= ~(1<<nCONFIG);
		while( !(PINF & (1<<nSTATUS)) ); // wait ready
		if(fi.fname[0])	{
			res = pf_open(fi.fname);
		}else{
			res = pf_open("TOP.RBF");
		}
		to_log("\r\npf_open: ");
		rs232_transmit(res + '0');
		if(res){
			continue;
		
		}
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