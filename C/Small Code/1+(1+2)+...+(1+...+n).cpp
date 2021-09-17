#include <stdio.h>
int main()
{
	int n,sum = 0,sumtemp = 0,temp = 1;
	scanf("%d",&n);
	for (;temp <= n;temp++)
	{
		sum += temp;
		sumtemp += sum;
	}
	printf("%d",sumtemp);
	return 0;
}
