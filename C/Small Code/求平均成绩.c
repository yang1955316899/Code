#include <stdio.h>//ͷ�ļ� 
int main()
{
	int Score[5],sum,temp = 0;//��ʼ������ 
	for(; temp < 5; temp++)
	{
		scanf("%d",Score+temp);//��ֵ 
		sum += Score[temp];//��� 
	}
	printf("%.2f",1.0*sum/5);//����ɼ� 
	return 0;//��ϰ�� 
}
