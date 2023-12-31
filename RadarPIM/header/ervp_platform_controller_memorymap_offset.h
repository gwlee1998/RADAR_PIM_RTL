#ifndef __ERVP_PLATFORM_CONTROLLER_MEMORYMAP_OFFSET_H__
#define __ERVP_PLATFORM_CONTROLLER_MEMORYMAP_OFFSET_H__



// total
#define BW_MMAP_OFFSET_ERVP_PLATFORM_CONTROLLER 18
#define ERVP_PLATFORM_CONTROLLER_ADDR_INTERVAL 8
#define BW_UNUSED_ERVP_PLATFORM_CONTROLLER 3
#define NUM_ERVP_PLATFORM_CONTROLLER_SUBMODULE 4
#define SUBMODULE_INDEX_ERVP_PLATFORM_CONTROLLER_RESET 0
#define SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_RESET 0x0
#define SUBMODULE_INDEX_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER 1
#define SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER 0x10000
#define SUBMODULE_INDEX_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO 2
#define SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO 0x20000
#define SUBMODULE_INDEX_ERVP_PLATFORM_CONTROLLER_EXTERNAL 3
#define SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_EXTERNAL 0x30000

// submodule reset
#define BW_MMAP_SUBOFFSET_RESET 5
#define BW_UNUSED_RESET 3
#define MMAP_SUBOFFSET_RESET_CMD 0x0
#define MMAP_SUBOFFSET_RESET_MASK 0x8
#define MMAP_SUBOFFSET_RESET_SEQUENCE 0x10

#define MMAP_OFFSET_RESET_CMD (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_RESET+MMAP_SUBOFFSET_RESET_CMD)
#define MMAP_OFFSET_RESET_MASK (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_RESET+MMAP_SUBOFFSET_RESET_MASK)
#define MMAP_OFFSET_RESET_SEQUENCE (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_RESET+MMAP_SUBOFFSET_RESET_SEQUENCE)

// submodule platform_register
#define BW_MMAP_SUBOFFSET_PLATFORM_REGISTER 8
#define BW_UNUSED_PLATFORM_REGISTER 3
#define MMAP_SUBOFFSET_PLATFORM_REGISTER_BOOT_MODE 0x0
#define MMAP_SUBOFFSET_PLATFORM_REGISTER_INITIALIZED 0x8
#define MMAP_SUBOFFSET_PLATFORM_REGISTER_SIM_ENV 0x10
#define MMAP_SUBOFFSET_PLATFORM_REGISTER_JTAG_SELECT 0x18
#define MMAP_SUBOFFSET_PLATFORM_REGISTER_BOOT_STATUS 0x20
#define MMAP_SUBOFFSET_PLATFORM_REGISTER_APP_ADDR 0x28
#define MMAP_SUBOFFSET_PLATFORM_REGISTER_PROC_AUTO_ID 0x30
#define MMAP_SUBOFFSET_PLATFORM_REGISTER_PROC_STATUS 0x38
#define MMAP_SUBOFFSET_PLATFORM_REGISTER_CORE_PC00 0x40
#define MMAP_SUBOFFSET_PLATFORM_REGISTER_CORE_PC01 0x48
#define MMAP_SUBOFFSET_PLATFORM_REGISTER_CORE_PC02 0x50
#define MMAP_SUBOFFSET_PLATFORM_REGISTER_CORE_PC03 0x58
#define MMAP_SUBOFFSET_PLATFORM_REGISTER_CORE_INST00 0x60
#define MMAP_SUBOFFSET_PLATFORM_REGISTER_CORE_INST01 0x68
#define MMAP_SUBOFFSET_PLATFORM_REGISTER_CORE_INST02 0x70
#define MMAP_SUBOFFSET_PLATFORM_REGISTER_CORE_INST03 0x78
#define MMAP_SUBOFFSET_PLATFORM_REGISTER_IMP_TYPE 0x80
#define MMAP_SUBOFFSET_PLATFORM_REGISTER_FLASH_BASE_ADDR 0x88

