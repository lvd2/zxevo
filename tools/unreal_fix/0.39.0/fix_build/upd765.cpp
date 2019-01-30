#include "std.h"

#include "emul.h"
#include "vars.h"
#include "util.h"

#include "upd765.h"

#if 0
#define dprintf printf
#else
#define dprintf(...)
#endif

static unsigned CalcCmdLen(u8 Cmd)
{
    Cmd &= 0x1F;
    unsigned CmdLen;
    switch(Cmd)
    {
    case 0b00010: CmdLen = 8; break; // read track
    case 0b00011: CmdLen = 2; break; // specify
    case 0b00100: CmdLen = 1; break; // sense drive status
    case 0b00101: CmdLen = 8; break; // write data
    case 0b00110: CmdLen = 8; break; // read data
    case 0b00111: CmdLen = 1; break; // recalibrate
    case 0b01000: CmdLen = 0; break; // sense interrupt status
    case 0b01001: CmdLen = 8; break; // write deleted data
    case 0b01010: CmdLen = 1; break; // read id
    case 0b01100: CmdLen = 8; break; // read deleted data
    case 0b01101: CmdLen = 5; break; // format track
    case 0b01111: CmdLen = 2; break; // seek
    case 0b10001: CmdLen = 8; break; // scan equal
    case 0b11001: CmdLen = 8; break; // scan low or equal
    case 0b11101: CmdLen = 8; break; // scan high or equal
    default: CmdLen = 0;
    }
    return CmdLen;
}

TUpd765::TUpd765()
{
    SelDrive = &comp.fdd[0];
}

