/*
 * SSD_interface.h
 *
 * Created: 10/28/2022 10:34:30 PM
 *  Author: AMIT
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_


#define SSD_ONE       1        
#define SSD_TWO       2


void SSD_initDirections     (void);
void SSD_displayNumber      (u8 desiredNumber,u8 ssdId);
void SSD_displayMultiNumber (u8 desiredNumber);
void SSD_writeHalfPort      (u8 value);

#endif /* SSD_INTERFACE_H_ */