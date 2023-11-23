

#include "radarpim_func.h"
#include "pim_utils.h"
#include "ervp_printf.h"

float time_domain_data[NUM_POINT];

float cos_t[NUM_POINT/2] = {
	1.00000000F, 0.99969882F, 0.99879546F, 0.99729046F, 0.99518473F, 0.99247953F, 0.98917651F, 0.98527764F, 
	0.98078528F, 0.97570213F, 0.97003125F, 0.96377607F, 0.95694034F, 0.94952818F, 0.94154407F, 0.93299280F, 
	0.92387953F, 0.91420976F, 0.90398929F, 0.89322430F, 0.88192126F, 0.87008699F, 0.85772861F, 0.84485357F, 
	0.83146961F, 0.81758481F, 0.80320753F, 0.78834643F, 0.77301045F, 0.75720885F, 0.74095113F, 0.72424708F, 
	0.70710678F, 0.68954054F, 0.67155895F, 0.65317284F, 0.63439328F, 0.61523159F, 0.59569930F, 0.57580819F, 
	0.55557023F, 0.53499762F, 0.51410274F, 0.49289819F, 0.47139674F, 0.44961133F, 0.42755509F, 0.40524131F, 
	0.38268343F, 0.35989504F, 0.33688985F, 0.31368174F, 0.29028468F, 0.26671276F, 0.24298018F, 0.21910124F, 
	0.19509032F, 0.17096189F, 0.14673047F, 0.12241068F, 0.09801714F, 0.07356456F, 0.04906767F, 0.02454123F, 
	0.00000000F, -0.02454123F, -0.04906767F, -0.07356456F, -0.09801714F, -0.12241068F, -0.14673047F, -0.17096189F, 
	-0.19509032F, -0.21910124F, -0.24298018F, -0.26671276F, -0.29028468F, -0.31368174F, -0.33688985F, -0.35989504F, 
	-0.38268343F, -0.40524131F, -0.42755509F, -0.44961133F, -0.47139674F, -0.49289819F, -0.51410274F, -0.53499762F, 
	-0.55557023F, -0.57580819F, -0.59569930F, -0.61523159F, -0.63439328F, -0.65317284F, -0.67155895F, -0.68954054F, 
	-0.70710678F, -0.72424708F, -0.74095113F, -0.75720885F, -0.77301045F, -0.78834643F, -0.80320753F, -0.81758481F, 
	-0.83146961F, -0.84485357F, -0.85772861F, -0.87008699F, -0.88192126F, -0.89322430F, -0.90398929F, -0.91420976F, 
	-0.92387953F, -0.93299280F, -0.94154407F, -0.94952818F, -0.95694034F, -0.96377607F, -0.97003125F, -0.97570213F, 
	-0.98078528F, -0.98527764F, -0.98917651F, -0.99247953F, -0.99518473F, -0.99729046F, -0.99879546F, -0.99969882F
}; 
float sin_t[NUM_POINT/2] = {
	-0.00000000F, -0.02454123F, -0.04906767F, -0.07356456F, -0.09801714F, -0.12241068F, -0.14673047F, -0.17096189F, 
	-0.19509032F, -0.21910124F, -0.24298018F, -0.26671276F, -0.29028468F, -0.31368174F, -0.33688985F, -0.35989504F, 
	-0.38268343F, -0.40524131F, -0.42755509F, -0.44961133F, -0.47139674F, -0.49289819F, -0.51410274F, -0.53499762F, 
	-0.55557023F, -0.57580819F, -0.59569930F, -0.61523159F, -0.63439328F, -0.65317284F, -0.67155895F, -0.68954054F, 
	-0.70710678F, -0.72424708F, -0.74095113F, -0.75720885F, -0.77301045F, -0.78834643F, -0.80320753F, -0.81758481F, 
	-0.83146961F, -0.84485357F, -0.85772861F, -0.87008699F, -0.88192126F, -0.89322430F, -0.90398929F, -0.91420976F, 
	-0.92387953F, -0.93299280F, -0.94154407F, -0.94952818F, -0.95694034F, -0.96377607F, -0.97003125F, -0.97570213F, 
	-0.98078528F, -0.98527764F, -0.98917651F, -0.99247953F, -0.99518473F, -0.99729046F, -0.99879546F, -0.99969882F, 
	-1.00000000F, -0.99969882F, -0.99879546F, -0.99729046F, -0.99518473F, -0.99247953F, -0.98917651F, -0.98527764F, 
	-0.98078528F, -0.97570213F, -0.97003125F, -0.96377607F, -0.95694034F, -0.94952818F, -0.94154407F, -0.93299280F, 
	-0.92387953F, -0.91420976F, -0.90398929F, -0.89322430F, -0.88192126F, -0.87008699F, -0.85772861F, -0.84485357F, 
	-0.83146961F, -0.81758481F, -0.80320753F, -0.78834643F, -0.77301045F, -0.75720885F, -0.74095113F, -0.72424708F, 
	-0.70710678F, -0.68954054F, -0.67155895F, -0.65317284F, -0.63439328F, -0.61523159F, -0.59569930F, -0.57580819F, 
	-0.55557023F, -0.53499762F, -0.51410274F, -0.49289819F, -0.47139674F, -0.44961133F, -0.42755509F, -0.40524131F, 
	-0.38268343F, -0.35989504F, -0.33688985F, -0.31368174F, -0.29028468F, -0.26671276F, -0.24298018F, -0.21910124F, 
	-0.19509032F, -0.17096189F, -0.14673047F, -0.12241068F, -0.09801714F, -0.07356456F, -0.04906767F, -0.02454123F
}; 


