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

TEMPLATE_FILE = ${RVX_ENV}/makefile/Makefile.platform.template
include ${RVX_UTIL_HOME}/template_makefile.mh

PLATFORM_DIR = ${CURDIR}
PLATFORM_NAME = $(notdir ${PLATFORM_DIR})
RVX_WORKSPACE = $(call absolute_path,${PLATFORM_DIR}/..)

USER_DIR = ./user

APP_DIR = ./app

SIM_RTL_DIRNAME = sim_rtl
SIM_RTL_DIR = ${CURDIR}/${SIM_RTL_DIRNAME}

PLATFORM_XML_FILE=${PLATFORM_DIR}/${PLATFORM_NAME}.xml

-include ./each_platform.mh

ifndef TARGET_IMP_CLASS
ifdef FPGA_NAME
	TARGET_IMP_CLASS = ${FPGA_NAME}
endif
endif

ifndef TARGET_IMP_CLASS
ifdef DEFAULT_FPGA_NAME
	TARGET_IMP_CLASS = ${DEFAULT_FPGA_NAME}
endif
endif

ENGINE_WS=${PLATFORM_DIR}/..
ENGINE_TARGET=platform
ENGINE_CMD_LIST=user util testbench app_base system_app clean distclean syn syn_arch sim_vp sim_rtl fpga imp_fpga imp_fpga_dir gui clean_imp app_list fpga_list imp_soc wifi_config aix_config
ENGINE_PARA= -p ${PLATFORM_NAME}

ifdef TARGET_IMP_CLASS
ENGINE_PARA+= -tic ${TARGET_IMP_CLASS}
endif

ifndef IMP_INSTANCE_DIR
ifdef IMP_INSTANCE_NAME
	IMP_INSTANCE_DIR = ${PLATFORM_DIR}/${IMP_INSTANCE_NAME}
endif
endif

ifdef IMP_INSTANCE_DIR
ENGINE_PARA+= -imp_dir ${IMP_INSTANCE_DIR}
endif
include ${RVX_ENV}/engine/rvx_make2engine.mh

ifndef TEST_APP_NAME
	TEST_APP_NAME=hello
endif

all: testbench syn header sim_vp

-include ${RVX_ENV}/makefile/platform.mh
-include ${RVX_ENV}/cloud/platform.mh

FPGA_LIST = $(shell ${PYTHON3_CMD} ${RVX_UTIL_HOME}/os_util.py dir_list ${ENGINE_WS}/../imp_class_info )

${FPGA_LIST}:
	@make imp_fpga TARGET_IMP_CLASS=$@

test: clean syn sim_rtl
	@cd ./sim_rtl && make ${TEST_APP_NAME}

test_fpga: clean_imp fpga
	@cd ./imp* && make project

.PHONY: imp_fpga sim_vp_cloud

