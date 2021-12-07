#!/bin/bash

if [ ! -v ASL_PATH ]; then
	ASL_PATH="../../../tools/asl/bin/"
fi

if [ ! -v MHMT_PATH ]; then
	MHMT_PATH="../../../tools/mhmt/"
fi

#cd ../../fat_boot/source
#./build.sh
#cd ../../page5/source

$MHMT_PATH/mhmt -mlz 8x8_ar.fnt 8x8_ar_pack.bin
$MHMT_PATH/mhmt -mlz 866_code.fnt 866_code_pack.bin
$MHMT_PATH/mhmt -mlz atm_code.fnt atm_code_pack.bin
$MHMT_PATH/mhmt -mlz perfpack.bin perfpack_pack.bin

$ASL_PATH/asl -U -L -x -olist rst8service.lst -D DELVAR=0 rst8service.a80
$ASL_PATH/p2bin rst8service.p ../rst8service.rom -r '$-$' -k

$ASL_PATH/asl -U -L -x -olist rst8service_fe.lst -D DOS_FE,DELVAR=0 rst8service.a80
$ASL_PATH/p2bin rst8service.p ../rst8service_fe.rom -r '$-$' -k
