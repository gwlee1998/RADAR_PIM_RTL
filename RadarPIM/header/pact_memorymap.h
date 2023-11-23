#ifndef __PACT_MEMORYMAP_H__
#define __PACT_MEMORYMAP_H__

#include "platform_info.h"
#include "pact_memorymap_offset.h"


// submodule pact
#define MMAP_PACT_MODE (I_PACT_CONTROL_BASEADDR+MMAP_OFFSET_PACT_MODE)
#define MMAP_PACT_CMD (I_PACT_CONTROL_BASEADDR+MMAP_OFFSET_PACT_CMD)
#define MMAP_PACT_ITR_ENABLE (I_PACT_CONTROL_BASEADDR+MMAP_OFFSET_PACT_ITR_ENABLE)
#define MMAP_PACT_STATUS (I_PACT_CONTROL_BASEADDR+MMAP_OFFSET_PACT_STATUS)
#define MMAP_PACT_INST_MEM_WINDEX (I_PACT_CONTROL_BASEADDR+MMAP_OFFSET_PACT_INST_MEM_WINDEX)
#define MMAP_PACT_INST_MEM_RINDEX (I_PACT_CONTROL_BASEADDR+MMAP_OFFSET_PACT_INST_MEM_RINDEX)
#define MMAP_PACT_INST_MEM_WDATA (I_PACT_CONTROL_BASEADDR+MMAP_OFFSET_PACT_INST_MEM_WDATA)

// reg pact.mode
// BW_PACT_MODE 2
// PACT_MODE_APB 1
// PACT_MODE_CORE 2
// PACT_MODE_INDEX_APB 0
// PACT_MODE_INDEX_CORE 1
// PACT_MODE_NONE 0

// reg pact.status
// BW_PACT_STATUS 1
// PACT_STATUS_IDLE 0
// PACT_STATUS_BUSY 1
// PACT_STATUS_INDEX_BUSY 0
// PACT_STATUS_NONE 0

// reg pact.cmd
// BW_PACT_CMD 32

// reg pact.itr_enable
// BW_PACT_ITR_ENABLE 1

// reg pact.inst_mem_windex
// BW_PACT_INST_MEM_WINDEX 32

// reg pact.inst_mem_rindex
// BW_PACT_INST_MEM_RINDEX 32

// reg pact.inst_mem_wdata
// BW_PACT_INST_MEM_WDATA 32

// reg pact_op_property
// BW_PACT_OP_PROPERTY 8
// PACT_OP_PROPERTY_RISCV 1
// PACT_OP_PROPERTY_VALID 2
// PACT_OP_PROPERTY_BARRIER 4
// PACT_OP_PROPERTY_FLOAT 8
// PACT_OP_PROPERTY_IMME 16
// PACT_OP_PROPERTY_LIBNODE 32
// PACT_OP_PROPERTY_CTRL 64
// PACT_OP_PROPERTY_USERNODE 128
// PACT_OP_PROPERTY_INDEX_RISCV 0
// PACT_OP_PROPERTY_INDEX_VALID 1
// PACT_OP_PROPERTY_INDEX_BARRIER 2
// PACT_OP_PROPERTY_INDEX_FLOAT 3
// PACT_OP_PROPERTY_INDEX_IMME 4
// PACT_OP_PROPERTY_INDEX_LIBNODE 5
// PACT_OP_PROPERTY_INDEX_CTRL 6
// PACT_OP_PROPERTY_INDEX_USERNODE 7
// PACT_OP_PROPERTY_NONE 0

// reg pact_node
// BW_PACT_NODE 16
// PACT_NODE_NONE 0

// reg pact_subop
// BW_PACT_SUBOP 4

// reg pact_immediate
// BW_PACT_IMMEDIATE 32

// reg pact_subop_lsu
// BW_PACT_SUBOP_LSU 3
// PACT_SUBOP_LSU_IDLE 0
// PACT_SUBOP_LSU_LOAD 1
// PACT_SUBOP_LSU_STORE 2
// PACT_SUBOP_LSU_INFO 3
// PACT_SUBOP_LSU_CLEAN 4
// PACT_SUBOP_LSU_INVALIDATE 5
// PACT_SUBOP_LSU_FLUSH 6
// PACT_SUBOP_LSU_WAITCACHE 7
// PACT_SUBOP_LSU_INDEX_LOAD 0
// PACT_SUBOP_LSU_INDEX_STORE 1
// PACT_SUBOP_LSU_INDEX_CLEAN 2

