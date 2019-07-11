
@ECHO OFF

cd fat_boot\source
call make.bat
del *.lst

cd ..\..\mainmenu\src
call make.bat
del *.lst

cd ..\..\page1\dos_fe
call make.bat
del *.lst

cd ..\..\page1\trdos503
call make.bat
del *.lst

cd ..\..\page0\source
call make.bat
del *.lst

cd ..\..\page1\evo-dos
call make.bat
del *.lst

cd ..\..\page2\source
call make.bat
del *.lst

cd ..\..\page3\source
call make.bat
del *.lst

cd ..\..\atm_cpm\source
call make.bat
del *.lst

cd ..\..\page5\source
call make.bat
del *.lst

cd ..\..\trdos_v6\source
call make.bat
del *.lst

cd ..\..

copy /B /Y page3\basic48_128.rom + page1\evo-dos_virt.rom + page5\rst8service.rom    + ff_16k.rom + page3\basic48_128.rom + page1\evo-dos_emu3d13.rom + page2\basic128.rom + page0\services.rom    ers.rom
copy /B /Y ff_16k.rom            + ff_16k.rom             + page5\rst8service_fe.rom + ff_16k.rom + page3\basic48_128.rom + page1\trdos503.rom        + page2\basic128.rom + page0\services_fe.rom ers_fe.rom

copy /B /Y page3\2006.rom+trdos_v6\dosatm3.rom+page2\basic128.rom+page0\glukpen.rom glukpent.rom
copy /B /Y atm_cpm\rbios.rom+page3\basic48_128_std.rom+page2\128_std.rom+page3\basic48_orig.rom basics_std.rom

copy /B /Y ff_64k.rom + basics_std.rom + glukpent.rom + profrom\evoprofrom.rom + ers.rom zxevo.rom
rem          64             64              64                   128               192
copy /B /Y ff_64k.rom + basics_std.rom + glukpent.rom + profrom\evoprofrom.rom + ers_fe.rom zxevo_fe.rom

rem for nedoos
rem copy /B /Y zxevo.rom d:\yad\unrealspeccy\zxevo.rom
rem copy /B /Y zxevo_fe.rom d:\yad\unrealspeccy\zxevo_fe.rom
rem copy /B /Y zxevo.rom d:\yad\svn\nedoos\nedoos\us\zxevo.rom
rem copy /B /Y zxevo.rom d:\_os\us\zxevo.rom

del ers.rom
del ers_fe.rom
del glukpent.rom
del basics_std.rom

pause
