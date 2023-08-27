#ifndef CAR_H
#define CAR_H
#include "stm32f1xx.h"
typedef enum {
	CAR_STOP_STATE,
	CAR_FORWARD_STATE,
	CAR_BACKWARD_STATE,
	CAR_LEFT_STATE,
	CAR_RIGHT_STATE
}CAR_STATE;
void car_motor(CAR_STATE car_state , uint8_t speed);
void car_init(GPIO_TypeDef  *GPIO_left, GPIO_TypeDef  *GPIO_right ,uint32_t GPIO_Pin_left,uint32_t GPIO_Pin_right,TIM_HandleTypeDef *htim,uint32_t channel_left,uint32_t channel_right);
#endif