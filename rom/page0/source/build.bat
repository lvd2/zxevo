
echo off

cd ..\..\mainmenu\src

call build.bat

cd ..\..\page0\source

..\..\..\tools\asl\bin\asl -U -L -x -olist services.lst services.a80
..\..\..\tools\asl\bin\p2bin services.p ..\services.rom -r $-$ -k

..\..\..\tools\asl\bin\asl -U -L -x -olist services_fe.lst -D DOS_FE services.a80
..\..\..\tools\asl\bin\p2bin services.p ..\services_fe.rom -r $-$ -k
