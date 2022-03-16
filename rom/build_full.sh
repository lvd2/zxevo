#!/bin/bash

set -x

#if ASL and MHMT paths are already set, convert them to absolute right now
if [ -v ASL_PATH ]; then
	ASL_PATH="$(cd $ASL_PATH; pwd)"
fi

if [ -v MHMT_PATH ]; then
	MHMT_PATH="$(cd $MHMT_PATH; pwd)"
fi


# cd to the dir where the script is situated
cd ${0%/*}


# set ASL and MHMT paths if not already set, also converting them to absolute
if [ ! -v ASL_PATH ]; then
	ASL_PATH="../tools/asl/bin/"
	ASL_PATH="$(cd $ASL_PATH; pwd)"
fi

if [ ! -v MHMT_PATH ]; then
	MHMT_PATH="../tools/mhmt/"
	MHMT_PATH="$(cd $MHMT_PATH; pwd)"
fi



# BUILD FAT BOOT
pushd fat_boot/source
source build.sh
popd

# BUILD MAIN MENU
pushd mainmenu/src
source build.sh
popd

# BUILD DOS_FE
pushd page1/dos_fe
source build.sh
popd

# BUILD START PAGE
pushd page0/source
source build.sh
popd

# BUILD NEO-DOS
pushd page1/neo-dos
source build.sh
popd

# BUILD BASIC 128
pushd page2/source
source build.sh
popd

# BUILD BASIC 48
pushd page3/source
source build.sh
popd

# BUILD ATM CP/M
pushd atm_cpm/source
source build.sh
popd

# BUILD RST 8 SERVICES
pushd page5/source
source build.sh
popd

# BUILD TR-DOS 6.10 
pushd trdos_v6/source
source build.sh
popd


# BUILD ERS
cat ff_16k.rom ff_16k.rom page5/rst8service_fe.rom ff_16k.rom page3/basic48_128.rom page1/tr5_03.rom page2/basic128.rom page0/services_fe.rom > ers_fe.rom

# BUILD PENT GLUK 
cat page3/2006.rom trdos_v6/dosatm3.rom page2/basic128.rom page0/glukpen.rom > glukpent.rom

# BUILD ATM CP/M 
cat atm_cpm/rbios.rom page3/basic48_128_std.rom page2/128_std.rom page3/basic48_orig.rom > basics_std.rom

# BUILD FULL ERS ROM EMUL FDD FE
#rem    64          64            64                128               192
cat ff_64k.rom basics_std.rom glukpent.rom profrom/evoprofrom.rom ers_fe.rom > zxevo_fe.rom

# rm ers.rom
rm ers_fe.rom
rm glukpent.rom
rm basics_std.rom

#read -rsn1 -p "Press any key to continue . . .";
