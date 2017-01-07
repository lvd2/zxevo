
@ECHO OFF

cd fat_boot\source

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

copy /B /Y page3\basic48_128.rom+page1\evo-dos_virt.rom+ff_16k.rom+ff_16k.rom+page5\rst8service.rom+page3\basic48_128.rom+page1\evo-dos_emu3d13.rom+page2\basic128.rom+page0\services.rom ers.rom
copy /B /Y page3\2006.rom+trdos_v6\dosatm3.rom+page2\basic128.rom+page0\glukpen.rom glukpent.rom
copy /B /Y atm_cpm\rbios.rom+page3\basic48_128_std.rom+page2\128_std.rom+page3\basic48_orig.rom basics_std.rom

rem          64            64           64                   128          192
copy /B /Y ff_64k.rom+basics_std.rom+glukpent.rom+profrom\evoprofrom.rom+ers.rom zxevo.rom

rem copy /B /Y zxevo.rom ..\tools\unreal_fix\0.37.6\fix_build\x32\zxevo.rom
copy /B /Y zxevo.rom d:\unrealspeccy\zxevo.rom

del ers.rom
del glukpent.rom
del basics_std.rom

pause
