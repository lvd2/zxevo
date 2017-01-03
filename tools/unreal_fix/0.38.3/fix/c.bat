@echo off
rem call "C:\Program Files (x86)\Microsoft Visual Studio 9.0\VC\vcvarsall.bat"
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
