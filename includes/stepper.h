/*
 * stepper.h
 *
 * Created: 29.03.2020 15:30:53
 *  Author: gju
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_

	// Number of steps per internal motor revolution 
	//const float STEPS_PER_REV = 32; 
	#define STEPS_PER_REV  32 

	//  Amount of Gear Reduction
	//const float GEAR_RED = 64;
	#define GEAR_RED  64;
	

	//Define Variables

static long number_of_steps;      // total number of steps this motor can take 

 
 int direction;            // Direction of rotation 
 static int pin_count;            // how many pins are in use. 
 static unsigned long last_step_time; // time stamp in us of when the last step was taken 
 static int step_number;          // which step the motor is on
static unsigned long step_delay; // delay between steps, in ms, based on speed 
 
 static int steps;

 
 // mover method:
 //void step(int number_of_steps);
 void step(int steps_to_move);
 unsigned long getSpeed();
 void stepMotor(int thisStep);
 void stopMotor();
 int getSteps();
#endif /* STEPPER_H_ */