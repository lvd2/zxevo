#pragma once

struct TUpd765
{
    static constexpr u8 MSR_RQM = 0b10000000;
    static constexpr u8 MSR_DIO = 0b01000000;
    static constexpr u8 MSR_EXM = 0b00100000;
    static constexpr u8 MSR_CB = 0b00010000;

    static constexpr u8 ST0_IC_MASK = 0b11000000;
    static constexpr u8 ST0_NT = 0b00000000;
    static constexpr u8 ST0_AT1 = 0b01000000;
    static constexpr u8 ST0_IC = 0b10000000;
    static constexpr u8 ST0_AT2 = 0b11000000;
    static constexpr u8 ST0_SE = 0b00100000;
    static constexpr u8 ST0_EC = 0b00010000;
    static constexpr u8 ST0_NR = 0b00001000;
    static constexpr u8 ST0_HD = 0b00000100;
    static constexpr u8 ST0_US1 = 0b00000010;
    static constexpr u8 ST0_US0 = 0b00000001;

    static constexpr u8 ST1_EN = 0b10000000;
    static constexpr u8 ST1_DE = 0b00100000;
    static constexpr u8 ST1_OR = 0b00010000;
    static constexpr u8 ST1_ND = 0b00000100;
    static constexpr u8 ST1_MA = 0b00000001;

    static constexpr u8 ST2_CM = 0b01000000;
    static constexpr u8 ST2_DD = 0b00100000;
    static constexpr u8 ST2_WC = 0b00010000;
    static constexpr u8 ST2_BC = 0b00000010;
    static constexpr u8 ST2_MD = 0b00000001;


    static constexpr u8 ST3_FT = 0b10000000;
    static constexpr u8 ST3_WP = 0b01000000;
    static constexpr u8 ST3_RY = 0b00100000;
    static constexpr u8 ST3_T0 = 0b00010000;
    static constexpr u8 ST3_TS = 0b00001000;
    static constexpr u8 ST3_HD = 0b00000100;
    static constexpr u8 ST3_US1 = 0b00000010;
    static constexpr u8 ST3_US0 = 0b00000001;

    u8 Data[9];
    u8 *Result[7];

    u8 Msr = MSR_RQM;

    u8 St0 = 0;
    u8 St1 = 0;
    u8 St2 = 0;
    u8 St3 = 0;

    // Физические параметры
    u8 pc[4]{ };
    u8 ph[4]{ };
    u8 pr[4]{ };

    // Логические параметры
    u8 c = 0;
    u8 h = 0;
    u8 r = 1;
    u8 n = 2; // 512b

    u8 eot = 0;

    unsigned CmdLen = 0;
    unsigned DataPtr = 0;

    unsigned ResultLen = 0;
    unsigned ResultPtr = 0;

    unsigned DataLen = 0;
    unsigned MaxDataLen = 0;
    bool ReadData = false;

    struct FDD *SelDrive;

    TUpd765();
    void out(u8 data);
    u8 in(u8 port);

    u8 ReadDataReg();

    void load();
    void seek(SEEK_MODE SeekMode = JUST_SEEK);
};

extern TUpd765 Upd765;
