@ECHO OFF

rem �������� ������ ���� � ���������

..\..\..\tools\sjasmplus\sjasmplus --sym=sym.log --lst=dump.log -isrc make_read_fat.a80

..\..\..\tools\mhmt\mhmt -mlz read_fat.rom read_fat_pack.rom

pause