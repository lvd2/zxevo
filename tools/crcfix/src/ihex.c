#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <alloca.h>

#include "ihex.h"

static int get_hexnibble(char sym)
{
	if( '0'<=sym && sym<='9' )
		return sym-'0';
	else if( 'A'<=sym && sym<='F' )
		return sym-'A'+10;
	else if( 'a'<=sym && sym<='f' )
		return sym-'a'+10;

	return -1;
}

static int get_hexbyte(char * ptr)
{
	return get_hexnibble(*ptr)*16 + get_hexnibble(*(ptr+1));
}

int parse_ihex(uint8_t * buffer, int32_t disp, int32_t low_bound, int32_t high_bound, uint8_t fill, char * filename)
{
	char chbuf[IHEX_BUF_SZ];

	int32_t i;

	FILE * file;

	int line = 1;

	int was_eof = 0;

	int t;

	int32_t seg_addr = 0;



	// open the file
	file = fopen(filename, "rt");
	if( !file )
	{
		fprintf(stderr,"ERROR: can't open file <%s>: %s!\n",filename,strerror(errno));
		return 0;
	}



	// fill the whole buffer with given fill value
	for(i=low_bound+disp;i<high_bound+disp;i++)
		buffer[i] = fill;

	
	// parse interhex line by line
	while( memset(chbuf, 0, IHEX_BUF_SZ), fgets(chbuf, IHEX_BUF_SZ, file) )
	{
		if( strlen(chbuf) > MAX_IHEX_LENGTH )
		{ // check maximum length of ihex string
			fprintf(stderr,"ERROR: line %d of file <%s> is too long!\n",line,filename);
			goto GENERAL_ERROR;
		}

		// ihex line parser
		int pos=0;
		//
		int ihex_length;
		int ihex_addr;
		int ihex_type;
		int ihex_checksum;

		int curr_length;
		int datapos = 0;


		// parser states
		enum parser_states
		{
			ST_INIT,
			ST_LEN,
			ST_ADDR,
			ST_TYPE,
			ST_DATA,
			ST_CHECKSUM,
			ST_DONE
		};
		//
		enum parser_states state = ST_INIT;

		while( chbuf[pos]!='\r' && chbuf[pos]!='\n' && chbuf[pos]!=0 )
		{
			switch( state )
			{
			case ST_INIT:
				if( chbuf[pos]!=':' ) goto PARSE_ERROR;
				state = ST_LEN;
				pos++;
				break;
			case ST_LEN:
				t = get_hexbyte(chbuf+pos);
				pos+=2;
				if( t<0 ) goto PARSE_ERROR;
				state = ST_ADDR;
				ihex_length = t;
				curr_length = t;
				break;
			case ST_ADDR:
				t = get_hexbyte(chbuf+pos);
				pos+=2;
				if( t<0 ) goto PARSE_ERROR;
				ihex_addr = t*256;
				t = get_hexbyte(chbuf+pos);
				pos+=2;
				if( t<0 ) goto PARSE_ERROR;
				ihex_addr += t;
				state = ST_TYPE;
				break;
			case ST_TYPE:
				t = get_hexbyte(chbuf+pos);
				pos+=2;
				if( t<0 ) goto PARSE_ERROR;
				ihex_type = t;
				state = ST_DATA;
				break;
			case ST_DATA:
				if( curr_length>0 )
				{
					t = get_hexbyte(chbuf+pos);
					pos+=2;
					if( t<0 ) goto PARSE_ERROR;

					// reuse buffer
					chbuf[datapos++] = t;

					curr_length--;
				}
				else
				{
					state = ST_CHECKSUM;
				}
				break;
			case ST_CHECKSUM:
				t = get_hexbyte(chbuf+pos);
				pos+=2;
				if( t<0 ) goto PARSE_ERROR;
				ihex_checksum = t;
				state = ST_DONE;
				break;
			default: // incl. ST_DONE
				goto PARSE_ERROR;
			}
		}

		// parse succeeded - checksum test
		t=0;
		for(i=0;i<ihex_length;i++)
			t+=chbuf[i];
		t+=ihex_length;
		t+=ihex_addr>>8;
		t+=ihex_addr;
		t+=ihex_type;
		t+=ihex_checksum;

		if( t&255 )
		{
			fprintf(stderr,"ERROR: line %d of file <%s>: checksum error!\n",line,filename);
			goto GENERAL_ERROR;
		}

		if( was_eof )
		{
			fprintf(stderr,"ERROR: line %d of file <%s>: ihex record encountered after EOF record!\n",line,filename);
			goto GENERAL_ERROR;
		}

		// apply ihex line
		switch( ihex_type )
		{
		case IHEX_TYPE_DATA:
			// should be non-zero length
			if( ihex_length<=0 )
			{
				fprintf(stderr,"ERROR: line %d of file <%s>: data record has zero length!\n",line,filename);
				goto GENERAL_ERROR;
			}
			// put data into buffer, also check ranges
			for(i=0;i<ihex_length;i++)
			{
				int32_t addr = seg_addr*16 + ihex_addr + i;
				if( addr<low_bound || high_bound<=addr )
				{
					fprintf(stderr,"ERROR: line %d of file <%s>: data record gets outside the range %x..%x!\n",line,filename,low_bound,high_bound);
					goto GENERAL_ERROR;
				}
				else
				{
					buffer[disp+addr] = chbuf[i];
				}
			}
			break;
		case IHEX_TYPE_SEGADDR:
			// set up new segment addr
			if( ihex_length!=2 )
			{
				fprintf(stderr,"ERROR: line %d of file <%s>: segment address record wrong length (must be 2)!\n",line,filename);
				goto GENERAL_ERROR;
			}
			seg_addr = ((uint8_t)chbuf[0])*256 + ((uint8_t)chbuf[1]);
			break;
		case IHEX_TYPE_EOF:
			if( ihex_length!=0 )
			{
				fprintf(stderr,"ERROR: line %d of file <%s>: EOF record wrong length (must be 0)!\n",line,filename);
				goto GENERAL_ERROR;
			}
			was_eof = 1;
			break;
		default: // unknown or unsupported record type
			fprintf(stderr,"ERROR: line %d of file <%s>: unknown record type %d!\n",line,filename,ihex_type);
			goto GENERAL_ERROR;
		}

		line++;
	}

	// EOF reached or error.
	if( feof(file) )
	{
		if( was_eof )
		{
			fclose(file);
			return 1;
		}

		fprintf(stderr, "file <%s>: unexpected EOF!\n",filename);
	}
	else if( ferror(file) )
	{
		fprintf(stderr, "file <%s>: %s!\n",filename,strerror(errno));
	}
	else
	{
		fprintf(stderr, "file <%s>: unknown error!\n",filename);
	}
	goto GENERAL_ERROR;


PARSE_ERROR:
	fprintf(stderr,"ERROR: line %d of file <%s>: parse error!\n",line,filename);
GENERAL_ERROR:
	fclose(file);
	return 0;
}





