#include <stdio.h>
int main()
{
	int rabbit,foot,temp;
	printf("������ŵ�������");
	scanf("%d",&foot);
	for(temp = 0;temp <= foot/2;temp++)
	{
		rabbit = (foot-2*temp)/4;
		if (temp*2 + rabbit*4 == foot) printf("����������%d,���ӵ�������%d\n",temp,rabbit);
	}
	return 0; 
}
