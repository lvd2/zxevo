#include <stdint.h>
#include <stdio.h>

#include "ihex.h"


int parse_ihex(uint8_t * buffer, int32_t disp, int32_t low_bound, int32_t high_bound, uint8_t fill, char * filename)
{
	char buf[IHEX_BUF_SZ];

	int32_t i;

	FILE * file;






	// fill the whole buffer with given fill value
	for(i=low_bound+disp,i<high_bound+disp,i++)
		buffer[i] = fill;

	
	// parse interhex line by line
	while( fgets(buf, IHEX_BUF_SZ, file) )
	{
	}

	// we are here: EOF reached unexpectedly or error.
	if( feof(file) )
	{
		fprintf(stderr, 
	}
}


