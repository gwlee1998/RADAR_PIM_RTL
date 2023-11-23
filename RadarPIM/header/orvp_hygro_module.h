#ifndef __ORVP_HYGRO_MODULE_H__
#define __ORVP_HYGRO_MODULE_H__

void configure_i2c_for_hygro_module();
void configure_hygro_module_for_temperature_or_humidity();
int read_temperature();
int read_humidity();
void configure_hygro_module_for_temperature_and_humidity();
void read_temperature_and_humidity(int *temperature, int *humidity);

#endif
