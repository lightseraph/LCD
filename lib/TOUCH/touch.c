#include "touch.h"
#include "lcd.h"
#include "tim.h"
#include "stdlib.h"
#include "math.h"
//#include "24cxx.h"
//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作��许可，不得用于其它任何用��1�7
// ALIENTEK STM32F407弢�发板
//触摸屏驱动（支持ADS7843/7846/UH7843/7846/XPT2046/TSC2046/OTT2001A等） 代码
//正点原子@ALIENTEK
//抢�术论坄1�7:www.openedv.com
//创建日期:2014/5/7
//版本：V1.2
//版权扢�有，盗版必究〄1�7
// Copyright(C) 广州市星翼电子科抢�有限公司 2014-2024
// All rights reserved
//********************************************************************************
//修改说明
// V1.1 20140721
//修正MDK圄1�7-O2优化旄1�7,触摸屏数据无法读取的bug.在TP_Write_Byte函数添加丢�个延旄1�7,解决问题.
// V1.2 20141130
//电容触摸屏增加FT5206的支挄1�7
//////////////////////////////////////////////////////////////////////////////////

_m_tp_dev tp_dev =
	{
		TP_Init,
		TP_Scan,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
};
//默认为touchtype=0的数捄1�7.
u8 CMD_RDX = 0XD0;
u8 CMD_RDY = 0X90;

//////////////////////////////////////////////////////////////////////////////////
//触摸按键扫描
// tp:0,屏幕坐标;1,物理坐标(校准等特殊场合用)
//返回倄1�7:当前触屏状��1�7.
// 0,触屏无触摄1�7;1,触屏有触摄1�7
u8 TP_Scan(u8 tp)
{

	return tp_dev.sta & TP_PRES_DOWN; //返回当前的触屏状怄1�7
}

//触摸屏初始化
//返回倄1�7:0,没有进行校准
//       1,进行过校凄1�7
u8 TP_Init(void)
{
	// GPIO_InitTypeDef GPIO_Initure;

	if (lcddev.id == 0X5510) //电容触摸屄1�7
	{
		if (GT9147_Init() == 0) //是GT9147
		{
			tp_dev.scan = GT9147_Scan; //扫描函数指向GT9147触摸屏扫揄1�7
		}
		else
		{
			// OTT2001A_Init();
			// tp_dev.scan = OTT2001A_Scan; //扫描函数指向OTT2001A触摸屏扫揄1�7
		}
		tp_dev.touchtype |= 0X80;			   //电容屄1�7
		tp_dev.touchtype |= lcddev.dir & 0X01; //横屏还是竖屏
		return 0;
	}
	else if (lcddev.id == 0X1963)
	{
		// FT5206_Init();
		// tp_dev.scan = FT5206_Scan;			   //扫描函数指向GT9147触摸屏扫揄1�7
		tp_dev.touchtype |= 0X80;			   //电容屄1�7
		tp_dev.touchtype |= lcddev.dir & 0X01; //横屏还是竖屏
		return 0;
	}
	else
	{
		/* RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); //使能GPIOB时钟
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE); //使能GPIOC时钟
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE); //使能GPIOF时钟

		// GPIOB1,2初始化设罄1�7
		GPIO_Initure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2; // PB1/PB2 设置为上拉输兄1�7
		GPIO_Initure.GPIO_Mode = GPIO_Mode_IN;			 //输入
		GPIO_Initure.GPIO_PuPd = GPIO_PuPd_UP;			 //上拉
		GPIO_Initure.GPIO_Speed = GPIO_High_Speed;		 //高��1�7
		GPIO_Init(GPIOB, &GPIO_Initure);				 //初始匄1�7

		// PB0
		GPIO_Initure.GPIO_Pin = GPIO_Pin_0;		 // PB0设置为推挽输凄1�7
		GPIO_Initure.GPIO_Mode = GPIO_Mode_OUT;	 //输出
		GPIO_Initure.GPIO_OType = GPIO_OType_PP; //推挽
		GPIO_Init(GPIOB, &GPIO_Initure);		 //初始匄1�7

		// PC13
		GPIO_Initure.GPIO_Pin = GPIO_Pin_13; // PC13设置为推挽输凄1�7
		GPIO_Init(GPIOC, &GPIO_Initure);	 //初始匄1�7

		// PF11
		GPIO_Initure.GPIO_Pin = GPIO_Pin_11; // PF11设置推挽输出
		GPIO_Init(GPIOF, &GPIO_Initure);	 //初始匄1�7 */

		/* TP_Read_XY(&tp_dev.x[0], &tp_dev.y[0]); //第一次读取初始化
		AT24CXX_Init();							//初始匄1�724CXX

		LCD_Clear(WHITE); //清屏
		TP_Adjust();	  //屏幕校准
		TP_Save_Adjdata();
		TP_Get_Adjdata(); */
	}
	return 1;
}
