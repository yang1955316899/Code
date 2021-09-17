#include <stdio.h>
int jia(int a,int b,int *re){*re = a+b;}
int jian(int a,int b,int *re){*re = a-b;}
int cheng(int a,int b,int *re){*re = a*b;}
int chu(int a,int b,int *re){*re = a/1.0*b;}
int main()
{
    int a,b,re= 0;
    scanf("%d %d ",&a,&b);
    switch (getchar())
    {
    case '+':jia(a,b,&re);break;
    case '-':jian(a,b,&re);break;
    case '*':cheng(a,b,&re);break;
    case '/':chu(a,b,&re);break;
    }
    printf("%d",re);
}