
@ECHO OFF

cd ..\..\fat_boot\source

CALL make.bat

cd ..\..\page5\source

..\..\..\tools\mhmt\mhmt -mlz 8x8_ar.fnt 8x8_ar_pack.bin
..\..\..\tools\mhmt\mhmt -mlz 866_code.fnt 866_code_pack.bin
..\..\..\tools\mhmt\mhmt -mlz atm_code.fnt atm_code_pack.bin
..\..\..\tools\mhmt\mhmt -mlz perfpack.bin perfpack_pack.bin

..\..\..\tools\asw\bin\asw -U -L -D DELVAR=1 rst8service.a80
..\..\..\tools\asw\bin\p2bin rst8service.p ..\rst8service.rom -r $-0xFFFF
..\..\..\tools\asw\bin\p2bin rst8service.p ..\cashrm.rom -r 0x10000-0x13FFF
..\..\..\tools\asw\bin\p2bin rst8service.p ..\cashrmsts.rom -r 0x14000-$ -k
