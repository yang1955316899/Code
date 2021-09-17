#include <stdio.h>
int main()
{
    int temp,sum = 0;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&temp);
        sum += temp;
    }
    printf("%.2f",sum*1.0/5);
    return 0;
}