#pragma once

struct PC_KEY
{
   unsigned char vkey;
   unsigned char normal;
   unsigned char shifted;
};

extern const PC_KEY pc_layout[];
extern const size_t pc_layout_count;
