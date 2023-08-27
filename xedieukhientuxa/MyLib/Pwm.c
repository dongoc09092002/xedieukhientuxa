#include "Pwm.h"


void pwm_set_duty( TIM_HandleTypeDef *htim,uint32_t channel , uint8_t duty){
	uint16_t ccr = (uint16_t)(((duty*1.0)/100)*( htim->Instance->ARR));
	switch(channel){
		case TIM_CHANNEL_1: 
			htim->Instance->CCR1 = ccr;
			break;
		case TIM_CHANNEL_2: 
			htim->Instance->CCR2 = ccr;
			break;
		case TIM_CHANNEL_3: 
			htim->Instance->CCR3 = ccr;
			break;
		case TIM_CHANNEL_4: 
			htim->Instance->CCR4 = ccr;
			break;
	}
}


