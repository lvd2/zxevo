
echo off

..\..\..\tools\asw\bin\asw -U -L -D DELVAR=1 basic48.a80
..\..\..\tools\asw\bin\p2bin basic48.p ..\basic48_128.rom -r $-$ -k
 