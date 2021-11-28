#!/bin/bash

# BUILD FAT BOOT
cd fat_boot/source
./build.sh

# BUILD MAIN MENU
cd ../../mainmenu/src
./build.sh

# BUILD DOS_FE
cd ../../page1/dos_fe
./build.sh

# BUILD TR-DOS 5.03
cd ../../page1/trdos503
./build.sh

# BUILD START PAGE
cd ../../page0/source
./build.sh

# BUILD EVO-DOS
cd ../../page1/evo-dos
./build.sh

# BUILD BASIC 128
cd ../../page2/source
./build.sh

# BUILD BASIC 48
cd ../../page3/source
./build.sh

# BUILD ATM CP/M
cd ../../atm_cpm/source
./build.sh

# BUILD RST 8 SERVICES
cd ../../page5/source
./build.sh

# BUILD TR-DOS 6.10 
cd ../../trdos_v6/source
./build.sh

cd ../..

# BUILD ERS 
cat page3/basic48_128.rom page1/evo-dos_virt.rom page5/rst8service.rom    ff_16k.rom page3/basic48_128.rom page1/evo-dos_emu3d13.rom page2/basic128.rom page0/services.rom    > ers.rom
cat ff_16k.rom            ff_16k.rom             page5/rst8service_fe.rom ff_16k.rom page3/basic48_128.rom page1/tr5_03.rom          page2/basic128.rom page0/services_fe.rom > ers_fe.rom

# BUILD PENT GLUK 
cat page3/2006.rom trdos_v6/dosatm3.rom page2/basic128.rom page0/glukpen.rom > glukpent.rom

# BUILD ATM CP/M 
cat atm_cpm/rbios.rom page3/basic48_128_std.rom page2/128_std.rom page3/basic48_orig.rom > basics_std.rom

# BUILD FULL ERS ROM
cat ff_64k.rom basics_std.rom glukpent.rom profrom/evoprofrom.rom ers.rom > zxevo.rom

# BUILD FULL ERS ROM EMUL FDD FE
#rem    64          64            64                128               192
cat ff_64k.rom basics_std.rom glukpent.rom profrom/evoprofrom.rom ers_fe.rom > zxevo_fe.rom

rm ers.rom
rm ers_fe.rom
rm glukpent.rom
rm basics_std.rom

read -rsn1 -p "Press any key to continue . . .";
