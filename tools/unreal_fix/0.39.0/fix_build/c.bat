@echo off
call iclvars.bat ia32 vs2015
cd sndrender
nmake clean
nmake all RELEASE=1 SSE2=1 USE_CL=1
cd ..

cd z80
nmake clean
nmake all RELEASE=1 SSE2=1 USE_CL=1
cd ..

nmake clean
nmake all RELEASE=1 SSE2=1 USE_CL=1
