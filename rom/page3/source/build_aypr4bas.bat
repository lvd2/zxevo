
echo off

..\..\..\tools\asl\bin\asl -cpu z80undoc -U -L aypr4bas.a80
..\..\..\tools\asl\bin\p2bin aypr4bas.p aypr4bas.rom -r $-$ -k

pause