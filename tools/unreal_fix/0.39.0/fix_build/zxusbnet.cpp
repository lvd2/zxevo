#include "std.h"
#include "emul.h"
#include "vars.h"
#include "zxusbnet.h"
#include <IPHlpApi.h>

#define buf_size 8*1024

//#define dbgmod
#ifdef dbgmod
#define DPRINTF printf
#else
#define DPRINTF(pa,pb)
#endif // dbgmod

#define WRITE_REG_FUNC(f_n) void f_n(sInfoStruct * s, u_char d, u_char z)
#define READ_REG_FUNC(f_n) u_char f_n(sInfoStruct * s, u_char z)


enum class TCP_STATE{
	NONE, CLIENT_CONNECTED, LISTEN_CONNECTED, CLIENT, LISTEN, CLOSED
};

/************************************/
/* The bit of MR regsiter defintion */
/************************************/
#define MR_DBW             (1 << 15)            /**< Data bus width bit of MR. */
#define MR_MPF             (1 << 14)            /**< Mac layer pause frame bit of MR. */
#define MR_WDF(X)          ((X & 0x07) << 11)   /**< Write data fetch time bit of  MR. */
#define MR_RDH             (1 << 10)            /**< Read data hold time bit of MR. */
#define MR_FS              (1 << 8)             /**< FIFO swap bit of MR. */
#define MR_RST             (1 << 7)             /**< S/W reset bit of MR. */
#define MR_MT              (1 << 5)             /**< Memory test bit of MR. */
#define MR_PB              (1 << 4)             /**< Ping block bit of MR. */
#define MR_PPPoE           (1 << 3)             /**< PPPoE bit of MR. */
#define MR_DBS             (1 << 2)             /**< Data bus swap of MR. */
#define MR_IND             (1 << 0)             /**< Indirect mode bit of MR. */


/***************************************/
/* The bit of Sn_MR regsiter defintion */
/***************************************/
#define Sn_MR_ALIGN        (1 << 8)             /**< Alignment bit of Sn_MR. */
#define Sn_MR_MULTI        (1 << 7)             /**< Multicasting bit of Sn_MR. */
#define Sn_MR_MF           (1 << 6)             /**< MAC filter bit of Sn_MR. */
#define Sn_MR_IGMPv        (1 << 5)             /**< IGMP version bit of Sn_MR. */
#define Sn_MR_ND           (1 << 5)             /**< No delayed ack bit of Sn_MR. */
#define Sn_MR_CLOSE        0x00                 /**< Protocol bits of Sn_MR. */
#define Sn_MR_TCP          0x01                 /**< Protocol bits of Sn_MR. */
#define Sn_MR_UDP          0x02                 /**< Protocol bits of Sn_MR. */
#define Sn_MR_IPRAW        0x03                 /**< Protocol bits of Sn_MR. */
#define Sn_MR_MACRAW       0x04                 /**< Protocol bits of Sn_MR. */
#define Sn_MR_PPPoE        0x05                 /**< Protocol bits of Sn_MR. */

/******************************/
/* The values of CR defintion */
/******************************/
#define Sn_CR_OPEN         0x01                 /**< OPEN command value of Sn_CR. */
#define Sn_CR_LISTEN       0x02                 /**< LISTEN command value of Sn_CR. */
#define Sn_CR_CONNECT      0x04                 /**< CONNECT command value of Sn_CR. */
#define Sn_CR_DISCON       0x08                 /**< DISCONNECT command value of Sn_CR. */
#define Sn_CR_CLOSE        0x10                 /**< CLOSE command value of Sn_CR. */
#define Sn_CR_SEND         0x20                 /**< SEND command value of Sn_CR. */
#define Sn_CR_SEND_MAC     0x21                 /**< SEND_MAC command value of Sn_CR. */ 
#define Sn_CR_SEND_KEEP    0x22                 /**< SEND_KEEP command value of Sn_CR */
#define Sn_CR_RECV         0x40                 /**< RECV command value of Sn_CR */
#define Sn_CR_PCON         0x23                 /**< PCON command value of Sn_CR */
#define Sn_CR_PDISCON      0x24                 /**< PDISCON command value of Sn_CR */ 
#define Sn_CR_PCR          0x25                 /**< PCR command value of Sn_CR */
#define Sn_CR_PCN          0x26                 /**< PCN command value of Sn_CR */
#define Sn_CR_PCJ          0x27                 /**< PCJ command value of Sn_CR */

