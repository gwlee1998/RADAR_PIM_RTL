/*****************/
/* Custom Region */
/*****************/

// wire spi_common_sclk;
// wire spi_common_sdq0;
// wire clk_system;
// wire clk_core;
// wire clk_system_external;
// wire clk_system_debug;
// wire clk_local_access;
// wire clk_process_000;
// wire clk_process_001;
// wire clk_noc;
// wire gclk_system;
// wire gclk_core;
// wire gclk_system_external;
// wire gclk_system_debug;
// wire gclk_local_access;
// wire gclk_process_000;
// wire gclk_process_001;
// wire gclk_noc;
// wire tick_1us;
// wire tick_62d5ms;
// wire tick_gpio;
// wire global_rstnn;
// wire global_rstpp;
// wire [(8)-1:0] rstnn_seqeunce;
// wire [(8)-1:0] rstpp_seqeunce;
// wire rstnn_user;
// wire rstpp_user;
// wire i_test1_clk;
// wire i_test1_rstnn;
// wire i_test1_rxawready;
// wire i_test1_rxawvalid;
// wire [(32)-1:0] i_test1_rxawaddr;
// wire [(1)-1:0] i_test1_rxawid;
// wire [(8)-1:0] i_test1_rxawlen;
// wire [(3)-1:0] i_test1_rxawsize;
// wire [(2)-1:0] i_test1_rxawburst;
// wire i_test1_rxwready;
// wire i_test1_rxwvalid;
// wire [(1)-1:0] i_test1_rxwid;
// wire [(32)-1:0] i_test1_rxwdata;
// wire [(32/8)-1:0] i_test1_rxwstrb;
// wire i_test1_rxwlast;
// wire i_test1_rxbready;
// wire i_test1_rxbvalid;
// wire [(1)-1:0] i_test1_rxbid;
// wire [(2)-1:0] i_test1_rxbresp;
// wire i_test1_rxarready;
// wire i_test1_rxarvalid;
// wire [(32)-1:0] i_test1_rxaraddr;
// wire [(1)-1:0] i_test1_rxarid;
// wire [(8)-1:0] i_test1_rxarlen;
// wire [(3)-1:0] i_test1_rxarsize;
// wire [(2)-1:0] i_test1_rxarburst;
// wire i_test1_rxrready;
// wire i_test1_rxrvalid;
// wire [(1)-1:0] i_test1_rxrid;
// wire [(32)-1:0] i_test1_rxrdata;
// wire i_test1_rxrlast;
// wire [(2)-1:0] i_test1_rxrresp;

/* DO NOT MODIFY THE ABOVE */
/* MUST MODIFY THE BELOW   */



TEST1_AXI
#(
	.SIZE_OF_MEMORYMAP((32'h 80000)),
	.BW_ADDR(32),
	.BW_DATA(32)
)
i_test1
(
	.clk(i_test1_clk),
	.rstnn(i_test1_rstnn),
	.rxawready(i_test1_rxawready),
	.rxawvalid(i_test1_rxawvalid),
	.rxawaddr(i_test1_rxawaddr),
	.rxawid(i_test1_rxawid),
	.rxawlen(i_test1_rxawlen),
	.rxawsize(i_test1_rxawsize),
	.rxawburst(i_test1_rxawburst),
	.rxwready(i_test1_rxwready),
	.rxwvalid(i_test1_rxwvalid),
	.rxwid(i_test1_rxwid),
	.rxwdata(i_test1_rxwdata),
	.rxwstrb(i_test1_rxwstrb),
	.rxwlast(i_test1_rxwlast),
	.rxbready(i_test1_rxbready),
	.rxbvalid(i_test1_rxbvalid),
	.rxbid(i_test1_rxbid),
	.rxbresp(i_test1_rxbresp),
	.rxarready(i_test1_rxarready),
	.rxarvalid(i_test1_rxarvalid),
	.rxaraddr(i_test1_rxaraddr),
	.rxarid(i_test1_rxarid),
	.rxarlen(i_test1_rxarlen),
	.rxarsize(i_test1_rxarsize),
	.rxarburst(i_test1_rxarburst),
	.rxrready(i_test1_rxrready),
	.rxrvalid(i_test1_rxrvalid),
	.rxrid(i_test1_rxrid),
	.rxrdata(i_test1_rxrdata),
	.rxrlast(i_test1_rxrlast),
	.rxrresp(i_test1_rxrresp)
);

// //assign `NOT_CONNECT = i_test1_clk;
// //assign `NOT_CONNECT = i_test1_rstnn;
// assign i_test1_rxawready = 0;
// //assign `NOT_CONNECT = i_test1_rxawvalid;
// //assign `NOT_CONNECT = i_test1_rxawaddr;
// //assign `NOT_CONNECT = i_test1_rxawid;
// //assign `NOT_CONNECT = i_test1_rxawlen;
// //assign `NOT_CONNECT = i_test1_rxawsize;
// //assign `NOT_CONNECT = i_test1_rxawburst;
// assign i_test1_rxwready = 0;
// //assign `NOT_CONNECT = i_test1_rxwvalid;
// //assign `NOT_CONNECT = i_test1_rxwid;
// //assign `NOT_CONNECT = i_test1_rxwdata;
// //assign `NOT_CONNECT = i_test1_rxwstrb;
// //assign `NOT_CONNECT = i_test1_rxwlast;
// //assign `NOT_CONNECT = i_test1_rxbready;
// assign i_test1_rxbvalid = 0;
// assign i_test1_rxbid = 0;
// assign i_test1_rxbresp = 0;
// assign i_test1_rxarready = 0;
// //assign `NOT_CONNECT = i_test1_rxarvalid;
// //assign `NOT_CONNECT = i_test1_rxaraddr;
// //assign `NOT_CONNECT = i_test1_rxarid;
// //assign `NOT_CONNECT = i_test1_rxarlen;
// //assign `NOT_CONNECT = i_test1_rxarsize;
// //assign `NOT_CONNECT = i_test1_rxarburst;
// //assign `NOT_CONNECT = i_test1_rxrready;
// assign i_test1_rxrvalid = 0;
// assign i_test1_rxrid = 0;
// assign i_test1_rxrdata = 0;
// assign i_test1_rxrlast = 0;
// assign i_test1_rxrresp = 0;

