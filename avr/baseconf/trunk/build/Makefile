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
#CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d

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


TARGETS = zx interrupts main ps2 spi depacker_dirty rs232 rtc atx joystick version tape kbmap




# Build dependencies

.PHONY: all

all: $(PROJECT).elf $(PROJECT).hex $(PROJECT).eep $(PROJECT).lss $(RELEASE).bin   size
	cp $(RELEASE).bin zxevo_fw.bin

# must not be before .PHONY and all targets
include $(TARGETS:%=%.d)

# dependencies generation
%.d: ../src/%.c Makefile
	$(AVRCC) -MM $(CFLAGS) $< | sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' > $@

# Compile
%.o: ../src/%.c Makefile
	$(AVRCC) $(CFLAGS) -c -o $@ $<


# Link
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
	-rm -rf $(TARGETS:%=%.o) $(TARGETS:%=%.d) $(FPGACORE).o $(PROJECT).* dep $(RELEASE).bin zxevo_fw.bin

## program chip
pgm: $(PROJECT).hex
	echo no pgm supported!


