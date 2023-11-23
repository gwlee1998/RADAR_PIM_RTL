// ****************************************************************************
// ****************************************************************************
// Copyright SoC Design Research Group, All rights reserved.
// Electronics and Telecommunications Research Institute (ETRI)
// 
// THESE DOCUMENTS CONTAIN CONFIDENTIAL INFORMATION AND KNOWLEDGE
// WHICH IS THE PROPERTY OF ETRI. NO PART OF THIS PUBLICATION IS
// TO BE USED FOR ANY OTHER PURPOSE, AND THESE ARE NOT TO BE
// REPRODUCED, COPIED, DISCLOSED, TRANSMITTED, STORED IN A RETRIEVAL
// SYSTEM OR TRANSLATED INTO ANY OTHER HUMAN OR COMPUTER LANGUAGE,
// IN ANY FORM, BY ANY MEANS, IN WHOLE OR IN PART, WITHOUT THE
// COMPLETE PRIOR WRITTEN PERMISSION OF ETRI.
// ****************************************************************************
// 2023-11-21
// Kyuseung Han (han@etri.re.kr)
// ****************************************************************************
// ****************************************************************************

`include "ervp_platform_controller_memorymap_offset.vh"
`include "ervp_external_peri_group_memorymap_offset.vh"
`include "memorymap_info.vh"
`include "ervp_global.vh"
`include "platform_info.vh"
`include "munoc_network_include.vh"

module RADARPIM
(
	boot_mode,
	external_clk_0,
	external_rstnn,
	led_list,
	uwb_reset,
	oled_sdcsel,
	oled_srstnn,
	oled_svbat,
	oled_svdd,
	pjtag_rtck,
	pjtag_rtrstnn,
	pjtag_rtms,
	pjtag_rtdi,
	pjtag_rtdo,
	uart_readymade_tx_list,
	uart_readymade_rx_list,
	printf_tx,
	printf_rx,
	oled_sclk,
	oled_scs,
	oled_sdq0,
	oled_sdq1,
	spi_flash_sclk,
	spi_flash_scs,
	spi_flash_sdq0,
	spi_flash_sdq1
);


