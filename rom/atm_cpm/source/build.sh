#!/bin/bash

if [ ! -v ASL_PATH ]; then
	ASL_PATH="../../../tools/asl/bin/"
fi

if [ ! -v MHMT_PATH ]; then
	MHMT_PATH="../../../tools/mhmt/"
fi

$ASL_PATH/asl -U -L -x -D DELVAR=1 rbios.a80
$ASL_PATH/p2bin rbios.p ../rbios.rom -r '$-$' -k

$MHMT_PATH/mhmt -mlz cpm.img cpm_pack.img
