#ifndef __ERVP_GPIO_H__
#define __ERVP_GPIO_H__

#include <stdint.h>
#include "ervp_mmio_util.h"
#include "ervp_bit_util.h"
#include "ervp_trigger_cond.h"
#include "ervp_external_peri_group_memorymap.h"

typedef union
{
	uint32_t reg_value;
	struct
	{
		unsigned int cmd : 4;
		unsigned int config : 5;
		unsigned int itr_cond : 5;
    int spare : 2;
    int value : 16;
	} br;
} GpioBinary;

static inline GpioBinary __gpio_get_binary(unsigned int addr)
{
  GpioBinary binary;
  binary.reg_value = REG32(addr);
  return binary;
}

static inline void __gpio_set_binary(unsigned int addr, const GpioBinary binary)
{
  REG32(addr) = binary.reg_value;
}

static inline unsigned int gpio_get_config(unsigned int addr)
{
  GpioBinary binary = __gpio_get_binary(addr);
  return binary.br.config;
}

static inline void gpio_set_config(unsigned int addr, unsigned int config)
{
  GpioBinary binary;
  binary.reg_value = 0;
  binary.br.config = config;
  binary.br.cmd = GPIO_CMD_WE_CONFIG;
  __gpio_set_binary(addr,binary);
}

static inline int gpio_get_input(unsigned int addr)
{
  GpioBinary binary = __gpio_get_binary(addr);
  return binary.br.value;
}

static inline void gpio_set_output(unsigned int addr, int value)
{
  GpioBinary binary = __gpio_get_binary(addr);
  binary.br.value = value;
  binary.br.config = set_bits_by_index(binary.br.config,GPIO_CONFIG_INDEX_IS_OUTPUT_PORT,GPIO_CONFIG_INDEX_IS_OUTPUT_PORT);
  binary.br.cmd = GPIO_CMD_WE_CONFIG | GPIO_CMD_WE_VALUE;
  __gpio_set_binary(addr,binary);
}

static inline void gpio_set_input_cfg(unsigned int addr, unsigned int config)
{
  GpioBinary binary = __gpio_get_binary(addr);
  binary.br.config = clear_bits_by_index(binary.br.config,GPIO_CONFIG_INDEX_IS_OUTPUT_PORT,GPIO_CONFIG_INDEX_IS_OUTPUT_PORT);
  binary.br.cmd = GPIO_CMD_WE_CONFIG;
  __gpio_set_binary(addr,binary);
}

static inline void gpio_enable_interrupt(unsigned int addr, unsigned int cond, int compare_value)
{
  GpioBinary binary = __gpio_get_binary(addr);
  binary.br.value = compare_value;
  binary.br.itr_cond = cond;
  binary.br.config = set_bits_by_index(binary.br.config,GPIO_CONFIG_INDEX_ITR_ENABLE,GPIO_CONFIG_INDEX_ITR_ENABLE);
  binary.br.cmd = GPIO_CMD_WE_CONFIG | GPIO_CMD_WE_ITR_COND;
  __gpio_set_binary(addr,binary);
}

static inline void gpio_diable_interrupt(unsigned int addr)
{
  GpioBinary binary = __gpio_get_binary(addr);
  binary.br.config = clear_bits_by_index(binary.br.config,GPIO_CONFIG_INDEX_ITR_ENABLE,GPIO_CONFIG_INDEX_ITR_ENABLE);
  binary.br.cmd = GPIO_CMD_WE_CONFIG;
  __gpio_set_binary(addr,binary);
}

static inline void gpio_clear_interrupt(unsigned int addr)
{
  GpioBinary binary;
  binary.reg_value = 0;
  binary.br.cmd = GPIO_CMD_CLEAR_ITR;
  __gpio_set_binary(addr,binary);
};

#endif

