#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__

void write_bluetooth(char ch);
void write_string_bluetooth(char *str);
char read_bluetooth();
void bt_init();
void bt_send(char *ch, int size);
void bt_recv(char *ch, int size);
int bt_recv_data(char *data);
int bt_send_data(char *data, int size);

#endif
