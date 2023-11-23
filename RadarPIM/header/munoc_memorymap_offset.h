#ifndef __MUNOC_MEMORYMAP_OFFSET_H__
#define __MUNOC_MEMORYMAP_OFFSET_H__



// total
#define BW_MMAP_OFFSET_MUNOC 10
#define MUNOC_ADDR_INTERVAL 8
#define BW_UNUSED_MUNOC 3
#define NUM_MUNOC_SUBMODULE 3
#define SUBMODULE_INDEX_MUNOC_INFO 0
#define SUBMODULE_ADDR_MUNOC_INFO 0x0
#define SUBMODULE_INDEX_MUNOC_ELOG 1
#define SUBMODULE_ADDR_MUNOC_ELOG 0x100
#define SUBMODULE_INDEX_MUNOC_CONTROLLER 2
#define SUBMODULE_ADDR_MUNOC_CONTROLLER 0x200

// submodule info
#define BW_MMAP_SUBOFFSET_INFO 7
#define BW_UNUSED_INFO 3
#define MMAP_SUBOFFSET_INFO_VERSION0 0x0
#define MMAP_SUBOFFSET_INFO_VERSION1 0x8
#define MMAP_SUBOFFSET_INFO_VERSION2 0x10
#define MMAP_SUBOFFSET_INFO_VERSION3 0x18
#define MMAP_SUBOFFSET_INFO_CONFIG0 0x20
#define MMAP_SUBOFFSET_INFO_CONFIG1 0x28
#define MMAP_SUBOFFSET_INFO_NUM_MASTER 0x30
#define MMAP_SUBOFFSET_INFO_NUM_SLAVE 0x38
#define MMAP_SUBOFFSET_INFO_SELF_ID 0x40

#define MMAP_OFFSET_INFO_VERSION0 (SUBMODULE_ADDR_MUNOC_INFO+MMAP_SUBOFFSET_INFO_VERSION0)
#define MMAP_OFFSET_INFO_VERSION1 (SUBMODULE_ADDR_MUNOC_INFO+MMAP_SUBOFFSET_INFO_VERSION1)
#define MMAP_OFFSET_INFO_VERSION2 (SUBMODULE_ADDR_MUNOC_INFO+MMAP_SUBOFFSET_INFO_VERSION2)
#define MMAP_OFFSET_INFO_VERSION3 (SUBMODULE_ADDR_MUNOC_INFO+MMAP_SUBOFFSET_INFO_VERSION3)
#define MMAP_OFFSET_INFO_CONFIG0 (SUBMODULE_ADDR_MUNOC_INFO+MMAP_SUBOFFSET_INFO_CONFIG0)
#define MMAP_OFFSET_INFO_CONFIG1 (SUBMODULE_ADDR_MUNOC_INFO+MMAP_SUBOFFSET_INFO_CONFIG1)
#define MMAP_OFFSET_INFO_NUM_MASTER (SUBMODULE_ADDR_MUNOC_INFO+MMAP_SUBOFFSET_INFO_NUM_MASTER)
#define MMAP_OFFSET_INFO_NUM_SLAVE (SUBMODULE_ADDR_MUNOC_INFO+MMAP_SUBOFFSET_INFO_NUM_SLAVE)
#define MMAP_OFFSET_INFO_SELF_ID (SUBMODULE_ADDR_MUNOC_INFO+MMAP_SUBOFFSET_INFO_SELF_ID)

// submodule elog
#define BW_MMAP_SUBOFFSET_ELOG 6
#define BW_UNUSED_ELOG 3
#define MMAP_SUBOFFSET_ELOG_COUNT 0x0
#define MMAP_SUBOFFSET_ELOG_VALID 0x8
#define MMAP_SUBOFFSET_ELOG_RW 0x10
#define MMAP_SUBOFFSET_ELOG_ADDR 0x18
#define MMAP_SUBOFFSET_ELOG_MASTER 0x20

#define MMAP_OFFSET_ELOG_COUNT (SUBMODULE_ADDR_MUNOC_ELOG+MMAP_SUBOFFSET_ELOG_COUNT)
#define MMAP_OFFSET_ELOG_VALID (SUBMODULE_ADDR_MUNOC_ELOG+MMAP_SUBOFFSET_ELOG_VALID)
#define MMAP_OFFSET_ELOG_RW (SUBMODULE_ADDR_MUNOC_ELOG+MMAP_SUBOFFSET_ELOG_RW)
#define MMAP_OFFSET_ELOG_ADDR (SUBMODULE_ADDR_MUNOC_ELOG+MMAP_SUBOFFSET_ELOG_ADDR)
#define MMAP_OFFSET_ELOG_MASTER (SUBMODULE_ADDR_MUNOC_ELOG+MMAP_SUBOFFSET_ELOG_MASTER)

