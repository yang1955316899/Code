#include <stdio.h>
int Change(int number,int temp);//�������庯�� 
int main()//������ 
{
	int number;//�洢���� 
	printf("������һ��ʮ��������");
	scanf("%d",&number);//���� 
	printf("�������Ӧ�Ķ�����Ϊ��");
	Change(number,2); //���ú��� 
	printf("\n�������Ӧ�İ˽���Ϊ��");//����һ�н��л��� 
	Change(number,8);//���ú��� 
	return 0;//���ֺ�ϰ�� 
} 
int Change(int number,int temp)//���庯�� number�����洢�����������  temp�洢����ת���Ľ��� 
{
    if(number/temp)//�����ݹ�����������number/temp == 0�Ļ���if�Ͳ�������н�����һ�εݹ飬ת�������ݴ�ӡ��������һ��������ѭ�� 
        Change(number/temp,temp);//�ݹ���ã���ɢ��ѧ��ʦ�̵ģ� 
    printf("%d",number%temp);//��� 
}
