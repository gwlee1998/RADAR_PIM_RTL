#ifndef __ERVP_USER_GPIO_H__
#define __ERVP_USER_GPIO_H__

#include "ervp_gpio.h"

static inline unsigned int get_user_gpio_addr(unsigned int index)
{
	unsigned int addr;
	addr = MMAP_GPIO_USER_GPIO00 + (index<<BW_UNUSED_GPIO);
	return addr;
}

void user_gpio_set_config(unsigned int index, unsigned int config);

int user_gpio_get_input(unsigned int index);

void user_gpio_set_output(unsigned int index, int value);

void user_gpio_set_input_cfg(unsigned int index, unsigned int config);

void user_gpio_enable_interrupt(unsigned int index, unsigned int cond,  int compare_value);

void user_gpio_diable_interrupt(unsigned int index, unsigned int addr);

static inline void user_gpio_clear_interrupt(unsigned int index)
{
	gpio_clear_interrupt(get_user_gpio_addr(index));
}

#endif

