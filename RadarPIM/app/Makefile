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

TEMPLATE_FILE = ${RVX_ENV}/makefile/Makefile.app_base.template
include ${RVX_UTIL_HOME}/template_makefile.mh

PLATFORM_DIR = $(call absolute_path,${CURDIR}/..)
PLATFORM_NAME = $(notdir ${PLATFORM_DIR})
RVX_WORKSPACE = $(call absolute_path,${PLATFORM_DIR}/..)

ifndef APP_NAME
	APP_NAME=Base
endif

ENGINE_WS=${PLATFORM_DIR}/..
ENGINE_TARGET=app
ENGINE_CMD_LIST=new delete clean eclipse
ENGINE_PARA= -p ${PLATFORM_NAME} -a ${APP_NAME}
include ${RVX_ENV}/engine/rvx_make2engine.mh

APP_BASE_DIR=${CURDIR}
-include ${RVX_ENV}/dev/rvx_dev_util.mh
