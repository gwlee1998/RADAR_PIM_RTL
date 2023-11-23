#ifndef __ORVP_I2C_DEFINE_H__
#define __ORVP_I2C_DEFINE_H__

/*
 * Definitions for the Opencores i2c master core
 */

/* --- Definitions for i2c master's registers --- */
	
/* ----- Read-write access                                            */

#define I2C_PRER_LO (0x00)     /* Low byte clock prescaler register  */	
#define I2C_PRER_HI (0x04)     /* High byte clock prescaler register */	
#define I2C_CTR     (0x08)     /* Control register                   */	
										
/* ----- Write-only registers                                         */
										
#define I2C_TXR     (0x0c)     /* Transmit byte register             */	
#define I2C_CR      (0x10)     /* Command register                   */	
	
/* ----- Read-only registers                                          */
										
#define I2C_RXR     (0x0c)     /* Receive byte register              */
#define I2C_SR      (0x10)     /* Status register                    */
	
/* ----- Bits definition                                              */
#define I2C_TXR_RW_WR	(0)
#define I2C_TXR_RW_RD	(1)
#define I2C_TXR_RW_MASK	(0x01)
	
/* ----- Control register                                             */
	
#define I2C_EN (1<<7)        /* Core enable bit:                   */
                                /*      1 - core is enabled           */
                                /*      0 - core is disabled          */
#define I2C_IEN (1<<6)       /* Interrupt enable bit               */
                                /*      1 - Interrupt enabled         */
                                /*      0 - Interrupt disabled        */
                                /* Other bits in CR are reserved      */

/* ----- Command register bits                                        */
 
#define I2C_STA (1<<7)       /* Generate (repeated) start condition*/
#define I2C_STO (1<<6)       /* Generate stop condition            */
#define I2C_RD  (1<<5)       /* Read from slave                    */
#define I2C_WR  (1<<4)       /* Write to slave                     */
#define I2C_ACK (1<<3)       /* Acknowledge from slave             */
                                /*      1 - ACK                       */
                                /*      0 - NACK                      */
#define I2C_IACK (1<<0)      /* Interrupt acknowledge              */

/* ----- Status register bits                                         */

#define I2C_RXACK (1<<7)     /* ACK received from slave            */
                                /*      1 - ACK                       */
                                /*      0 - NACK                      */
#define I2C_BUSY  (1<<6)     /* Busy bit                           */
#define I2C_TIP   (1<<1)     /* Transfer in progress               */
#define I2C_IF    (1<<0)     /* Interrupt flag                     */

/* bit testing and setting macros                                     */

#define ISSET(reg,bitmask)       ((reg)&(bitmask))
#define ISCLEAR(reg,bitmask)     (!(ISSET(reg,bitmask)))
#define BITSET(reg,bitmask)      ((reg)|(bitmask))
#define BITCLEAR(reg,bitmask)    ((reg)|(~(bitmask)))
#define BITTOGGLE(reg,bitmask)   ((reg)^(bitmask))
#define REGMOVE(reg,value)       ((reg)=(value))

#define IDLE asm volatile ("")

#endif
