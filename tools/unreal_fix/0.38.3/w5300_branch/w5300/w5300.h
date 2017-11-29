#pragma once
#ifndef W5300_H
#define W5300_H
#ifdef W5300DLL_EXPORTS
#define W5300DLL_API __declspec(dllexport) 
#else
#define W5300DLL_API __declspec(dllimport) 
#endif

#define Wiz5300 W5300::W5300_Class
//#include <MSWSock.h>

namespace W5300
{
	class W5300_Class
	{
	public:
		static W5300DLL_API int Init(void);

		static W5300DLL_API int Close(void);

		static W5300DLL_API unsigned char RegRead(unsigned int Addr);

		static W5300DLL_API void RegWrite(unsigned int Addr, unsigned char Data);
	};
}
#endif