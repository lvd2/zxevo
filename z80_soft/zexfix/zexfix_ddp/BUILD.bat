@echo off
del /f /q *.p
del /f /q *.lst
if exist zexall.bin del /f /q zexall.bin
if exist zexfix.bin del /f /q zexfix.bin

rem --- Compile with "Macro Assembler AS" http://john.ccac.rwth-aachen.de:8000/as/
rem set %PATHASW%=C:\ASW

echo ===== Make ZEXALL =====
%PATHASW%\bin\asw.exe -cpu z80undoc -L zexall__StuartBrady2007.a80
if exist zexall__StuartBrady2007.p %PATHASW%\bin\p2bin.exe zexall__StuartBrady2007.p zexall.bin -r $-$ -k
if not exist zexall.bin goto err

echo ===== Make ZEXFIX =====
%PATHASW%\bin\asw.exe -cpu z80undoc -L zexallfix__JB.a80
if exist zexallfix__JB.p %PATHASW%\bin\p2bin.exe zexallfix__JB.p zexfix.bin -r $-$ -k
if not exist zexfix.bin goto err

goto ok

:err
echo * ERROR! *

:ok
