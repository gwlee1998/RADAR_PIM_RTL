#ifndef __HW_INFO_H__
#define __HW_INFO_H__


#define PLATFORM_ADDR 32
#define NUM_CORE_USER 2
#define NUM_CORE_TEAM 2
#define NUM_LOCK_USER 2
#define NUM_LOCK_SYSTEM 5
#define NUM_BARRIER_USER 2
#define NUM_BARRIER_SYSTEM 0
#define NUM_AUTO_ID 2
#define NUM_GLOBAL_TAG 2
#define SRAM_SIZE 0x40000
#define SRAM_CELL_SIZE 0x40000
#define SRAM_CELL_WIDTH 32
#define SRAM_PORT_WIDTH 32
#define DRAM_SIZE 0
#define INCLUDE_IROM
#define TICK_HZ 1000000
#define SYSTEM_CLK_HZ 50000000
#define CORE_CLK_HZ 50000000
#define UART_CLK_HZ 50000000
#define SPI_CLK_HZ 50000000
#define I2C_CLK_HZ 50000000
#define OLED_CLK_HZ 50000000
#define PACT_CLK_HZ 0
#define NUM_UART_READYMADE 1
#define NUM_SPI_READYMADE 0
#define NUM_I2C_READYMADE 0
#define NUM_UART_USER 0
#define NUM_SPI_USER 0
#define NUM_I2C_USER 0
#define NUM_LED_CHECKER 1
#define NUM_AIOIF 0
#define NUM_SWITCH_SLIDE_READYMADE 0
#define INCLUDE_SRAM
//#define INCLUDE_SLOW_DRAM
//#define INCLUDE_FAST_DRAM
//#define INCLUDE_SDRAM
//#define INCLUDE_DDR
//#define INCLUDE_DRAM
#define INCLUDE_BOOT_MODE
#define INCLUDE_CACHE
#define INCLUDE_TIMER
//#define INCLUDE_PLIC
//#define INCLUDE_CORE_JTAG
#define INCLUDE_OLED
//#define INCLUDE_OLED_BW
#define INCLUDE_OLED_RGB
#define INCLUDE_SPI_FLASH
#define INCLUDE_UART_PRINTF
//#define INCLUDE_OLEDBW_PRINTF
//#define INCLUDE_FUSE_BOX
//#define INCLUDE_ADC
//#define INCLUDE_USER_INTERRUPTS
//#define INCLUDE_ARDUCAM
//#define INCLUDE_BLUETOOTH
//#define INCLUDE_WIFI
//#define INCLUDE_JPEG_ENCODER
//#define INCLUDE_JPEGLS_ENCODER
//#define INCLUDE_HBC1_TX
//#define INCLUDE_HBC1_RX
#define INCLUDE_CORE_PERI_GROUP
//#define INCLUDE_NOC_DEBUG
//#define INCLUDE_PACT
//#define INCLUDE_I2S
//#define INCLUDE_DMA
//#define INCLUDE_FLORIAN
//#define INCLUDE_FLORIAN_SP
//#define INCLUDE_FLORIAN_DP
//#define INCLUDE_TRAFFIC_GENERATOR
//#define INCLUDE_LCD_SHIELD
//#define INCLUDE_GPIO_PINMUX
//#define INCLUDE_EDGE_VIDEO_SYSTEM
//#define INCLUDE_VDMA
//#define INCLUDE_VIM
//#define INCLUDE_VOM
//#define INCLUDE_HDMI
//#define INCLUDE_CIS
//#define INCLUDE_SPI_LCD
//#define INCLUDE_TCACHING
#define INCLUDE_HW_BARRIER
//#define I2S_SAMPLING_RATE
//#define I2S_IP_CLK_HZ
//#define I2S_MCLK_HZ
#define NOC_FLIT_DIVISOR 1
#define NUM_TRAFFIC_GENERATOR 0
#define PLATFORM_NAME "RadarPIM"
#define INCLUDE_RVC_ROCKET_MEDIUM
#define NUM_CORE 2
#define NUM_REAL_CORE 2
#define CACHE_LINE_SIZE 64
#define IS_CACHEABLE_REGION_FIXED
#define FIXED_CACHEABLE_REGION_SIZE 131072
#define INCLUDE_MULTICORE
#define BARRIER_INDEX_FOR_USER 0
#define NUM_BARRIER 2
#define LOCK_INDEX_FOR_USER 0
#define LOCK_INDEX_FOR_SYSTEM_VARIABLE 2
#define LOCK_INDEX_FOR_SYSTEM_HW 3
#define LOCK_INDEX_FOR_PRINTF 4
#define LOCK_INDEX_FOR_SW_BARRIER 5
#define NUM_LOCK 7
#define AUTO_ID_INDEX_FOR_HW_BARRIER 0
#define SPI_INDEX_FOR_READYMADE 0
#define SPI_INDEX_FOR_USER 0
#define SPI_INDEX_FOR_SYSTEM 0
#define SPI_INDEX_FOR_OLED 0
#define SPI_INDEX_FOR_SPI_FLASH 1
#define NUM_SPI_SYSTEM 2
#define UART_INDEX_FOR_READYMADE 0
#define UART_INDEX_FOR_USER 1
#define UART_INDEX_FOR_SYSTEM 1
#define UART_INDEX_FOR_UART_PRINTF 1
#define NUM_UART_SYSTEM 1
#define I2C_INDEX_FOR_READYMADE 0
#define I2C_INDEX_FOR_USER 0
#define I2C_INDEX_FOR_SYSTEM 0
#define NUM_I2C_SYSTEM 0
#define GPIO_INDEX_FOR_UWB_RESET 0
#define NUM_GPIO 1
#define SRAM_ADDR 0x40080000
#define NUM_UART 2
#define NUM_SPI 2
#define NUM_I2C 0
#define INCLUDE_CORE_USER
#define INCLUDE_CORE_TEAM
#define INCLUDE_LOCK_USER
#define INCLUDE_LOCK_SYSTEM
#define INCLUDE_BARRIER_USER
//#define INCLUDE_BARRIER_SYSTEM
#define INCLUDE_AUTO_ID
#define INCLUDE_GLOBAL_TAG
#define INCLUDE_UART_READYMADE
//#define INCLUDE_SPI_READYMADE
//#define INCLUDE_I2C_READYMADE
//#define INCLUDE_UART_USER
//#define INCLUDE_SPI_USER
//#define INCLUDE_I2C_USER
#define INCLUDE_LED_CHECKER
//#define INCLUDE_AIOIF
//#define INCLUDE_SWITCH_SLIDE_READYMADE
#define INCLUDE_CORE
#define INCLUDE_REAL_CORE
#define INCLUDE_BARRIER
#define INCLUDE_LOCK
#define INCLUDE_SPI_SYSTEM
#define INCLUDE_UART_SYSTEM
//#define INCLUDE_I2C_SYSTEM
#define INCLUDE_GPIO
#define INCLUDE_UART
#define INCLUDE_SPI
//#define INCLUDE_I2C
#define NUM_PREDEFINED_CLOCK 0

#endif