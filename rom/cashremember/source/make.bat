
@ECHO OFF

..\..\..\tools\asw\bin\asw -U -L cash20.a80
..\..\..\tools\asw\bin\p2bin cash20.p cash20.rom -r $-$ -k

rem asw -U -L viewer.a80
rem p2bin viewer.p viewer.rom -r $-$ -k

..\..\..\tools\mhmt\mhmt -mlz cash20.rom ..\cashrm_pack.rom
..\..\..\tools\mhmt\mhmt -mlz sts4_3j.bin ..\sts43j_pack.rom
..\..\..\tools\mhmt\mhmt -mlz sts4_3i.bin ..\sts43i_pack.rom

rem asw -U -L make_scl.a80
rem p2bin make_scl.p make_scl.rom -r $-$ -k

rem csum32 make_scl.rom
rem copy /B /Y make_scl.rom+csum32.bin cash20.scl

rem del csum32.bin
rem del *.lst
del *.rom
