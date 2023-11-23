#ifndef __ERVP_DELAY_H__
#define __ERVP_DELAY_H__

#include "platform_info.h"

#ifdef INCLUDE_TIMER

#include "ervp_timer.h"

static inline void delay_us(unsigned int time_in_us)
{
	delay_us_by_timer(time_in_us);
}

static inline void delay_ms(unsigned int time_in_ms)
{
	delay_ms_by_timer(time_in_ms);
}

static inline void delay_sec(unsigned int time_in_sec)
{
	delay_sec_by_timer(time_in_sec);
}

#else // ifndef INCLUDE_TIMER

#include "ervp_real_clock.h"

static inline void delay_us(unsigned int time_in_us)
{
	delay_us_by_real_clock(time_in_us);
}

static inline void delay_ms(unsigned int time_in_ms)
{
	delay_ms_by_real_clock(time_in_ms);
}

static inline void delay_sec(unsigned int time_in_sec)
{
	delay_sec_by_real_clock(time_in_sec);
}

#endif // INCLUDE_TIMER

#endif
