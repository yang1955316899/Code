#include <stdio.h>
int main()
{
	int long times;scanf("%d",&times);
	for(int long number=1;number <= times;number++)
	{
		int long sum=0;
		for(int long temp=1;temp<number;temp++)
		   if(number%temp==0) sum+=temp;
		if(sum==number) printf("%d\n",number);
	}
	return 0;
}
