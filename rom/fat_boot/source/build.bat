
echo off

..\..\..\tools\asl\bin\asl -U -L -x -D DELVAR=0 micro_boot_fat.a80
..\..\..\tools\asl\bin\p2bin micro_boot_fat.p ..\micro_boot_fat.rom -r $-$ -k

..\..\..\tools\mhmt\mhmt -mlz ..\micro_boot_fat.rom ..\micro_boot_fat_pack.rom
