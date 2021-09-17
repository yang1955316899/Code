#include <stdio.h>
bool d[100] = {0}, b[100] = {0}, c[100] = {0};
int sum = 0, a[100];
int search(int);
int print();
int main()
{
    search(1); //从第1个皇后开始放置
}
int search(int i)
{
    int j;
    for (j = 1; j <= 8; j++)                           //每个皇后都有8位置(列)可以试放
        if ((!b[j]) && (!c[i + j]) && (!d[i - j + 7])) //寻找放置皇后的位置　由于C++不能操作负数组，因此考虑加7
        {                                              //放置皇后,建立相应标志值
            a[i] = j;                                  //摆放皇后
            b[j] = 1;                                  //宣布占领第j列
            c[i + j] = 1;                              //占领两个对角线
            d[i - j + 7] = 1;
            if (i == 8)
                print(); //８个皇后都放置好,输出
            else
                search(i + 1); //继续递归放置下一个皇后
            b[j] = 0;          //递归返回即为回溯一步,当前皇后退出
            c[i + j] = 0;
            d[i - j + 7] = 0;
        }
}
int print()
{
    int i;
    sum++; //方案数累加1
    printf("sum=", sum);
    for (i = 1; i <= 8; i++) //输出一种方案
        printf(" %d", a[i]);
}