input wire [(`BW_BOOT_MODE)-1:0] boot_mode;
input wire external_clk_0;
input wire external_rstnn;
output wire [((1)*(1))-1:0] led_list;
inout wire uwb_reset;
inout wire oled_sdcsel;
inout wire oled_srstnn;
inout wire oled_svbat;
inout wire oled_svdd;
input wire pjtag_rtck;
input wire pjtag_rtrstnn;
input wire pjtag_rtms;
input wire pjtag_rtdi;
output wire pjtag_rtdo;
output wire [((1)*(1))-1:0] uart_readymade_tx_list;
input wire [((1)*(1))-1:0] uart_readymade_rx_list;
output wire printf_tx;
input wire printf_rx;
output wire oled_sclk;
output wire oled_scs;
output wire oled_sdq0;
input wire oled_sdq1;
output wire spi_flash_sclk;
output wire spi_flash_scs;
output wire spi_flash_sdq0;
input wire spi_flash_sdq1;


wire spi_common_sclk;
wire spi_common_sdq0;
wire clk_system;
wire clk_core;
wire clk_system_external;
wire clk_system_debug;
wire clk_local_access;
wire clk_process_000;
wire clk_process_001;
wire clk_noc;
wire gclk_system;
wire gclk_core;
wire gclk_system_external;
wire gclk_system_debug;
wire gclk_local_access;
wire gclk_process_000;
wire gclk_process_001;
wire gclk_noc;
wire tick_1us;
wire tick_62d5ms;
wire tick_gpio;
wire global_rstnn;
wire global_rstpp;
wire [(8)-1:0] rstnn_seqeunce;
wire [(8)-1:0] rstpp_seqeunce;
wire rstnn_user;
wire rstpp_user;
wire [(`BW_BOOT_MODE)-1:0] i_rtl_boot_mode;
wire i_rtl_clk_system;
wire i_rtl_clk_core;
wire i_rtl_clk_system_external;
wire i_rtl_clk_system_debug;
wire i_rtl_clk_local_access;
wire i_rtl_clk_process_000;
wire i_rtl_clk_process_001;
wire i_rtl_clk_noc;
wire i_rtl_gclk_system;
wire i_rtl_gclk_core;
wire i_rtl_gclk_system_external;
wire i_rtl_gclk_system_debug;
wire i_rtl_gclk_local_access;
wire i_rtl_gclk_process_000;
wire i_rtl_gclk_process_001;
wire i_rtl_gclk_noc;
wire i_rtl_tick_1us;
wire i_rtl_tick_62d5ms;
wire i_rtl_tick_gpio;
wire i_rtl_external_rstnn;
wire i_rtl_global_rstnn;
wire i_rtl_global_rstpp;
wire [(8)-1:0] i_rtl_rstnn_seqeunce;
wire [(8)-1:0] i_rtl_rstpp_seqeunce;
wire i_rtl_rstnn_user;
wire i_rtl_rstpp_user;
wire [((1)*(1))-1:0] i_rtl_led_list;
wire i_rtl_i_test1_clk;
wire i_rtl_i_test1_rstnn;
wire i_rtl_i_pll0_external_rstnn;
wire i_rtl_i_pll0_clk_system;
wire i_rtl_i_system_sram_clk;
wire i_rtl_i_system_sram_rstnn;
wire i_rtl_spi_common_sclk;
wire i_rtl_spi_common_sdq0;
wire [(1)-1:0] i_rtl_uwb_reset_soe;
wire [(1)-1:0] i_rtl_uwb_reset_soval;
wire [(1)-1:0] i_rtl_uwb_reset_sival;
wire [(1)-1:0] i_rtl_oled_sdcsel_oe;
wire [(1)-1:0] i_rtl_oled_sdcsel_oval;
wire [(1)-1:0] i_rtl_oled_sdcsel_ival;
wire [(1)-1:0] i_rtl_oled_srstnn_oe;
wire [(1)-1:0] i_rtl_oled_srstnn_oval;
wire [(1)-1:0] i_rtl_oled_srstnn_ival;
wire [(1)-1:0] i_rtl_oled_svbat_oe;
wire [(1)-1:0] i_rtl_oled_svbat_oval;
wire [(1)-1:0] i_rtl_oled_svbat_ival;
wire [(1)-1:0] i_rtl_oled_svdd_oe;
wire [(1)-1:0] i_rtl_oled_svdd_oval;
wire [(1)-1:0] i_rtl_oled_svdd_ival;
wire i_rtl_pjtag_rtck;
wire i_rtl_pjtag_rtrstnn;
wire i_rtl_pjtag_rtms;
wire i_rtl_pjtag_rtdi;
wire i_rtl_pjtag_rtdo;
wire [((1)*(1))-1:0] i_rtl_uart_readymade_tx_list;
wire [((1)*(1))-1:0] i_rtl_uart_readymade_rx_list;
wire i_rtl_printf_tx;
wire i_rtl_printf_rx;
wire i_rtl_oled_sclk;
wire i_rtl_oled_scs;
wire i_rtl_oled_sdq0;
wire i_rtl_oled_sdq1;
wire i_rtl_spi_flash_sclk;
wire i_rtl_spi_flash_scs;
wire i_rtl_spi_flash_sdq0;
wire i_rtl_spi_flash_sdq1;
wire i_rtl_i_test1_sxawready;
wire i_rtl_i_test1_sxawvalid;
wire [(32)-1:0] i_rtl_i_test1_sxawaddr;
wire [(1)-1:0] i_rtl_i_test1_sxawid;
wire [(8)-1:0] i_rtl_i_test1_sxawlen;
wire [(3)-1:0] i_rtl_i_test1_sxawsize;
wire [(2)-1:0] i_rtl_i_test1_sxawburst;
wire i_rtl_i_test1_sxwready;
wire i_rtl_i_test1_sxwvalid;
wire [(1)-1:0] i_rtl_i_test1_sxwid;
wire [(32)-1:0] i_rtl_i_test1_sxwdata;
wire [(32/8)-1:0] i_rtl_i_test1_sxwstrb;
wire i_rtl_i_test1_sxwlast;
wire i_rtl_i_test1_sxbready;
wire i_rtl_i_test1_sxbvalid;
wire [(1)-1:0] i_rtl_i_test1_sxbid;
wire [(2)-1:0] i_rtl_i_test1_sxbresp;
wire i_rtl_i_test1_sxarready;
wire i_rtl_i_test1_sxarvalid;
wire [(32)-1:0] i_rtl_i_test1_sxaraddr;
wire [(1)-1:0] i_rtl_i_test1_sxarid;
wire [(8)-1:0] i_rtl_i_test1_sxarlen;
wire [(3)-1:0] i_rtl_i_test1_sxarsize;
wire [(2)-1:0] i_rtl_i_test1_sxarburst;
wire i_rtl_i_test1_sxrready;
wire i_rtl_i_test1_sxrvalid;
wire [(1)-1:0] i_rtl_i_test1_sxrid;
wire [(32)-1:0] i_rtl_i_test1_sxrdata;
wire i_rtl_i_test1_sxrlast;
wire [(2)-1:0] i_rtl_i_test1_sxrresp;
wire i_rtl_i_system_sram_sxawready;
wire i_rtl_i_system_sram_sxawvalid;
wire [(32)-1:0] i_rtl_i_system_sram_sxawaddr;
wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_rtl_i_system_sram_sxawid;
wire [(8)-1:0] i_rtl_i_system_sram_sxawlen;
wire [(3)-1:0] i_rtl_i_system_sram_sxawsize;
wire [(2)-1:0] i_rtl_i_system_sram_sxawburst;
wire i_rtl_i_system_sram_sxwready;
wire i_rtl_i_system_sram_sxwvalid;
wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_rtl_i_system_sram_sxwid;
wire [(32)-1:0] i_rtl_i_system_sram_sxwdata;
wire [(32/8)-1:0] i_rtl_i_system_sram_sxwstrb;
wire i_rtl_i_system_sram_sxwlast;
wire i_rtl_i_system_sram_sxbready;
wire i_rtl_i_system_sram_sxbvalid;
wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_rtl_i_system_sram_sxbid;
wire [(2)-1:0] i_rtl_i_system_sram_sxbresp;
wire i_rtl_i_system_sram_sxarready;
wire i_rtl_i_system_sram_sxarvalid;
wire [(32)-1:0] i_rtl_i_system_sram_sxaraddr;
wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_rtl_i_system_sram_sxarid;
wire [(8)-1:0] i_rtl_i_system_sram_sxarlen;
wire [(3)-1:0] i_rtl_i_system_sram_sxarsize;
wire [(2)-1:0] i_rtl_i_system_sram_sxarburst;
wire i_rtl_i_system_sram_sxrready;
wire i_rtl_i_system_sram_sxrvalid;
wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_rtl_i_system_sram_sxrid;
wire [(32)-1:0] i_rtl_i_system_sram_sxrdata;
wire i_rtl_i_system_sram_sxrlast;
wire [(2)-1:0] i_rtl_i_system_sram_sxrresp;
wire i_test1_clk;
wire i_test1_rstnn;
wire i_test1_rxawready;
wire i_test1_rxawvalid;
wire [(32)-1:0] i_test1_rxawaddr;
wire [(1)-1:0] i_test1_rxawid;
wire [(8)-1:0] i_test1_rxawlen;
wire [(3)-1:0] i_test1_rxawsize;
wire [(2)-1:0] i_test1_rxawburst;
wire i_test1_rxwready;
wire i_test1_rxwvalid;
wire [(1)-1:0] i_test1_rxwid;
wire [(32)-1:0] i_test1_rxwdata;
wire [(32/8)-1:0] i_test1_rxwstrb;
wire i_test1_rxwlast;
wire i_test1_rxbready;
wire i_test1_rxbvalid;
wire [(1)-1:0] i_test1_rxbid;
wire [(2)-1:0] i_test1_rxbresp;
wire i_test1_rxarready;
wire i_test1_rxarvalid;
wire [(32)-1:0] i_test1_rxaraddr;
wire [(1)-1:0] i_test1_rxarid;
wire [(8)-1:0] i_test1_rxarlen;
wire [(3)-1:0] i_test1_rxarsize;
wire [(2)-1:0] i_test1_rxarburst;
wire i_test1_rxrready;
wire i_test1_rxrvalid;
wire [(1)-1:0] i_test1_rxrid;
wire [(32)-1:0] i_test1_rxrdata;
wire i_test1_rxrlast;
wire [(2)-1:0] i_test1_rxrresp;
wire i_pll0_external_clk;
wire i_pll0_external_rstnn;
wire i_pll0_clk_system;
wire i_system_sram_clk;
wire i_system_sram_rstnn;
wire i_system_sram_rxawready;
wire i_system_sram_rxawvalid;
wire [(32)-1:0] i_system_sram_rxawaddr;
wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_system_sram_rxawid;
wire [(8)-1:0] i_system_sram_rxawlen;
wire [(3)-1:0] i_system_sram_rxawsize;
wire [(2)-1:0] i_system_sram_rxawburst;
wire i_system_sram_rxwready;
wire i_system_sram_rxwvalid;
wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_system_sram_rxwid;
wire [(32)-1:0] i_system_sram_rxwdata;
wire [(32/8)-1:0] i_system_sram_rxwstrb;
wire i_system_sram_rxwlast;
wire i_system_sram_rxbready;
wire i_system_sram_rxbvalid;
wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_system_sram_rxbid;
wire [(2)-1:0] i_system_sram_rxbresp;
wire i_system_sram_rxarready;
wire i_system_sram_rxarvalid;
wire [(32)-1:0] i_system_sram_rxaraddr;
wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_system_sram_rxarid;
wire [(8)-1:0] i_system_sram_rxarlen;
wire [(3)-1:0] i_system_sram_rxarsize;
wire [(2)-1:0] i_system_sram_rxarburst;
wire i_system_sram_rxrready;
wire i_system_sram_rxrvalid;
wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_system_sram_rxrid;
wire [(32)-1:0] i_system_sram_rxrdata;
wire i_system_sram_rxrlast;
wire [(2)-1:0] i_system_sram_rxrresp;
wire [((1)*(1))-1:0] tristate_buffer_for_uwb_reset_roe_list;
wire [((1)*(1))-1:0] tristate_buffer_for_uwb_reset_roval_list;
wire [((1)*(1))-1:0] tristate_buffer_for_uwb_reset_rival_list;
wire [((1)*(1))-1:0] tristate_buffer_for_oled_sdcsel_roe_list;
wire [((1)*(1))-1:0] tristate_buffer_for_oled_sdcsel_roval_list;
wire [((1)*(1))-1:0] tristate_buffer_for_oled_sdcsel_rival_list;
wire [((1)*(1))-1:0] tristate_buffer_for_oled_srstnn_roe_list;
wire [((1)*(1))-1:0] tristate_buffer_for_oled_srstnn_roval_list;
wire [((1)*(1))-1:0] tristate_buffer_for_oled_srstnn_rival_list;
wire [((1)*(1))-1:0] tristate_buffer_for_oled_svbat_roe_list;
wire [((1)*(1))-1:0] tristate_buffer_for_oled_svbat_roval_list;
wire [((1)*(1))-1:0] tristate_buffer_for_oled_svbat_rival_list;
wire [((1)*(1))-1:0] tristate_buffer_for_oled_svdd_roe_list;
wire [((1)*(1))-1:0] tristate_buffer_for_oled_svdd_roval_list;
wire [((1)*(1))-1:0] tristate_buffer_for_oled_svdd_rival_list;

