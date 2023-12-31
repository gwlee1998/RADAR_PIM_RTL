#ifndef __ERVP_COMMON_PERI_GROUP_MEMORYMAP_OFFSET_H__
#define __ERVP_COMMON_PERI_GROUP_MEMORYMAP_OFFSET_H__



// total
#define BW_MMAP_OFFSET_ERVP_COMMON_PERI_GROUP 15
#define ERVP_COMMON_PERI_GROUP_ADDR_INTERVAL 8
#define BW_UNUSED_ERVP_COMMON_PERI_GROUP 3
#define NUM_ERVP_COMMON_PERI_GROUP_SUBMODULE 5
#define SUBMODULE_INDEX_ERVP_COMMON_PERI_GROUP_IROM 0
#define SUBMODULE_ADDR_ERVP_COMMON_PERI_GROUP_IROM 0x0
#define SUBMODULE_INDEX_ERVP_COMMON_PERI_GROUP_LOCK 1
#define SUBMODULE_ADDR_ERVP_COMMON_PERI_GROUP_LOCK 0x1000
#define SUBMODULE_INDEX_ERVP_COMMON_PERI_GROUP_AUTO_ID 2
#define SUBMODULE_ADDR_ERVP_COMMON_PERI_GROUP_AUTO_ID 0x2000
#define SUBMODULE_INDEX_ERVP_COMMON_PERI_GROUP_CPG_MISC 3
#define SUBMODULE_ADDR_ERVP_COMMON_PERI_GROUP_CPG_MISC 0x3000
#define SUBMODULE_INDEX_ERVP_COMMON_PERI_GROUP_REAL_CLOCK 4
#define SUBMODULE_ADDR_ERVP_COMMON_PERI_GROUP_REAL_CLOCK 0x4000

// submodule irom
#define BW_MMAP_SUBOFFSET_IROM 12
#define BW_UNUSED_IROM 3


// submodule lock
#define BW_MMAP_SUBOFFSET_LOCK 12
#define BW_UNUSED_LOCK 3


// submodule auto_id
#define BW_MMAP_SUBOFFSET_AUTO_ID 12
#define BW_UNUSED_AUTO_ID 3


// submodule cpg_misc
#define BW_MMAP_SUBOFFSET_CPG_MISC 5
#define BW_UNUSED_CPG_MISC 3
#define MMAP_SUBOFFSET_CPG_MISC_GLOBAL_TAG 0x0
#define MMAP_SUBOFFSET_CPG_MISC_SYSTEM_TICK_CONFIG 0x8
#define MMAP_SUBOFFSET_CPG_MISC_CORE_TICK_CONFIG 0x10

#define MMAP_OFFSET_CPG_MISC_GLOBAL_TAG (SUBMODULE_ADDR_ERVP_COMMON_PERI_GROUP_CPG_MISC+MMAP_SUBOFFSET_CPG_MISC_GLOBAL_TAG)
#define MMAP_OFFSET_CPG_MISC_SYSTEM_TICK_CONFIG (SUBMODULE_ADDR_ERVP_COMMON_PERI_GROUP_CPG_MISC+MMAP_SUBOFFSET_CPG_MISC_SYSTEM_TICK_CONFIG)
#define MMAP_OFFSET_CPG_MISC_CORE_TICK_CONFIG (SUBMODULE_ADDR_ERVP_COMMON_PERI_GROUP_CPG_MISC+MMAP_SUBOFFSET_CPG_MISC_CORE_TICK_CONFIG)

// submodule real_clock
#define BW_MMAP_SUBOFFSET_REAL_CLOCK 4
#define BW_UNUSED_REAL_CLOCK 3


// reg cpg_misc.global_tag
#define BW_CPG_MISC_GLOBAL_TAG 8

// reg cpg_misc.system_tick_config
#define BW_CPG_MISC_SYSTEM_TICK_CONFIG 11

// reg cpg_misc.core_tick_config
#define BW_CPG_MISC_CORE_TICK_CONFIG 11

#endif