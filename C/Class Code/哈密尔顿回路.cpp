#include <stdio.h>
#include <string.h>
int start, length, x, n, e, y;
bool visited[101], v1[101];
int ans[101], num[101];
int g[101][101];
void print()
{
    int i;
    if (length == n + 1)
    { //没有这个筛选，会输出所有的回路
        for (i = 1; i <= length; i++)
            printf("%d", ans[i]);
    }
}
void dfs(int i) //图用数组模拟邻接表存储，访问点i
{
    visited[i] = true; //标记为已经访问过
    v1[i] = true;      //标记为已在一张图中出现过
    ans[++length] = i; //记录下答案
    for (int j = 1; j <= num[i]; j++)
    {
        if (g[i][j] == x) //回到起点，构成哈密尔顿环
        {
            ans[++length] = g[i][j];
            print(); //这里说明找到了一个环，则输出ans数组。
            length--;
        }
        if (!visited[g[i][j]])
            dfs(g[i][j]); //遍历与i相关联的所有未访问过的顶点
    }
    length--;
    visited[i] = false; //这里是回溯过程，注意v1的值不恢复。
}
int main()
{
    memset(visited, false, sizeof(visited));
    memset(v1, false, sizeof(v1));
    scanf("%d %d", &n, &e);
    for (int i = 1; i <= e; i++)
    {
        scanf("%d %d", &x, &y);
        num[x]++; //统计每个点的度
        num[y]++;
        g[x][num[x]] = y;
        g[y][num[y]] = x;
    }
    for (x = 1; x <= n; x++)
        //每一个点都作为起点尝试访问，找到所有不连通部分的回路
        if (!v1[x]) //如果点x不在之前曾经被访问过的图里。
        {
            length = 0; //定义一个ans数组存答案，length记答案的长度。
            dfs(x);
        }
    return 0;
}
/*
5 7
1 2
2 3
3 4
4 5
5 1
5 3
4 1
另一组数据：
5 10 
1 2
2 3
3 4
4 5
5 1
5 3
4 1 
2 5
2 4
3 1
  */
