#ifndef __MUNOC_API_H__
#define __MUNOC_API_H__

#include "ervp_reg_util.h"
#include "munoc_memorymap_offset.h"
#include "platform_info.h"

#define NOC_MMAP(reg) (NOC_CONTROLLER_BASEADDR+(reg))
#define NOC_MMAP2(value,reg) (NOC_MMAP(reg)+(value<<(BW_MMAP_OFFSET_MUNOC)))

#define MASTER_IP 0
#define SLAVE_IP 1

#define ELOG_MMAP(index,reg) NOC_MMAP2(index,reg)
#define NI_MMAP(type, index,reg) NOC_MMAP2((type+(index<<1)),reg)

int get_node_id();
void print_noc_version();
void print_noc_info();
int get_number_of_master();
int get_number_of_slave();
void print_ip_list();
//void enable_monitor(); this does NOT work
void disable_monitor();
void print_monitor_status();
void disable_ip(char* name);
void check_undefined_access();
void check_noc_status();

#define NODE_ID get_node_id()

#endif
