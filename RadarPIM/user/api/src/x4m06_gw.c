// Written by: Øyvind Nydal Dahl
// Company: Novelda (XeThru)
// August 2018
#include <stdint.h>
#include "platform_info.h"
#include "ervp_printf.h"
//#include "ervp_multicore_synch.h"
#include "ervp_external_peri_group_memorymap_offset.h"
#include "ervp_mmio_util.h"



#include "ervp_variable_allocation.h"

#include "ervp_delay.h"
#include "x4m06_gw.h"
#include "uwb_api.h"
#include "ervp_real_clock.h"
volatile unsigned char send_buf[64];  // Buffer for sending data to radar. Size picked at random
volatile unsigned char recv_buf[RECV_BUFFER_SIZE];  // Buffer for receiving data from radar. Size picked at random

uint32_t content_id, info, num_floats;  // array --> not &


uint32_t get_num_floats(){
  return num_floats;
}


// Set FPS
void set_fps(float fps) 
{
  //Fill send buffer
  send_buf[0] = XT_START;
  send_buf[1] = XTS_SPC_X4DRIVER;
  send_buf[2] = XTS_SPCX_SET;
  send_buf[3] = XTS_SPCXI_FPS & 0xff;
  send_buf[4] = (XTS_SPCXI_FPS >> 8) & 0xff;
  send_buf[5] = (XTS_SPCXI_FPS >> 16) & 0xff;  
  send_buf[6] = (XTS_SPCXI_FPS >> 24) & 0xff;

  // Copy the bytes of the floats to send buffer
  memcpy(send_buf+7, &fps, 4);

  //Send the command
  send_command2(11);

  // Get ACK response from radar
  get_ack2();
}


void set_pulses_per_step(uint32_t pps)
{
  //Fill send buffer
  send_buf[0] = XT_START;
  send_buf[1] = XTS_SPC_X4DRIVER;
  send_buf[2] = XTS_SPCX_SET;
  send_buf[3] = XTS_SPCXI_PULSESPERSTEP & 0xff;
  send_buf[4] = (XTS_SPCXI_PULSESPERSTEP >> 8) & 0xff;
  send_buf[5] = (XTS_SPCXI_PULSESPERSTEP >> 16) & 0xff;  
  send_buf[6] = (XTS_SPCXI_PULSESPERSTEP >> 24) & 0xff;
  send_buf[7] = pps & 0xff;
  send_buf[8] = (pps >> 8) & 0xff;
  send_buf[9] = (pps >> 16) & 0xff;  
  send_buf[10] = (pps >> 24) & 0xff;

  //Send the command
  send_command2(11);

  // Get ACK response from radar
  get_ack2();
}



void set_iterations(uint32_t iterations)
{
  //Fill send buffer
  send_buf[0] = XT_START;
  send_buf[1] = XTS_SPC_X4DRIVER;
  send_buf[2] = XTS_SPCX_SET;
  send_buf[3] = XTS_SPCXI_ITERATIONS & 0xff;
  send_buf[4] = (XTS_SPCXI_ITERATIONS >> 8) & 0xff;
  send_buf[5] = (XTS_SPCXI_ITERATIONS >> 16) & 0xff;  
  send_buf[6] = (XTS_SPCXI_ITERATIONS >> 24) & 0xff;
  send_buf[7] = iterations & 0xff;
  send_buf[8] = (iterations >> 8) & 0xff;
  send_buf[9] = (iterations >> 16) & 0xff;  
  send_buf[10] = (iterations >> 24) & 0xff;

  //Send the command
  send_command2(11);

  // Get ACK response from radar
  get_ack2();
}



void set_downconversion(bool baseband)
{
  //Fill send buffer
  send_buf[0] = XT_START;
  send_buf[1] = XTS_SPC_X4DRIVER;
  send_buf[2] = XTS_SPCX_SET;
  send_buf[3] = XTS_SPCXI_DOWNCONVERSION & 0xff;
  send_buf[4] = (XTS_SPCXI_DOWNCONVERSION >> 8) & 0xff;
  send_buf[5] = (XTS_SPCXI_DOWNCONVERSION >> 16) & 0xff;  
  send_buf[6] = (XTS_SPCXI_DOWNCONVERSION >> 24) & 0xff;

  if (baseband)
    send_buf[7] = 0x01;
  else
    send_buf[7] = 0x00;

  //Send the command
  send_command2(8);

  // Get ACK response from radar
  get_ack2();
}


