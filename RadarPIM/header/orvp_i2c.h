#ifndef __ORVP_I2C_H__
#define __ORVP_I2C_H__

#include <stdint.h>

#define I2C_DISABLE                         0
#define I2C_ENABLE                          1

#define I2C_INTERRUPT_DISABLE               0
#define I2C_INTERRUPT_ENABLE                1

// r means num of reg_index, and d does num of data
void configure_i2c(int i2c_index, int target_freq, int i2c_enable, int i2c_interrupt_enable);
void write_i2c_r0dn(int i2c_index, uint8_t module_address, uint8_t *data, int num_bytes);
void write_i2c_r1dn(int i2c_index, uint8_t module_address, uint8_t reg_address, uint8_t *data, int num_bytes);
void read_i2c_r0dn(int i2c_index, uint8_t module_address, uint8_t *data, int num_bytes);
void read_i2c_r1dn(int i2c_index, uint8_t module_address, uint8_t reg_address, uint8_t *data, int num_bytes);
uint8_t read_i2c_r1d1(int i2c_index, uint8_t module_address, uint8_t reg_address);
void write_i2c_r1d1(int i2c_index, uint8_t module_address, uint8_t reg_address, uint8_t data);
void write_i2c_r2d1(int i2c_index, uint8_t module_address, uint16_t reg_address, uint8_t data);
void write_i2c_r2d2(int i2c_index, uint8_t module_address, uint16_t reg_address, uint16_t data);

#endif
