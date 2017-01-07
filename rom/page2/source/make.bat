
@ECHO OFF

..\..\..\tools\asw\bin\asw -U -L spec128_0.a80
..\..\..\tools\asw\bin\p2bin spec128_0.p ..\basic128.rom -r $-$ -k
