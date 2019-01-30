#include "std.h"

#include "emul.h"
#include "vars.h"
#include "fdd.h"
#include "util.h"

// Все данные внутри ipf файла в формате big endian

static constexpr size_t CAPS_MAXPLATFORM = 4;

static constexpr char ID_CAPS[] = "CAPS";
static constexpr char ID_INFO[] = "INFO";
static constexpr char ID_IMGE[] = "IMGE";
static constexpr char ID_DATA[] = "DATA";

static constexpr u16 MFM_MARK_A1 = 0x4489;
static constexpr u16 MFM_MARK_C2 = 0x5224;

static inline u32 be2cpu(u32 x)
{
    return _byteswap_ulong(x);
}

static inline u16 be2cpu(u16 x)
{
    return _byteswap_ushort(x);
}

static inline u8 ReadU8(u8 *&Ptr)
{
    u8 x = *Ptr++;
    return x;
}

static inline u16 ReadU16(u8 *&Ptr)
{
    u16 x = *((u16 *)Ptr);
    Ptr += sizeof(u16);
    return x;
}

static inline u32 ReadU32(u8 *&Ptr)
{
    u32 x = *((u32 *)Ptr);
    Ptr += sizeof(u32);
    return x;
}

#pragma pack(push, 1)
struct TCapsId
{
    char Name[4];
    u32 Size;
    u32 Crc;
};

enum TEncoderType : u32
{
    CAPS_ENCODER = 1,
    SPS_ENCODER = 2
};

// caps packed date.time format
struct TCapsDateTime
{
    u32 date; // packed date, yyyymmdd
    u32 time; // packed time, hhmmssttt
};

// platform IDs, not about configuration, but intended use
enum TPlatformId : u32
{
    cppidNA = 0, // invalid platform (dummy entry)
    cppidAmiga,
    cppidAtariST,
    cppidPC,
    cppidAmstradCPC,
    cppidSpectrum,
    cppidSamCoupe,
    cppidArchimedes,
    cppidC64,
    cppidAtari8,
    cppidLast
};


// image information
struct TCapsInfo
{
    u32 type;        // image type
    TEncoderType encoder;     // image encoder ID
    u32 encrev;      // image encoder revision
    u32 release;     // release ID
    u32 revision;    // release revision ID
    u32 origin;      // original source reference
    u32 mincylinder; // lowest cylinder number
    u32 maxcylinder; // highest cylinder number
    u32 minhead;     // lowest head number
    u32 maxhead;     // highest head number
    TCapsDateTime crdt;  // image creation date.time
    TPlatformId platform[CAPS_MAXPLATFORM]; // intended platform(s)
    u32 disknum;     // disk# for release, >= 1 if multidisk
    u32 userid;      // user id of the image creator
    u32 reserved[3]; // future use
};

// density types
enum TDensityType : u32
{
    cpdenNA = 0,     // invalid density
    cpdenNoise,    // cells are unformatted (random size)
    cpdenAuto,     // automatic cell size, according to track size
    cpdenCLAmiga,  // Copylock Amiga
    cpdenCLAmiga2, // Copylock Amiga, new
    cpdenCLST,     // Copylock ST
    cpdenSLAmiga,  // Speedlock Amiga
    cpdenSLAmiga2, // Speedlock Amiga, old
    cpdenABAmiga,  // Adam Brierley Amiga
    cpdenABAmiga2, // Adam Brierley, density key Amiga
    cpdenLast
};

// signal processing used
enum TSigType : u32
{
    cpsigNA = 0, // invalid signal type
    cpsig2us,  // 2us cells
    cpsigLast
};


// track image descriptor
struct TCapsImage
{
    u32 cylinder; // cylinder#
    u32 head;     // head#
    TDensityType dentype;  // density type
    TSigType sigtype;  // signal processing type
    u32 trksize;  // decoded track size, rounded
    u32 startpos; // start position, rounded
    u32 startbit; // start position on original data
    u32 databits; // decoded data size in bits
    u32 gapbits;  // decoded gap size in bits
    u32 trkbits;  // decoded track size in bits
    u32 blkcnt;   // number of blocks
    u32 process;  // encoder prcocess
    u32 flag;     // image flags
    u32 did;      // data chunk identifier
    u32 reserved[3]; // future use
};

// data area
struct TCapsData
{
    u32 size;  // data area size in bytes after chunk
    u32 bsize; // data area size in bits
    u32 dcrc;  // data area crc
    u32 did;   // data chunk identifier
};

