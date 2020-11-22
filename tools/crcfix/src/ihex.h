#ifndef _IHEX_C_
#define _IHEX_C_

// max length of bytes in ihex is 255, thus 512+ chars maximum length. So the value below is sane.
#define IHEX_BUF_SZ (1024)

// maximum sane length of ihex line:
//   1 : semicolon
//   2 : byte length
//   4 : word address
//   2 : byte type
// 510 : hex string of max 255 bytes
//   2 : byte checksum
//   2 : newlines
// =523 bytes
#define MAX_IHEX_LENGTH (523)

// types of IHEX recors
#define IHEX_TYPE_DATA     (0)
#define IHEX_TYPE_EOF      (1)
#define IHEX_TYPE_SEGADDR  (2)
#define IHEX_TYPE_STARTSEG (3)
#define IHEX_TYPE_ELINADDR (4)
#define IHEX_TYPE_STARTLIN (5)



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
int parse_ihex(uint8_t * buffer, int32_t disp, int32_t low_bound, int32_t high_bound, uint8_t fill, char * filename);


// writes intelhex from memory buffer. addresses are from low_bound to high_bound,
// indices in the buffer are from low_bound+disp to high_bound+disp.
//
// returns zero in case of any errors, otherwise non-zero.
int write_ihex(uint8_t * buffer, int32_t disp, int32_t low_bound, int32_t high_bound, char * filename);

#endif // _IHEX_C_