static char get_hex_nibble(uint8_t value)
{
	value &= 0x0F;

	if( value<10 )
		return value+'0';
	else
		return value-10+'A';
}

static void write_hex_value(char * buf, uint8_t value, uint8_t * checksum)
{
	buf[0] = get_hex_nibble(value>>4);
	buf[1] = get_hex_nibble(value);

	if( checksum )
		*checksum += value;
}

static int write_ihex_line(FILE * file, uint8_t type, uint16_t addr, uint8_t * buffer, int32_t length)
{
	if( length<0 || length>255 )
	{
		fprintf(stderr, "ERROR: attempt to generate ihex line with wrong length %d!\n",length);
		return 0;
	}

	uint32_t chlen = length*2 + 12;
	
	char * chbuf = alloca(chlen);
	memset(chbuf,0,chlen);

	uint32_t chpos = 0;

	uint8_t checksum = 0;


	// fill buffer
	chbuf[chpos++] = ':';

	// length
	write_hex_value(&chbuf[chpos], length, &checksum); chpos+=2;

	// address
	write_hex_value(&chbuf[chpos], addr>>8, &checksum); chpos+=2;
	write_hex_value(&chbuf[chpos], addr   , &checksum); chpos+=2;

	// type
	write_hex_value(&chbuf[chpos], type, &checksum); chpos+=2;

	// data
	for(int32_t i=0;i<length;i++)
	{
		write_hex_value(&chbuf[chpos], buffer[i], &checksum);
		chpos+=2;
	}

	// checksum
	write_hex_value(&chbuf[chpos], 1+(~checksum), NULL); chpos+=2;

	// string zero termination
	chbuf[chpos++] = 0;

	if( chpos!=chlen )
	{
		fprintf(stderr, "FATAL ERROR: wrong buffer allocation size!\n");
//printf("chpos=%d, chlen=%d, length=%d\n",chpos,chlen,length);
		exit(1);
	}

	// put string to file
	if( fprintf(file,"%s\n",chbuf) < 0 )
	{
		fprintf(stderr,"ERROR: can't write to the output file: %s!\n",strerror(errno));
		return 0;
	}

	return 1;
}

int write_ihex(uint8_t * buffer, int32_t disp, int32_t low_bound, int32_t high_bound, char * filename)
{
	FILE * file;


	// create file
	file = fopen(filename, "wt");
	if( !file )
	{
		fprintf(stderr,"ERROR: can't create file <%s>: %s!\n",filename,strerror(errno));
		return 0;
	}


	int32_t prev_seg_addr = (-1);


	int32_t beg_addr;




	beg_addr = low_bound;


	while( beg_addr<high_bound )
	{
		int32_t end_addr = (beg_addr & (~15)) + 16;

		if( end_addr>high_bound )
			end_addr = high_bound;

//printf("beg_addr: %05X\n",beg_addr);

		// generate segment addr, if needed
		int32_t seg_addr, addr;

		addr = beg_addr & 0x0FFFF;
		seg_addr = (beg_addr - addr) >> 4;
		if( seg_addr != prev_seg_addr )
		{
			uint8_t buf[2];
			buf[0] = seg_addr>>8;
			buf[1] = seg_addr;

			if( !write_ihex_line(file, IHEX_TYPE_SEGADDR, 0, buf, 2) )
			{
				fclose(file);
				return 0;
			}
			
			prev_seg_addr = seg_addr;
		}


		// generate data
		if( !write_ihex_line(file, IHEX_TYPE_DATA, addr, &buffer[disp+beg_addr], (end_addr-beg_addr)) )
		{
			fclose(file);
			return 0;
		}

		beg_addr = end_addr;
	}

	
	// generate EOF record
	if( !write_ihex_line(file, IHEX_TYPE_EOF, 0, NULL, 0) )
	{
		fclose(file);
		return 0;
	}


	fclose(file);
	return 1;
}

