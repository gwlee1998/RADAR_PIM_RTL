#ifndef __ERVP_AUTO_ID_H__
#define __ERVP_AUTO_ID_H__

#include "platform_info.h"
#include "ervp_mmio_util.h"
#include "ervp_common_peri_group_memorymap.h"

static inline unsigned int get_auto_id_addr(int id_index)
{
	const unsigned int addr = MMAP_SUBMODULE_AUTO_ID;
	const unsigned int shift = BW_UNUSED_AUTO_ID + id_index;
	return addr + (1<<shift);
}

static inline unsigned int get_auto_id(int id_index)
{
	return REG32(get_auto_id_addr(id_index));
}

static inline void init_auto_id(int id_index)
{
	REG32(get_auto_id_addr(id_index)) = 0;
}

#endif
