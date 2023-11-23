#include "pim_utils.h"
#include <stdint.h>


uint32_t cmd;

static inline unsigned int get_test1_addr(unsigned int offset)
{
    return (I_TEST1_SLAVE_BASEADDR + offset);
}

static inline unsigned int get_test1_reg_addr(unsigned int offset)
{
   return (I_TEST1_SLAVE_REG_ADDR + offset);
}

uint32_t get_addr_offset(uint32_t addr){
    return addr&(MEM_MODULE_SIZE-1);
}

void wait_pim()
{
    while(!REG32(get_test1_reg_addr(OFFSET_DONE)));
}

void radar_pim_set_inst(uint64_t inst)
{
    REG64(get_test1_reg_addr(OFFSET_INST_MSB)) = inst;
}

void radar_pim_check_status()
{
    while(!REG32(get_test1_reg_addr(OFFSET_DONE)));
}
void store_copied_vector(float data, uint16_t addr)
{
    REG32F(get_test1_reg_addr(OFFSET_SW_MULTIPLE+addr)) = data;
}
void store_rshifted_vector(float data, uint16_t addr)
{
    REG32F(get_test1_reg_addr(OFFSET_SW_RSHIFTED+addr)) = data;
}
void store_lshifted_vector(float data, uint16_t addr)
{
    REG32F(get_test1_reg_addr(OFFSET_SW_LSHIFTED+addr)) = data;
}

void init_array(uint16_t start, uint16_t len, uint8_t size)
{
    uint32_t addr = (uint32_t)start;
    uint32_t end = (uint32_t) (start+size*len);
    while(addr<end){
        REG32(get_test1_reg_addr(OFFSET_SW_MULTIPLE+addr)) = 0;
        addr += 4;
    }
}

void radar_pim_inst_auto_incr(int8_t sel_oprd , int16_t num_incr, int8_t stride)
{
    cmd = PIM_INCR_CMD(sel_oprd,num_incr,stride);
    REG32(get_test1_reg_addr(OFFSET_CMD)) = cmd;
    wait_pim();
}