#define MMAP_OFFSET_PLATFORM_REGISTER_BOOT_MODE (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER+MMAP_SUBOFFSET_PLATFORM_REGISTER_BOOT_MODE)
#define MMAP_OFFSET_PLATFORM_REGISTER_INITIALIZED (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER+MMAP_SUBOFFSET_PLATFORM_REGISTER_INITIALIZED)
#define MMAP_OFFSET_PLATFORM_REGISTER_SIM_ENV (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER+MMAP_SUBOFFSET_PLATFORM_REGISTER_SIM_ENV)
#define MMAP_OFFSET_PLATFORM_REGISTER_JTAG_SELECT (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER+MMAP_SUBOFFSET_PLATFORM_REGISTER_JTAG_SELECT)
#define MMAP_OFFSET_PLATFORM_REGISTER_BOOT_STATUS (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER+MMAP_SUBOFFSET_PLATFORM_REGISTER_BOOT_STATUS)
#define MMAP_OFFSET_PLATFORM_REGISTER_APP_ADDR (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER+MMAP_SUBOFFSET_PLATFORM_REGISTER_APP_ADDR)
#define MMAP_OFFSET_PLATFORM_REGISTER_PROC_AUTO_ID (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER+MMAP_SUBOFFSET_PLATFORM_REGISTER_PROC_AUTO_ID)
#define MMAP_OFFSET_PLATFORM_REGISTER_PROC_STATUS (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER+MMAP_SUBOFFSET_PLATFORM_REGISTER_PROC_STATUS)
#define MMAP_OFFSET_PLATFORM_REGISTER_CORE_PC00 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER+MMAP_SUBOFFSET_PLATFORM_REGISTER_CORE_PC00)
#define MMAP_OFFSET_PLATFORM_REGISTER_CORE_PC01 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER+MMAP_SUBOFFSET_PLATFORM_REGISTER_CORE_PC01)
#define MMAP_OFFSET_PLATFORM_REGISTER_CORE_PC02 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER+MMAP_SUBOFFSET_PLATFORM_REGISTER_CORE_PC02)
#define MMAP_OFFSET_PLATFORM_REGISTER_CORE_PC03 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER+MMAP_SUBOFFSET_PLATFORM_REGISTER_CORE_PC03)
#define MMAP_OFFSET_PLATFORM_REGISTER_CORE_INST00 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER+MMAP_SUBOFFSET_PLATFORM_REGISTER_CORE_INST00)
#define MMAP_OFFSET_PLATFORM_REGISTER_CORE_INST01 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER+MMAP_SUBOFFSET_PLATFORM_REGISTER_CORE_INST01)
#define MMAP_OFFSET_PLATFORM_REGISTER_CORE_INST02 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER+MMAP_SUBOFFSET_PLATFORM_REGISTER_CORE_INST02)
#define MMAP_OFFSET_PLATFORM_REGISTER_CORE_INST03 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER+MMAP_SUBOFFSET_PLATFORM_REGISTER_CORE_INST03)
#define MMAP_OFFSET_PLATFORM_REGISTER_IMP_TYPE (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER+MMAP_SUBOFFSET_PLATFORM_REGISTER_IMP_TYPE)
#define MMAP_OFFSET_PLATFORM_REGISTER_FLASH_BASE_ADDR (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_PLATFORM_REGISTER+MMAP_SUBOFFSET_PLATFORM_REGISTER_FLASH_BASE_ADDR)

