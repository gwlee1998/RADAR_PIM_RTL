## ****************************************************************************
## ****************************************************************************
## Copyright SoC Design Research Group, All rights reservxd.
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
## 2023-11-23
## Kyuseung Han (han@etri.re.kr)
## ****************************************************************************
## ****************************************************************************

if {[file exist ./xci/xilinx_clock_pll_0/xilinx_clock_pll_0.xci]==0} {
	create_ip -force -name clk_wiz -vendor xilinx.com -library ip -version 6.0 -module_name xilinx_clock_pll_0 -dir ./xci
	set_property CONFIG.PRIMARY_PORT fpga_clk [get_ips xilinx_clock_pll_0]
	set_property CONFIG.PRIM_IN_FREQ 100.0 [get_ips xilinx_clock_pll_0]
	set_property CONFIG.CLKOUT1_USED true [get_ips xilinx_clock_pll_0]
	set_property CONFIG.CLK_OUT1_PORT clk_50000000 [get_ips xilinx_clock_pll_0]
	set_property CONFIG.CLKOUT1_REQUESTED_OUT_FREQ 50.0 [get_ips xilinx_clock_pll_0]
} else {
	read_ip ./xci/xilinx_clock_pll_0/xilinx_clock_pll_0.xci
}
if {[file exist ./xci/xilinx_clock_pll_0/xilinx_clock_pll_0_stub.v]==0} {
	synth_ip -quiet ./xci/xilinx_clock_pll_0/xilinx_clock_pll_0.xci
} else {
	read_verilog ./xci/xilinx_clock_pll_0/xilinx_clock_pll_0_stub.v
}