#ifndef __ERVP_EPG_API_H__
#define __ERVP_EPG_API_H__

// to communicate with other IPs or external devices
int get_gpreg(int i);
void set_gpreg(int i, int data);

void gpio_tick_enable(int value);
void gpio_tick_disable();

void init_switch();
unsigned int get_slide_switch(int index);

void spi_user_output_acquire_lock();
void spi_user_output_release_lock();

void spi_cs_config_user_output(unsigned int spi_index, unsigned int enable, unsigned int value);
void spi_dq0_config_user_output(unsigned int spi_index, unsigned int enable, unsigned int value);
void spi_clk_config_user_output(unsigned int spi_index, unsigned int enable, unsigned int value);

#endif
