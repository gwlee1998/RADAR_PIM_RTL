// ****************************************************************************
// ****************************************************************************
// Copyright SoC Design Research Group, All rights reservxd.
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
// 2023-11-23
// Kyuseung Han (han@etri.re.kr)
// ****************************************************************************
// ****************************************************************************

`include "ervp_platform_controller_memorymap_offset.vh"
`include "ervp_external_peri_group_memorymap_offset.vh"
`include "memorymap_info.vh"
`include "ervp_global.vh"
`include "platform_info.vh"
`include "munoc_network_include.vh"

module RADARPIM_FPGA
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

input wire [`BW_BOOT_MODE-1:0] boot_mode;
input wire external_clk_0;
input wire external_rstnn;
output wire [(1)*(1)-1:0] led_list;
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
output wire [(1)*(1)-1:0] uart_readymade_tx_list;
input wire [(1)*(1)-1:0] uart_readymade_rx_list;
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



RADARPIM
i_platform
(
	.boot_mode(boot_mode),
	.external_clk_0(external_clk_0),
	.external_rstnn(external_rstnn),
	.led_list(led_list),
	.uwb_reset(uwb_reset),
	.oled_sdcsel(oled_sdcsel),
	.oled_srstnn(oled_srstnn),
	.oled_svbat(oled_svbat),
	.oled_svdd(oled_svdd),
	.pjtag_rtck(pjtag_rtck),
	.pjtag_rtrstnn(pjtag_rtrstnn),
	.pjtag_rtms(pjtag_rtms),
	.pjtag_rtdi(pjtag_rtdi),
	.pjtag_rtdo(pjtag_rtdo),
	.uart_readymade_tx_list(uart_readymade_tx_list),
	.uart_readymade_rx_list(uart_readymade_rx_list),
	.printf_tx(printf_tx),
	.printf_rx(printf_rx),
	.oled_sclk(oled_sclk),
	.oled_scs(oled_scs),
	.oled_sdq0(oled_sdq0),
	.oled_sdq1(oled_sdq1),
	.spi_flash_sclk(spi_flash_sclk),
	.spi_flash_scs(spi_flash_scs),
	.spi_flash_sdq0(spi_flash_sdq0),
	.spi_flash_sdq1(spi_flash_sdq1)
);

endmodule