RADARPIM_RTL
i_rtl
(
	.boot_mode(i_rtl_boot_mode),
	.clk_system(i_rtl_clk_system),
	.clk_core(i_rtl_clk_core),
	.clk_system_external(i_rtl_clk_system_external),
	.clk_system_debug(i_rtl_clk_system_debug),
	.clk_local_access(i_rtl_clk_local_access),
	.clk_process_000(i_rtl_clk_process_000),
	.clk_process_001(i_rtl_clk_process_001),
	.clk_noc(i_rtl_clk_noc),
	.gclk_system(i_rtl_gclk_system),
	.gclk_core(i_rtl_gclk_core),
	.gclk_system_external(i_rtl_gclk_system_external),
	.gclk_system_debug(i_rtl_gclk_system_debug),
	.gclk_local_access(i_rtl_gclk_local_access),
	.gclk_process_000(i_rtl_gclk_process_000),
	.gclk_process_001(i_rtl_gclk_process_001),
	.gclk_noc(i_rtl_gclk_noc),
	.tick_1us(i_rtl_tick_1us),
	.tick_62d5ms(i_rtl_tick_62d5ms),
	.tick_gpio(i_rtl_tick_gpio),
	.external_rstnn(i_rtl_external_rstnn),
	.global_rstnn(i_rtl_global_rstnn),
	.global_rstpp(i_rtl_global_rstpp),
	.rstnn_seqeunce(i_rtl_rstnn_seqeunce),
	.rstpp_seqeunce(i_rtl_rstpp_seqeunce),
	.rstnn_user(i_rtl_rstnn_user),
	.rstpp_user(i_rtl_rstpp_user),
	.led_list(i_rtl_led_list),
	.i_test1_clk(i_rtl_i_test1_clk),
	.i_test1_rstnn(i_rtl_i_test1_rstnn),
	.i_pll0_external_rstnn(i_rtl_i_pll0_external_rstnn),
	.i_pll0_clk_system(i_rtl_i_pll0_clk_system),
	.i_system_sram_clk(i_rtl_i_system_sram_clk),
	.i_system_sram_rstnn(i_rtl_i_system_sram_rstnn),
	.spi_common_sclk(i_rtl_spi_common_sclk),
	.spi_common_sdq0(i_rtl_spi_common_sdq0),
	.uwb_reset_soe(i_rtl_uwb_reset_soe),
	.uwb_reset_soval(i_rtl_uwb_reset_soval),
	.uwb_reset_sival(i_rtl_uwb_reset_sival),
	.oled_sdcsel_oe(i_rtl_oled_sdcsel_oe),
	.oled_sdcsel_oval(i_rtl_oled_sdcsel_oval),
	.oled_sdcsel_ival(i_rtl_oled_sdcsel_ival),
	.oled_srstnn_oe(i_rtl_oled_srstnn_oe),
	.oled_srstnn_oval(i_rtl_oled_srstnn_oval),
	.oled_srstnn_ival(i_rtl_oled_srstnn_ival),
	.oled_svbat_oe(i_rtl_oled_svbat_oe),
	.oled_svbat_oval(i_rtl_oled_svbat_oval),
	.oled_svbat_ival(i_rtl_oled_svbat_ival),
	.oled_svdd_oe(i_rtl_oled_svdd_oe),
	.oled_svdd_oval(i_rtl_oled_svdd_oval),
	.oled_svdd_ival(i_rtl_oled_svdd_ival),
	.pjtag_rtck(i_rtl_pjtag_rtck),
	.pjtag_rtrstnn(i_rtl_pjtag_rtrstnn),
	.pjtag_rtms(i_rtl_pjtag_rtms),
	.pjtag_rtdi(i_rtl_pjtag_rtdi),
	.pjtag_rtdo(i_rtl_pjtag_rtdo),
	.uart_readymade_tx_list(i_rtl_uart_readymade_tx_list),
	.uart_readymade_rx_list(i_rtl_uart_readymade_rx_list),
	.printf_tx(i_rtl_printf_tx),
	.printf_rx(i_rtl_printf_rx),
	.oled_sclk(i_rtl_oled_sclk),
	.oled_scs(i_rtl_oled_scs),
	.oled_sdq0(i_rtl_oled_sdq0),
	.oled_sdq1(i_rtl_oled_sdq1),
	.spi_flash_sclk(i_rtl_spi_flash_sclk),
	.spi_flash_scs(i_rtl_spi_flash_scs),
	.spi_flash_sdq0(i_rtl_spi_flash_sdq0),
	.spi_flash_sdq1(i_rtl_spi_flash_sdq1),
	.i_test1_sxawready(i_rtl_i_test1_sxawready),
	.i_test1_sxawvalid(i_rtl_i_test1_sxawvalid),
	.i_test1_sxawaddr(i_rtl_i_test1_sxawaddr),
	.i_test1_sxawid(i_rtl_i_test1_sxawid),
	.i_test1_sxawlen(i_rtl_i_test1_sxawlen),
	.i_test1_sxawsize(i_rtl_i_test1_sxawsize),
	.i_test1_sxawburst(i_rtl_i_test1_sxawburst),
	.i_test1_sxwready(i_rtl_i_test1_sxwready),
	.i_test1_sxwvalid(i_rtl_i_test1_sxwvalid),
	.i_test1_sxwid(i_rtl_i_test1_sxwid),
	.i_test1_sxwdata(i_rtl_i_test1_sxwdata),
	.i_test1_sxwstrb(i_rtl_i_test1_sxwstrb),
	.i_test1_sxwlast(i_rtl_i_test1_sxwlast),
	.i_test1_sxbready(i_rtl_i_test1_sxbready),
	.i_test1_sxbvalid(i_rtl_i_test1_sxbvalid),
	.i_test1_sxbid(i_rtl_i_test1_sxbid),
	.i_test1_sxbresp(i_rtl_i_test1_sxbresp),
	.i_test1_sxarready(i_rtl_i_test1_sxarready),
	.i_test1_sxarvalid(i_rtl_i_test1_sxarvalid),
	.i_test1_sxaraddr(i_rtl_i_test1_sxaraddr),
	.i_test1_sxarid(i_rtl_i_test1_sxarid),
	.i_test1_sxarlen(i_rtl_i_test1_sxarlen),
	.i_test1_sxarsize(i_rtl_i_test1_sxarsize),
	.i_test1_sxarburst(i_rtl_i_test1_sxarburst),
	.i_test1_sxrready(i_rtl_i_test1_sxrready),
	.i_test1_sxrvalid(i_rtl_i_test1_sxrvalid),
	.i_test1_sxrid(i_rtl_i_test1_sxrid),
	.i_test1_sxrdata(i_rtl_i_test1_sxrdata),
	.i_test1_sxrlast(i_rtl_i_test1_sxrlast),
	.i_test1_sxrresp(i_rtl_i_test1_sxrresp),
	.i_system_sram_sxawready(i_rtl_i_system_sram_sxawready),
	.i_system_sram_sxawvalid(i_rtl_i_system_sram_sxawvalid),
	.i_system_sram_sxawaddr(i_rtl_i_system_sram_sxawaddr),
	.i_system_sram_sxawid(i_rtl_i_system_sram_sxawid),
	.i_system_sram_sxawlen(i_rtl_i_system_sram_sxawlen),
	.i_system_sram_sxawsize(i_rtl_i_system_sram_sxawsize),
	.i_system_sram_sxawburst(i_rtl_i_system_sram_sxawburst),
	.i_system_sram_sxwready(i_rtl_i_system_sram_sxwready),
	.i_system_sram_sxwvalid(i_rtl_i_system_sram_sxwvalid),
	.i_system_sram_sxwid(i_rtl_i_system_sram_sxwid),
	.i_system_sram_sxwdata(i_rtl_i_system_sram_sxwdata),
	.i_system_sram_sxwstrb(i_rtl_i_system_sram_sxwstrb),
	.i_system_sram_sxwlast(i_rtl_i_system_sram_sxwlast),
	.i_system_sram_sxbready(i_rtl_i_system_sram_sxbready),
	.i_system_sram_sxbvalid(i_rtl_i_system_sram_sxbvalid),
	.i_system_sram_sxbid(i_rtl_i_system_sram_sxbid),
	.i_system_sram_sxbresp(i_rtl_i_system_sram_sxbresp),
	.i_system_sram_sxarready(i_rtl_i_system_sram_sxarready),
	.i_system_sram_sxarvalid(i_rtl_i_system_sram_sxarvalid),
	.i_system_sram_sxaraddr(i_rtl_i_system_sram_sxaraddr),
	.i_system_sram_sxarid(i_rtl_i_system_sram_sxarid),
	.i_system_sram_sxarlen(i_rtl_i_system_sram_sxarlen),
	.i_system_sram_sxarsize(i_rtl_i_system_sram_sxarsize),
	.i_system_sram_sxarburst(i_rtl_i_system_sram_sxarburst),
	.i_system_sram_sxrready(i_rtl_i_system_sram_sxrready),
	.i_system_sram_sxrvalid(i_rtl_i_system_sram_sxrvalid),
	.i_system_sram_sxrid(i_rtl_i_system_sram_sxrid),
	.i_system_sram_sxrdata(i_rtl_i_system_sram_sxrdata),
	.i_system_sram_sxrlast(i_rtl_i_system_sram_sxrlast),
	.i_system_sram_sxrresp(i_rtl_i_system_sram_sxrresp)
);

