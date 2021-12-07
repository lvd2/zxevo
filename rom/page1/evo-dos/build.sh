#!/bin/bash

if [ ! -v ASL_PATH ]; then
	ASL_PATH="../../../tools/asl/bin/"
fi

if [ ! -v MHMT_PATH ]; then
	MHMT_PATH="../../../tools/mhmt/"
fi

$ASL_PATH/asl -U -L -x -olist evo-dos_3d13.lst -D EMU3D2F=0,EMU=1 evo-dos.a80
$ASL_PATH/p2bin evo-dos.p ../evo-dos_emu3d13.rom -r '$-$' -k

$ASL_PATH/asl -U -L -x -olist evo-dos_3d2f.lst -D EMU3D2F=1,EMU=1 evo-dos.a80
$ASL_PATH/p2bin evo-dos.p ../evo-dos_virt.rom -r '$-$' -k
