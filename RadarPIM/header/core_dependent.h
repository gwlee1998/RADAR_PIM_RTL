#ifndef __CORE_DEPENDENT_H__
#define __CORE_DEPENDENT_H__

#include "platform_info.h"

#include "riscv_isa.h"
#include "csr_encoding.h"
#include "ervp_reg_util.h"
#include "ervp_interrupt.h"

#define BIG_ENDIAN_ACCESS 0

static inline int get_thread_id()
{
	int result;
	if(NUM_THREAD_PER_TEAM==1)
		result = 0;
	else
	{
		result = get_internal_core_id();
#ifdef VP_ENV
		switch(NUM_THREAD_PER_TEAM)
		{
			case 2:
				result &= 0x1;
				break;
			case 4:
				result &= 0x3;
				break;
			default:
				while(1);
		}
#endif // VP_ENV
	}
	return result;
}

static inline unsigned int get_interrupt(){
	return ((read_csr(mstatus) & MSTATUS_MIE)>0);
}

static inline void enable_interrupt(){
	// Enable interrupts in general.
	set_csr(mstatus, MSTATUS_MIE);
}

static inline void disable_interrupt(){
	// Enable interrupts in general.
	clear_csr(mstatus, MSTATUS_MIE);
}

static inline void allow_interrupt_timer(){
	// Enable the Machine-Timer bit in MIE
	set_csr(mie, MIP_MTIP);
}

static inline void disallow_interrupt_timer(){
	// Disable the Machine-Timer bit in MIE
	clear_csr(mie, MIP_MTIP);
}

static inline void allow_interrupt_plic(){
	check_plic_grant();
	// Enable the Machine-External bit in MIE
	set_csr(mie, MIP_MEIP);
}

static inline void disallow_interrupt_plic(){
	// Disable the Machine-External bit in MIE
	clear_csr(mie, MIP_MEIP);
}

static inline void flush_cache()
{
	asm volatile ("fence.i");
	//asm volatile(".word 0xfc000073" : : : "memory");
}

/*
static inline void disable_interrupt(){
	int value;
	value = 0;
	write_csr(MEIMASK, value);
	value = 0;
	write_csr(MSTATUS, value);
}
static inline void enable_interrupt(){
	int value;
	value = 0xFFFFFFFF;
	write_csr(MEIMASK, value);
	value = 8;
	write_csr(MSTATUS, value);
}
*/

//#define CSR_MUMR0_BASE 0xBE0
//#define CSR_MUMR1_BASE 0xBE1
//#define CSR_MUMR2_BASE 0xBE2
//#define CSR_MUMR3_BASE 0xBE3
//#define CSR_MUMR0_LAST 0xBE8
//#define CSR_MUMR1_LAST 0xBE9
//#define CSR_MUMR2_LAST 0xBEA
//#define CSR_MUMR3_LAST 0xBEB

static inline void init_core()
{
	write_csr(mie, 0);
	//write_csr(mideleg, 0); when using VM in old version
	//write_csr(medeleg, 0); when using VM in old version
	if (read_csr(misa) & (1 << ('F' - 'A'))) { // if F extension is present
		set_csr(mstatus, MSTATUS_FS); // allow FPU instructions without trapping
		write_csr(fcsr, 0); // initialize rounding mode, undefined at reset
	}
}

void init_cache(unsigned int cacheable_start, unsigned int cacheable_last);
void set_cacheable_region(int index, unsigned int cacheable_start, unsigned int cacheable_last);

#endif
