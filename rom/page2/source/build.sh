#!/bin/bash

if [ ! -v ASL_PATH ]; then
	ASL_PATH="../../../tools/asl/bin/"
fi

if [ ! -v MHMT_PATH ]; then
	MHMT_PATH="../../../tools/mhmt/"
fi

$ASL_PATH/asl -U -L spec128_0.a80
$ASL_PATH/p2bin spec128_0.p ../basic128.rom -r '$-$' -k
