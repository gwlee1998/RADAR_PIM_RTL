#ifndef __ERVP_MMIO_UTIL_H__
#define __ERVP_MMIO_UTIL_H__

#include <stdint.h>
#include "ervp_reg_util.h"
#include "core_dependent.h"

static inline uint32_t convert_endian(uint32_t data)
{
	uint32_t converted_data;
	converted_data = (data&0xFF);
	converted_data = (converted_data<<8) + ((data>>8)&0xFF);
	converted_data = (converted_data<<8) + ((data>>16)&0xFF);
	converted_data = (converted_data<<8) + ((data>>24)&0xFF);
	return converted_data;
}

static inline uint32_t mmio_read_data(unsigned int addr)
{
	uint32_t data = REG32(addr);
	uint32_t converted_data;
	if(BIG_ENDIAN_ACCESS==1)
		converted_data = convert_endian(data);
	else
		converted_data = data;
	return converted_data;
}

static inline void mmio_write_data(unsigned int addr, uint32_t data)
{
	uint32_t converted_data;
	if(BIG_ENDIAN_ACCESS==1)
		converted_data = convert_endian(data);
	else
		converted_data = data;
	REG32(addr) = converted_data;
}

void mmio_read_string(unsigned int addr, char* dest, int max_size);

static inline int mmfifo_get_vacancy(unsigned int addr)
{
  return mmio_read_data(addr);
}

static inline void mmfifo_wait_unitl_ready(unsigned int addr, int length)
{
  while(1)
  {
    int num_vacancy = mmfifo_get_vacancy(addr);
    if (num_vacancy>=length)
      break;
  }
}

void mmfifo_write(unsigned int addr, const void* value_list, int length);
void mmfifo_write_force(unsigned int addr, const void* value_list, int length);
void mmfifo_read(unsigned int addr, unsigned int valid_num_addr, void* value_list, int length);
void mmfifo_read_force(unsigned int addr, void* value_list, int length);

#endif
