#include <stdio.h> 
int main()
{
	float a,b;
	printf("请输入两位数，并用空格隔开：");
	scanf("%f %f",&a,&b);
	printf("%g + %g = %g\n",a,b,a+b);
	printf("%g - %g = %g\n",a,b,a-b);
	printf("%g * %g = %g\n",a,b,a*b);
	printf("%g ÷ %g = %g\n",a,b,a/b);
	return 0;	//养成好习惯 
} 
