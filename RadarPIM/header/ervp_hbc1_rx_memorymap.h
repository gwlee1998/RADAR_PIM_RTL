#ifndef __ERVP_HBC1_RX_MEMORYMAP_H__
#define __ERVP_HBC1_RX_MEMORYMAP_H__

#include "platform_info.h"
#include "ervp_hbc1_rx_memorymap_offset.h"

#define MMAP_SUBMODULE_HRX_DEMODULATOR (HBC1_RX_BASEADDR+SUBMODULE_ADDR_ERVP_HBC1_RX_HRX_DEMODULATOR)
#define MMAP_SUBMODULE_HRX_FRAME (HBC1_RX_BASEADDR+SUBMODULE_ADDR_ERVP_HBC1_RX_HRX_FRAME)
#define MMAP_SUBMODULE_HRX_AFE (HBC1_RX_BASEADDR+SUBMODULE_ADDR_ERVP_HBC1_RX_HRX_AFE)

// submodule hrx_demodulator
#define MMAP_HRX_DEMODULATOR_SW_RESET (HBC1_RX_BASEADDR+MMAP_OFFSET_HRX_DEMODULATOR_SW_RESET)
#define MMAP_HRX_DEMODULATOR_VERSION (HBC1_RX_BASEADDR+MMAP_OFFSET_HRX_DEMODULATOR_VERSION)
#define MMAP_HRX_DEMODULATOR_ENABLE (HBC1_RX_BASEADDR+MMAP_OFFSET_HRX_DEMODULATOR_ENABLE)
#define MMAP_HRX_DEMODULATOR_CONFIG (HBC1_RX_BASEADDR+MMAP_OFFSET_HRX_DEMODULATOR_CONFIG)

// submodule hrx_frame
#define MMAP_HRX_FRAME_STATUS (HBC1_RX_BASEADDR+MMAP_OFFSET_HRX_FRAME_STATUS)
#define MMAP_HRX_FRAME_CLEAR (HBC1_RX_BASEADDR+MMAP_OFFSET_HRX_FRAME_CLEAR)
#define MMAP_HRX_FRAME_CORR (HBC1_RX_BASEADDR+MMAP_OFFSET_HRX_FRAME_CORR)
#define MMAP_HRX_FRAME_HEADER (HBC1_RX_BASEADDR+MMAP_OFFSET_HRX_FRAME_HEADER)
#define MMAP_HRX_FRAME_DATA_OUTPUT (HBC1_RX_BASEADDR+MMAP_OFFSET_HRX_FRAME_DATA_OUTPUT)

// submodule hrx_afe
#define MMAP_HRX_AFE_CONFIG (HBC1_RX_BASEADDR+MMAP_OFFSET_HRX_AFE_CONFIG)

// reg hrx_frame.status
// BW_HRX_FRAME_STATUS 3
// HRX_FRAME_STATUS_BIT_VALID 1
// HRX_FRAME_STATUS_BIT_HEAD_CRC 2
// HRX_FRAME_STATUS_BIT_DATA_CRC 4
// HRX_FRAME_STATUS_INVALID 0
// HRX_FRAME_STATUS_VALID_NO_CRC 1
// HRX_FRAME_STATUS_VALID_HEAD_CRC 3
// HRX_FRAME_STATUS_VALID_DATA_CRC 5

// reg hrx_demodulator.sw_reset
// BW_HRX_DEMODULATOR_SW_RESET 1

// reg hrx_demodulator.version
// BW_HRX_DEMODULATOR_VERSION 32

// reg hrx_demodulator.enable
// BW_HRX_DEMODULATOR_ENABLE 1

// reg hrx_demodulator.config
// BW_HRX_DEMODULATOR_CONFIG 32

// reg hrx_frame.clear
// BW_HRX_FRAME_CLEAR 1

// reg hrx_frame.corr
// BW_HRX_FRAME_CORR 16

// reg hrx_frame.header
// BW_HRX_FRAME_HEADER 32

// reg hrx_frame.data_output
// BW_HRX_FRAME_DATA_OUTPUT 32

// reg hrx_afe.config
// BW_HRX_AFE_CONFIG 32

// reg power_mode
// BW_POWER_MODE 1
// POWER_MODE_NORMAL 0
// POWER_MODE_POWER_DOWN 1

#endif