/**********************************/
/* The values of Sn_SSR defintion */
/**********************************/
#define SOCK_CLOSED        0x00                 /**< SOCKETn is released */
#define SOCK_ARP           0x01                 /**< ARP-request is transmitted in order to acquire destination hardware address. */
#define SOCK_INIT          0x13                 /**< SOCKETn is open as TCP mode. */
#define SOCK_LISTEN        0x14                 /**< SOCKETn operates as "TCP SERVER" and waits for connection-request (SYN packet) from "TCP CLIENT". */
#define SOCK_SYNSENT       0x15                 /**< Connect-request(SYN packet) is transmitted to "TCP SERVER". */
#define SOCK_SYNRECV       0x16                 /**< Connect-request(SYN packet) is received from "TCP CLIENT". */
#define SOCK_ESTABLISHED   0x17                 /**< TCP connection is established. */
#define SOCK_FIN_WAIT      0x18                 /**< SOCKETn is closing. */
#define SOCK_CLOSING       0x1A                 /**< SOCKETn is closing. */
#define SOCK_TIME_WAIT     0x1B                 /**< SOCKETn is closing. */
#define SOCK_CLOSE_WAIT    0x1C                 /**< Disconnect-request(FIN packet) is received from the peer. */
#define SOCK_LAST_ACK      0x1D                 /**< SOCKETn is closing. */
#define SOCK_UDP           0x22                 /**< SOCKETn is open as UDP mode. */
#define SOCK_IPRAW         0x32                 /**< SOCKETn is open as IPRAW mode. */
#define SOCK_MACRAW        0x42                 /**< SOCKET0 is open as MACRAW mode. */
#define SOCK_PPPoE         0x5F                 /**< SOCKET0 is open as PPPoE mode. */


union LONG_CHAR{
	u_long ul;
	u_char b[4];
};


static struct sInfoStruct
{
	SOCKET s; //socket
	sockaddr_in sa_in;
	u_char PORTR[2];
	WSAEVENT Event;
	u_char MR[2];
	u_char CR;
	TCP_STATE tcpState;
	u_long RX_RSR;
	u_char rx[buf_size + 8];
	u_char * rx_ptr;
	LONG_CHAR TX_WRSR;
	u_char tx[buf_size];
	u_char * tx_ptr;
	SOCKET list; //socket
}soc[8];
static char myIP[4];
static sockaddr_in sa_in;
static u_long len_test;
static TIMEVAL select_timeout;
static u_char stat_regs[0x0100]; 
static u_char regs[sizeof(stat_regs)];
static int ns, iResult;
static u_char data;
static char * s_ptr;
static fd_set fd_s;
static fd_set fd_s1;
static u_long is_blocked = 0, non_blocked = 1;
WSADATA wsaData;

