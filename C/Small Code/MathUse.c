#include <stdio.h>
#include <math.h>
int main()
{
    int x,y;
    scanf("%d",&x);
    y = fabs(3 * sin(x) + 4 * cos(x)) + exp(x);
    printf("%d",y);
}