void set_dac_step(uint8_t step)
{
  //Fill send buffer
  send_buf[0] = XT_START;
  send_buf[1] = XTS_SPC_X4DRIVER;
  send_buf[2] = XTS_SPCX_SET;
  send_buf[3] = XTS_SPCXI_DACSTEP & 0xff;
  send_buf[4] = (XTS_SPCXI_DACSTEP >> 8) & 0xff;
  send_buf[5] = (XTS_SPCXI_DACSTEP >> 16) & 0xff;  
  send_buf[6] = (XTS_SPCXI_DACSTEP >> 24) & 0xff;
  send_buf[7] = step;

  //Send the command
  send_command2(8);

  // Get ACK response from radar
  get_ack2();
}

void set_dac_min(uint32_t dac_min)
{
  //Fill send buffer
  send_buf[0] = XT_START;
  send_buf[1] = XTS_SPC_X4DRIVER;
  send_buf[2] = XTS_SPCX_SET;
  send_buf[3] = XTS_SPCXI_DACMIN & 0xff;
  send_buf[4] = (XTS_SPCXI_DACMIN >> 8) & 0xff;
  send_buf[5] = (XTS_SPCXI_DACMIN >> 16) & 0xff;  
  send_buf[6] = (XTS_SPCXI_DACMIN >> 24) & 0xff;
  send_buf[7] = dac_min & 0xff;
  send_buf[8] = (dac_min >> 8) & 0xff;
  send_buf[9] = (dac_min >> 16) & 0xff;  
  send_buf[10] = (dac_min >> 24) & 0xff;

  //Send the command
  send_command2(11);

  // Get ACK response from radar
  get_ack2();
}


void set_dac_max(uint32_t dac_max)
{
  //Fill send buffer
  send_buf[0] = XT_START;
  send_buf[1] = XTS_SPC_X4DRIVER;
  send_buf[2] = XTS_SPCX_SET;
  send_buf[3] = XTS_SPCXI_DACMAX & 0xff;
  send_buf[4] = (XTS_SPCXI_DACMAX >> 8) & 0xff;
  send_buf[5] = (XTS_SPCXI_DACMAX >> 16) & 0xff;  
  send_buf[6] = (XTS_SPCXI_DACMAX >> 24) & 0xff;
  send_buf[7] = dac_max & 0xff;
  send_buf[8] = (dac_max >> 8) & 0xff;
  send_buf[9] = (dac_max >> 16) & 0xff;  
  send_buf[10] = (dac_max >> 24) & 0xff;

  //Send the command
  send_command2(11);

  // Get ACK response from radar
  get_ack2();
}


void set_frame_offset(float offset) 
{
  //Fill send buffer
  send_buf[0] = XT_START;
  send_buf[1] = XTS_SPC_X4DRIVER;
  send_buf[2] = XTS_SPCX_SET;
  send_buf[3] = XTS_SPCXI_FRAMEAREAOFFSET & 0xff;
  send_buf[4] = (XTS_SPCXI_FRAMEAREAOFFSET >> 8) & 0xff;
  send_buf[5] = (XTS_SPCXI_FRAMEAREAOFFSET >> 16) & 0xff;  
  send_buf[6] = (XTS_SPCXI_FRAMEAREAOFFSET >> 24) & 0xff;

  // Copy the bytes of the floats to send buffer
  memcpy(send_buf+7, &offset, 4);

  //Send the command
  send_command2(11);

  // Get ACK response from radar
  get_ack2();
}

