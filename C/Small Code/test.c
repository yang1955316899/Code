#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d", &a);
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &b);
        printf("%d ", a + b);
        a = b;
    }
}
