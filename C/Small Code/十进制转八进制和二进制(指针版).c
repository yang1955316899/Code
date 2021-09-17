#include "stdio.h"
#include "math.h"
void fvdb(int a,int *b)
{
	*b=0;
	while(a!=0)
	{
		static int i = 0;
		*b=*b+a%2*pow(10,i);
		a=a/2;
		i++;
	}	
}
void fvdo(int a,int *b)
{
	*b=0;
	while(a!=0)
	{
		static int i = 0;
		*b=*b+a%8*pow(10,i);
		a=a/8;
		i++;
	}	
}
void main()
{
	int a,b,o;
	printf("entre a:");
	scanf("%d",&a);
	fvdb(a,&b);
	printf("%d->%d\n",a,b);
	fvdo(a,&b);
	printf("%d->%d\n",a,b);
}

