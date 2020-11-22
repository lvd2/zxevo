#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// for non-boot area of 0x00000..0x1DFFF
#define ADDR_RANGE (0x1E000)

// fill value
#define FILL_VALUE (0xFF)

#include "ihex.h"
#include "crc.h"


uint8_t buffer[ADDR_RANGE];

int main(int argc, char ** argv)
{
	int was_error = 0;

	uint16_t crc;


	if( argc!=3 )
	{
		printf("Fix CRC for the ZXEvo AVR firmware in order to pass bootloader CRC check.\n");
		printf("===\n");
		printf("Usage: crcfix <infile> <outfile>\n");

		if( argc==2 )
		{
			if( !strcmp(argv[1],"-h") || !strcmp(argv[1],"--help") )
				exit(0);
		}

		exit(1);
	}


	// parse input file
	was_error = was_error || !parse_ihex(buffer, 0, 0, ADDR_RANGE-2, FILL_VALUE, argv[1]);

/*
for(int i=0;i<ADDR_RANGE;i+=16)
{
printf("%05X:",i);
for(int j=0;j<16;j++)
printf("%02X",buffer[i+j]);
printf("\n");
}

buffer[0x1DFF0] = 0x4e;
buffer[0x1DFF1] = 0x6f;
buffer[0x1DFF2] = 0x20;
buffer[0x1DFF3] = 0x69;
buffer[0x1DFF4] = 0x6e;
buffer[0x1DFF5] = 0x66;
buffer[0x1DFF6] = 0x6f;
buffer[0x1DFF7] = 0x00;
buffer[0x1DFF8] = 0x00;
buffer[0x1DFF9] = 0x00;
buffer[0x1DFFA] = 0x00;
buffer[0x1DFFB] = 0x00;
buffer[0x1DFFC] = 0x76;
buffer[0x1DFFD] = 0xa9;
*/


	// calc CRC and put it into last two bytes of the buffer
	if( !was_error )
	{
		crc = calc_crc(buffer,ADDR_RANGE-2);

		buffer[ADDR_RANGE-2] = crc>>8;
		buffer[ADDR_RANGE-1] = crc;
	}



//printf("crc=%04x\n",crc);


/*
printf("<none>: %04x\n",calc_crc(NULL,0));

char * a="A";
printf("%s: %04x\n",a,calc_crc(a,strlen(a)));

a="123456789";
printf("%s: %04x\n",a,calc_crc(a,strlen(a)));

char b[256];
for(int i=0;i<256;i++) b[i]='A';
printf("256*\"A\": %04x\n",calc_crc(b,256));
*/

//printf("write_ihex! was_error=%d\n",was_error);



	// write back new IHEX with embedded CRC
	was_error = was_error || !write_ihex(buffer,0,0,ADDR_RANGE,argv[2]);



	return was_error ? 1 : 0;
}

