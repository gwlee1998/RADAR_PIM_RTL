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

module RADARPIM_RTL
(
	boot_mode,
	clk_system,
	clk_core,
	clk_system_external,
	clk_system_debug,
	clk_local_access,
	clk_process_000,
	clk_process_001,
	clk_noc,
	gclk_system,
	gclk_core,
	gclk_system_external,
	gclk_system_debug,
	gclk_local_access,
	gclk_process_000,
	gclk_process_001,
	gclk_noc,
	tick_1us,
	tick_62d5ms,
	tick_gpio,
	external_rstnn,
	global_rstnn,
	global_rstpp,
	rstnn_seqeunce,
	rstpp_seqeunce,
	rstnn_user,
	rstpp_user,
	led_list,
	i_test1_clk,
	i_test1_rstnn,
	i_pll0_external_rstnn,
	i_pll0_clk_system,
	i_system_sram_clk,
	i_system_sram_rstnn,
	spi_common_sclk,
	spi_common_sdq0,
	uwb_reset_soe,
	uwb_reset_soval,
	uwb_reset_sival,
	oled_sdcsel_oe,
	oled_sdcsel_oval,
	oled_sdcsel_ival,
	oled_srstnn_oe,
	oled_srstnn_oval,
	oled_srstnn_ival,
	oled_svbat_oe,
	oled_svbat_oval,
	oled_svbat_ival,
	oled_svdd_oe,
	oled_svdd_oval,
	oled_svdd_ival,
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
	spi_flash_sdq1,
	i_test1_sxawready,
	i_test1_sxawvalid,
	i_test1_sxawaddr,
	i_test1_sxawid,
	i_test1_sxawlen,
	i_test1_sxawsize,
	i_test1_sxawburst,
	i_test1_sxwready,
	i_test1_sxwvalid,
	i_test1_sxwid,
	i_test1_sxwdata,
	i_test1_sxwstrb,
	i_test1_sxwlast,
	i_test1_sxbready,
	i_test1_sxbvalid,
	i_test1_sxbid,
	i_test1_sxbresp,
	i_test1_sxarready,
	i_test1_sxarvalid,
	i_test1_sxaraddr,
	i_test1_sxarid,
	i_test1_sxarlen,
	i_test1_sxarsize,
	i_test1_sxarburst,
	i_test1_sxrready,
	i_test1_sxrvalid,
	i_test1_sxrid,
	i_test1_sxrdata,
	i_test1_sxrlast,
	i_test1_sxrresp,
	i_system_sram_sxawready,
	i_system_sram_sxawvalid,
	i_system_sram_sxawaddr,
	i_system_sram_sxawid,
	i_system_sram_sxawlen,
	i_system_sram_sxawsize,
	i_system_sram_sxawburst,
	i_system_sram_sxwready,
	i_system_sram_sxwvalid,
	i_system_sram_sxwid,
	i_system_sram_sxwdata,
	i_system_sram_sxwstrb,
	i_system_sram_sxwlast,
	i_system_sram_sxbready,
	i_system_sram_sxbvalid,
	i_system_sram_sxbid,
	i_system_sram_sxbresp,
	i_system_sram_sxarready,
	i_system_sram_sxarvalid,
	i_system_sram_sxaraddr,
	i_system_sram_sxarid,
	i_system_sram_sxarlen,
	i_system_sram_sxarsize,
	i_system_sram_sxarburst,
	i_system_sram_sxrready,
	i_system_sram_sxrvalid,
	i_system_sram_sxrid,
	i_system_sram_sxrdata,
	i_system_sram_sxrlast,
	i_system_sram_sxrresp
);

parameter BW_FNI_PHIT = `MAX_BW_FNI_PHIT;
parameter BW_BNI_PHIT = `MAX_BW_BNI_PHIT;