const float FIR1_RAW[LEN_FIR1_RAW] = {
    10.0F,10.0F,10.0F,10.0F,10.0F,10.0F,10.0F,10.0F,10.0F,10.0F
};


const float FIR2_ACC[20] = {1.0F,1.0F,1.0F,1.0F,1.0F,1.0F,1.0F,1.0F,1.0F,1.0F,1.0F,1.0F,1.0F,1.0F,1.0F,1.0F,1.0F,1.0F,1.0F};


typedef struct __IDX_PAIR{
    uint32_t addr_int;
    uint32_t bank_num;
}IDX_PAIR;

// float* FIR1_RAW_bank[8];
// float* FIR2_RAW_bank[8];
// float* UWB_ARRAY_EACH[8];
// float* UWB_ARRAY_ABS[8];
// float* UWB_ARRAY_2[8];
// float* UWB_CONV1[8];

float dataMean0 [256];
float* UWB_TD_DATA[8];
float* UWB_TD_DATA2[8];

float* UWB_CONV2[8];
float* CONV2_MEAN_PSUM[8];
float* CONV2_VRC_PSUM[8];
float* ACC_ARRAY[8];

float* X_r_fft[8];
float* X_i_fft[8];
float* Y_r_fft[8];
float* Y_i_fft[8];

int idx_reverse[NUM_POINT];

static inline int reverse_bit(int x)
{
    int temp = 0;
    for(int i=0; i<NUM_STAGE; i++)
        temp |= (((x&(0x00000001<<i))>>i)<<(NUM_STAGE-i-1));
    return temp;
}

static inline int get_twiddle_index(int ss_log, int bank_num, int widx_each){
    return ((((bank_num)*(NUM_POINT/NUM_UNIT)/2)|widx_each)<<(NUM_STAGE-ss_log))&(NUM_POINT/2-1);
}
static inline void set_wr(int ss_log, int bank_num, int data_idx, float data)
{
    PIM_ARRAY_FL(bank_num, MEM_BASE_W+((2*ss_log-2)*MEM_OFFSET_W)+(SIZE_WORD*data_idx)) = data;
}

static inline void set_wi(int ss_log, int bank_num, int data_idx, float data)
{
    PIM_ARRAY_FL(bank_num, MEM_BASE_W+((2*ss_log-1)*MEM_OFFSET_W)+(SIZE_WORD*data_idx)) = data;
}


