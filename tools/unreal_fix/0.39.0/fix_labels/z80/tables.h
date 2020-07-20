#pragma once
extern const unsigned char rl0[];
extern const unsigned char rl1[];

extern const unsigned char rr0[];
extern const unsigned char rr1[];

extern const unsigned char rlcf[];
extern const unsigned char rrcf[];

#ifdef __ICL
extern unsigned char rol[];
extern unsigned char ror[];
extern unsigned char rlcaf[];
extern unsigned char rrcaf[];
#else
struct TMakeRot
{
    constexpr TMakeRot();

    u8 rol[0x100];
    u8 ror[0x100];
    u8 rlcaf[0x100];
    u8 rrcaf[0x100];
};

extern const TMakeRot MakeRot;
#define rol MakeRot.rol
#define ror MakeRot.ror
#define rlcaf MakeRot.rlcaf
#define rrcaf MakeRot.rrcaf
#endif

extern const unsigned char sraf[];


#ifdef __ICL
extern unsigned char log_f[];
#else
struct TLogf
{
    constexpr TLogf();

    u8 log_f[0x100];
};

extern const TLogf Logf;
#define log_f Logf.log_f
#endif

extern const unsigned char incf[];
extern const unsigned char decf[];

#ifdef __ICL
extern unsigned char adcf[];
#else

struct TMakeAdcf
{
    constexpr TMakeAdcf();

    u8 adcf[0x20000];
};

extern const TMakeAdcf MakeAdcf;

#define adcf MakeAdcf.adcf
#endif

#ifdef __ICL
extern unsigned char sbcf[];
extern unsigned char cpf[];
extern unsigned char cpf8b[];
#else

struct TMakeSbc
{
    constexpr TMakeSbc();

    u8 sbcf[0x20000];
    u8 cpf[0x10000];
    u8 cpf8b[0x10000];
};

extern const TMakeSbc MakeSbc;

#define sbcf MakeSbc.sbcf
#define cpf MakeSbc.cpf
#define cpf8b MakeSbc.cpf8b
#endif

Z80INLINE void and8(Z80 *cpu, unsigned char src)
{
   cpu->a &= src;
   cpu->f = log_f[cpu->a] | HF;
}

Z80INLINE void or8(Z80 *cpu, unsigned char src)
{
   cpu->a |= src;
   cpu->f = log_f[cpu->a];
}

Z80INLINE void xor8(Z80 *cpu, unsigned char src)
{
   cpu->a ^= src;
   cpu->f = log_f[cpu->a];
}

Z80INLINE void bitmem(Z80 *cpu, unsigned char src, unsigned char bit)
{
   cpu->f = log_f[src & (1 << bit)] | HF | (cpu->f & CF);
   cpu->f = (cpu->f & ~(F3|F5)) | (cpu->memh & (F3|F5));
}

Z80INLINE void set(unsigned char &src, unsigned char bit)
{
   src |= (1 << bit);
}

Z80INLINE void res(unsigned char &src, unsigned char bit)
{
   src &= ~(1 << bit);
}

Z80INLINE void bit(Z80 *cpu, unsigned char src, unsigned char bit)
{
   cpu->f = log_f[src & (1 << bit)] | HF | (cpu->f & CF) | (src & (F3|F5));
}

Z80INLINE unsigned char resbyte(unsigned char src, unsigned char bit)
{
   return src & ~(1 << bit);
}

Z80INLINE unsigned char setbyte(unsigned char src, unsigned char bit)
{
   return u8(src | (1U << bit));
}

Z80INLINE void inc8(Z80 *cpu, unsigned char &x)
{
   cpu->f = incf[x] | (cpu->f & CF);
   x++;
}

Z80INLINE void dec8(Z80 *cpu, unsigned char &x)
{
   cpu->f = decf[x] | (cpu->f & CF);
   x--;
}

Z80INLINE void add8(Z80 *cpu, unsigned char src)
{
   cpu->f = adcf[cpu->a + src*0x100];
   cpu->a += src;
}

Z80INLINE void sub8(Z80 *cpu, unsigned char src)
{
   cpu->f = sbcf[cpu->a*0x100 + src];
   cpu->a -= src;
}

Z80INLINE void adc8(Z80 *cpu, unsigned char src)
{
   unsigned char carry = ((cpu->f) & CF);
   cpu->f = adcf[cpu->a + src*0x100 + 0x10000*carry];
   cpu->a += src + carry;
}

Z80INLINE void sbc8(Z80 *cpu, unsigned char src)
{
   unsigned char carry = ((cpu->f) & CF);
   cpu->f = sbcf[cpu->a*0x100 + src + 0x10000*carry];
   cpu->a -= src + carry;
}

Z80INLINE void cp8(Z80 *cpu, unsigned char src)
{
   cpu->f = cpf[cpu->a*0x100 + src];
}

void init_z80tables();
