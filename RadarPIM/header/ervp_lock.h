#ifndef __ERVP_LOCK_H__
#define __ERVP_LOCK_H__

#include "platform_info.h"
#include "ervp_mmio_util.h"
#include "ervp_common_peri_group_memorymap.h"
#include "ervp_core_peri_group_memorymap.h"

#ifdef INCLUDE_MULTICORE

static inline unsigned int get_lock_addr(int lock_index)
{
	const unsigned int addr = MMAP_SUBMODULE_LOCK;
	const unsigned int shift = BW_UNUSED_LOCK + lock_index;
	return addr + (1<<shift);
}

static inline unsigned int get_wait_lock_addr(int lock_index)
{
	const unsigned int addr = MMAP_SUBMODULE_WAIT_LOCK;
	const unsigned int shift = BW_UNUSED_WAIT_LOCK + lock_index;
	return addr + (1<<shift);
}

static inline unsigned int __is_lock_occupied(unsigned int addr)
{
	return REG32(addr);
}

static inline void __wait_lock(unsigned int addr)
{
	while(__is_lock_occupied(addr)!=0);
}

// returns positive value if acquired rather than 1
static inline int __try_to_acquire_lock(unsigned int addr)
{
	return REG32(addr); // test-and-set
}

static inline void __release_lock(unsigned int addr)
{
	REG32(addr) = 0;
}

void acquire_lock(int lock_index);
static inline void release_lock(int lock_index)
{
	const unsigned int addr = get_lock_addr(lock_index);
	__release_lock(addr);
}

int acquire_shared_resource(int lock_index);
void release_shared_resource(int lock_index, int interrupt_status);

#else

static inline void acquire_lock(int lock_index){ return; }
static inline void release_lock(int lock_index){ return; }
static inline int acquire_shared_resource(int lock_index){ return 1; }
static inline void release_shared_resource(int lock_index, int interrupt_status){ return; }

#endif

#endif
