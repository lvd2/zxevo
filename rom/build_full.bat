
echo off

echo ####################
echo ## BUILD FAT BOOT ##
echo ####################
cd fat_boot\source
call build.bat

echo #####################
echo ## BUILD MAIN MENU ##
echo #####################
cd ..\..\mainmenu\src
call build.bat

echo ##################
echo ## BUILD DOS_FE ##
echo ##################
cd ..\..\page1\dos_fe
call build.bat

echo #######################
echo ## BUILD TR-DOS 5.03 ##
echo #######################
cd ..\..\page1\trdos503
call build.bat

echo ######################
echo ## BUILD START PAGE ##
echo ######################
cd ..\..\page0\source
call build.bat

echo ###################
echo ## BUILD EVO-DOS ##
echo ###################
cd ..\..\page1\evo-dos
call build.bat

echo #####################
echo ## BUILD BASIC 128 ##
echo #####################
cd ..\..\page2\source
call build.bat

echo ####################
echo ## BUILD BASIC 48 ##
echo ####################
cd ..\..\page3\source
call build.bat

echo ####################
echo ## BUILD ATM CP/M ##
echo ####################
cd ..\..\atm_cpm\source
call build.bat

echo ##########################
echo ## BUILD RST 8 SERVICES ##
echo ##########################
cd ..\..\page5\source
call build.bat

echo #######################
echo ## BUILD TR-DOS 6.10 ##
echo #######################
cd ..\..\trdos_v6\source
call build.bat

cd ..\..

echo ###############
echo ## BUILD ERS ##
echo ###############
copy /b /y page3\basic48_128.rom + page1\evo-dos_virt.rom + page5\rst8service.rom    + ff_16k.rom + page3\basic48_128.rom + page1\evo-dos_emu3d13.rom + page2\basic128.rom + page0\services.rom    ers.rom
copy /b /y ff_16k.rom            + ff_16k.rom             + page5\rst8service_fe.rom + ff_16k.rom + page3\basic48_128.rom + page1\tr5_03.rom        + page2\basic128.rom + page0\services_fe.rom ers_fe.rom

echo #####################
echo ## BUILD PENT GLUK ##
echo #####################
copy /b /y page3\2006.rom+trdos_v6\dosatm3.rom+page2\basic128.rom+page0\glukpen.rom glukpent.rom

echo ####################
echo ## BUILD ATM CP/M ##
echo ####################
copy /b /y atm_cpm\rbios.rom+page3\basic48_128_std.rom+page2\128_std.rom+page3\basic48_orig.rom basics_std.rom

echo ########################
echo ## BUILD FULL ERS ROM ##
echo ########################
copy /b /y ff_64k.rom + basics_std.rom + glukpent.rom + profrom\evoprofrom.rom + ers.rom zxevo.rom

echo ####################################
echo ## BUILD FULL ERS ROM EMUL FDD FE ##
echo ####################################
rem          64             64              64                   128               192
copy /b /y ff_64k.rom + basics_std.rom + glukpent.rom + profrom\evoprofrom.rom + ers_fe.rom zxevo_fe.rom

echo #################################
echo ## COPY ROM'S FOR UNRESLSPECCY ##
echo #################################
copy /B /Y zxevo.rom d:\yad\unrealspeccy\zxevo.rom
copy /B /Y zxevo_fe.rom d:\yad\unrealspeccy\zxevo_fe.rom

del ers.rom
del ers_fe.rom
del glukpent.rom
del basics_std.rom

pause
