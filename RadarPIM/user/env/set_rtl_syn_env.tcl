set verilog_module_list [concat_file_list $verilog_module_list ${PLATFORM_DIR}/user/rtl/src/*.v]
set verilog_module_list [concat_file_list $verilog_module_list ${PLATFORM_DIR}/user/rtl/src/*/*.v]
set verilog_module_list [concat_file_list $verilog_module_list ${PLATFORM_DIR}/user/rtl/src/*.sv]
set verilog_module_list [concat_file_list $verilog_module_list ${PLATFORM_DIR}/user/rtl/src/*/*.sv]
lappend verilog_include_list ${PLATFORM_DIR}/user/rtl/include

set vhdl_module_list [concat_file_list $vhdl_module_list ${PLATFORM_DIR}/user/rtl/src/*.{vhd,vhdl}]
set vhdl_module_list [concat_file_list $vhdl_module_list ${PLATFORM_DIR}/user/rtl/src/*/*.{vhd,vhdl}]
