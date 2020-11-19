#ifndef _IHEX_C_
#define _IHEX_C_

// max length of bytes in ihex is 255, thus 512+ chars maximum length. So the value below is sane.
#define IHEX_BUF_SZ (1024)

// parses intelhex file into the memory area so that low_bound<=every byte's address<high_bound.
//
// when a byte is put in the buffer, a 'disp' value is added to its address to
// make index into 'buffer' array.
//
// it is assumed that low_bound+disp .. high_bound+disp-1 are all valid indices
// into the 'buffer' array
// 
// unspecified bytes are filled with 'fill' value.
//
// returns zero in case of any errors, otherwise non-zero.
//
// detected errors:
// - any of file errors
// - intelhex format errors (incl. unknown record types)
// - addressing errors (any byte from intelhex goes outside bounds)
// an appropriate error message is printed into stderr
//
int parse_ihex(uint8_t * buffer, int32_t disp, int32_t low_bound, int32_t high_bound, uint8_t fill, char * filename);


#endif // _IHEX_C_

