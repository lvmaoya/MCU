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
	//P2=0xFE; //ֱ�Ӳ����Ĵ���
	//P2_1=0;//��������λ
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
	//Demo2�����������ٰ�һ���� 


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

//Demo3������������ʾ��
//unsigned char LEDNum;//��51��Ƭ���Ĵ���һ�����ǰ�λ������ͨ��������ʾ�Ĵ���
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


//Demo4:����ledλ��
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