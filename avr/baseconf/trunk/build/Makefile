###############################################################################
# Makefile for the project pentevo
###############################################################################

# tools (optionally with path)
AVRCC ?= avr-gcc
AVRSIZE ?= avr-size
AVROBJDUMP ?= avr-objdump
AVROBJCOPY ?= avr-objcopy


# project naming 
PROJECT = core
FPGACORE = top
RELEASE = zxevo

## Options common to compile, link and assembly rules
MCU = atmega128

COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -Wextra -gdwarf-2 -std=gnu99 -Os -DF_CPU=11059200UL -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=$(PROJECT).map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Objects that must be built in order to link
TARGETS = zx   interrupts   main   ps2   spi   depacker_dirty   rs232   rtc   atx   joystick   version   tape   kbmap





## Build
all: $(PROJECT).elf $(PROJECT).hex $(PROJECT).eep $(PROJECT).lss $(RELEASE).bin   size
	cp $(RELEASE).bin zxevo_fw.bin

#release: $(PROJECT).elf core.hex core.eep core.lss size zxevo_release.bin
#	mv zxevo_release.bin zxevo_fw.bin

## Compile
zx.o: ../src/zx.c ../src/zx.h
	$(AVRCC) $(CFLAGS) -c  $<

interrupts.o: ../src/interrupts.c
	$(AVRCC) $(CFLAGS) -c  $<

main.o: ../src/main.c
	$(AVRCC) $(CFLAGS) -c  $<

ps2.o: ../src/ps2.c ../src/ps2.h
	$(AVRCC) $(CFLAGS) -c  $<

spi.o: ../src/spi.c ../src/spi.h
	$(AVRCC) $(CFLAGS) -c  $<

depacker_dirty.o: ../src/depacker_dirty.c ../src/depacker_dirty.h
	$(AVRCC) $(CFLAGS) -c  $<

rs232.o: ../src/rs232.c ../src/rs232.h
	$(AVRCC) $(CFLAGS) -c  $<

rtc.o: ../src/rtc.c ../src/rtc.h
	$(AVRCC) $(CFLAGS) -c  $<

atx.o: ../src/atx.c ../src/atx.h
	$(AVRCC) $(CFLAGS) -c  $<

joystick.o: ../src/joystick.c ../src/joystick.h
	$(AVRCC) $(CFLAGS) -c  $<

version.o: ../src/version.c ../src/version.h
	$(AVRCC) $(CFLAGS) -c  $<

tape.o: ../src/tape.c ../src/tape.h
	$(AVRCC) $(CFLAGS) -c  $<

kbmap.o: ../src/kbmap.c ../src/kbmap.h
	$(AVRCC) $(CFLAGS) -c  $<

##Link
$(PROJECT).elf: $(TARGETS:%=%.o) $(FPGACORE).o
	 $(AVRCC) $(LDFLAGS) $(TARGETS:%=%.o) $(FPGACORE).o -o $(PROJECT).elf

$(FPGACORE).o: $(FPGACORE).mlz
	$(AVROBJCOPY) -I binary -O elf32-avr -B avr:51 --rename-section .data=.progmem.data,contents,alloc,load,readonly,data --redefine-sym _binary_top_mlz_start=fpga --redefine-sym _binary_top_mlz_end=fpga_end $(FPGACORE).mlz $(FPGACORE).o

%.hex: $(PROJECT).elf
	$(AVROBJCOPY) -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(PROJECT).elf
	$(AVROBJCOPY) $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(PROJECT).elf
	$(AVROBJDUMP) -h -S $< > $@

size: $(PROJECT).elf
	@echo .
	@$(AVRSIZE) -C --mcu=${MCU} $(PROJECT).elf

#zxevo_beta.bin: core.hex core.eep
#	../../../tools/make_fw/make_fw core.hex core.eep zxevo_beta.bin version.txt

$(RELEASE).bin: core.hex core.eep
	../../../../../tools/make_fw/make_fw $(PROJECT).hex $(PROJECT).eep $(RELEASE).bin version.txt o

## Clean target
.PHONY: clean
clean:
	-rm -rf $(TARGETS:%=%.o) $(FPGACORE).o $(PROJECT).* dep $(RELEASE).bin zxevo_fw.bin

## program chip
pgm: $(PROJECT).hex
	echo no pgm supported!



## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)
