/*
 * EXT_INT_confg.h
 *
 * Created: 9/24/2019 3:44:11 PM
 *  Author: Ashraf Amgad
 */ 


#ifndef EXT_INT_CONFG_H_
#define EXT_INT_CONFG_H_


// INIT			
// UNINIT	
#define EXTINT_0_INIT		INIT
#define EXTINT_1_INIT		INIT
#define EXTINT_2_INIT		UNINIT


// EXTINT_MODE_LOW_LEVEL						
// EXTINT_MODE_HIGH_LEVEL						
// EXTINT_MODE_ANY_LOGICAL_CHANGE				
// EXTINT_MODE_FALLING_EDGE					 
// EXTINT_MODE_RISING_EDGE					
#define EXTINT_0_MODE					EXTINT_MODE_FALLING_EDGE
#define EXTINT_1_MODE					EXTINT_MODE_FALLING_EDGE
#define EXTINT_2_MODE					EXTINT_MODE_LOW_LEVEL




#endif /* EXT_INT_CONFG_H_ */