RADARPIM_CLOCK_PLL_0_00
i_pll0
(
	.external_clk(i_pll0_external_clk),
	.external_rstnn(i_pll0_external_rstnn),
	.clk_system(i_pll0_clk_system)
);

RADARPIM_SRAM_01
i_system_sram
(
	.clk(i_system_sram_clk),
	.rstnn(i_system_sram_rstnn),
	.rxawready(i_system_sram_rxawready),
	.rxawvalid(i_system_sram_rxawvalid),
	.rxawaddr(i_system_sram_rxawaddr),
	.rxawid(i_system_sram_rxawid),
	.rxawlen(i_system_sram_rxawlen),
	.rxawsize(i_system_sram_rxawsize),
	.rxawburst(i_system_sram_rxawburst),
	.rxwready(i_system_sram_rxwready),
	.rxwvalid(i_system_sram_rxwvalid),
	.rxwid(i_system_sram_rxwid),
	.rxwdata(i_system_sram_rxwdata),
	.rxwstrb(i_system_sram_rxwstrb),
	.rxwlast(i_system_sram_rxwlast),
	.rxbready(i_system_sram_rxbready),
	.rxbvalid(i_system_sram_rxbvalid),
	.rxbid(i_system_sram_rxbid),
	.rxbresp(i_system_sram_rxbresp),
	.rxarready(i_system_sram_rxarready),
	.rxarvalid(i_system_sram_rxarvalid),
	.rxaraddr(i_system_sram_rxaraddr),
	.rxarid(i_system_sram_rxarid),
	.rxarlen(i_system_sram_rxarlen),
	.rxarsize(i_system_sram_rxarsize),
	.rxarburst(i_system_sram_rxarburst),
	.rxrready(i_system_sram_rxrready),
	.rxrvalid(i_system_sram_rxrvalid),
	.rxrid(i_system_sram_rxrid),
	.rxrdata(i_system_sram_rxrdata),
	.rxrlast(i_system_sram_rxrlast),
	.rxrresp(i_system_sram_rxrresp)
);

