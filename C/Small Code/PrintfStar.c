#include <stdio.h>
int main()
{
    for (int time = 1; time <= 7; )
    {
        for (int temp = 7 - time; temp > 0; ) {printf(" ");temp-=2;}
        for (int temp = time; temp > 0; temp--) printf("*");
        printf("\n");
        time += 2;
    }
    for (int time = 1; time <= 6; )
    {
        for (int temp = time; temp > 0; ) {printf(" ");temp-=2;}
        for (int temp = 6 - time; temp > 0; temp--) printf("*");
        printf("\n");
        time += 2;
    }
}