#include <stdio.h>

#define maxn 20001
int father[maxn];
int m, n, i, x, y, q;
int find(int x) //用递归的实现
{
    if (father[x] != x)
        return find(father[x]);
    else
        return x;
}
void unionn(int r1, int r2)
{
    father[r2] = r1;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
        father[i] = i; //建立新的集合，其仅有的成员是i
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        int r1 = find(x);
        int r2 = find(y);
        if (r1 != r2)
            unionn(r1, r2);
    }
    scanf("%d", &q);
    for (i = 1; i <= q; i++)
    {
        scanf("%d%d", &x, &y);
        if (find(x) == find(y))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
