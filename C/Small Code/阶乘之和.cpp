#include <stdio.h>
int main(){
	int n,temp=1,sum=0;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		temp = temp * i;
		sum += temp;
	}
	printf("%d",sum);
	return 0;
} 
