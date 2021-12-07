#!/bin/bash

if [ ! -v ASL_PATH ]; then
	ASL_PATH="../../../tools/asl/bin/"
fi

if [ ! -v MHMT_PATH ]; then
	MHMT_PATH="../../../tools/mhmt/"
fi

$ASL_PATH/asl -U -L -x -olist main.lst main.a80
$ASL_PATH/p2bin main.p main.rom -r '$-$' -k

$ASL_PATH/asl -U -L -x -olist main_fe.lst -D DOS_FE main.a80
$ASL_PATH/p2bin main.p main_fe.rom -r '$-$' -k

$ASL_PATH/asl -U -L cmosset.a80
$ASL_PATH/p2bin cmosset.p cmosset.rom -r '$-$' -k

$MHMT_PATH/mhmt -mlz main.rom ../main_pack.rom
$MHMT_PATH/mhmt -mlz main_fe.rom ../main_fe_pack.rom
$MHMT_PATH/mhmt -mlz cmosset.rom ../cmosset_pack.rom
$MHMT_PATH/mhmt -mlz chars_eng.bin ../chars_pack.rom

