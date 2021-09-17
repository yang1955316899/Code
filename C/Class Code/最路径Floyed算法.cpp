#include <stdio.h>
#include <math.h>
#include <string.h>

int a[101][3];
double f[101][101];
int n, i, j, k, x, y, m, s, e;
int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d%d", &a[i][1], &a[i][2]);
    scanf("%d", &m);
    memset(f, 0x7f, sizeof(f)); //初始化f数组为最大值
    for (i = 1; i <= m; i++)    //预处理出x、y间距离
    {
        scanf("%d%d", &x, &y);
        f[y][x] = f[x][y] = sqrt(pow(double(a[x][1] - a[y][1]), 2) + pow(double(a[x][2] - a[y][2]), 2));
    }
    scanf("%d%d", &s, &e);
    for (k = 1; k <= n; k++) //floyed 最短路算法
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if ((i != j) && (i != k) && (j != k) && (f[i][k] + f[k][j] < f[i][j]))
                    f[i][j] = f[i][k] + f[k][j];
    printf("%.2lf\n", f[s][e]);
    return 0;
}
