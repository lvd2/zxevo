
echo off

..\..\..\tools\asw\bin\asw -L trdos503.a80
..\..\..\tools\asw\bin\p2bin trdos503.p ..\trdos503.rom -r $-$ -k