// static void set_FIR1(){
//     init_array(MEM_BASE_FIR1-NUM_UNIT*4,LEN_FIR1_RAW+2*NUM_UNIT,sizeof(float));
//     for(int i=0;i<LEN_FIR1_RAW;i++){
//         store_copied_vector(FIR1_RAW[i], MEM_BASE_FIR1+4*i);
//     }
// }


static inline void set_reverse_bit(){
    for(int i=0;i<NUM_POINT;i++){
        idx_reverse[i] = reverse_bit(i);
    }
}

static void setup_ptrs(){
    for(int i=0;i<NUM_UNIT;i++){
        //UWB_ARRAY_EACH[i] = PIM_PTR(i,MEM_BASE_UWB_ARRAY);
        X_r_fft[i] = PIM_PTR(i,MEM_BASE_X);
        X_i_fft[i] = PIM_PTR(i,MEM_BASE_X + MEM_OFFSET_X);
        Y_r_fft[i] = PIM_PTR(i,MEM_BASE_Y);
        Y_i_fft[i] = PIM_PTR(i,MEM_BASE_Y + MEM_OFFSET_Y);
        //FIR1_RAW_bank[i] = PIM_PTR(i,MEM_BASE_FIR1);
        //FIR2_RAW_bank[i] = PIM_PTR(i,MEM_BASE_FIR2);
        //UWB_ARRAY_ABS[i] = PIM_PTR(i,MEM_BASE_UWB_ARRAY_ABS);
        //UWB_ARRAY_2[i] = PIM_PTR(i,MEM_BASE_UWB_ARRAY2);
        //UWB_CONV1[i] = PIM_PTR(i,MEM_BASE_CONV1_VAL);
        UWB_TD_DATA[i] = PIM_PTR(i,MEM_BASE_TD_DATA);
        UWB_TD_DATA2[i] = PIM_PTR(i,MEM_BASE_TD_DATA2);
        
        CONV2_MEAN_PSUM[i] = PIM_PTR(i,ADDR_MEAN_CONV2);
        CONV2_VRC_PSUM[i] = PIM_PTR(i,ADDR_VRC_CONV2);
        ACC_ARRAY[i] = PIM_PTR(i,MEM_BASE_ACC_ARRAY);
    }
    set_reverse_bit();
}

// static void set_FIR1(){
//     init_array(MEM_BASE_FIR1,LEN_FIR1_RAW+NUM_UNIT,sizeof(float));
//     for(int i=0;i<LEN_FIR1_RAW;i++){
//         store_rshifted_vector(FIR1_RAW[i], MEM_BASE_FIR1+4*i);
//     }
// }
// static void set_FIR2(){
//     init_array(MEM_BASE_FIR2,NUM_WINDOW+NUM_UNIT,sizeof(float));
//     for(int i=0;i<LEN_FIR2_ACC;i++){
//         store_rshifted_vector(FIR2_ACC[LEN_FIR2_ACC-i], MEM_BASE_FIR2+4*i);
//     }
// }

static void init_TD_DATA(){
    init_array(MEM_BASE_TD_DATA, NUM_WINDOW, sizeof(float));
    init_array(MEM_BASE_TD_DATA2, 2*NUM_WINDOW, sizeof(float));
}

// static float find_repr_data(){
//     float temp_max = 0.0F;
//     float temp_val;
//     for(int i=0; i<LEN_UWB_ARRAY_EACH;i++){
//         for(int j=0;j<NUM_UNIT;j++){
//             temp_val = UWB_CONV1[j][i];
//             if(temp_val>temp_max){
//                 temp_max = temp_val;
//             }
//         }
//     }
//     return temp_max;
// }



