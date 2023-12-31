#ifndef __ERVP_TIMER_MEMORYMAP_H__
#define __ERVP_TIMER_MEMORYMAP_H__

#include "platform_info.h"
#include "ervp_timer_memorymap_offset.h"


// submodule timer
#define MMAP_TIMER_CMD (CORE_PERI_GROUP_BASEADDR+SUBMODULE_ADDR_ERVP_CORE_PERI_GROUP_TIMER+MMAP_OFFSET_TIMER_CMD)
#define MMAP_TIMER_INTERVAL (CORE_PERI_GROUP_BASEADDR+SUBMODULE_ADDR_ERVP_CORE_PERI_GROUP_TIMER+MMAP_OFFSET_TIMER_INTERVAL)
#define MMAP_TIMER_ITR_CLEAR (CORE_PERI_GROUP_BASEADDR+SUBMODULE_ADDR_ERVP_CORE_PERI_GROUP_TIMER+MMAP_OFFSET_TIMER_ITR_CLEAR)
#define MMAP_TIMER_DELAY (CORE_PERI_GROUP_BASEADDR+SUBMODULE_ADDR_ERVP_CORE_PERI_GROUP_TIMER+MMAP_OFFSET_TIMER_DELAY)
#define MMAP_TIMER_ISR (CORE_PERI_GROUP_BASEADDR+SUBMODULE_ADDR_ERVP_CORE_PERI_GROUP_TIMER+MMAP_OFFSET_TIMER_ISR)

// reg timer.cmd
// BW_TIMER_CMD 5
// TIMER_CMD_IDLE 9
// TIMER_CMD_ITR_ONCE 3
// TIMER_CMD_ITR_PERIODIC 7
// TIMER_CMD_DELAY 24

// reg timer.interval
// BW_TIMER_INTERVAL 32

// reg timer.itr_clear
// BW_TIMER_ITR_CLEAR 32

// reg timer.delay
// BW_TIMER_DELAY 32

// reg timer.isr
// BW_TIMER_ISR 32

#endif