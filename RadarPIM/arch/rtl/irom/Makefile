## ****************************************************************************
## ****************************************************************************
## Copyright SoC Design Research Group, All rights reserved.    
## Electronics and Telecommunications Research Institute (ETRI)
##
## THESE DOCUMENTS CONTAIN CONFIDENTIAL INFORMATION AND KNOWLEDGE 
## WHICH IS THE PROPERTY OF ETRI. NO PART OF THIS PUBLICATION IS 
## TO BE USED FOR ANY OTHER PURPOSE, AND THESE ARE NOT TO BE 
## REPRODUCED, COPIED, DISCLOSED, TRANSMITTED, STORED IN A RETRIEVAL 
## SYSTEM OR TRANSLATED INTO ANY OTHER HUMAN OR COMPUTER LANGUAGE, 
## IN ANY FORM, BY ANY MEANS, IN WHOLE OR IN PART, WITHOUT THE 
## COMPLETE PRIOR WRITTEN PERMISSION OF ETRI.
## ****************************************************************************
## 2019-04-15
## Kyuseung Han (han@etri.re.kr)
## ****************************************************************************
## ****************************************************************************

ifdef RVX_MINI_HOME
	include ${RVX_MINI_HOME}/rvx_config.mh
else
	include ${RVX_DEVKIT_HOME}/rvx_config.mh
endif

ORIGINAL_FILE_LIST=./Makefile
include ${RVX_UTIL_HOME}/distclean.mh

include ${RVX_SSW_HOME}/core/orca/set_env.mh
include ${RVX_SSW_HOME}/api/munoc/env/set_env.mh
include ${RVX_SSW_HOME}/api/platform_controller/env/set_env.mh
INCLUDES += -I${RVX_SSW_HOME}/memorymap

INFO_DIR = ../../ssw/include
RESULT_DIR = ../../rtl/include

CFLAGS += -Os
INCLUDES += -I${INFO_DIR}

all: compile_irom gen_irom_header

compile_irom:
	@$(CC) $(CFLAGS) $(INCLUDES) -c ${RVX_SSW_HOME}/irom/general_irom.S -o irom.elf
	@$(OBJDUMP) -D irom.elf > irom.dump
	@$(CROSS_COMPILE)strip -O binary irom.elf -o irom.bin
	@xxd -c4 -g4 -ps irom.bin > irom.hex

gen_irom_header:
	@${PYTHON3_CMD} ${RVX_UTIL_HOME}/generate_rom_header.py -hex_file irom.hex -hex_be -width 32 -p irom -od ${RESULT_DIR}

clean_irom_header:
	-@rm -rf ${RESULT_DIR}/irom_contents.vh ${RESULT_DIR}/irom_capacity.vh

clean: distclean
