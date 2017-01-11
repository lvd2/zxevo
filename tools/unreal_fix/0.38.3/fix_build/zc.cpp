// Z-Controller by KOE
// Only SD-card
#include "std.h"
#include "emul.h"
#include "vars.h"
#include "sdcard.h"
#include "zc.h"

void TZc::Reset()
{
  SdCard.Reset();
  Cfg = 0;
  Status = 0;
  RdBuff = 0xff;
}

void TZc::Wr(u32 Port, u8 Val)
{
  switch(Port & 0xFF)
  {
    case 0x77: // config
      Cfg = Val & 3;
    break;

    case 0x57: // data
      if (!(Cfg & 2))   // SD card selected
      {
        RdBuff = SdCard.Rd();
        SdCard.Wr(Val);
      }
      else
        RdBuff = 255;
      //printf("\nOUT %02X  in %02X",Val,RdBuff);
    break;
  }
}

u8 TZc::Rd(u32 Port)
{
  switch(Port & 0xFF)
  {
    case 0x77: // status
      return Status;      // always returns 0

    case 0x57: // data
      u8 tmp = RdBuff;
      
      if (!(Cfg & 2))   // SD card selected
      {
        RdBuff = SdCard.Rd();
        SdCard.Wr(0xff);
      }
      else
        RdBuff = 255;
      
      //printf("\nout FF  IN %02X (next %02X)",tmp,RdBuff);
      return tmp;
  }

  return 0xFF;
}

TZc Zc;