// reg pact_subop_mac0
// BW_PACT_SUBOP_MAC0 4
// PACT_SUBOP_MAC0_IDLE 0
// PACT_SUBOP_MAC0_ADD 1
// PACT_SUBOP_MAC0_EWMULT 2
// PACT_SUBOP_MAC0_MULT_COND 3
// PACT_SUBOP_MAC0_ADD_INV 4
// PACT_SUBOP_MAC0_INIT_ACC 8
// PACT_SUBOP_MAC0_INDEX_ADD 0
// PACT_SUBOP_MAC0_INDEX_EWMULT 1
// PACT_SUBOP_MAC0_INDEX_ADD_INV 2
// PACT_SUBOP_MAC0_INDEX_INIT_ACC 3

// reg pact_subop_arrange0
// BW_PACT_SUBOP_ARRANGE0 2
// PACT_SUBOP_ARRANGE0_IDLE 0
// PACT_SUBOP_ARRANGE0_TRANS 1
// PACT_SUBOP_ARRANGE0_SCALAR 2
// PACT_SUBOP_ARRANGE0_INDEX_TRANS 0
// PACT_SUBOP_ARRANGE0_INDEX_SCALAR 1

// reg pact_subop_core
// BW_PACT_SUBOP_CORE 3
// PACT_SUBOP_CORE_IDLE 0
// PACT_SUBOP_CORE_STARTADDR 1
// PACT_SUBOP_CORE_ACTIVE 2
// PACT_SUBOP_CORE_WAIT 3
// PACT_SUBOP_CORE_SLEEP 4
// PACT_SUBOP_CORE_INDEX_STARTADDR 0
// PACT_SUBOP_CORE_INDEX_ACTIVE 1
// PACT_SUBOP_CORE_INDEX_SLEEP 2

// reg pact_op_ctrl
// BW_PACT_OP_CTRL 2
// PACT_OP_CTRL_INTERRUPT 1
// PACT_OP_CTRL_FINISH 2
// PACT_OP_CTRL_INDEX_INTERRUPT 0
// PACT_OP_CTRL_INDEX_FINISH 1
// PACT_OP_CTRL_NONE 0

// reg pact_op_libnode
// BW_PACT_OP_LIBNODE 6
// PACT_OP_LIBNODE_LSU0 1
// PACT_OP_LIBNODE_LSU1 2
// PACT_OP_LIBNODE_MAC0 4
// PACT_OP_LIBNODE_ARRANGE0 8
// PACT_OP_LIBNODE_CORE0 16
// PACT_OP_LIBNODE_CORE1 32
// PACT_OP_LIBNODE_INDEX_LSU0 0
// PACT_OP_LIBNODE_INDEX_LSU1 1
// PACT_OP_LIBNODE_INDEX_MAC0 2
// PACT_OP_LIBNODE_INDEX_ARRANGE0 3
// PACT_OP_LIBNODE_INDEX_CORE0 4
// PACT_OP_LIBNODE_INDEX_CORE1 5
// PACT_OP_LIBNODE_NONE 0