// static float get_mean_CONV2_DATA(){
//     float mean = 0.0F;
//     radar_pim_set_inst(PIM_INST_MAC_ACC(0xff, MEM_BASE_CONV2_VAL, ADDR_FIXED_ONE_OF_N));
//     radar_pim_inst_auto_incr(0b010,NUM_WINDOW/NUM_UNIT,4);
//     radar_pim_set_inst(PIM_INST_ACC_GET(0xff,ADDR_MEAN_CONV2));
//     radar_pim_set_inst(PIM_INST_ACC_CLEAR(0xff));
//     for(int i=0;i<NUM_UNIT;i++){
//         mean += (*CONV2_MEAN_PSUM[i]);
//     }
//     return mean;
// }

// static float get_var_CONV2_DATA(float mean){
//     float var = 0.0F;

//     radar_pim_set_inst(PIM_INST_MAC_ACC(0xff, MEM_BASE_CONV2_VAL, ADDR_FIXED_ONE_OF_N));
//     radar_pim_inst_auto_incr(0b010,NUM_WINDOW/NUM_UNIT,4);
//     radar_pim_set_inst(PIM_INST_ACC_GET(0xff,ADDR_MEAN_CONV2));
//     radar_pim_set_inst(PIM_INST_ACC_CLEAR(0xff));
//     for(int i=0;i<NUM_UNIT;i++){
//         mean += (*CONV2_MEAN_PSUM[i]);
//     }
//     return mean;
// }


static void setup_time_data_for_fft(float* src){
    for(int i=0; i<(NUM_UNIT); i++){
        for(int j=0; j<(NUM_POINT/NUM_UNIT); j++){
            X_r_fft[i][j] = src[idx_reverse[(i*(NUM_POINT/NUM_UNIT)+j)]];
            X_i_fft[i][j] = 0.0F;
        }
    }
}



float getVar2(float* data, int size){
    float val = 0.0F;
    //float mean = get_mean(data,size);
    
    for(int i=0;i<size;i++){
        val+=(data[i])*(data[i]);
    }
    val /= (float)size;
    return val;
}

float getMean2(float* data, int size){
    float val = 0.0F;
    for(int i=0;i<size;i++){
        val+=data[i];
    }
    val /= (float)size;
    return val;
} 
void setup_radarpim(){
    setup_ptrs();
    // set_FIR1();
    // set_FIR2();
    init_TD_DATA();
    setup_twiddle();
    store_copied_vector(1.0F,ADDR_FIXED_ONE);
    store_copied_vector((float)1.0F/((float)NUM_POINT),ADDR_FIXED_ONE_OF_N);
}

void cal_abs_uwb_data(int frame_num){
//     radar_pim_set_inst(PIM_INST_FL_MULT(0xff,MEM_BASE_UWB_ARRAY_ABS,MEM_BASE_UWB_ARRAY+(4*frame_num*LEN_UWB_ARRAY_EACH),MEM_BASE_UWB_ARRAY+(4*frame_num*LEN_UWB_ARRAY_EACH)));
//     radar_pim_inst_auto_incr(0b111,LEN_UWB_ARRAY_EACH,4); 
    
//     for(int i=0; i<LEN_UWB_ARRAY_EACH;i++){
//         for(int j=0;j<NUM_UNIT;j++){
//             store_copied_vector(UWB_ARRAY_ABS[j][i],MEM_BASE_UWB_ARRAY2+4*(NUM_UNIT*i+j));
//         }
//     }
}

void run_FIR1_pim(){
    //     radar_pim_set_inst(PIM_INST_ACC_CLEAR(0xff));
    // for(int i=0; i<LEN_UWB_ARRAY_EACH;i++){
    //     radar_pim_set_inst(PIM_INST_MAC_ACC(0xff, MEM_BASE_UWB_ARRAY2+8*4*i, MEM_BASE_FIR1));
    //     radar_pim_inst_auto_incr(0b011,LEN_FIR1_RAW+NUM_UNIT-1,4);
    //     radar_pim_set_inst(PIM_INST_ACC_GET(0xff,MEM_BASE_CONV1_VAL+4*i));
    //     radar_pim_set_inst(PIM_INST_ACC_CLEAR(0xff));
    // }
}

