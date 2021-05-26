
echo off

..\..\..\tools\asw\bin\asw -U -L dos_fe.a80
..\..\..\tools\asw\bin\p2bin dos_fe.p dos_fe.rom -r $-$ -k

..\..\..\tools\mhmt\mhmt -mlz dos_fe.rom ..\dos_fe_pack.rom

rem del dos_fe.rom
