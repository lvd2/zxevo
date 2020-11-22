#include <stdint.h>

#include "crc.h"

uint16_t calc_crc(uint8_t * buffer, int32_t length)
{
	static int crc_table_initialized = 0;

	static uint16_t crc_table[256];


	uint16_t crc;


	// initialize crc table, if needed
	if( !crc_table_initialized )
	{
		for(int i=0;i<256;i++)
		{
			crc = i<<8;

			for(int j=0;j<8;j++)
				crc = (crc<<1) ^ ((crc & 0x8000) ? CRC_POLY : 0);

			crc_table[i] = crc;
		}

		crc_table_initialized = 1;
	}


	// IV
	crc = 0xFFFF;

	// byte loop
	for(int32_t i=0;i<length;i++)
	{
		crc = crc_table[ (crc>>8) ^ buffer[i] ] ^ (crc<<8);
	}

	return crc;
}
