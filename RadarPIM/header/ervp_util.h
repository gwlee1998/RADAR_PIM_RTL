#ifndef __ERVP_UTIL_H__
#define __ERVP_UTIL_H__

#include "core_dependent.h"

#define static_assert(cond) switch(0) { case 0: case !!(long)(cond): ; }

static inline void delay_unit(unsigned int count) {
	unsigned int i;
	for(i=0; i<(count>>2); i++)
	{
		IDLE;
	}
}

void convert_value_to_bitvector(unsigned int value, char* bitvector);

#endif
