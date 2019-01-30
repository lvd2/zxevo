#include "std.h"

#include "emul.h"
#include "vars.h"
#include "fdd.h"
#include "upd765.h"

#if 0
#define dprintf printf
#else
#define dprintf(...)
#endif

#pragma pack(push, 1)
union TDiskInfo
{
    struct
    {
        char Sig[34];
        char Name[14];
        u8 c;
        u8 h;
        u16 TrackSize; // Только для dsk (не для edsk)
        u8 TrackOffsets[]; // c * h, Только для edsk
    };
    u8 Raw[256];
};

#ifndef __ICL // icl 19 под win не имеет __builtin_offsetof
static_assert(offsetof(TDiskInfo, TrackOffsets) == 0x34);
#endif

struct TSecInfo
{
    u8 c;
    u8 h;
    u8 r;
    u8 n; // sector size code
    u8 St1;
    u8 St2;
    u16 DataLen; // Только для edsk
};

union  TTrackInfo
{
    struct
    {
        char Sig[13];
        char Reserved[3];
        u8 c;
        u8 h;
        char Reserved2[2];
        u8 n; // sector size code
        u8 NumSec;
        u8 Gap3Len;
        u8 Filler;
        TSecInfo SecInfoList[];
    };
    u8 Raw[256];
};
#pragma pack(pop)

int FDD::read_dsk()
{
    dprintf("read_dsk\n");

    const auto DiskInfo{ (const TDiskInfo *)snbuf };

    auto IsExtended{ memcmp(DiskInfo->Sig, "EXTENDED", 8) == 0};
    if(!IsExtended && memcmp(DiskInfo->Sig, "MV - CPC", 8) != 0)
    {
        return 0;
    }

    newdisk(DiskInfo->c, DiskInfo->h);

    unsigned Offset{ sizeof(TDiskInfo) };
    for(unsigned c = 0; c < DiskInfo->c; c++)
    {
        for(unsigned h = 0; h < DiskInfo->h; h++)
        {
            auto TrkSize{ IsExtended ? unsigned(DiskInfo->TrackOffsets[c*DiskInfo->h + h] << 8U) : DiskInfo->TrackSize };
            if(TrkSize == 0)
            {
                continue;
            }
            t.seek(this, c, h, JUST_SEEK);

            const auto TrackInfo{ (const TTrackInfo *)(snbuf + Offset) };
            const auto SecDataStart{ snbuf + Offset + sizeof(TTrackInfo) };
            auto SecData{ SecDataStart };
            u8* PrevSecData{ };

            bool IsOverlappedSec = false; // Capitan Blood, License to kill
            if(IsExtended)
            {
                IsOverlappedSec = true;
                constexpr unsigned SecLen[]{ 128, 256, 512, 1024, 2048, 4096, 6144 };
                for(unsigned s = 0; s < min(size_t(TrackInfo->NumSec), _countof(SecLen)); s++)
                {
                    const auto &SecInfo{ TrackInfo->SecInfoList[s] };
                    if(SecLen[s] != SecInfo.DataLen)
                    {
                        IsOverlappedSec = false;
                        break;
                    }
                }
            }

            for(unsigned s = 0; s < TrackInfo->NumSec; s++)
            {
                const auto &SecInfo{ TrackInfo->SecInfoList[s] };
                auto SecInfoDataLen{ SecInfo.DataLen };
                t.hdr[s].c = SecInfo.c;
                t.hdr[s].s = SecInfo.h;
                t.hdr[s].n = SecInfo.r;
                t.hdr[s].l = SecInfo.n;
                t.hdr[s].c1 = 0;
                t.hdr[s].c2 = 0;
                t.hdr[s].wp = nullptr;
                t.hdr[s].data = SecData;


                t.hdr[s].datlen = IsExtended ? SecInfoDataLen : 128U << SecInfo.n;
                if(t.hdr[s].datlen == 0)
                {
                    t.hdr[s].data = nullptr;
                }

                // Защиты типа как в golden axe (первый сектор на трэке (код 6, размер 8192)
                // превышает размер трэка, дальше идут обыные сектора)
                // Этот первый сектор содержит полную информацию о всей дорожке (остальные сектора сформированы в зоне данных этого сектора)
                // Такую дорожку надо сразу загружать в udi формате восстановив синхроимпульсы по байтам A1A1A1 FE/FB
                // А информацию о раскладке и размерах секторов взять из описания в dsk (там вся информация продублирована по 2 раза)
                // Сначала в большом секторе, а потом в маленьких секторах (которые фактически являются ссылками на куски большого)
/*
                // Криво снятые образы с защитой от opera soft (например mot)
                // Правильно снятый образ (corsarios + mutant zone)
                if(IsExtended && c == 40 && SecInfo.n == 8 && SecInfoDataLen == 0)
                {
                    const auto &SecInfo{ TrackInfo->SecInfoList[s-1] };
                    auto SecInfoDataLen{ SecInfo.DataLen };
                    t.hdr[s].data = PrevSecData - 0x512;
                    t.hdr[s].datlen = IsExtended ? SecInfoDataLen : 128U << SecInfo.n;
                }
*/
                if((SecInfo.St1 & TUpd765::ST1_DE)) // crc error in address or data
                {
                    if((SecInfo.St2 & TUpd765::ST2_DD)) // crc error in data
                    {
                        t.hdr[s].c2 = 2;
                        if(IsOverlappedSec)
                        {
                            t.hdr[s].data = nullptr;
                        }
                    }
                    else
                    {
                        t.hdr[s].c1 = 2; // crc error in address
//                    t.hdr[s].data = nullptr;
                    }
                }

                if(SecInfo.St2 & TUpd765::ST2_CM)
                {
                    t.hdr[s].Flags = SECHDR::FL_DDAM;
                }
                else
                {
                    t.hdr[s].Flags = 0;
                }
                PrevSecData = SecData;
                SecData += IsExtended ? SecInfoDataLen : 128U << SecInfo.n;
            }
            t.s = TrackInfo->NumSec;
            t.format();
            Offset += TrkSize;
        }
    }
    return 1;
}