// submodule design_info
#define BW_MMAP_SUBOFFSET_DESIGN_INFO 8
#define BW_UNUSED_DESIGN_INFO 3
#define MMAP_SUBOFFSET_DESIGN_INFO_DATE00 0x0
#define MMAP_SUBOFFSET_DESIGN_INFO_DATE01 0x8
#define MMAP_SUBOFFSET_DESIGN_INFO_DATE02 0x10
#define MMAP_SUBOFFSET_DESIGN_INFO_DATE03 0x18
#define MMAP_SUBOFFSET_DESIGN_INFO_DATE04 0x20
#define MMAP_SUBOFFSET_DESIGN_INFO_DATE05 0x28
#define MMAP_SUBOFFSET_DESIGN_INFO_DATE06 0x30
#define MMAP_SUBOFFSET_DESIGN_INFO_DATE07 0x38
#define MMAP_SUBOFFSET_DESIGN_INFO_USERNAME00 0x40
#define MMAP_SUBOFFSET_DESIGN_INFO_USERNAME01 0x48
#define MMAP_SUBOFFSET_DESIGN_INFO_USERNAME02 0x50
#define MMAP_SUBOFFSET_DESIGN_INFO_USERNAME03 0x58
#define MMAP_SUBOFFSET_DESIGN_INFO_HOME_GIT_NAME00 0x60
#define MMAP_SUBOFFSET_DESIGN_INFO_HOME_GIT_NAME01 0x68
#define MMAP_SUBOFFSET_DESIGN_INFO_HOME_GIT_NAME02 0x70
#define MMAP_SUBOFFSET_DESIGN_INFO_HOME_GIT_NAME03 0x78
#define MMAP_SUBOFFSET_DESIGN_INFO_PLATFORM_NAME00 0x80
#define MMAP_SUBOFFSET_DESIGN_INFO_PLATFORM_NAME01 0x88
#define MMAP_SUBOFFSET_DESIGN_INFO_PLATFORM_NAME02 0x90
#define MMAP_SUBOFFSET_DESIGN_INFO_PLATFORM_NAME03 0x98
#define MMAP_SUBOFFSET_DESIGN_INFO_HOME_GIT_VERSION00 0xa0
#define MMAP_SUBOFFSET_DESIGN_INFO_HOME_GIT_VERSION01 0xa8
#define MMAP_SUBOFFSET_DESIGN_INFO_HOME_GIT_VERSION02 0xb0
#define MMAP_SUBOFFSET_DESIGN_INFO_HOME_GIT_VERSION03 0xb8
#define MMAP_SUBOFFSET_DESIGN_INFO_DEVKIT_GIT_VERSION00 0xc0
#define MMAP_SUBOFFSET_DESIGN_INFO_DEVKIT_GIT_VERSION01 0xc8
#define MMAP_SUBOFFSET_DESIGN_INFO_DEVKIT_GIT_VERSION02 0xd0
#define MMAP_SUBOFFSET_DESIGN_INFO_DEVKIT_GIT_VERSION03 0xd8

#define MMAP_OFFSET_DESIGN_INFO_DATE00 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_DATE00)
#define MMAP_OFFSET_DESIGN_INFO_DATE01 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_DATE01)
#define MMAP_OFFSET_DESIGN_INFO_DATE02 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_DATE02)
#define MMAP_OFFSET_DESIGN_INFO_DATE03 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_DATE03)
#define MMAP_OFFSET_DESIGN_INFO_DATE04 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_DATE04)
#define MMAP_OFFSET_DESIGN_INFO_DATE05 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_DATE05)
#define MMAP_OFFSET_DESIGN_INFO_DATE06 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_DATE06)
#define MMAP_OFFSET_DESIGN_INFO_DATE07 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_DATE07)
#define MMAP_OFFSET_DESIGN_INFO_USERNAME00 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_USERNAME00)
#define MMAP_OFFSET_DESIGN_INFO_USERNAME01 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_USERNAME01)
#define MMAP_OFFSET_DESIGN_INFO_USERNAME02 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_USERNAME02)
#define MMAP_OFFSET_DESIGN_INFO_USERNAME03 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_USERNAME03)
#define MMAP_OFFSET_DESIGN_INFO_HOME_GIT_NAME00 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_HOME_GIT_NAME00)
#define MMAP_OFFSET_DESIGN_INFO_HOME_GIT_NAME01 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_HOME_GIT_NAME01)
#define MMAP_OFFSET_DESIGN_INFO_HOME_GIT_NAME02 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_HOME_GIT_NAME02)
#define MMAP_OFFSET_DESIGN_INFO_HOME_GIT_NAME03 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_HOME_GIT_NAME03)
#define MMAP_OFFSET_DESIGN_INFO_PLATFORM_NAME00 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_PLATFORM_NAME00)
#define MMAP_OFFSET_DESIGN_INFO_PLATFORM_NAME01 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_PLATFORM_NAME01)
#define MMAP_OFFSET_DESIGN_INFO_PLATFORM_NAME02 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_PLATFORM_NAME02)
#define MMAP_OFFSET_DESIGN_INFO_PLATFORM_NAME03 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_PLATFORM_NAME03)
#define MMAP_OFFSET_DESIGN_INFO_HOME_GIT_VERSION00 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_HOME_GIT_VERSION00)
#define MMAP_OFFSET_DESIGN_INFO_HOME_GIT_VERSION01 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_HOME_GIT_VERSION01)
#define MMAP_OFFSET_DESIGN_INFO_HOME_GIT_VERSION02 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_HOME_GIT_VERSION02)
#define MMAP_OFFSET_DESIGN_INFO_HOME_GIT_VERSION03 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_HOME_GIT_VERSION03)
#define MMAP_OFFSET_DESIGN_INFO_DEVKIT_GIT_VERSION00 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_DEVKIT_GIT_VERSION00)
#define MMAP_OFFSET_DESIGN_INFO_DEVKIT_GIT_VERSION01 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_DEVKIT_GIT_VERSION01)
#define MMAP_OFFSET_DESIGN_INFO_DEVKIT_GIT_VERSION02 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_DEVKIT_GIT_VERSION02)
#define MMAP_OFFSET_DESIGN_INFO_DEVKIT_GIT_VERSION03 (SUBMODULE_ADDR_ERVP_PLATFORM_CONTROLLER_DESIGN_INFO+MMAP_SUBOFFSET_DESIGN_INFO_DEVKIT_GIT_VERSION03)

