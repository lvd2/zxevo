
@ECHO OFF

..\..\..\tools\asw\bin\asw -U -L -D DELVAR=1 main.a80
..\..\..\tools\asw\bin\p2bin main.p main.rom -r $-$ -k

..\..\..\tools\asw\bin\asw -U -L make_cmosset.a80
..\..\..\tools\asw\bin\p2bin make_cmosset.p cmosset.rom -r $-$ -k

..\..\..\tools\mhmt\mhmt -mlz main.rom main_pack.rom
..\..\..\tools\mhmt\mhmt -mlz cmosset.rom cmosset_pack.rom
..\..\..\tools\mhmt\mhmt -mlz chars_eng.bin chars_pack.bin

..\..\..\tools\asw\bin\asw -U -L -D dos_fe=0,DELVAR=0 services.a80
..\..\..\tools\asw\bin\p2bin services.p ..\services.rom -r $-$ -k

..\..\..\tools\asw\bin\asw -U -L -D dos_fe=1,DELVAR=0 services.a80
..\..\..\tools\asw\bin\p2bin services.p ..\services_fe.rom -r $-$ -k

del main.rom
del cmosset.rom
del main_pack.rom
del cmosset_pack.rom