void WizRecv(sInfoStruct * s){
	if (s->rx_ptr)return;
	int len=0;
	if (s->MR[1] == Sn_MR_TCP){
		len = recv(s->s, (char*)&s->rx[2], buf_size, 0);
	}
	else{
		iResult = sizeof(s->sa_in);
		len=recvfrom(s->s, (char*)&s->rx[8], buf_size, 0, (sockaddr *)&s->sa_in, &iResult);
	}
	if(len>0)DPRINTF("Recv %d bytes\r\n", len);
	switch (len)
	{
	case -1:
		return;
	case 0:
		if (s->MR[1] == Sn_MR_TCP)
			s->tcpState = TCP_STATE::CLOSED;
		return;
	default:
		break;
	}
	//unsigned char * p = s->rx;
	if (s->MR[1] == Sn_MR_TCP)
	{
		s->rx[0] = (len & 0xff00) >> 8;
		s->rx[1] = len & 0x00ff;
		s->RX_RSR = (len + 3) & 0x0001fffe;
	}
	else{
		*((ULONG*)s->rx) = s->sa_in.sin_addr.S_un.S_addr;
		*((u_short*)&s->rx[4]) = s->sa_in.sin_port;
		s->rx[6] = (len & 0xff00) >> 8;
		s->rx[7] = len & 0x00ff;
		s->RX_RSR = (len + 9) & 0x0001fffe;
	}
	s->rx_ptr = s->rx;
}

READ_REG_FUNC(read_MR){ return s->MR[z]; }

READ_REG_FUNC(read_CR){
	if (!s->CR)return 0;
	if (s->s == INVALID_SOCKET)return s->CR;
	return 0;
}

READ_REG_FUNC(read_SSR){
	if (s->s == INVALID_SOCKET || s->tcpState == TCP_STATE::CLOSED)
		return SOCK_CLOSED;
	if (s->MR[1] == Sn_MR_TCP && s->tcpState == TCP_STATE::NONE){
		return SOCK_INIT;
	}
	FD_ZERO(&fd_s);
	FD_SET(s->s, &fd_s);
	iResult = select(0, NULL, NULL, &fd_s, &select_timeout);
	if (iResult == SOCKET_ERROR)
		return SOCK_CLOSED;
	if (s->tcpState == TCP_STATE::LISTEN){
		s->list = accept(s->s, (sockaddr *)&s->sa_in, &ns);
		if (s->list != SOCKET_ERROR){
			ioctlsocket(s->s, FIONBIO, &is_blocked);
			closesocket(s->s);
			s->s = s->list;
			ioctlsocket(s->s, FIONBIO, &non_blocked);
			bool bOptVal = true;
			setsockopt(s->s, SOL_SOCKET, SO_KEEPALIVE, (char*)bOptVal, sizeof(bOptVal));
			s->tcpState = TCP_STATE::LISTEN_CONNECTED;
			return SOCK_ESTABLISHED;
		}
		return SOCK_LISTEN;
	}
	FD_ZERO(&fd_s);
	FD_SET(s->s, &fd_s);
	iResult = select(0, NULL, &fd_s, NULL, &select_timeout);
	if (iResult == SOCKET_ERROR)
		return SOCK_CLOSED;
	if (iResult == 0){
		switch (s->MR[1])
		{
		case Sn_MR_TCP:
			switch (s->tcpState)
			{
			case TCP_STATE::LISTEN_CONNECTED:
			case TCP_STATE::CLIENT_CONNECTED:
				return SOCK_ESTABLISHED;
			default:
				FD_ZERO(&fd_s);
				FD_SET(s->s, &fd_s);
				iResult = select(0, NULL, NULL, &fd_s, &select_timeout);
				if (iResult != 0){
					s->tcpState = TCP_STATE::CLOSED;
					return SOCK_CLOSED;
				}
				return SOCK_INIT;
			}
		case Sn_MR_UDP:
			return SOCK_UDP;
		default:
			return SOCK_CLOSED;
		}
	}
	else if (iResult > 0){
		FD_ZERO(&fd_s);
		FD_SET(s->s, &fd_s);
		iResult = select(0, NULL, NULL, &fd_s, &select_timeout);
		if (iResult != 0){
			s->tcpState = TCP_STATE::CLOSED;
			return SOCK_CLOSED;
		}
		switch (s->MR[1])
		{
		case Sn_MR_TCP:
			switch (s->tcpState)
			{
			case TCP_STATE::LISTEN:
				s->tcpState = TCP_STATE::LISTEN_CONNECTED;
				return SOCK_ESTABLISHED;
			case TCP_STATE::CLIENT:
				s->tcpState = TCP_STATE::CLIENT_CONNECTED;
				return SOCK_ESTABLISHED;
			case TCP_STATE::CLOSED:
				return SOCK_CLOSED;
			}
			WizRecv(s);
			if (s->tcpState == TCP_STATE::CLOSED) return SOCK_CLOSED;
			return SOCK_ESTABLISHED;
		case Sn_MR_UDP:
			return SOCK_UDP;
		default:
			return SOCK_CLOSED;
		}
	}
	//ns = WSAGetLastError();
	return SOCK_CLOSED;
}

