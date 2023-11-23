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

TEMPLATE_FILE = ${RVX_ENV}/makefile/Makefile.imp_fpga.template
TEMPLATE_CONFIG = "PLATFORM_DIR=${RVX_MINI_HOME}/platform/RadarPIM" "PLATFORM_NAME=RadarPIM" "TARGET_IMP_CLASS=arty-100t"
include ${RVX_UTIL_HOME}/template_makefile.mh

PLATFORM_DIR = ${RVX_MINI_HOME}/platform/RadarPIM
PLATFORM_NAME = RadarPIM
TARGET_IMP_CLASS=arty-100t
OUTPUT_FILE=""

########
# both #
########

APP_NAME=None
ifndef BUILD_MODE
BUILD_MODE=release
endif

ENGINE_WS=${PLATFORM_DIR}/..
ENGINE_TARGET=imp_fpga
ENGINE_CMD_LIST=module top pll info xci path tcl clean build after_build clean_build project open imp reimp check program mcs program_flash ila ila_clean printf run_ocd connect_ocd run flash app_list dump_image display_image manual_top __project __imp
ENGINE_PARA= -p ${PLATFORM_NAME} -a ${APP_NAME} -tic ${TARGET_IMP_CLASS} -bm ${BUILD_MODE} -imp_dir ${CURDIR} -o ${OUTPUT_FILE}
include ${RVX_ENV}/engine/rvx_make2engine.mh

APP_LIST = $(shell ${PYTHON3_CMD} ${RVX_UTIL_HOME}/os_util.py dir_list ${ENGINE_WS}/${PLATFORM_NAME}/app )

#######
# ocd #
#######

$(addsuffix .build, ${APP_LIST}):%.build:
	@make build APP_NAME=$(*)

$(addsuffix .run, ${APP_LIST}):%.run:
	@make run APP_NAME=$(*)

$(addsuffix .clean, ${APP_LIST}):%.clean:
	@make clean_build APP_NAME=$(*)

$(addsuffix .reall, ${APP_LIST}):%.reall: %.clean %.all

$(addsuffix .all, ${APP_LIST}):%.all: %.run

$(addsuffix .flash, ${APP_LIST}):%.flash: %
	@make flash APP_NAME=$(*)

${APP_LIST}:%:
	@make build after_build APP_NAME=$(*)

ocd: run_ocd

telnet: connect_ocd

mcom: printf

test: program mcom hello.reall
