/*
 * Title: 74HC595 Serial-to-Parallel Latch
 * Author: Osama Mazhar
 * Date: 22nd May 2011
 * Email: osamazhar@yahoo.com
 */

#include<reg51.h>
#include<math.h>

sbit SH = P1^0;
sbit ST = P1^1;
sbit DS = P1^2;
sbit LSBACC = ACC^0;

void SerialIn(unsigned char);
void LatchData(unsigned char LatchOutput);
void MSDelay(unsigned int value); 

void main()
	{
	char x;
	SH = 0;
	ST = 0;
	DS = 0;
	while(1)
	{
	for(x=0; x<8; x++)
		{
		 LatchData(pow(2,x));
		 MSDelay(10);
		}
	for(x=6; x>=0; x--)
		{
		 LatchData(pow(2,x));
		 MSDelay(10);
		}
	}
   }
 void SerialIn(unsigned char x)
	{
	 DS = x;
	 SH = 1;
	 DS = 0;
 	 SH = 0;
	}

void LatchData(unsigned char LatchOutput)
	{
	 unsigned char x;
	 for(x=0; x<8; x++)
	 	{
	 	 ACC = LatchOutput;
	 	 ACC = ACC >> x;
	 	 SerialIn(LSBACC);
		}
	 ST = 1;
	 ST = 0;
	}

void MSDelay(unsigned int value)
	{
		unsigned int x,y;
		for(x=0; x<value; x++)
			for(y=0; y<1275; y++);
	}