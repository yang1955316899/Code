#include <stdio.h>
int main()
{
    int max = -1, min = 101,temp;
    for (int people = 0; people < 50; people++)
    {
        scanf("%d",&temp);
        if (max < temp) max = temp;
        if (min > temp) min = temp;
    }
    printf("���ֵ��%d����Сֵ��%d",max,min);
    return 0;
}