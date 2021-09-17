#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct AZ *p,*last,*new;
    int number = 65;
    struct AZ
    {
        char Litter;
        struct AZ *next;
    };
    p = (struct AZ *)malloc(sizeof(struct AZ));
    while (number > 90)
    {
        
        p->Litter = number;
        new = (struct AZ *)malloc(sizeof(struct AZ));
        p->next = new;
        p = new;
    }
}