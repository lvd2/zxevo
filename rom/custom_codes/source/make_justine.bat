
@echo off

..\..\..\tools\asw\bin\asw -U -L justine.a80
..\..\..\tools\asw\bin\p2bin justine.p ..\justine.rom -r $-$ -k

del *.lst

pause