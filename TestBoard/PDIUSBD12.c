/******************************************************************
   本程序只供学习使用，未经作者许可，不得用于其它任何用途
        欢迎访问我的USB专区：http://group.ednchina.com/93/
        欢迎访问我的blog：   http://www.ednchina.com/blog/computer00
                             http://computer00.21ic.org
        感谢PCB赞助商——电子园： http://bbs.cepark.com/
PDIUSBD12.C  file
作者：电脑圈圈
建立日期: 2008.06.27
修改日期: 2008.06.27
版本：V1.1
版权所有，盗版必究。
Copyright(C) 电脑圈圈 2008-2018
All rights reserved
*******************************************************************/
#include <AT89x52.H>
#include "MyType.h"
#include "PDIUSBD12.H"
/********************************************************************
函数功能：D12写命令。
入口参数：Command：一字节命令。
返    回：无。
备    注：无。
********************************************************************/
void D12WriteCommand(uint8 Command)
{
    D12SetCommandAddr();  //设置为命令地址
    D12ClrWr(); //WR置低
    D12SetPortOut(); //将数据口设置为输出状态（注意这里为空宏，移植时可能有用）
    D12SetData(Command);  //输出命令到数据口上
    D12SetWr(); //WR置高
    D12SetPortIn(); //将数据口设置为输入状态，以备后面输入使用
}
////////////////////////End of function//////////////////////////////
/********************************************************************
函数功能：读一字节D12数据。
入口参数：无。
返    回：读回的一字节。
备    注：无。
********************************************************************/
uint8 D12ReadByte(void)
{
    uint8 temp;
    D12SetDataAddr(); //设置为数据地址
    D12ClrRd(); //RD置低
    temp=D12GetData(); //读回数据
    D12SetRd(); //RD置高
    return temp; //返回读到数据
}
////////////////////////End of function//////////////////////////////
/********************************************************************
函数功能：读D12的ID。
入口参数：无。
返    回：D12的ID。
备    注：无。
********************************************************************/
uint16 D12ReadID(void)
{
    uint16 id;
    D12WriteCommand(Read_ID); //写读ID命令
    id=D12ReadByte(); //读回ID号低字节
    id|=((uint16)D12ReadByte())<<8; //读回ID号高字节
    return id;
}
////////////////////////End of function//////////////////////////////
