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
// 2023-11-23
// Kyuseung Han (han@etri.re.kr)
// ****************************************************************************
// ****************************************************************************

`include "ervp_global.vh"
`include "ervp_axi_define.vh"
`include "munoc_network_include.vh"

module RADARPIM_SRAM_01
(
	clk,
	rstnn,

	rxawid,
	rxawaddr,
	rxawlen,
	rxawsize,
	rxawburst,
	rxawvalid,
	rxawready,

	rxwid,
	rxwdata,
	rxwstrb,
	rxwlast,
	rxwvalid,
	rxwready,

	rxbid,
	rxbresp,
	rxbvalid,
	rxbready,

	rxarid,
	rxaraddr,
	rxarlen,
	rxarsize,
	rxarburst,
	rxarvalid,
	rxarready,

	rxrid,
	rxrdata,
	rxrresp,
	rxrlast,
	rxrvalid,
	rxrready
);

////////////////////////////
/* parameter input output */
////////////////////////////

localparam CAPACITY = 262144;  // in bytes
localparam BW_ADDR = 32;
localparam BW_DATA = 32;
localparam BW_AXI_TID = `REQUIRED_BW_OF_SLAVE_TID;
localparam CELL_SIZE = 262144;  // in bytes
localparam CELL_WIDTH = 32;

`include "ervp_log_util.vf"
`include "ervp_bitwidth_util.vf"

localparam BW_BYTE_WEN = `NUM_BYTE(CELL_WIDTH);
localparam CELL_DEPTH = `DIVIDERU(CELL_SIZE,BW_BYTE_WEN);
localparam BW_CELL_INDEX = REQUIRED_BITWIDTH_INDEX(CELL_DEPTH);

localparam NUM_CELL = `DIVIDERU(CAPACITY,CELL_SIZE);

input wire clk, rstnn;

//AW Channel
input wire [BW_AXI_TID-1:0] rxawid;
input wire [BW_ADDR-1:0] rxawaddr;
input wire [`BW_AXI_ALEN-1:0] rxawlen;
input wire [`BW_AXI_ASIZE-1:0] rxawsize;
input wire [`BW_AXI_ABURST-1:0] rxawburst;
input wire rxawvalid;
output wire rxawready;

//W Channel
input wire [BW_AXI_TID-1:0] rxwid;
input wire [BW_DATA-1:0] rxwdata;
input wire [`BW_AXI_WSTRB(BW_DATA)-1:0] rxwstrb;
input wire rxwlast;
input wire rxwvalid;
output wire rxwready;

//B Channel
output wire [BW_AXI_TID-1:0] rxbid;
output wire [`BW_AXI_BRESP-1:0] rxbresp;
output wire rxbvalid;
input wire rxbready;

//AR Channel
input wire [BW_AXI_TID-1:0] rxarid;
input wire [BW_ADDR-1:0] rxaraddr;
input wire [`BW_AXI_ALEN-1:0] rxarlen;
input wire [`BW_AXI_ASIZE-1:0] rxarsize;
input wire [`BW_AXI_ABURST-1:0] rxarburst;
input wire rxarvalid;
output wire rxarready;

//R Channel
output wire [BW_AXI_TID-1:0] rxrid;
output wire [BW_DATA-1:0] rxrdata;
output wire [`BW_AXI_RRESP-1:0] rxrresp;
output wire rxrlast;
output wire rxrvalid;
input wire rxrready;

/////////////
/* signals */
/////////////

genvar i;

wire [NUM_CELL-1:0] cell_select_list;
wire [BW_CELL_INDEX*NUM_CELL-1:0] cell_index_list;
wire [NUM_CELL-1:0] cell_enable_list;
wire [NUM_CELL-1:0] cell_wenable_list;
wire [BW_BYTE_WEN*NUM_CELL-1:0] cell_wenable_byte_list;
wire [BW_DATA*NUM_CELL-1:0] cell_wenable_bit_list;
wire [BW_DATA*NUM_CELL-1:0] cell_wdata_list;
wire [NUM_CELL-1:0] cell_renable_list;
wire [BW_DATA*NUM_CELL-1:0] cell_rdata_list;

