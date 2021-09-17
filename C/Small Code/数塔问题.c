#include <stdio.h>
int main()
{
	int n,j,i; 
	int a[100][100];	
	do{
		printf("请输入数塔的行数(1~100)：");
		scanf("%d",&n);	
	}while(n <= 1 || n > 100);
	for(j = 0;j < n;j++)
	{
		for(i = 0;i <= j;i++)
		{
			scanf("%d",&a[j][i]);
		}
	}
	for(i = n-2;i >= 0;i--)
	{
		for(j = 0;j <= n-2;j++)
		{
			a[i][j] += (a[i+1][j] < a[i+1][j+1])?(a[i+1][j]):(a[i+1][j+1]);
		}
	}  
	printf("最小路径的值：%d",a[0][0]);
}
