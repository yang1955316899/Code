#include "stdio.h"
int main()
{
    char c;
    printf( "input c:");
    scanf("%c",&c);
    if(c>='A'&&c<='z'||c>='a' &&c<='z')
        printf("%d",c);
    else
        printf("%%");
}

