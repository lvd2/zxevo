#pragma once

extern char asmbuf[0x40];
extern unsigned char asmresult[24];

const unsigned char *disasm(const unsigned char *cmd, unsigned current, char labels);
unsigned assemble_cmd(unsigned char *cmd, unsigned addr);