input wire [(`BW_BOOT_MODE)-1:0] boot_mode;
output wire clk_system;
output wire clk_core;
output wire clk_system_external;
output wire clk_system_debug;
output wire clk_local_access;
output wire clk_process_000;
output wire clk_process_001;
output wire clk_noc;
output wire gclk_system;
output wire gclk_core;
output wire gclk_system_external;
output wire gclk_system_debug;
output wire gclk_local_access;
output wire gclk_process_000;
output wire gclk_process_001;
output wire gclk_noc;
output wire tick_1us;
output wire tick_62d5ms;
output wire tick_gpio;
input wire external_rstnn;
output wire global_rstnn;
output wire global_rstpp;
output wire [(8)-1:0] rstnn_seqeunce;
output wire [(8)-1:0] rstpp_seqeunce;
output wire rstnn_user;
output wire rstpp_user;
output wire [((1)*(1))-1:0] led_list;
output wire i_test1_clk;
output wire i_test1_rstnn;
output wire i_pll0_external_rstnn;
input wire i_pll0_clk_system;
output wire i_system_sram_clk;
output wire i_system_sram_rstnn;
output wire spi_common_sclk;
output wire spi_common_sdq0;
output wire [(1)-1:0] uwb_reset_soe;
output wire [(1)-1:0] uwb_reset_soval;
input wire [(1)-1:0] uwb_reset_sival;
output wire [(1)-1:0] oled_sdcsel_oe;
output wire [(1)-1:0] oled_sdcsel_oval;
input wire [(1)-1:0] oled_sdcsel_ival;
output wire [(1)-1:0] oled_srstnn_oe;
output wire [(1)-1:0] oled_srstnn_oval;
input wire [(1)-1:0] oled_srstnn_ival;
output wire [(1)-1:0] oled_svbat_oe;
output wire [(1)-1:0] oled_svbat_oval;
input wire [(1)-1:0] oled_svbat_ival;
output wire [(1)-1:0] oled_svdd_oe;
output wire [(1)-1:0] oled_svdd_oval;
input wire [(1)-1:0] oled_svdd_ival;
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
input wire i_test1_sxawready;
output wire i_test1_sxawvalid;
output wire [(32)-1:0] i_test1_sxawaddr;
output wire [(1)-1:0] i_test1_sxawid;
output wire [(8)-1:0] i_test1_sxawlen;
output wire [(3)-1:0] i_test1_sxawsize;
output wire [(2)-1:0] i_test1_sxawburst;
input wire i_test1_sxwready;
output wire i_test1_sxwvalid;
output wire [(1)-1:0] i_test1_sxwid;
output wire [(32)-1:0] i_test1_sxwdata;
output wire [(32/8)-1:0] i_test1_sxwstrb;
output wire i_test1_sxwlast;
output wire i_test1_sxbready;
input wire i_test1_sxbvalid;
input wire [(1)-1:0] i_test1_sxbid;
input wire [(2)-1:0] i_test1_sxbresp;
input wire i_test1_sxarready;
output wire i_test1_sxarvalid;
output wire [(32)-1:0] i_test1_sxaraddr;
output wire [(1)-1:0] i_test1_sxarid;
output wire [(8)-1:0] i_test1_sxarlen;
output wire [(3)-1:0] i_test1_sxarsize;
output wire [(2)-1:0] i_test1_sxarburst;
output wire i_test1_sxrready;
input wire i_test1_sxrvalid;
input wire [(1)-1:0] i_test1_sxrid;
input wire [(32)-1:0] i_test1_sxrdata;
input wire i_test1_sxrlast;
input wire [(2)-1:0] i_test1_sxrresp;
input wire i_system_sram_sxawready;
output wire i_system_sram_sxawvalid;
output wire [(32)-1:0] i_system_sram_sxawaddr;
output wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_system_sram_sxawid;
output wire [(8)-1:0] i_system_sram_sxawlen;
output wire [(3)-1:0] i_system_sram_sxawsize;
output wire [(2)-1:0] i_system_sram_sxawburst;
input wire i_system_sram_sxwready;
output wire i_system_sram_sxwvalid;
output wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_system_sram_sxwid;
output wire [(32)-1:0] i_system_sram_sxwdata;
output wire [(32/8)-1:0] i_system_sram_sxwstrb;
output wire i_system_sram_sxwlast;
output wire i_system_sram_sxbready;
input wire i_system_sram_sxbvalid;
input wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_system_sram_sxbid;
input wire [(2)-1:0] i_system_sram_sxbresp;
input wire i_system_sram_sxarready;
output wire i_system_sram_sxarvalid;
output wire [(32)-1:0] i_system_sram_sxaraddr;
output wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_system_sram_sxarid;
output wire [(8)-1:0] i_system_sram_sxarlen;
output wire [(3)-1:0] i_system_sram_sxarsize;
output wire [(2)-1:0] i_system_sram_sxarburst;
output wire i_system_sram_sxrready;
input wire i_system_sram_sxrvalid;
input wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_system_sram_sxrid;
input wire [(32)-1:0] i_system_sram_sxrdata;
input wire i_system_sram_sxrlast;
input wire [(2)-1:0] i_system_sram_sxrresp;


wire autoname_63;
wire rstnn_noc;
wire i_main_core_clk;
wire i_main_core_rstnn;
wire [(32)-1:0] i_main_core_interrupt_vector;
wire i_main_core_interrupt_out;
wire i_main_core_sxawready;
wire i_main_core_sxawvalid;
wire [(32)-1:0] i_main_core_sxawaddr;
wire [(4)-1:0] i_main_core_sxawid;
wire [(8)-1:0] i_main_core_sxawlen;
wire [(3)-1:0] i_main_core_sxawsize;
wire [(2)-1:0] i_main_core_sxawburst;
wire i_main_core_sxwready;
wire i_main_core_sxwvalid;
wire [(4)-1:0] i_main_core_sxwid;
wire [(32)-1:0] i_main_core_sxwdata;
wire [(32/8)-1:0] i_main_core_sxwstrb;
wire i_main_core_sxwlast;
wire i_main_core_sxbready;
wire i_main_core_sxbvalid;
wire [(4)-1:0] i_main_core_sxbid;
wire [(2)-1:0] i_main_core_sxbresp;
wire i_main_core_sxarready;
wire i_main_core_sxarvalid;
wire [(32)-1:0] i_main_core_sxaraddr;
wire [(4)-1:0] i_main_core_sxarid;
wire [(8)-1:0] i_main_core_sxarlen;
wire [(3)-1:0] i_main_core_sxarsize;
wire [(2)-1:0] i_main_core_sxarburst;
wire i_main_core_sxrready;
wire i_main_core_sxrvalid;
wire [(4)-1:0] i_main_core_sxrid;
wire [(32)-1:0] i_main_core_sxrdata;
wire i_main_core_sxrlast;
wire [(2)-1:0] i_main_core_sxrresp;
wire [(32)-1:0] i_main_core_spc;
wire [(32)-1:0] i_main_core_sinst;
wire i_sub_core_001_clk;
wire i_sub_core_001_rstnn;
wire [(32)-1:0] i_sub_core_001_interrupt_vector;
wire i_sub_core_001_interrupt_out;
wire i_sub_core_001_sxawready;
wire i_sub_core_001_sxawvalid;
wire [(32)-1:0] i_sub_core_001_sxawaddr;
wire [(4)-1:0] i_sub_core_001_sxawid;
wire [(8)-1:0] i_sub_core_001_sxawlen;
wire [(3)-1:0] i_sub_core_001_sxawsize;
wire [(2)-1:0] i_sub_core_001_sxawburst;
wire i_sub_core_001_sxwready;
wire i_sub_core_001_sxwvalid;
wire [(4)-1:0] i_sub_core_001_sxwid;
wire [(32)-1:0] i_sub_core_001_sxwdata;
wire [(32/8)-1:0] i_sub_core_001_sxwstrb;
wire i_sub_core_001_sxwlast;
wire i_sub_core_001_sxbready;
wire i_sub_core_001_sxbvalid;
wire [(4)-1:0] i_sub_core_001_sxbid;
wire [(2)-1:0] i_sub_core_001_sxbresp;
wire i_sub_core_001_sxarready;
wire i_sub_core_001_sxarvalid;
wire [(32)-1:0] i_sub_core_001_sxaraddr;
wire [(4)-1:0] i_sub_core_001_sxarid;
wire [(8)-1:0] i_sub_core_001_sxarlen;
wire [(3)-1:0] i_sub_core_001_sxarsize;
wire [(2)-1:0] i_sub_core_001_sxarburst;
wire i_sub_core_001_sxrready;
wire i_sub_core_001_sxrvalid;
wire [(4)-1:0] i_sub_core_001_sxrid;
wire [(32)-1:0] i_sub_core_001_sxrdata;
wire i_sub_core_001_sxrlast;
wire [(2)-1:0] i_sub_core_001_sxrresp;
wire [(32)-1:0] i_sub_core_001_spc;
wire [(32)-1:0] i_sub_core_001_sinst;
wire i_led_clk;
wire i_led_tick_62d5ms;
wire i_led_rstnn;
wire i_led_app_finished;
wire [((1)*(1))-1:0] i_led_led_list;
wire i_gpio_uwb_reset_clk;
wire i_gpio_uwb_reset_rstnn;
wire i_gpio_uwb_reset_tick_gpio;
wire i_gpio_uwb_reset_rwenable;
wire [(32)-1:0] i_gpio_uwb_reset_rwdata;
wire i_gpio_uwb_reset_rrenable;
wire [(32)-1:0] i_gpio_uwb_reset_rrdata;
wire [(`BW_GPIO_VALUE)-1:0] i_gpio_uwb_reset_ruser_pinout;
wire [(`BW_GPIO_VALUE)-1:0] i_gpio_uwb_reset_ruser_pinin;
wire i_gpio_uwb_reset_rinterrupt;
wire [(1)-1:0] i_gpio_uwb_reset_gpio_soe;
wire [(1)-1:0] i_gpio_uwb_reset_gpio_soval;
wire [(1)-1:0] i_gpio_uwb_reset_gpio_sival;
wire common_peri_group_clk;
wire common_peri_group_rstnn;
wire [(7)-1:0] common_peri_group_lock_status_list;
wire [(64)-1:0] common_peri_group_real_clock;
wire [(2)-1:0] common_peri_group_global_tag_list;
wire [(11)-1:0] common_peri_group_system_tick_config;
wire [(11)-1:0] common_peri_group_core_tick_config;
wire common_peri_group_rpsel;
wire common_peri_group_rpenable;
wire common_peri_group_rpwrite;
wire [(32)-1:0] common_peri_group_rpaddr;
wire [(32)-1:0] common_peri_group_rpwdata;
wire common_peri_group_rpready;
wire [(32)-1:0] common_peri_group_rprdata;
wire common_peri_group_rpslverr;
wire autoname_62_clk;
wire autoname_62_rstnn;
wire [(11)-1:0] autoname_62_tick_config;
wire autoname_62_tick_1us;
wire autoname_62_tick_62d5ms;
wire autoname_64_clk;
wire autoname_64_rstnn;
wire autoname_64_tick_1us;
wire [(64)-1:0] autoname_64_real_clock;
wire external_peri_group_clk;
wire external_peri_group_rstnn;
wire external_peri_group_tick_1us;
wire external_peri_group_tick_gpio;
wire [(32)-1:0] external_peri_group_uart_interrupts;
wire external_peri_group_spi_interrupt;
wire [(32)-1:0] external_peri_group_i2c_interrupts;
wire [(32)-1:0] external_peri_group_gpio_interrupts;
wire external_peri_group_wifi_interrupt;
wire external_peri_group_spi_common_sclk;
wire external_peri_group_spi_common_sdq0;
wire [(`BW_GPIO_VALUE*`NUM_GPIO)-1:0] external_peri_group_user_pinout_list;
wire [(`BW_GPIO_VALUE*`NUM_GPIO)-1:0] external_peri_group_user_pinin_list;
wire external_peri_group_rpsel;
wire external_peri_group_rpenable;
wire external_peri_group_rpwrite;
wire [(32)-1:0] external_peri_group_rpaddr;
wire [(32)-1:0] external_peri_group_rpwdata;
wire external_peri_group_rpready;
wire [(32)-1:0] external_peri_group_rprdata;
wire external_peri_group_rpslverr;
wire [((1)*(2))-1:0] external_peri_group_uart_stx_list;
wire [((1)*(2))-1:0] external_peri_group_uart_srx_list;
wire [((1)*(2))-1:0] external_peri_group_spi_sclk_list;
wire [((1)*(2))-1:0] external_peri_group_spi_scs_list;
wire [((1)*(2))-1:0] external_peri_group_spi_sdq0_list;
wire [((1)*(2))-1:0] external_peri_group_spi_sdq1_list;
wire [(1)-1:0] external_peri_group_oled_sdcsel_oe;
wire [(1)-1:0] external_peri_group_oled_sdcsel_oval;
wire [(1)-1:0] external_peri_group_oled_sdcsel_ival;
wire [(1)-1:0] external_peri_group_oled_srstnn_oe;
wire [(1)-1:0] external_peri_group_oled_srstnn_oval;
wire [(1)-1:0] external_peri_group_oled_srstnn_ival;
wire [(1)-1:0] external_peri_group_oled_svbat_oe;
wire [(1)-1:0] external_peri_group_oled_svbat_oval;
wire [(1)-1:0] external_peri_group_oled_svbat_ival;
wire [(1)-1:0] external_peri_group_oled_svdd_oe;
wire [(1)-1:0] external_peri_group_oled_svdd_oval;
wire [(1)-1:0] external_peri_group_oled_svdd_ival;
wire external_peri_group_wifi_sitr;
wire external_peri_group_wifi_srstnn;
wire external_peri_group_wifi_swp;
wire external_peri_group_wifi_shibernate;
wire [((1)*(1))-1:0] external_peri_group_gpio_swenable_list;
wire [((32)*(1))-1:0] external_peri_group_gpio_swdata_list;
wire [((1)*(1))-1:0] external_peri_group_gpio_srenable_list;
wire [((32)*(1))-1:0] external_peri_group_gpio_srdata_list;
wire [((`BW_GPIO_VALUE)*(1))-1:0] external_peri_group_gpio_suser_pinout_list;
wire [((`BW_GPIO_VALUE)*(1))-1:0] external_peri_group_gpio_suser_pinin_list;
wire [((1)*(1))-1:0] external_peri_group_gpio_sinterrupt_list;
wire core_peri_group_clk;
wire core_peri_group_rstnn;
wire core_peri_group_tick_1us;
wire core_peri_group_delay_notice;
wire core_peri_group_plic_interrupt;
wire [(7)-1:0] core_peri_group_lock_status_list;
wire [(2)-1:0] core_peri_group_global_tag_list;
wire [(32)-1:0] core_peri_group_core_interrupt_vector;
wire core_peri_group_allows_holds;
wire core_peri_group_rpsel;
wire core_peri_group_rpenable;
wire core_peri_group_rpwrite;
wire [(32)-1:0] core_peri_group_rpaddr;
wire [(32)-1:0] core_peri_group_rpwdata;
wire core_peri_group_rpready;
wire [(32)-1:0] core_peri_group_rprdata;
wire core_peri_group_rpslverr;
wire core_peri_group_tcu_spsel;
wire core_peri_group_tcu_spenable;
wire core_peri_group_tcu_spwrite;
wire [(32)-1:0] core_peri_group_tcu_spaddr;
wire [(32)-1:0] core_peri_group_tcu_spwdata;
wire core_peri_group_tcu_spready;
wire [(32)-1:0] core_peri_group_tcu_sprdata;
wire core_peri_group_tcu_spslverr;
wire core_peri_group_florian_spsel;
wire core_peri_group_florian_spenable;
wire core_peri_group_florian_spwrite;
wire [(32)-1:0] core_peri_group_florian_spaddr;
wire [(32)-1:0] core_peri_group_florian_spwdata;
wire core_peri_group_florian_spready;
wire [(32)-1:0] core_peri_group_florian_sprdata;
wire core_peri_group_florian_spslverr;
wire autoname_65_clk;
wire autoname_65_rstnn;
wire autoname_65_tick_1us;
wire autoname_65_delay_notice;
wire autoname_65_plic_interrupt;
wire [(7)-1:0] autoname_65_lock_status_list;
wire [(2)-1:0] autoname_65_global_tag_list;
wire [(32)-1:0] autoname_65_core_interrupt_vector;
wire autoname_65_allows_holds;
wire autoname_65_rpsel;
wire autoname_65_rpenable;
wire autoname_65_rpwrite;
wire [(32)-1:0] autoname_65_rpaddr;
wire [(32)-1:0] autoname_65_rpwdata;
wire autoname_65_rpready;
wire [(32)-1:0] autoname_65_rprdata;
wire autoname_65_rpslverr;
wire autoname_65_tcu_spsel;
wire autoname_65_tcu_spenable;
wire autoname_65_tcu_spwrite;
wire [(32)-1:0] autoname_65_tcu_spaddr;
wire [(32)-1:0] autoname_65_tcu_spwdata;
wire autoname_65_tcu_spready;
wire [(32)-1:0] autoname_65_tcu_sprdata;
wire autoname_65_tcu_spslverr;
wire autoname_65_florian_spsel;
wire autoname_65_florian_spenable;
wire autoname_65_florian_spwrite;
wire [(32)-1:0] autoname_65_florian_spaddr;
wire [(32)-1:0] autoname_65_florian_spwdata;
wire autoname_65_florian_spready;
wire [(32)-1:0] autoname_65_florian_sprdata;
wire autoname_65_florian_spslverr;
wire platform_controller_clk;
wire platform_controller_external_rstnn;
wire platform_controller_global_rstnn;
wire platform_controller_global_rstpp;
wire [(8)-1:0] platform_controller_rstnn_seqeunce;
wire [(8)-1:0] platform_controller_rstpp_seqeunce;
wire [(`BW_BOOT_MODE)-1:0] platform_controller_boot_mode;
wire platform_controller_jtag_select;
wire platform_controller_initialized;
wire platform_controller_app_finished;
wire platform_controller_rstnn;
wire platform_controller_shready;
wire [(32)-1:0] platform_controller_shaddr;
wire [(3)-1:0] platform_controller_shburst;
wire platform_controller_shmasterlock;
wire [(4)-1:0] platform_controller_shprot;
wire [(3)-1:0] platform_controller_shsize;
wire [(2)-1:0] platform_controller_shtrans;
wire platform_controller_shwrite;
wire [(32)-1:0] platform_controller_shwdata;
wire [(32)-1:0] platform_controller_shrdata;
wire platform_controller_shresp;
wire platform_controller_rpsel;
wire platform_controller_rpenable;
wire platform_controller_rpwrite;
wire [(32)-1:0] platform_controller_rpaddr;
wire [(32)-1:0] platform_controller_rpwdata;
wire platform_controller_rpready;
wire [(32)-1:0] platform_controller_rprdata;
wire platform_controller_rpslverr;
wire platform_controller_pjtag_rtck;
wire platform_controller_pjtag_rtrstnn;
wire platform_controller_pjtag_rtms;
wire platform_controller_pjtag_rtdi;
wire platform_controller_pjtag_rtdo;
wire platform_controller_noc_debug_spsel;
wire platform_controller_noc_debug_spenable;
wire platform_controller_noc_debug_spwrite;
wire [(32)-1:0] platform_controller_noc_debug_spaddr;
wire [(32)-1:0] platform_controller_noc_debug_spwdata;
wire platform_controller_noc_debug_spready;
wire [(32)-1:0] platform_controller_noc_debug_sprdata;
wire platform_controller_noc_debug_spslverr;
wire [((32)*(2))-1:0] platform_controller_rpc_list;
wire [((32)*(2))-1:0] platform_controller_rinst_list;
wire default_slave_clk_network;
wire default_slave_rstnn_network;
wire default_slave_clk_debug;
wire default_slave_rstnn_debug;
wire default_slave_comm_disable;
wire [(`BW_FNI_LINK(BW_FNI_PHIT))-1:0] default_slave_rfni_link;
wire default_slave_rfni_ready;
wire [(`BW_BNI_LINK(BW_BNI_PHIT))-1:0] default_slave_rbni_link;
wire default_slave_rbni_ready;
wire default_slave_debug_rpsel;
wire default_slave_debug_rpenable;
wire default_slave_debug_rpwrite;
wire [(32)-1:0] default_slave_debug_rpaddr;
wire [(32)-1:0] default_slave_debug_rpwdata;
wire default_slave_debug_rpready;
wire [(32)-1:0] default_slave_debug_rprdata;
wire default_slave_debug_rpslverr;
wire [(`BW_SVRING_LINK)-1:0] default_slave_svri_rlink;
wire default_slave_svri_rack;
wire [(`BW_SVRING_LINK)-1:0] default_slave_svri_slink;
wire default_slave_svri_sack;
wire i_mnim_i_main_core_no_name_clk;
wire i_mnim_i_main_core_no_name_rstnn;
wire i_mnim_i_main_core_no_name_comm_disable;
wire i_mnim_i_main_core_no_name_local_allows_holds;
wire i_mnim_i_main_core_no_name_rxawready;
wire i_mnim_i_main_core_no_name_rxawvalid;
wire [(32)-1:0] i_mnim_i_main_core_no_name_rxawaddr;
wire [(4)-1:0] i_mnim_i_main_core_no_name_rxawid;
wire [(8)-1:0] i_mnim_i_main_core_no_name_rxawlen;
wire [(3)-1:0] i_mnim_i_main_core_no_name_rxawsize;
wire [(2)-1:0] i_mnim_i_main_core_no_name_rxawburst;
wire i_mnim_i_main_core_no_name_rxwready;
wire i_mnim_i_main_core_no_name_rxwvalid;
wire [(4)-1:0] i_mnim_i_main_core_no_name_rxwid;
wire [(32)-1:0] i_mnim_i_main_core_no_name_rxwdata;
wire [(32/8)-1:0] i_mnim_i_main_core_no_name_rxwstrb;
wire i_mnim_i_main_core_no_name_rxwlast;
wire i_mnim_i_main_core_no_name_rxbready;
wire i_mnim_i_main_core_no_name_rxbvalid;
wire [(4)-1:0] i_mnim_i_main_core_no_name_rxbid;
wire [(2)-1:0] i_mnim_i_main_core_no_name_rxbresp;
wire i_mnim_i_main_core_no_name_rxarready;
wire i_mnim_i_main_core_no_name_rxarvalid;
wire [(32)-1:0] i_mnim_i_main_core_no_name_rxaraddr;
wire [(4)-1:0] i_mnim_i_main_core_no_name_rxarid;
wire [(8)-1:0] i_mnim_i_main_core_no_name_rxarlen;
wire [(3)-1:0] i_mnim_i_main_core_no_name_rxarsize;
wire [(2)-1:0] i_mnim_i_main_core_no_name_rxarburst;
wire i_mnim_i_main_core_no_name_rxrready;
wire i_mnim_i_main_core_no_name_rxrvalid;
wire [(4)-1:0] i_mnim_i_main_core_no_name_rxrid;
wire [(32)-1:0] i_mnim_i_main_core_no_name_rxrdata;
wire i_mnim_i_main_core_no_name_rxrlast;
wire [(2)-1:0] i_mnim_i_main_core_no_name_rxrresp;
wire [(`BW_FNI_LINK(BW_FNI_PHIT))-1:0] i_mnim_i_main_core_no_name_sfni_link;
wire i_mnim_i_main_core_no_name_sfni_ready;
wire [(`BW_BNI_LINK(BW_BNI_PHIT))-1:0] i_mnim_i_main_core_no_name_sbni_link;
wire i_mnim_i_main_core_no_name_sbni_ready;
wire [(`BW_SVRING_LINK)-1:0] i_mnim_i_main_core_no_name_svri_rlink;
wire i_mnim_i_main_core_no_name_svri_rack;
wire [(`BW_SVRING_LINK)-1:0] i_mnim_i_main_core_no_name_svri_slink;
wire i_mnim_i_main_core_no_name_svri_sack;
wire i_mnim_i_main_core_no_name_local_spsel;
wire i_mnim_i_main_core_no_name_local_spenable;
wire i_mnim_i_main_core_no_name_local_spwrite;
wire [(32)-1:0] i_mnim_i_main_core_no_name_local_spaddr;
wire [(32)-1:0] i_mnim_i_main_core_no_name_local_spwdata;
wire i_mnim_i_main_core_no_name_local_spready;
wire [(32)-1:0] i_mnim_i_main_core_no_name_local_sprdata;
wire i_mnim_i_main_core_no_name_local_spslverr;
wire i_mnim_i_sub_core_001_no_name_clk;
wire i_mnim_i_sub_core_001_no_name_rstnn;
wire i_mnim_i_sub_core_001_no_name_comm_disable;
wire i_mnim_i_sub_core_001_no_name_local_allows_holds;
wire i_mnim_i_sub_core_001_no_name_rxawready;
wire i_mnim_i_sub_core_001_no_name_rxawvalid;
wire [(32)-1:0] i_mnim_i_sub_core_001_no_name_rxawaddr;
wire [(4)-1:0] i_mnim_i_sub_core_001_no_name_rxawid;
wire [(8)-1:0] i_mnim_i_sub_core_001_no_name_rxawlen;
wire [(3)-1:0] i_mnim_i_sub_core_001_no_name_rxawsize;
wire [(2)-1:0] i_mnim_i_sub_core_001_no_name_rxawburst;
wire i_mnim_i_sub_core_001_no_name_rxwready;
wire i_mnim_i_sub_core_001_no_name_rxwvalid;
wire [(4)-1:0] i_mnim_i_sub_core_001_no_name_rxwid;
wire [(32)-1:0] i_mnim_i_sub_core_001_no_name_rxwdata;
wire [(32/8)-1:0] i_mnim_i_sub_core_001_no_name_rxwstrb;
wire i_mnim_i_sub_core_001_no_name_rxwlast;
wire i_mnim_i_sub_core_001_no_name_rxbready;
wire i_mnim_i_sub_core_001_no_name_rxbvalid;
wire [(4)-1:0] i_mnim_i_sub_core_001_no_name_rxbid;
wire [(2)-1:0] i_mnim_i_sub_core_001_no_name_rxbresp;
wire i_mnim_i_sub_core_001_no_name_rxarready;
wire i_mnim_i_sub_core_001_no_name_rxarvalid;
wire [(32)-1:0] i_mnim_i_sub_core_001_no_name_rxaraddr;
wire [(4)-1:0] i_mnim_i_sub_core_001_no_name_rxarid;
wire [(8)-1:0] i_mnim_i_sub_core_001_no_name_rxarlen;
wire [(3)-1:0] i_mnim_i_sub_core_001_no_name_rxarsize;
wire [(2)-1:0] i_mnim_i_sub_core_001_no_name_rxarburst;
wire i_mnim_i_sub_core_001_no_name_rxrready;
wire i_mnim_i_sub_core_001_no_name_rxrvalid;
wire [(4)-1:0] i_mnim_i_sub_core_001_no_name_rxrid;
wire [(32)-1:0] i_mnim_i_sub_core_001_no_name_rxrdata;
wire i_mnim_i_sub_core_001_no_name_rxrlast;
wire [(2)-1:0] i_mnim_i_sub_core_001_no_name_rxrresp;
wire [(`BW_FNI_LINK(BW_FNI_PHIT))-1:0] i_mnim_i_sub_core_001_no_name_sfni_link;
wire i_mnim_i_sub_core_001_no_name_sfni_ready;
wire [(`BW_BNI_LINK(BW_BNI_PHIT))-1:0] i_mnim_i_sub_core_001_no_name_sbni_link;
wire i_mnim_i_sub_core_001_no_name_sbni_ready;
wire [(`BW_SVRING_LINK)-1:0] i_mnim_i_sub_core_001_no_name_svri_rlink;
wire i_mnim_i_sub_core_001_no_name_svri_rack;
wire [(`BW_SVRING_LINK)-1:0] i_mnim_i_sub_core_001_no_name_svri_slink;
wire i_mnim_i_sub_core_001_no_name_svri_sack;
wire i_mnim_i_sub_core_001_no_name_local_spsel;
wire i_mnim_i_sub_core_001_no_name_local_spenable;
wire i_mnim_i_sub_core_001_no_name_local_spwrite;
wire [(32)-1:0] i_mnim_i_sub_core_001_no_name_local_spaddr;
wire [(32)-1:0] i_mnim_i_sub_core_001_no_name_local_spwdata;
wire i_mnim_i_sub_core_001_no_name_local_spready;
wire [(32)-1:0] i_mnim_i_sub_core_001_no_name_local_sprdata;
wire i_mnim_i_sub_core_001_no_name_local_spslverr;
wire i_mnim_platform_controller_master_clk;
wire i_mnim_platform_controller_master_rstnn;
wire i_mnim_platform_controller_master_comm_disable;
wire i_mnim_platform_controller_master_rhready;
wire [(32)-1:0] i_mnim_platform_controller_master_rhaddr;
wire [(3)-1:0] i_mnim_platform_controller_master_rhburst;
wire i_mnim_platform_controller_master_rhmasterlock;
wire [(4)-1:0] i_mnim_platform_controller_master_rhprot;
wire [(3)-1:0] i_mnim_platform_controller_master_rhsize;
wire [(2)-1:0] i_mnim_platform_controller_master_rhtrans;
wire i_mnim_platform_controller_master_rhwrite;
wire [(32)-1:0] i_mnim_platform_controller_master_rhwdata;
wire [(32)-1:0] i_mnim_platform_controller_master_rhrdata;
wire i_mnim_platform_controller_master_rhresp;
wire [(`BW_FNI_LINK(BW_FNI_PHIT))-1:0] i_mnim_platform_controller_master_sfni_link;
wire i_mnim_platform_controller_master_sfni_ready;
wire [(`BW_BNI_LINK(BW_BNI_PHIT))-1:0] i_mnim_platform_controller_master_sbni_link;
wire i_mnim_platform_controller_master_sbni_ready;
wire [(`BW_SVRING_LINK)-1:0] i_mnim_platform_controller_master_svri_rlink;
wire i_mnim_platform_controller_master_svri_rack;
wire [(`BW_SVRING_LINK)-1:0] i_mnim_platform_controller_master_svri_slink;
wire i_mnim_platform_controller_master_svri_sack;
wire i_snim_i_test1_slave_clk;
wire i_snim_i_test1_slave_rstnn;
wire i_snim_i_test1_slave_comm_disable;
wire i_snim_i_test1_slave_sxawready;
wire i_snim_i_test1_slave_sxawvalid;
wire [(32)-1:0] i_snim_i_test1_slave_sxawaddr;
wire [(1)-1:0] i_snim_i_test1_slave_sxawid;
wire [(8)-1:0] i_snim_i_test1_slave_sxawlen;
wire [(3)-1:0] i_snim_i_test1_slave_sxawsize;
wire [(2)-1:0] i_snim_i_test1_slave_sxawburst;
wire i_snim_i_test1_slave_sxwready;
wire i_snim_i_test1_slave_sxwvalid;
wire [(1)-1:0] i_snim_i_test1_slave_sxwid;
wire [(32)-1:0] i_snim_i_test1_slave_sxwdata;
wire [(32/8)-1:0] i_snim_i_test1_slave_sxwstrb;
wire i_snim_i_test1_slave_sxwlast;
wire i_snim_i_test1_slave_sxbready;
wire i_snim_i_test1_slave_sxbvalid;
wire [(1)-1:0] i_snim_i_test1_slave_sxbid;
wire [(2)-1:0] i_snim_i_test1_slave_sxbresp;
wire i_snim_i_test1_slave_sxarready;
wire i_snim_i_test1_slave_sxarvalid;
wire [(32)-1:0] i_snim_i_test1_slave_sxaraddr;
wire [(1)-1:0] i_snim_i_test1_slave_sxarid;
wire [(8)-1:0] i_snim_i_test1_slave_sxarlen;
wire [(3)-1:0] i_snim_i_test1_slave_sxarsize;
wire [(2)-1:0] i_snim_i_test1_slave_sxarburst;
wire i_snim_i_test1_slave_sxrready;
wire i_snim_i_test1_slave_sxrvalid;
wire [(1)-1:0] i_snim_i_test1_slave_sxrid;
wire [(32)-1:0] i_snim_i_test1_slave_sxrdata;
wire i_snim_i_test1_slave_sxrlast;
wire [(2)-1:0] i_snim_i_test1_slave_sxrresp;
wire [(`BW_FNI_LINK(BW_FNI_PHIT))-1:0] i_snim_i_test1_slave_rfni_link;
wire i_snim_i_test1_slave_rfni_ready;
wire [(`BW_BNI_LINK(BW_BNI_PHIT))-1:0] i_snim_i_test1_slave_rbni_link;
wire i_snim_i_test1_slave_rbni_ready;
wire [(`BW_SVRING_LINK)-1:0] i_snim_i_test1_slave_svri_rlink;
wire i_snim_i_test1_slave_svri_rack;
wire [(`BW_SVRING_LINK)-1:0] i_snim_i_test1_slave_svri_slink;
wire i_snim_i_test1_slave_svri_sack;
wire i_snim_i_system_sram_no_name_clk;
wire i_snim_i_system_sram_no_name_rstnn;
wire i_snim_i_system_sram_no_name_comm_disable;
wire i_snim_i_system_sram_no_name_sxawready;
wire i_snim_i_system_sram_no_name_sxawvalid;
wire [(32)-1:0] i_snim_i_system_sram_no_name_sxawaddr;
wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_snim_i_system_sram_no_name_sxawid;
wire [(8)-1:0] i_snim_i_system_sram_no_name_sxawlen;
wire [(3)-1:0] i_snim_i_system_sram_no_name_sxawsize;
wire [(2)-1:0] i_snim_i_system_sram_no_name_sxawburst;
wire i_snim_i_system_sram_no_name_sxwready;
wire i_snim_i_system_sram_no_name_sxwvalid;
wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_snim_i_system_sram_no_name_sxwid;
wire [(32)-1:0] i_snim_i_system_sram_no_name_sxwdata;
wire [(32/8)-1:0] i_snim_i_system_sram_no_name_sxwstrb;
wire i_snim_i_system_sram_no_name_sxwlast;
wire i_snim_i_system_sram_no_name_sxbready;
wire i_snim_i_system_sram_no_name_sxbvalid;
wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_snim_i_system_sram_no_name_sxbid;
wire [(2)-1:0] i_snim_i_system_sram_no_name_sxbresp;
wire i_snim_i_system_sram_no_name_sxarready;
wire i_snim_i_system_sram_no_name_sxarvalid;
wire [(32)-1:0] i_snim_i_system_sram_no_name_sxaraddr;
wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_snim_i_system_sram_no_name_sxarid;
wire [(8)-1:0] i_snim_i_system_sram_no_name_sxarlen;
wire [(3)-1:0] i_snim_i_system_sram_no_name_sxarsize;
wire [(2)-1:0] i_snim_i_system_sram_no_name_sxarburst;
wire i_snim_i_system_sram_no_name_sxrready;
wire i_snim_i_system_sram_no_name_sxrvalid;
wire [(`REQUIRED_BW_OF_SLAVE_TID)-1:0] i_snim_i_system_sram_no_name_sxrid;
wire [(32)-1:0] i_snim_i_system_sram_no_name_sxrdata;
wire i_snim_i_system_sram_no_name_sxrlast;
wire [(2)-1:0] i_snim_i_system_sram_no_name_sxrresp;
wire [(`BW_FNI_LINK(BW_FNI_PHIT))-1:0] i_snim_i_system_sram_no_name_rfni_link;
wire i_snim_i_system_sram_no_name_rfni_ready;
wire [(`BW_BNI_LINK(BW_BNI_PHIT))-1:0] i_snim_i_system_sram_no_name_rbni_link;
wire i_snim_i_system_sram_no_name_rbni_ready;
wire [(`BW_SVRING_LINK)-1:0] i_snim_i_system_sram_no_name_svri_rlink;
wire i_snim_i_system_sram_no_name_svri_rack;
wire [(`BW_SVRING_LINK)-1:0] i_snim_i_system_sram_no_name_svri_slink;
wire i_snim_i_system_sram_no_name_svri_sack;
wire i_snim_common_peri_group_no_name_clk;
wire i_snim_common_peri_group_no_name_rstnn;
wire i_snim_common_peri_group_no_name_comm_disable;
wire i_snim_common_peri_group_no_name_spsel;
wire i_snim_common_peri_group_no_name_spenable;
wire i_snim_common_peri_group_no_name_spwrite;
wire [(32)-1:0] i_snim_common_peri_group_no_name_spaddr;
wire [(32)-1:0] i_snim_common_peri_group_no_name_spwdata;
wire i_snim_common_peri_group_no_name_spready;
wire [(32)-1:0] i_snim_common_peri_group_no_name_sprdata;
wire i_snim_common_peri_group_no_name_spslverr;
wire [(`BW_FNI_LINK(BW_FNI_PHIT))-1:0] i_snim_common_peri_group_no_name_rfni_link;
wire i_snim_common_peri_group_no_name_rfni_ready;
wire [(`BW_BNI_LINK(BW_BNI_PHIT))-1:0] i_snim_common_peri_group_no_name_rbni_link;
wire i_snim_common_peri_group_no_name_rbni_ready;
wire [(`BW_SVRING_LINK)-1:0] i_snim_common_peri_group_no_name_svri_rlink;
wire i_snim_common_peri_group_no_name_svri_rack;
wire [(`BW_SVRING_LINK)-1:0] i_snim_common_peri_group_no_name_svri_slink;
wire i_snim_common_peri_group_no_name_svri_sack;
wire i_snim_external_peri_group_no_name_clk;
wire i_snim_external_peri_group_no_name_rstnn;
wire i_snim_external_peri_group_no_name_comm_disable;
wire i_snim_external_peri_group_no_name_spsel;
wire i_snim_external_peri_group_no_name_spenable;
wire i_snim_external_peri_group_no_name_spwrite;
wire [(32)-1:0] i_snim_external_peri_group_no_name_spaddr;
wire [(32)-1:0] i_snim_external_peri_group_no_name_spwdata;
wire i_snim_external_peri_group_no_name_spready;
wire [(32)-1:0] i_snim_external_peri_group_no_name_sprdata;
wire i_snim_external_peri_group_no_name_spslverr;
wire [(`BW_FNI_LINK(BW_FNI_PHIT))-1:0] i_snim_external_peri_group_no_name_rfni_link;
wire i_snim_external_peri_group_no_name_rfni_ready;
wire [(`BW_BNI_LINK(BW_BNI_PHIT))-1:0] i_snim_external_peri_group_no_name_rbni_link;
wire i_snim_external_peri_group_no_name_rbni_ready;
wire [(`BW_SVRING_LINK)-1:0] i_snim_external_peri_group_no_name_svri_rlink;
wire i_snim_external_peri_group_no_name_svri_rack;
wire [(`BW_SVRING_LINK)-1:0] i_snim_external_peri_group_no_name_svri_slink;
wire i_snim_external_peri_group_no_name_svri_sack;
wire i_snim_platform_controller_no_name_clk;
wire i_snim_platform_controller_no_name_rstnn;
wire i_snim_platform_controller_no_name_comm_disable;
wire i_snim_platform_controller_no_name_spsel;
wire i_snim_platform_controller_no_name_spenable;
wire i_snim_platform_controller_no_name_spwrite;
wire [(32)-1:0] i_snim_platform_controller_no_name_spaddr;
wire [(32)-1:0] i_snim_platform_controller_no_name_spwdata;
wire i_snim_platform_controller_no_name_spready;
wire [(32)-1:0] i_snim_platform_controller_no_name_sprdata;
wire i_snim_platform_controller_no_name_spslverr;
wire [(`BW_FNI_LINK(BW_FNI_PHIT))-1:0] i_snim_platform_controller_no_name_rfni_link;
wire i_snim_platform_controller_no_name_rfni_ready;
wire [(`BW_BNI_LINK(BW_BNI_PHIT))-1:0] i_snim_platform_controller_no_name_rbni_link;
wire i_snim_platform_controller_no_name_rbni_ready;
wire [(`BW_SVRING_LINK)-1:0] i_snim_platform_controller_no_name_svri_rlink;
wire i_snim_platform_controller_no_name_svri_rack;
wire [(`BW_SVRING_LINK)-1:0] i_snim_platform_controller_no_name_svri_slink;
wire i_snim_platform_controller_no_name_svri_sack;
wire i_system_router_clk;
wire i_system_router_rstnn;
wire [((`BW_FNI_LINK(BW_FNI_PHIT))*(3))-1:0] i_system_router_rfni_link_list;
wire [((1)*(3))-1:0] i_system_router_rfni_ready_list;
wire [((`BW_BNI_LINK(BW_BNI_PHIT))*(3))-1:0] i_system_router_rbni_link_list;
wire [((1)*(3))-1:0] i_system_router_rbni_ready_list;
wire [((`BW_FNI_LINK(BW_FNI_PHIT))*(6))-1:0] i_system_router_sfni_link_list;
wire [((1)*(6))-1:0] i_system_router_sfni_ready_list;
wire [((`BW_BNI_LINK(BW_BNI_PHIT))*(6))-1:0] i_system_router_sbni_link_list;
wire [((1)*(6))-1:0] i_system_router_sbni_ready_list;

RVC_ROCKET_MEDIUM
#(
	.ENABLE_INTERRUPTS(1),
	.NUM_INTERRUPTS(32)
)
i_main_core
(
	.clk(i_main_core_clk),
	.rstnn(i_main_core_rstnn),
	.interrupt_vector(i_main_core_interrupt_vector),
	.interrupt_out(i_main_core_interrupt_out),
	.sxawready(i_main_core_sxawready),
	.sxawvalid(i_main_core_sxawvalid),
	.sxawaddr(i_main_core_sxawaddr),
	.sxawid(i_main_core_sxawid),
	.sxawlen(i_main_core_sxawlen),
	.sxawsize(i_main_core_sxawsize),
	.sxawburst(i_main_core_sxawburst),
	.sxwready(i_main_core_sxwready),
	.sxwvalid(i_main_core_sxwvalid),
	.sxwid(i_main_core_sxwid),
	.sxwdata(i_main_core_sxwdata),
	.sxwstrb(i_main_core_sxwstrb),
	.sxwlast(i_main_core_sxwlast),
	.sxbready(i_main_core_sxbready),
	.sxbvalid(i_main_core_sxbvalid),
	.sxbid(i_main_core_sxbid),
	.sxbresp(i_main_core_sxbresp),
	.sxarready(i_main_core_sxarready),
	.sxarvalid(i_main_core_sxarvalid),
	.sxaraddr(i_main_core_sxaraddr),
	.sxarid(i_main_core_sxarid),
	.sxarlen(i_main_core_sxarlen),
	.sxarsize(i_main_core_sxarsize),
	.sxarburst(i_main_core_sxarburst),
	.sxrready(i_main_core_sxrready),
	.sxrvalid(i_main_core_sxrvalid),
	.sxrid(i_main_core_sxrid),
	.sxrdata(i_main_core_sxrdata),
	.sxrlast(i_main_core_sxrlast),
	.sxrresp(i_main_core_sxrresp),
	.spc(i_main_core_spc),
	.sinst(i_main_core_sinst)
);

RVC_ROCKET_MEDIUM
#(
	.ENABLE_INTERRUPTS(1),
	.NUM_INTERRUPTS(32)
)
i_sub_core_001
(
	.clk(i_sub_core_001_clk),
	.rstnn(i_sub_core_001_rstnn),
	.interrupt_vector(i_sub_core_001_interrupt_vector),
	.interrupt_out(i_sub_core_001_interrupt_out),
	.sxawready(i_sub_core_001_sxawready),
	.sxawvalid(i_sub_core_001_sxawvalid),
	.sxawaddr(i_sub_core_001_sxawaddr),
	.sxawid(i_sub_core_001_sxawid),
	.sxawlen(i_sub_core_001_sxawlen),
	.sxawsize(i_sub_core_001_sxawsize),
	.sxawburst(i_sub_core_001_sxawburst),
	.sxwready(i_sub_core_001_sxwready),
	.sxwvalid(i_sub_core_001_sxwvalid),
	.sxwid(i_sub_core_001_sxwid),
	.sxwdata(i_sub_core_001_sxwdata),
	.sxwstrb(i_sub_core_001_sxwstrb),
	.sxwlast(i_sub_core_001_sxwlast),
	.sxbready(i_sub_core_001_sxbready),
	.sxbvalid(i_sub_core_001_sxbvalid),
	.sxbid(i_sub_core_001_sxbid),
	.sxbresp(i_sub_core_001_sxbresp),
	.sxarready(i_sub_core_001_sxarready),
	.sxarvalid(i_sub_core_001_sxarvalid),
	.sxaraddr(i_sub_core_001_sxaraddr),
	.sxarid(i_sub_core_001_sxarid),
	.sxarlen(i_sub_core_001_sxarlen),
	.sxarsize(i_sub_core_001_sxarsize),
	.sxarburst(i_sub_core_001_sxarburst),
	.sxrready(i_sub_core_001_sxrready),
	.sxrvalid(i_sub_core_001_sxrvalid),
	.sxrid(i_sub_core_001_sxrid),
	.sxrdata(i_sub_core_001_sxrdata),
	.sxrlast(i_sub_core_001_sxrlast),
	.sxrresp(i_sub_core_001_sxrresp),
	.spc(i_sub_core_001_spc),
	.sinst(i_sub_core_001_sinst)
);

ERVP_LED_CHECKER
#(
	.NUM_LED(1)
)
i_led
(
	.clk(i_led_clk),
	.tick_62d5ms(i_led_tick_62d5ms),
	.rstnn(i_led_rstnn),
	.app_finished(i_led_app_finished),
	.led_list(i_led_led_list)
);

ERVP_GPIO
#(
	.BW_GPIO(1)
)
i_gpio_uwb_reset
(
	.clk(i_gpio_uwb_reset_clk),
	.rstnn(i_gpio_uwb_reset_rstnn),
	.tick_gpio(i_gpio_uwb_reset_tick_gpio),
	.rwenable(i_gpio_uwb_reset_rwenable),
	.rwdata(i_gpio_uwb_reset_rwdata),
	.rrenable(i_gpio_uwb_reset_rrenable),
	.rrdata(i_gpio_uwb_reset_rrdata),
	.ruser_pinout(i_gpio_uwb_reset_ruser_pinout),
	.ruser_pinin(i_gpio_uwb_reset_ruser_pinin),
	.rinterrupt(i_gpio_uwb_reset_rinterrupt),
	.gpio_soe(i_gpio_uwb_reset_gpio_soe),
	.gpio_soval(i_gpio_uwb_reset_gpio_soval),
	.gpio_sival(i_gpio_uwb_reset_gpio_sival)
);

ERVP_COMMON_PERI_GROUP
#(
	.BW_ADDR(32),
	.BW_DATA(32),
	.NUM_LOCK(7),
	.NUM_GLOBAL_TAG(2),
	.NUM_AUTO_ID(2)
)
common_peri_group
(
	.clk(common_peri_group_clk),
	.rstnn(common_peri_group_rstnn),
	.lock_status_list(common_peri_group_lock_status_list),
	.real_clock(common_peri_group_real_clock),
	.global_tag_list(common_peri_group_global_tag_list),
	.system_tick_config(common_peri_group_system_tick_config),
	.core_tick_config(common_peri_group_core_tick_config),
	.rpsel(common_peri_group_rpsel),
	.rpenable(common_peri_group_rpenable),
	.rpwrite(common_peri_group_rpwrite),
	.rpaddr(common_peri_group_rpaddr),
	.rpwdata(common_peri_group_rpwdata),
	.rpready(common_peri_group_rpready),
	.rprdata(common_peri_group_rprdata),
	.rpslverr(common_peri_group_rpslverr)
);

ERVP_TICK_GENERATOR
autoname_62
(
	.clk(autoname_62_clk),
	.rstnn(autoname_62_rstnn),
	.tick_config(autoname_62_tick_config),
	.tick_1us(autoname_62_tick_1us),
	.tick_62d5ms(autoname_62_tick_62d5ms)
);

ERVP_REAL_CLOCK
autoname_64
(
	.clk(autoname_64_clk),
	.rstnn(autoname_64_rstnn),
	.tick_1us(autoname_64_tick_1us),
	.real_clock(autoname_64_real_clock)
);

ERVP_EXTERNAL_PERI_GROUP
#(
	.BW_ADDR(32),
	.BW_DATA(32),
	.NUM_UART(2),
	.NUM_SPI(2),
	.NUM_I2C(0),
	.NUM_GPIO(1),
	.NUM_AIOIF(0)
)
external_peri_group
(
	.clk(external_peri_group_clk),
	.rstnn(external_peri_group_rstnn),
	.tick_1us(external_peri_group_tick_1us),
	.tick_gpio(external_peri_group_tick_gpio),
	.uart_interrupts(external_peri_group_uart_interrupts),
	.spi_interrupt(external_peri_group_spi_interrupt),
	.i2c_interrupts(external_peri_group_i2c_interrupts),
	.gpio_interrupts(external_peri_group_gpio_interrupts),
	.wifi_interrupt(external_peri_group_wifi_interrupt),
	.spi_common_sclk(external_peri_group_spi_common_sclk),
	.spi_common_sdq0(external_peri_group_spi_common_sdq0),
	.user_pinout_list(external_peri_group_user_pinout_list),
	.user_pinin_list(external_peri_group_user_pinin_list),
	.rpsel(external_peri_group_rpsel),
	.rpenable(external_peri_group_rpenable),
	.rpwrite(external_peri_group_rpwrite),
	.rpaddr(external_peri_group_rpaddr),
	.rpwdata(external_peri_group_rpwdata),
	.rpready(external_peri_group_rpready),
	.rprdata(external_peri_group_rprdata),
	.rpslverr(external_peri_group_rpslverr),
	.uart_stx_list(external_peri_group_uart_stx_list),
	.uart_srx_list(external_peri_group_uart_srx_list),
	.spi_sclk_list(external_peri_group_spi_sclk_list),
	.spi_scs_list(external_peri_group_spi_scs_list),
	.spi_sdq0_list(external_peri_group_spi_sdq0_list),
	.spi_sdq1_list(external_peri_group_spi_sdq1_list),
	.oled_sdcsel_oe(external_peri_group_oled_sdcsel_oe),
	.oled_sdcsel_oval(external_peri_group_oled_sdcsel_oval),
	.oled_sdcsel_ival(external_peri_group_oled_sdcsel_ival),
	.oled_srstnn_oe(external_peri_group_oled_srstnn_oe),
	.oled_srstnn_oval(external_peri_group_oled_srstnn_oval),
	.oled_srstnn_ival(external_peri_group_oled_srstnn_ival),
	.oled_svbat_oe(external_peri_group_oled_svbat_oe),
	.oled_svbat_oval(external_peri_group_oled_svbat_oval),
	.oled_svbat_ival(external_peri_group_oled_svbat_ival),
	.oled_svdd_oe(external_peri_group_oled_svdd_oe),
	.oled_svdd_oval(external_peri_group_oled_svdd_oval),
	.oled_svdd_ival(external_peri_group_oled_svdd_ival),
	.wifi_sitr(external_peri_group_wifi_sitr),
	.wifi_srstnn(external_peri_group_wifi_srstnn),
	.wifi_swp(external_peri_group_wifi_swp),
	.wifi_shibernate(external_peri_group_wifi_shibernate),
	.gpio_swenable_list(external_peri_group_gpio_swenable_list),
	.gpio_swdata_list(external_peri_group_gpio_swdata_list),
	.gpio_srenable_list(external_peri_group_gpio_srenable_list),
	.gpio_srdata_list(external_peri_group_gpio_srdata_list),
	.gpio_suser_pinout_list(external_peri_group_gpio_suser_pinout_list),
	.gpio_suser_pinin_list(external_peri_group_gpio_suser_pinin_list),
	.gpio_sinterrupt_list(external_peri_group_gpio_sinterrupt_list)
);

ERVP_CORE_PERI_GROUP
#(
	.BW_ADDR(32),
	.BW_DATA(32),
	.PROCESS_ID(0),
	.NUM_LOCK(7),
	.NUM_GLOBAL_TAG(2)
)
core_peri_group
(
	.clk(core_peri_group_clk),
	.rstnn(core_peri_group_rstnn),
	.tick_1us(core_peri_group_tick_1us),
	.delay_notice(core_peri_group_delay_notice),
	.plic_interrupt(core_peri_group_plic_interrupt),
	.lock_status_list(core_peri_group_lock_status_list),
	.global_tag_list(core_peri_group_global_tag_list),
	.core_interrupt_vector(core_peri_group_core_interrupt_vector),
	.allows_holds(core_peri_group_allows_holds),
	.rpsel(core_peri_group_rpsel),
	.rpenable(core_peri_group_rpenable),
	.rpwrite(core_peri_group_rpwrite),
	.rpaddr(core_peri_group_rpaddr),
	.rpwdata(core_peri_group_rpwdata),
	.rpready(core_peri_group_rpready),
	.rprdata(core_peri_group_rprdata),
	.rpslverr(core_peri_group_rpslverr),
	.tcu_spsel(core_peri_group_tcu_spsel),
	.tcu_spenable(core_peri_group_tcu_spenable),
	.tcu_spwrite(core_peri_group_tcu_spwrite),
	.tcu_spaddr(core_peri_group_tcu_spaddr),
	.tcu_spwdata(core_peri_group_tcu_spwdata),
	.tcu_spready(core_peri_group_tcu_spready),
	.tcu_sprdata(core_peri_group_tcu_sprdata),
	.tcu_spslverr(core_peri_group_tcu_spslverr),
	.florian_spsel(core_peri_group_florian_spsel),
	.florian_spenable(core_peri_group_florian_spenable),
	.florian_spwrite(core_peri_group_florian_spwrite),
	.florian_spaddr(core_peri_group_florian_spaddr),
	.florian_spwdata(core_peri_group_florian_spwdata),
	.florian_spready(core_peri_group_florian_spready),
	.florian_sprdata(core_peri_group_florian_sprdata),
	.florian_spslverr(core_peri_group_florian_spslverr)
);

ERVP_CORE_PERI_GROUP
#(
	.BW_ADDR(32),
	.BW_DATA(32),
	.PROCESS_ID(1),
	.NUM_LOCK(7),
	.NUM_GLOBAL_TAG(2)
)
autoname_65
(
	.clk(autoname_65_clk),
	.rstnn(autoname_65_rstnn),
	.tick_1us(autoname_65_tick_1us),
	.delay_notice(autoname_65_delay_notice),
	.plic_interrupt(autoname_65_plic_interrupt),
	.lock_status_list(autoname_65_lock_status_list),
	.global_tag_list(autoname_65_global_tag_list),
	.core_interrupt_vector(autoname_65_core_interrupt_vector),
	.allows_holds(autoname_65_allows_holds),
	.rpsel(autoname_65_rpsel),
	.rpenable(autoname_65_rpenable),
	.rpwrite(autoname_65_rpwrite),
	.rpaddr(autoname_65_rpaddr),
	.rpwdata(autoname_65_rpwdata),
	.rpready(autoname_65_rpready),
	.rprdata(autoname_65_rprdata),
	.rpslverr(autoname_65_rpslverr),
	.tcu_spsel(autoname_65_tcu_spsel),
	.tcu_spenable(autoname_65_tcu_spenable),
	.tcu_spwrite(autoname_65_tcu_spwrite),
	.tcu_spaddr(autoname_65_tcu_spaddr),
	.tcu_spwdata(autoname_65_tcu_spwdata),
	.tcu_spready(autoname_65_tcu_spready),
	.tcu_sprdata(autoname_65_tcu_sprdata),
	.tcu_spslverr(autoname_65_tcu_spslverr),
	.florian_spsel(autoname_65_florian_spsel),
	.florian_spenable(autoname_65_florian_spenable),
	.florian_spwrite(autoname_65_florian_spwrite),
	.florian_spaddr(autoname_65_florian_spaddr),
	.florian_spwdata(autoname_65_florian_spwdata),
	.florian_spready(autoname_65_florian_spready),
	.florian_sprdata(autoname_65_florian_sprdata),
	.florian_spslverr(autoname_65_florian_spslverr)
);

ERVP_PLATFORM_CONTROLLER
#(
	.BW_ADDR(32),
	.NUM_RESET(8),
	.NUM_AUTO_RESET(4),
	.NUM_CORE(2)
)
platform_controller
(
	.clk(platform_controller_clk),
	.external_rstnn(platform_controller_external_rstnn),
	.global_rstnn(platform_controller_global_rstnn),
	.global_rstpp(platform_controller_global_rstpp),
	.rstnn_seqeunce(platform_controller_rstnn_seqeunce),
	.rstpp_seqeunce(platform_controller_rstpp_seqeunce),
	.boot_mode(platform_controller_boot_mode),
	.jtag_select(platform_controller_jtag_select),
	.initialized(platform_controller_initialized),
	.app_finished(platform_controller_app_finished),
	.rstnn(platform_controller_rstnn),
	.shready(platform_controller_shready),
	.shaddr(platform_controller_shaddr),
	.shburst(platform_controller_shburst),
	.shmasterlock(platform_controller_shmasterlock),
	.shprot(platform_controller_shprot),
	.shsize(platform_controller_shsize),
	.shtrans(platform_controller_shtrans),
	.shwrite(platform_controller_shwrite),
	.shwdata(platform_controller_shwdata),
	.shrdata(platform_controller_shrdata),
	.shresp(platform_controller_shresp),
	.rpsel(platform_controller_rpsel),
	.rpenable(platform_controller_rpenable),
	.rpwrite(platform_controller_rpwrite),
	.rpaddr(platform_controller_rpaddr),
	.rpwdata(platform_controller_rpwdata),
	.rpready(platform_controller_rpready),
	.rprdata(platform_controller_rprdata),
	.rpslverr(platform_controller_rpslverr),
	.pjtag_rtck(platform_controller_pjtag_rtck),
	.pjtag_rtrstnn(platform_controller_pjtag_rtrstnn),
	.pjtag_rtms(platform_controller_pjtag_rtms),
	.pjtag_rtdi(platform_controller_pjtag_rtdi),
	.pjtag_rtdo(platform_controller_pjtag_rtdo),
	.noc_debug_spsel(platform_controller_noc_debug_spsel),
	.noc_debug_spenable(platform_controller_noc_debug_spenable),
	.noc_debug_spwrite(platform_controller_noc_debug_spwrite),
	.noc_debug_spaddr(platform_controller_noc_debug_spaddr),
	.noc_debug_spwdata(platform_controller_noc_debug_spwdata),
	.noc_debug_spready(platform_controller_noc_debug_spready),
	.noc_debug_sprdata(platform_controller_noc_debug_sprdata),
	.noc_debug_spslverr(platform_controller_noc_debug_spslverr),
	.rpc_list(platform_controller_rpc_list),
	.rinst_list(platform_controller_rinst_list)
);

MUNOC_DEFAULT_SNIM
#(
	.NODE_ID(`NODE_ID_DEFAULT_SLAVE),
	.BW_FNI_PHIT(BW_FNI_PHIT),
	.BW_BNI_PHIT(BW_BNI_PHIT),
	.BW_PLATFORM_ADDR(32),
	.USE_SW_INTERFACE(1),
	.USE_JTAG_INTERFACE(1),
	.NOC_CONTROLLER_BASEADDR(`NOC_CONTROLLER_BASEADDR)
)
default_slave
(
	.clk_network(default_slave_clk_network),
	.rstnn_network(default_slave_rstnn_network),
	.clk_debug(default_slave_clk_debug),
	.rstnn_debug(default_slave_rstnn_debug),
	.comm_disable(default_slave_comm_disable),
	.rfni_link(default_slave_rfni_link),
	.rfni_ready(default_slave_rfni_ready),
	.rbni_link(default_slave_rbni_link),
	.rbni_ready(default_slave_rbni_ready),
	.debug_rpsel(default_slave_debug_rpsel),
	.debug_rpenable(default_slave_debug_rpenable),
	.debug_rpwrite(default_slave_debug_rpwrite),
	.debug_rpaddr(default_slave_debug_rpaddr),
	.debug_rpwdata(default_slave_debug_rpwdata),
	.debug_rpready(default_slave_debug_rpready),
	.debug_rprdata(default_slave_debug_rprdata),
	.debug_rpslverr(default_slave_debug_rpslverr),
	.svri_rlink(default_slave_svri_rlink),
	.svri_rack(default_slave_svri_rack),
	.svri_slink(default_slave_svri_slink),
	.svri_sack(default_slave_svri_sack)
);

MUNOC_AXI_MASTER_NETWORK_INTERFACE_MODULE
#(
	.NODE_ID(`NODE_ID_I_MNIM_I_MAIN_CORE_NO_NAME),
	.BW_FNI_PHIT(BW_FNI_PHIT),
	.BW_BNI_PHIT(BW_BNI_PHIT),
	.BW_PLATFORM_ADDR(32),
	.BW_NODE_DATA(32),
	.LOCAL_ENABLE(1),
	.LOCAL_UPPER_ADDR(4'h F),
	.NAME("i_main_core_no_name"),
	.BW_AXI_MASTER_TID(4)
)
i_mnim_i_main_core_no_name
(
	.clk(i_mnim_i_main_core_no_name_clk),
	.rstnn(i_mnim_i_main_core_no_name_rstnn),
	.comm_disable(i_mnim_i_main_core_no_name_comm_disable),
	.local_allows_holds(i_mnim_i_main_core_no_name_local_allows_holds),
	.rxawready(i_mnim_i_main_core_no_name_rxawready),
	.rxawvalid(i_mnim_i_main_core_no_name_rxawvalid),
	.rxawaddr(i_mnim_i_main_core_no_name_rxawaddr),
	.rxawid(i_mnim_i_main_core_no_name_rxawid),
	.rxawlen(i_mnim_i_main_core_no_name_rxawlen),
	.rxawsize(i_mnim_i_main_core_no_name_rxawsize),
	.rxawburst(i_mnim_i_main_core_no_name_rxawburst),
	.rxwready(i_mnim_i_main_core_no_name_rxwready),
	.rxwvalid(i_mnim_i_main_core_no_name_rxwvalid),
	.rxwid(i_mnim_i_main_core_no_name_rxwid),
	.rxwdata(i_mnim_i_main_core_no_name_rxwdata),
	.rxwstrb(i_mnim_i_main_core_no_name_rxwstrb),
	.rxwlast(i_mnim_i_main_core_no_name_rxwlast),
	.rxbready(i_mnim_i_main_core_no_name_rxbready),
	.rxbvalid(i_mnim_i_main_core_no_name_rxbvalid),
	.rxbid(i_mnim_i_main_core_no_name_rxbid),
	.rxbresp(i_mnim_i_main_core_no_name_rxbresp),
	.rxarready(i_mnim_i_main_core_no_name_rxarready),
	.rxarvalid(i_mnim_i_main_core_no_name_rxarvalid),
	.rxaraddr(i_mnim_i_main_core_no_name_rxaraddr),
	.rxarid(i_mnim_i_main_core_no_name_rxarid),
	.rxarlen(i_mnim_i_main_core_no_name_rxarlen),
	.rxarsize(i_mnim_i_main_core_no_name_rxarsize),
	.rxarburst(i_mnim_i_main_core_no_name_rxarburst),
	.rxrready(i_mnim_i_main_core_no_name_rxrready),
	.rxrvalid(i_mnim_i_main_core_no_name_rxrvalid),
	.rxrid(i_mnim_i_main_core_no_name_rxrid),
	.rxrdata(i_mnim_i_main_core_no_name_rxrdata),
	.rxrlast(i_mnim_i_main_core_no_name_rxrlast),
	.rxrresp(i_mnim_i_main_core_no_name_rxrresp),
	.sfni_link(i_mnim_i_main_core_no_name_sfni_link),
	.sfni_ready(i_mnim_i_main_core_no_name_sfni_ready),
	.sbni_link(i_mnim_i_main_core_no_name_sbni_link),
	.sbni_ready(i_mnim_i_main_core_no_name_sbni_ready),
	.svri_rlink(i_mnim_i_main_core_no_name_svri_rlink),
	.svri_rack(i_mnim_i_main_core_no_name_svri_rack),
	.svri_slink(i_mnim_i_main_core_no_name_svri_slink),
	.svri_sack(i_mnim_i_main_core_no_name_svri_sack),
	.local_spsel(i_mnim_i_main_core_no_name_local_spsel),
	.local_spenable(i_mnim_i_main_core_no_name_local_spenable),
	.local_spwrite(i_mnim_i_main_core_no_name_local_spwrite),
	.local_spaddr(i_mnim_i_main_core_no_name_local_spaddr),
	.local_spwdata(i_mnim_i_main_core_no_name_local_spwdata),
	.local_spready(i_mnim_i_main_core_no_name_local_spready),
	.local_sprdata(i_mnim_i_main_core_no_name_local_sprdata),
	.local_spslverr(i_mnim_i_main_core_no_name_local_spslverr)
);

MUNOC_AXI_MASTER_NETWORK_INTERFACE_MODULE
#(
	.NODE_ID(`NODE_ID_I_MNIM_I_SUB_CORE_001_NO_NAME),
	.BW_FNI_PHIT(BW_FNI_PHIT),
	.BW_BNI_PHIT(BW_BNI_PHIT),
	.BW_PLATFORM_ADDR(32),
	.BW_NODE_DATA(32),
	.LOCAL_ENABLE(1),
	.LOCAL_UPPER_ADDR(4'h F),
	.NAME("i_sub_core_001_no_name"),
	.BW_AXI_MASTER_TID(4)
)
i_mnim_i_sub_core_001_no_name
(
	.clk(i_mnim_i_sub_core_001_no_name_clk),
	.rstnn(i_mnim_i_sub_core_001_no_name_rstnn),
	.comm_disable(i_mnim_i_sub_core_001_no_name_comm_disable),
	.local_allows_holds(i_mnim_i_sub_core_001_no_name_local_allows_holds),
	.rxawready(i_mnim_i_sub_core_001_no_name_rxawready),
	.rxawvalid(i_mnim_i_sub_core_001_no_name_rxawvalid),
	.rxawaddr(i_mnim_i_sub_core_001_no_name_rxawaddr),
	.rxawid(i_mnim_i_sub_core_001_no_name_rxawid),
	.rxawlen(i_mnim_i_sub_core_001_no_name_rxawlen),
	.rxawsize(i_mnim_i_sub_core_001_no_name_rxawsize),
	.rxawburst(i_mnim_i_sub_core_001_no_name_rxawburst),
	.rxwready(i_mnim_i_sub_core_001_no_name_rxwready),
	.rxwvalid(i_mnim_i_sub_core_001_no_name_rxwvalid),
	.rxwid(i_mnim_i_sub_core_001_no_name_rxwid),
	.rxwdata(i_mnim_i_sub_core_001_no_name_rxwdata),
	.rxwstrb(i_mnim_i_sub_core_001_no_name_rxwstrb),
	.rxwlast(i_mnim_i_sub_core_001_no_name_rxwlast),
	.rxbready(i_mnim_i_sub_core_001_no_name_rxbready),
	.rxbvalid(i_mnim_i_sub_core_001_no_name_rxbvalid),
	.rxbid(i_mnim_i_sub_core_001_no_name_rxbid),
	.rxbresp(i_mnim_i_sub_core_001_no_name_rxbresp),
	.rxarready(i_mnim_i_sub_core_001_no_name_rxarready),
	.rxarvalid(i_mnim_i_sub_core_001_no_name_rxarvalid),
	.rxaraddr(i_mnim_i_sub_core_001_no_name_rxaraddr),
	.rxarid(i_mnim_i_sub_core_001_no_name_rxarid),
	.rxarlen(i_mnim_i_sub_core_001_no_name_rxarlen),
	.rxarsize(i_mnim_i_sub_core_001_no_name_rxarsize),
	.rxarburst(i_mnim_i_sub_core_001_no_name_rxarburst),
	.rxrready(i_mnim_i_sub_core_001_no_name_rxrready),
	.rxrvalid(i_mnim_i_sub_core_001_no_name_rxrvalid),
	.rxrid(i_mnim_i_sub_core_001_no_name_rxrid),
	.rxrdata(i_mnim_i_sub_core_001_no_name_rxrdata),
	.rxrlast(i_mnim_i_sub_core_001_no_name_rxrlast),
	.rxrresp(i_mnim_i_sub_core_001_no_name_rxrresp),
	.sfni_link(i_mnim_i_sub_core_001_no_name_sfni_link),
	.sfni_ready(i_mnim_i_sub_core_001_no_name_sfni_ready),
	.sbni_link(i_mnim_i_sub_core_001_no_name_sbni_link),
	.sbni_ready(i_mnim_i_sub_core_001_no_name_sbni_ready),
	.svri_rlink(i_mnim_i_sub_core_001_no_name_svri_rlink),
	.svri_rack(i_mnim_i_sub_core_001_no_name_svri_rack),
	.svri_slink(i_mnim_i_sub_core_001_no_name_svri_slink),
	.svri_sack(i_mnim_i_sub_core_001_no_name_svri_sack),
	.local_spsel(i_mnim_i_sub_core_001_no_name_local_spsel),
	.local_spenable(i_mnim_i_sub_core_001_no_name_local_spenable),
	.local_spwrite(i_mnim_i_sub_core_001_no_name_local_spwrite),
	.local_spaddr(i_mnim_i_sub_core_001_no_name_local_spaddr),
	.local_spwdata(i_mnim_i_sub_core_001_no_name_local_spwdata),
	.local_spready(i_mnim_i_sub_core_001_no_name_local_spready),
	.local_sprdata(i_mnim_i_sub_core_001_no_name_local_sprdata),
	.local_spslverr(i_mnim_i_sub_core_001_no_name_local_spslverr)
);

MUNOC_AHB_MASTER_NETWORK_INTERFACE_MODULE
#(
	.NODE_ID(`NODE_ID_I_MNIM_PLATFORM_CONTROLLER_MASTER),
	.BW_FNI_PHIT(BW_FNI_PHIT),
	.BW_BNI_PHIT(BW_BNI_PHIT),
	.BW_PLATFORM_ADDR(32),
	.BW_NODE_DATA(32),
	.NAME("platform_controller_master")
)
i_mnim_platform_controller_master
(
	.clk(i_mnim_platform_controller_master_clk),
	.rstnn(i_mnim_platform_controller_master_rstnn),
	.comm_disable(i_mnim_platform_controller_master_comm_disable),
	.rhready(i_mnim_platform_controller_master_rhready),
	.rhaddr(i_mnim_platform_controller_master_rhaddr),
	.rhburst(i_mnim_platform_controller_master_rhburst),
	.rhmasterlock(i_mnim_platform_controller_master_rhmasterlock),
	.rhprot(i_mnim_platform_controller_master_rhprot),
	.rhsize(i_mnim_platform_controller_master_rhsize),
	.rhtrans(i_mnim_platform_controller_master_rhtrans),
	.rhwrite(i_mnim_platform_controller_master_rhwrite),
	.rhwdata(i_mnim_platform_controller_master_rhwdata),
	.rhrdata(i_mnim_platform_controller_master_rhrdata),
	.rhresp(i_mnim_platform_controller_master_rhresp),
	.sfni_link(i_mnim_platform_controller_master_sfni_link),
	.sfni_ready(i_mnim_platform_controller_master_sfni_ready),
	.sbni_link(i_mnim_platform_controller_master_sbni_link),
	.sbni_ready(i_mnim_platform_controller_master_sbni_ready),
	.svri_rlink(i_mnim_platform_controller_master_svri_rlink),
	.svri_rack(i_mnim_platform_controller_master_svri_rack),
	.svri_slink(i_mnim_platform_controller_master_svri_slink),
	.svri_sack(i_mnim_platform_controller_master_svri_sack)
);

MUNOC_AXI_SLAVE_NETWORK_INTERFACE_MODULE
#(
	.NODE_ID(`NODE_ID_I_SNIM_I_TEST1_SLAVE),
	.BW_FNI_PHIT(BW_FNI_PHIT),
	.BW_BNI_PHIT(BW_BNI_PHIT),
	.BW_PLATFORM_ADDR(32),
	.BW_NODE_DATA(32),
	.NAME("i_test1_slave"),
	.BW_AXI_SLAVE_TID(1)
)
i_snim_i_test1_slave
(
	.clk(i_snim_i_test1_slave_clk),
	.rstnn(i_snim_i_test1_slave_rstnn),
	.comm_disable(i_snim_i_test1_slave_comm_disable),
	.sxawready(i_snim_i_test1_slave_sxawready),
	.sxawvalid(i_snim_i_test1_slave_sxawvalid),
	.sxawaddr(i_snim_i_test1_slave_sxawaddr),
	.sxawid(i_snim_i_test1_slave_sxawid),
	.sxawlen(i_snim_i_test1_slave_sxawlen),
	.sxawsize(i_snim_i_test1_slave_sxawsize),
	.sxawburst(i_snim_i_test1_slave_sxawburst),
	.sxwready(i_snim_i_test1_slave_sxwready),
	.sxwvalid(i_snim_i_test1_slave_sxwvalid),
	.sxwid(i_snim_i_test1_slave_sxwid),
	.sxwdata(i_snim_i_test1_slave_sxwdata),
	.sxwstrb(i_snim_i_test1_slave_sxwstrb),
	.sxwlast(i_snim_i_test1_slave_sxwlast),
	.sxbready(i_snim_i_test1_slave_sxbready),
	.sxbvalid(i_snim_i_test1_slave_sxbvalid),
	.sxbid(i_snim_i_test1_slave_sxbid),
	.sxbresp(i_snim_i_test1_slave_sxbresp),
	.sxarready(i_snim_i_test1_slave_sxarready),
	.sxarvalid(i_snim_i_test1_slave_sxarvalid),
	.sxaraddr(i_snim_i_test1_slave_sxaraddr),
	.sxarid(i_snim_i_test1_slave_sxarid),
	.sxarlen(i_snim_i_test1_slave_sxarlen),
	.sxarsize(i_snim_i_test1_slave_sxarsize),
	.sxarburst(i_snim_i_test1_slave_sxarburst),
	.sxrready(i_snim_i_test1_slave_sxrready),
	.sxrvalid(i_snim_i_test1_slave_sxrvalid),
	.sxrid(i_snim_i_test1_slave_sxrid),
	.sxrdata(i_snim_i_test1_slave_sxrdata),
	.sxrlast(i_snim_i_test1_slave_sxrlast),
	.sxrresp(i_snim_i_test1_slave_sxrresp),
	.rfni_link(i_snim_i_test1_slave_rfni_link),
	.rfni_ready(i_snim_i_test1_slave_rfni_ready),
	.rbni_link(i_snim_i_test1_slave_rbni_link),
	.rbni_ready(i_snim_i_test1_slave_rbni_ready),
	.svri_rlink(i_snim_i_test1_slave_svri_rlink),
	.svri_rack(i_snim_i_test1_slave_svri_rack),
	.svri_slink(i_snim_i_test1_slave_svri_slink),
	.svri_sack(i_snim_i_test1_slave_svri_sack)
);

MUNOC_AXI_SLAVE_NETWORK_INTERFACE_MODULE
#(
	.NODE_ID(`NODE_ID_I_SNIM_I_SYSTEM_SRAM_NO_NAME),
	.BW_FNI_PHIT(BW_FNI_PHIT),
	.BW_BNI_PHIT(BW_BNI_PHIT),
	.BW_PLATFORM_ADDR(32),
	.BW_NODE_DATA(32),
	.NAME("i_system_sram_no_name"),
	.BW_AXI_SLAVE_TID(`REQUIRED_BW_OF_SLAVE_TID)
)
i_snim_i_system_sram_no_name
(
	.clk(i_snim_i_system_sram_no_name_clk),
	.rstnn(i_snim_i_system_sram_no_name_rstnn),
	.comm_disable(i_snim_i_system_sram_no_name_comm_disable),
	.sxawready(i_snim_i_system_sram_no_name_sxawready),
	.sxawvalid(i_snim_i_system_sram_no_name_sxawvalid),
	.sxawaddr(i_snim_i_system_sram_no_name_sxawaddr),
	.sxawid(i_snim_i_system_sram_no_name_sxawid),
	.sxawlen(i_snim_i_system_sram_no_name_sxawlen),
	.sxawsize(i_snim_i_system_sram_no_name_sxawsize),
	.sxawburst(i_snim_i_system_sram_no_name_sxawburst),
	.sxwready(i_snim_i_system_sram_no_name_sxwready),
	.sxwvalid(i_snim_i_system_sram_no_name_sxwvalid),
	.sxwid(i_snim_i_system_sram_no_name_sxwid),
	.sxwdata(i_snim_i_system_sram_no_name_sxwdata),
	.sxwstrb(i_snim_i_system_sram_no_name_sxwstrb),
	.sxwlast(i_snim_i_system_sram_no_name_sxwlast),
	.sxbready(i_snim_i_system_sram_no_name_sxbready),
	.sxbvalid(i_snim_i_system_sram_no_name_sxbvalid),
	.sxbid(i_snim_i_system_sram_no_name_sxbid),
	.sxbresp(i_snim_i_system_sram_no_name_sxbresp),
	.sxarready(i_snim_i_system_sram_no_name_sxarready),
	.sxarvalid(i_snim_i_system_sram_no_name_sxarvalid),
	.sxaraddr(i_snim_i_system_sram_no_name_sxaraddr),
	.sxarid(i_snim_i_system_sram_no_name_sxarid),
	.sxarlen(i_snim_i_system_sram_no_name_sxarlen),
	.sxarsize(i_snim_i_system_sram_no_name_sxarsize),
	.sxarburst(i_snim_i_system_sram_no_name_sxarburst),
	.sxrready(i_snim_i_system_sram_no_name_sxrready),
	.sxrvalid(i_snim_i_system_sram_no_name_sxrvalid),
	.sxrid(i_snim_i_system_sram_no_name_sxrid),
	.sxrdata(i_snim_i_system_sram_no_name_sxrdata),
	.sxrlast(i_snim_i_system_sram_no_name_sxrlast),
	.sxrresp(i_snim_i_system_sram_no_name_sxrresp),
	.rfni_link(i_snim_i_system_sram_no_name_rfni_link),
	.rfni_ready(i_snim_i_system_sram_no_name_rfni_ready),
	.rbni_link(i_snim_i_system_sram_no_name_rbni_link),
	.rbni_ready(i_snim_i_system_sram_no_name_rbni_ready),
	.svri_rlink(i_snim_i_system_sram_no_name_svri_rlink),
	.svri_rack(i_snim_i_system_sram_no_name_svri_rack),
	.svri_slink(i_snim_i_system_sram_no_name_svri_slink),
	.svri_sack(i_snim_i_system_sram_no_name_svri_sack)
);

MUNOC_APB_SLAVE_NETWORK_INTERFACE_MODULE
#(
	.NODE_ID(`NODE_ID_I_SNIM_COMMON_PERI_GROUP_NO_NAME),
	.BW_FNI_PHIT(BW_FNI_PHIT),
	.BW_BNI_PHIT(BW_BNI_PHIT),
	.BW_PLATFORM_ADDR(32),
	.BW_NODE_DATA(32),
	.NAME("common_peri_group_no_name")
)
i_snim_common_peri_group_no_name
(
	.clk(i_snim_common_peri_group_no_name_clk),
	.rstnn(i_snim_common_peri_group_no_name_rstnn),
	.comm_disable(i_snim_common_peri_group_no_name_comm_disable),
	.spsel(i_snim_common_peri_group_no_name_spsel),
	.spenable(i_snim_common_peri_group_no_name_spenable),
	.spwrite(i_snim_common_peri_group_no_name_spwrite),
	.spaddr(i_snim_common_peri_group_no_name_spaddr),
	.spwdata(i_snim_common_peri_group_no_name_spwdata),
	.spready(i_snim_common_peri_group_no_name_spready),
	.sprdata(i_snim_common_peri_group_no_name_sprdata),
	.spslverr(i_snim_common_peri_group_no_name_spslverr),
	.rfni_link(i_snim_common_peri_group_no_name_rfni_link),
	.rfni_ready(i_snim_common_peri_group_no_name_rfni_ready),
	.rbni_link(i_snim_common_peri_group_no_name_rbni_link),
	.rbni_ready(i_snim_common_peri_group_no_name_rbni_ready),
	.svri_rlink(i_snim_common_peri_group_no_name_svri_rlink),
	.svri_rack(i_snim_common_peri_group_no_name_svri_rack),
	.svri_slink(i_snim_common_peri_group_no_name_svri_slink),
	.svri_sack(i_snim_common_peri_group_no_name_svri_sack)
);

