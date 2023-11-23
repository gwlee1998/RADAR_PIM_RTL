#ifndef __ERVP_CORE_ID_H__
#define __ERVP_CORE_ID_H__

#include "ervp_reg_util.h"
#include "platform_info.h"

#include "core_dependent.h"
#include "ervp_core_peri_group_memorymap_offset.h"
#include "ervp_external_peri_group_api.h"

static inline int get_process_id()
{
	int result;
	if(NUM_REAL_CORE==NUM_THREAD_PER_TEAM)
		result = 0;
	else
	{
#ifdef VP_ENV
		result = get_internal_core_id();
		switch(NUM_THREAD_PER_TEAM)
		{
			case 1:
				break;
			case 2:
				result >>= 1;
				break;
			case 4:
				result >>= 2;
				break;
			default:
				while(1);
		}
#else // VP_ENV
#ifdef INCLUDE_MULTICORE
		result = REG32(CORE_PERI_GROUP_BASEADDR+MMAP_OFFSET_MULTICORE_SUPPORTER_PROCESS_ID);
#else
		while(1);
#endif
#endif // VP_ENV
	}
	return result;
}

static inline int concat_id(int process_id, int thread_id)
{
	int result = process_id;
	switch(NUM_THREAD_PER_TEAM)
	{
		case 1:
			break;
		case 2:
			result <<= 1;
			result += thread_id;
			break;
		case 4:
			result <<= 2;
			result += thread_id;
			break;
		default:
			while(1);
	}
	return result;
}

static inline int get_exclusive_id()
{
#ifdef VP_ENV
	return get_internal_core_id();
#else
	return concat_id(get_process_id(),get_thread_id());
#endif
}

#define EXCLUSIVE_ID get_exclusive_id()
#define THREAD_ID get_thread_id()
#define PROCESS_ID get_process_id()

#define CORE_ID(pid,thid) concat_id(pid,thid)

#endif
