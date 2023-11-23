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

TEMPLATE_FILE = ${RVX_ENV}/makefile/Makefile.app.template
include ${RVX_UTIL_HOME}/template_makefile.mh

PLATFORM_DIR = $(call absolute_path,${CURDIR}/../..)
PLATFORM_NAME = $(notdir ${PLATFORM_DIR})

APP_NAME = $(notdir ${CURDIR})

TARGET_IMP_CLASS=vp
BUILD_MODE=release
BUILD_MODE_LIST=release debug

ENGINE_WS=${PLATFORM_DIR}/..
ENGINE_TARGET=app
ENGINE_CMD_LIST=build clean run debugger.start debugger.stop debug path build_dir compile_list compile compile_incremental wifi_config aix_config local_ssw wifi_ssw aix_ssw
ENGINE_PARA= -p ${PLATFORM_NAME} -a ${APP_NAME} -tic ${TARGET_IMP_CLASS} -bm ${BUILD_MODE}
include ${RVX_ENV}/engine/rvx_make2engine.mh

FPGA_LIST = $(shell ${PYTHON3_CMD} ${RVX_UTIL_HOME}/os_util.py dir_list ${ENGINE_WS}/../imp_class_info )
IMP_LIST = vp rtl ${FPGA_LIST}

${IMP_LIST}:
	@make build TARGET_IMP_CLASS=$@ BUILD_MODE=release

test:
	@make build TARGET_IMP_CLASS=vp BUILD_MODE=release
	@cd vp.release; make run
	