MUNOC_APB_SLAVE_NETWORK_INTERFACE_MODULE
#(
	.NODE_ID(`NODE_ID_I_SNIM_EXTERNAL_PERI_GROUP_NO_NAME),
	.BW_FNI_PHIT(BW_FNI_PHIT),
	.BW_BNI_PHIT(BW_BNI_PHIT),
	.BW_PLATFORM_ADDR(32),
	.BW_NODE_DATA(32),
	.NAME("external_peri_group_no_name")
)
i_snim_external_peri_group_no_name
(
	.clk(i_snim_external_peri_group_no_name_clk),
	.rstnn(i_snim_external_peri_group_no_name_rstnn),
	.comm_disable(i_snim_external_peri_group_no_name_comm_disable),
	.spsel(i_snim_external_peri_group_no_name_spsel),
	.spenable(i_snim_external_peri_group_no_name_spenable),
	.spwrite(i_snim_external_peri_group_no_name_spwrite),
	.spaddr(i_snim_external_peri_group_no_name_spaddr),
	.spwdata(i_snim_external_peri_group_no_name_spwdata),
	.spready(i_snim_external_peri_group_no_name_spready),
	.sprdata(i_snim_external_peri_group_no_name_sprdata),
	.spslverr(i_snim_external_peri_group_no_name_spslverr),
	.rfni_link(i_snim_external_peri_group_no_name_rfni_link),
	.rfni_ready(i_snim_external_peri_group_no_name_rfni_ready),
	.rbni_link(i_snim_external_peri_group_no_name_rbni_link),
	.rbni_ready(i_snim_external_peri_group_no_name_rbni_ready),
	.svri_rlink(i_snim_external_peri_group_no_name_svri_rlink),
	.svri_rack(i_snim_external_peri_group_no_name_svri_rack),
	.svri_slink(i_snim_external_peri_group_no_name_svri_slink),
	.svri_sack(i_snim_external_peri_group_no_name_svri_sack)
);

MUNOC_APB_SLAVE_NETWORK_INTERFACE_MODULE
#(
	.NODE_ID(`NODE_ID_I_SNIM_PLATFORM_CONTROLLER_NO_NAME),
	.BW_FNI_PHIT(BW_FNI_PHIT),
	.BW_BNI_PHIT(BW_BNI_PHIT),
	.BW_PLATFORM_ADDR(32),
	.BW_NODE_DATA(32),
	.NAME("platform_controller_no_name")
)
i_snim_platform_controller_no_name
(
	.clk(i_snim_platform_controller_no_name_clk),
	.rstnn(i_snim_platform_controller_no_name_rstnn),
	.comm_disable(i_snim_platform_controller_no_name_comm_disable),
	.spsel(i_snim_platform_controller_no_name_spsel),
	.spenable(i_snim_platform_controller_no_name_spenable),
	.spwrite(i_snim_platform_controller_no_name_spwrite),
	.spaddr(i_snim_platform_controller_no_name_spaddr),
	.spwdata(i_snim_platform_controller_no_name_spwdata),
	.spready(i_snim_platform_controller_no_name_spready),
	.sprdata(i_snim_platform_controller_no_name_sprdata),
	.spslverr(i_snim_platform_controller_no_name_spslverr),
	.rfni_link(i_snim_platform_controller_no_name_rfni_link),
	.rfni_ready(i_snim_platform_controller_no_name_rfni_ready),
	.rbni_link(i_snim_platform_controller_no_name_rbni_link),
	.rbni_ready(i_snim_platform_controller_no_name_rbni_ready),
	.svri_rlink(i_snim_platform_controller_no_name_svri_rlink),
	.svri_rack(i_snim_platform_controller_no_name_svri_rack),
	.svri_slink(i_snim_platform_controller_no_name_svri_slink),
	.svri_sack(i_snim_platform_controller_no_name_svri_sack)
);

