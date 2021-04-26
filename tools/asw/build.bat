
@echo off

copy makefile.def asl-current

cd asl-current

make clean
make

copy asl.exe ..\bin\asw.exe
copy p2bin.exe ..\bin
copy as.msg ..\bin
copy cmdarg.msg ..\bin
copy ioerrs.msg ..\bin
copy p2bin.msg ..\bin
copy tools.msg ..\bin

cd ..

pause
