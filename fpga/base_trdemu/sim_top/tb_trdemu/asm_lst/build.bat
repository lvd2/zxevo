
@ECHO OFF

..\..\svn\pentevo\tools\asw\bin\asw -U -L -x -olist services.lst services.a80
..\..\svn\pentevo\tools\asw\bin\p2bin services.p services.bin -r $-$ -k

..\..\svn\pentevo\tools\asw\bin\asw -U -L -x -olist dos_fe.lst dos_fe.a80
..\..\svn\pentevo\tools\asw\bin\p2bin dos_fe.p dos_fe.bin -r $-$ -k

..\..\svn\pentevo\tools\asw\bin\asw -U -L -x -olist trdos.lst trdos.a80
..\..\svn\pentevo\tools\asw\bin\p2bin trdos.p trdos.bin -r $-$ -k

copy /B /Y ff_64k.rom + ff_64k.rom + ff_64k.rom + ff_64k.rom + ff_64k.rom + ff_64k.rom + ff_64k.rom 7page.bin

copy /B /Y 7page.bin + dos_fe.bin + trdos.bin + ff_16k.rom + services.bin ers_test.rom
copy /B /Y ers_test.rom d:\yad\unrealspeccy\zxevo.rom

del *.bin
rem del *.lst
