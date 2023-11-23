#ifndef __RADARPIM_FUNC_H__
#define __RADARPIM_FUNC_H__

#include "pim_utils.h"
#define SIZE_WORD 4
#define NUM_POINT 256
#define NUM_STAGE 8



///sensor
#define START_X 40
#define STOP_X 120
#define NUM_WINDOW NUM_POINT
#define NUM_PACKET ((STOP_X-START_X)*8)
#define LEN_FRAME (NUM_PACKET/4)

#define MEM_BASE_TD_DATA 0x00 // not shifted
#define MEM_BASE_TD_DATA2 MEM_BASE_TD_DATA + (4*NUM_WINDOW) //0x800~0xc00
#define MEM_BASE_ACC_ARRAY MEM_BASE_TD_DATA2 + (8*NUM_WINDOW)

// #define MEM_BASE_CONV2_VAL MEM_BASE_TD_DATA2 + (8*NUM_WINDOW) // 0x800~0x1800
// #define MEM_BASE_SHIFTED_TD_DATA MEM_BASE_CONV2_VAL + 8*NUM_WINDOW/NUM_UNIT  // 0x1800~0x2000
// #define MEM_BASE_OP1_ACC MEM_BASE_SHIFTED_TD_DATA   + 8*NUM_WINDOW



#define ADDR_VRC_CONV2 0x35fc
#define ADDR_MEAN_CONV2 0x35f8
#define MEM_BASE_FIR1 0x3600
#define MEM_BASE_FIR2 0x3700
#define SIZE_FIR2

#define MEM_BASE_X 0x3800
#define MEM_BASE_Y (MEM_BASE_X + 2*MEM_OFFSET_X) 
#define MEM_BASE_W (MEM_BASE_Y+2*MEM_OFFSET_X)
#define MEM_ADDR_W_LAST (MEM_BASE_W+2*MEM_OFFSET_W*NUM_STAGE)


#define MEM_OFFSET_X ((NUM_POINT/NUM_UNIT)*SIZE_WORD)          
#define MEM_OFFSET_W MEM_OFFSET_X/2
#define MEM_OFFSET_Y MEM_OFFSET_X

#define LEN_FIR1_RAW 10
#define LEN_FIR1_RAW 10
#define LEN_FIR2_ACC 20
#define ITER_FIR1 
#define ITER_FIR2 (2*NUM_WINDOW)/NUM_UNIT

#define ADDR_FIXED_ONE_OF_N 0x3f04
#define ADDR_FIXED_ONE 0x3f00



extern float time_domain_data[NUM_POINT];
extern float* X_r_fft[8];
extern float* X_i_fft[8];
extern float* Y_r_fft[8];
extern float* Y_i_fft[8];
extern float* UWB_TD_DATA[8];
extern float* ACC_ARRAY[8];
extern float* UWB_ARRAY_2[8];
extern float* UWB_ARRAY_EACH[8];
extern float* UWB_CONV1[8];
extern float* UWB_CONV2[8];
extern float* UWB_ARRAY_ABS[8];


void setup_radarpim();
// void cal_abs_uwb_data(int frame_num);
// void run_FIR1_pim();
void run_FIR2_pim();
void run_fft_pim(float *src);
// void update_TD_DATA();
void RadarPIMsetACC(float * data, int size, float * acc);
float get_ACC(int banknum, int idx);
void setup_twiddle();
void set_ACC_pim();
float getVar2(float* data, int size);
float getMean2(float* data, int size);
void update_TD_DATA_for_demo(float presdat);
#endif