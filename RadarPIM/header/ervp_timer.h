#ifndef __ERVP_TIMER_H__
#define __ERVP_TIMER_H__

#include "stdint.h"
#include "ervp_mmio_util.h"
#include "platform_info.h"
#include "ervp_core_peri_group_memorymap_offset.h"
#include "ervp_timer_memorymap.h"

static inline void clear_timer_interrupt(void)
{
	REG32(MMAP_TIMER_ITR_CLEAR) = 1;
}

static inline void set_timer_cmd(int cmd)
{
	REG32(MMAP_TIMER_CMD) = cmd;
}

static inline void start_timer_periodic()
{
	set_timer_cmd(TIMER_CMD_ITR_PERIODIC);
}

static inline void start_timer_once()
{
	set_timer_cmd(TIMER_CMD_ITR_ONCE);
}

static inline void stop_timer(void)
{
	set_timer_cmd(TIMER_CMD_IDLE);
}

// used by FreeRTOS
static inline void _config_timer_interval(unsigned int interval_tick)
{
	REG32(MMAP_TIMER_INTERVAL) = interval_tick;
}

void config_timer_interval_us(unsigned int period_us);
void config_timer_interval_ms(unsigned int period_ms);
void start_timer_once_ms(unsigned int period_ms);

void delay_us_by_timer(unsigned int time_in_us);
void delay_ms_by_timer(unsigned int time_in_ms);
void delay_sec_by_timer(unsigned int time_in_sec);

#endif