void TUpd765::out(u8 data)
{
    // 3FFD (регистр команд/данных)
    if(Msr & (MSR_CB | MSR_EXM))
    {
        dprintf("upd765:   error fdc is busy, d=0x%02X, msr=0x%02X\n", data, Msr);
        return;
    }

    if(DataPtr < _countof(Data))
    {
        if(DataPtr == 0) // Передается код команды
        {
            CmdLen = CalcCmdLen(data);

        }
        Data[DataPtr++] = data;
    }
    if(DataPtr == CmdLen + 1) // execute command
    {
        Msr |= MSR_CB;
        ResultPtr = 0;
        ReadData = false;
        // Защиты используют факт, что в +3 используется только младший бит из us
        // Поэтому при us=2 выбирается тот же дисковод что и при us=0
        // untouchables, batman the movie, chase h.q.
        auto Cmd = Data[0] & 0x1F;
        switch(Cmd)
        {
        case 0b00011: // specify
            dprintf("upd765: specify: srt=%u, hut=%u, hlt=%u, nd=%u\n", Data[1] >> 4U, Data[1] & 0xFU, Data[2] >> 1U, Data[2] & 1U);
            Msr &= ~(MSR_DIO | MSR_CB); // CPU->FDC
            break;
        case 0b00100: // sense drv st
        {
            auto us{ (Data[1] & 3U) };
            auto hd{ (Data[1] >> 2U) & 1U };
            SelDrive = &comp.fdd[us];

            St3 &= ~3;
            St3 |= ST3_RY | us;
            if(pc[us] == 0)
            {
                St3 |= ST3_T0;
            }
            else
            {
                St3 &= ~ST3_T0;
            }
            Result[0] = &St3;
            ResultLen = 1;
            Msr |= MSR_RQM | MSR_DIO; // CPU<-FDC
            dprintf("upd765: sense drv st: hd=%u, us=%u, st3=0x%02X\n", hd, us, St3);
            break;
        }
        case 0b00110: // read data
        case 0b01100: // read deleted data
            ReadData = true;
        case 0b00010: // read track
        {
            c = Data[2];
            h = Data[3];
            r = Data[4];
            n = Data[5];
            auto mt = (Data[0] >> 7U) & 1U;
            auto sk = (Data[0] >> 5U) & 1U;
            auto us = Data[1] & 1U;
            SelDrive = &comp.fdd[us];
            ph[us] = (Data[1] >> 2U) & 1U;
            eot = Data[6];

            const char *CmdStr{ };
            switch(Cmd)
            {
            case 0b00010: CmdStr = "track"; break; // read track
            case 0b00110: CmdStr = "data"; break; // read data
            case 0b01100: CmdStr = "deleted data"; break; // read deleted data
            }

            load();

            auto SecHdr = SelDrive->t.get_sector(r, n);

            dprintf("upd765: read %s: mt=%u, sk=%u, hd=%u, us=%u, c=%u, h=%u, r=%u, n=%u, eot=%u, dtl=%u, pc=%u, ph=%u\n",
                CmdStr, mt, sk, ph[us], us, c, h, r, n, eot, Data[8], pc[us], ph[us]);

            if(SecHdr != nullptr)
            {
                pr[us] = u8(SecHdr - SelDrive->t.hdr);
                DataLen = SecHdr->datlen;
                MaxDataLen = unsigned(MAX_TRACK_LEN - (SecHdr->data - SelDrive->t.trkd));
            }

            Msr |= MSR_EXM;
            St0 = u8((ph[us] << 2U) | us);
            St1 = 0;
            St2 = 0;

            if(SecHdr == nullptr || SecHdr->data == nullptr)
            {
                Msr &= ~MSR_EXM;
                if(ReadData)
                {
                    St0 |= ST0_AT1;
                }
                St1 |= ST1_ND;
                DataLen = 0;
            }

            if(SecHdr != nullptr && SecHdr->c1 == 0)
            {
                Msr &= ~MSR_EXM;
                St0 |= ST0_AT1;
                St1 |= ST1_DE;
                DataLen = 0;
            }

            if(SecHdr != nullptr && (Cmd == 0b00110 && (SecHdr->Flags & SECHDR::FL_DDAM) ||
                Cmd == 0b01100 && !(SecHdr->Flags & SECHDR::FL_DDAM)))
            {
                St2 |= ST2_CM;
                if(sk != 0) // skip data/deleted data
                {
                    Msr &= ~MSR_EXM;
                    DataLen = 0;
                }
            }

            if(SecHdr != nullptr && SecHdr->c != c)
            {
                St2 |= ST2_WC;

                if(c == 0xFF)
                {
                    St2 |= ST2_BC;
                }
            }

            Result[0] = &St0;
            Result[1] = &St1;
            Result[2] = &St2;
            Result[3] = &c;
            Result[4] = &h;
            Result[5] = &r;
            Result[6] = &n;
            ResultLen = 7;
            Msr |= MSR_RQM | MSR_DIO; // CPU<-FDC
            break;
        }
        case 0b00111: // recalibrate
        {
            auto us{ Data[1] & 3U };
            SelDrive = &comp.fdd[us];
            trdos_seek = ROMLED_TIME;
            dprintf("upd765: recalibrate: us=%u\n", us);
            pc[us] = 0;
            ph[us] = 0;
            pr[us] = 0;
            seek();
            St0 = u8(ST0_SE | us);
            St3 |= ST3_T0;
            Msr &= ~(MSR_DIO | MSR_CB); // CPU->FDC
            break;
        }
        case 0b01000: // sense int
        {
            Result[0] = &St0;
            Result[1] = &pc[SelDrive->Id];
            ResultLen = 2;
            Msr |= MSR_RQM | MSR_DIO; // CPU<-FDC
            dprintf("upd765: sense int: st0=0x%02X, pc=%u, c=%u\n", St0, pc[SelDrive->Id], c);
            break;
        }
        case 0b01010: // read id
        {
            u8 us{ u8(Data[1] & 1U) };
            ph[us] = (Data[1] >> 2U) & 1U;
            SelDrive = &comp.fdd[us];

            load();

            St0 = u8((ph[us] << 2U) | us);
            St1 = 0;
            St2 = 0;

            const auto opr = pr[us];
            if(SelDrive->t.s == 0) // Трэк без секторов
            {
                St1 |= ST1_MA;
            }
            else
            {
                const auto &SecHdr = SelDrive->t.hdr[pr[us]];
                pr[us]++;
                if(pr[us] >= SelDrive->t.s)
                {
                    pr[us] = 0;
                }
                c = SecHdr.c;
                h = SecHdr.s;
                r = SecHdr.n;
                n = SecHdr.l;

                if(SecHdr.c1 == 0)
                {
                    St1 |= ST1_DE | ST1_ND;
                }

                if(c == 0xFF && c != SecHdr.c)
                {
                    St2 |= ST2_BC;
                }
            }

            Result[0] = &St0;
            Result[1] = &St1;
            Result[2] = &St2;
            Result[3] = &c;
            Result[4] = &h;
            Result[5] = &r;
            Result[6] = &n;
            ResultLen = 7;
            Msr |= MSR_RQM | MSR_DIO; // CPU<-FDC
            dprintf("upd765: read id: hd=%u, us=%u, c=%u, h=%u, r=%u, n=%u, pc=%u, ph=%u, pr=%u\n",
                h, Data[1] & 3U, c, h, r, n, pc[us], ph[us], opr);
            break;
        }
        case 0b01111: // seek
        {
            trdos_seek = ROMLED_TIME;
            u8 us{ u8(Data[1] & 3U) };
            auto oph = ph[us];
            auto opc = pc[us];
            ph[us] = (Data[1] >> 2U) & 1U;
            pc[us] = u8(Data[2]);
            SelDrive = &comp.fdd[us];
            if(oph != ph[us] || opc != pc[us])
            {
                pr[us] = 0;
            }
            dprintf("upd765: seek: hd=%u, us=%u, ncn=%u\n", ph[us], us, pc[us]);
            seek();
            St0 = u8(ST0_SE | (ph[us] << 2U) | us);
            if(pc[us] != 0)
            {
                St3 &= ~ST3_T0;
            }
            Msr &= ~(MSR_DIO | MSR_CB); // CPU->FDC
            break;
        }
        default:
            dprintf("upd765: unk cmd=0x%02X\n", Data[0]);
            St0 = ST0_IC;
            Result[0] = &St0;
            ResultLen = 1;
            Msr |= MSR_RQM | MSR_DIO; // CPU<-FDC
            break;
        }
        DataPtr = 0;
    }
}

