
echo off

..\..\..\tools\asw\bin\asw -U -L -x -olist main.lst main.a80
..\..\..\tools\asw\bin\p2bin main.p main.rom -r $-$ -k

..\..\..\tools\asw\bin\asw -U -L -x -olist main_fe.lst -D DOS_FE main.a80
..\..\..\tools\asw\bin\p2bin main.p main_fe.rom -r $-$ -k

..\..\..\tools\asw\bin\asw -U -L cmosset.a80
..\..\..\tools\asw\bin\p2bin cmosset.p cmosset.rom -r $-$ -k

..\..\..\tools\mhmt\mhmt -mlz main.rom ..\main_pack.rom
..\..\..\tools\mhmt\mhmt -mlz main_fe.rom ..\main_fe_pack.rom
..\..\..\tools\mhmt\mhmt -mlz cmosset.rom ..\cmosset_pack.rom
..\..\..\tools\mhmt\mhmt -mlz chars_eng.bin ..\chars_pack.rom

rem del *.rom
