
echo off

..\..\..\tools\asw\bin\asw -U -L -x -olist evo-dos_3d13.lst -D EMU3D2F=0,EMU=1 evo-dos.a80
..\..\..\tools\asw\bin\p2bin evo-dos.p ..\evo-dos_emu3d13.rom -r $-$ -k

..\..\..\tools\asw\bin\asw -U -L -x -olist evo-dos_3d2f.lst -D EMU3D2F=1,EMU=1 evo-dos.a80
..\..\..\tools\asw\bin\p2bin evo-dos.p ..\evo-dos_virt.rom -r $-$ -k
