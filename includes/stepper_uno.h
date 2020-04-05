/*
 * stepper_uno.h
 *
 * Created: 30.03.2020 10:52:31
 *  Author: gju
 */ 


#ifndef STEPPER_UNO_H_
#define STEPPER_UNO_H_

	// Number of steps per internal motor revolution 
	#define STEPS_PER_REV  32 

	//  Amount of Gear Reduction
	#define GEAR_RED  64;



	// Number of steps per geared output rotation
	const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;	




	#define INT0_GREY     _BV(PB0)  
	#define INT1_ORANGE   _BV(PB1)
	#define INT2_YELLOW   _BV(PB2)	
	#define INT3_BLUE     _BV(PB3)
	
	#define DELAY  50L*100L // milliseconds between steps 
	
	/*const*/ uint8_t cw[] = {INT0_GREY, INT1_ORANGE, INT2_YELLOW, INT3_BLUE, INT0_GREY}; //ClockWise - Right-hand rotation
	/*const*/ uint8_t ccw[] = {INT3_BLUE,INT2_YELLOW, INT1_ORANGE,INT0_GREY, INT3_BLUE};  //CounterClockWise -Left-hand rotation
	//uint8_t i;
	static int StepsRequired; 
//	static void step();

 
#endif /* STEPPER_UNO_H_ */