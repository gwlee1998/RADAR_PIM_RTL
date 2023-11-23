#ifndef __ORVP_RTCC_MODULE_H__
#define __ORVP_RTCC_MODULE_H__

// user define for day
#define MONDAY				1
#define TUESDAY				2
#define WEDNESDAY			3
#define THURSDAY			4
#define FRIDAY				5
#define SATURDAY			6
#define SUNDAY				7

void configure_i2c_for_rtcc_module();
void configure_rtcc_module(unsigned int sec, unsigned int min, unsigned int hour, unsigned int day, unsigned int date, unsigned int month, unsigned int year);
void read_time(unsigned int *sec, unsigned int *min, unsigned int *hour, unsigned int *day, unsigned int *date, unsigned int *month, unsigned int *year);

#endif
