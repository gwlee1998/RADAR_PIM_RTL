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
## 2019-04
## Kyuseung Han (han@etri.re.kr)
## ****************************************************************************
## ****************************************************************************

set FPGA_NAME arty-100t
set GENERATED_TOP_MODULE RADARPIM_FPGA

set USER_TOP_FILE ${PLATFORM_DIR}/user/fpga/${FPGA_NAME}/set_top_module.tcl
set USER_COMMON_TOP_FILE ${PLATFORM_DIR}/user/fpga/common/set_top_module.tcl
if {[file exist ${USER_TOP_FILE}]} {
	source ${USER_TOP_FILE}
} elseif {[file exist ${USER_COMMON_TOP_FILE}]} {
	source ${USER_COMMON_TOP_FILE}
} else {
	set TOP_MODULE ${GENERATED_TOP_MODULE}
}

# lappend define_list

set PROJECT_NAME [string tolower ${TOP_MODULE}]
set BIT_FILE_NAME ${PROJECT_NAME}.${FPGA_NAME}

set IMP_MODE release
#set IMP_MODE debug
