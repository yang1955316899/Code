#include <stdio.h>
int jia(int number);
int a,sum,number;
int main()
{
	a = jia(100);
	printf("%d",a);
}
int jia(int number)
{

	sum += number;
    if(number == 0)
    	return(sum);
    jia(number-1);
}
