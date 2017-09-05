@ECHO OFF

..\..\..\tools\asw\bin\asw -U -L -D DELVAR=0 main.a80
..\..\..\tools\asw\bin\p2bin main.p main.rom -r $-$ -k

..\..\..\tools\mhmt\mhmt -mlz main.rom main_pack.rom

pause