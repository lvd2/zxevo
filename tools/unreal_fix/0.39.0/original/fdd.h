#pragma once

struct SECHDR
{
    unsigned char c, s, n, l;
    unsigned short crc; // CRC ��������� �������

    // ����� crc ���� ������ � ������:
    // ��� ��������������:
    //   0 - ������������ ���������� �������� crc
    //   1 - ������ crc �� crc(��� ������)/crcd(��� ������)
    //   2 - ��������� crc (������������ ��������� ����������� crc))
    // ��� ������ (������� seek ������������� ���� c1 � c2):
    //   0 - ������������ crc �� ��������� � ��������� � ��������� (������������ crc error)
    //   1 - ������������ crc ��������� � ��������� � ���������
    unsigned char c1, c2;
    
    // ��������� �� ������ ������� ������ �����
    // ��� �������������� ����������� ��������:
    //   1 -��������� ������ ������
    u8 *data;
    u8 *id; // ��������� �� ��������� ������� ������ �����
    u8 *wp; // ��������� �� ������� ����� ������� ������ ������� ������ ����� (������������ ������ ��� ��������)
    unsigned wp_start; // ����� ������� ���� � ����� ������� ������ (������������ ������ �����) ��� ������� �������

    // ������ ������� � ������
    // ��� ��������������:
    //   0 - ������ ������� ������� ��� (128 << n) & SectorSizeMask
    unsigned datlen;
    unsigned crcd;        // used to load specific CRC from FDI-file

    // ������������ ��� .dsk �������
    static constexpr u8 FL_DDAM{ 0b00000001 };
    u8 Flags = 0;
};

enum SEEK_MODE
{
    JUST_SEEK = 0, LOAD_SECTORS = 1
};

static inline bool test_bit(const u8 *data, unsigned bit)
{
    return (data[bit >> 3] & (1U << (bit & 7))) != 0;
}

static inline void set_bit(u8 *data, unsigned bit)
{
    data[bit >> 3] |= (1U << (bit & 7));
}

static inline void clr_bit(u8 *data, unsigned bit)
{
    data[bit >> 3] &= ~(1U << (bit & 7));
}


struct TRKCACHE
{
    // cached track position
    struct FDD *drive;
    unsigned cyl, side; // ���������� ���������

    // generic track data
    unsigned trklen;
    // pointer to data inside UDI
    u8 *trkd; // ������ (����� ���� NULL, ���� ���� ��� ������)
    u8 *trki; // ������� ����� ���������������
    u8 *trkwp; // ������� ����� ������� ������
    unsigned ts_byte;                 // cpu.t per byte
    SEEK_MODE sf;                     // flag: is sectors filled
    unsigned s;                       // no. of sectors
    // sectors on track
    SECHDR hdr[MAX_SEC];

    void set_i(unsigned pos)
    {
        set_bit(trki, pos);
    }
    void clr_i(unsigned pos)
    {
        clr_bit(trki, pos);
    }
    bool test_i(unsigned pos)
    {
        return test_bit(trki, pos);
    }

    void set_wp(unsigned pos)
    {
        set_bit(trkwp, pos);
    }
    bool test_wp(unsigned pos)
    {
        return test_bit(trkwp, pos);
    }

    void write(unsigned pos, unsigned char byte, u8 index)
    {
        if(!trkd)
            return;

        trkd[pos] = byte;
        if(index)
            set_i(pos);
        else
            clr_i(pos);
    }

    void seek(FDD *d, unsigned cyl, unsigned side, SEEK_MODE fs);
    void format(); // before use, call seek(d,c,s,JUST_SEEK), set s and hdr[]
    unsigned write_sector(unsigned sec, unsigned l, unsigned char *data); // call seek(d,c,s,LOAD_SECTORS)
    const SECHDR *get_sector(unsigned sec, unsigned l) const; // before use, call fill(d,c,s,LOAD_SECTORS)

    void dump();
    void clear()
    {
        drive = nullptr;
        trkd = nullptr;
        ts_byte = Z80FQ / (MAX_TRACK_LEN * FDD_RPS);
    }
    TRKCACHE()
    {
        clear();
    }
};

struct FDD
{
    u8 Id;
    // drive data

    __int64 motor;       // 0 - not spinning, >0 - time when it'll stop
    unsigned char track; // head position

    // disk data

    unsigned char *rawdata;              // used in VirtualAlloc/VirtualFree
    unsigned rawsize;

    // ��������� ����� ������� (��� �������� ������ ��� ��� �������� ������� �����), ����� ���� ��������� �� MAX_CYLS
    // ����� ������������� �������������� ������� ��������� ���� ADS � ��������
    unsigned cyls;
    unsigned sides;
    unsigned trklen[MAX_CYLS][2];
    u8 *trkd[MAX_CYLS][2]; // ������
    u8 *trki[MAX_CYLS][2]; // ������� ����� ���������������
    u8 *trkwp[MAX_CYLS][2]; // ������� ����� ������� ������
    unsigned char optype; // bits: 0-not modified, 1-write sector, 2-format track
    unsigned char snaptype;

    TRKCACHE t; // used in read/write image
    char name[0x200];
    char dsc[0x200];

    char test();
    void free();
    int index();

    void format_trd(unsigned CylCnt); // ������������ ������ ��� wldr_trd
    void emptydisk(unsigned FreeSecCnt); // ������������ ������ ��� wldr_trd
    int addfile(unsigned char *hdr, unsigned char *data); // ������������ ������ ��� wldr_trd
    void addboot(); // ������������ ������ ��� wldr_trd

    void set_i(unsigned c, unsigned s, unsigned pos)
    {
        set_bit(trki[c][s], pos);
    }

    void newdisk(unsigned cyls, unsigned sides);

    int read(unsigned char snType);

    int read_scl();
    int read_hob();
    int read_trd();
    int write_trd(FILE *ff);
    int read_fdi();
    int write_fdi(FILE *ff);
    int read_td0();
    int write_td0(FILE *ff);
    int read_udi();
    int write_udi(FILE *ff);

    void format_isd();
    int read_isd();
    int write_isd(FILE *ff);

    void format_pro();
    int read_pro();
    int write_pro(FILE *ff);

    int read_dsk();
    int read_ipf();

    ~FDD()
    {
        free();
    }
};

bool done_fdd(bool Cancelable);
