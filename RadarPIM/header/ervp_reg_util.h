#ifndef __ERVP_REG_UTIL_H__
#define __ERVP_REG_UTIL_H__

#include <stdint.h>

#define REG8(add) *((volatile uint8_t *)(add))  
#define REG16(add) *((volatile uint16_t *)(add))
#define REG32(add) *((volatile uint32_t *)(add))
#define REG64(add) *((volatile uint64_t *)(add))

#endif
