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
    printf("\t\t\t\t|\t 0. �˳�ϵͳ\t\t\t\t|\n");
    printf("\t\t\t\t|\t 1. ��ӳɼ�\t\t\t\t|\n");
    printf("\t\t\t\t|\t 2. ���ҳɼ�\t\t\t\t|\n");
    printf("\t\t\t\t|-----------------------------------------------|\n\n");
    printf("\t\t\t\t\t�������������Ĺ��ܵ����(0-2): ___\b\b\b");
}
int Input()
{
    system("cls");
    printf("����������:");
    scanf("%s", &Student[Use_number].Name);
    printf("������ɼ�:");
    scanf("%d", &Student[Use_number].Score);
    Use_number++;
}
int Search()
{
    system("cls");
    int times = 0,temp = 0;
    printf("��������Ҫ���ҵ������� ___\b\b\b");
    scanf("%s", Student[100].Name);
    printf("����\t�ɼ�\n");
    for (temp = 0; temp < Use_number; temp++)
    {
        if ((strcmp(Student[temp].Name,Student[100].Name)) == 0)
        {
            times++;
            printf("%s\t%d\n", Student[temp].Name,Student[temp].Score);
        }
    }
    printf("%sͬѧһ������%d��\n", Student[100].Name, times);
    printf("��������ص����˵���");
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
            printf("\t\t\t\t\tȷ���˳�ϵͳ��(y/n) ___\b\b\b");
            if (_getch() == 121)
            {
                system("cls");
                printf("\t\t\t\t\t��л����ʹ�ã�������1.5����˳���");
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