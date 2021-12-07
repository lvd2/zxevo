#!/bin/bash

if [ ! -v ASL_PATH ]; then
	ASL_PATH="../../../tools/asl/bin/"
fi

if [ ! -v MHMT_PATH ]; then
	MHMT_PATH="../../../tools/mhmt/"
fi

$ASL_PATH/asl -U -L -D DELVAR=1 trdos_v6.a80
$ASL_PATH/p2bin trdos_v6.p ../dosatm3.rom -r '$-$' -k
