#include <stdio.h>
#include <windows.h>
#include <conio.h>
struct Data
{
    char Name[9];
    int Score;
} Student[101];
int Use_number = 0;
int Menu()
{
    system("cls");
    printf("\t\t\t\t|-----------------------MENU--------------------|\n");
    printf("\t\t\t\t|\t 0. 退出系统\t\t\t\t|\n");
    printf("\t\t\t\t|\t 1. 添加成绩\t\t\t\t|\n");
    printf("\t\t\t\t|\t 2. 查找成绩\t\t\t\t|\n");
    printf("\t\t\t\t|-----------------------------------------------|\n\n");
    printf("\t\t\t\t\t请输入您想进入的功能的序号(0-2): ___\b\b\b");
}
int Input()
{
    system("cls");
    printf("请输入姓名:");
    scanf("%s", &Student[Use_number].Name);
    printf("请输入成绩:");
    scanf("%d", &Student[Use_number].Score);
    Use_number++;
}
int Search()
{
    system("cls");
    int times = 0,temp = 0;
    printf("请输入需要查找的姓名： ___\b\b\b");
    scanf("%s", Student[100].Name);
    printf("姓名\t成绩\n");
    for (temp = 0; temp < Use_number; temp++)
    {
        if ((strcmp(Student[temp].Name,Student[100].Name)) == 0)
        {
            times++;
            printf("%s\t%d\n", Student[temp].Name,Student[temp].Score);
        }
    }
    printf("%s同学一共出现%d次\n", Student[100].Name, times);
    printf("按任意键回到主菜单！");
    if (_getch());
}
int main()
{
    while (996)
    {
        Menu();
        switch (_getch())
        {
        case 48:
        {
            system("cls");
            printf("\t\t\t\t\t确认退出系统？(y/n) ___\b\b\b");
            if (_getch() == 121)
            {
                system("cls");
                printf("\t\t\t\t\t感谢您的使用！程序将在1.5秒后退出！");
                Sleep(1500);
                exit(0);
            }
            else
                break;
        }
        case 49:
            Input();
            break;
        case 50:
            Search();
            break;
        }
    }
}