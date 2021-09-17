/* myio.h - 自己写的程序库 */
//==声明区==============================
#define	LED	P1			//	定义LED接至Port 1
void debouncer(void); 	//	声明防弹跳函数 
void delay10ms(int); 	//	声明10毫秒延迟函数 
void alter(int);	 	//	声明交互闪烁函数 
void left(int); 		//	声明单灯左移函数 
void right(int);	 	//	声明单灯右移函数 
void pili(int);	 		//	声明霹雳灯函数 
void flash(int);	 	//	声明闪烁函数 
//==自己写的子程序========================
/* 防弹跳函数函数,延迟约20ms */
void debouncer(void)	//	防弹跳函数开始 
{	delay10ms(2);		//	延迟约20ms 
}						//	防弹跳函数结束 
/* 延迟函数开始,延迟约x 10ms */
void delay10ms(int x)	//	延迟函数开始 
{	int i,j;			//	声明整数变量i,j
	for (i=0;i<x;i++)	//	计数x次,延迟约x 10ms 
		for (j=0;j<1200;j++);	//	计数1200次，延迟约10ms 
}					//	延迟函数结束 
/* 高低位元交互闪烁函数,执行x次 */
void alter(int x) 		//	高低位元交互闪烁函数开始
{	int i;				//	声明变量i
	LED=0x0f;			//	初始状态(高位元亮,低位元灭)
	for(i=0;i<2*x-1;i++)//	i变量for循环执行2x-1次  
	{	delay10ms(50);	//	延迟50*10m=0.5s
		LED=~LED;		//	LED反相输出 
	}					//	i变量for循环结束 
	delay10ms(50);		//	延迟50 10m=0.5s			
}						//	高低位元交互闪烁函数结束 
/* 全灯闪烁函数,执行x次 */
void flash(int x) 		//	全灯闪烁函数开始
{	int i;				//	声明变量i
	LED=0x00;			//	初始状态(全亮)
	for(i=0;i<2*x-1;i++)//	i变量for循环执行2x-1次 
	{	delay10ms(50);	//	延迟50 10m=0.5s
		LED=~LED;		//	P0反相输出
	}					//	i变量for循环结束 
	delay10ms(50);		//	延迟50 10m=0.5s	
}						//	全灯闪烁函数结束 
/* 单灯左移函数,执行x圈 */
void left(int x) 		//	单灯左移函数开始
{	int i, j;			//	声明变量i,j
	for(i=0;i<x;i++)	//	i循环,执行x圈 
	{	LED=0xfe;		//	初始状态=1111 1110
		for(j=0;j<7;j++)//	j循环,左移7次 
		{	delay10ms(25);	//	延迟25 10m=0.25s
			LED=(LED<<1)|0x01;	//	左移1位後,LSB设为1
		}				//	j循环结束  
		delay10ms(25);	//	延迟25 10m=0.25s
	}					//	i循环结束*/
}						//	单灯左移函数结束 
/* 单灯右移函数,执行x圈 */
void right(int x) 		//	单灯右移函数开始 
{	int i, j;			//	声明变量i,j
	for(i=0;i<x;i++)	//	i循环,执行x圈 
	{	LED=0X7f;		//	初始状态=0111 1111
		for(j=0;j<7;j++)//	j循环,右移7次 
		{	delay10ms(25);	//	延迟25 10m=0.25s
			LED=(LED>>1)|0x80;	//	左移1位後,MSB设为1
		}			//	j循环结束 
		delay10ms(25);	//	延迟25 10m=0.25s
	}				//	i循环结束 
}					//	单灯左移函数结束 
/* 霹雳灯函数,执行x圈 */
void pili(int x)	//	霹雳灯函数开始 
{	int i;			//	声明变量i
	for(i=0;i<x;i++)//	i循环,执行x圈 
	{	left(1);	//	单灯左移一圈 
		right(1);	//	单灯左移一圈 
	}				//	i循环结束 
}					//	霹雳灯函数结束 
