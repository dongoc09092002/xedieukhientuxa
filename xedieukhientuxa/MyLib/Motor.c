#include "Motor.h"
#include "Pwm.h"

//duty 0->100
void motor_control( Motor_typeDef *motor , MOTOR_STATE state , uint8_t duty ){
	switch(state){
		case MOTOR_STOP: 
			HAL_GPIO_WritePin(motor->GPIO ,motor->GPIO_Pin , 0);
			pwm_set_duty(motor->htim ,motor->channel , 0);
			break;
		case MOTOR_CW: 
			HAL_GPIO_WritePin(motor->GPIO ,motor->GPIO_Pin , 0);
			pwm_set_duty(motor->htim , motor->channel , duty);
			break;
		case MOTOR_CCW: 
			HAL_GPIO_WritePin(motor->GPIO ,motor->GPIO_Pin , 1);
		  pwm_set_duty(motor->htim , motor->channel , 100-duty);
			break;
	}
}
void motor_init( Motor_typeDef *motor , GPIO_TypeDef  *_GPIO ,uint32_t _GPIO_Pin,TIM_HandleTypeDef *_htim,uint32_t _channel){
	motor->htim = _htim;
	motor->channel = _channel;
	motor->GPIO = _GPIO;
	motor->GPIO_Pin = _GPIO_Pin;
	HAL_TIM_PWM_Start(motor->htim , motor->channel);
}
