/*
 * stepper_uno.c
 *
 * Created: 29.03.2020 15:07:36
 *  Author: gju
 */ 

#ifndef F_CPU
#define F_CPU 16000000	// Has to be here (not in .h or program.c) otherwise fucked up things happen
#endif

#include <avr/io.h>
//#include <util/delay.h>
#include <stdbool.h>

//#include "./includes/utils.h"
#include "./includes/wiring.h"
#include "./includes/uart.h"
#include "./includes/stepper_uno.h"

//init();

//#define _DEBUG




bool toggle = 1; 


static char rx_Buffer[MAX_STRING]="";
int count=0;




static uint8_t previous_mm=2,ss=0,mm=2,hh=0;

static unsigned long one_sec;
static unsigned long two_sec;
static unsigned long wait_min;











/**/
/*
ISR(USART_RX_vect)
{
	
	
	uint8_t data;
	data=UDR0;
	
	rx_Buffer[count++]=data;
	if(data=='\r' || count>MAX_STRING){
	*//*	
		rx_Buffer[count]='\0';
		//printf("SET %d",rx_Buffer);
		if(strstr(rx_Buffer,"set")!=0){
			if(memcmp(rx_Buffer, "set", 3)==0)
			{
				cli();
				memmove(rx_Buffer,rx_Buffer+4,strlen(rx_Buffer)+1);
				
					hh = conv2d(rx_Buffer);
					mm = conv2d(rx_Buffer + 3);
					ss = conv2d(rx_Buffer + 6); // Get H, M, S from compile time

					setTime(hh, mm, ss, -1, 0);
					//setDate(day, date, month,age, year);

					refresh_time();	
					

					
				printf("SET %d",rx_Buffer);
				sei();
			}
		}
		*/
		/*
		count=0;
	}
}
*/







void halfStepping(uint8_t direction[]){
  uint8_t i;
  for ( i=0; i<=3; i++ ){	// step through the phases 

    PORTB = direction[i];	// single-coil part 
	delayMicroseconds(DELAY);
	
    PORTB |= direction[i+1];	// add in half-step 
	delayMicroseconds(DELAY);
	
	
  }
}

/*
void step(){
	
		PORTB = INT0_GREY ;    
		_delay_ms(DELAY);    
		PORTB = INT1_ORANGE;    
		_delay_ms(DELAY);    
		PORTB = INT2_YELLOW;    
		_delay_ms(DELAY);    
		PORTB = INT3_BLUE;    
		_delay_ms(DELAY);      
}
*/


 




FILE uart_str = FDEV_SETUP_STREAM(uart_putch, uart_getch, _FDEV_SETUP_RW);
	

int main(void)
{
	one_sec=1000L;
	two_sec=one_sec * 10L;// * 1000L;
	wait_min=one_sec*60;

	
	stdout = stdin = &uart_str;// Define Output/Input Stream

    
   	DDRB=0b00101111;
	PORTB =0x0b00100000;


	//set 4 PINB as OUTPUUT
	//DDRB |= (1<<PINB0) |(1<<PINB1) |(1<<PINB2) |(1<<PINB3);// |(1<<PINB5) ;
	//set 4 PINB as HIGH
	//PORTB = ~(1<<PINB0) & ~(1<<PINB1) & ~(1<<PINB2) & ~(1<<PINB3);// & ~(1<<PINB5);
	
	init();
	
	USART_Init( MYUBRR );
	printf("USART OK !");

	StepsRequired  = STEPS_PER_OUT_REV / 8; 


	while(1)
    {
			if(toggle == 1){
				
				//step();
				
				
				//PORTB |= (1<<PINB5);
				PORTB =0b00100000;

				for (int i=0; i<=StepsRequired; i++){
//				for (StepsRequired>0;; StepsRequired--){
					halfStepping(cw);    
				}	   
 				PORTB =0b00100000;
    
				delay(one_sec*3);
				//printf("%d-%d\n",1,now);
				toggle=0;
			}
			if(toggle == 0){
				
				//step();
				//PORTB &= ~(1<<PINB5);
				PORTB =0b00000000;
    
				for (int i=0; i<=StepsRequired; i++){
					halfStepping(ccw);    
				}   
				PORTB =0b00000000;
 
				delay(one_sec*3);

				toggle=1;
			
			}

		
	
		
	}
}