wire [BW_CELL_INDEX-1:0] cell_index [NUM_CELL-1:0];
wire cell_enable [NUM_CELL-1:0];
wire cell_wenable [NUM_CELL-1:0];
wire [BW_BYTE_WEN-1:0] cell_wenable_byte [NUM_CELL-1:0];
wire [BW_DATA-1:0] cell_wenable_bit [NUM_CELL-1:0];
wire [BW_DATA-1:0] cell_wdata [NUM_CELL-1:0];
wire cell_renable [NUM_CELL-1:0];
wire [BW_DATA-1:0] cell_rdata [NUM_CELL-1:0];

////////////
/* logics */
////////////

ERVP_SPSRAM_CONTROLLER_AXI
#(
	.BW_ADDR(BW_ADDR),
	.BW_DATA(BW_DATA),
	.BW_AXI_TID(BW_AXI_TID),
	.BASEADDR(0),
	.CELL_SIZE(CELL_SIZE),
  .CELL_WIDTH(CELL_WIDTH),
	.NUM_CELL(NUM_CELL)
)
i_controller
(
	.clk(clk),
	.rstnn(rstnn),
  .enable(1'b 1),

	.rxawid(rxawid),
	.rxawaddr(rxawaddr),
	.rxawlen(rxawlen),
	.rxawsize(rxawsize),
	.rxawburst(rxawburst),
	.rxawvalid(rxawvalid),
	.rxawready(rxawready),

	.rxwid(rxwid),
	.rxwdata(rxwdata),
	.rxwstrb(rxwstrb),
	.rxwlast(rxwlast),
	.rxwvalid(rxwvalid),
	.rxwready(rxwready),

	.rxbid(rxbid),
	.rxbresp(rxbresp),
	.rxbvalid(rxbvalid),
	.rxbready(rxbready),

	.rxarid(rxarid),
	.rxaraddr(rxaraddr),
	.rxarlen(rxarlen),
	.rxarsize(rxarsize),
	.rxarburst(rxarburst),
	.rxarvalid(rxarvalid),
	.rxarready(rxarready),

	.rxrid(rxrid),
	.rxrdata(rxrdata),
	.rxrresp(rxrresp),
	.rxrlast(rxrlast),
	.rxrvalid(rxrvalid),
	.rxrready(rxrready),

	.sscell_select_list(cell_select_list),
	.sscell_index_list(cell_index_list),
	.sscell_enable_list(cell_enable_list),
	.sscell_wenable_list(cell_wenable_list),
	.sscell_wenable_byte_list(cell_wenable_byte_list),
	.sscell_wenable_bit_list(cell_wenable_bit_list),
	.sscell_wdata_list(cell_wdata_list),
	.sscell_renable_list(cell_renable_list),
	.sscell_rdata_list(cell_rdata_list)
);

generate
for(i=0; i<NUM_CELL; i=i+1)
begin : generate_cell_signals
  assign cell_index[i] = cell_index_list[BW_CELL_INDEX*(i+1)-1 -:BW_CELL_INDEX];
  assign cell_enable[i] = cell_enable_list[i];
  assign cell_wenable[i] = cell_wenable_list[i];
  assign cell_wenable_byte[i] = cell_wenable_byte_list[BW_BYTE_WEN*(i+1)-1 -:BW_BYTE_WEN];
  assign cell_wenable_bit[i] = cell_wenable_bit_list[BW_DATA*(i+1)-1 -:BW_DATA];
  assign cell_wdata[i] = cell_wdata_list[BW_DATA*(i+1)-1 -:BW_DATA];
  assign cell_renable[i] = cell_renable_list[i];
  assign cell_rdata_list[BW_DATA*(i+1)-1 -:BW_DATA] = cell_rdata[i];
end
endgenerate

generate
for(i=0; i<NUM_CELL; i=i+1)
begin : generate_cell
  ERVP_MEMORY_CELL_1R1W
  #(
    .DEPTH(CELL_DEPTH),
    .WIDTH(CELL_WIDTH),
    .BW_INDEX(BW_CELL_INDEX),
    .USE_SINGLE_INDEX(1),
    .USE_SUBWORD_ENABLE(1),
    .BW_SUBWORD(8)
  )
  i_cell
  (
    .clk(clk),
    .rstnn(rstnn),
    .index(cell_index[i]),
    .windex(cell_index[i]),
    .wenable(cell_wenable[i]),
    .wpermit(cell_wenable_byte[i]),
    .wdata(cell_wdata[i]),
    .rindex(cell_index[i]),
    .rdata_asynch(),
    .renable(cell_renable[i]),
    .rdata_synch(cell_rdata[i])
  );
end
endgenerate


endmodule
