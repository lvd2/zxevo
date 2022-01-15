
echo off

..\..\..\tools\asl\bin\asl -U -L -x -olist neo-dos.lst -D EMU=1 neo-dos.a80
..\..\..\tools\asl\bin\p2bin neo-dos.p ..\neo-dos.rom -r $-$ -k
