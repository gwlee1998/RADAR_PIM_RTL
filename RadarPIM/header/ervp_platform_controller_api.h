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
// 2017-05
// Kyuseung Han (han@etri.re.kr)
// ****************************************************************************
// ****************************************************************************

#ifndef __ERVP_PLATFORM_CONTROLLER_API_H__
#define __ERVP_PLATFORM_CONTROLLER_API_H__

#include "ervp_mmio_util.h"
#include "platform_info.h"
#include "ervp_platform_controller_memorymap.h"

static inline int is_sim()
{
#ifdef VP_ENV
	return 1;
#else
	return REG32(MMAP_PLATFORM_REGISTER_SIM_ENV);
#endif
}

static inline int get_imp_type()
{
#ifdef VP_ENV
	return IMP_TYPE_VP;
#else
	return REG32(MMAP_PLATFORM_REGISTER_IMP_TYPE);
#endif
}

static inline int get_flash_base_addr()
{
	return REG32(MMAP_PLATFORM_REGISTER_FLASH_BASE_ADDR);
}

static inline int get_app_addr()
{
	return REG32(MMAP_PLATFORM_REGISTER_APP_ADDR);
}

static inline unsigned int get_proc_auto_id()
{
	return REG32(MMAP_PLATFORM_REGISTER_PROC_AUTO_ID);
}

int get_test_period_ms();

#endif
