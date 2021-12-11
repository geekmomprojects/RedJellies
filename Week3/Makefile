CC = gcc
cflags = -I.
DEPS = flash_simulator.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
flash_sim.exe: flash_simulator.o main.o
	$(CC) -o flash_sim.exe flash_simulator.o main.o