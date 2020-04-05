/*
 * utils.c
 *
 * Created: 29.03.2020 18:38:45
 *  Author: gju
 */ 
//#include <inttypes.h>
//#include <avr/io.h>
//#include <avr/interrupt.h>
#include "../includes/utils.h"




unsigned long micros() {
/*
	unsigned long m;
	uint8_t oldSREG = SREG, t;
	
	cli();
	m = timer0_overflow_count;
#if defined(TCNT0)
	t = TCNT0;
#elif defined(TCNT0L)
	t = TCNT0L;
#else
	#error TIMER 0 not defined
#endif

#ifdef TIFR0
	if ((TIFR0 & _BV(TOV0)) && (t < 255))
		m++;
#else
	if ((TIFR & _BV(TOV0)) && (t < 255))
		m++;
#endif

	SREG = oldSREG;
	
	return ((m << 8) + t) * (64 / clockCyclesPerMicrosecond());
	*/
 	
   
	return 0;
} 