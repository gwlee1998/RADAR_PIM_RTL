#ifndef __ERVP_MEMEORY_ALIGNMENT_H__
#define __ERVP_MEMEORY_ALIGNMENT_H__

#include "platform_info.h"

static inline int align(int addr, int align_size)
{
	const int lower = (align_size-1);
	int temp;
	temp = addr & lower;
	if(temp!=0)
		addr += (align_size-temp);
	return addr;
}

static inline int align_cache_line(int addr)
{
	#ifdef INCLUDE_CACHE
	return align(addr, DATA_ALIGN_SIZE);
	#else
	return addr;
	#endif
}

#endif
