
#include "uwb_api.h"

#include "ervp_uart_define.h"
#include "ervp_uart.h"

#include "ervp_delay.h"
#include "ervp_variable_allocation.h"




void uwb_uart_init2()
{
  uwb_rstnn2(0);
  delay_ms(100);
  uwb_rstnn2(1);

  uart_config(UART_ID_OF_UWB, UART_RATE_UWB);
}


void uwb_uart_write2(char *ch, int size)
{
  int i;
  for(i=0; i<size; i++)
  {
    uart_putc(UART_ID_OF_UWB, ch[i]);
  }
}

char uwb_uart_read2()
{
  return uart_getc(UART_ID_OF_UWB);
}

void uwb_uart_byte_read(char *ch, int size)
{
  int i;
  for(i=0; i<size; i++)
  {
    ch[i] = uart_getc(UART_ID_OF_UWB);
  }
}


char uwb_uart_get2()
{
  return  uart_read_rx_buffer(UART_ID_OF_UWB);
}

void uwb_uart_put2(char ch)
{
  uart_putc(UART_ID_OF_UWB, ch);

}

int  uwb_uart_available2()
{
  return uart_check_rx_data_ready(UART_ID_OF_UWB);
}