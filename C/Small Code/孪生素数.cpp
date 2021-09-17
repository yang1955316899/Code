#include <stdio.h>
int main()
{
	int n;scanf("%d",&n);int prime[10000] = {0};prime[0,1] = 1;
	for(int temp = 1;temp <= n;temp++)
	{
		if(!prime[temp])
		{
			int x = temp*2;
			for(;x < n;x += temp)
			{
				prime[x] = 1;
			}
		}
	}
	for(int temp = 2;temp <= n;temp++)
	{
		if(prime[temp] == 0 && prime[temp - 1] == 0) printf("%d %d\n",temp,temp - 1);
		if(prime[temp] == 0 && prime[temp - 2] == 0) printf("%d %d\n",temp,temp - 2);
	}
	return 0;
}

