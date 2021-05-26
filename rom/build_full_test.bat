
echo off

ECHO **************
ECHO BUILD FAT BOOT
ECHO **************
cd fat_boot\source
call build.bat

ECHO ***************
ECHO BUILD MAIN MENU
ECHO ***************
cd ..\..\mainmenu\src
call build_test

ECHO ************
ECHO BUILD DOS_FE
ECHO ************
cd ..\..\page1\dos_fe
call build.bat

ECHO *****************
ECHO BUILD TR-DOS 5.03
ECHO *****************
cd ..\..\page1\trdos503
call build.bat

ECHO ****************
ECHO BUILD START PAGE
ECHO ****************
cd ..\..\page0\source
call build.bat

ECHO *************
ECHO BUILD EVO-DOS
ECHO *************
cd ..\..\page1\evo-dos
call build.bat

ECHO ***************
ECHO BUILD BASIC 128
ECHO ***************
cd ..\..\page2\source
call build.bat

ECHO **************
ECHO BUILD BASIC 48
ECHO **************
cd ..\..\page3\source
call build.bat

ECHO **************
ECHO BUILD ATM CP/M
ECHO **************
cd ..\..\atm_cpm\source
call build.bat

ECHO ********************
ECHO BUILD RST 8 SERVICES
ECHO ********************
cd ..\..\page5\source
call build_test.bat

ECHO *****************
ECHO BUILD TR-DOS 6.10
ECHO *****************
cd ..\..\trdos_v6\source
call build.bat

cd ..\..

ECHO *********
ECHO BUILD ERS
ECHO *********
copy /B /Y page3\basic48_128.rom + page1\evo-dos_virt.rom + page5\rst8service.rom    + ff_16k.rom + page3\basic48_128.rom + page1\evo-dos_emu3d13.rom + page2\basic128.rom + page0\services.rom    ers.rom
copy /B /Y ff_16k.rom            + ff_16k.rom             + page5\rst8service_fe.rom + ff_16k.rom + page3\basic48_128.rom + page1\trdos503.rom        + page2\basic128.rom + page0\services_fe.rom ers_fe.rom

ECHO ***************
ECHO BUILD PENT GLUK
ECHO ***************
copy /B /Y page3\2006.rom+trdos_v6\dosatm3.rom+page2\basic128.rom+page0\glukpen.rom glukpent.rom

ECHO **************
ECHO BUILD ATM CP/M
ECHO **************
copy /B /Y atm_cpm\rbios.rom+page3\basic48_128_std.rom+page2\128_std.rom+page3\basic48_orig.rom basics_std.rom

ECHO ******************
ECHO BUILD FULL ERS ROM
ECHO ******************
copy /B /Y ff_64k.rom + basics_std.rom + glukpent.rom + profrom\evoprofrom.rom + ers.rom zxevo.rom

ECHO ******************************
ECHO BUILD FULL ERS ROM EMUL FDD FE
ECHO ******************************
rem          64             64              64                   128               192
copy /B /Y ff_64k.rom + basics_std.rom + glukpent.rom + profrom\evoprofrom.rom + ers_fe.rom zxevo_fe.rom

ECHO *************************
ECHO COPY ROM'S FOR UNRESLSPECCY
ECHO *************************
copy /B /Y zxevo.rom d:\yad\unrealspeccy\zxevo.rom
copy /B /Y zxevo_fe.rom d:\yad\unrealspeccy\zxevo_fe.rom

del ers.rom
del ers_fe.rom
del glukpent.rom
del basics_std.rom

pause