// submodule controller
#define BW_MMAP_SUBOFFSET_CONTROLLER 8
#define BW_UNUSED_CONTROLLER 3
#define MMAP_SUBOFFSET_CONTROLLER_NAME0 0x0
#define MMAP_SUBOFFSET_CONTROLLER_NAME1 0x8
#define MMAP_SUBOFFSET_CONTROLLER_NAME2 0x10
#define MMAP_SUBOFFSET_CONTROLLER_NAME3 0x18
#define MMAP_SUBOFFSET_CONTROLLER_NAME4 0x20
#define MMAP_SUBOFFSET_CONTROLLER_NAME5 0x28
#define MMAP_SUBOFFSET_CONTROLLER_NAME6 0x30
#define MMAP_SUBOFFSET_CONTROLLER_NAME7 0x38
#define MMAP_SUBOFFSET_CONTROLLER_TYPE0 0x40
#define MMAP_SUBOFFSET_CONTROLLER_TYPE1 0x48
#define MMAP_SUBOFFSET_CONTROLLER_NODEID 0x50
#define MMAP_SUBOFFSET_CONTROLLER_FNI_STATE 0x58
#define MMAP_SUBOFFSET_CONTROLLER_BNI_STATE 0x60
#define MMAP_SUBOFFSET_CONTROLLER_MONITOR_ENABLE 0x68
#define MMAP_SUBOFFSET_CONTROLLER_EXCLUDE 0x70
#define MMAP_SUBOFFSET_CONTROLLER_IP_TIMEOUT 0x78
#define MMAP_SUBOFFSET_CONTROLLER_NOC_TIMEOUT 0x80
#define MMAP_SUBOFFSET_CONTROLLER_ROUTING_ERROR 0x88
#define MMAP_SUBOFFSET_CONTROLLER_BANDWIDTH 0x90
#define MMAP_SUBOFFSET_CONTROLLER_PROTOCOL_VIOLATION 0x98

#define MMAP_OFFSET_CONTROLLER_NAME0 (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_NAME0)
#define MMAP_OFFSET_CONTROLLER_NAME1 (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_NAME1)
#define MMAP_OFFSET_CONTROLLER_NAME2 (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_NAME2)
#define MMAP_OFFSET_CONTROLLER_NAME3 (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_NAME3)
#define MMAP_OFFSET_CONTROLLER_NAME4 (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_NAME4)
#define MMAP_OFFSET_CONTROLLER_NAME5 (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_NAME5)
#define MMAP_OFFSET_CONTROLLER_NAME6 (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_NAME6)
#define MMAP_OFFSET_CONTROLLER_NAME7 (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_NAME7)
#define MMAP_OFFSET_CONTROLLER_TYPE0 (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_TYPE0)
#define MMAP_OFFSET_CONTROLLER_TYPE1 (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_TYPE1)
#define MMAP_OFFSET_CONTROLLER_NODEID (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_NODEID)
#define MMAP_OFFSET_CONTROLLER_FNI_STATE (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_FNI_STATE)
#define MMAP_OFFSET_CONTROLLER_BNI_STATE (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_BNI_STATE)
#define MMAP_OFFSET_CONTROLLER_MONITOR_ENABLE (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_MONITOR_ENABLE)
#define MMAP_OFFSET_CONTROLLER_EXCLUDE (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_EXCLUDE)
#define MMAP_OFFSET_CONTROLLER_IP_TIMEOUT (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_IP_TIMEOUT)
#define MMAP_OFFSET_CONTROLLER_NOC_TIMEOUT (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_NOC_TIMEOUT)
#define MMAP_OFFSET_CONTROLLER_ROUTING_ERROR (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_ROUTING_ERROR)
#define MMAP_OFFSET_CONTROLLER_BANDWIDTH (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_BANDWIDTH)
#define MMAP_OFFSET_CONTROLLER_PROTOCOL_VIOLATION (SUBMODULE_ADDR_MUNOC_CONTROLLER+MMAP_SUBOFFSET_CONTROLLER_PROTOCOL_VIOLATION)

// reg info.version0
#define BW_INFO_VERSION0 32

// reg info.version1
#define BW_INFO_VERSION1 32

// reg info.version2
#define BW_INFO_VERSION2 32

// reg info.version3
#define BW_INFO_VERSION3 32

// reg info.config0
#define BW_INFO_CONFIG0 32

// reg info.config1
#define BW_INFO_CONFIG1 32

// reg info.num_master
#define BW_INFO_NUM_MASTER 32

// reg info.num_slave
#define BW_INFO_NUM_SLAVE 32

// reg info.self_id
#define BW_INFO_SELF_ID 32

// reg elog.count
#define BW_ELOG_COUNT 32

// reg elog.valid
#define BW_ELOG_VALID 32

// reg elog.rw
#define BW_ELOG_RW 32

// reg elog.addr
#define BW_ELOG_ADDR 32

// reg elog.master
#define BW_ELOG_MASTER 32

// reg controller.name0
#define BW_CONTROLLER_NAME0 32

// reg controller.name1
#define BW_CONTROLLER_NAME1 32

// reg controller.name2
#define BW_CONTROLLER_NAME2 32

// reg controller.name3
#define BW_CONTROLLER_NAME3 32

// reg controller.name4
#define BW_CONTROLLER_NAME4 32

// reg controller.name5
#define BW_CONTROLLER_NAME5 32

// reg controller.name6
#define BW_CONTROLLER_NAME6 32

// reg controller.name7
#define BW_CONTROLLER_NAME7 32

// reg controller.type0
#define BW_CONTROLLER_TYPE0 32

// reg controller.type1
#define BW_CONTROLLER_TYPE1 32

// reg controller.nodeid
#define BW_CONTROLLER_NODEID 32

// reg controller.fni_state
#define BW_CONTROLLER_FNI_STATE 32

// reg controller.bni_state
#define BW_CONTROLLER_BNI_STATE 32

// reg controller.monitor_enable
#define BW_CONTROLLER_MONITOR_ENABLE 32

// reg controller.exclude
#define BW_CONTROLLER_EXCLUDE 32

// reg controller.ip_timeout
#define BW_CONTROLLER_IP_TIMEOUT 32

// reg controller.noc_timeout
#define BW_CONTROLLER_NOC_TIMEOUT 32

// reg controller.routing_error
#define BW_CONTROLLER_ROUTING_ERROR 32

// reg controller.bandwidth
#define BW_CONTROLLER_BANDWIDTH 32

// reg controller.protocol_violation
#define BW_CONTROLLER_PROTOCOL_VIOLATION 32

#endif