#!/bin/bash

if [ ! -v ASL_PATH ]; then
	ASL_PATH="../../../tools/asl/bin/"
fi

if [ ! -v MHMT_PATH ]; then
	MHMT_PATH="../../../tools/mhmt/"
fi

$ASL_PATH/asl -U -L -x -olist neo-dos.lst -D EMU=1 neo-dos.a80
$ASL_PATH/p2bin neo-dos.p ../neo-dos.rom -r '$-$' -k

$MHMT_PATH/mhmt -mlz dos_fe.rom ..\dos_fe_pack.rom