void run_FIR2_pim(){
    // for(int i=0; i<2*NUM_WINDOW/NUM_UNIT;i++){
    //     radar_pim_set_inst(PIM_INST_MAC_ACC(0xff, MEM_BASE_TD_DATA+8*4*i, MEM_BASE_FIR2));
    //     radar_pim_inst_auto_incr(0b011,LEN_FIR2_ACC+NUM_UNIT-1,4);
    //     radar_pim_set_inst(PIM_INST_ACC_GET(0xff,MEM_BASE_CONV2_VAL+4*i));
    //     radar_pim_set_inst(PIM_INST_ACC_CLEAR(0xff));
    // }
}

void update_TD_DATA(){
    float data = find_repr_data();

    float back_up_last[8];
    radar_pim_set_inst(PIM_INST_MOVE_INT(0xff,MEM_BASE_TD_DATA,MEM_BASE_TD_DATA+4));
    radar_pim_inst_auto_incr(0b110,NUM_WINDOW,4);
    store_copied_vector(data,MEM_BASE_TD_DATA+4*(NUM_WINDOW-1));
}

void update_TD_DATA_for_demo(float presdat){
    // float data = presdat;

    // float back_up_last[8];
    // radar_pim_set_inst(PIM_INST_MOVE_INT(0xff,MEM_BASE_TD_DATA,MEM_BASE_TD_DATA+4));
    // radar_pim_inst_auto_incr(0b110,NUM_WINDOW,4);
    // store_copied_vector(data,MEM_BASE_TD_DATA+4*(NUM_WINDOW-1));
}

void RadarPIMsetACC(float * data, int size, float * acc){
    float mean = getMean2(data,size);
    
    for(int i=0; i<size;i++){
        dataMean0[i] = data[i]-mean;
    }

    float var = getVar2(dataMean0,size);
    for(int i=0; i<size;i++){
        store_copied_vector(dataMean0[i], MEM_BASE_TD_DATA+4*i);
        store_rshifted_vector(dataMean0[i], MEM_BASE_TD_DATA2+4*i);
    }

    for(int i=0; i<size/NUM_UNIT; i++){
        int lag = NUM_UNIT*i;
        radar_pim_set_inst(PIM_INST_ACC_CLEAR(0xff));
        radar_pim_set_inst(PIM_INST_MAC_ACC(0xff,get_addr_offset(&UWB_TD_DATA[0][lag]),get_addr_offset(&UWB_TD_DATA2[0][0])));
        radar_pim_inst_auto_incr(0b011,size-lag,4);
        radar_pim_set_inst(PIM_INST_ACC_GET(0xff,get_addr_offset(&ACC_ARRAY[0][i])));
    }
    
    for(int i=0; i<size/NUM_UNIT;i++){
        for(int j=0;j<NUM_UNIT;j++){
            int lag = NUM_UNIT*i+j;
            acc[lag] = ACC_ARRAY[j][i]/(var*(size-lag));
        }
    }

}

float get_ACC(int banknum, int idx){
    return UWB_TD_DATA[banknum][idx];
}

