
@echo off

copy /Y /B makefile.def asl-current
copy /Y /B make.exe asl-current

cd asl-current

make

copy /Y /B *.exe ..\bin
copy /Y /B *.msg ..\bin
move ..\bin\asl.exe ..\bin\asw.exe
del ..\bin\mkdepend.exe
del ..\bin\make.exe
del ..\bin\rescomp.exe

make clean
del *.exe

cd ..

pause
