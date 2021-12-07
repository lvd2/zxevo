#!/bin/bash

if [ ! -v ASL_PATH ]; then
	ASL_PATH="../../../tools/asl/bin/"
fi

if [ ! -v MHMT_PATH ]; then
	MHMT_PATH="../../../tools/mhmt/"
fi

#../../../tools/asl/bin/asl -U -L -x -D DELVAR=0 micro_boot_fat.a80
#../../../tools/asl/bin/p2bin micro_boot_fat.p ../micro_boot_fat.rom -r '$-$' -k
$ASL_PATH/asl -U -L -x -D DELVAR=0 micro_boot_fat.a80
$ASL_PATH/p2bin micro_boot_fat.p ../micro_boot_fat.rom -r '$-$' -k

#../../../tools/mhmt/mhmt -mlz ../micro_boot_fat.rom ../micro_boot_fat_pack.rom
$MHMT_PATH/mhmt -mlz ../micro_boot_fat.rom ../micro_boot_fat_pack.rom

