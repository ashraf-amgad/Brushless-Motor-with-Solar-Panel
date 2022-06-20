/*
 * DIO_utils.h
 *
 * Created: 9/11/2019 8:56:41 AM
 *  Author: Ashraf Amgad
 */ 


#ifndef UTILS_H_
#define UTILS_H_


#define Set_Bit(reg,bit_num)		    (reg |= (1<<bit_num) )
#define Clr_Bit(reg,bit_num)			(reg &= (~(1<<bit_num)) )
#define Tog_Bit(reg,bit_num)			(reg ^= (1<<bit_num) )
#define Get_Bit(reg,bit_num)			( (reg>>bit_num) & 0x01 )
#define SET_BITS(Reg , Mask)			(Reg |= Mask)
#define CLR_BITS(Reg , Mask)			(Reg &= ~(Mask)) 
#define Set_Port(Reg , Mask)			(Reg = Mask)

#endif /* UTILS_H_ */
