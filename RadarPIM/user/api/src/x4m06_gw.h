#ifndef __X4M06_H__
#define __X4M06_H__

#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "ervp_core_id.h"

// Written by: Øyvind Nydal Dahl
// Company: Novelda (XeThru)
// August 2018


// SERIAL PORTS:
// These definitions work for Arduino Mega, but must be changed for other Arduinos.
//
//#define SerialRadar Serial1    // Used for communication with the radar
//#define SerialDebug Serial    // Used for printing debug information

// Pin definitions
//#define RESET_PIN 2
//#define RADAR_RX_PIN 18


//
// The following values can be found in XeThru Module Communication Protocol:
//  https://www.xethru.com/community/resources/xethru-module-communication-protocol.130/
//
#define XT_START 0x7d
#define XT_STOP 0x7e
#define XT_ESCAPE 0x7f

#define XTS_FLAGSEQUENCE_START_NOESCAPE (uint32_t)7C7C7C7C

#define XTS_SPC_X4DRIVER  0x50
#define XTS_SPCX_SET      0x10
#define XTS_SPCX_GET      0x11

#define XTS_SPCXI_FPS             (uint32_t)0x00000010
#define XTS_SPCXI_PULSESPERSTEP   (uint32_t)0x00000011
#define XTS_SPCXI_ITERATIONS      (uint32_t)0x00000012
#define XTS_SPCXI_DOWNCONVERSION  (uint32_t)0x00000013
#define XTS_SPCXI_FRAMEAREA       (uint32_t)0x00000014
#define XTS_SPCXI_DACSTEP         (uint32_t)0x00000015
#define XTS_SPCXI_DACMIN          (uint32_t)0x00000016
#define XTS_SPCXI_DACMAX          (uint32_t)0x00000017
#define XTS_SPCXI_FRAMEAREAOFFSET (uint32_t)0x00000018
#define XTS_SPCXI_PRFDIV          (uint32_t)0x00000025


#define XTS_SPR_APPDATA 0x50
#define XTS_SPR_SYSTEM 0x30

#define XTS_SPR_ACK 0x10
#define XTS_SPR_ERROR 0x20

#define XTS_SPRS_BOOTING  (uint32_t)0x00000010
#define XTS_SPRS_READY    (uint32_t)0x00000011

#define RECV_BUFFER_SIZE  1000
#define NUM_FRAME 16
#define START_X 40
#define STOP_X 120

#define FRAME_RATE 16
#define UWB_NUM_PACKET ((STOP_X-START_X)*8)

#define UWB_NUM_DATA 300
#define RT_WINDOW 128
#define MAX_TAU RT_WINDOW
#define INIT_WINDOW 20*FRAME_RATE



uint32_t get_num_floats();
void set_fps(float fps);
void set_pulses_per_step(uint32_t pps);
void set_iterations(uint32_t iterations);
void set_downconversion(bool baseband);
void set_dac_step(uint8_t step);
void set_dac_min(uint32_t dac_min);
void set_dac_max(uint32_t dac_max);
void set_frame_offset(float offset);
void set_frame_area(float start_at, float stop_at);
void set_prf_div(uint8_t div);

// This method waits indefinitely for the XTS_SPRS_READY message from the radar
void wait_for_ready_message2();

// This method checks if an ACK was received from the radar
void get_ack2();

/*
 * Adds CRC, Escaping and Stop byte to the
 * send_buf and sends it over the SerialRadar.
 */
void send_command2(int len); 

  
/* 
 * Receive data from radar module
 *  -Data is stored in the global array recv_buf[]
 *  -On success it returns number of bytes received (without escape bytes
 *  -On error it returns -1
 */
int receive_data2();
int receive_float_data_msg();
int receive_float_data_msg_with_printf();

#endif
