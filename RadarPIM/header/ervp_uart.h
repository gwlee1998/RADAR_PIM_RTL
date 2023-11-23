#ifndef __ERVP_UART_H__
#define __ERVP_UART_H__

void uart_init(void);
void uart_config(int uart_index, unsigned int baud_rate);
int uart_putc(int uart_index, char c);
char uart_getc(int uart_index);
void uart_puts(int uart_index, char *c);

int uart_check_rx_data_ready(int uart_index);
char uart_read_rx_buffer(int uart_index);

#endif
