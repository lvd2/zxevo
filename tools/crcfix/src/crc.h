#ifndef _CRC_C_
#define _CRC_C_


// CRC poly
#define CRC_POLY (0x1021)



// calculates "wrong" CRC16-CCITT of the given buffer
uint16_t calc_crc(uint8_t * buffer, int32_t length);


#endif // _CRC_C_
