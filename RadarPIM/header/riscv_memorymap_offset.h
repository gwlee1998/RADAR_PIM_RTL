#ifndef __RISCV_MEMORYMAP_OFFSET_H__
#define __RISCV_MEMORYMAP_OFFSET_H__



// total
#define BW_MMAP_OFFSET_RISCV None
#define RISCV_ADDR_INTERVAL 8
#define BW_UNUSED_RISCV 3
#define NUM_RISCV_SUBMODULE 0

// reg rvisa_opcode
#define BW_RVISA_OPCODE 7

// reg rvisa_regindex
#define BW_RVISA_REGINDEX 5

// reg rvisa_funct3
#define BW_RVISA_FUNCT3 3

// reg rvisa_funct7
#define BW_RVISA_FUNCT7 7

// reg rvisa_shamt
#define BW_RVISA_SHAMT 5

// reg rvisa_type
#define BW_RVISA_TYPE 8
#define RVISA_TYPE_RD 1
#define RVISA_TYPE_RS1 2
#define RVISA_TYPE_RS2 4
#define RVISA_TYPE_FUNCT3 8
#define RVISA_TYPE_FUNCT7 16
#define RVISA_TYPE_IMM 32
#define RVISA_TYPE_B 64
#define RVISA_TYPE_J 128
#define RVISA_TYPE_INDEX_RD 0
#define RVISA_TYPE_INDEX_RS1 1
#define RVISA_TYPE_INDEX_RS2 2
#define RVISA_TYPE_INDEX_FUNCT3 3
#define RVISA_TYPE_INDEX_FUNCT7 4
#define RVISA_TYPE_INDEX_IMM 5
#define RVISA_TYPE_INDEX_B 6
#define RVISA_TYPE_INDEX_J 7
#define RVISA_TYPE_NONE 0

// reg rvisa_property
#define BW_RVISA_PROPERTY 8
#define RVISA_PROPERTY_VARIABLE_CYCLE 1
#define RVISA_PROPERTY_MULTI_CYCLE 2
#define RVISA_PROPERTY_WB 4
#define RVISA_PROPERTY_SIGNED_RS1 8
#define RVISA_PROPERTY_SIGNED_RS2 16
#define RVISA_PROPERTY_LOAD 32
#define RVISA_PROPERTY_STORE 64
#define RVISA_PROPERTY_SECOND_RESULT 128
#define RVISA_PROPERTY_INDEX_VARIABLE_CYCLE 0
#define RVISA_PROPERTY_INDEX_MULTI_CYCLE 1
#define RVISA_PROPERTY_INDEX_WB 2
#define RVISA_PROPERTY_INDEX_SIGNED_RS1 3
#define RVISA_PROPERTY_INDEX_SIGNED_RS2 4
#define RVISA_PROPERTY_INDEX_LOAD 5
#define RVISA_PROPERTY_INDEX_STORE 6
#define RVISA_PROPERTY_INDEX_SECOND_RESULT 7
#define RVISA_PROPERTY_NONE 0

// reg paco_writeback_property
#define BW_PACO_WRITEBACK_PROPERTY 1

// reg rvisa_opcode32
#define BW_RVISA_OPCODE32 5
#define RVISA_OPCODE32_LOAD 0
#define RVISA_OPCODE32_LOAD_FP 1
#define RVISA_OPCODE32_CUSTOM_0 2
#define RVISA_OPCODE32_MISC_MEM 3
#define RVISA_OPCODE32_OP_IMM 4
#define RVISA_OPCODE32_AUIPC 5
#define RVISA_OPCODE32_OP_IMM_32 6
#define RVISA_OPCODE32_NAN0 7
#define RVISA_OPCODE32_STORE 8
#define RVISA_OPCODE32_STORE_FP 9
#define RVISA_OPCODE32_CUSTOM_1 10
#define RVISA_OPCODE32_AMO 11
#define RVISA_OPCODE32_OP 12
#define RVISA_OPCODE32_LUI 13
#define RVISA_OPCODE32_OP_32 14
#define RVISA_OPCODE32_NAN1 15
#define RVISA_OPCODE32_MADD 16
#define RVISA_OPCODE32_MSUB 17
#define RVISA_OPCODE32_NMSUB 18
#define RVISA_OPCODE32_NMADD 19
#define RVISA_OPCODE32_OP_FP 20
#define RVISA_OPCODE32_NAN3 21
#define RVISA_OPCODE32_NAN4 22
#define RVISA_OPCODE32_NAN5 23
#define RVISA_OPCODE32_BRANCH 24
#define RVISA_OPCODE32_JALR 25
#define RVISA_OPCODE32_NAN6 26
#define RVISA_OPCODE32_JAL 27
#define RVISA_OPCODE32_SYSTEM 28
#define RVISA_OPCODE32_NAN7 29
#define RVISA_OPCODE32_NAN8 30
#define RVISA_OPCODE32_NAN9 31
#define RVISA_OPCODE32_INDEX_LOAD_FP 0
#define RVISA_OPCODE32_INDEX_CUSTOM_0 1
#define RVISA_OPCODE32_INDEX_OP_IMM 2
#define RVISA_OPCODE32_INDEX_STORE 3
#define RVISA_OPCODE32_INDEX_MADD 4

// reg rvisa_bcond
#define BW_RVISA_BCOND 2
#define RVISA_BCOND_EQ 0
#define RVISA_BCOND_NE 1
#define RVISA_BCOND_LT 2
#define RVISA_BCOND_GE 3
#define RVISA_BCOND_INDEX_NE 0
#define RVISA_BCOND_INDEX_LT 1

