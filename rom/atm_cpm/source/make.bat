
@ECHO OFF

..\..\..\tools\asw\bin\asw -U -L -D DELVAR=1 rbios.a80
..\..\..\tools\asw\bin\p2bin rbios.p ..\rbios.rom -r $-$ -k
