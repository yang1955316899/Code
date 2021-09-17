#include <stdio.h>
#include <math.h>
int main()
{
	int number,g,s,b,times;
	scanf("%d",&times);
	for(number = 100;number < 1000;number++)
	{
		g = number%10;
		s = number/10%10;
		b = number/100%10; 
		if (number == pow(g,3)+pow(s,3)+pow(b,3)) printf("%d ",number);
	}
}