MUNOC_NETWORK_DUAL_ROUTER
#(
	.BW_FNI_PHIT(BW_FNI_PHIT),
	.BW_BNI_PHIT(BW_BNI_PHIT),
	.NUM_MASTER(3),
	.NUM_SLAVE(6),
	.ROUTER_ID(`ROUTER_ID_I_SYSTEM_ROUTER)
)
i_system_router
(
	.clk(i_system_router_clk),
	.rstnn(i_system_router_rstnn),
	.rfni_link_list(i_system_router_rfni_link_list),
	.rfni_ready_list(i_system_router_rfni_ready_list),
	.rbni_link_list(i_system_router_rbni_link_list),
	.rbni_ready_list(i_system_router_rbni_ready_list),
	.sfni_link_list(i_system_router_sfni_link_list),
	.sfni_ready_list(i_system_router_sfni_ready_list),
	.sbni_link_list(i_system_router_sbni_link_list),
	.sbni_ready_list(i_system_router_sbni_ready_list)
);

assign clk_core = clk_system;
assign clk_system_external = clk_system;
assign clk_system_debug = clk_system;
assign clk_local_access = clk_core;
assign clk_process_000 = clk_core;
assign clk_process_001 = clk_core;
assign clk_noc = clk_core;
assign gclk_system = clk_system;
assign gclk_core = clk_core;
assign gclk_system_external = clk_system_external;
assign gclk_system_debug = clk_system_debug;
assign gclk_local_access = clk_local_access;
assign gclk_process_000 = clk_process_000;
assign gclk_process_001 = clk_process_001;
assign gclk_noc = clk_noc;
assign tick_1us = autoname_62_tick_1us;
assign tick_62d5ms = autoname_62_tick_62d5ms;
assign tick_gpio = external_peri_group_tick_gpio;
assign autoname_63 = tick_1us;
assign global_rstnn = platform_controller_global_rstnn;
assign global_rstpp = platform_controller_global_rstpp;
assign rstnn_seqeunce = platform_controller_rstnn_seqeunce;
assign rstpp_seqeunce = platform_controller_rstpp_seqeunce;
assign i_led_rstnn = rstnn_seqeunce[1];
assign i_system_sram_rstnn = rstnn_seqeunce[1];
assign common_peri_group_rstnn = rstnn_seqeunce[1];
assign autoname_62_rstnn = rstnn_seqeunce[1];
assign autoname_64_rstnn = rstnn_seqeunce[2];
assign external_peri_group_rstnn = rstnn_seqeunce[2];
assign core_peri_group_rstnn = rstnn_seqeunce[2];
assign autoname_65_rstnn = rstnn_seqeunce[2];
assign platform_controller_rstnn = rstnn_seqeunce[3];
assign default_slave_rstnn_network = rstnn_seqeunce[3];
assign default_slave_rstnn_debug = rstnn_seqeunce[3];
assign i_gpio_uwb_reset_rstnn = rstnn_seqeunce[4];
assign i_test1_rstnn = rstnn_seqeunce[5];
assign i_main_core_rstnn = rstnn_seqeunce[6];
assign i_sub_core_001_rstnn = rstnn_seqeunce[7];
assign rstnn_user = rstnn_seqeunce[3];
assign rstpp_user = rstpp_seqeunce[3];
assign i_led_clk = gclk_system_external;
assign external_peri_group_clk = gclk_system_external;
assign clk_system = i_pll0_clk_system;
assign i_gpio_uwb_reset_clk = clk_system;
assign common_peri_group_clk = clk_system;
assign autoname_62_clk = clk_system;
assign autoname_64_clk = clk_system;
assign platform_controller_clk = clk_system;
assign core_peri_group_clk = gclk_local_access;
assign autoname_65_clk = gclk_local_access;
assign default_slave_clk_debug = gclk_system_debug;
assign i_main_core_clk = gclk_process_000;
assign i_sub_core_001_clk = gclk_process_001;
assign rstnn_noc = rstnn_seqeunce[1];
assign i_system_router_rstnn = rstnn_noc;
assign i_system_router_clk = gclk_noc;
assign i_test1_clk = gclk_noc;
assign i_system_sram_clk = gclk_noc;
assign default_slave_clk_network = gclk_noc;
assign i_mnim_i_main_core_no_name_clk = gclk_noc;
assign i_mnim_i_main_core_no_name_rstnn = rstnn_noc;
assign i_mnim_i_sub_core_001_no_name_clk = gclk_noc;
assign i_mnim_i_sub_core_001_no_name_rstnn = rstnn_noc;
assign i_mnim_platform_controller_master_clk = gclk_noc;
assign i_mnim_platform_controller_master_rstnn = rstnn_noc;
assign i_snim_i_test1_slave_clk = gclk_noc;
assign i_snim_i_test1_slave_rstnn = rstnn_noc;
assign i_snim_i_system_sram_no_name_clk = gclk_noc;
assign i_snim_i_system_sram_no_name_rstnn = rstnn_noc;
assign i_snim_common_peri_group_no_name_clk = gclk_noc;
assign i_snim_common_peri_group_no_name_rstnn = rstnn_noc;
assign i_snim_external_peri_group_no_name_clk = gclk_noc;
assign i_snim_external_peri_group_no_name_rstnn = rstnn_noc;
assign i_snim_platform_controller_no_name_clk = gclk_noc;
assign i_snim_platform_controller_no_name_rstnn = rstnn_noc;
assign i_led_tick_62d5ms = autoname_62_tick_62d5ms;
assign i_led_app_finished = platform_controller_app_finished;
assign i_gpio_uwb_reset_tick_gpio = external_peri_group_tick_gpio;
assign i_pll0_external_rstnn = platform_controller_global_rstnn;
assign core_peri_group_lock_status_list = common_peri_group_lock_status_list;
assign autoname_65_lock_status_list = common_peri_group_lock_status_list;
assign common_peri_group_real_clock = autoname_64_real_clock;
assign core_peri_group_global_tag_list = common_peri_group_global_tag_list;
assign autoname_65_global_tag_list = common_peri_group_global_tag_list;
assign autoname_62_tick_config = common_peri_group_system_tick_config;
assign autoname_64_tick_1us = autoname_62_tick_1us;
assign external_peri_group_tick_1us = autoname_62_tick_1us;
assign core_peri_group_tick_1us = autoname_63;
assign autoname_65_tick_1us = autoname_63;
assign platform_controller_external_rstnn = external_rstnn;
assign platform_controller_boot_mode = boot_mode;
assign platform_controller_jtag_select = `JTAG_SELECT_NOC;
assign platform_controller_initialized = 1'b 1;
assign i_main_core_interrupt_vector = core_peri_group_core_interrupt_vector;
assign i_sub_core_001_interrupt_vector = autoname_65_core_interrupt_vector;
assign core_peri_group_allows_holds = i_mnim_i_main_core_no_name_local_allows_holds;
assign autoname_65_allows_holds = i_mnim_i_sub_core_001_no_name_local_allows_holds;
assign external_peri_group_user_pinout_list = 0;
assign default_slave_comm_disable = 0;
assign core_peri_group_plic_interrupt = 0;
assign autoname_65_plic_interrupt = 0;
assign i_mnim_i_main_core_no_name_comm_disable = 0;
assign i_mnim_i_sub_core_001_no_name_comm_disable = 0;
assign i_mnim_platform_controller_master_comm_disable = 0;
assign i_snim_common_peri_group_no_name_comm_disable = 0;
assign i_snim_platform_controller_no_name_comm_disable = 0;
assign i_snim_i_test1_slave_comm_disable = 0;
assign i_snim_i_system_sram_no_name_comm_disable = 0;
assign i_snim_external_peri_group_no_name_comm_disable = 0;
assign spi_common_sclk = external_peri_group_spi_common_sclk;
assign spi_common_sdq0 = external_peri_group_spi_common_sdq0;
assign led_list[1*(0+1)-1 -:1] = i_led_led_list[1*(0+1)-1 -:1];
assign uwb_reset_soe = i_gpio_uwb_reset_gpio_soe;
assign uwb_reset_soval = i_gpio_uwb_reset_gpio_soval;
assign i_gpio_uwb_reset_gpio_sival = uwb_reset_sival;
assign i_main_core_sxawready = i_mnim_i_main_core_no_name_rxawready;
assign i_mnim_i_main_core_no_name_rxawvalid = i_main_core_sxawvalid;
assign i_mnim_i_main_core_no_name_rxawaddr = i_main_core_sxawaddr;
assign i_mnim_i_main_core_no_name_rxawid = i_main_core_sxawid;
assign i_mnim_i_main_core_no_name_rxawlen = i_main_core_sxawlen;
assign i_mnim_i_main_core_no_name_rxawsize = i_main_core_sxawsize;
assign i_mnim_i_main_core_no_name_rxawburst = i_main_core_sxawburst;
assign i_main_core_sxwready = i_mnim_i_main_core_no_name_rxwready;
assign i_mnim_i_main_core_no_name_rxwvalid = i_main_core_sxwvalid;
assign i_mnim_i_main_core_no_name_rxwid = i_main_core_sxwid;
assign i_mnim_i_main_core_no_name_rxwdata = i_main_core_sxwdata;
assign i_mnim_i_main_core_no_name_rxwstrb = i_main_core_sxwstrb;
assign i_mnim_i_main_core_no_name_rxwlast = i_main_core_sxwlast;
assign i_mnim_i_main_core_no_name_rxbready = i_main_core_sxbready;
assign i_main_core_sxbvalid = i_mnim_i_main_core_no_name_rxbvalid;
assign i_main_core_sxbid = i_mnim_i_main_core_no_name_rxbid;
assign i_main_core_sxbresp = i_mnim_i_main_core_no_name_rxbresp;
assign i_main_core_sxarready = i_mnim_i_main_core_no_name_rxarready;
assign i_mnim_i_main_core_no_name_rxarvalid = i_main_core_sxarvalid;
assign i_mnim_i_main_core_no_name_rxaraddr = i_main_core_sxaraddr;
assign i_mnim_i_main_core_no_name_rxarid = i_main_core_sxarid;
assign i_mnim_i_main_core_no_name_rxarlen = i_main_core_sxarlen;
assign i_mnim_i_main_core_no_name_rxarsize = i_main_core_sxarsize;
assign i_mnim_i_main_core_no_name_rxarburst = i_main_core_sxarburst;
assign i_mnim_i_main_core_no_name_rxrready = i_main_core_sxrready;
assign i_main_core_sxrvalid = i_mnim_i_main_core_no_name_rxrvalid;
assign i_main_core_sxrid = i_mnim_i_main_core_no_name_rxrid;
assign i_main_core_sxrdata = i_mnim_i_main_core_no_name_rxrdata;
assign i_main_core_sxrlast = i_mnim_i_main_core_no_name_rxrlast;
assign i_main_core_sxrresp = i_mnim_i_main_core_no_name_rxrresp;
assign i_sub_core_001_sxawready = i_mnim_i_sub_core_001_no_name_rxawready;
assign i_mnim_i_sub_core_001_no_name_rxawvalid = i_sub_core_001_sxawvalid;
assign i_mnim_i_sub_core_001_no_name_rxawaddr = i_sub_core_001_sxawaddr;
assign i_mnim_i_sub_core_001_no_name_rxawid = i_sub_core_001_sxawid;
assign i_mnim_i_sub_core_001_no_name_rxawlen = i_sub_core_001_sxawlen;
assign i_mnim_i_sub_core_001_no_name_rxawsize = i_sub_core_001_sxawsize;
assign i_mnim_i_sub_core_001_no_name_rxawburst = i_sub_core_001_sxawburst;
assign i_sub_core_001_sxwready = i_mnim_i_sub_core_001_no_name_rxwready;
assign i_mnim_i_sub_core_001_no_name_rxwvalid = i_sub_core_001_sxwvalid;
assign i_mnim_i_sub_core_001_no_name_rxwid = i_sub_core_001_sxwid;
assign i_mnim_i_sub_core_001_no_name_rxwdata = i_sub_core_001_sxwdata;
assign i_mnim_i_sub_core_001_no_name_rxwstrb = i_sub_core_001_sxwstrb;
assign i_mnim_i_sub_core_001_no_name_rxwlast = i_sub_core_001_sxwlast;
assign i_mnim_i_sub_core_001_no_name_rxbready = i_sub_core_001_sxbready;
assign i_sub_core_001_sxbvalid = i_mnim_i_sub_core_001_no_name_rxbvalid;
assign i_sub_core_001_sxbid = i_mnim_i_sub_core_001_no_name_rxbid;
assign i_sub_core_001_sxbresp = i_mnim_i_sub_core_001_no_name_rxbresp;
assign i_sub_core_001_sxarready = i_mnim_i_sub_core_001_no_name_rxarready;
assign i_mnim_i_sub_core_001_no_name_rxarvalid = i_sub_core_001_sxarvalid;
assign i_mnim_i_sub_core_001_no_name_rxaraddr = i_sub_core_001_sxaraddr;
assign i_mnim_i_sub_core_001_no_name_rxarid = i_sub_core_001_sxarid;
assign i_mnim_i_sub_core_001_no_name_rxarlen = i_sub_core_001_sxarlen;
assign i_mnim_i_sub_core_001_no_name_rxarsize = i_sub_core_001_sxarsize;
assign i_mnim_i_sub_core_001_no_name_rxarburst = i_sub_core_001_sxarburst;
assign i_mnim_i_sub_core_001_no_name_rxrready = i_sub_core_001_sxrready;
assign i_sub_core_001_sxrvalid = i_mnim_i_sub_core_001_no_name_rxrvalid;
assign i_sub_core_001_sxrid = i_mnim_i_sub_core_001_no_name_rxrid;
assign i_sub_core_001_sxrdata = i_mnim_i_sub_core_001_no_name_rxrdata;
assign i_sub_core_001_sxrlast = i_mnim_i_sub_core_001_no_name_rxrlast;
assign i_sub_core_001_sxrresp = i_mnim_i_sub_core_001_no_name_rxrresp;
assign platform_controller_shready = i_mnim_platform_controller_master_rhready;
assign i_mnim_platform_controller_master_rhaddr = platform_controller_shaddr;
assign i_mnim_platform_controller_master_rhburst = platform_controller_shburst;
assign i_mnim_platform_controller_master_rhmasterlock = platform_controller_shmasterlock;
assign i_mnim_platform_controller_master_rhprot = platform_controller_shprot;
assign i_mnim_platform_controller_master_rhsize = platform_controller_shsize;
assign i_mnim_platform_controller_master_rhtrans = platform_controller_shtrans;
assign i_mnim_platform_controller_master_rhwrite = platform_controller_shwrite;
assign i_mnim_platform_controller_master_rhwdata = platform_controller_shwdata;
assign platform_controller_shrdata = i_mnim_platform_controller_master_rhrdata;
assign platform_controller_shresp = i_mnim_platform_controller_master_rhresp;
assign i_snim_i_test1_slave_sxawready = i_test1_sxawready;
assign i_test1_sxawvalid = i_snim_i_test1_slave_sxawvalid;
assign i_test1_sxawaddr = i_snim_i_test1_slave_sxawaddr;
assign i_test1_sxawid = i_snim_i_test1_slave_sxawid;
assign i_test1_sxawlen = i_snim_i_test1_slave_sxawlen;
assign i_test1_sxawsize = i_snim_i_test1_slave_sxawsize;
assign i_test1_sxawburst = i_snim_i_test1_slave_sxawburst;
assign i_snim_i_test1_slave_sxwready = i_test1_sxwready;
assign i_test1_sxwvalid = i_snim_i_test1_slave_sxwvalid;
assign i_test1_sxwid = i_snim_i_test1_slave_sxwid;
assign i_test1_sxwdata = i_snim_i_test1_slave_sxwdata;
assign i_test1_sxwstrb = i_snim_i_test1_slave_sxwstrb;
assign i_test1_sxwlast = i_snim_i_test1_slave_sxwlast;
assign i_test1_sxbready = i_snim_i_test1_slave_sxbready;
assign i_snim_i_test1_slave_sxbvalid = i_test1_sxbvalid;
assign i_snim_i_test1_slave_sxbid = i_test1_sxbid;
assign i_snim_i_test1_slave_sxbresp = i_test1_sxbresp;
assign i_snim_i_test1_slave_sxarready = i_test1_sxarready;
assign i_test1_sxarvalid = i_snim_i_test1_slave_sxarvalid;
assign i_test1_sxaraddr = i_snim_i_test1_slave_sxaraddr;
assign i_test1_sxarid = i_snim_i_test1_slave_sxarid;
assign i_test1_sxarlen = i_snim_i_test1_slave_sxarlen;
assign i_test1_sxarsize = i_snim_i_test1_slave_sxarsize;
assign i_test1_sxarburst = i_snim_i_test1_slave_sxarburst;
assign i_test1_sxrready = i_snim_i_test1_slave_sxrready;
assign i_snim_i_test1_slave_sxrvalid = i_test1_sxrvalid;
assign i_snim_i_test1_slave_sxrid = i_test1_sxrid;
assign i_snim_i_test1_slave_sxrdata = i_test1_sxrdata;
assign i_snim_i_test1_slave_sxrlast = i_test1_sxrlast;
assign i_snim_i_test1_slave_sxrresp = i_test1_sxrresp;
assign i_snim_i_system_sram_no_name_sxawready = i_system_sram_sxawready;
assign i_system_sram_sxawvalid = i_snim_i_system_sram_no_name_sxawvalid;
assign i_system_sram_sxawaddr = i_snim_i_system_sram_no_name_sxawaddr;
assign i_system_sram_sxawid = i_snim_i_system_sram_no_name_sxawid;
assign i_system_sram_sxawlen = i_snim_i_system_sram_no_name_sxawlen;
assign i_system_sram_sxawsize = i_snim_i_system_sram_no_name_sxawsize;
assign i_system_sram_sxawburst = i_snim_i_system_sram_no_name_sxawburst;
assign i_snim_i_system_sram_no_name_sxwready = i_system_sram_sxwready;
assign i_system_sram_sxwvalid = i_snim_i_system_sram_no_name_sxwvalid;
assign i_system_sram_sxwid = i_snim_i_system_sram_no_name_sxwid;
assign i_system_sram_sxwdata = i_snim_i_system_sram_no_name_sxwdata;
assign i_system_sram_sxwstrb = i_snim_i_system_sram_no_name_sxwstrb;
assign i_system_sram_sxwlast = i_snim_i_system_sram_no_name_sxwlast;
assign i_system_sram_sxbready = i_snim_i_system_sram_no_name_sxbready;
assign i_snim_i_system_sram_no_name_sxbvalid = i_system_sram_sxbvalid;
assign i_snim_i_system_sram_no_name_sxbid = i_system_sram_sxbid;
assign i_snim_i_system_sram_no_name_sxbresp = i_system_sram_sxbresp;
assign i_snim_i_system_sram_no_name_sxarready = i_system_sram_sxarready;
assign i_system_sram_sxarvalid = i_snim_i_system_sram_no_name_sxarvalid;
assign i_system_sram_sxaraddr = i_snim_i_system_sram_no_name_sxaraddr;
assign i_system_sram_sxarid = i_snim_i_system_sram_no_name_sxarid;
assign i_system_sram_sxarlen = i_snim_i_system_sram_no_name_sxarlen;
assign i_system_sram_sxarsize = i_snim_i_system_sram_no_name_sxarsize;
assign i_system_sram_sxarburst = i_snim_i_system_sram_no_name_sxarburst;
assign i_system_sram_sxrready = i_snim_i_system_sram_no_name_sxrready;
assign i_snim_i_system_sram_no_name_sxrvalid = i_system_sram_sxrvalid;
assign i_snim_i_system_sram_no_name_sxrid = i_system_sram_sxrid;
assign i_snim_i_system_sram_no_name_sxrdata = i_system_sram_sxrdata;
assign i_snim_i_system_sram_no_name_sxrlast = i_system_sram_sxrlast;
assign i_snim_i_system_sram_no_name_sxrresp = i_system_sram_sxrresp;
assign common_peri_group_rpsel = i_snim_common_peri_group_no_name_spsel;
assign common_peri_group_rpenable = i_snim_common_peri_group_no_name_spenable;
assign common_peri_group_rpwrite = i_snim_common_peri_group_no_name_spwrite;
assign common_peri_group_rpaddr = i_snim_common_peri_group_no_name_spaddr;
assign common_peri_group_rpwdata = i_snim_common_peri_group_no_name_spwdata;
assign i_snim_common_peri_group_no_name_spready = common_peri_group_rpready;
assign i_snim_common_peri_group_no_name_sprdata = common_peri_group_rprdata;
assign i_snim_common_peri_group_no_name_spslverr = common_peri_group_rpslverr;
assign external_peri_group_rpsel = i_snim_external_peri_group_no_name_spsel;
assign external_peri_group_rpenable = i_snim_external_peri_group_no_name_spenable;
assign external_peri_group_rpwrite = i_snim_external_peri_group_no_name_spwrite;
assign external_peri_group_rpaddr = i_snim_external_peri_group_no_name_spaddr;
assign external_peri_group_rpwdata = i_snim_external_peri_group_no_name_spwdata;
assign i_snim_external_peri_group_no_name_spready = external_peri_group_rpready;
assign i_snim_external_peri_group_no_name_sprdata = external_peri_group_rprdata;
assign i_snim_external_peri_group_no_name_spslverr = external_peri_group_rpslverr;
assign platform_controller_rpsel = i_snim_platform_controller_no_name_spsel;
assign platform_controller_rpenable = i_snim_platform_controller_no_name_spenable;
assign platform_controller_rpwrite = i_snim_platform_controller_no_name_spwrite;
assign platform_controller_rpaddr = i_snim_platform_controller_no_name_spaddr;
assign platform_controller_rpwdata = i_snim_platform_controller_no_name_spwdata;
assign i_snim_platform_controller_no_name_spready = platform_controller_rpready;
assign i_snim_platform_controller_no_name_sprdata = platform_controller_rprdata;
assign i_snim_platform_controller_no_name_spslverr = platform_controller_rpslverr;
assign i_system_router_rfni_link_list[`BW_FNI_LINK(BW_FNI_PHIT)*(0+1)-1 -:`BW_FNI_LINK(BW_FNI_PHIT)] = i_mnim_i_main_core_no_name_sfni_link;
assign i_mnim_i_main_core_no_name_sfni_ready = i_system_router_rfni_ready_list[1*(0+1)-1 -:1];
assign i_mnim_i_main_core_no_name_sbni_link = i_system_router_rbni_link_list[`BW_BNI_LINK(BW_BNI_PHIT)*(0+1)-1 -:`BW_BNI_LINK(BW_BNI_PHIT)];
assign i_system_router_rbni_ready_list[1*(0+1)-1 -:1] = i_mnim_i_main_core_no_name_sbni_ready;
assign i_system_router_rfni_link_list[`BW_FNI_LINK(BW_FNI_PHIT)*(1+1)-1 -:`BW_FNI_LINK(BW_FNI_PHIT)] = i_mnim_i_sub_core_001_no_name_sfni_link;
assign i_mnim_i_sub_core_001_no_name_sfni_ready = i_system_router_rfni_ready_list[1*(1+1)-1 -:1];
assign i_mnim_i_sub_core_001_no_name_sbni_link = i_system_router_rbni_link_list[`BW_BNI_LINK(BW_BNI_PHIT)*(1+1)-1 -:`BW_BNI_LINK(BW_BNI_PHIT)];
assign i_system_router_rbni_ready_list[1*(1+1)-1 -:1] = i_mnim_i_sub_core_001_no_name_sbni_ready;
assign i_system_router_rfni_link_list[`BW_FNI_LINK(BW_FNI_PHIT)*(2+1)-1 -:`BW_FNI_LINK(BW_FNI_PHIT)] = i_mnim_platform_controller_master_sfni_link;
assign i_mnim_platform_controller_master_sfni_ready = i_system_router_rfni_ready_list[1*(2+1)-1 -:1];
assign i_mnim_platform_controller_master_sbni_link = i_system_router_rbni_link_list[`BW_BNI_LINK(BW_BNI_PHIT)*(2+1)-1 -:`BW_BNI_LINK(BW_BNI_PHIT)];
assign i_system_router_rbni_ready_list[1*(2+1)-1 -:1] = i_mnim_platform_controller_master_sbni_ready;
assign i_snim_i_test1_slave_rfni_link = i_system_router_sfni_link_list[`BW_FNI_LINK(BW_FNI_PHIT)*(0+1)-1 -:`BW_FNI_LINK(BW_FNI_PHIT)];
assign i_system_router_sfni_ready_list[1*(0+1)-1 -:1] = i_snim_i_test1_slave_rfni_ready;
assign i_system_router_sbni_link_list[`BW_BNI_LINK(BW_BNI_PHIT)*(0+1)-1 -:`BW_BNI_LINK(BW_BNI_PHIT)] = i_snim_i_test1_slave_rbni_link;
assign i_snim_i_test1_slave_rbni_ready = i_system_router_sbni_ready_list[1*(0+1)-1 -:1];
assign i_snim_i_system_sram_no_name_rfni_link = i_system_router_sfni_link_list[`BW_FNI_LINK(BW_FNI_PHIT)*(1+1)-1 -:`BW_FNI_LINK(BW_FNI_PHIT)];
assign i_system_router_sfni_ready_list[1*(1+1)-1 -:1] = i_snim_i_system_sram_no_name_rfni_ready;
assign i_system_router_sbni_link_list[`BW_BNI_LINK(BW_BNI_PHIT)*(1+1)-1 -:`BW_BNI_LINK(BW_BNI_PHIT)] = i_snim_i_system_sram_no_name_rbni_link;
assign i_snim_i_system_sram_no_name_rbni_ready = i_system_router_sbni_ready_list[1*(1+1)-1 -:1];
assign i_snim_common_peri_group_no_name_rfni_link = i_system_router_sfni_link_list[`BW_FNI_LINK(BW_FNI_PHIT)*(2+1)-1 -:`BW_FNI_LINK(BW_FNI_PHIT)];
assign i_system_router_sfni_ready_list[1*(2+1)-1 -:1] = i_snim_common_peri_group_no_name_rfni_ready;
assign i_system_router_sbni_link_list[`BW_BNI_LINK(BW_BNI_PHIT)*(2+1)-1 -:`BW_BNI_LINK(BW_BNI_PHIT)] = i_snim_common_peri_group_no_name_rbni_link;
assign i_snim_common_peri_group_no_name_rbni_ready = i_system_router_sbni_ready_list[1*(2+1)-1 -:1];
assign i_snim_external_peri_group_no_name_rfni_link = i_system_router_sfni_link_list[`BW_FNI_LINK(BW_FNI_PHIT)*(3+1)-1 -:`BW_FNI_LINK(BW_FNI_PHIT)];
assign i_system_router_sfni_ready_list[1*(3+1)-1 -:1] = i_snim_external_peri_group_no_name_rfni_ready;
assign i_system_router_sbni_link_list[`BW_BNI_LINK(BW_BNI_PHIT)*(3+1)-1 -:`BW_BNI_LINK(BW_BNI_PHIT)] = i_snim_external_peri_group_no_name_rbni_link;
assign i_snim_external_peri_group_no_name_rbni_ready = i_system_router_sbni_ready_list[1*(3+1)-1 -:1];
assign i_snim_platform_controller_no_name_rfni_link = i_system_router_sfni_link_list[`BW_FNI_LINK(BW_FNI_PHIT)*(4+1)-1 -:`BW_FNI_LINK(BW_FNI_PHIT)];
assign i_system_router_sfni_ready_list[1*(4+1)-1 -:1] = i_snim_platform_controller_no_name_rfni_ready;
assign i_system_router_sbni_link_list[`BW_BNI_LINK(BW_BNI_PHIT)*(4+1)-1 -:`BW_BNI_LINK(BW_BNI_PHIT)] = i_snim_platform_controller_no_name_rbni_link;
assign i_snim_platform_controller_no_name_rbni_ready = i_system_router_sbni_ready_list[1*(4+1)-1 -:1];
assign default_slave_rfni_link = i_system_router_sfni_link_list[`BW_FNI_LINK(BW_FNI_PHIT)*(5+1)-1 -:`BW_FNI_LINK(BW_FNI_PHIT)];
assign i_system_router_sfni_ready_list[1*(5+1)-1 -:1] = default_slave_rfni_ready;
assign i_system_router_sbni_link_list[`BW_BNI_LINK(BW_BNI_PHIT)*(5+1)-1 -:`BW_BNI_LINK(BW_BNI_PHIT)] = default_slave_rbni_link;
assign default_slave_rbni_ready = i_system_router_sbni_ready_list[1*(5+1)-1 -:1];
assign platform_controller_rpc_list[32*(0+1)-1 -:32] = i_main_core_spc;
assign platform_controller_rinst_list[32*(0+1)-1 -:32] = i_main_core_sinst;
assign platform_controller_rpc_list[32*(1+1)-1 -:32] = i_sub_core_001_spc;
assign platform_controller_rinst_list[32*(1+1)-1 -:32] = i_sub_core_001_sinst;
assign i_gpio_uwb_reset_rwenable = external_peri_group_gpio_swenable_list[1*(`GPIO_INDEX_FOR_UWB_RESET+1)-1 -:1];
assign i_gpio_uwb_reset_rwdata = external_peri_group_gpio_swdata_list[32*(`GPIO_INDEX_FOR_UWB_RESET+1)-1 -:32];
assign i_gpio_uwb_reset_rrenable = external_peri_group_gpio_srenable_list[1*(`GPIO_INDEX_FOR_UWB_RESET+1)-1 -:1];
assign external_peri_group_gpio_srdata_list[32*(`GPIO_INDEX_FOR_UWB_RESET+1)-1 -:32] = i_gpio_uwb_reset_rrdata;
assign i_gpio_uwb_reset_ruser_pinout = external_peri_group_gpio_suser_pinout_list[`BW_GPIO_VALUE*(`GPIO_INDEX_FOR_UWB_RESET+1)-1 -:`BW_GPIO_VALUE];
assign external_peri_group_gpio_suser_pinin_list[`BW_GPIO_VALUE*(`GPIO_INDEX_FOR_UWB_RESET+1)-1 -:`BW_GPIO_VALUE] = i_gpio_uwb_reset_ruser_pinin;
assign external_peri_group_gpio_sinterrupt_list[1*(`GPIO_INDEX_FOR_UWB_RESET+1)-1 -:1] = i_gpio_uwb_reset_rinterrupt;
assign default_slave_debug_rpsel = platform_controller_noc_debug_spsel;
assign default_slave_debug_rpenable = platform_controller_noc_debug_spenable;
assign default_slave_debug_rpwrite = platform_controller_noc_debug_spwrite;
assign default_slave_debug_rpaddr = platform_controller_noc_debug_spaddr;
assign default_slave_debug_rpwdata = platform_controller_noc_debug_spwdata;
assign platform_controller_noc_debug_spready = default_slave_debug_rpready;
assign platform_controller_noc_debug_sprdata = default_slave_debug_rprdata;
assign platform_controller_noc_debug_spslverr = default_slave_debug_rpslverr;
assign core_peri_group_rpsel = i_mnim_i_main_core_no_name_local_spsel;
assign core_peri_group_rpenable = i_mnim_i_main_core_no_name_local_spenable;
assign core_peri_group_rpwrite = i_mnim_i_main_core_no_name_local_spwrite;
assign core_peri_group_rpaddr = i_mnim_i_main_core_no_name_local_spaddr;
assign core_peri_group_rpwdata = i_mnim_i_main_core_no_name_local_spwdata;
assign i_mnim_i_main_core_no_name_local_spready = core_peri_group_rpready;
assign i_mnim_i_main_core_no_name_local_sprdata = core_peri_group_rprdata;
assign i_mnim_i_main_core_no_name_local_spslverr = core_peri_group_rpslverr;
assign autoname_65_rpsel = i_mnim_i_sub_core_001_no_name_local_spsel;
assign autoname_65_rpenable = i_mnim_i_sub_core_001_no_name_local_spenable;
assign autoname_65_rpwrite = i_mnim_i_sub_core_001_no_name_local_spwrite;
assign autoname_65_rpaddr = i_mnim_i_sub_core_001_no_name_local_spaddr;
assign autoname_65_rpwdata = i_mnim_i_sub_core_001_no_name_local_spwdata;
assign i_mnim_i_sub_core_001_no_name_local_spready = autoname_65_rpready;
assign i_mnim_i_sub_core_001_no_name_local_sprdata = autoname_65_rprdata;
assign i_mnim_i_sub_core_001_no_name_local_spslverr = autoname_65_rpslverr;
assign oled_sdcsel_oe = external_peri_group_oled_sdcsel_oe;
assign oled_sdcsel_oval = external_peri_group_oled_sdcsel_oval;
assign external_peri_group_oled_sdcsel_ival = oled_sdcsel_ival;
assign oled_srstnn_oe = external_peri_group_oled_srstnn_oe;
assign oled_srstnn_oval = external_peri_group_oled_srstnn_oval;
assign external_peri_group_oled_srstnn_ival = oled_srstnn_ival;
assign oled_svbat_oe = external_peri_group_oled_svbat_oe;
assign oled_svbat_oval = external_peri_group_oled_svbat_oval;
assign external_peri_group_oled_svbat_ival = oled_svbat_ival;
assign oled_svdd_oe = external_peri_group_oled_svdd_oe;
assign oled_svdd_oval = external_peri_group_oled_svdd_oval;
assign external_peri_group_oled_svdd_ival = oled_svdd_ival;
assign platform_controller_pjtag_rtck = pjtag_rtck;
assign platform_controller_pjtag_rtrstnn = pjtag_rtrstnn;
assign platform_controller_pjtag_rtms = pjtag_rtms;
assign platform_controller_pjtag_rtdi = pjtag_rtdi;
assign pjtag_rtdo = platform_controller_pjtag_rtdo;
assign external_peri_group_wifi_sitr = 0;
assign default_slave_svri_rlink = 0;
assign default_slave_svri_sack = 0;
assign i_mnim_i_main_core_no_name_svri_rlink = 0;
assign i_mnim_i_main_core_no_name_svri_sack = 0;
assign i_mnim_i_sub_core_001_no_name_svri_rlink = 0;
assign i_mnim_i_sub_core_001_no_name_svri_sack = 0;
assign i_mnim_platform_controller_master_svri_rlink = 0;
assign i_mnim_platform_controller_master_svri_sack = 0;
assign i_snim_i_test1_slave_svri_rlink = 0;
assign i_snim_i_test1_slave_svri_sack = 0;
assign i_snim_i_system_sram_no_name_svri_rlink = 0;
assign i_snim_i_system_sram_no_name_svri_sack = 0;
assign i_snim_common_peri_group_no_name_svri_rlink = 0;
assign i_snim_common_peri_group_no_name_svri_sack = 0;
assign i_snim_external_peri_group_no_name_svri_rlink = 0;
assign i_snim_external_peri_group_no_name_svri_sack = 0;
assign i_snim_platform_controller_no_name_svri_rlink = 0;
assign i_snim_platform_controller_no_name_svri_sack = 0;
assign core_peri_group_tcu_spready = 0;
assign core_peri_group_tcu_sprdata = 0;
assign core_peri_group_tcu_spslverr = 0;
assign autoname_65_tcu_spready = 0;
assign autoname_65_tcu_sprdata = 0;
assign autoname_65_tcu_spslverr = 0;
assign core_peri_group_florian_spready = 0;
assign core_peri_group_florian_sprdata = 0;
assign core_peri_group_florian_spslverr = 0;
assign autoname_65_florian_spready = 0;
assign autoname_65_florian_sprdata = 0;
assign autoname_65_florian_spslverr = 0;
assign uart_readymade_tx_list[1*(0+1)-1 -:1] = external_peri_group_uart_stx_list[1*(0+1)-1 -:1];
assign external_peri_group_uart_srx_list[1*(0+1)-1 -:1] = uart_readymade_rx_list[1*(0+1)-1 -:1];
assign printf_tx = external_peri_group_uart_stx_list[1*(`UART_INDEX_FOR_UART_PRINTF+1)-1 -:1];
assign external_peri_group_uart_srx_list[1*(`UART_INDEX_FOR_UART_PRINTF+1)-1 -:1] = printf_rx;
assign oled_sclk = external_peri_group_spi_sclk_list[1*(`SPI_INDEX_FOR_OLED+1)-1 -:1];
assign oled_scs = external_peri_group_spi_scs_list[1*(`SPI_INDEX_FOR_OLED+1)-1 -:1];
assign oled_sdq0 = external_peri_group_spi_sdq0_list[1*(`SPI_INDEX_FOR_OLED+1)-1 -:1];
assign external_peri_group_spi_sdq1_list[1*(`SPI_INDEX_FOR_OLED+1)-1 -:1] = oled_sdq1;
assign spi_flash_sclk = external_peri_group_spi_sclk_list[1*(`SPI_INDEX_FOR_SPI_FLASH+1)-1 -:1];
assign spi_flash_scs = external_peri_group_spi_scs_list[1*(`SPI_INDEX_FOR_SPI_FLASH+1)-1 -:1];
assign spi_flash_sdq0 = external_peri_group_spi_sdq0_list[1*(`SPI_INDEX_FOR_SPI_FLASH+1)-1 -:1];
assign external_peri_group_spi_sdq1_list[1*(`SPI_INDEX_FOR_SPI_FLASH+1)-1 -:1] = spi_flash_sdq1;


endmodule