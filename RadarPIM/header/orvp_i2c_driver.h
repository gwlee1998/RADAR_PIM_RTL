#ifndef __ORVP_I2C_DRIVER_H__
#define __ORVP_I2C_DRIVER_H__

#include "ervp_external_peri_group_memorymap.h"

static inline unsigned int get_base_addr(int i2c_index)
{
	const unsigned int addr_diff = SUBMODULE_ADDR_ERVP_EXTERNAL_PERI_GROUP_I2C1 - SUBMODULE_ADDR_ERVP_EXTERNAL_PERI_GROUP_I2C0;
	return (EXTERNAL_PERI_GROUP_BASEADDR + SUBMODULE_ADDR_ERVP_EXTERNAL_PERI_GROUP_I2C0) + i2c_index*addr_diff;
}

void start_i2c_transmisstion(int i2c_index, unsigned char module_address);
void write_a_byte_on_i2c(int i2c_index, unsigned char data);
void finish_writing_a_byte_on_i2c(int i2c_index, unsigned char data);
void start_i2c_reading(int i2c_index, unsigned char module_address);
unsigned char read_a_byte_on_i2c(int i2c_index);
unsigned char finish_reading_a_byte_on_i2c(int i2c_index);
void check_i2c_write(int i2c_index);
void wait_i2c_processing(int i2c_index);

#endif