READ_REG_FUNC(read_PORTR){
	return s->PORTR[z];
}

READ_REG_FUNC(read_DPORTR){
	if (z) return (s->sa_in.sin_port & 0xff00) >> 8;
	else return s->sa_in.sin_port & 0x00ff;
}

READ_REG_FUNC(read_ZERO){
	return 0;
}

READ_REG_FUNC(read_DIPR12){
	if (!z)
		return s->sa_in.sin_addr.S_un.S_un_b.s_b1;
	else
		return s->sa_in.sin_addr.S_un.S_un_b.s_b2;
}

READ_REG_FUNC(read_DIPR34){
	if (!z)
		return s->sa_in.sin_addr.S_un.S_un_b.s_b3;
	else
		return s->sa_in.sin_addr.S_un.S_un_b.s_b4;
}

READ_REG_FUNC(read_TX_FSR32){
	if (z == 0) return 0;
	return ((sizeof(s->tx) - (u_int)s->tx_ptr + (u_int)s->tx) & 0x00010000) >> 16;
}

READ_REG_FUNC(read_TX_FSR10){
	if (z == 0) return ((sizeof(s->tx) - (u_int)s->tx_ptr + (u_int)s->tx) & 0x0000ff00) >> 8;
	return (sizeof(s->tx) - (u_int)s->tx_ptr + (u_int)s->tx) & 0x000000fF;
}

READ_REG_FUNC(read_RX_RSR32){
	if (s->s == INVALID_SOCKET)return 0;
	if (z == 0) return 0;
	WizRecv(s);
	return (u_char)((s->RX_RSR & 0x00010000) >> 16);
}

READ_REG_FUNC(read_RX_RSR10){
	if (s->s == INVALID_SOCKET)return 0;
	WizRecv(s);
	if (z == 0) return (s->RX_RSR & 0x0000ff00) >> 8;
	return s->RX_RSR & 0x000000fF;
}

READ_REG_FUNC(read_RX){
	if (s->RX_RSR == 0)return 0;
	data = *(s->rx_ptr + z);
	if (z == 0)return data;
	s->RX_RSR -= 2;
	if (s->RX_RSR == 0)
		s->rx_ptr = NULL;
	else
		s->rx_ptr += 2;
	return data;
}

u_char(*regReadFunc[0x20])(sInfoStruct *, u_char) = {
	read_MR, read_CR, read_ZERO, read_ZERO, read_SSR, read_PORTR, read_ZERO, read_ZERO,
	read_ZERO, read_DPORTR, read_DIPR12, read_DIPR34, read_ZERO, read_ZERO, read_ZERO, read_ZERO,
	read_ZERO, read_ZERO, read_TX_FSR32, read_TX_FSR10, read_RX_RSR32, read_RX_RSR10, read_ZERO, read_ZERO,
	read_RX, read_ZERO, read_ZERO, read_ZERO, read_ZERO, read_ZERO, read_ZERO, read_ZERO,
};
void WIZ_CLOSE_SOC(sInfoStruct * s)
{
	if (s->s != INVALID_SOCKET){
		ioctlsocket(s->s, FIONBIO, &is_blocked);
		iResult = closesocket(s->s);
		DPRINTF("closesocket = %x", iResult);
		s->s = INVALID_SOCKET;
	}
}