// reg pact_op_usernode
// BW_PACT_OP_USERNODE 25
// PACT_OP_USERNODE_00 1
// PACT_OP_USERNODE_01 2
// PACT_OP_USERNODE_02 4
// PACT_OP_USERNODE_03 8
// PACT_OP_USERNODE_04 16
// PACT_OP_USERNODE_05 32
// PACT_OP_USERNODE_06 64
// PACT_OP_USERNODE_07 128
// PACT_OP_USERNODE_08 256
// PACT_OP_USERNODE_09 512
// PACT_OP_USERNODE_10 1024
// PACT_OP_USERNODE_11 2048
// PACT_OP_USERNODE_12 4096
// PACT_OP_USERNODE_13 8192
// PACT_OP_USERNODE_14 16384
// PACT_OP_USERNODE_15 32768
// PACT_OP_USERNODE_16 65536
// PACT_OP_USERNODE_17 131072
// PACT_OP_USERNODE_18 262144
// PACT_OP_USERNODE_19 524288
// PACT_OP_USERNODE_20 1048576
// PACT_OP_USERNODE_21 2097152
// PACT_OP_USERNODE_22 4194304
// PACT_OP_USERNODE_23 8388608
// PACT_OP_USERNODE_24 16777216
// PACT_OP_USERNODE_INDEX_00 0
// PACT_OP_USERNODE_INDEX_01 1
// PACT_OP_USERNODE_INDEX_02 2
// PACT_OP_USERNODE_INDEX_03 3
// PACT_OP_USERNODE_INDEX_04 4
// PACT_OP_USERNODE_INDEX_05 5
// PACT_OP_USERNODE_INDEX_06 6
// PACT_OP_USERNODE_INDEX_07 7
// PACT_OP_USERNODE_INDEX_08 8
// PACT_OP_USERNODE_INDEX_09 9
// PACT_OP_USERNODE_INDEX_10 10
// PACT_OP_USERNODE_INDEX_11 11
// PACT_OP_USERNODE_INDEX_12 12
// PACT_OP_USERNODE_INDEX_13 13
// PACT_OP_USERNODE_INDEX_14 14
// PACT_OP_USERNODE_INDEX_15 15
// PACT_OP_USERNODE_INDEX_16 16
// PACT_OP_USERNODE_INDEX_17 17
// PACT_OP_USERNODE_INDEX_18 18
// PACT_OP_USERNODE_INDEX_19 19
// PACT_OP_USERNODE_INDEX_20 20
// PACT_OP_USERNODE_INDEX_21 21
// PACT_OP_USERNODE_INDEX_22 22
// PACT_OP_USERNODE_INDEX_23 23
// PACT_OP_USERNODE_INDEX_24 24
// PACT_OP_USERNODE_NONE 0

// reg pact_write_reg
// BW_PACT_WRITE_REG 32
// PACT_WRITE_REG_00 1
// PACT_WRITE_REG_01 2
// PACT_WRITE_REG_02 4
// PACT_WRITE_REG_03 8
// PACT_WRITE_REG_04 16
// PACT_WRITE_REG_05 32
// PACT_WRITE_REG_06 64
// PACT_WRITE_REG_07 128
// PACT_WRITE_REG_08 256
// PACT_WRITE_REG_09 512
// PACT_WRITE_REG_10 1024
// PACT_WRITE_REG_11 2048
// PACT_WRITE_REG_12 4096
// PACT_WRITE_REG_13 8192
// PACT_WRITE_REG_14 16384
// PACT_WRITE_REG_15 32768
// PACT_WRITE_REG_16 65536
// PACT_WRITE_REG_17 131072
// PACT_WRITE_REG_18 262144
// PACT_WRITE_REG_19 524288
// PACT_WRITE_REG_20 1048576
// PACT_WRITE_REG_21 2097152
// PACT_WRITE_REG_22 4194304
// PACT_WRITE_REG_23 8388608
// PACT_WRITE_REG_24 16777216
// PACT_WRITE_REG_25 33554432
// PACT_WRITE_REG_26 67108864
// PACT_WRITE_REG_27 134217728
// PACT_WRITE_REG_28 268435456
// PACT_WRITE_REG_29 536870912
// PACT_WRITE_REG_30 1073741824
// PACT_WRITE_REG_31 2147483648
// PACT_WRITE_REG_INDEX_00 0
// PACT_WRITE_REG_INDEX_01 1
// PACT_WRITE_REG_INDEX_02 2
// PACT_WRITE_REG_INDEX_03 3
// PACT_WRITE_REG_INDEX_04 4
// PACT_WRITE_REG_INDEX_05 5
// PACT_WRITE_REG_INDEX_06 6
// PACT_WRITE_REG_INDEX_07 7
// PACT_WRITE_REG_INDEX_08 8
// PACT_WRITE_REG_INDEX_09 9
// PACT_WRITE_REG_INDEX_10 10
// PACT_WRITE_REG_INDEX_11 11
// PACT_WRITE_REG_INDEX_12 12
// PACT_WRITE_REG_INDEX_13 13
// PACT_WRITE_REG_INDEX_14 14
// PACT_WRITE_REG_INDEX_15 15
// PACT_WRITE_REG_INDEX_16 16
// PACT_WRITE_REG_INDEX_17 17
// PACT_WRITE_REG_INDEX_18 18
// PACT_WRITE_REG_INDEX_19 19
// PACT_WRITE_REG_INDEX_20 20
// PACT_WRITE_REG_INDEX_21 21
// PACT_WRITE_REG_INDEX_22 22
// PACT_WRITE_REG_INDEX_23 23
// PACT_WRITE_REG_INDEX_24 24
// PACT_WRITE_REG_INDEX_25 25
// PACT_WRITE_REG_INDEX_26 26
// PACT_WRITE_REG_INDEX_27 27
// PACT_WRITE_REG_INDEX_28 28
// PACT_WRITE_REG_INDEX_29 29
// PACT_WRITE_REG_INDEX_30 30
// PACT_WRITE_REG_INDEX_31 31
// PACT_WRITE_REG_NONE 0

