#ifndef __ERVP_TCU_MEMORYMAP_OFFSET_H__
#define __ERVP_TCU_MEMORYMAP_OFFSET_H__



// total
#define BW_MMAP_OFFSET_ERVP_TCU 8
#define ERVP_TCU_ADDR_INTERVAL 8
#define BW_UNUSED_ERVP_TCU 3
#define NUM_ERVP_TCU_SUBMODULE 1

// submodule tcu
#define MMAP_SUBOFFSET_TCU_REGION_VALID_LIST 0x0
#define MMAP_SUBOFFSET_TCU_REGION_START00 0x8
#define MMAP_SUBOFFSET_TCU_REGION_START01 0x10
#define MMAP_SUBOFFSET_TCU_REGION_START02 0x18
#define MMAP_SUBOFFSET_TCU_REGION_START03 0x20
#define MMAP_SUBOFFSET_TCU_REGION_START04 0x28
#define MMAP_SUBOFFSET_TCU_REGION_START05 0x30
#define MMAP_SUBOFFSET_TCU_REGION_START06 0x38
#define MMAP_SUBOFFSET_TCU_REGION_START07 0x40
#define MMAP_SUBOFFSET_TCU_REGION_LAST00 0x48
#define MMAP_SUBOFFSET_TCU_REGION_LAST01 0x50
#define MMAP_SUBOFFSET_TCU_REGION_LAST02 0x58
#define MMAP_SUBOFFSET_TCU_REGION_LAST03 0x60
#define MMAP_SUBOFFSET_TCU_REGION_LAST04 0x68
#define MMAP_SUBOFFSET_TCU_REGION_LAST05 0x70
#define MMAP_SUBOFFSET_TCU_REGION_LAST06 0x78
#define MMAP_SUBOFFSET_TCU_REGION_LAST07 0x80
#define MMAP_SUBOFFSET_TCU_REGION_OFFSET00 0x88
#define MMAP_SUBOFFSET_TCU_REGION_OFFSET01 0x90
#define MMAP_SUBOFFSET_TCU_REGION_OFFSET02 0x98
#define MMAP_SUBOFFSET_TCU_REGION_OFFSET03 0xa0
#define MMAP_SUBOFFSET_TCU_REGION_OFFSET04 0xa8
#define MMAP_SUBOFFSET_TCU_REGION_OFFSET05 0xb0
#define MMAP_SUBOFFSET_TCU_REGION_OFFSET06 0xb8
#define MMAP_SUBOFFSET_TCU_REGION_OFFSET07 0xc0

#define MMAP_OFFSET_TCU_REGION_VALID_LIST (MMAP_SUBOFFSET_TCU_REGION_VALID_LIST)
#define MMAP_OFFSET_TCU_REGION_START00 (MMAP_SUBOFFSET_TCU_REGION_START00)
#define MMAP_OFFSET_TCU_REGION_START01 (MMAP_SUBOFFSET_TCU_REGION_START01)
#define MMAP_OFFSET_TCU_REGION_START02 (MMAP_SUBOFFSET_TCU_REGION_START02)
#define MMAP_OFFSET_TCU_REGION_START03 (MMAP_SUBOFFSET_TCU_REGION_START03)
#define MMAP_OFFSET_TCU_REGION_START04 (MMAP_SUBOFFSET_TCU_REGION_START04)
#define MMAP_OFFSET_TCU_REGION_START05 (MMAP_SUBOFFSET_TCU_REGION_START05)
#define MMAP_OFFSET_TCU_REGION_START06 (MMAP_SUBOFFSET_TCU_REGION_START06)
#define MMAP_OFFSET_TCU_REGION_START07 (MMAP_SUBOFFSET_TCU_REGION_START07)
#define MMAP_OFFSET_TCU_REGION_LAST00 (MMAP_SUBOFFSET_TCU_REGION_LAST00)
#define MMAP_OFFSET_TCU_REGION_LAST01 (MMAP_SUBOFFSET_TCU_REGION_LAST01)
#define MMAP_OFFSET_TCU_REGION_LAST02 (MMAP_SUBOFFSET_TCU_REGION_LAST02)
#define MMAP_OFFSET_TCU_REGION_LAST03 (MMAP_SUBOFFSET_TCU_REGION_LAST03)
#define MMAP_OFFSET_TCU_REGION_LAST04 (MMAP_SUBOFFSET_TCU_REGION_LAST04)
#define MMAP_OFFSET_TCU_REGION_LAST05 (MMAP_SUBOFFSET_TCU_REGION_LAST05)
#define MMAP_OFFSET_TCU_REGION_LAST06 (MMAP_SUBOFFSET_TCU_REGION_LAST06)
#define MMAP_OFFSET_TCU_REGION_LAST07 (MMAP_SUBOFFSET_TCU_REGION_LAST07)
#define MMAP_OFFSET_TCU_REGION_OFFSET00 (MMAP_SUBOFFSET_TCU_REGION_OFFSET00)
#define MMAP_OFFSET_TCU_REGION_OFFSET01 (MMAP_SUBOFFSET_TCU_REGION_OFFSET01)
#define MMAP_OFFSET_TCU_REGION_OFFSET02 (MMAP_SUBOFFSET_TCU_REGION_OFFSET02)
#define MMAP_OFFSET_TCU_REGION_OFFSET03 (MMAP_SUBOFFSET_TCU_REGION_OFFSET03)
#define MMAP_OFFSET_TCU_REGION_OFFSET04 (MMAP_SUBOFFSET_TCU_REGION_OFFSET04)
#define MMAP_OFFSET_TCU_REGION_OFFSET05 (MMAP_SUBOFFSET_TCU_REGION_OFFSET05)
#define MMAP_OFFSET_TCU_REGION_OFFSET06 (MMAP_SUBOFFSET_TCU_REGION_OFFSET06)
#define MMAP_OFFSET_TCU_REGION_OFFSET07 (MMAP_SUBOFFSET_TCU_REGION_OFFSET07)

// reg tcu.region_valid_list
#define BW_TCU_REGION_VALID_LIST 8

// reg tcu.region_start
#define BW_TCU_REGION_START 32

// reg tcu.region_last
#define BW_TCU_REGION_LAST 32

// reg tcu.region_offset
#define BW_TCU_REGION_OFFSET 32

#endif