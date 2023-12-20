#include "remote.h"
#include "tim.h"
// #include "delay.h"
// #include "usart.h"
//////////////////////////////////////////////////////////////////////////////////
// 本程序只供学习使用，未经作者许可，不得用于其它任何用途
// ALIENTEK miniSTM32开发板
// 红外遥控解码驱动 代码
// 正点原子@ALIENTEK
// 技术论坛:www.openedv.com
// 修改日期:2012/9/12
// 版本：V1.0
// 版权所有，盗版必究。
// Copyright(C) 广州市星翼电子科技有限公司 2009-2019
// All rights reserved
//////////////////////////////////////////////////////////////////////////////////

// 红外遥控初始化
// 设置IO以及定时器4的输入捕获
void Remote_Init(void)
{

  // GPIO_InitTypeDef GPIO_Initure;
  // NVIC_InitTypeDef NVIC_InitStructure;
  // TIM_HandleTypeDef  TIM5_Handler;
  // TIM_IC_InitTypeDef TIM5_CH2Config;

  // RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); //使能PORTB时钟
  // RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);	//TIM5 时钟使能

  // __HAL_RCC_GPIOA_CLK_ENABLE(); // 使能GPIOB时钟
  // __HAL_RCC_TIM5_CLK_ENABLE();  // 使能TIM5时钟

  // GPIO_Initure.Pin = GPIO_PIN_1;       // PA1 输入
  // GPIO_Initure.Mode = GPIO_MODE_INPUT; // 上拉输入
  // GPIO_Initure.Pull = GPIO_PULLUP;     // 下拉
  // GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;
  // HAL_GPIO_Init(GPIOA, &GPIO_Initure);
  // HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); // 初始化GPIOA1

  // TIM_TimeBaseStructure.TIM_Period = 10000; //设定计数器自动重装值 最大10ms溢出
  // TIM_TimeBaseStructure.TIM_Prescaler =(72-1); 	//预分频器,1M的计数频率,1us加1.
  // TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
  // TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式

  // TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx

  // TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;  // 选择输入端 IC2映射到TI5上
  // TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//上升沿捕获
  // TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
  // TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //配置输入分频,不分频
  // TIM_ICInitStructure.TIM_ICFilter = 0x03;//IC4F=0011 配置输入滤波器 8个定时器时钟周期滤波
  // TIM_ICInit(TIM5, &TIM_ICInitStructure);//初始化定时器输入捕获通道

  // TIM_Cmd(TIM5,ENABLE ); 	//使能定时器5

  // NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;  //TIM5中断
  // NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //先占优先级0级
  // NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //从优先级3级
  // NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
  // NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

  // TIM_ITConfig( TIM5,TIM_IT_Update|TIM_IT_CC2,ENABLE);//允许更新中断 ,允许CC2IE捕获中断

  HAL_TIM_Base_Start_IT(&htim5);
  HAL_TIM_IC_Start_IT(&htim5, TIM_CHANNEL_2);
  __HAL_TIM_ENABLE_IT(&htim5, TIM_IT_UPDATE | TIM_IT_CC2);
}

// 遥控器接收状态
//[7]:收到了引导码标志
//[6]:得到了一个按键的所有信息
//[5]:保留
//[4]:标记上升沿是否已经被捕获
//[3:0]:溢出计时器
u8 RmtSta = 0;
u16 Dval;       // 下降沿时计数器的值
u32 RmtRec = 0; // 红外接收到的数据
u8 RmtCnt = 0;  // 按键按下的次数
// 定时器5中断服务程序
void RemoteIRQHandler(void)
{
  if (RmtSta & 0x80) // 上次有数据被接收到了
  {
    RmtSta &= ~0X10; // 取消上升沿已经被捕获标记
    if ((RmtSta & 0X0F) == 0X00)
      RmtSta |= 1 << 6; // 标记已经完成一次按键的键值信息采集
    if ((RmtSta & 0X0F) < 14)
      RmtSta++;
    else
    {
      RmtSta &= ~(1 << 7); // 清空引导标识
      RmtSta &= 0XF0;      // 清空计数器
    }
  }
}
// 定时器5输入捕获中断服务程序
void RemoteICHandler(void)
{
  if (RDATA) // 上升沿捕获
  {

    // TIM_OC2PolarityConfig(TIM5, TIM_ICPOLARITY_FALLING); // CC1P=1 设置为下降沿捕获
    // TIM_SetCounter(TIM5, 0);                             // 清空定时器值

    // TIM_RESET_CAPTUREPOLARITY(&htim5, TIM_CHANNEL_2);
    __HAL_TIM_SET_CAPTUREPOLARITY(&htim5, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_FALLING);
    __HAL_TIM_SET_COUNTER(&htim5, 0);
    RmtSta |= 0X10; // 标记上升沿已经被捕获
  }
  else // 下降沿捕获
  {
    // Dval = TIM_GetCapture2(TIM5);                       // 读取CCR1也可以清CC1IF标志位
    // TIM_OC2PolarityConfig(TIM5, TIM_ICPOLARITY_RISING); // CC4P=0	设置为上升沿捕获

    Dval = HAL_TIM_ReadCapturedValue(&htim5, TIM_CHANNEL_2);
    __HAL_TIM_SET_CAPTUREPOLARITY(&htim5, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_RISING);

    if (RmtSta & 0X10) // 完成一次高电平捕获
    {
      if (RmtSta & 0X80) // 接收到了引导码
      {
        if (Dval > 300 && Dval < 800) // 560为标准值,560us
        {
          RmtRec <<= 1; // 左移一位.
          RmtRec |= 0;  // 接收到0
        }
        else if (Dval > 1400 && Dval < 1800) // 1680为标准值,1680us
        {
          RmtRec <<= 1; // 左移一位.
          RmtRec |= 1;  // 接收到1
        }
        else if (Dval > 2200 && Dval < 2600) // 得到按键键值增加的信息 2500为标准值2.5ms
        {
          RmtCnt++;       // 按键次数增加1次
          RmtSta &= 0XF0; // 清空计时器
        }
      }
      else if (Dval > 4200 && Dval < 4700) // 4500为标准值4.5ms
      {
        RmtSta |= 1 << 7; // 标记成功接收到了引导码
        RmtCnt = 0;       // 清除按键次数计数器
      }
    }
    RmtSta &= ~(1 << 4);
  }

  //  TIM_ClearFlag(TIM5,TIM_IT_UPDATE|TIM_IT_CC2);
  __HAL_TIM_CLEAR_FLAG(&htim5, TIM_IT_UPDATE | TIM_IT_CC2);
}

// 处理红外键盘
// 返回值:
//	 0,没有任何按键按下
// 其他,按下的按键键值.
u8 Remote_Scan(void)
{
  u8 sta = 0;
  u8 t1, t2;
  if (RmtSta & (1 << 6)) // 得到一个按键的所有信息了
  {
    t1 = RmtRec >> 24;                      // 得到地址码
    t2 = (RmtRec >> 16) & 0xff;             // 得到地址反码
    if ((t1 == (u8)~t2) && t1 == REMOTE_ID) // 检验遥控识别码(ID)及地址
    {
      t1 = RmtRec >> 8;
      t2 = RmtRec;
      if (t1 == (u8)~t2)
        sta = t1; // 键值正确
    }
    if ((sta == 0) || ((RmtSta & 0X80) == 0)) // 按键数据错误/遥控已经没有按下了
    {
      RmtSta &= ~(1 << 6); // 清除接收到有效按键标识
      RmtCnt = 0;          // 清除按键次数计数器
    }
  }
  return sta;
}
