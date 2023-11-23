source ./set_path.tcl

source ${RVX_ENV}/ocd/ervp_jtag_memorymap_offset.tcl
source ${RVX_ENV}/ocd/ervp_platform_controller_memorymap_offset.tcl
source ${RVX_ENV}/ocd/ervp_external_peri_group_memorymap_offset.tcl
source ${RVX_ENV}/ocd/munoc_memorymap_offset.tcl

source ${PLATFORM_DIR}/arch/tcl/memorymap_info.tcl
source ${PLATFORM_DIR}/arch/tcl/hw_info.tcl
source ${PLATFORM_DIR}/arch/tcl/ssw_info.tcl

source ${RVX_ENV}/ocd/util.tcl
source ${RVX_ENV}/ocd/jtag_function.tcl
source ${RVX_ENV}/ocd/memory_function.tcl
source ${RVX_ENV}/ocd/control_function.tcl
source ${RVX_ENV}/ocd/mmio_function.tcl
source ${RVX_ENV}/ocd/misc_api.tcl
source ${RVX_ENV}/ocd/platform_controller_api.tcl
source ${RVX_ENV}/ocd/flash_api.tcl
source ${RVX_ENV}/ocd/noc_api.tcl
source ${RVX_ENV}/ocd/dump_api.tcl

if [info exists INCLUDE_SDRAM]==1 {
  set set_sdram_config_path ./set_sdram_config.tcl
  if [file exists $set_sdram_config_path]==1 {
    source $set_sdram_config_path
  }
}
print_platform_info
