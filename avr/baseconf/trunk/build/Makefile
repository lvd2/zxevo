###############################################################################
# Makefile for the project pentevo
###############################################################################

## General Flags
PROJECT = core
MCU = atmega128
TARGET = $(PROJECT).elf
AVRCC ?= avr-gcc
SIZE ?= avr-size
OBJDUMP ?= avr-objdump
OBJCOPY ?= avr-objcopy

RELEASE = zxevo

## Options common to compile, link and assembly rules
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
OBJECTS = zx.o interrupts.o main.o ps2.o spi.o depacker_dirty.o rs232.o rtc.o atx.o joystick.o version.o tape.o kbmap.o

## Objects explicitly added by the user
#LINKONLYOBJECTS = fpga.o
FPGACORE = top

## Build
all: $(TARGET) $(PROJECT).hex $(PROJECT).eep $(PROJECT).lss size $(RELEASE).bin
	mv $(RELEASE).bin zxevo_fw.bin

release: $(TARGET) core.hex core.eep core.lss size zxevo_release.bin
	mv zxevo_release.bin zxevo_fw.bin

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
$(TARGET): $(OBJECTS) $(FPGACORE).o
	 $(AVRCC) $(LDFLAGS) $(OBJECTS) $(FPGACORE).o -o $(TARGET)

$(FPGACORE).o: $(FPGACORE).mlz
	$(OBJCOPY) -I binary -O elf32-avr -B avr:51 --rename-section .data=.progmem.data,contents,alloc,load,readonly,data --redefine-sym _binary_top_mlz_start=fpga --redefine-sym _binary_top_mlz_end=fpga_end $(FPGACORE).mlz $(FPGACORE).o

%.hex: $(TARGET)
	$(OBJCOPY) -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	$(OBJCOPY) $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	$(OBJDUMP) -h -S $< > $@

size: ${TARGET}
	@echo .
	@$(SIZE) -C --mcu=${MCU} ${TARGET}

#zxevo_beta.bin: core.hex core.eep
#	../../../tools/make_fw/make_fw core.hex core.eep zxevo_beta.bin version.txt

$(RELEASE).bin: core.hex core.eep
	../../../../../tools/make_fw/make_fw $(PROJECT).hex $(PROJECT).eep $(RELEASE).bin version.txt o

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) $(FPGACORE).o $(PROJECT).* dep $(RELEASE).bin zxevo_fw.bin

## program chip
pgm: $(PROJECT).hex
	echo no pgm supported!



## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)
