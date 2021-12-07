#!/bin/bash

if [ ! -v ASL_PATH ]; then
	ASL_PATH="../../../tools/asl/bin/"
fi

if [ ! -v MHMT_PATH ]; then
	MHMT_PATH="../../../tools/mhmt/"
fi

$ASL_PATH/asl -U -L -D DELVAR=1 basic48.a80
$ASL_PATH/p2bin basic48.p ../basic48_128.rom -r '$-$' -k
 