TRISTATE_BUFFER_OE
#(
	.NUM_DATA(1),
	.BW_DATA(1)
)
tristate_buffer_for_uwb_reset
(
	.inout_port_list(uwb_reset),
	.roe_list(tristate_buffer_for_uwb_reset_roe_list),
	.roval_list(tristate_buffer_for_uwb_reset_roval_list),
	.rival_list(tristate_buffer_for_uwb_reset_rival_list)
);

TRISTATE_BUFFER_OE
#(
	.NUM_DATA(1),
	.BW_DATA(1)
)
tristate_buffer_for_oled_sdcsel
(
	.inout_port_list(oled_sdcsel),
	.roe_list(tristate_buffer_for_oled_sdcsel_roe_list),
	.roval_list(tristate_buffer_for_oled_sdcsel_roval_list),
	.rival_list(tristate_buffer_for_oled_sdcsel_rival_list)
);

TRISTATE_BUFFER_OE
#(
	.NUM_DATA(1),
	.BW_DATA(1)
)
tristate_buffer_for_oled_srstnn
(
	.inout_port_list(oled_srstnn),
	.roe_list(tristate_buffer_for_oled_srstnn_roe_list),
	.roval_list(tristate_buffer_for_oled_srstnn_roval_list),
	.rival_list(tristate_buffer_for_oled_srstnn_rival_list)
);

