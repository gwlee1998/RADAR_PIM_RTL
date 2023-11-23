#ifndef __ERVP_MEMORY_UTIL_H__
#define __ERVP_MEMORY_UTIL_H__

#include <stdint.h>
#include <stdio.h>

extern volatile unsigned int heap_sram_addr;
extern volatile unsigned int heap_sram_end;
extern volatile unsigned int heap_dram_addr;
extern volatile unsigned int heap_dram_end;

void print_memory_byte(uint8_t* array, int size);
void print_memory_4byte(uint32_t* array, int size);
void* malloc_dram(size_t size);
int compare_memory(const void* result, const void* ref, size_t num, int prints);

#define memcpy memcpy_
void* memcpy_(void* dst, const void* src, size_t num);

#define memset memset_
void* memset_(void* ptr, int value, size_t num);

#define malloc malloc_
void* malloc_(size_t size);

#define calloc calloc_
void* calloc_(size_t elt_count, size_t elt_size);

#define free free_
void free_(void* ptr);

#define realloc realloc_
void *realloc_(void *ptr, size_t new_size);

#endif
