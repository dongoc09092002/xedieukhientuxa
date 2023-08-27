#include "Car.h"
#include "Motor.h"
Motor_typeDef motor_right;
Motor_typeDef motor_left;
void car_motor(CAR_STATE car_state , uint8_t speed ){
	switch(car_state){
		case CAR_STOP_STATE:
			motor_control(&motor_left , MOTOR_STOP , 0);
			motor_control(&motor_right , MOTOR_STOP , 0);
			break;
		case CAR_FORWARD_STATE:
			motor_control(&motor_left , MOTOR_CW , speed);
			motor_control(&motor_right , MOTOR_CW , speed);
			break;
		case CAR_BACKWARD_STATE:
			motor_control(&motor_left , MOTOR_CCW , speed);
			motor_control(&motor_right , MOTOR_CCW , speed);
			break;
		case CAR_LEFT_STATE:
			motor_control(&motor_left , MOTOR_STOP , 0);
			motor_control(&motor_right , MOTOR_CW , speed);
			break;
		case CAR_RIGHT_STATE:
			motor_control(&motor_left , MOTOR_CW , speed);
			motor_control(&motor_right , MOTOR_STOP , 0);
			break;
		default :
			break;
	}
}
void car_init(GPIO_TypeDef  *GPIO_left, GPIO_TypeDef  *GPIO_right ,uint32_t GPIO_Pin_left,uint32_t GPIO_Pin_right,TIM_HandleTypeDef *htim,uint32_t channel_left,uint32_t channel_right){
	motor_init(&motor_right , GPIO_right , GPIO_Pin_right , htim , channel_right) ;
	motor_init(&motor_left , GPIO_left , GPIO_Pin_left , htim , channel_left) ;
}

