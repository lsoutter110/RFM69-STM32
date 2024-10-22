/*
 * rfm69_pv.h
 *
 *  Created on: Oct 22, 2024
 *      Author: liam
 */

#ifndef RFM69_STM32_SRC_RFM69_INT_H_
#define RFM69_STM32_SRC_RFM69_INT_H_

// Pin definitions for the PicoLP (STM32L051)
#include <spi.h>
#define RF_SPI hspi1
// define your custom pins and spi handle here

#define CSMA_LIMIT             -90 // upper RX signal sensitivity threshold in dBm for carrier sense access
#define RF69_MODE_SLEEP         0   // XTAL OFF
#define RF69_MODE_STANDBY       1   // XTAL ON
#define RF69_MODE_SYNTH         2   // PLL ON
#define RF69_MODE_RX            3   // RX MODE
#define RF69_MODE_TX            4   // TX MODE
#define null                  0
#define COURSE_TEMP_COEF    -90     // puts the temperature reading in the ballpark, user can fine tune the returned value
#define RF69_BROADCAST_ADDR   0
#define RF69_CSMA_LIMIT_MS 1000
#define RF69_TX_LIMIT_MS   1000
#define RF69_FSTEP    61.03515625   // == FXOSC / 2^19 = 32MHz / 2^19 (p13 in datasheet) / FXOSC = module crystal oscillator frequency
// TWS: define CTLbyte bits
//#define RFM69_CTL_SENDACK   0x80
//#define RFM69_CTL_REQACK    0x40

void setHighPowerRegs(uint8_t onOff);
void sendFrame(uint8_t toAddress, const void* buffer, uint8_t size);
void receiveBegin();

#endif /* RFM69_STM32_SRC_RFM69_INT_H_ */
