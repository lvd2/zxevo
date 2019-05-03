
@ECHO OFF

cd ..\..\fat_boot\source

call make.bat

cd ..\..\page5\source

..\..\..\tools\mhmt\mhmt -mlz 8x8_ar.fnt 8x8_ar_pack.bin
..\..\..\tools\mhmt\mhmt -mlz 866_code.fnt 866_code_pack.bin
..\..\..\tools\mhmt\mhmt -mlz atm_code.fnt atm_code_pack.bin
..\..\..\tools\mhmt\mhmt -mlz perfpack.bin perfpack_pack.bin

..\..\..\tools\asw\bin\asw -U -L -x -olist rst8service.lst -D DELVAR=0 rst8service.a80
..\..\..\tools\asw\bin\p2bin rst8service.p ..\rst8service.rom -r $-$ -k

..\..\..\tools\asw\bin\asw -U -L -x -olist rst8service_fe.lst -D DOS_FE,DELVAR=0 rst8service.a80
..\..\..\tools\asw\bin\p2bin rst8service.p ..\rst8service_fe.rom -r $-$ -k
