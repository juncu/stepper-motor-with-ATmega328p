/*
 * timer.c
 *
 * Created: 12.03.2020 09:32:13
 *  Author: gju
 */ 

#include "../includes/timer.h"


void init_timer()
{
 
 
  //++++++++++ Initial ATMega368 Timer/Counter0 Peripheral ++++++++//
  //Timer anhalten, Prescaler Reset
  GTCCR |= (1 << TSM) | (1 << PSRASY);	

  TCCR0A=0x00;                  // Normal Timer0 Operation
  TCCR0B=(1<<CS01);   // 8 prescaller: Clk/8
  //TCCR0B=(1<<CS00);   // NO prescaller: Clk
  //TCCR0B=(1<<CS02)|(1<<CS00);   // Use maximum prescaller: Clk/1024

  GTCCR &= ~(1 << TSM);//Timer starten

  TCNT0=TIMER_RESET;                   // Start counter from 0x94, overflow at 10 mSec

  //TCNT0=15;                   // Start counter from 0x94, overflow at 10 mSec
  
  TIMSK0=(1<<TOIE0);            // Enable Counter Overflow Interrupt
 
  
 
/* 
 
//set timer2 interrupt at 8kHz
  TCCR2A = 0;// set entire TCCR2A register to 0
  TCCR2B = 0;// same for TCCR2B
  TCNT2  = 0;//initialize counter value to 0
  // set compare match register for 8khz increments
  OCR2A = 249;// = (16*10^6) / (8000*8) - 1 (must be <256)
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
  // Set CS21 bit for 8 prescaler
  TCCR2B |= (1 << CS21);   
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);
 */ 
 sei();                        // Enable Interrupt
  
}  