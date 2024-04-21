#include <REGX52.H>
void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;

	while(xms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	
		xms--;
	}
}
void main()
{
	//P2=0xFE; //直接操作寄存器
	//P2_1=0;//操作具体位
	//Demo1
//	while(1)
//	{
//		if(P3_1==0)
//		{
//			P2_1=0;
//		}
//		else
//		{
//			P2_1=1;
//		}
//	}
	//Demo2：按下亮，再按一次灭 


//	while(1)
//	{
//		if(P3_1==0)
//		{
//			Delay(20);
//			while(P3_1==0);
//			Delay(20);
//			
//			P2_0=~P2_0;
//		}
//	}

//Demo3：按二进制显示；
//unsigned char LEDNum;//和51单片机寄存器一样都是八位，所以通常用来表示寄存器
//while(1)
//	{
//		if(P3_1==0)
//		{
//			Delay(20);
//			while(P3_1==0);
//			Delay(20);
//			
//			LEDNum++;
//			P2=~LEDNum;
//		}
//	}


//Demo4:控制led位移
unsigned char LEDNum;
P2=~(0x01);
while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			
			LEDNum++;
			if(LEDNum>=8)
			{
				LEDNum=0;
			}
			P2=~(0x01<<LEDNum);
		}
		if(P3_0==0)
		{
			Delay(20);
			while(P3_0==0);
			Delay(20);
			
		
			if(LEDNum==0)
				LEDNum=7;
			else
				LEDNum--;
			P2=~(0x01<<LEDNum);
		}
	}
}