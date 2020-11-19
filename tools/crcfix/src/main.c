#include <stdint.h>
#include <stdio.h>
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


	if( argc!=3 )
	{
		printf("Fix CRC for the AVR firmware in order to pass bootloader CRC check.\n");
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
	was_error ||= parse_ihex(buffer, 0, 0, ADDR_RANGE-2, FILL_VALUE, argv[1]);

	// calc CRC






	return 0;
}