// original meaning of some CapsBlock entries for old images
struct TCapsBlockExt
{
    u32 blocksize;  // decoded block size, rounded
    u32 gapsize;    // decoded gap size, rounded
};

// new meaning of some CapsBlock entries for new images
struct TSPSBlockExt
{
    u32 gapoffset;  // offset of gap stream in data area
    u32 celltype;   // bitcell type
};

// union for old or new images
union TCapsBlockType
{
    TCapsBlockExt caps; // access old image
    TSPSBlockExt sps;   // access new image
    static_assert(sizeof(sps) == sizeof(caps));
};

// encoder types
enum TEncType : u32
{
    cpencNA = 0, // invalid encoder
    cpencMFM,  // MFM
    cpencRaw,  // no encoder used, test data only
    cpencLast
};

// CapsBlock flags
union TCapsBlockFlags // Порядок битовых полей в структуре соответствует little endian
{
    struct
    {
        u32 CAPS_BF_GP0 : 1; // bit0
        u32 CAPS_BF_GP1 : 1; // bit1
        u32 CAPS_BF_DMB : 1; // bit2
        u32 : 29;
    };
    u32 Flags;
};

// block image descriptor
struct TCapsBlock
{
    u32 blockbits;  // decoded block size in bits
    u32 gapbits;    // decoded gap size in bits
    TCapsBlockType bt;  // content depending on image type
    TEncType enctype;    // encoder type
    TCapsBlockFlags flag;       // block flags
    u32 gapvalue;   // default gap value
    u32 dataoffset; // offset of data stream in data area (относительно первого caps блока)
};

// gap types
enum TGapType : u8
{
    cpgapEnd = 0, // gap stream end
    cpgapCount, // gap counter
    cpgapData,  // gap data pattern
    cpgapLast
};

union TGapStreamElementHdr
{
    struct
    {
        TGapType GapType : 5;
        u8 GapSizeWidth : 3;
    };
    u8 Hdr;
};

// data types
enum TDataType : u8
{
    cpdatEnd = 0, // data stream end
    cpdatMark,  // mark/sync
    cpdatData,  // data
    cpdatGap,   // gap
    cpdatRaw,   // raw
    cpdatFData, // flakey data
    cpdatLast
};

union TDataStreamElementHdr
{
    struct
    {
        TDataType DataType : 5;
        u8 DataSizeWidth : 3;
    };
    u8 Hdr;
};
#pragma pack(pop)

static void ReadCapsId(TCapsId *CapsId, u8 *&Ptr)
{
    memcpy(CapsId->Name, Ptr, 4); Ptr += 4;
    CapsId->Size = be2cpu(ReadU32(Ptr));
    CapsId->Crc = be2cpu(ReadU32(Ptr));
}

static void ReadCapsDateTime(TCapsDateTime *CapsDateTime, u8 *&Ptr)
{
    CapsDateTime->date = be2cpu(ReadU32(Ptr));
    CapsDateTime->time = be2cpu(ReadU32(Ptr));
}

static void ReadCapsInfo(TCapsInfo *CapsInfo, u8 *&Ptr)
{
    CapsInfo->type = be2cpu(ReadU32(Ptr));
    CapsInfo->encoder = TEncoderType(be2cpu(ReadU32(Ptr)));
    CapsInfo->encrev = be2cpu(ReadU32(Ptr));
    CapsInfo->release = be2cpu(ReadU32(Ptr));
    CapsInfo->revision = be2cpu(ReadU32(Ptr));
    CapsInfo->origin = be2cpu(ReadU32(Ptr));
    CapsInfo->mincylinder = be2cpu(ReadU32(Ptr));
    CapsInfo->maxcylinder = be2cpu(ReadU32(Ptr));
    CapsInfo->minhead = be2cpu(ReadU32(Ptr));
    CapsInfo->maxhead = be2cpu(ReadU32(Ptr));
    ReadCapsDateTime(&CapsInfo->crdt, Ptr);
    for(auto &v : CapsInfo->platform)
    {
        v = TPlatformId(be2cpu(ReadU32(Ptr)));
    }
    CapsInfo->disknum = be2cpu(ReadU32(Ptr));
    CapsInfo->userid = be2cpu(ReadU32(Ptr));

    for(auto &v : CapsInfo->reserved)
    {
        v = be2cpu(ReadU32(Ptr));
    }
}

