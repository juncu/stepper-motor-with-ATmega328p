#ifndef UART_H
#define UART_H
#endif

#include <avr/io.h>
#include <stdio.h> //for FILE

#define FOSC 16000000 // Clock Speed   OK !!!!
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

#define	MAX_STRING 256


extern void USART_Init( unsigned int ubrr);
extern void uart_flush(void);
extern int uart_putch(char ch,FILE *stream);
extern int uart_getch(FILE *stream);
