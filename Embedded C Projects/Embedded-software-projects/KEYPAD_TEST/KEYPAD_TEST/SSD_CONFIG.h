/*
 * SSD_CONFIG.h
 *
 * Created: 10/28/2022 10:37:05 PM
 *  Author: Eng Ahmed khaled
 */ 




#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

#define  SSD_ONE 1
#define  SSD_TWO 2


void SSD_INIT(void);
void SSD_displayNOM(u8 desired_number, u8 ssdId);
void SSD_WriteHalfPort(u8 Value);
void SSD_DisplayMultiNom(u8 num);
#endif  /*SSD_INTERFACE_H*/