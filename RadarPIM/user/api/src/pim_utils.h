#ifndef __PIM_UTLS_H__
#define __PIM_UTLS_H__
#include <stdint.h>
#include "platform_info.h"
#include "ervp_reg_util.h"

#define NUM_UNIT 8
#define MEM_MODULE_SIZE ((I_TEST1_SLAVE_SIZE/2)/NUM_UNIT)

#define I_TEST1_SLAVE_REG_ADDR (I_TEST1_SLAVE_BASEADDR+(I_TEST1_SLAVE_SIZE/2))
#define OFFSET_INST_MSB (0X0)
#define OFFSET_INST_LSB (0X4)
#define OFFSET_CMD 0X10
#define OFFSET_INCR 0X14
#define OFFSET_STRIDE 0X18
#define OFFSET_DONE 0x20


#define PIM_ARRAY(BANK_NUM, WADDR) REG32(I_TEST1_SLAVE_BASEADDR+(MEM_MODULE_SIZE*BANK_NUM) + WADDR)

#define SET_INST(PINST) REG64(I_TEST1_SLAVE_BASEADDR + OFFSET_INST_MSB) = PINST
#define OFFSET_SW_MULTIPLE 1*MEM_MODULE_SIZE
#define OFFSET_SW_RSHIFTED 2*MEM_MODULE_SIZE
#define OFFSET_SW_LSHIFTED 3*MEM_MODULE_SIZE


#define INST(SEL,OPCODE,DEST,OP1,OP2) ((((((uint64_t)SEL)<<24)|(((uint64_t)OPCODE)<<16))|((uint64_t)DEST))|((((uint64_t)OP1)<<16|((uint64_t)OP2))<<32))

#define PIM_INCR_CMD(SEL_OPRD, num_incr, stride) ((1<<31)|(SEL_OPRD<<24)|(num_incr<<8)|stride)
#define PIM_INST_MOVE_INT(SEL,DEST,OP1) INST(SEL,0x00,DEST,OP1,0)
#define PIM_INST_FL_MULT(SEL, DEST, OP1, OP2) INST(SEL,0x48,DEST,OP1,OP2)
#define PIM_INST_FL_SUB(SEL, DEST, OP1, OP2) INST(SEL,0x44,DEST,OP1,OP2)
#define PIM_INST_FL_ADD(SEL, DEST, OP1, OP2) INST(SEL,0x40,DEST,OP1,OP2)
#define PIM_INST_MAC(SEL, DEST, OP1, OP2) INST(SEL,0x58,DEST,OP1,OP2)
#define PIM_INST_MAC_ACC(SEL, OP1, OP2) INST(SEL,0x58,MEM_MODULE_SIZE+4,OP1,OP2)
#define PIM_INST_ACC_CLEAR(SEL) INST(SEL,0x00,MEM_MODULE_SIZE+4,MEM_MODULE_SIZE,0)
#define PIM_INST_ACC_GET(SEL, DEST) INST(SEL,0x00,DEST,MEM_MODULE_SIZE+4,0)
#define NABI_CAL(SEL, DEST, OP1, OP2) INST(SEL,0x50,DEST,OP1,OP2)
#define NABI_MOVE(SEL, DEST, RADDR, SS) INST(SEL,0x54,DEST,RADDR,SS)

#define REG32F(add) *((volatile float*)(add))
#define PIM_PTR(BANK_NUM, RADDR) (float*)(I_TEST1_SLAVE_BASEADDR+(MEM_MODULE_SIZE*BANK_NUM) + RADDR)


#define PIM_ARRAY(BANK_NUM, ADDR) REG32(get_pim_addr((MEM_MODULE_SIZE*BANK_NUM) + ADDR))
#define PIM_ARRAY_FL(BANK_NUM, ADDR) REG32F(get_pim_addr((MEM_MODULE_SIZE*BANK_NUM) + ADDR))
static inline unsigned int get_pim_addr(int offset){
    return (I_TEST1_SLAVE_BASEADDR + offset);
};
void radar_pim_set_inst(uint64_t inst);
void wait_pim();
void radar_pim_check_status();
void radar_pim_inst_auto_incr(int8_t sel_oprd , int16_t num_incr, int8_t stride);
void store_copied_vector(float data, uint16_t addr);
void store_rshifted_vector(float data, uint16_t addr);
void store_lshifted_vector(float data, uint16_t addr);
void init_array(uint16_t start, uint16_t len, uint8_t size);
uint32_t get_addr_offset(uint32_t addr);

#endif