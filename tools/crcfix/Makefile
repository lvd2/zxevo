CC = gcc

#CFLAGS = -O0 -Wall -Wno-maybe-uninitialized  -ggdb -g
CFLAGS = -Os -Wall -Wno-maybe-uninitialized -ggdb -g


TGT = crcfix


all: $(TGT)

$(TGT): main.o ihex.o crc.o Makefile
	$(CC) $(CFLAGS) $(filter-out $(lastword $^),$^) -o $@

main.o: src/main.c src/ihex.h src/crc.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

ihex.o: src/ihex.c src/ihex.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

crc.o: src/crc.c src/crc.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@



clean:
	rm *.o *.exe $(TGT)

