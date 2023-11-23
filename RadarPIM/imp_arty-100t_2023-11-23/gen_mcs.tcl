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
## 2019-10-01
## Kyuseung Han (han@etri.re.kr)
## ****************************************************************************
## ****************************************************************************

set define_list {}

source ./set_path.tcl
source ./set_design.tcl
source ${RVX_ENV}/xilinx/__set_env.tcl

write_cfgmem -format mcs -interface spix4 -size 4 -loadbit "up 0x0 ${IMP_RESULT_DIR}/${BIT_FILE_NAME}.bit" -file ${IMP_RESULT_DIR}/${BIT_FILE_NAME}.mcs -force