void set_frame_area(float start_at, float stop_at)
{
  //Fill send buffer
  send_buf[0] = XT_START;
  send_buf[1] = XTS_SPC_X4DRIVER;
  send_buf[2] = XTS_SPCX_SET;
  send_buf[3] = XTS_SPCXI_FRAMEAREA & 0xff;
  send_buf[4] = (XTS_SPCXI_FRAMEAREA >> 8) & 0xff;
  send_buf[5] = (XTS_SPCXI_FRAMEAREA >> 16) & 0xff;  
  send_buf[6] = (XTS_SPCXI_FRAMEAREA >> 24) & 0xff;

  // Copy the bytes of the floats to send buffer
  memcpy(send_buf+7, &start_at, 4);
  memcpy(send_buf+11, &stop_at, 4);

  //Send the command
  send_command2(15);

  // Get ACK response from radar
  get_ack2();
}



void set_prf_div(uint8_t div)
{
  //Fill send buffer
  send_buf[0] = XT_START;
  send_buf[1] = XTS_SPC_X4DRIVER;
  send_buf[2] = XTS_SPCX_SET;
  send_buf[3] = XTS_SPCXI_PRFDIV & 0xff;
  send_buf[4] = (XTS_SPCXI_PRFDIV >> 8) & 0xff;
  send_buf[5] = (XTS_SPCXI_PRFDIV >> 16) & 0xff;  
  send_buf[6] = (XTS_SPCXI_PRFDIV >> 24) & 0xff;
  send_buf[7] = div;

  //Send the command
  send_command2(8);

  // Get ACK response from radar
  get_ack2();
}


// This method waits indefinitely for the XTS_SPRS_READY message from the radar
void wait_for_ready_message2()
{
  printf("Waiting for XTS_SPRS_READY...\n");
  while (true) {
    if (receive_data2() < 1)
      continue;

    if (recv_buf[1] != XTS_SPR_SYSTEM)
      continue;

    uint32_t response_code = (uint32_t)recv_buf[2] | ((uint32_t)recv_buf[3] << 8) | ((uint32_t)recv_buf[4] << 16) | ((uint32_t)recv_buf[5] << 24);
    if (response_code == (uint32_t)XTS_SPRS_READY) {
      printf("Received XTS_SPRS_READY!\n");
      return;
    }
    else if (response_code == (uint32_t)XTS_SPRS_BOOTING)
      printf("Radar is booting...\n");
  }
}

// This method checks if an ACK was received from the radar
void get_ack2()
{
  int len = receive_data2();

  if (len == 0)
    printf("No response from radar\n");
  else if (len < 0)
    printf("Error in response from radar\n");
  else if (recv_buf[1] != XTS_SPR_ACK)  // Check response for ACK
    printf("Did not receive ACK!\n");
}


/*
 * Adds CRC, Escaping and Stop byte to the
 * send_buf and sends it over the SerialRadar.
 */
void send_command2(int len) 
{ 
  unsigned char crc = 0;

  // Calculate CRC
  for (int i = 0; i < len; i++)
    crc ^= send_buf[i];

  // Add CRC to send buffer
  send_buf[len] = crc;
  len++;

  // Go through send buffer and add escape characters where needed
  for (int i = 1; i < len; i++) {
    if (send_buf[i] == XT_START || send_buf[i] == XT_STOP || send_buf[i] == XT_ESCAPE)
    {
      // Shift following bytes one place up
      for (int u=len; u > i; u--)
        send_buf[u] = send_buf[u-1];

      // Add escape byte at old byte location
      send_buf[i] = XT_ESCAPE;

      // Increase length by one
      len++;

      // Increase counter so we don't process it again
      i++;
    }
  } 

  // Send data (including CRC) and XT_STOP
  // SerialRadar.write(send_buf, len);
  //SerialRadar.write(XT_STOP);
  uwb_uart_write2((char *)send_buf, len);
  uwb_uart_put2(XT_STOP);

  // Print out sent data for debugging:
  printf("Sent: ");  
  for (int i = 0; i < len; i++) {
    printf("%x",send_buf[i]);
    printf(" ");
  }
  printf("%x\n",XT_STOP);
}


/* 
 * Receive data from radar module
 *  -Data is stored in the global array recv_buf[]
 *  -On success it returns number of bytes received (without escape bytes
 *  -On error it returns -1
 */
