// See LICENSE for license details.

#ifndef __FRVP_SPI_H__
#define __FRVP_SPI_H__

/* Fields */

#define SPI_SCK_POL             0x1
#define SPI_SCK_PHA             0x2

#define SPI_FMT_PROTO(x)        ((x) & 0x3)
#define SPI_FMT_ENDIAN(x)       (((x) & 0x1) << 2)
#define SPI_FMT_DIR(x)          (((x) & 0x1) << 3)
#define SPI_FMT_LEN(x)          (((x) & 0xf) << 16)
#define SPI_FMT_DIR_BIT			(0x1 << 3)

/* TXCTRL register */
#define SPI_TXWM(x)             ((x) & 0xffff)
/* RXCTRL register */
#define SPI_RXWM(x)             ((x) & 0xffff)

#define SPI_IP_TXWM             0x1
#define SPI_IP_RXWM             0x2

#define SPI_FCTRL_EN            0x1

#define SPI_INSN_CMD_EN         0x1
#define SPI_INSN_ADDR_LEN(x)    (((x) & 0x7) << 1)
#define SPI_INSN_PAD_CNT(x)     (((x) & 0xf) << 4)
#define SPI_INSN_CMD_PROTO(x)   (((x) & 0x3) << 8)
#define SPI_INSN_ADDR_PROTO(x)  (((x) & 0x3) << 10)
#define SPI_INSN_DATA_PROTO(x)  (((x) & 0x3) << 12)
#define SPI_INSN_CMD_CODE(x)    (((x) & 0xff) << 16)
#define SPI_INSN_PAD_CODE(x)    (((x) & 0xff) << 24)

#define SPI_TXFIFO_FULL  (1 << 31)   
#define SPI_RXFIFO_EMPTY (1 << 31)   

/* Values */

#define SPI_CSMODE_AUTO         0
#define SPI_CSMODE_HOLD         2
#define SPI_CSMODE_OFF          3

#define SPI_DIR_RX              0
#define SPI_DIR_TX              1

#define SPI_PROTO_S             0
#define SPI_PROTO_D             1
#define SPI_PROTO_Q             2

#define SPI_ENDIAN_MSB          0
#define SPI_ENDIAN_LSB          1

#define SPI_SCKMODE_0			0	/* Start: Low, Data placing: Falling edge, Data sampling: Rising edge */
#define SPI_SCKMODE_1			1	/* Start: Low, Data placing: Rising edge, Data sampling: Falling edge */
#define SPI_SCKMODE_2			2	/* Start: High, Data placing: Rising edge, Data sampling: Falling edge */
#define SPI_SCKMODE_3			3	/* Start: High, Data placing: Falling edge, Data sampling: Rising edge */

#define SPI_DIVSOR(freq)		(SPI_CLK_HZ/(2*freq)-1)

typedef struct
{
	unsigned int divisor;
	int sck_mode;
	int select; // onehot
	int cs_mode;
	int frame_format;
	int cs_active_low;
} SpiConfig;

void print_spi_config(const SpiConfig *config);
void spi_configure(const SpiConfig *config);
void spi_store_config(SpiConfig *config);
void spi_restore_config(const SpiConfig *config);
void spi_start();
void spi_end();
void spi_set_direction(int direction);
void spi_read(int num_bytes, unsigned char* data);
void spi_write(int num_bytes, const unsigned char* data);
void spi_read_and_write(int num_bytes, const unsigned char* tx_data, unsigned char* rx_data);

#endif
