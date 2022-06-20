/*
 * EXT_INT_priv.h
 *
 * Created: 9/24/2019 3:43:51 PM
 *  Author: Ashraf Amgad
 */ 


#ifndef EXT_INT_PRIV_H_
#define EXT_INT_PRIV_H_


#define STATUS_REG								(*(volatile u8*)(0x5F))
#define GENERAL_INT_CONTROL_REG					(*(volatile u8*)(0x5B))
#define GENERAL_INT_FLAG_REG					(*(volatile u8*)(0x5A))
#define MCU_CONTROL_REG							(*(volatile u8*)(0x55))
#define MCU_CONTROL_STATUS_REG					(*(volatile u8*)(0x54))
	
#define INT_1_ADDRESS							(*(volatile u8*)(0x02))
#define INT_0_ADDRESS							(*(volatile u8*)(0x04))
#define INT_2_ADDRESS							(*(volatile u8*)(0x24))

#define INIT				1
#define UNINIT				0

#define EXTINT_MODE_LOW_LEVEL						0
#define EXTINT_MODE_HIGH_LEVEL						1
#define EXTINT_MODE_ANY_LOGICAL_CHANGE				2
#define EXTINT_MODE_FALLING_EDGE					3
#define EXTINT_MODE_RISING_EDGE						4


#endif /* EXT_INT_PRIV_H_ */
