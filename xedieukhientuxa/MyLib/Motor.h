#ifndef MOTOR_H
#define MOTOR_H
#include "stm32f1xx_hal.h"
//trang thai cua motor
typedef enum{
		MOTOR_STOP,
		MOTOR_CW,    // cung chieu kim dong ho
		MOTOR_CCW    // nguoc chieu kim dong ho
}MOTOR_STATE;

typedef struct{
	GPIO_TypeDef  *GPIO;
	uint32_t GPIO_Pin;
	TIM_HandleTypeDef *htim;
	uint32_t channel ;
	uint8_t duty;
	MOTOR_STATE state;
}Motor_typeDef;

void motor_control( Motor_typeDef *motor , MOTOR_STATE state , uint8_t duty );

void motor_init( Motor_typeDef *motor , GPIO_TypeDef  *GPIO ,uint32_t GPIO_Pin,TIM_HandleTypeDef *htim,uint32_t channel);

#endif
