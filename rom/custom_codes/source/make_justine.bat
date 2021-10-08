
@echo off

..\..\..\tools\asl\bin\asl -U -L justine.a80
..\..\..\tools\asl\bin\p2bin justine.p ..\justine.rom -r $-$ -k

del *.lst

pause