static void ReadCapsImage(TCapsImage *CapsImage, u8 *&Ptr)
{
    CapsImage->cylinder = be2cpu(ReadU32(Ptr));
    CapsImage->head = be2cpu(ReadU32(Ptr));
    CapsImage->dentype = TDensityType(be2cpu(ReadU32(Ptr)));
    CapsImage->sigtype = TSigType(be2cpu(ReadU32(Ptr)));
    CapsImage->trksize = be2cpu(ReadU32(Ptr));
    CapsImage->startpos = be2cpu(ReadU32(Ptr));
    CapsImage->startbit = be2cpu(ReadU32(Ptr));
    CapsImage->databits = be2cpu(ReadU32(Ptr));
    CapsImage->gapbits = be2cpu(ReadU32(Ptr));
    CapsImage->trkbits = be2cpu(ReadU32(Ptr));
    CapsImage->blkcnt = be2cpu(ReadU32(Ptr));
    CapsImage->process = be2cpu(ReadU32(Ptr));
    CapsImage->flag = be2cpu(ReadU32(Ptr));
    CapsImage->did = be2cpu(ReadU32(Ptr));
    for(auto &v : CapsImage->reserved)
    {
        v = be2cpu(ReadU32(Ptr));
    }
}

static void ReadCapsData(TCapsData *CapsData, u8 *&Ptr)
{
    CapsData->size = be2cpu(ReadU32(Ptr));
    CapsData->bsize = be2cpu(ReadU32(Ptr));
    CapsData->dcrc = be2cpu(ReadU32(Ptr));
    CapsData->did = be2cpu(ReadU32(Ptr));
}

static void ReadCapsBlockType(TCapsBlockType *CapsBlockType, TEncoderType EncoderType, u8 *&Ptr)
{
    switch(EncoderType)
    {
    case CAPS_ENCODER:
        CapsBlockType->caps.blocksize = be2cpu(ReadU32(Ptr));
        CapsBlockType->caps.gapsize = be2cpu(ReadU32(Ptr));
        break;
    case SPS_ENCODER:
        CapsBlockType->sps.gapoffset = be2cpu(ReadU32(Ptr));
        CapsBlockType->sps.celltype = be2cpu(ReadU32(Ptr));
        break;
    default:
        assert(!"unknown encoder type");
    }
}

static void ReadCapsBlock(TCapsBlock *CapsBlock, TEncoderType EncoderType, u8 *&Ptr)
{
    CapsBlock->blockbits = be2cpu(ReadU32(Ptr));
    CapsBlock->gapbits = be2cpu(ReadU32(Ptr));
    ReadCapsBlockType(&CapsBlock->bt, EncoderType, Ptr);
    CapsBlock->enctype = TEncType(be2cpu(ReadU32(Ptr)));
    CapsBlock->flag.Flags = be2cpu(ReadU32(Ptr));
    CapsBlock->gapvalue = be2cpu(ReadU32(Ptr));
    CapsBlock->dataoffset = be2cpu(ReadU32(Ptr));
}

static void ReadGapHdr(TGapStreamElementHdr *GapStreamElementHdr, u8 *&Ptr)
{
    GapStreamElementHdr->Hdr = *Ptr++;
}

static u32 ReadVarUint(unsigned n, u8 *&Ptr)
{
    u32 v = 0;
    for(unsigned i = 0; i < n; i++)
    {
        v |= unsigned(*Ptr) << (n - i - 1) * 8;
        Ptr++;
    }

    return v;
}

static void ReadDataHdr(TDataStreamElementHdr *DataStreamElementHdr, u8 *&Ptr)
{
    DataStreamElementHdr->Hdr = *Ptr++;
}

