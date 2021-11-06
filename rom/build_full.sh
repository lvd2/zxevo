#!/bin/bash

echo ####################
echo ## BUILD FAT BOOT ##
echo ####################
cd fat_boot/source
./build.sh

echo #####################
echo ## BUILD MAIN MENU ##
echo #####################
cd ../../mainmenu/src
./build.sh

echo ##################
echo ## BUILD DOS_FE ##
echo ##################
cd ../../page1/dos_fe
./build.sh

echo #######################
echo ## BUILD TR-DOS 5.03 ##
echo #######################
cd ../../page1/trdos503
./build.sh

echo ######################
echo ## BUILD START PAGE ##
echo ######################
cd ../../page0/source
./build.sh

echo ###################
echo ## BUILD EVO-DOS ##
echo ###################
cd ../../page1/evo-dos
./build.sh

echo #####################
echo ## BUILD BASIC 128 ##
echo #####################
cd ../../page2/source
./build.sh

echo ####################
echo ## BUILD BASIC 48 ##
echo ####################
cd ../../page3/source
./build.sh

echo ####################
echo ## BUILD ATM CP/M ##
echo ####################
cd ../../atm_cpm/source
./build.sh

echo ##########################
echo ## BUILD RST 8 SERVICES ##
echo ##########################
cd ../../page5/source
./build.sh

echo #######################
echo ## BUILD TR-DOS 6.10 ##
echo #######################
ccd ../../trdos_v6/source
./build.sh

cd ../..

echo ###############
echo ## BUILD ERS ##
echo ###############
cat page3/basic48_128.rom page1/evo-dos_virt.rom page5/rst8service.rom    ff_16k.rom page3/basic48_128.rom page1/evo-dos_emu3d13.rom page2/basic128.rom page0/services.rom    > ers.rom
cat ff_16k.rom            ff_16k.rom             page5/rst8service_fe.rom ff_16k.rom page3/basic48_128.rom page1/tr5_03.rom          page2/basic128.rom page0/services_fe.rom > ers_fe.rom

echo #####################
echo ## BUILD PENT GLUK ##
echo #####################
cat page3/2006.rom trdos_v6/dosatm3.rom page2/basic128.rom page0/glukpen.rom > glukpent.rom

echo ####################
echo ## BUILD ATM CP/M ##
echo ####################
cat atm_cpm/rbios.rom page3/basic48_128_std.rom page2/128_std.rom page3/basic48_orig.rom > basics_std.rom

echo ########################
echo ## BUILD FULL ERS ROM ##
echo ########################
cat ff_64k.rom basics_std.rom glukpent.rom profrom/evoprofrom.rom ers.rom > zxevo.rom

echo ####################################
echo ## BUILD FULL ERS ROM EMUL FDD FE ##
echo ####################################
#rem    64          64            64                128               192
cat ff_64k.rom basics_std.rom glukpent.rom profrom/evoprofrom.rom ers_fe.rom > zxevo_fe.rom

rm ers.rom
rm ers_fe.rom
rm glukpent.rom
rm basics_std.rom

echo; read -rsn1 -p "Press any key to continue . . .";
