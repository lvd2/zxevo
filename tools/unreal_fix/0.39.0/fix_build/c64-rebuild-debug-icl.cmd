@echo off
call iclvars.bat intel64 vs2017
cd sndrender
nmake clean
nmake all X64=1 SSE2=1 DEBUG=1
cd ..

cd z80
nmake clean
nmake all X64=1 SSE2=1 DEBUG=1
cd ..

nmake clean
nmake all X64=1 SSE2=1 DEBUG=1
