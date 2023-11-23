// Copyright 1986-2023 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2022.2.2 (win64) Build 3788238 Tue Feb 21 20:00:34 MST 2023
// Date        : Thu Nov 23 10:00:37 2023
// Host        : LPSoC_gw running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               c:/Users/GW_LPSoC/rvx_dev/platform/RadarPIM/imp_arty-100t_2023-11-23/xci/xilinx_clock_pll_0/xilinx_clock_pll_0_stub.v
// Design      : xilinx_clock_pll_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a100tcsg324-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
module xilinx_clock_pll_0(clk_50000000, reset, locked, fpga_clk)
/* synthesis syn_black_box black_box_pad_pin="clk_50000000,reset,locked,fpga_clk" */;
  output clk_50000000;
  input reset;
  output locked;
  input fpga_clk;
endmodule
