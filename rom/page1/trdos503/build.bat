
echo off

..\..\..\tools\asl\bin\asl -L trdos503.a80
..\..\..\tools\asl\bin\p2bin trdos503.p ..\trdos503.rom -r $-$ -k
