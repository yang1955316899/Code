#include <stdio.h>
int main()
{
	int a,b,c,number;scanf("%d",&number);
	for (a=1;a<=number-2;a++)
	  for (b=a;b<=number-2;b++)
	    for (c=b;c<=number-2;c++)
	    	if ((a+b>c)&&(b+c>a)&&(c+a>b)&&(a+b+c==number))
	    		printf("%d %d %d\n",a,b,c);
	return 0;
}
