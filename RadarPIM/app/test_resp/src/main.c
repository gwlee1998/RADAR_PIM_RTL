#include <stdint.h>
#include "ervp_printf.h"
#include "ervp_reg_util.h"
#include "ervp_memory_util.h"
#include "ervp_core_id.h"
#include "ervp_multicore_synch.h"
#include "ervp_real_clock.h"
#include "ervp_delay.h"
#include "pim_utils.h"
#include "radarpim_func.h"
#include "x4m06_gw.h"
#include "oled_rgb.h"
#include "radar_image.h"
#include "uwb_api.h"

#define ITER (FRAME_RATE*1200)


volatile int timer_start2;
volatile int timer_end2;
volatile float freq_domain[NUM_WINDOW];

char raw_packet [NUM_FRAME][LEN_FRAME];
float normalized [NUM_FRAME][LEN_FRAME];
float uwb_arr2[UWB_NUM_DATA];
float acc[NUM_WINDOW];

float * float_ptr;
float ptr_val_r = 0.0F;
float ptr_val_i = 0.0F;
int max_pos_acc=0;
int last_mp = LEN_FRAME/2;
float ptr_val = 0.0F;
float g_max_val =0.0F;
int frame_idx=0;
int frame_valid=0;


int main(){
    if(EXCLUSIVE_ID==0){
        setup_radarpim();
        oled_rgb_config_spi();
        oled_rgb_clear();
        oled_rgb_start();
        for(int i =0; i<64;i++){
            for(int j =0 ;j<96; j++){
                bmp_radar[2*(OLEDRGB_WIDTH*i+j)] = 0;
                bmp_radar[2*(OLEDRGB_WIDTH*i+j)+1] =0;
            }
        }
        for(int i = 0; i<NUM_WINDOW; i++){
            time_domain_data[i] = 0.0F;
        }
        printf("X4M06 Rrespiration Test !\n");
        uwb_uart_init2();
        printf("1.uart_init\n");
        wait_for_ready_message2();
        printf("2.wait_ready_message\n");
        set_pulses_per_step(87);
        set_downconversion(false);
        set_iterations(64);
        set_dac_min(949);
        set_dac_max(1100);
        set_dac_step(1);
        set_prf_div(16);
        set_frame_offset(0.2);
        set_frame_area((float)((float)START_X/100.0), (float)((float)STOP_X/100.0));
        printf("3.set parameter\n");
        // Setting the fps to something higher than 0 will make the radar start sending data
        set_fps(FRAME_RATE);
        printf("4.set fps\n");
    }

  reach_and_pass_barrier(0,2);
  printf("start!\n");
  flush_cache();


    if(EXCLUSIVE_ID==0){
        int iter=0;
        do{
            receive_float_data_msg(raw_packet[iter%NUM_FRAME]);
            frame_valid = 1;
            frame_idx = iter%NUM_FRAME;
            printf("core0: %d\n",frame_idx);
            reach_and_pass_barrier(0,NUM_CORE);
            iter++;
        }while(iter<ITER);

        frame_valid = 0;
    }
    else{

        float last_val = 0.0F;
        float last_val2 = 0.0F;
        float max_val = 0.0F;
        float max_val_oled = 0.0F;
        float min_val_oled = 10000.0F;
        float max_freq = 0.0F;
        float max_acc = 0.0F;
        float val_temp;
        int num_floats = (int)get_num_floats();
        int numBins = num_floats/2;
        int stride = NUM_WINDOW/96+1;
        int norm1 = 0;
        float norm2 = 0.0F;
        int max_pos =0;
        float data_normalized=0.0f;
        while(!frame_valid) delay_ms(10);
        while(frame_valid){
            

         num_floats = (int)get_num_floats();
            printf("core1 : %d, numfloats : %d\n",frame_idx,get_num_floats());
            for (int j=0; j< num_floats; j++)
                {
                    float_ptr = (float*)&raw_packet[frame_idx][4*j];
                    ptr_val = *float_ptr;
                    norm1=(j-last_mp)*(j-last_mp);
                    norm2 = 0.5F+1.0F/((float)norm1+2.0F);
                    ptr_val = ptr_val*norm2;

                    if(ptr_val<0.0F){
                        ptr_val = -ptr_val;
                    }
                    ptr_val = (ptr_val+last_val+last_val2)/3.0F;
                    last_val2 = last_val;
                    last_val = ptr_val;
                    if (ptr_val > max_val) {
                        max_val = ptr_val;
                        max_pos = j;
                        if(ptr_val>g_max_val){
                            g_max_val = ptr_val;
                        }
                    }
                    data_normalized = 31.0F*(ptr_val)/(g_max_val);
                    normalized[frame_idx][j] = (data_normalized);
                }

            int distance = START_X + (max_pos*(STOP_X-START_X))/num_floats;
            
            last_mp = (7*last_mp+max_pos)/8;
            g_max_val = 0.96875F*g_max_val + 0.03125F*max_val;

            float present_data = 0.0F;
            for(int i = last_mp-5; i<last_mp+5;i++){
                if(i>=0){
                    present_data+=normalized[frame_idx][i];
                }
            }
            present_data /= 10.0F;

            for(int i = 1; i<NUM_WINDOW; i++){
                time_domain_data[i-1] = time_domain_data[i];
            }
            time_domain_data[NUM_WINDOW-1] = present_data;
            
            timer_start2 = get_real_clock_tick();
                    RadarPIMsetACC(time_domain_data,NUM_WINDOW,acc);
                    // run_fft_pim(acc);
                 run_fft_pim(&time_domain_data[0]);
            timer_end2 = get_real_clock_tick();
            max_val = 0.0F;
            max_pos = 0;
            X_r_fft[0][0] = 0;
            X_i_fft[0][0] = 0;
            X_r_fft[0][1] = 0;
            X_i_fft[0][1] = 0;
            for(int i=0;i<NUM_UNIT/2;i++){
                for(int j=0;j<NUM_POINT/NUM_UNIT;j++){
                    // freq_domain[NUM_UNIT*j+i] = (X_r_fft[i][j]*X_r_fft[i][j])+(X_i_fft[i][j]*X_i_fft[i][j]);
                    float tmp = (X_r_fft[i][j]*X_r_fft[i][j])+(X_i_fft[i][j]*X_i_fft[i][j]);
                    if(tmp>max_val){
                        max_val = tmp;
                        max_pos = NUM_POINT/NUM_UNIT*i+j;
                    }
                }
            }
            printf("\n\n\n\n\n\n\tRADAR PROCESSING IN PIM takes %dus\n\n",timer_end2-timer_start2);
            printf("\n\n\t\t\t==================================================\n");
            printf("\n\n\t\t\t<<\t\trespiration rate\t\t>>\n");
            printf("\n\n\t\t\t\t\t\t%drpm\n",(60*max_pos)/16);
            printf("\n\n\t\t\t==================================================\n\n\n\n\n\n\n\n\n");
            max_val = 0.0F;

            for(int i=0; i<NUM_WINDOW;i++){
                //uwb_arr2[i] = UWB_CONV2[banknum][internal_idx];
                //uwb_arr2[i] = acc[i];
                uwb_arr2[i] = time_domain_data[i];
            }
            for(int i =0; i<NUM_WINDOW;i++){
                if(uwb_arr2[i] > max_val_oled){
                    max_val_oled = uwb_arr2[i];
                }
                if(uwb_arr2[i]<min_val_oled){
                    min_val_oled = uwb_arr2[i];
                }
            }
            
            for (int i=NUM_WINDOW-96; i<NUM_WINDOW ; i++){
                int j = 96-(NUM_WINDOW-i);
                int temp_oled = (int)(60.0F*((uwb_arr2[i]-min_val_oled)/(max_val_oled-min_val_oled)));
                for(int k=0;k<64;k++){
                    if(((k > (64-temp_oled)-2)&&(k < (64-temp_oled)+2))){
                        bmp_radar[2*(OLEDRGB_WIDTH*k+j)] =  255;
                        bmp_radar[2*(OLEDRGB_WIDTH*k+j)+1] = 255;
                    }
                    else {
                        bmp_radar[2*(OLEDRGB_WIDTH*k+j)] =  0;
                        bmp_radar[2*(OLEDRGB_WIDTH*k+j)+1] = 0;
                    }
                }
            }
        
            oled_rgb_draw_bitmap(0,0,95,63, &bmp_radar[0]);
            reach_and_pass_barrier(0,NUM_CORE);
        }


    }
    printf("MEM_W_LAST ADDR : %dk\n",MEM_ADDR_W_LAST);
    printf("end!\n");
    return 0;
}
