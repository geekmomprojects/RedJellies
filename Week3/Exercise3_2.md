# Exercise 3_2
## SPI Flash Test Code
Unfortunately, the SPI Flash we need to test the Key-Value storage system is on backorder. The KVStore only uses the read, write
and erase functions from the SPI Flash subsystem. Create a small simulator so you can test the KVStore. Write a
test for your simulater that uses the read, write and erase functions.

Here is the SPI Flash information.
[https://www.digikey.com/en/products/detail/winbond-electronics/W25Q80DVSNIG-TR/5154948](https://www.digikey.com/en/products/detail/winbond-electronics/W25Q80DVSNIG-TR/5154948)

We are going to use ST’s Standard Peripheral Flash Driver so here is the header file for the
code you will need to simulate:
[https://drive.google.com/file/d/12dw-pZiKiK1vi4gv49W1x6np5uzCH_cV/view?usp=sharing](https://drive.google.com/file/d/12dw-pZiKiK1vi4gv49W1x6np5uzCH_cV/view?usp=sharing)

Your assignment is to create a small module that compiles and runs on your computer that
implements your flash simulator. You will also need a main file to test out your simulator.
Important notes: You don’t need a full Flash simulator, only what is necessary to test the
KVStore code. You aren’t writing the KVStore code. You do not need to use CPPUTest or other
unit test framework. If you are writing more than 50 lines of code, you are going in the wrong
direction.
Turn in two source files (simulator and main test), and send a link to the
#assignment-submission channel on Discord. Make sure the files are publicly viewable.

## SPI Flash Test Code
I read the datasheet for the flash to determine that the capacity is 8 MB, sector size is 4 KB and page size is 256 bytes. I implemented simulations of the read/write/erase functions declared in spi_flash.h file that create/read/write a disk file to emulate doing the same with flash memory.

I also found it a bit difficult to compile simple C code on my desktop since I didn't have the enviroment set up correctly. In the end, it was easiest to just open an Ubuntu shell on my Windows desktop and create a Makefile to compile and link the code with gcc.

The files in this exercise are:
- *spi_flash.h* - the original header file with function declarations
- *flash_simulator.h* parameters shared by the simulation functions
- *flash_simulator.c* the simulation functions themselves which read/write/erase a disk file to emulate flash
- *main.c* calls the simulation functions to test them
- *Makefile* the usual compilation instructions