// reg pact_read_reg
// BW_PACT_READ_REG 16
// PACT_READ_REG_00 1
// PACT_READ_REG_01 2
// PACT_READ_REG_02 4
// PACT_READ_REG_03 8
// PACT_READ_REG_04 16
// PACT_READ_REG_05 32
// PACT_READ_REG_06 64
// PACT_READ_REG_07 128
// PACT_READ_REG_08 256
// PACT_READ_REG_09 512
// PACT_READ_REG_10 1024
// PACT_READ_REG_11 2048
// PACT_READ_REG_12 4096
// PACT_READ_REG_13 8192
// PACT_READ_REG_14 16384
// PACT_READ_REG_15 32768
// PACT_READ_REG_INDEX_00 0
// PACT_READ_REG_INDEX_01 1
// PACT_READ_REG_INDEX_02 2
// PACT_READ_REG_INDEX_03 3
// PACT_READ_REG_INDEX_04 4
// PACT_READ_REG_INDEX_05 5
// PACT_READ_REG_INDEX_06 6
// PACT_READ_REG_INDEX_07 7
// PACT_READ_REG_INDEX_08 8
// PACT_READ_REG_INDEX_09 9
// PACT_READ_REG_INDEX_10 10
// PACT_READ_REG_INDEX_11 11
// PACT_READ_REG_INDEX_12 12
// PACT_READ_REG_INDEX_13 13
// PACT_READ_REG_INDEX_14 14
// PACT_READ_REG_INDEX_15 15
// PACT_READ_REG_NONE 0

// reg pact_float_special_case
// BW_PACT_FLOAT_SPECIAL_CASE 3
// PACT_FLOAT_SPECIAL_CASE_NORMAL 0
// PACT_FLOAT_SPECIAL_CASE_NAN 1
// PACT_FLOAT_SPECIAL_CASE_PZERO 2
// PACT_FLOAT_SPECIAL_CASE_MZERO 3
// PACT_FLOAT_SPECIAL_CASE_PINF 4
// PACT_FLOAT_SPECIAL_CASE_MINF 5
// PACT_FLOAT_SPECIAL_CASE_INDEX_NAN 0
// PACT_FLOAT_SPECIAL_CASE_INDEX_PZERO 1
// PACT_FLOAT_SPECIAL_CASE_INDEX_PINF 2

// reg pact_data_width
// BW_PACT_DATA_WIDTH 2
// PACT_DATA_WIDTH_DATA08 0
// PACT_DATA_WIDTH_DATA16 1
// PACT_DATA_WIDTH_DATA32 2
// PACT_DATA_WIDTH_DATA64 3
// PACT_DATA_WIDTH_INDEX_DATA16 0
// PACT_DATA_WIDTH_INDEX_DATA32 1

// reg pact_cmd_op
// BW_PACT_CMD_OP 5
// PACT_CMD_OP_START_FIFO 1
// PACT_CMD_OP_INIT_RINDEX 2
// PACT_CMD_OP_START_MEM 4
// PACT_CMD_OP_SET_RINDEX 8
// PACT_CMD_OP_CLEAR_ITR 16
// PACT_CMD_OP_INDEX_START_FIFO 0
// PACT_CMD_OP_INDEX_INIT_RINDEX 1
// PACT_CMD_OP_INDEX_START_MEM 2
// PACT_CMD_OP_INDEX_SET_RINDEX 3
// PACT_CMD_OP_INDEX_CLEAR_ITR 4
// PACT_CMD_OP_NONE 0

// reg pact_inst_mem_index
// BW_PACT_INST_MEM_INDEX 8

#endif