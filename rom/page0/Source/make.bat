
@ECHO OFF

cd ..\..\mainmenu\src

call make.bat

cd ..\..\page0\source

..\..\..\tools\asw\bin\asw -U -L services.a80
..\..\..\tools\asw\bin\p2bin services.p ..\services.rom -r $-$ -k

..\..\..\tools\asw\bin\asw -U -L -D DOS_FE services.a80
..\..\..\tools\asw\bin\p2bin services.p ..\services_fe.rom -r $-$ -k
