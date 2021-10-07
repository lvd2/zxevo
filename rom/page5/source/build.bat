
echo on

cd ..\..\fat_boot\source

call build.bat

cd ..\..\page5\source

..\..\..\tools\mhmt\mhmt -mlz 8x8_ar.fnt 8x8_ar_pack.bin
..\..\..\tools\mhmt\mhmt -mlz 866_code.fnt 866_code_pack.bin
..\..\..\tools\mhmt\mhmt -mlz atm_code.fnt atm_code_pack.bin
..\..\..\tools\mhmt\mhmt -mlz perfpack.bin perfpack_pack.bin

..\..\..\tools\asl\bin\asl -U -L -x -olist rst8service.lst -D DELVAR=0 rst8service.a80
..\..\..\tools\asl\bin\p2bin rst8service.p ..\rst8service.rom -r $-$ -k

..\..\..\tools\asl\bin\asl -U -L -x -olist rst8service_fe.lst -D DOS_FE,DELVAR=0 rst8service.a80
..\..\..\tools\asl\bin\p2bin rst8service.p ..\rst8service_fe.rom -r $-$ -k