int receive_data2() {

  int recv_len = 0;  //Number of bytes received

  // Wait 500 ms if nothing is available yet
  if (!uwb_uart_available2())
    delay_ms(500);
  // Wait for start character
  

  while (uwb_uart_available2()) 
  //while(1)
  {
    
    unsigned char c = uwb_uart_read2();  // Get one byte from radar

    // If we receive an ESCAPE character, the next byte is never the real start character
    if (c == XT_ESCAPE)
    {
      // Wait for next byte and skip it.
      while (!uwb_uart_available2());
      printf("Ignoring because escape: ");
      printf("%x",uwb_uart_read2());
    }
    else if (c == XT_START) 
    {
      // If it's the start character we fill the first character of the buffer and move on
      recv_buf[0] = c;
      recv_len = 1;
      break;
    }

    // Wait 10 ms if nothing is available yet
    if (!uwb_uart_available2())
      delay_ms(10);
  }

  // Wait 10 ms if nothing is available yet
  if (!uwb_uart_available2())
    delay_ms(10);

  // Start receiving the rest of the bytes
  while (uwb_uart_available2()) 
  {
    // read a byte
    unsigned char c = uwb_uart_read2(); // Get one byte from radar

    // is it an escape byte?
    if (c == XT_ESCAPE)
    {
      // If it's an escape character next character in buffer is data and not special character:
      while (!uwb_uart_available2());
      c = uwb_uart_read2();
    }
    // is it the stop byte?
    else if (c == XT_STOP) {
      // Fill response buffer, and increase counter
      recv_buf[recv_len++] = c;
      break;  //Exit this loop 
    }

    // Fill response buffer, and increase counter
    recv_buf[recv_len++] = c;

    // Wait 10 ms if nothing is available yet
    if (!uwb_uart_available2())
      delay_ms(10);
  }

#if 1
  // Print received data
  printf("Received: ");
  for (int i = 0; i < recv_len; i++) {
    printf("%x",recv_buf[i]);
    printf(" ");
  }
  printf(" \n");
#endif

  // If nothing was received, return 0.
  if (recv_len==0)
    return 0;

  // If stop character was not received, return with error.
  if (recv_buf[recv_len-1] != XT_STOP)
    return -1;


  //
  // Calculate CRC
  //
  unsigned char crc = 0;

  // CRC is calculated without the crc itself and the stop byte, hence the -2 in the counter
  for (int i = 0; i < recv_len-2; i++) 
    crc ^= recv_buf[i];

  // Check if calculated CRC matches the recieved
  if (crc == recv_buf[recv_len-2]) 
  {
    return recv_len;  // Return length of received data (without escape bytes) upon success
  }
  else 
  {
    printf("CRC mismatch: ");
    printf("%x",crc);
    printf(" != ");
    printf("%x\n", recv_buf[recv_len-2]);
    return -1; // Return -1 upon crc failure
  } 
}


int receive_float_data_msg(char* packet) {

  bool start_sequence_received = false;
  int recv_len = 0;  //Number of bytes received
  int discarded = 0; //Number of bytes discarded

  uint32_t packet_length = 0;

  // uint32_t content_id, info, num_floats;  // array --> not &
  //volatile char* data_array_c = (char*) data_array;

  // Wait for XTS_FLAGSEQUENCE_START_NOESCAPE sequence (0x7C7C7C7C)


  while (!start_sequence_received) 
  {
    while (!uwb_uart_available2()) {}    
    unsigned char c = uwb_uart_read2();  // Get one byte from radar
    if (c == 0x7C)
    {
      //printf("First 7C received");
      while (!uwb_uart_available2()) {}
      if (uwb_uart_read2() != 0x7C) {
        discarded++;
        continue;
      }

      //printf("Second 7C received");
      while (!uwb_uart_available2()) {}
      if (uwb_uart_read2() != 0x7C) {
        discarded++;
        continue;
      }

      //printf("Third 7C received");
      while (!uwb_uart_available2()) {}
      if (uwb_uart_read2() == 0x7C)
        start_sequence_received = true;
      else {
        discarded++;
        continue;
      }
    }
    else {
      discarded++;
    }
  }

  while (!uwb_uart_available2()) {}
  uwb_uart_byte_read((char *)&packet_length, 4);


  while (!uwb_uart_available2()) {}
  uwb_uart_read2();



  // Read byte XTS_SPR_DATA
  while (!uwb_uart_available2()) {}
  uwb_uart_read2();

  // Read byte XTS_SPRD_FLOAT
  while (!uwb_uart_available2()) {}
  uwb_uart_read2();



  while (!uwb_uart_available2()) {}
  //SerialRadar.readBytes((char [])&content_id, 4);
  uwb_uart_byte_read((char *)&content_id, 4);
  while (!uwb_uart_available2()) {}
  //SerialRadar.readBytes((char [])&info, 4);
  uwb_uart_byte_read((char *)&info, 4);
  while (!uwb_uart_available2()) {}
  //SerialRadar.readBytes((char [])&num_floats, 4);
  uwb_uart_byte_read((char *)&num_floats, 4);


 while (recv_len < packet_length-14) {
      while(!uwb_uart_available2()){}
        packet[recv_len++] = uwb_uart_read2();
  }
  return 0;
}




