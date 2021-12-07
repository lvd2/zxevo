#!/bin/bash

if [ ! -v ASL_PATH ]; then
	ASL_PATH="../../../tools/asl/bin/"
fi

if [ ! -v MHMT_PATH ]; then
	MHMT_PATH="../../../tools/mhmt/"
fi

$ASL_PATH/asl -L trdos503.a80
$ASL_PATH/p2bin trdos503.p ../trdos503.rom -r '$-$' -k