// submodule external
#define BW_MMAP_SUBOFFSET_EXTERNAL 16
#define BW_UNUSED_EXTERNAL 3


// reg reset.cmd
#define BW_RESET_CMD 3
#define RESET_CMD_IDLE 0
#define RESET_CMD_INIT 1
#define RESET_CMD_AUTO_INCR 2
#define RESET_CMD_NEXT_STEP 3
#define RESET_CMD_IDLE_WITH_ERROR 4
#define RESET_CMD_INDEX_INIT 0
#define RESET_CMD_INDEX_AUTO_INCR 1
#define RESET_CMD_INDEX_IDLE_WITH_ERROR 2

// reg reset.mask
#define BW_RESET_MASK 32

// reg reset.sequence
#define BW_RESET_SEQUENCE 32

// reg platform_register.boot_mode
#define BW_PLATFORM_REGISTER_BOOT_MODE 4

// reg platform_register.initialized
#define BW_PLATFORM_REGISTER_INITIALIZED 1

// reg platform_register.sim_env
#define BW_PLATFORM_REGISTER_SIM_ENV 1

// reg platform_register.jtag_select
#define BW_PLATFORM_REGISTER_JTAG_SELECT 1

// reg platform_register.boot_status
#define BW_PLATFORM_REGISTER_BOOT_STATUS 32

// reg platform_register.app_addr
#define BW_PLATFORM_REGISTER_APP_ADDR 32

// reg platform_register.proc_auto_id
#define BW_PLATFORM_REGISTER_PROC_AUTO_ID 32

// reg platform_register.proc_status
#define BW_PLATFORM_REGISTER_PROC_STATUS 32

// reg platform_register.core_pc
#define BW_PLATFORM_REGISTER_CORE_PC 32

// reg platform_register.core_inst
#define BW_PLATFORM_REGISTER_CORE_INST 32

// reg platform_register.imp_type
#define BW_PLATFORM_REGISTER_IMP_TYPE 32

// reg platform_register.flash_base_addr
#define BW_PLATFORM_REGISTER_FLASH_BASE_ADDR 32

// reg design_info.date
#define BW_DESIGN_INFO_DATE 32

// reg design_info.username
#define BW_DESIGN_INFO_USERNAME 32

// reg design_info.home_git_name
#define BW_DESIGN_INFO_HOME_GIT_NAME 32

// reg design_info.platform_name
#define BW_DESIGN_INFO_PLATFORM_NAME 32

// reg design_info.home_git_version
#define BW_DESIGN_INFO_HOME_GIT_VERSION 32

// reg design_info.devkit_git_version
#define BW_DESIGN_INFO_DEVKIT_GIT_VERSION 32

// reg boot_mode
#define BW_BOOT_MODE 1
#define BOOT_MODE_OCD 0
#define BOOT_MODE_STAND_ALONE 1
#define BOOT_MODE_INDEX_STAND_ALONE 0

// reg boot_status
#define BW_BOOT_STATUS 2
#define BOOT_STATUS_RESETED 0
#define BOOT_STATUS_APP_LOAD 1
#define BOOT_STATUS_ALL_READY 2
#define BOOT_STATUS_INDEX_APP_LOAD 0
#define BOOT_STATUS_INDEX_ALL_READY 1

// reg jtag_select
#define BW_JTAG_SELECT 1
#define JTAG_SELECT_NOC 0
#define JTAG_SELECT_CORE 1
#define JTAG_SELECT_INDEX_CORE 0

// reg imp_type
#define BW_IMP_TYPE 2
#define IMP_TYPE_RTL 0
#define IMP_TYPE_FPGA 1
#define IMP_TYPE_CHIP 2
#define IMP_TYPE_VP 3
#define IMP_TYPE_INDEX_FPGA 0
#define IMP_TYPE_INDEX_CHIP 1

#endif