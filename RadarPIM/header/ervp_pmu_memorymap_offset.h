// ****************************************************************************
// ****************************************************************************
// Copyright SoC Design Research Group, All rights reserved.
// Electronics and Telecommunications Research Institute (ETRI)
// 
// THESE DOCUMENTS CONTAIN CONFIDENTIAL INFORMATION AND KNOWLEDGE
// WHICH IS THE PROPERTY OF ETRI. NO PART OF THIS PUBLICATION IS
// TO BE USED FOR ANY OTHER PURPOSE, AND THESE ARE NOT TO BE
// REPRODUCED, COPIED, DISCLOSED, TRANSMITTED, STORED IN A RETRIEVAL
// SYSTEM OR TRANSLATED INTO ANY OTHER HUMAN OR COMPUTER LANGUAGE,
// IN ANY FORM, BY ANY MEANS, IN WHOLE OR IN PART, WITHOUT THE
// COMPLETE PRIOR WRITTEN PERMISSION OF ETRI.
// ****************************************************************************
// 2018-03-28
// Kyuseung Han (han@etri.re.kr)
// ****************************************************************************
// ****************************************************************************

#ifndef __ERVP_PMU_MEMORYMAP_H__
#define __ERVP_PMU_MEMORYMAP_H__

// pmu
#define BW_MMAP_OFFSET_PMU (3)
#define MMAP_SUBOFFSET_PMU_CMD (0x0)
#define MMAP_SUBOFFSET_PMU_TIME (0x4)

#define MMAP_OFFSET_PMU_CMD (MMAP_SUBOFFSET_PMU_CMD)
#define MMAP_OFFSET_PMU_TIME (MMAP_SUBOFFSET_PMU_TIME)

#define BW_POWER_STATE (2)
#define POWER_STATE_IDLE (0)
#define POWER_STATE_SLEEP_ITR (1)
#define POWER_STATE_SLEEP_TIMER (2)
#define POWER_STATE_SLLEP_BOTH (3)

#endif