static unsigned PollCnt = 10;
static unsigned DataLenPrev = 0;

u8 TUpd765::in(u8 port)
{
    switch(port)
    {
        case 2: // 2FFD (main status register)
//            printf("upd765: read msr: msr=0x%02X\n", Msr);
            if(DataLen != 0)
            {
                if(PollCnt == 0)
                {
                    ReadDataReg();
                    St1 |= ST1_OR;
                }
                else
                {
                    if(DataLen == DataLenPrev)
                    {
                        PollCnt--;
                    }
                }
                DataLenPrev = DataLen;
            }
            else
            {
                PollCnt = 10;
            }
            return Msr; // детект +3/+2A осуществляется по биту D7 main status register (если 1, то +3)
        case 3: // 3FFD (регистр данных)
            return ReadDataReg();
    }
    return 0xFF;
}

u8 TUpd765::ReadDataReg()
{
    if(DataLen != 0) // Данные
    {
        trdos_load = ROMLED_TIME;

        const auto *SecHdr = &SelDrive->t.hdr[pr[SelDrive->Id]];//SelDrive->t.get_sector(r, n);
        auto DataIdx = SecHdr->datlen - DataLen;
        auto Data = SecHdr->data[DataIdx];

        DataLen--;
        MaxDataLen--;

        bool Overrun = false;
        if(MaxDataLen == 0)
        {
            Overrun = (DataLen != 0);
            DataLen = 0;
        }

        if(DataLen == 0)
        {
            pr[SelDrive->Id]++;// = u8(SecHdr - SelDrive->t.hdr + 1);
            pr[SelDrive->Id] %= SelDrive->t.s;
        }

        if(DataLen == 0 && SecHdr->c2 == 0)
        {
            Msr &= ~MSR_EXM;
            St0 &= ~ST0_IC_MASK;
            St0 |= ST0_AT1;
            St1 |= ST1_DE;
            St2 |= ST2_DD;
            Data ^= rdtsc(); // Ошибка crc в зоне данных сектора

            dprintf("upd765:   data transfer complete1\n");
            return Data;
        }

        if(DataLen == 0 && r < eot)
        {
            r++;
            SecHdr = SelDrive->t.get_sector(r, n);
            if(SecHdr == nullptr) // Сектор не найден
            {
                St0 &= ~ST0_IC_MASK;
                St0 |= ST0_AT1;

                St1 |= ST1_ND;
                St1 |= ST1_MA;
                St2 |= ST2_MD;

                DataLen = 0;
            }
            else
            {
                pr[SelDrive->Id] = u8(SecHdr - SelDrive->t.hdr);
                pr[SelDrive->Id] %= SelDrive->t.s;

                n = SecHdr->l;
                DataLen = SecHdr->datlen;

                if(SecHdr->c1 == 0)
                {
                    St0 &= ~ST0_IC_MASK;
                    St0 |= ST0_AT1;

                    St1 |= ST1_DE;
                    St2 |= ST2_DD;
                    DataLen = 0;
                }
            }
        }

        if(ReadData && DataLen == 0 && (r >= eot || Overrun))
        {
            St0 &= ~ST0_IC_MASK;
            St0 |= ST0_AT1;

            St1 |= ST1_EN; // Всегда установлен на +3 (см. комментарии в дизассемблере +3dos (0x204A))
        }

        if(DataLen == 0)
        {
            dprintf("upd765:   data transfer complete2\n");
            Msr &= ~MSR_EXM;
        }
        return Data;
    }
    else // Результаты
    {
        assert((Msr & MSR_EXM) == 0);
        if(ResultPtr < ResultLen)
        {
            u8 Res = *Result[ResultPtr++];
            dprintf("upd765:   read result: 0x%02X\n", Res);
            if(ResultPtr == ResultLen)
            {
                dprintf("upd765:   read result complete\n");
                assert((Msr & (MSR_DIO | MSR_CB)) != 0);
                Msr &= ~(MSR_DIO | MSR_CB); // CPU->FDC
                St0 &= ~ST0_IC_MASK;
                St0 |= ST0_IC;
            }
            return Res;
        }
        else
        {
            dprintf("upd765:   error no result to read\n");
        }
    }

    return 0xFF;
}

void TUpd765::load()
{
    seek(LOAD_SECTORS);
}

void TUpd765::seek(SEEK_MODE SeekMode)
{
    auto cyl{ pc[SelDrive->Id] /*/ 2*/ };
    if(cyl > 42)
    {
        cyl = 42;
    }
    SelDrive->track = cyl;
    SelDrive->t.seek(SelDrive, cyl, ph[SelDrive->Id], SeekMode);
}

TUpd765 Upd765;
