-- Copyright 1986-2023 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2022.2.2 (win64) Build 3788238 Tue Feb 21 20:00:34 MST 2023
-- Date        : Thu Nov 23 10:00:37 2023
-- Host        : LPSoC_gw running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub
--               c:/Users/GW_LPSoC/rvx_dev/platform/RadarPIM/imp_arty-100t_2023-11-23/xci/xilinx_clock_pll_0/xilinx_clock_pll_0_stub.vhdl
-- Design      : xilinx_clock_pll_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7a100tcsg324-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity xilinx_clock_pll_0 is
  Port ( 
    clk_50000000 : out STD_LOGIC;
    reset : in STD_LOGIC;
    locked : out STD_LOGIC;
    fpga_clk : in STD_LOGIC
  );

end xilinx_clock_pll_0;

architecture stub of xilinx_clock_pll_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "clk_50000000,reset,locked,fpga_clk";
begin
end;