// reg paco_datasize
#define BW_PACO_DATASIZE 2
#define PACO_DATASIZE_BYTE 0
#define PACO_DATASIZE_HALFWORD 1
#define PACO_DATASIZE_WORD 2
#define PACO_DATASIZE_INDEX_HALFWORD 0
#define PACO_DATASIZE_INDEX_WORD 1

// reg paco_imm
#define BW_PACO_IMM 32

// reg paco_arbiter_source
#define BW_PACO_ARBITER_SOURCE 3
#define PACO_ARBITER_SOURCE_LOAD 1
#define PACO_ARBITER_SOURCE_DIV 2
#define PACO_ARBITER_SOURCE_FIXED 4
#define PACO_ARBITER_SOURCE_INDEX_LOAD 0
#define PACO_ARBITER_SOURCE_INDEX_DIV 1
#define PACO_ARBITER_SOURCE_INDEX_FIXED 2
#define PACO_ARBITER_SOURCE_NONE 0

// reg paco_reg_read_state
#define BW_PACO_REG_READ_STATE 7
#define PACO_REG_READ_STATE_RF 1
#define PACO_REG_READ_STATE_FQ 2
#define PACO_REG_READ_STATE_SC 4
#define PACO_REG_READ_STATE_WB 8
#define PACO_REG_READ_STATE_FMC 16
#define PACO_REG_READ_STATE_VC 32
#define PACO_REG_READ_STATE_ZERO 64
#define PACO_REG_READ_STATE_INDEX_RF 0
#define PACO_REG_READ_STATE_INDEX_FQ 1
#define PACO_REG_READ_STATE_INDEX_SC 2
#define PACO_REG_READ_STATE_INDEX_WB 3
#define PACO_REG_READ_STATE_INDEX_FMC 4
#define PACO_REG_READ_STATE_INDEX_VC 5
#define PACO_REG_READ_STATE_INDEX_ZERO 6
#define PACO_REG_READ_STATE_NONE 0

// reg paco_fq_source
#define BW_PACO_FQ_SOURCE 2
#define PACO_FQ_SOURCE_SC 1
#define PACO_FQ_SOURCE_MULT 2
#define PACO_FQ_SOURCE_INDEX_SC 0
#define PACO_FQ_SOURCE_INDEX_MULT 1
#define PACO_FQ_SOURCE_NONE 0

// reg paco_result_source
#define BW_PACO_RESULT_SOURCE 8
#define PACO_RESULT_SOURCE_DADD 1
#define PACO_RESULT_SOURCE_IMM 2
#define PACO_RESULT_SOURCE_NEXT_PC 4
#define PACO_RESULT_SOURCE_LOGICAL 8
#define PACO_RESULT_SOURCE_PADD 16
#define PACO_RESULT_SOURCE_COMPARE 32
#define PACO_RESULT_SOURCE_SHIFTER 64
#define PACO_RESULT_SOURCE_CSR 128
#define PACO_RESULT_SOURCE_INDEX_DADD 0
#define PACO_RESULT_SOURCE_INDEX_IMM 1
#define PACO_RESULT_SOURCE_INDEX_NEXT_PC 2
#define PACO_RESULT_SOURCE_INDEX_LOGICAL 3
#define PACO_RESULT_SOURCE_INDEX_PADD 4
#define PACO_RESULT_SOURCE_INDEX_COMPARE 5
#define PACO_RESULT_SOURCE_INDEX_SHIFTER 6
#define PACO_RESULT_SOURCE_INDEX_CSR 7
#define PACO_RESULT_SOURCE_NONE 0

// reg paco_lsu_response_source
#define BW_PACO_LSU_RESPONSE_SOURCE 4
#define PACO_LSU_RESPONSE_SOURCE_DIRECT 1
#define PACO_LSU_RESPONSE_SOURCE_LSU0 2
#define PACO_LSU_RESPONSE_SOURCE_LSU1 4
#define PACO_LSU_RESPONSE_SOURCE_DMEM 8
#define PACO_LSU_RESPONSE_SOURCE_INDEX_DIRECT 0
#define PACO_LSU_RESPONSE_SOURCE_INDEX_LSU0 1
#define PACO_LSU_RESPONSE_SOURCE_INDEX_LSU1 2
#define PACO_LSU_RESPONSE_SOURCE_INDEX_DMEM 3
#define PACO_LSU_RESPONSE_SOURCE_NONE 0

// reg paco_csr_addr
#define BW_PACO_CSR_ADDR 12
#define PACO_CSR_ADDR_STOP_REQUEST 3264
#define PACO_CSR_ADDR_CORECACHE_COMMAND 3265
#define PACO_CSR_ADDR_LSU_BUSY 3268
#define PACO_CSR_ADDR_CORECACHE_BUSY 3269
#define PACO_CSR_ADDR_MEMORY_START 2048
#define PACO_CSR_ADDR_MEMORY_LAST 2049
#define PACO_CSR_ADDR_DCACHE_START 2050
#define PACO_CSR_ADDR_DCACHE_LAST 2051
#define PACO_CSR_ADDR_LSU0_START 2052
#define PACO_CSR_ADDR_LSU0_LAST 2053
#define PACO_CSR_ADDR_MSTATUS 768
#define PACO_CSR_ADDR_MIE 772
#define PACO_CSR_ADDR_INDEX_MEMORY_START 11

#endif