void WizOpenSocket(sInfoStruct * s){
	bool bOptVal = true;
	if (s->s != INVALID_SOCKET) return;
	s->RX_RSR = 0;
	s->sa_in.sin_family = AF_INET;
	s->rx_ptr = NULL;
	s->tx_ptr = s->tx;
	s->tcpState = TCP_STATE::NONE;
	switch (s->MR[1])
	{
	case Sn_MR_TCP:
		s->s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		setsockopt(s->s, SOL_SOCKET, SO_KEEPALIVE, (char*)bOptVal, sizeof(bOptVal));
		DPRINTF("Opensocket %u ", s->s);
		break;
	case Sn_MR_UDP:
		s->s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		break;
	default:
		s->s = INVALID_SOCKET;
		break;
	}
	if (s->s != INVALID_SOCKET){
		ioctlsocket(s->s, FIONBIO, &non_blocked);
		s->CR = 0;
	}
}

void WizConnect(sInfoStruct *s){
	if (s->MR[1] != Sn_MR_TCP || s->s == INVALID_SOCKET || s->tcpState != TCP_STATE::NONE) return;
	s->CR = 0;
	s->tcpState = TCP_STATE::CLIENT;
	connect(s->s, (SOCKADDR *)&s->sa_in, sizeof(s->sa_in));
}

void WisDisconnect(sInfoStruct *s){
	if (s->MR[1] != Sn_MR_TCP) return;
}

void WisListen(sInfoStruct *s){
	if (s->MR[1] != Sn_MR_TCP || s->s == INVALID_SOCKET || s->tcpState != TCP_STATE::NONE) return;
	s->tcpState = TCP_STATE::LISTEN;
	ZeroMemory(&sa_in, sizeof(sa_in));
	//s->list = s->s;
	sa_in.sin_family = AF_INET;
	sa_in.sin_addr.S_un.S_addr = 0;
	sa_in.sin_port = (s->PORTR[1] << 8) | s->PORTR[0];
	bind(s->s, (sockaddr *)&sa_in, sizeof(sa_in));
	listen(s->s, 1);
	ns = sizeof(s->sa_in);
}

void WizSend(sInfoStruct *s){
	if (s->s == INVALID_SOCKET)return;
	iResult = (int)(s->TX_WRSR.ul & 0x01ffff);
	if (s->MR[1] == Sn_MR_TCP && s->tcpState != TCP_STATE::NONE){
		send(s->s, (char*)s->tx, (int)(s->TX_WRSR.ul & 0x01ffff), 0);
		s->tx_ptr = s->tx;
		s->TX_WRSR.ul = 0;
		DPRINTF("Send %d bytes\r\n", iResult);
	}
	else if (s->MR[1] == Sn_MR_UDP){
		sendto(s->s, (char*)s->tx, (int)(s->TX_WRSR.ul & 0x01ffff), 0, (sockaddr *)&s->sa_in, sizeof(sa_in));
		s->tx_ptr = s->tx;
		s->TX_WRSR.ul = 0;
		DPRINTF("Send %d bytes\r\n", iResult);
	}
}

WRITE_REG_FUNC(write_DPORTR){
	if (z) s->sa_in.sin_port = ((s->sa_in.sin_port) & 0x00ff) | (d << 8);
	else s->sa_in.sin_port = ((s->sa_in.sin_port) & 0xff00) | d;
};

WRITE_REG_FUNC(write_MR){
	WIZ_CLOSE_SOC(s);
	s->MR[z] = d;
};