void run_fft_pim(float *src){
    setup_time_data_for_fft(&src[0]);
    for(int ss_log=1; ss_log<=NUM_STAGE; ss_log++){
        radar_pim_set_inst(NABI_CAL(0xff, MEM_BASE_Y, MEM_BASE_X, MEM_BASE_W+(2*(ss_log-1)*MEM_OFFSET_W)));
        radar_pim_set_inst(NABI_CAL(0xff, MEM_BASE_Y+8, MEM_BASE_X+8, MEM_BASE_W+(2*(ss_log-1)*MEM_OFFSET_W)+4));
        radar_pim_set_inst(NABI_CAL(0xff, MEM_BASE_Y+16, MEM_BASE_X+16, MEM_BASE_W+(2*(ss_log-1)*MEM_OFFSET_W)+8));
        radar_pim_set_inst(NABI_CAL(0xff, MEM_BASE_Y+24, MEM_BASE_X+24, MEM_BASE_W+(2*(ss_log-1)*MEM_OFFSET_W)+12));
        radar_pim_set_inst(NABI_CAL(0xff, MEM_BASE_Y+32, MEM_BASE_X+32, MEM_BASE_W+(2*(ss_log-1)*MEM_OFFSET_W)+16));
        radar_pim_set_inst(NABI_CAL(0xff, MEM_BASE_Y+40, MEM_BASE_X+40, MEM_BASE_W+(2*(ss_log-1)*MEM_OFFSET_W)+20));
        radar_pim_set_inst(NABI_CAL(0xff, MEM_BASE_Y+48, MEM_BASE_X+48, MEM_BASE_W+(2*(ss_log-1)*MEM_OFFSET_W)+24));
        radar_pim_set_inst(NABI_CAL(0xff, MEM_BASE_Y+56, MEM_BASE_X+56, MEM_BASE_W+(2*(ss_log-1)*MEM_OFFSET_W)+28));
        wait_pim();
        radar_pim_set_inst(NABI_CAL(0xff, MEM_BASE_Y+64, MEM_BASE_X+64, MEM_BASE_W+(2*(ss_log-1)*MEM_OFFSET_W)+32));
        radar_pim_set_inst(NABI_CAL(0xff, MEM_BASE_Y+72, MEM_BASE_X+72, MEM_BASE_W+(2*(ss_log-1)*MEM_OFFSET_W)+36));
        radar_pim_set_inst(NABI_CAL(0xff, MEM_BASE_Y+80, MEM_BASE_X+80, MEM_BASE_W+(2*(ss_log-1)*MEM_OFFSET_W)+40));
        radar_pim_set_inst(NABI_CAL(0xff, MEM_BASE_Y+88, MEM_BASE_X+88, MEM_BASE_W+(2*(ss_log-1)*MEM_OFFSET_W)+44));
        radar_pim_set_inst(NABI_CAL(0xff, MEM_BASE_Y+96, MEM_BASE_X+96, MEM_BASE_W+(2*(ss_log-1)*MEM_OFFSET_W)+48));
        radar_pim_set_inst(NABI_CAL(0xff, MEM_BASE_Y+104, MEM_BASE_X+104, MEM_BASE_W+(2*(ss_log-1)*MEM_OFFSET_W)+52));
        radar_pim_set_inst(NABI_CAL(0xff, MEM_BASE_Y+112, MEM_BASE_X+112, MEM_BASE_W+(2*(ss_log-1)*MEM_OFFSET_W)+56));
        radar_pim_set_inst(NABI_CAL(0xff, MEM_BASE_Y+120, MEM_BASE_X+120, MEM_BASE_W+(2*(ss_log-1)*MEM_OFFSET_W)+60));
        wait_pim();
        radar_pim_set_inst(NABI_MOVE(0xff, MEM_BASE_X, MEM_BASE_Y, ss_log));
        radar_pim_inst_auto_incr(0b010,NUM_POINT/NUM_UNIT,4);
        radar_pim_set_inst(NABI_MOVE(0xff, MEM_BASE_X+MEM_OFFSET_X, MEM_BASE_Y+MEM_OFFSET_Y, ss_log));
        radar_pim_inst_auto_incr(0b010,NUM_POINT/NUM_UNIT,4);
    }

}




void setup_twiddle(){
    for(int ss_log=1; ss_log<=NUM_STAGE; ss_log++){
        for(int i=0;i<NUM_UNIT;i++){
            for(int j=0;j<(NUM_POINT/NUM_UNIT)/2;j++){
                set_wr(ss_log, i, j, cos_t[get_twiddle_index(ss_log,i,j)]);
                set_wi(ss_log, i, j, sin_t[get_twiddle_index(ss_log,i,j)]);
            }
        }
    }
}

