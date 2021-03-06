/*
 * timer_cfg.h
 *
 * Created: 3/12/2020 6:27:12 PM
 *  Author: Ashraf Amgad
 */ 


#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_



/* TIMER_INIT , TIMER_UNINIT */
#define TIMER_0_INIT	TIMER_INIT
#define TIMER_2_INIT	TIMER_UNINIT

/* TIMER_PRESCALER_1 , TIMER_PRESCALER_8 , TIMER_PRESCALER_32 , TIMER_PRESCALER_64 , TIMER_PRESCALER_128 , TIMER_PRESCALER_256 , TIMER_PRESCALER_1024 */
#define TIMER_0_PRESCALER    TIMER_PRESCALER_64
#define TIMER_2_PRESCALER    TIMER_PRESCALER_64


/* TIMER_MODE_NORMAL , TIMER_MODE_CTC , TIMER_MODE_FAST_PWM , TIMER_MODE_PHASE_CORRECT_PWM */
#define TIMER_0_MODE		(TIMER_MODE_FAST_PWM)

/* TIMER_MODE_NORMAL , TIMER_MODE_CTC  , TIMER_MODE_FAST_PWM , TIMER_MODE_PHASE_CORRECT_PWM */
#define TIMER_2_MODE		(TIMER_MODE_CTC)


/* TIMER_OCn_NON_PWM_DISCONNECT			  , TIMER_OCn_NON_PWM_TOGGLE                     , TIMER_OCn_NON_PWM_CLEAR  , TIMER_OCn_NON_PWM_SET */
/* TIMER_OCn_FAST_PWM_DISCONNECT          , TIMER_OCn_FAST_PWM_SET_AT_TOP                 , TIMER_OCn_FAST_PWM_CLEAR_AT_TOP  */
/* TIMER_OCn_PHASE_CORRECT_PWM_DISCONNECT , TIMER_OCn_PHASE_CORRECT_PWM_CLEAR_AT_UP_COUNT , TIMER_OCn_PHASE_CORRECT_PWM_SET_AT_UP_COUNT  */
#define TIMER_0_OC0_MODE		(TIMER_OCn_FAST_PWM_SET_AT_TOP)
#define TIMER_2_OC2_MODE		(TIMER_OCn_NON_PWM_DISCONNECT)



#endif /* TIMER_CFG_H_ */
