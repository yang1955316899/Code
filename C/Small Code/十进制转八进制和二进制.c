#include <stdio.h>
int Change(int number,int temp);//声明定义函数 
int main()//主函数 
{
	int number;//存储变量 
	printf("请输入一个十进制数：");
	scanf("%d",&number);//输入 
	printf("这个数对应的二进制为：");
	Change(number,2); //调用函数 
	printf("\n这个数对应的八进制为：");//对上一行进行换行 
	Change(number,8);//调用函数 
	return 0;//保持好习惯 
} 
int Change(int number,int temp)//定义函数 number变量存储的输入的数字  temp存储的是转换的进制 
{
    if(number/temp)//跳出递归的条件，如果number/temp == 0的话，if就不不会进行进入下一次递归，转而将数据打印出来，并一层层的跳出循环 
        Change(number/temp,temp);//递归调用（离散数学老师教的） 
    printf("%d",number%temp);//输出 
}
