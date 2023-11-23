/***********************************************************************/
/*																		*/
/*	oled_rgb.h	--	Interface Declarations for IOShieldOled.cpp		*/
/*																		*/
/************************************************************************/
/*	Author:		Cristian Fatu											*/
/*	Copyright 2015, Digilent Inc.										*/
/************************************************************************/
/*
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
/************************************************************************/
/*  File Description:													*/
/*																		*/
/*	This header file contains the object class declarations and other	*/
/*	interface declarations need to use the OLED graphics display driver	*/
/*	for the Digilent Basic I/O Shield.									*/
/*																		*/
/************************************************************************/
/*  Revision History:													*/
/*																		*/
/*	07/20/2015(CristianF): created										*/
/*																		*/
/************************************************************************/

#ifndef __OLED_RGB_H__
#define __OLED_RGB_H__

/* ------------------------------------------------------------ */
/*					Miscellaneous Declarations					*/
/* ------------------------------------------------------------ */

#define OLEDRGB_WIDTH                      	96
#define OLEDRGB_HEIGHT                     	64

#define CMD_DRAWLINE                       	0x21
#define CMD_DRAWRECTANGLE                  	0x22
#define CMD_COPYWINDOW                     	0x23
#define CMD_DIMWINDOW                      	0x24
#define CMD_CLEARWINDOW                    	0x25
#define CMD_FILLWINDOW                     	0x26
#define DISABLE_FILL    0x00
#define ENABLE_FILL     0x01
#define CMD_CONTINUOUSSCROLLINGSETUP      	0x27
#define CMD_DEACTIVESCROLLING              	0x2E
#define CMD_ACTIVESCROLLING                	0x2F

#define CMD_SETCOLUMNADDRESS              	0x15
#define CMD_SETROWADDRESS                 	0x75
#define CMD_SETCONTRASTA                  	0x81
#define CMD_SETCONTRASTB                  	0x82
#define CMD_SETCONTRASTC                  	0x83
#define CMD_MASTERCURRENTCONTROL          	0x87
#define CMD_SETPRECHARGESPEEDA           	0x8A
#define CMD_SETPRECHARGESPEEDB           	0x8B
#define CMD_SETPRECHARGESPEEDC           	0x8C
#define CMD_SETREMAP                       	0xA0
#define CMD_SETDISPLAYSTARTLINE          	0xA1
#define CMD_SETDISPLAYOFFSET              	0xA2
#define CMD_NORMALDISPLAY                  	0xA4
#define CMD_ENTIREDISPLAYON              	0xA5
#define CMD_ENTIREDISPLAYOFF              	0xA6
#define CMD_INVERSEDISPLAY                 	0xA7
#define CMD_SETMULTIPLEXRATIO             	0xA8
#define CMD_DIMMODESETTING                	0xAB
#define CMD_SETMASTERCONFIGURE            	0xAD
#define CMD_DIMMODEDISPLAYON             	0xAC
#define CMD_DISPLAYOFF                     	0xAE
#define CMD_DISPLAYON    			0xAF
#define CMD_POWERSAVEMODE                 	0xB0
#define CMD_PHASEPERIODADJUSTMENT         	0xB1
#define CMD_DISPLAYCLOCKDIV               	0xB3
#define CMD_SETGRAySCALETABLE            	0xB8
#define CMD_ENABLELINEARGRAYSCALETABLE  	0xB9
#define CMD_SETPRECHARGEVOLTAGE           	0xBB
#define CMD_SETVVOLTAGE                   	0xBE

#define RGB(R,G,B)                  (((R>>3)<<11) | ((G>>2)<<5) | (B>>3))

#include "ervp_image.h"

/* ------------------------------------------------------------ */
/*					Global Variable Declarations				*/
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/*					Function Declarations					*/
/* ------------------------------------------------------------ */

void oled_rgb_start(void);
void oled_rgb_end(void);
void oled_rgb_config_spi();

void oled_rgb_clear();

void oled_rgb_draw_rectangle(unsigned char c1, unsigned char r1, unsigned char c2, unsigned char r2, unsigned short lineColor, unsigned char bFill, unsigned short fillColor);
void oled_rgb_draw_line(unsigned char c1, unsigned char r1, unsigned char c2, unsigned char r2, unsigned short lineColor);
void oled_rgb_draw_pixel(unsigned char x, unsigned char y, unsigned short pixelColor);
void oled_rgb_draw_bitmap(unsigned char c1, unsigned char r1, unsigned char c2, unsigned char r2, const unsigned char *pBmp);
void oled_rgb_copy(unsigned char c1, unsigned char r1, unsigned char c2, unsigned char r2, unsigned char c_new, unsigned char r_new);
void oled_rgb_dim_window(unsigned char c1, unsigned char r1, unsigned char c2, unsigned char r2);
void oled_rgb_start_scrolling(unsigned char c_shift_size, unsigned char start_row_addr, unsigned char r_length, unsigned char r_shift_size, unsigned char time_interval);
void oled_rgb_stop_scrolling();

void oled_rgb_draw_rvx_image(const ErvpImage *image);


/* ------------------------------------------------------------ */

#endif

/************************************************************************/
