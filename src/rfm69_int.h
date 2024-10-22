/*
 * rfm69_pv.h
 *
 *  Created on: Oct 22, 2024
 *      Author: liam
 */

#ifndef RFM69_STM32_SRC_RFM69_INT_H_
#define RFM69_STM32_SRC_RFM69_INT_H_

void setHighPowerRegs(uint8_t onOff);
void sendFrame(uint8_t toAddress, const void* buffer, uint8_t size);
void receiveBegin();

#endif /* RFM69_STM32_SRC_RFM69_INT_H_ */
