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
// 2019-04-05
// Sukho Lee (shlee99@etri.re.kr)
// ****************************************************************************
// ****************************************************************************

#ifndef __BIO_CONTROLLER_MEMORYMAP_H__
#define __BIO_CONTROLLER_MEMORYMAP_H__

// bio controller
#define BW_MMAP_OFFSET_BIO_CONTROLLER (5)
#define MMAP_SUBOFFSET_BIO_CONTROLLER_18V_EN  (0x00)
#define MMAP_SUBOFFSET_BIO_CONTROLLER_POS_PULSE   (0x04)
#define MMAP_SUBOFFSET_BIO_CONTROLLER_NEG_PULSE   (0x08)
#define MMAP_SUBOFFSET_BIO_CONTROLLER_MUX     (0x0c)
#define MMAP_SUBOFFSET_BIO_CONTROLLER_POTEN   (0x10)

#define MMAP_OFFSET_BIO_CONTROLLER_18V_EN (MMAP_SUBOFFSET_BIO_CONTROLLER_18V_EN)
#define MMAP_OFFSET_BIO_CONTROLLER_POS_PULSE  (MMAP_SUBOFFSET_BIO_CONTROLLER_POS_PULSE)
#define MMAP_OFFSET_BIO_CONTROLLER_NEG_PULSE  (MMAP_SUBOFFSET_BIO_CONTROLLER_NEG_PULSE)
#define MMAP_OFFSET_BIO_CONTROLLER_MUX    (MMAP_SUBOFFSET_BIO_CONTROLLER_MUX)
#define MMAP_OFFSET_BIO_CONTROLLER_POTEN  (MMAP_SUBOFFSET_BIO_CONTROLLER_POTEN)

#endif