WRITE_REG_FUNC(write_CR){
	if (!z)return;
	DPRINTF("Write CR = %x\r\n", d);
	s->CR = d;
	switch (d)
	{
	case Sn_CR_CLOSE:
		WIZ_CLOSE_SOC(s);
		s->CR = 0;
		break;
	case Sn_CR_RECV:
		s->rx_ptr = NULL;
		s->RX_RSR = 0;
		s->CR = 0;
		break;
	case Sn_CR_SEND:
		WizSend(s);
		break;
	case Sn_CR_DISCON:
		if (s->s != INVALID_SOCKET){
			WIZ_CLOSE_SOC(s);
			//WizOpenSocket(s);
			s->CR = 0;
		}
		break;
	case Sn_CR_OPEN:
		WizOpenSocket(s);
		break;
	case Sn_CR_LISTEN:
		WisListen(s);
		break;
	case Sn_CR_CONNECT:
		WizConnect(s);
		break;
	default:
		break;
	}
};

WRITE_REG_FUNC(write_PORTR){
	s->PORTR[z] = d;
};

WRITE_REG_FUNC(write_DIPR12){
	if (!z)s->sa_in.sin_addr.S_un.S_un_b.s_b1 = d;
	else s->sa_in.sin_addr.S_un.S_un_b.s_b2 = d;
}

WRITE_REG_FUNC(write_DIPR34){
	if (!z)s->sa_in.sin_addr.S_un.S_un_b.s_b3 = d;
	else s->sa_in.sin_addr.S_un.S_un_b.s_b4 = d;
}

WRITE_REG_FUNC(write_TX_WRSR32){
	s->TX_WRSR.b[3 - z] = d;
};

WRITE_REG_FUNC(write_TX_WRSR10){
	s->TX_WRSR.b[1 - z] = d;
};

WRITE_REG_FUNC(write_TX){
	*(s->tx_ptr + z) = d;
	if (z == 0)return;
	s->tx_ptr += 2;
};

WRITE_REG_FUNC(write_ZERO){};

void(*regWriteFunc[0x20])(sInfoStruct * s, u_char, u_char) = {
	write_MR, write_CR, write_ZERO, write_ZERO, write_ZERO, write_PORTR, write_ZERO, write_ZERO,
	write_ZERO, write_DPORTR, write_DIPR12, write_DIPR34, write_ZERO, write_ZERO, write_ZERO, write_ZERO,
	write_TX_WRSR32, write_TX_WRSR10, write_ZERO, write_ZERO, write_ZERO, write_ZERO, write_ZERO, write_TX,
	write_ZERO, write_ZERO, write_ZERO, write_ZERO, write_ZERO, write_ZERO, write_ZERO, write_ZERO,
};

u_char Wiz5300_RegRead(unsigned int Addr)
{

	if(comp.wiznet.p82&0x08)Addr^=0x01;
	if (Addr >= 0x0200)
		return regReadFunc[(Addr & 0x3f) >> 1](&soc[(Addr >> 6) & 0x07], Addr & 0x01);
	if (Addr <= 0x00ff){
		return regs[Addr];
	}
	return 0;
}

void Wiz5300_RegWrite(unsigned int Addr, unsigned char Data)
{
	if(comp.wiznet.p82&0x08)Addr^=0x01;
	if (Addr >= 0x0200)
		regWriteFunc[(Addr & 0x3f) >> 1](&soc[(Addr >> 6) & 0x07], Data, Addr & 0x01);
	else if (Addr <= 0x00ff) {
		regs[Addr] = stat_regs[Addr];
	}
}

