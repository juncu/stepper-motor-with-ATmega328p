#include "../includes/uart.h"
#include <util/delay.h>

void USART_Init( unsigned int ubrr)
{

	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	/* Set frame format: 8data, 2stop bit */
	UCSR0C |=  (1<<UCSZ01) | (1<<UCSZ00); 
	//  UCSR0C = 0b00000110; //asyncronus  8-2-none;
/*               ||||||||
//	       UMSELn1|||||||   
//	        UMSELn0||||||    
//             UPMn1|||||
//              UPM0|||||
//               USBS||||
//              UCSZn1||| 
//               UCSZn0||
//                  UCPOL
/*
Bit 7 - (1)URSEL => select UCSRC or UBRRH
    6 - (0)UMSEL => 0=Asyncronous 1=Syncronous
 	5 - (0)UPM1 & UPM0 => Parity Mode 00=NO 10= EVEN 11=ODD
 	4 - (0)UPM0 & UPM0 => Parity Mode 00=NO 10= EVEN 11=ODD
    3 - (0)USBS Stopbit 0=1 bit / 1=2 bit
    2 - (1)UCSZ1 Character Size UCSZ1=1/UCSZ0=1 => 8 bit
    1 - (1)UCSZ0 Character Size UCSZ1=1/UCSZ0=0 => 7 bit
    0 - (0)UCPOL Clock Parity 0=Risig Edge 1=Falling Edge
*/


	/*Enable receiver and transmitter & Rx-Int enable*/
 	UCSR0B = (1<<RXEN0)|(1<<TXEN0) | (1<< RXCIE0);
	/*
Bit 7 - (0)RXCIEn: RX Complete Interrupt Enable
    6 - (0)TXCIEn: TX Complete Interrupt Enable
    5 - (0)UDRIEn: USART recv Register Empty Interrupt Enable
    4 - (0)RXENn: Receiver Enable
    3 - (0)TXENn: Transmitter Enable
    2 - (0)UCSZn2: Character Size
    1 - (0)RXB8n: Receive recv Bit 8
    0 - (0)TXB8n: Transmit recv Bit 8
*/ 
	
}


void uart_flush(void)
{
  unsigned char dummy;
  while (UCSR0A & (1<<RXC0)) 
	dummy = UDR0;
}

int uart_putch(char ch,FILE *stream)
{
   if (ch == '\n')
    uart_putch('\r', stream);
   while (!(UCSR0A & (1<<UDRE0)));
   UDR0=ch;
//   return 0;
   return ch;
}
int uart_getch(FILE *stream)
{
   unsigned char ch;
   while (!(UCSR0A & (1<<RXC0)));
   ch=UDR0;  

   /* Echo the Output Back to terminal */
   uart_putch(ch,stream);       

   return ch;
}


