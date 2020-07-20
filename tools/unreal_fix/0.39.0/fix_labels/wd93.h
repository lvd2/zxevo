#pragma once

const int Z80FQ = 3500000; // todo: #define as (conf.frame*conf.intfq)
const int FDD_RPS = 5; // rotation speed

const int MAX_TRACK_LEN = 6250;
constexpr unsigned MAX_SEC_DATA_LEN = 6144U;
const int MAX_CYLS = 86;            // don't load images with so many tracks
const int MAX_PHYS_CYL = 86;        // don't seek over it
const int MAX_SEC = 256;

struct WD1793
{
   enum WDSTATE
   {
      S_IDLE = 0,
      S_WAIT,

      S_DELAY_BEFORE_CMD,
      S_CMD_RW,
      S_FOUND_NEXT_ID,
      S_RDSEC,
      S_READ,
      S_WRSEC,
      S_WRITE,
      S_WRTRACK,
      S_WR_TRACK_DATA,

      S_TYPE1_CMD,
      S_STEP,
      S_SEEKSTART,
      S_RESTORE,
      S_SEEK,
      S_VERIFY,
      S_VERIFY2,

      S_WAIT_HLT,
      S_WAIT_HLT_RW,

      S_EJECT1,
      S_EJECT2
   };

   __int64 next, time;
   __int64 idx_tmo;

   struct FDD *seldrive;
   unsigned tshift;

   WDSTATE state, state2;

   unsigned char cmd;
   unsigned char data, track, sector;
   unsigned char rqs, status;
   u8 sign_status; // Внешние сигналы (пока только HLD)

   unsigned drive, side;                // update this with changing 'system'

   signed char stepdirection;
   unsigned char system;                // beta128 system register

   unsigned idx_cnt; // idx counter

   // read/write sector(s) data
   __int64 end_waiting_am;
   unsigned foundid;                    // index in trkcache.hdr for next encountered ID and bytes before this ID
   unsigned rwptr, rwlen;

   // format track data
   unsigned start_crc;

   enum CMDBITS
   {
      CMD_SEEK_RATE     = 0x03,
      CMD_SEEK_VERIFY   = 0x04,
      CMD_SEEK_HEADLOAD = 0x08,
      CMD_SEEK_TRKUPD   = 0x10,
      CMD_SEEK_DIR      = 0x20,

      CMD_WRITE_DEL     = 0x01,
      CMD_SIDE_CMP_FLAG = 0x02,
      CMD_DELAY         = 0x04,
      CMD_SIDE          = 0x08,
      CMD_SIDE_SHIFT    = 3,
      CMD_MULTIPLE      = 0x10
   };

   enum BETA_STATUS
   {
      DRQ   = 0x40,
      INTRQ = 0x80
   };

   enum WD_STATUS
   {
      WDS_BUSY      = 0x01,
      WDS_INDEX     = 0x02,
      WDS_DRQ       = 0x02,
      WDS_TRK00     = 0x04,
      WDS_LOST      = 0x04,
      WDS_CRCERR    = 0x08,
      WDS_NOTFOUND  = 0x10,
      WDS_SEEKERR   = 0x10,
      WDS_RECORDT   = 0x20,
      WDS_HEADL     = 0x20,
      WDS_WRFAULT   = 0x20,
      WDS_WRITEP    = 0x40,
      WDS_NOTRDY    = 0x80
   };

   enum WD_SYS
   {
      SYS_HLT       = 0x08
   };

   enum WD_SIG
   {
       SIG_HLD      = 0x01
   };

   unsigned char in(unsigned char port);
   void out(unsigned char port, unsigned char val);
   u8 RdStatus();

   void process();
   void find_marker();
   char notready();
   void load();
   void getindex();
   void trdos_traps();

//   TRKCACHE trkcache;

   bool EjectPending;
   void Eject(unsigned Drive);

   WD1793();
};
