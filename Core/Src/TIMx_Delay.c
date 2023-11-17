//源文件
#include "TIMx_Delay.h"
 
void delay_us(uint16_t us)
{
    __HAL_TIM_SET_COUNTER(DEL_TIM_Handle, 0);
    __HAL_TIM_ENABLE(DEL_TIM_Handle);
    while(__HAL_TIM_GET_COUNTER(DEL_TIM_Handle) < us);
    __HAL_TIM_DISABLE(DEL_TIM_Handle);
}