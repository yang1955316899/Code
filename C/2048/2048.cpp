#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*stdio.h������ͨ�����������������ͷ�ļ� 
conio.h������ȡ���̷���ֵ��ͷ�ļ� 
windows.h��������cmd����ա�����ʱ���ͷ�ļ� 
stdlib.h�������������ͷ�ļ� 
time.h��������������������*/ 

/*ȫ�ֱ�������*/
#define N 3
int list[N][N] = {0};
/*��������������*/
/*�������ֵ*/
void Zero_To_Rand(int flag)
{
    if (flag)
    {
        srand((unsigned)time(NULL));
        int x, y;
        do
        {
            x = rand() % N;
            y = rand() % N;
        }while (list[x][y] != 0);
        if (rand() % 10 > 8)//ʮ��֮һ�ĸ��ʻ����4��ʮ��֮�ŵĸ��ʲ���2
            list[x][y] = 4;
        else
            list[x][y] = 2;        
    }
}
/*����ˢ��*/
void Print()
{
    for (int x = 0; x < N; x++)
    {
        printf("��������������������������������������������������������\n");
        for (int y = 0; y < N; y++)
			printf("|%6d",list[x][y]);
        printf("|\n");
    }
    printf("��������������������������������������������������������");
}
/*��⺯��*/
int Game_Over()
{
	for (int x = 0; x < N; x++) 
		for (int y = 0; y < N - 1; y++) 
        {
			if (list[x][y] == list[x][y + 1]) 
				return 1;
			if (list[y][x] == list[y + 1][x]) 
				return 1;
		}
    return 0;
}
/*�ϲ����*/
void Add(int *number,int *occupy)//�����߼�����˵ÿһ��/ÿһ�����ƶ�����˵���߼���һ���ģ����ǿ����Ƿ���ͬ����� 
{
    for(int temp = 0;temp < N;temp++)
        if(number[temp] == number[temp + 1] && number[temp] != 0)
        {
            number[temp] *= 2;
		    number[temp + 1] = 0;
			*occupy -= 1;
        }
	int new_occupy = 0; //�µ�ռ��λ���洢�����ڿ���number[]�б��е�����ֵ 
	for(int temp = 0;temp < N;temp++)//�������Ժ��ٺϲ���������Ϸ���߼� 
        if(number[temp]) 
        {
            number[new_occupy] =number[temp];
			if(new_occupy != temp) number[temp] = 0;
			new_occupy += 1;
        }
}
/*��ӭ����*/
void Welcome()
{
    printf("\
                     	|\n\
                 __\\--__|_\n\
  II=======OOOOO[/ ��02 ___|\n\
           _____\\______|/-----.\n\
         /____________________|\n\
          \\����������/\n\
            ~~~~~~~~~~~~~~~~\n");
}
/*���иı�*/
void Lie_change(int mode)//ģʽ0�����ƣ�ģʽ1������ 
{
    for(int lie_number = 0;lie_number < N;lie_number++)
    {
        int number[N] = {0},list_temp = 0;//list[]������ݣ�list_temp���list[]������ʹ����� 
        for(int temp = 0;temp < N;temp++)//��˳���Ԫ���ռ���һ�𣬲����ڽ���list[]���б���
            if(list[temp][lie_number] != 0)
            {
                number[list_temp] = list[temp][lie_number];
                list[temp][lie_number] = 0;//��ģʽ��ԭ���н������� 
                list_temp++;
            }
        Add(number,&list_temp);
        if(mode)
            for(int temp = 1;temp <= list_temp;temp++)
                list[N - temp][lie_number] = number[list_temp - temp];//���� 
        else
            for(;list_temp >= 0;list_temp--)
                list[list_temp][lie_number] = number[list_temp];//����
    }
} 
void Hang_change(int mode)//ģʽ0�����ƣ�ģʽ1������
{
    for (int hang_number = 0; hang_number < N; hang_number++)
    {
        int number[N] = {0},list_temp = 0;//list[]������ݣ�list_temp���list[]������ʹ����� 
        for(int temp = 0;temp < N;temp++)//��˳���Ԫ���ռ���һ�𣬲����ڽ���list[]���б���
            if(list[hang_number][temp] != 0)
            {
                number[list_temp] = list[hang_number][temp];
                list[hang_number][temp] = 0;//��ģʽ��ԭ���н������� 
                list_temp++;
            }
        Add(number,&list_temp);
        if(mode)
            for(int temp = 1;temp <= list_temp;temp++)
                list[hang_number][N - temp] = number[list_temp - temp];//���� 
        else
            for(;list_temp >= 0;list_temp--)
                list[hang_number][list_temp] = number[list_temp];//���� 
    }
}

/*����Ϸ�߼�*/
void Start_Game()
{
    system("cls");
    int flag = 0;
    Zero_To_Rand(1);
    Zero_To_Rand(1);
    while (Game_Over())
    {
        int list_copy[N][N];
        Zero_To_Rand(flag);
        flag = 0;
        for (int x = 0;x < N;x++) for (int y = 0; y < N; y++) list_copy[x][y] = list[x][y];
        system("cls");
        Print();
        switch (_getch())
        {
            case 119:
            {
                Lie_change(0);
                for (int x = 0; x < N; x++) for (int y = 0; y < N; y++) if (list[x][y] != list_copy[x][y]) flag = 1;
                break;
            }    
            case 115:
            {
                Lie_change(1);
                for (int x = 0; x < N; x++) for (int y = 0; y < N; y++) if (list[x][y] != list_copy[x][y]) flag = 1;
                break;
            } 
            case 97:
            {
                Hang_change(0);
                for (int x = 0; x < N; x++) for (int y = 0; y < N; y++) if (list[x][y] != list_copy[x][y]) flag = 1;
                break;
            }
            case 100:
            {
                Hang_change(1);
                for (int x = 0; x < N; x++) for (int y = 0; y < N; y++) if (list[x][y] != list_copy[x][y]) flag = 1;
                break;
            }
            default:
                printf("�������");
                Sleep(500);
                break;
        }
    } 
}
/*������ת����*/
void Direction()
{
    system("cls");
    Welcome();
    printf("��ӭ����2048����Ӣ��״̬�°�W������Ϸ����S�˳���Ϸ����A�鿴������Ա����D�鿴�ʵ�:");
    switch (_getch())
    {
        case 119:
        {
            Start_Game();
            break;
        }
        case 115:
            exit(1);
        case 97:
        {
            system("cls");
            printf("\t\t\t\t\t�������ѧ�뼼��1904��,���\n");
            printf("\t\t\t\t\t��������������˵���");
            if (_getch()) break;
        }
        default:
        {
            printf("�����������������룡");
            Sleep(1000);
            Direction();
            break;
        }    
    }
}
/*������*/
int main()
{
    Direction();
    system("cls");
    printf("��Ϸ������");
}
