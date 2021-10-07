
@echo off

copy /Y /B makefile.def asl-current

cd asl-current

make

copy /Y /B *.exe ..\bin
copy /Y /B *.msg ..\bin
del ..\bin\mkdepend.exe
del ..\bin\rescomp.exe

make clean
del *.exe

cd ..

pause
