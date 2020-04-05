/*
 * timer.h
 *
 * Created: 12.03.2020 09:31:42
 *  Author: gju
 */ 


#ifndef _TIMER_H_
#define _TIMER_H_

#include <avr/interrupt.h>


//16000000 / 1024 =15.652 255-15 = 240 = 0xF0
//#define TIMER_RESET  0xF1//0xF0
//OCR2A = 249;// = (16*10^6) / (8000*8) - 1 (must be <256)
//(16000000 / 64000)=250 -> 1 tick = 0,5 uSec 
//#define TIMER_RESET  249
#define TIMER_RESET 249  //256-249

void init_timer();



#endif /* TIMER_H_ */