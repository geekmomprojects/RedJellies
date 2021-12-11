#include <stdio.h>
#include <stdlib.h>
#include "flash_simulator.h"

/* Use Init function to create or verify the existence of 
 * the local disk file which we'll use to store/retrieve data
 */
 
#define WRITE_CHUNK_SIZE	0x100000  // Writing 1 MB at a time

void sFLASH_Init(void) {
	//Create 1MB array of zeroes for writing to file
	uint8_t zero_arr[WRITE_CHUNK_SIZE] = {0};
    //Create the disk file we'll use. This will overwrite anything
	// already there
    FILE *fptr = fopen(FLASH_FILE, "wb");
    //Fill or overwrite with zeros
	if (fptr == NULL) {
		printf("Open file error!\n");
		exit(1);
	}

	// Fill buffer with zeroes
	int bytes_written = 0;
	for (int i = 0; i < FLASH_SIZE/sizeof(zero_arr); i++) {
		int nwritten = fwrite(zero_arr, sizeof(uint8_t), WRITE_CHUNK_SIZE, fptr);
		bytes_written += nwritten;
		if (nwritten != WRITE_CHUNK_SIZE) {
			printf("Write error at byte %d\n", bytes_written);
			break;
		}
	}

	fclose(fptr);
}

/* Erase just one sector of flash. Should find out how large a sector really is */
void sFLASH_EraseSector(uint32_t SectorAddr) {
	uint8_t zero_arr[SECTOR_SIZE] = {0};
	sFLASH_WritePage(zero_arr, SectorAddr, SECTOR_SIZE);

}

/* Erase Bulk is the same as initializing in the simulation */
void sFLASH_EraseBulk(void) { sFLASH_Init(); }


void sFLASH_WritePage(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite) {	
	FILE *fptr = fopen(FLASH_FILE, "r+b");
	if (fptr == NULL) {
		printf("Open file error!\n");
		exit(1);
	}
	/* fseek returns zero if successful */
	if (fseek(fptr, WriteAddr, SEEK_SET)) {
		printf("Error finding file address %d\n", WriteAddr);
		exit(1);
	}
	if (fwrite(pBuffer, sizeof(uint8_t), NumByteToWrite, fptr) != NumByteToWrite) {
		printf("Error overwriting file sector %d", WriteAddr);
	}
}
void sFLASH_WriteBuffer(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite){
	sFLASH_WritePage(pBuffer, WriteAddr, NumByteToWrite);
}
void sFLASH_ReadBuffer(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead){
	FILE *fptr = fopen(FLASH_FILE, "rb");
	if (fptr == NULL) {
		printf("Open file error!\n");
		exit(1);
	}
	/* fseek returns zero if successful */
	if (fseek(fptr, ReadAddr, SEEK_SET)) {
		printf("Error finding file address %d\n", ReadAddr);
		exit(1);
	}
	if (fread(pBuffer, sizeof(uint8_t), NumByteToRead, fptr) != NumByteToRead) {
		printf("Error reading data from address %d\n", ReadAddr);	
	}
}
uint32_t sFLASH_ReadID(void){ return 1;}
void sFLASH_StartReadSequence(uint32_t ReadAddr){}

