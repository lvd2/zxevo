@ECHO OFF
rem set PATH=c:\mingw\avrgcc\bin;%PATH%
set PATH=c:\mingw\avrgcc\bin;c:\mingw\bin;c:\mingw\msys\bin

set FPGA_PATH=fpga/quartus
set FPGA_FILE=top.rbf

set AVR_PATH=avr/build
set AVR_FILE=top.mlz

set RESULT=zxevo_fw.bin

set MHMT_BIN="../../../tools/mhmt/mhmt.exe"

IF NOT EXIST %FPGA_PATH%/%FPGA_FILE% (
        ECHO top.rbf not found
		ECHO First assemble the fpga sources
		ECHO Then run winbuild.bat
		pause 0
        EXIT /b
)

%MHMT_BIN% -maxwin2048 %FPGA_PATH%/%FPGA_FILE% %AVR_PATH%/%AVR_FILE%

make -C %AVR_PATH%
copy avr\build\zxevo.bin zxevo_fw.bin
copy zxevo_fw.bin e:\zxevo_fw.bin
