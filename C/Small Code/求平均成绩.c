#include <stdio.h>//头文件 
int main()
{
	int Score[5],sum,temp = 0;//初始化变量 
	for(; temp < 5; temp++)
	{
		scanf("%d",Score+temp);//赋值 
		sum += Score[temp];//求和 
	}
	printf("%.2f",1.0*sum/5);//输出成绩 
	return 0;//好习惯 
}
