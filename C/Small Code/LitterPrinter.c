#include <stdio.h>
int main()
{
    char litter;
    while ((litter = getchar()) != '\n')
        if (litter >= 'a' && litter <= 'z' || litter >= 'A' && litter <= 'Z')
            printf("%c", litter);
    return 0;
}