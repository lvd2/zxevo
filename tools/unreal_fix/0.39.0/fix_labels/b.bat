@echo off

cd sndrender
nmake -f Makefile.gcc clean
nmake -f Makefile.gcc all
cd ..

cd z80
nmake -f Makefile.gcc clean
nmake -f Makefile.gcc all
cd ..

nmake -f Makefile.gcc clean
nmake -f Makefile.gcc all
