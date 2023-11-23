###########################
# DO NOT MODIFY THE BELOW #
###########################

set USER_FPGA_IMP_ENV_FILE ${PLATFORM_DIR}/user/env/set_fpga_imp_env.tcl
if {[file exist ${USER_FPGA_IMP_ENV_FILE}]} {
	source ${USER_FPGA_IMP_ENV_FILE}
}
