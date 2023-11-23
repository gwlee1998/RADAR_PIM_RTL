#ifndef __UWB_API_H__
#define __UWB_API_H__

#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "ervp_core_id.h"

#include "ervp_user_gpio.h"

#define UART_ID_OF_UWB            (UART_INDEX_FOR_READYMADE)
#define UART_RATE_UWB                     (115200)


void uwb_uart_init2();
void uwb_uart_write2(char *ch, int size);
char uwb_uart_read2();
char uwb_uart_get2();
int  uwb_uart_available2();
void uwb_uart_byte_read(char *ch, int size);

static inline void uwb_rstnn2(unsigned int value)
{
  user_gpio_set_output(GPIO_INDEX_FOR_UWB_RESET, value);
}


#endif