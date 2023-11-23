#ifndef __ERVP_REAL_CLOCK_H__
#define __ERVP_REAL_CLOCK_H__

#include "stdint.h"

uint64_t get_real_clock_tick();
static inline uint64_t get_mtime(){	return get_real_clock_tick(); };
void print_real_clock_tick();
void print_real_clock_dhms();

void delay_us_by_real_clock(unsigned int time_in_us);
void delay_ms_by_real_clock(unsigned int time_in_ms);
void delay_sec_by_real_clock(unsigned int time_in_sec);

#endif
