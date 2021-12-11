#ifndef __FLASH_SIMULATOR_H
#define __FLASH_SIMULATOR_H

/* buffer for data to be written/read */
#include "spi_flash.h"
/* the flash chip W25Q80DVSNIG TR stores 8 MB, with 4K sector size */
#define FLASH_SIZE    	0x800000
#define SECTOR_SIZE		0x1000
#define PAGE_SIZE		0x100
#define FLASH_FILE  	"simulated_flash.bin"

#endif