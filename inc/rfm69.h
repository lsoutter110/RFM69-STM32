// **********************************************************************************
// Driver definition for HopeRF RFM69W/RFM69HW/RFM69CW/RFM69HCW, Semtech SX1231/1231H
// **********************************************************************************
// Copyright Felix Rusu 2016, http://www.LowPowerLab.com/contact
// **********************************************************************************
// License
// **********************************************************************************
// This program is free software; you can redistribute it 
// and/or modify it under the terms of the GNU General    
// Public License as published by the Free Software       
// Foundation; either version 3 of the License, or        
// (at your option) any later version.                    
//                                                        
// This program is distributed in the hope that it will   
// be useful, but WITHOUT ANY WARRANTY; without even the  
// implied warranty of MERCHANTABILITY or FITNESS FOR A   
// PARTICULAR PURPOSE. See the GNU General Public        
// License for more details.                              
//                                                        
// Licence can be viewed at                               
// http://www.gnu.org/licenses/gpl-3.0.txt
//
// Please maintain this license information along with authorship
// and copyright notices in any redistribution of this code
// **********************************************************************************


// **********************************************************************************
// Converted to AVR environment by Zulkar Nayem
// Modified by Willow Herring
// Modified by Liam Soutter
// **********************************************************************************

#ifndef RFM69_H
#define RFM69_H

#define RF69_MAX_DATA_LEN       61  // to take advantage of the built in AES/CRC we want to limit the frame size to the internal FIFO size (66 bytes - 3 bytes overhead - 2 bytes crc)

// Global Variables
extern volatile uint8_t DATA[RF69_MAX_DATA_LEN+1];  // RX/TX payload buffer, including end of string NULL char

// Function Declarations
void rfm69_init(uint16_t freqBand, uint8_t nodeID, uint8_t networkID);
void rcCalibration();

void setAddress(uint8_t addr);
void setNetwork(uint8_t networkID);
void setFrequency(uint32_t freqHz);
void setPowerLevel(uint8_t level);
void setMode(uint8_t mode);
void sleep();
void encrypt(const char* key);

uint32_t getFrequency();
int16_t readRSSI(uint8_t forceTrigger);

uint8_t canSend();
void send(uint8_t toAddress, const void* buffer, uint8_t bufferSize);
void promiscuous(uint8_t onOff);
uint8_t receiveDone();

uint8_t readReg(uint8_t addr);
void writeReg(uint8_t addr, uint8_t val);

#endif

