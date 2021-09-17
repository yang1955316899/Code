#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
int main()
{
    int start,end;
    printf("Start?\nPress any key");
    if(_getch())
        start = time(NULL);
    system("cls");
    printf("Press any key to pause!\n");
    if(_getch())
        end = time(NULL);
    printf("Use time:%d min %d sec",(end - start) / 60,(end - start) % 60);
}