#ifndef __ERVP_PLATFORM_API_H__
#define __ERVP_PLATFORM_API_H__

#include "ervp_error_code.h"

void print_platform_info();
void print_rvx_info();
int wait_or_initialize();
void set_initialized();
void clear_bss(int bss_start, int bss_end);
void init_platform();
void init_heap(int _heap_sram_start, int _heap_dram_start);
void init_each_core(unsigned int cacheable_start, unsigned int cacheable_last);

void exit_platform();
void exit(unsigned int status);

void assert(int condition, const char* fmt, ...);

#endif
