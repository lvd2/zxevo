#!/bin/bash

if [ ! -v ASL_PATH ]; then
	ASL_PATH="../../../tools/asl/bin/"
fi

if [ ! -v MHMT_PATH ]; then
	MHMT_PATH="../../../tools/mhmt/"
fi

$ASL_PATH/asl -U -L -x -olist services.lst services.a80
$ASL_PATH/p2bin services.p ../services.rom -r '$-$' -k

$ASL_PATH/asl -U -L -x -olist services_fe.lst -D DOS_FE services.a80
$ASL_PATH/p2bin services.p ../services_fe.rom -r '$-$' -k
