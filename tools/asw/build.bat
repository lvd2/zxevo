
@echo off

copy /Y /B makefile.def asl-current
copy /Y /B make.exe asl-current

cd asl-current

make

copy /Y /B asl.exe ..\bin\asw.exe
copy /Y /B p2bin.exe ..\bin
copy /Y /B as.msg ..\bin
copy /Y /B cmdarg.msg ..\bin
copy /Y /B ioerrs.msg ..\bin
copy /Y /B p2bin.msg ..\bin
copy /Y /B tools.msg ..\bin

make clean
del *.exe

cd ..

pause
