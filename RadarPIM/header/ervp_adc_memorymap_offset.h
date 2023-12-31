#ifndef __ERVP_ADC_MEMORYMAP_OFFSET_H__
#define __ERVP_ADC_MEMORYMAP_OFFSET_H__



// total
#define BW_MMAP_OFFSET_ERVP_ADC 6
#define ERVP_ADC_ADDR_INTERVAL 8
#define BW_UNUSED_ERVP_ADC 3
#define NUM_ERVP_ADC_SUBMODULE 1

// submodule adc
#define MMAP_SUBOFFSET_ADC_ANALOG_CONFIG 0x0
#define MMAP_SUBOFFSET_ADC_INTERFACE_CONFIG 0x8
#define MMAP_SUBOFFSET_ADC_FIFO_PERIOD 0x10
#define MMAP_SUBOFFSET_ADC_VALUE 0x18
#define MMAP_SUBOFFSET_ADC_FIFO 0x20

#define MMAP_OFFSET_ADC_ANALOG_CONFIG (MMAP_SUBOFFSET_ADC_ANALOG_CONFIG)
#define MMAP_OFFSET_ADC_INTERFACE_CONFIG (MMAP_SUBOFFSET_ADC_INTERFACE_CONFIG)
#define MMAP_OFFSET_ADC_FIFO_PERIOD (MMAP_SUBOFFSET_ADC_FIFO_PERIOD)
#define MMAP_OFFSET_ADC_VALUE (MMAP_SUBOFFSET_ADC_VALUE)
#define MMAP_OFFSET_ADC_FIFO (MMAP_SUBOFFSET_ADC_FIFO)

// reg ervp_adc.interface_config
#define BW_ERVP_ADC_INTERFACE_CONFIG 1
#define ERVP_ADC_INTERFACE_CONFIG_FIFO_ENABLE 1
#define ERVP_ADC_INTERFACE_CONFIG_INDEX_FIFO_ENABLE 0
#define ERVP_ADC_INTERFACE_CONFIG_NONE 0

// reg adc.analog_config
#define BW_ADC_ANALOG_CONFIG 32

// reg adc.interface_config
#define BW_ADC_INTERFACE_CONFIG 32

// reg adc.fifo_period
#define BW_ADC_FIFO_PERIOD 32

// reg adc.value
#define BW_ADC_VALUE 32

// reg adc.fifo
#define BW_ADC_FIFO 32

#endif