int receive_float_data_msg_with_printf() {

//   bool start_sequence_received = false;
//   int recv_len = 0;  //Number of bytes received
//   int discarded = 0; //Number of bytes discarded

//   uint32_t packet_length = 0;

//   uint32_t content_id, info, num_floats;  // array --> not &


//   // Wait for XTS_FLAGSEQUENCE_START_NOESCAPE sequence (0x7C7C7C7C)
//   while (!start_sequence_received) 
//   {
//     while (!uwb_uart_available2()) {}    

//     unsigned char c = uwb_uart_read2();  // Get one byte from radar
//     if (c == 0x7C)
//     {
//       //printf("First 7C received");
//       while (!uwb_uart_available2()) {}
//       if (uwb_uart_read2() != 0x7C) {
//         discarded++;
//         continue;
//       }

//       //printf("Second 7C received");
//       while (!uwb_uart_available2()) {}
//       if (uwb_uart_read2() != 0x7C) {
//         discarded++;
//         continue;
//       }

//       //printf("Third 7C received");
//       while (!uwb_uart_available2()) {}
//       if (uwb_uart_read2() == 0x7C)
//         start_sequence_received = true;
//       else {
//         discarded++;
//         continue;
//       }
//     }
//     else {
//       discarded++;
//     }
//   }
//   while (!uwb_uart_available2()) {}
//   uwb_uart_byte_read((char *)&packet_length, 4);

//   while (!uwb_uart_available2()) {}
//   uwb_uart_read2();
//   // Read byte XTS_SPR_DATA
//   while (!uwb_uart_available2()) {}
//   uwb_uart_read2();

//   // Read byte XTS_SPRD_FLOAT
//   while (!uwb_uart_available2()) {}
//   uwb_uart_read2();

//   while (!uwb_uart_available2()) {}
//   //SerialRadar.readBytes((char [])&content_id, 4);
//   uwb_uart_byte_read((char *)&content_id, 4);
//   while (!uwb_uart_available2()) {}
//   //SerialRadar.readBytes((char [])&info, 4);
//   uwb_uart_byte_read((char *)&info, 4);
//   while (!uwb_uart_available2()) {}
//   //SerialRadar.readBytes((char [])&num_floats, 4);
//   uwb_uart_byte_read((char *)&num_floats, 4);
//  while (recv_len < packet_length-14) {
//       while(!uwb_uart_available2()){}
//       uwb_arr[gnum_frame][recv_len++] = uwb_uart_read2();
//     }

//   int max_pos = -1;
//   float max_val = 0.0;
//   float * float_ptr;

//   for (int i=0; i < num_floats; i++)
//   {
//     float_ptr = (float*)&uwb_arr[gnum_frame][i*4];

//     if (*float_ptr > max_val) {
//       max_val = *float_ptr;
//       max_pos = i;
//     }

//     // There are some issues when printing floats with a lot of decimals, 
//     // so here we're converting to int (and loosing resolution)
//     //SerialDebug.print((int)(radar_data[i]*10000), DEC);

//     printf("index : %d, fp : %.4f",i+1,*float_ptr);
//     printf("\n");
//   }

// printf("\npacket_len = %d\n",packet_length);
// printf("\ncontent id : %d\n",content_id);
// printf("\ninfo :  %d\n",info);
// printf("\nn_float = %d\n",num_floats);



return 0;

}
