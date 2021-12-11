#include <stdio.h>
#include "flash_simulator.h"

int main() {
    printf("Initializing Flash\n");
	sFLASH_Init();
	printf("Done initializing Flash\n");
	
	char *test_text = "The quick brown fox jumped over the lazy dog";
	uint32_t addr = 0;
	sFLASH_WritePage(test_text, addr, sizeof(test_text));
	
	char buf[SECTOR_SIZE];
	sFLASH_ReadBuffer(buf, addr, sizeof(test_text));
	printf("Read string %s", test_text); 
	
}