void getNetProperties(void){
	char ac[80];
	gethostname(ac, sizeof(ac));
	struct hostent *phe = gethostbyname(ac);
	if (phe)memcpy(&stat_regs[0x0018], phe->h_addr_list[0], 4);
	if (*((ULONG32*)(&stat_regs[0x0018])) == 0)return;

	PIP_ADAPTER_INFO pAdapterInfo, pAdapter = NULL;
	DWORD dwRetVal = 0;
	//unsigned int i;
	//struct tm newtime;
	//errno_t error;
	ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);
	pAdapterInfo = (IP_ADAPTER_INFO*)malloc(sizeof(IP_ADAPTER_INFO));
	// if (pAdapterInfo==NULL) ...return
	if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW){
		free(pAdapterInfo);
		pAdapterInfo = (IP_ADAPTER_INFO*)malloc(ulOutBufLen);
		// if (pAdapterInfo==NULL) ...return
	}
	if ((dwRetVal = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen)) == NO_ERROR){
		pAdapter = pAdapterInfo;
		while (pAdapter)
		{
			if (pAdapter->IpAddressList.Context != *((DWORD32*)(&stat_regs[0x0018]))){
				pAdapter = pAdapter->Next;
				continue;
			}
			printf("Network adapter: %s \r\n",pAdapter->Description);
			*((ULONG32*)(&stat_regs[0x0014])) = inet_addr(pAdapter->IpAddressList.IpMask.String);
			*((ULONG32*)(&stat_regs[0x0010])) = inet_addr(pAdapter->GatewayList.IpAddress.String);
			memcpy(&stat_regs[0x008], pAdapter->Address, 8);
			break;
		}
	}
	else
	{
		//print error, no return
	}
	if (pAdapterInfo){
		free(pAdapterInfo);
	}
}

int Wiz5300_Init(void)
{
	ZeroMemory(stat_regs, sizeof(stat_regs));
	memset(&stat_regs[0x20], 0x08, 16);
	stat_regs[0x00] = 0x38;
	stat_regs[0xfe] = 0x53;
	stat_regs[0x31] = 0xff;
	memcpy(regs, stat_regs, sizeof(stat_regs));

	ZeroMemory(soc, sizeof(soc));
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	for (int i = 0; i < 8; i++){
		soc[i].s = INVALID_SOCKET;
		soc[i].sa_in.sin_family = AF_INET;
		soc[i].list = INVALID_SOCKET;
	}
	select_timeout.tv_sec = 0;
	select_timeout.tv_usec = 0;
	getNetProperties();
	//DPRINTF("wiz init\r\n");
	return 0;
}

int Wiz5300_Close(void)
{
	for (int i = 0; i < 8; i++) {
		if (soc[i].s != INVALID_SOCKET){
			ioctlsocket(soc[i].s, FIONBIO, &is_blocked);
			closesocket(soc[i].s);
		}
	}
	WSACleanup(); //Clean up Winsock
	return 0;
}


void pXXAB_Write(unsigned port, unsigned char val){
	if((!(port&0x8000))&&(comp.wiznet.p82&0x10)){
		Wiz5300_RegWrite(((comp.wiznet.p81&0x0f)<<6)|
			((port&0x3f00)>>8),val);
		return;
	}
	if(port==0x83ab){
		if((comp.wiznet.p83&0x10)^(val&0x10)){
			if(val&0x10){Wiz5300_Init();}
			else {Wiz5300_Close();}
		}
		comp.wiznet.p83=val;
		
	}else if(port==0x82ab){
		comp.wiznet.p82=val;
	}else if(port==0x81ab){
		comp.wiznet.p81=val;
		return;
	}
	comp.wiznet.memEna=conf.wiznet && (comp.wiznet.p82 & 0x04) 
		&& (comp.wiznet.p83 & 0x10) && (!(comp.wiznet.p82 & 0x10));
	return;
}

unsigned char pXXAB_Read(unsigned port){
	if((!(port&0x8000))&&(comp.wiznet.p82&0x10)){
		return Wiz5300_RegRead(((comp.wiznet.p81&0x0f)<<6)|
			((port&0x3f00)>>8));
		
	}
		if(port==0x83ab){
			return comp.wiznet.p83;
		}else if(port==0x82ab){
			return comp.wiznet.p82;
		}else if(port==0x81ab){
			return comp.wiznet.p81;
		}else if(port&0x8000){return 0xFF;}

		return 0xff;
}

