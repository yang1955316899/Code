#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*stdio.h——普通输入输出及基本语句的头文件 
conio.h——获取键盘返回值的头文件 
windows.h——控制cmd的清空、控制时间的头文件 
stdlib.h——随机数生成头文件 
time.h——配合随机数函数产生*/ 

/*全局变量定义*/
#define N 3
int list[N][N] = {0};
/*辅助函数定义区*/
/*随机数赋值*/
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
        if (rand() % 10 > 8)//十分之一的概率会产生4，十分之九的概率产生2
            list[x][y] = 4;
        else
            list[x][y] = 2;        
    }
}
/*界面刷新*/
void Print()
{
    for (int x = 0; x < N; x++)
    {
        printf("————————————————————————————\n");
        for (int y = 0; y < N; y++)
			printf("|%6d",list[x][y]);
        printf("|\n");
    }
    printf("————————————————————————————");
}
/*检测函数*/
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
/*合并相加*/
void Add(int *number,int *occupy)//对于逻辑上来说每一行/每一列在移动上来说，逻辑是一样的，都是考虑是否相同再相加 
{
    for(int temp = 0;temp < N;temp++)
        if(number[temp] == number[temp + 1] && number[temp] != 0)
        {
            number[temp] *= 2;
		    number[temp + 1] = 0;
			*occupy -= 1;
        }
	int new_occupy = 0; //新的占用位数存储，用于控制number[]列表中的索引值 
	for(int temp = 0;temp < N;temp++)//相加完成以后再合并，符合游戏的逻辑 
        if(number[temp]) 
        {
            number[new_occupy] =number[temp];
			if(new_occupy != temp) number[temp] = 0;
			new_occupy += 1;
        }
}
/*欢迎界面*/
void Welcome()
{
    printf("\
                     	|\n\
                 __\\--__|_\n\
  II=======OOOOO[/ ★02 ___|\n\
           _____\\______|/-----.\n\
         /____________________|\n\
          \\◎◎◎◎◎◎◎◎⊙/\n\
            ~~~~~~~~~~~~~~~~\n");
}
/*行列改变*/
void Lie_change(int mode)//模式0：上移；模式1：下移 
{
    for(int lie_number = 0;lie_number < N;lie_number++)
    {
        int number[N] = {0},list_temp = 0;//list[]存放数据，list_temp存放list[]数据已使用情况 
        for(int temp = 0;temp < N;temp++)//按顺序把元素收集在一起，并存在叫做list[]的列表中
            if(list[temp][lie_number] != 0)
            {
                number[list_temp] = list[temp][lie_number];
                list[temp][lie_number] = 0;//按模式对原序列进行整顿 
                list_temp++;
            }
        Add(number,&list_temp);
        if(mode)
            for(int temp = 1;temp <= list_temp;temp++)
                list[N - temp][lie_number] = number[list_temp - temp];//下移 
        else
            for(;list_temp >= 0;list_temp--)
                list[list_temp][lie_number] = number[list_temp];//上移
    }
} 
void Hang_change(int mode)//模式0：左移；模式1：右移
{
    for (int hang_number = 0; hang_number < N; hang_number++)
    {
        int number[N] = {0},list_temp = 0;//list[]存放数据，list_temp存放list[]数据已使用情况 
        for(int temp = 0;temp < N;temp++)//按顺序把元素收集在一起，并存在叫做list[]的列表中
            if(list[hang_number][temp] != 0)
            {
                number[list_temp] = list[hang_number][temp];
                list[hang_number][temp] = 0;//按模式对原序列进行整顿 
                list_temp++;
            }
        Add(number,&list_temp);
        if(mode)
            for(int temp = 1;temp <= list_temp;temp++)
                list[hang_number][N - temp] = number[list_temp - temp];//右移 
        else
            for(;list_temp >= 0;list_temp--)
                list[hang_number][list_temp] = number[list_temp];//左移 
    }
}

/*主游戏逻辑*/
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
                printf("输入错误！");
                Sleep(500);
                break;
        }
    } 
}
/*按键跳转函数*/
void Direction()
{
    system("cls");
    Welcome();
    printf("欢迎来到2048！在英文状态下按W进入游戏，按S退出游戏，按A查看制作人员，按D查看彩蛋:");
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
            printf("\t\t\t\t\t计算机科学与技术1904班,杨建文\n");
            printf("\t\t\t\t\t按任意键返回主菜单！");
            if (_getch()) break;
        }
        default:
        {
            printf("输入有误，请重新输入！");
            Sleep(1000);
            Direction();
            break;
        }    
    }
}
/*主函数*/
int main()
{
    Direction();
    system("cls");
    printf("游戏结束！");
}
