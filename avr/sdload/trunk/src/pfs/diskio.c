#include <avr/io.h>
#include <string.h>
#include "diskio.h"

#define LOGENABLE

#ifdef LOGENABLE
void rs232_transmit(BYTE data);
void to_log(char* ptr);
#define TO_LOG	to_log
#define RS232_TRANSMIT rs232_transmit
#else
#define TO_LOG(_a)
#define RS232_TRANSMIT(_a)
#endif

#define CS_HIGH	{PORTF |= 0b00100000;spi_io(0xff);}
#define CS_LOW	PORTF &= 0b11011111;

BYTE spi_io(BYTE spi){
		BYTE i=8;
		register BYTE portf = PORTF;
		do{
			portf &= 0b11101111;
			PORTF = portf;
			if(spi&0x80) {
				portf |= 0b10000000;
			}else{
				portf &= 0b01111111;
			}
			PORTF = portf; 
			spi=spi<<1;
			if(PINF & 0x40) {
				spi |= 1;
			}
			portf |= 0b00010000;
			PORTF = portf;
		}while(--i);
	return spi;
}

const BYTE CMD00[] = {0X40,0X00,0X00,0X00,0X00,0X95};
const BYTE CMD08[] = {0X48,0X00,0X00,0X01,0XAA,0X87};
const BYTE CMD16[] = {0X50,0X00,0X00,0X02,0X00,0XFF};

#define CMD_17 	0X51		//READ_SINGLE_BLOCK
#define CMD_24	0X58		//WRITE_BLOCK
#define CMD_55 	0X77		//APP_CMD
#define CMD_58 	0X7A		//READ_OCR
#define CMD_59 	0X7B		//CRC_ON_OFF
#define ACMD_41 0X69		//SD_SEND_OP_COND

/*
CMD_09          EQU 0X49        ;SEND_CSD
CMD_12          EQU 0X4C        ;STOP_TRANSMISSION
CMD_17          EQU 0X51        ;READ_SINGLE_BLOCK
CMD_18          EQU 0X52        ;READ_MULTIPLE_BLOCK
CMD_24          EQU 0X58        ;WRITE_BLOCK
CMD_25          EQU 0X59        ;WRITE_MULTIPLE_BLOCK
CMD_55          EQU 0X77        ;APP_CMD
CMD_58          EQU 0X7A        ;READ_OCR
CMD_59          EQU 0X7B        ;CRC_ON_OFF
ACMD_41         EQU 0X69        ;SD_SEND_OP_COND
*/

static BYTE sd_blsize 		= 0xff;
static BYTE writep_status 	= 0x00;

void outcom(const BYTE * cmd){
	BYTE i = 6;
	CS_LOW
	do{
		spi_io(*cmd);
		cmd++;
	}while(--i);
}

void out_com(BYTE cmd){
	CS_LOW
	spi_io(0xff);
	spi_io(0xff);
	spi_io(cmd);
	spi_io(0x00);
	spi_io(0x00);
	spi_io(0x00);
	spi_io(0x00);
	spi_io(0xff);
}

BYTE in_oout(void){
	BYTE res;
	BYTE i = 33;
	do{
		res = spi_io(0xff);
		if(res != 0xff) break;
	}while(--i);
	return res;
}

BYTE disk_initialize(void){
	if(writep_status) disk_writep(0, 0);
	CS_HIGH
	UINT i = 64;
	BYTE res;
	while (--i){
		spi_io(0xff);
	}
	i = 1024;
	do{
		outcom(CMD00);
		res = in_oout() - 1;
		CS_HIGH
		if(res == 0x00) break;
	}while(--i);
	if(res){
		TO_LOG(" (CMD00 error) ");
		return 1;
	}
	outcom(CMD08);
	res = in_oout();
	spi_io(0xff);
	spi_io(0xff);
	spi_io(0xff);
	spi_io(0xff);
	if(res & 0b00000100){
		res = 0x00;
	}else{
		res = 0x40;
	}
	i = 10000;
	do{
		CS_HIGH
		out_com(CMD_55);
		in_oout();
		spi_io(0xff);
		spi_io(0xff);
		spi_io(0xff);
		spi_io(0xff);
		spi_io(ACMD_41);
		spi_io(res);
		spi_io(0x00);
		spi_io(0x00);
		spi_io(0x00);
		spi_io(0xff);
		if(in_oout()==0x00) break;
	}while(--i);
	if(i == 0) {
		TO_LOG(" (ACMD_41 error) ");
		return 1;
	}
	
	i = 1024;
	do{
		out_com(CMD_59);
		if(in_oout()==0x00) break;
	}while(--i);
	if(i == 0) {
		TO_LOG(" (CMD_59 error) ");
		return 1;
	}
	
	i = 1024;
	do{
		outcom(CMD16);
		if(in_oout()==0x00) break;
	}while(--i);
	if(i == 0) {
		TO_LOG(" (CMD16 error) ");
		return 1;
	}
	out_com(CMD_58);
	in_oout();
	sd_blsize = spi_io(0xff) & 0x40;
	spi_io(0xff);
	spi_io(0xff);
	spi_io(0xff);
	
	CS_HIGH
	return 0x00;
}