TRISTATE_BUFFER_OE
#(
	.NUM_DATA(1),
	.BW_DATA(1)
)
tristate_buffer_for_oled_svbat
(
	.inout_port_list(oled_svbat),
	.roe_list(tristate_buffer_for_oled_svbat_roe_list),
	.roval_list(tristate_buffer_for_oled_svbat_roval_list),
	.rival_list(tristate_buffer_for_oled_svbat_rival_list)
);

TRISTATE_BUFFER_OE
#(
	.NUM_DATA(1),
	.BW_DATA(1)
)
tristate_buffer_for_oled_svdd
(
	.inout_port_list(oled_svdd),
	.roe_list(tristate_buffer_for_oled_svdd_roe_list),
	.roval_list(tristate_buffer_for_oled_svdd_roval_list),
	.rival_list(tristate_buffer_for_oled_svdd_rival_list)
);

assign i_rtl_boot_mode = boot_mode;
assign i_rtl_external_rstnn = external_rstnn;
assign i_test1_clk = i_rtl_i_test1_clk;
assign i_test1_rstnn = i_rtl_i_test1_rstnn;
assign i_pll0_external_clk = external_clk_0;
assign i_pll0_external_rstnn = i_rtl_i_pll0_external_rstnn;
assign i_rtl_i_pll0_clk_system = i_pll0_clk_system;
assign i_system_sram_clk = i_rtl_i_system_sram_clk;
assign i_system_sram_rstnn = i_rtl_i_system_sram_rstnn;
assign spi_common_sclk = i_rtl_spi_common_sclk;
assign spi_common_sdq0 = i_rtl_spi_common_sdq0;
assign clk_system = i_rtl_clk_system;
assign clk_core = i_rtl_clk_core;
assign clk_system_external = i_rtl_clk_system_external;
assign clk_system_debug = i_rtl_clk_system_debug;
assign clk_local_access = i_rtl_clk_local_access;
assign clk_process_000 = i_rtl_clk_process_000;
assign clk_process_001 = i_rtl_clk_process_001;
assign clk_noc = i_rtl_clk_noc;
assign gclk_system = i_rtl_gclk_system;
assign gclk_core = i_rtl_gclk_core;
assign gclk_system_external = i_rtl_gclk_system_external;
assign gclk_system_debug = i_rtl_gclk_system_debug;
assign gclk_local_access = i_rtl_gclk_local_access;
assign gclk_process_000 = i_rtl_gclk_process_000;
assign gclk_process_001 = i_rtl_gclk_process_001;
assign gclk_noc = i_rtl_gclk_noc;
assign tick_1us = i_rtl_tick_1us;
assign tick_62d5ms = i_rtl_tick_62d5ms;
assign tick_gpio = i_rtl_tick_gpio;
assign global_rstnn = i_rtl_global_rstnn;
assign global_rstpp = i_rtl_global_rstpp;
assign rstnn_seqeunce = i_rtl_rstnn_seqeunce;
assign rstpp_seqeunce = i_rtl_rstpp_seqeunce;
assign rstnn_user = i_rtl_rstnn_user;
assign rstpp_user = i_rtl_rstpp_user;
assign led_list[1*(0+1)-1 -:1] = i_rtl_led_list[1*(0+1)-1 -:1];
assign tristate_buffer_for_uwb_reset_roe_list[1*(0+1)-1 -:1] = i_rtl_uwb_reset_soe;
assign tristate_buffer_for_uwb_reset_roval_list[1*(0+1)-1 -:1] = i_rtl_uwb_reset_soval;
assign i_rtl_uwb_reset_sival = tristate_buffer_for_uwb_reset_rival_list[1*(0+1)-1 -:1];
assign tristate_buffer_for_oled_sdcsel_roe_list[1*(0+1)-1 -:1] = i_rtl_oled_sdcsel_oe;
assign tristate_buffer_for_oled_sdcsel_roval_list[1*(0+1)-1 -:1] = i_rtl_oled_sdcsel_oval;
assign i_rtl_oled_sdcsel_ival = tristate_buffer_for_oled_sdcsel_rival_list[1*(0+1)-1 -:1];
assign tristate_buffer_for_oled_srstnn_roe_list[1*(0+1)-1 -:1] = i_rtl_oled_srstnn_oe;
assign tristate_buffer_for_oled_srstnn_roval_list[1*(0+1)-1 -:1] = i_rtl_oled_srstnn_oval;
assign i_rtl_oled_srstnn_ival = tristate_buffer_for_oled_srstnn_rival_list[1*(0+1)-1 -:1];
assign tristate_buffer_for_oled_svbat_roe_list[1*(0+1)-1 -:1] = i_rtl_oled_svbat_oe;
assign tristate_buffer_for_oled_svbat_roval_list[1*(0+1)-1 -:1] = i_rtl_oled_svbat_oval;
assign i_rtl_oled_svbat_ival = tristate_buffer_for_oled_svbat_rival_list[1*(0+1)-1 -:1];
assign tristate_buffer_for_oled_svdd_roe_list[1*(0+1)-1 -:1] = i_rtl_oled_svdd_oe;
assign tristate_buffer_for_oled_svdd_roval_list[1*(0+1)-1 -:1] = i_rtl_oled_svdd_oval;
assign i_rtl_oled_svdd_ival = tristate_buffer_for_oled_svdd_rival_list[1*(0+1)-1 -:1];
assign i_rtl_pjtag_rtck = pjtag_rtck;
assign i_rtl_pjtag_rtrstnn = pjtag_rtrstnn;
assign i_rtl_pjtag_rtms = pjtag_rtms;
assign i_rtl_pjtag_rtdi = pjtag_rtdi;
assign pjtag_rtdo = i_rtl_pjtag_rtdo;
assign printf_tx = i_rtl_printf_tx;
assign i_rtl_printf_rx = printf_rx;
assign oled_sclk = i_rtl_oled_sclk;
assign oled_scs = i_rtl_oled_scs;
assign oled_sdq0 = i_rtl_oled_sdq0;
assign i_rtl_oled_sdq1 = oled_sdq1;
assign spi_flash_sclk = i_rtl_spi_flash_sclk;
assign spi_flash_scs = i_rtl_spi_flash_scs;
assign spi_flash_sdq0 = i_rtl_spi_flash_sdq0;
assign i_rtl_spi_flash_sdq1 = spi_flash_sdq1;
assign i_rtl_i_test1_sxawready = i_test1_rxawready;
assign i_test1_rxawvalid = i_rtl_i_test1_sxawvalid;
assign i_test1_rxawaddr = i_rtl_i_test1_sxawaddr;
assign i_test1_rxawid = i_rtl_i_test1_sxawid;
assign i_test1_rxawlen = i_rtl_i_test1_sxawlen;
assign i_test1_rxawsize = i_rtl_i_test1_sxawsize;
assign i_test1_rxawburst = i_rtl_i_test1_sxawburst;
assign i_rtl_i_test1_sxwready = i_test1_rxwready;
assign i_test1_rxwvalid = i_rtl_i_test1_sxwvalid;
assign i_test1_rxwid = i_rtl_i_test1_sxwid;
assign i_test1_rxwdata = i_rtl_i_test1_sxwdata;
assign i_test1_rxwstrb = i_rtl_i_test1_sxwstrb;
assign i_test1_rxwlast = i_rtl_i_test1_sxwlast;
assign i_test1_rxbready = i_rtl_i_test1_sxbready;
assign i_rtl_i_test1_sxbvalid = i_test1_rxbvalid;
assign i_rtl_i_test1_sxbid = i_test1_rxbid;
assign i_rtl_i_test1_sxbresp = i_test1_rxbresp;
assign i_rtl_i_test1_sxarready = i_test1_rxarready;
assign i_test1_rxarvalid = i_rtl_i_test1_sxarvalid;
assign i_test1_rxaraddr = i_rtl_i_test1_sxaraddr;
assign i_test1_rxarid = i_rtl_i_test1_sxarid;
assign i_test1_rxarlen = i_rtl_i_test1_sxarlen;
assign i_test1_rxarsize = i_rtl_i_test1_sxarsize;
assign i_test1_rxarburst = i_rtl_i_test1_sxarburst;
assign i_test1_rxrready = i_rtl_i_test1_sxrready;
assign i_rtl_i_test1_sxrvalid = i_test1_rxrvalid;
assign i_rtl_i_test1_sxrid = i_test1_rxrid;
assign i_rtl_i_test1_sxrdata = i_test1_rxrdata;
assign i_rtl_i_test1_sxrlast = i_test1_rxrlast;
assign i_rtl_i_test1_sxrresp = i_test1_rxrresp;
assign i_rtl_i_system_sram_sxawready = i_system_sram_rxawready;
assign i_system_sram_rxawvalid = i_rtl_i_system_sram_sxawvalid;
assign i_system_sram_rxawaddr = i_rtl_i_system_sram_sxawaddr;
assign i_system_sram_rxawid = i_rtl_i_system_sram_sxawid;
assign i_system_sram_rxawlen = i_rtl_i_system_sram_sxawlen;
assign i_system_sram_rxawsize = i_rtl_i_system_sram_sxawsize;
assign i_system_sram_rxawburst = i_rtl_i_system_sram_sxawburst;
assign i_rtl_i_system_sram_sxwready = i_system_sram_rxwready;
assign i_system_sram_rxwvalid = i_rtl_i_system_sram_sxwvalid;
assign i_system_sram_rxwid = i_rtl_i_system_sram_sxwid;
assign i_system_sram_rxwdata = i_rtl_i_system_sram_sxwdata;
assign i_system_sram_rxwstrb = i_rtl_i_system_sram_sxwstrb;
assign i_system_sram_rxwlast = i_rtl_i_system_sram_sxwlast;
assign i_system_sram_rxbready = i_rtl_i_system_sram_sxbready;
assign i_rtl_i_system_sram_sxbvalid = i_system_sram_rxbvalid;
assign i_rtl_i_system_sram_sxbid = i_system_sram_rxbid;
assign i_rtl_i_system_sram_sxbresp = i_system_sram_rxbresp;
assign i_rtl_i_system_sram_sxarready = i_system_sram_rxarready;
assign i_system_sram_rxarvalid = i_rtl_i_system_sram_sxarvalid;
assign i_system_sram_rxaraddr = i_rtl_i_system_sram_sxaraddr;
assign i_system_sram_rxarid = i_rtl_i_system_sram_sxarid;
assign i_system_sram_rxarlen = i_rtl_i_system_sram_sxarlen;
assign i_system_sram_rxarsize = i_rtl_i_system_sram_sxarsize;
assign i_system_sram_rxarburst = i_rtl_i_system_sram_sxarburst;
assign i_system_sram_rxrready = i_rtl_i_system_sram_sxrready;
assign i_rtl_i_system_sram_sxrvalid = i_system_sram_rxrvalid;
assign i_rtl_i_system_sram_sxrid = i_system_sram_rxrid;
assign i_rtl_i_system_sram_sxrdata = i_system_sram_rxrdata;
assign i_rtl_i_system_sram_sxrlast = i_system_sram_rxrlast;
assign i_rtl_i_system_sram_sxrresp = i_system_sram_rxrresp;
assign uart_readymade_tx_list[1*(0+1)-1 -:1] = i_rtl_uart_readymade_tx_list[1*(0+1)-1 -:1];
assign i_rtl_uart_readymade_rx_list[1*(0+1)-1 -:1] = uart_readymade_rx_list[1*(0+1)-1 -:1];

`include "RadarPIM_user_region.vh"

`ifdef USE_ILA
`include "ila_description.vh"
`endif

endmodule