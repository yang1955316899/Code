#include <stdio.h>
int main()
{
	int rabbit,foot,temp;
	printf("请输入脚的数量：");
	scanf("%d",&foot);
	for(temp = 0;temp <= foot/2;temp++)
	{
		rabbit = (foot-2*temp)/4;
		if (temp*2 + rabbit*4 == foot) printf("鸡的数量：%d,兔子的数量：%d\n",temp,rabbit);
	}
	return 0; 
}
