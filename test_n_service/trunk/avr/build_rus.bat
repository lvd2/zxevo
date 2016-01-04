@echo off
if exist fpga.mlz del /f /q fpga.mlz
if exist fpga.inc del /f /q fpga.inc
if exist _message.inc del /f /q _message.inc
if exist service.hex del /f /q service.hex
if exist service.eep.hex del /f /q service.eep.hex
if exist ..\rus\zxevo_fw.bin del /f /q ..\rus\zxevo_fw.bin
echo .EQU DEF_LANG = $00 >deflang.inc
..\..\..\tools\mhmt\mhmt.exe -mlz -maxwin2048 ..\fpga\main.rbf fpga.mlz
..\..\..\tools\bin2avr\bin2avr.exe fpga.mlz
..\..\..\tools\sfep\sfep.exe _message.asm
..\..\..\tools\avra\avra.exe -fI service.asm -e service.eep.hex -l service.lst
if errorlevel 1 goto quit
if not exist ..\rus md ..\rus
..\..\..\tools\make_fw\make_fw.exe service.hex service.eep.hex ..\rus\zxevo_fw.bin version.txt %1
:quit