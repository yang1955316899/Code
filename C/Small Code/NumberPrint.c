#include <stdio.h>
int main()
{
    char litter;
    while ((litter = getchar()) != '\n')
        if (litter >= '0' && litter <= '9')
            printf("%c", litter);
    return 0;
}