int FDD::read_ipf()
{
    u8 *Gptr = snbuf;

    u8 *Ptr = Gptr;
    TCapsId CapsId;
    ReadCapsId(&CapsId, Ptr);

    Gptr += CapsId.Size;
    Ptr = Gptr;

    if(memcmp(CapsId.Name, ID_CAPS, sizeof(CapsId.Name)) != 0)
    {
        return 0;
    }

    ReadCapsId(&CapsId, Ptr);
    if(memcmp(CapsId.Name, ID_INFO, sizeof(CapsId.Name)) != 0)
    {
        return 0;
    }

    TCapsInfo CapsInfo;
    ReadCapsInfo(&CapsInfo, Ptr);

    Gptr += CapsId.Size;
    Ptr = Gptr;
    u8 *ImgeStart = Gptr; // Начало массива записей IMGE

    if(CapsInfo.maxcylinder >= MAX_CYLS)
    {
        err_printf("cylinders (%u) > MAX_CYLS(%d)", cyls, MAX_CYLS);
        return 0;
    }

    if(CapsInfo.maxhead >= 2)
    {
        err_printf("sides (%u) > 2", sides);
        return 0;
    }

    cyls = CapsInfo.maxcylinder + 1;
    sides = CapsInfo.maxhead + 1;

    size_t mem = 0;
    const unsigned bitmap_len = (unsigned(MAX_TRACK_LEN + 7U)) >> 3;

    mem += (MAX_CYLS - cyls) * sides * (MAX_TRACK_LEN + bitmap_len); // Добавка для возможности форматирования на MAX_CYLS дорожек

    rawsize = align_by(mem, 4096U);
    rawdata = (unsigned char*)VirtualAlloc(nullptr, rawsize, MEM_COMMIT, PAGE_READWRITE);
    u8 *dst = rawdata;

    auto Ncyls{ CapsInfo.maxcylinder - CapsInfo.mincylinder + 1 };
    auto Nheads{ CapsInfo.maxhead - CapsInfo.minhead + 1 };

    u8 *DataStart2 = Gptr + (Ncyls * Nheads)*(sizeof(TCapsId) + sizeof(TCapsImage));

    // Неиспользуемые трэки в начале диска
    for(unsigned c = 0; c < CapsInfo.mincylinder; c++)
    {
        for(unsigned h = 0; h < sides; h++)
        {
            trklen[c][h] = MAX_TRACK_LEN;
            trkd[c][h] = dst;
            dst += MAX_TRACK_LEN;

            trki[c][h] = dst;
            dst += bitmap_len;
        }
    }

    for(unsigned c = CapsInfo.mincylinder; c <= CapsInfo.maxcylinder; c++)
    {
        for(unsigned h = CapsInfo.minhead; h <= CapsInfo.maxhead; h++)
        {
            ReadCapsId(&CapsId, Ptr);
            assert(memcmp(CapsId.Name, ID_IMGE, sizeof(CapsId.Name)) == 0);

            TCapsImage CapsImage;
            ReadCapsImage(&CapsImage, Ptr);
            assert(CapsImage.cylinder == c && CapsImage.head == h);

            Gptr += CapsId.Size;
            Ptr = Gptr;
        }
    }

    u8 *DataStart = Gptr; // Начало массива записей DATA
    assert(DataStart == DataStart2);

    for(unsigned c = CapsInfo.mincylinder; c <= CapsInfo.maxcylinder; c++)
    {
        for(unsigned h = CapsInfo.minhead; h <= CapsInfo.maxhead; h++)
        {
            ReadCapsId(&CapsId, Ptr);
            assert(memcmp(CapsId.Name, ID_DATA, sizeof(CapsId.Name)) == 0);

            TCapsData CapsData; // Блоки переменной длины
            ReadCapsData(&CapsData, Ptr);

            u8 *PtrCapsBlock = Ptr;
            Gptr += CapsId.Size + CapsData.size;

            Ptr = ImgeStart + (sizeof(TCapsId) + sizeof(TCapsImage)) * (CapsData.did - 1);

            ReadCapsId(&CapsId, Ptr);
            assert(memcmp(CapsId.Name, ID_IMGE, sizeof(CapsId.Name)) == 0);

            TCapsImage CapsImage;
            ReadCapsImage(&CapsImage, Ptr);
            assert(CapsImage.cylinder == c && CapsImage.head == h);
            assert(CapsImage.did == CapsData.did);

//            assert(CapsImage.trksize % 2 == 0);
            unsigned sz = min(unsigned(CapsImage.trksize / 2), unsigned(MAX_TRACK_LEN)); // Размер в битовых ячейках / 8
            trklen[c][h] = sz;
            trkd[c][h] = dst;

            u8 *dsti = dst + sz;
            trki[c][h] = dsti;

            Ptr = PtrCapsBlock;

            u32 FixedGapSize = 0;

            // Расчет суммарного размера всех фиксированных GAP'ов
            for(unsigned i = 0; i < CapsImage.blkcnt; i++)
            {
                TCapsBlock CapsBlock;
                ReadCapsBlock(&CapsBlock, CapsInfo.encoder, Ptr);
                u8 *Optr = Ptr;

                Ptr = PtrCapsBlock + CapsBlock.bt.sps.gapoffset;

                auto GalcGapSize = [&Ptr, &FixedGapSize]()
                {
                    bool IsEnd = false;
                    u32 Count = 0;
                    do
                    {
                        TGapStreamElementHdr GapHdr;
                        ReadGapHdr(&GapHdr, Ptr);

                        IsEnd = (GapHdr.GapSizeWidth == 0 && GapHdr.GapType == cpgapEnd);
                        if(GapHdr.GapSizeWidth != 0)
                        {
                            u32 Size = ReadVarUint(GapHdr.GapSizeWidth, Ptr); // Величина в битах
                            Size = (Size + 7) / 8; // Величина в байтах
                            switch(GapHdr.GapType)
                            {
                            case cpgapCount:
                                Count = Size;
                                break;
                            case cpgapData:
                            {
                                FixedGapSize += Count * Size;

                                Ptr += Size;
                                break;
                            }
                            }
                        }
                    } while(!IsEnd);
                };

                if(CapsBlock.flag.CAPS_BF_GP0) // Fw gap
                {
                    GalcGapSize();
                }

                if(CapsBlock.flag.CAPS_BF_GP1) // Bw gap
                {
                    GalcGapSize();
                }

                Ptr = Optr;
            }


            // Позиция в битовых ячейках / 8, коррекция к стандартной длине трэка
            // (многие ipf Файлы имеют длину трэка > 100000 битовых ячеек)
            // видимо образы снимали на дисководе с заниженной скоростью вращения шпинделя
            // (дисководы от +3 не имеют кварцевой стабилизации скорости вращения, и используют двигатель с пассиком,
            // а не синхронный многополюсный двигатель с прямым приводом)
            // http://www.cpcwiki.eu/index.php/Amstrad_FDD_part (на +3 применялись аналогичные дисководы)
            u32 RealGapBits = MAX_TRACK_LEN * 16 - CapsImage.databits;
            assert(RealGapBits >= FixedGapSize * 16);
            u32 AvailGapBits = RealGapBits - FixedGapSize * 16;
            u32 FlexGapBits = CapsImage.gapbits - FixedGapSize * 16;
            u32 StartPos = (FlexGapBits != 0) ? (CapsImage.startbit * AvailGapBits) / (16 * FlexGapBits) : 0;
            if(StartPos < 13)
            {
                StartPos = 13; // 4E + 12(00)
            }

            dst += StartPos;

            Ptr = PtrCapsBlock;

            for(unsigned i = 0; i < CapsImage.blkcnt; i++)
            {
                TCapsBlock CapsBlock;
                ReadCapsBlock(&CapsBlock, CapsInfo.encoder, Ptr);
                u8 *Optr = Ptr;

                unsigned GapBitsRemaining = CapsBlock.gapbits / 2; // Это не биты, а MFM ячейки (их в 2 раза больше чем битов)

                assert(CapsInfo.encoder == SPS_ENCODER);


                Ptr = PtrCapsBlock + CapsBlock.dataoffset;

                bool IsEnd = false;
                do
                {
                    TDataStreamElementHdr DataHdr;
                    ReadDataHdr(&DataHdr, Ptr);

                    IsEnd = (DataHdr.DataSizeWidth == 0 && DataHdr.DataType == cpdatEnd);
                    if(DataHdr.DataSizeWidth != 0)
                    {
                        u32 Size = ReadVarUint(DataHdr.DataSizeWidth, Ptr);
                        if(CapsBlock.flag.CAPS_BF_DMB) // размер данных в битах
                        {
//                            assert(Size % 8 == 0);
                            Size = (Size + 7) / 8;
                        }
                        switch(DataHdr.DataType)
                        {
                        case cpdatMark: // Синхрометки закодированные по правилам MFM
                        {
                            u8 *Optr2 = Ptr;
                            assert(Size % 2 == 0);
                            for(unsigned j = 0; j < Size / 2; j++)
                            {
                                u16 Mark = be2cpu(ReadU16(Ptr));
                                assert(dst + 1 - trkd[c][h] <= trklen[c][h]);
                                unsigned pos = unsigned(dst - trkd[c][h]);
                                switch(Mark)
                                {
                                case MFM_MARK_A1: // A1
                                    *dst++ = 0xA1;
                                    set_i(c, h, pos);
                                    break;
                                case MFM_MARK_C2: // C2
                                    *dst++ = 0xC2;
                                    set_i(c, h, pos);
                                    break;
                                default:
                                    assert(!"unknown mark");
                                }
                            }
                            Ptr = Optr2;
                            break;
                        }
                        case cpdatData: // Данные (в виде декодированых байтов)
                        case cpdatGap: // Заполнители gap (в виде декодированых байтов)
                            assert(dst + Size - trkd[c][h] <= trklen[c][h]);
                            memcpy(dst, Ptr, Size);
                            dst += Size;
                            break;
                        default:
                            assert(!"invalid data type");
                        }
                        Ptr += Size;
                    }
                } while(!IsEnd);

                Ptr = PtrCapsBlock + CapsBlock.bt.sps.gapoffset;

                auto ProcessGap = [&Ptr, &dst, &GapBitsRemaining, StartPos, c, h, i, this]()
                {
                    bool IsEnd = false;
                    u32 Count = 0;
                    u8 *GapPtr = nullptr;
                    u32 GapDataSize = 0;
                    do
                    {
                        TGapStreamElementHdr GapHdr;
                        ReadGapHdr(&GapHdr, Ptr);

                        IsEnd = (GapHdr.GapSizeWidth == 0 && GapHdr.GapType == cpgapEnd);
                        if(GapHdr.GapSizeWidth != 0)
                        {
                            u32 Size = ReadVarUint(GapHdr.GapSizeWidth, Ptr); // Величина в битах
                            Size = (Size + 7) / 8; // Величина в байтах
                            switch(GapHdr.GapType)
                            {
                            case cpgapCount:
                                Count = Size;
                                break;
                            case cpgapData:
                            {
//                                printf("c=%u,h=%u,i=%u,o=0x%X\n", c, h, i, unsigned(dst - trkd[c][h] + 0x13));

                                if(Count == 0) // GAP переменной длины
                                {
                                    if(dst - trkd[c][h] >= trklen[c][h]) // Начало трэка
                                    {
                                        GapPtr = Ptr;
                                        GapDataSize = Size;
                                    }
                                    else // Конец трэка
                                    {
                                        Count = min(GapBitsRemaining / 8, unsigned(trklen[c][h] - (dst - trkd[c][h])));
                                    }
                                }

                                if(dst - trkd[c][h] < trklen[c][h])
                                {
                                    while(Count)
                                    {
                                        assert(dst - trkd[c][h] < trklen[c][h]);
                                        memcpy(dst, Ptr, Size);
                                        dst += Size;
                                        GapBitsRemaining -= Size * 8;
                                        Count--;
                                    }
                                }
                                else if(Count != 0)
                                {
                                    assert(StartPos >= Count * Size);
                                    dst = trkd[c][h] + StartPos - Count * Size;

                                    u32 CountOld = Count;
                                    while(Count) // GAP фиксированной длины перед C2C2C2FC
                                    {
                                        assert(dst - trkd[c][h] < trklen[c][h]);
                                        memcpy(dst, Ptr, Size);
                                        dst += Size;
                                        GapBitsRemaining -= Size * 8;
                                        Count--;
                                    }

                                    if(GapPtr) // GAP переменной длины в начале трэка
                                    {
                                        dst = trkd[c][h];
                                        Count = StartPos - CountOld * Size;

                                        while(Count)
                                        {
                                            assert(dst - trkd[c][h] < trklen[c][h]);
                                            memcpy(dst, GapPtr, GapDataSize);
                                            dst += GapDataSize;
                                            GapBitsRemaining -= GapDataSize * 8;
                                            Count--;
                                        }

                                        GapPtr = nullptr;
                                    }
                                }
                                Ptr += Size;
                                break;
                            }
                            }
                        }
                    } while(!IsEnd);
                };

                if(CapsBlock.flag.CAPS_BF_GP0) // Fw gap
                {
                    ProcessGap();
                }

                if(CapsBlock.flag.CAPS_BF_GP1) // Bw gap
                {
                    ProcessGap();
                }

//                assert(GapBitsRemaining == 0);
                Ptr = Optr;
            }

            dst += sz - (dst - trkd[c][h]);
            assert(dst - trkd[c][h] == sz);
            dst += (unsigned(sz + 7)) >> 3;
            Ptr = Gptr;
        }
    }

    // Неиспользуемые трэки в конце диска
    for(unsigned c = CapsInfo.maxcylinder + 1; c < MAX_CYLS; c++)
    {
        for(unsigned h = 0; h < sides; h++)
        {
            trklen[c][h] = MAX_TRACK_LEN;
            trkd[c][h] = dst;
            dst += MAX_TRACK_LEN;

            trki[c][h] = dst;
            dst += bitmap_len;
        }
    }

    return 1;
}
