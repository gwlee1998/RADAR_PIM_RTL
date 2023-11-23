#ifndef __ERVP_UART_H__
#define __ERVP_UART_H__

void uart_init(void);
int uart_putc(char c);
char uart_getc(void);
void uart_puts(char *c);

#endif