DRESULT disk_readp (BYTE* buff, DWORD sector, UINT offset, UINT count){
	static DWORD c_sector = 0xffffffffl;
	static BYTE cache[512];
	if(sd_blsize == 0xff) return RES_NOTRDY;
	if(writep_status) return RES_ERROR;
	if(c_sector != sector){
		BYTE* c;
		if(count == 512){
			c = buff;
		}else{
			c = cache;
			c_sector = sector;
		}
		UINT i;
			CS_LOW
			spi_io(0xff);
			spi_io(0xff);
			spi_io(0xff);
			spi_io(0xff);
			if(sd_blsize == 0x00) sector *= 512;
			spi_io(CMD_17);
			spi_io(((BYTE*) &sector)[3]);
			spi_io(((BYTE*) &sector)[2]);
			spi_io(((BYTE*) &sector)[1]);
			spi_io(((BYTE*) &sector)[0]);
			spi_io(0xff);
			while((i = in_oout())!=0xfe){
				//todo убрать вечный цикл!!!
			}
		i = 512;
		while(i--){
			(*c++) = spi_io(0xff);
		}
		spi_io(0xff);
		CS_HIGH
		if(count == 512) return RES_OK;
	}
	memcpy(buff, cache + offset, count);
	return RES_OK;
}
/*
DRESULT disk_readp (BYTE* buff, DWORD sector, UINT offset, UINT count){
	if(sd_blsize == 0xff) return RES_NOTRDY;
	if(writep_status) return RES_ERROR;
	UINT skip = 512 + 2 - offset - count;
	CS_LOW
	spi_io(0xff);
	spi_io(0xff);
	if(sd_blsize == 0x00) sector *= 512;
	spi_io(CMD_17);
	spi_io(((BYTE*) &sector)[3]);
	spi_io(((BYTE*) &sector)[2]);
	spi_io(((BYTE*) &sector)[1]);
	spi_io(((BYTE*) &sector)[0]);
	spi_io(0xff);
	while(in_oout()!=0xfe);
	while(offset--) spi_io(0xff);
	while(count--){
		(*buff++) = spi_io(0xff);
	}
	while(skip--) spi_io(0xff);
	spi_io(0xff);
	CS_HIGH
	return 0x00;
}
*/

DRESULT disk_writep (const BYTE* buff, DWORD sc){
	static WORD wr_cnt;
	if(sd_blsize == 0xff) return RES_NOTRDY;
	
	if (!buff) {
		if (sc) {
			CS_LOW
			spi_io(0xff);
			spi_io(0xff);
			if(sd_blsize == 0x00) sc *= 512;
			spi_io(CMD_24);
			spi_io(((BYTE*) &sc)[3]);
			spi_io(((BYTE*) &sc)[2]);
			spi_io(((BYTE*) &sc)[1]);
			spi_io(((BYTE*) &sc)[0]);
			spi_io(0xff);
			if(in_oout() != 0X00) return RES_ERROR;
			spi_io(0xff);
			spi_io(0xfe);
			
			writep_status=1;
			wr_cnt = 512;
		} else {
			// Finalize write process
			if(writep_status == 0) return RES_NOTRDY;
			while(wr_cnt--){
				spi_io(0x00);
			}
			in_oout();
			while(spi_io(0xff) != 0xff);
			writep_status = 0x00;
			CS_HIGH
		}
	} else {
		if(writep_status == 0) return RES_NOTRDY;
		wr_cnt -= (WORD)sc;
			while(sc--){
				spi_io(*buff++);
			}
	}
	return RES_OK;
}



