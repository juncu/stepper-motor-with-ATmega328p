/*
 * gju_stepper.c
 *
 * Created: 29.03.2020 15:32:53
 *  Author: gju
 */ 
#include <avr/io.h>
#include "../includes/stepper.h"

//#include "../includes/utils.h"

//unsigned long step_delay; // delay between steps, in ms, based on speed 


/*
 * Moves the motor forward or backwards.
 */
void stopMotor()
{
	PORTB = 0b00100000; 
}


/*
 * Moves the motor forward or backwards.
 */
void stepMotor(int thisStep)
{
	

  if (pin_count == 4) {
	  //steps++;
	  
    switch (thisStep) {
      case 0:  // 1010
        /*
		digitalWrite(motor_pin_1, HIGH);
        digitalWrite(motor_pin_2, LOW);
        digitalWrite(motor_pin_3, HIGH);
        digitalWrite(motor_pin_4, LOW);
        */
		//PORTB |= ~(1<<PINB0) | (1<<PINB1) | ~(1<<PINB2) | (1<<PINB3); 
		PORTB = 0b00001010; 
      break;
      case 1:  // 0110
		/*
        digitalWrite(motor_pin_1, LOW);
        digitalWrite(motor_pin_2, HIGH);
        digitalWrite(motor_pin_3, HIGH);
        digitalWrite(motor_pin_4, LOW);
		*/
		//PORTB |= ~(1<<PINB0) | (1<<PINB1) | (1<<PINB2) | ~(1<<PINB3); 
		PORTB = 0b00100110; 

      break;
      case 2:  //0101
        /*
		digitalWrite(motor_pin_1, LOW);
        digitalWrite(motor_pin_2, HIGH);
        digitalWrite(motor_pin_3, LOW);
        digitalWrite(motor_pin_4, HIGH);
		*/
		//PORTB |= ~(1<<PINB0) | (1<<PINB1) | ~(1<<PINB2) | (1<<PINB3);
		PORTB = 0b00000101; 
 
	  break;
      case 3:  //1001
		/*
        digitalWrite(motor_pin_1, HIGH);
        digitalWrite(motor_pin_2, LOW);
        digitalWrite(motor_pin_3, LOW);
        digitalWrite(motor_pin_4, HIGH);
		*/
		//PORTB |= (1<<PINB0) | ~(1<<PINB1) | ~(1<<PINB2) | (1<<PINB3);
		PORTB = 0b00101001; 
 
	  break;
    }
  }
  
	
	
	
/*	
  if (this->pin_count == 2) {
    switch (thisStep) {
      case 0:  // 01
		digitalWrite(motor_pin_1, LOW);
		
        digitalWrite(motor_pin_2, HIGH);
      break;
      case 1:  // 11
        digitalWrite(motor_pin_1, HIGH);
        digitalWrite(motor_pin_2, HIGH);
      break;
      case 2:  // 10
        digitalWrite(motor_pin_1, HIGH);
        digitalWrite(motor_pin_2, LOW);
      break;
      case 3:  // 00
        digitalWrite(motor_pin_1, LOW);
        digitalWrite(motor_pin_2, LOW);
      break;
    }
  }
  if (this->pin_count == 4) {
    switch (thisStep) {
      case 0:  // 1010
        digitalWrite(motor_pin_1, HIGH);
        digitalWrite(motor_pin_2, LOW);
        digitalWrite(motor_pin_3, HIGH);
        digitalWrite(motor_pin_4, LOW);
      break;
      case 1:  // 0110
        digitalWrite(motor_pin_1, LOW);
        digitalWrite(motor_pin_2, HIGH);
        digitalWrite(motor_pin_3, HIGH);
        digitalWrite(motor_pin_4, LOW);
      break;
      case 2:  //0101
        digitalWrite(motor_pin_1, LOW);
        digitalWrite(motor_pin_2, HIGH);
        digitalWrite(motor_pin_3, LOW);
        digitalWrite(motor_pin_4, HIGH);
      break;
      case 3:  //1001
        digitalWrite(motor_pin_1, HIGH);
        digitalWrite(motor_pin_2, LOW);
        digitalWrite(motor_pin_3, LOW);
        digitalWrite(motor_pin_4, HIGH);
      break;
    }
  }

  if (this->pin_count == 5) {
    switch (thisStep) {
      case 0:  // 01101
        digitalWrite(motor_pin_1, LOW);
        digitalWrite(motor_pin_2, HIGH);
        digitalWrite(motor_pin_3, HIGH);
        digitalWrite(motor_pin_4, LOW);
        digitalWrite(motor_pin_5, HIGH);
        break;
      case 1:  // 01001
        digitalWrite(motor_pin_1, LOW);
        digitalWrite(motor_pin_2, HIGH);
        digitalWrite(motor_pin_3, LOW);
        digitalWrite(motor_pin_4, LOW);
        digitalWrite(motor_pin_5, HIGH);
        break;
      case 2:  // 01011
        digitalWrite(motor_pin_1, LOW);
        digitalWrite(motor_pin_2, HIGH);
        digitalWrite(motor_pin_3, LOW);
        digitalWrite(motor_pin_4, HIGH);
        digitalWrite(motor_pin_5, HIGH);
        break;
      case 3:  // 01010
        digitalWrite(motor_pin_1, LOW);
        digitalWrite(motor_pin_2, HIGH);
        digitalWrite(motor_pin_3, LOW);
        digitalWrite(motor_pin_4, HIGH);
        digitalWrite(motor_pin_5, LOW);
        break;
      case 4:  // 11010
        digitalWrite(motor_pin_1, HIGH);
        digitalWrite(motor_pin_2, HIGH);
        digitalWrite(motor_pin_3, LOW);
        digitalWrite(motor_pin_4, HIGH);
        digitalWrite(motor_pin_5, LOW);
        break;
      case 5:  // 10010
        digitalWrite(motor_pin_1, HIGH);
        digitalWrite(motor_pin_2, LOW);
        digitalWrite(motor_pin_3, LOW);
        digitalWrite(motor_pin_4, HIGH);
        digitalWrite(motor_pin_5, LOW);
        break;
      case 6:  // 10110
        digitalWrite(motor_pin_1, HIGH);
        digitalWrite(motor_pin_2, LOW);
        digitalWrite(motor_pin_3, HIGH);
        digitalWrite(motor_pin_4, HIGH);
        digitalWrite(motor_pin_5, LOW);
        break;
      case 7:  // 10100
        digitalWrite(motor_pin_1, HIGH);
        digitalWrite(motor_pin_2, LOW);
        digitalWrite(motor_pin_3, HIGH);
        digitalWrite(motor_pin_4, LOW);
        digitalWrite(motor_pin_5, LOW);
        break;
      case 8:  // 10101
        digitalWrite(motor_pin_1, HIGH);
        digitalWrite(motor_pin_2, LOW);
        digitalWrite(motor_pin_3, HIGH);
        digitalWrite(motor_pin_4, LOW);
        digitalWrite(motor_pin_5, HIGH);
        break;
      case 9:  // 00101
        digitalWrite(motor_pin_1, LOW);
        digitalWrite(motor_pin_2, LOW);
        digitalWrite(motor_pin_3, HIGH);
        digitalWrite(motor_pin_4, LOW);
        digitalWrite(motor_pin_5, HIGH);
        break;
    }
  }
  */
}
 











unsigned long getSpeed()
{
  return step_delay;
}


/*
 * getSteps
*/
int getSteps()
{
	return steps;
}
 
void step(int steps_to_move){
	  int steps_left = abs(steps_to_move);  // how many steps to take

	// determine direction based on whether steps_to_mode is + or -:
	if (steps_to_move > 0) { 
		direction = 1; 
	}
	
	if (steps_to_move < 0) { 
		direction = 0; 
	}


  // decrement the number of steps, moving one step each time:
	while (steps_left > 0)
	{
		unsigned long now = micros();
		// move only if the appropriate delay has passed:
		if (now - last_step_time >= step_delay)
		{
			// get the timeStamp of when you stepped:
			last_step_time = now ;
			// increment or decrement the step number,	depending on direction:
			if (direction == 1){
				step_number++;
				if (step_number == number_of_steps) {
					step_number = 0;
				}
			}
			else{
				if (step_number == 0) {
					step_number = number_of_steps;
				}
				step_number--;
			}
			// decrement the steps left:
			steps_left--;
      
			// step the motor to step number 0, 1, ..., {3 or 10}
			if (pin_count == 5)
				stepMotor(step_number % 10);
			else
				stepMotor(step_number % 4);
		}
		
	} 
};