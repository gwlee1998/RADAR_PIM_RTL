// See LICENSE for license details.

#ifndef __FRVP_SPI_FLASH_H__
#define __FRVP_SPI_FLASH_H__

#define SPI_FLASH_INST_RDID		0x9f	// and ox9e
#define SPI_FLASH_INST_READ		0x03
#define SPI_FLASH_INST_FAST_READ	0x0b
#define SPI_FLASH_INST_DOFR		0x3b
#define SPI_FLASH_INST_DIOFR		0xbb
#define SPI_FLASH_INST_QOFR		0x6b
#define SPI_FLASH_INST_QIOFR		0xeb
#define SPI_FLASH_INST_ROTP		0x4b
#define SPI_FLASH_INST_WREN		0x06
#define SPI_FLASH_INST_WRDI		0x04
#define SPI_FLASH_INST_PP		0x02
#define SPI_FLASH_INST_DIFP		0xa2
#define SPI_FLASH_INST_DIEFP		0xd2
#define SPI_FLASH_INST_QIFP		0x32
#define SPI_FLASH_INST_QIEFP		0x12
#define SPI_FLASH_INST_POTP		0x42
#define SPI_FLASH_INST_SSE		0x20
#define SPI_FLASH_INST_SE		0xd8
#define SPI_FLASH_INST_BE		0xc7
#define SPI_FLASH_INST_PER		0x7a
#define SPI_FLASH_INST_PES		0x75
#define SPI_FLASH_INST_RDSR		0x05
#define SPI_FLASH_INST_WRSR		0x01
#define SPI_FLASH_INST_RDLR		0xe8
#define SPI_FLASH_INST_WRLR		0xe5
#define SPI_FLASH_INST_RFSR		0x70
#define SPI_FLASH_INST_CLFSR		0x50
#define SPI_FLASH_INST_RDNVCR		0xb5
#define SPI_FLASH_INST_WRNVCR		0xb1
#define SPI_FLASH_INST_RDVCR		0x85
#define SPI_FLASH_INST_WRVCR		0x81
#define SPI_FLASH_INST_RDVECR		0x65
#define SPI_FLASH_INST_WRVXCR		0x61

/* Legacy SPI Status Register bits */
#define SPI_FLASH_STAUTS_WIP		(1<<0)		/* Write in progress bit */

/* Flag Status Register bits */
#define SPI_FLASH_FLAG_STATUS_ES	(1<<6)		/* Erase Suspend bit */

#define SPI_FLASH_PAGE_SIZE		0x100		// 256 bytes
#define SPI_FLASH_SECTOR_SIZE		0x10000		// 64 Kbytes
#define SPI_FLASH_NUM_PAGES_PER_SECTOR		(SPI_FLASH_SECTOR_SIZE / SPI_FLASH_PAGE_SIZE)

void configure_spi_flash(void);
void read_flash(unsigned int addr, int num_bytes, unsigned char *rdata);
void write_flash_wo_erase(unsigned int addr, int num_bytes, unsigned char *wdata);
void erase_sector(unsigned int addr);
void write_flash(unsigned int addr, int num_bytes, unsigned char *wdata);
void set_flash_mode(void);
void verify_flash_id(void);

static inline unsigned int align_sector_addr(unsigned int addr)
{
	return (addr & (~0xFFFF));
}
//void disable_flash();
//void read_flash(void);
//void command_flash(unsigned char data1, unsigned char data2, unsigned char data3);

#endif
