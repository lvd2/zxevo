#include "std.h"

#include "emul.h"
#include "vars.h"
#include "dxerr.h"
#include "util.h"

#ifdef EMUL_DEBUG
#include "dxerr9.h"
void printrdd(const char *pr, HRESULT r)
{
   color(CONSCLR_ERROR);
   printf("%s: %s\n", pr, DXGetErrorString(r));
   color();

#ifdef _DEBUG
   OutputDebugString(pr);
   OutputDebugString(": ");
   OutputDebugString(DXGetErrorString(r));
   OutputDebugString("\n");
#endif
}

void printrdi(const char *pr, HRESULT r)
{
   color(CONSCLR_ERROR);
   printf("%s: %s\n", pr, DXGetErrorString(r));
   color();

#ifdef _DEBUG
   OutputDebugString(pr);
   OutputDebugString(": ");
   OutputDebugString(DXGetErrorString(r));
   OutputDebugString("\n");
#endif
}

void printrmm(const char *pr, MMRESULT r)
{
   char buf[200]; sprintf(buf, "unknown error (%08X)", r);
   const char *str = buf;
   switch (r)
   {
      case MMSYSERR_NOERROR: str = "ok"; break;
      case MMSYSERR_INVALHANDLE: str = "MMSYSERR_INVALHANDLE"; break;
      case MMSYSERR_NODRIVER: str = "MMSYSERR_NODRIVER"; break;
      case WAVERR_UNPREPARED: str = "WAVERR_UNPREPARED"; break;
      case MMSYSERR_NOMEM: str = "MMSYSERR_NOMEM"; break;
      case MMSYSERR_ALLOCATED: str = "MMSYSERR_ALLOCATED"; break;
      case WAVERR_BADFORMAT: str = "WAVERR_BADFORMAT"; break;
      case WAVERR_SYNC: str = "WAVERR_SYNC"; break;
      case MMSYSERR_INVALFLAG: str = "MMSYSERR_INVALFLAG"; break;
   }
   color(CONSCLR_ERROR);
   printf("%s: %s\n", pr, str);
   color();
}

void printrds(const char *pr, HRESULT r)
{
   color(CONSCLR_ERROR);
   PCSTR ErrStr;
   if(r == AUDCLNT_E_DEVICE_IN_USE)
   {
       ErrStr = "AUDCLNT_E_DEVICE_IN_USE";
   }
   else
   {
       ErrStr = DXGetErrorString(r);
   }

   printf("%s: 0x%lX, %s\n", pr, r, ErrStr);
   color();
}
#else
#define printrdd(x,y)
#define printrdi(x,y)
#define printrds(x,y)
#define printrmm(x,y)
#endif
