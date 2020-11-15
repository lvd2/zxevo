#!/bin/bash

#make sure it runs from correct place -- 'cd' to the dir where this script is situated
cd ${0%/*}

# some variables
FPGA_PATH=fpga/quartus
FPGA_FILE=top.rbf

AVR_PATH=avr/build
AVR_FILE=top.mlz

RESULT=zxevo_fw.bin

MHMT_BIN=../../../tools/mhmt/mhmt


# build FPGA
cd $FPGA_PATH && make
cd -

# check whether top.rbf exists
if [ ! -f "$FPGA_PATH/$FPGA_FILE" ]; then
	echo Error: $FPGA_FILE was not built!
	exit 1
fi

# pack and copy fpga file to avr dir
$MHMT_BIN -maxwin2048 $FPGA_PATH/$FPGA_FILE $AVR_PATH/$AVR_FILE || { echo 'mhmt failed!' ; exit 1; }

# go build avr firmware
cd $AVR_PATH && make
cd -

# check whether there is end file
if [ ! -f "$AVR_PATH/$RESULT" ]; then
	echo Error: $RESULT was not build!
	exit 1
fi

cp $AVR_PATH/$RESULT ./

echo Done!

