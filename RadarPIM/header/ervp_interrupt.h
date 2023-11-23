#ifndef __ERVP_INTERRUPT_H__
#define __ERVP_INTERRUPT_H__

#include "platform_info.h"

typedef void (*function_ptr_t) (void);
void init_handle_trap();
void wait_for_interrupts();

#ifdef INCLUDE_TIMER
void register_isr_timer(function_ptr_t isr);
#endif

#ifdef INCLUDE_PLIC

void register_isr_gpio(int gpio_index, function_ptr_t isr, int priority);
void enable_isr_gpio(int gpio_index);
void disable_isr_gpio(int gpio_index);

void register_isr_user(int user_index, function_ptr_t isr, int priority);
void enable_isr_user(int user_index);
void disable_isr_user(int user_index);

void register_isr_wifi(function_ptr_t isr, int priority);
void enable_isr_wifi();
void disable_isr_wifi();

void register_isr_hbc1(function_ptr_t isr, int priority);
void enable_isr_hbc1();
void disable_isr_hbc1();

void register_isr_i2s(function_ptr_t isr, int priority);
void enable_isr_i2s();
void disable_isr_i2s();
#endif

#ifdef INCLUDE_MULTICORE

void register_plic_grant();
void check_plic_grant();

#else

static inline void register_plic_grant(){};
static inline void check_plic_grant(){};

#endif

#endif
