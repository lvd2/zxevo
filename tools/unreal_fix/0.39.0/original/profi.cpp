#include "std.h"

#include "emul.h"
#include "vars.h"
#include "draw.h"
#include "profi.h"

static u8 profi_pal[0x10] = { };

void profi_writepal(u8 val)
{
    unsigned ProfiPalIdx = (~comp.pFE) & 0xF;
    assert(ProfiPalIdx < 0x10);
    profi_pal[ProfiPalIdx] = val; // Gg0Rr0Bb

    // Преобразование палитры в формат ULA+
    u8 PalIdx = ((ProfiPalIdx & 8) << 1) | (ProfiPalIdx & 7);
    comp.comp_pal[PalIdx + 0 * 8] =
    comp.comp_pal[PalIdx + 1 * 8] =
    comp.comp_pal[PalIdx + 3 * 8] =
    comp.comp_pal[PalIdx + 5 * 8] = u8(t.profi_pal_map[val]);
    temp.comp_pal_changed = 1;
}
