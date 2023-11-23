###########################
# DO NOT MODIFY THE BELOW #
###########################

# arch
source ${PLATFORM_DIR}/arch/rtl/env/set_rtl_syn_env.tcl

# working directory
set verilog_module_list [concat_file_list $verilog_module_list ./src/*.v]
lappend verilog_include_list ./include

set vhdl_module_list [concat_file_list $vhdl_module_list ./src/*.{vhd,vhdl}]



#set xci_list [concat_file_list $xci_list ./xci/*/*.{xci,xcix}]

# user
set verilog_module_list [concat_file_list $verilog_module_list ${PLATFORM_DIR}/user/fpga/common/src/*.v]
lappend verilog_include_list ${PLATFORM_DIR}/user/fpga/common/include

set vhdl_module_list [concat_file_list $vhdl_module_list ${PLATFORM_DIR}/user/fpga/common/src/*.{vhd,vhdl}]

set USER_RTL_SYN_ENV_FILE ${PLATFORM_DIR}/user/env/set_rtl_syn_env.tcl
if {[file exist ${USER_RTL_SYN_ENV_FILE}]} {
	source ${USER_RTL_SYN_ENV_FILE}
}

set USER_FPGA_SYN_ENV_FILE ${PLATFORM_DIR}/user/env/set_fpga_syn_env.tcl
if {[file exist ${USER_FPGA_SYN_ENV_FILE}]} {
	source ${USER_FPGA_SYN_ENV_FILE}
}
