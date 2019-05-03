
@ECHO OFF

cd ..\..\mainmenu\src

call make.bat

cd ..\..\page0\source

..\..\..\tools\asw\bin\asw -U -L -x -olist services.lst services.a80
..\..\..\tools\asw\bin\p2bin services.p ..\services.rom -r $-$ -k

..\..\..\tools\asw\bin\asw -U -L -x -olist services_fe.lst -D DOS_FE services.a80
..\..\..\tools\asw\bin\p2bin services.p ..\services_fe.rom -r $-$ -k
