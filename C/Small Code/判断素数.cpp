#include <stdio.h>
int main()
{
	int n,temp = 0;
	scanf("%d",&n);
	if (n != 1)
	{
		for (int i = 2;i < n;i++)
		{
			if (n % i == 0)
			{
				temp = 1;
				break;
			}
		}
	}
	else
	{
		temp = 1;
	} 
	if (temp == 1) printf("��������"); else printf("������"); 
	return 0;
} 
