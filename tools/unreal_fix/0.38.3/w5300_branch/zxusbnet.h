#ifndef zxusbnet_h
#define zxusbnet_h

void 			pXXAB_Write(unsigned port, unsigned char val);
unsigned char 	pXXAB_Read(unsigned port);

int 			Wiz5300_Init(void);
int 			Wiz5300_Close(void);
unsigned char 	Wiz5300_RegRead(unsigned int Addr);
void 			Wiz5300_RegWrite(unsigned int Addr, unsigned char Data);

#endif
