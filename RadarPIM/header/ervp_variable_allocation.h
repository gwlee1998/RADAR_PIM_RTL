#ifndef __ERVP_VARIABLE_ALLOCATION_H__
#define __ERVP_VARIABLE_ALLOCATION_H__

#include "platform_info.h"

#define ALIGNED_DATA __attribute__ ((aligned(DATA_ALIGN_SIZE)))

#ifdef INCLUDE_CACHE
#define NOTCACHED_DATA __attribute__ ((section(".notcached")))
#define CACHED_DATA ALIGNED_DATA __attribute__ ((section(".cached")))
#define EXCLUSIVE_DATA ALIGNED_DATA __attribute__ ((section(".exclusive")))
#define PRIVATE_DATA __attribute__ ((section(".private")))
#else
#define NOTCACHED_DATA
#define CACHED_DATA
#define EXCLUSIVE_DATA
#define PRIVATE_DATA
#endif

#define DATA_BSS __attribute__ ((section(".bss")))
#define BIG_DATA __attribute__ ((section(".bigdata")))
#define BIG_DATA_BSS __attribute__ ((section(".bigdata_bss")))
#define ONCE_DATA __attribute__ ((section(".once")))
#define MUST_SRAM __attribute__ ((section(".must_sram")))
#define MUST_DRAM __attribute__ ((section(".must_dram")))

#endif

