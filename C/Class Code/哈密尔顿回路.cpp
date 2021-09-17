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
    { //û�����ɸѡ����������еĻ�·
        for (i = 1; i <= length; i++)
            printf("%d", ans[i]);
    }
}
void dfs(int i) //ͼ������ģ���ڽӱ�洢�����ʵ�i
{
    visited[i] = true; //���Ϊ�Ѿ����ʹ�
    v1[i] = true;      //���Ϊ����һ��ͼ�г��ֹ�
    ans[++length] = i; //��¼�´�
    for (int j = 1; j <= num[i]; j++)
    {
        if (g[i][j] == x) //�ص���㣬���ɹ��ܶ��ٻ�
        {
            ans[++length] = g[i][j];
            print(); //����˵���ҵ���һ�����������ans���顣
            length--;
        }
        if (!visited[g[i][j]])
            dfs(g[i][j]); //������i�����������δ���ʹ��Ķ���
    }
    length--;
    visited[i] = false; //�����ǻ��ݹ��̣�ע��v1��ֵ���ָ���
}
int main()
{
    memset(visited, false, sizeof(visited));
    memset(v1, false, sizeof(v1));
    scanf("%d %d", &n, &e);
    for (int i = 1; i <= e; i++)
    {
        scanf("%d %d", &x, &y);
        num[x]++; //ͳ��ÿ����Ķ�
        num[y]++;
        g[x][num[x]] = y;
        g[y][num[y]] = x;
    }
    for (x = 1; x <= n; x++)
        //ÿһ���㶼��Ϊ��㳢�Է��ʣ��ҵ����в���ͨ���ֵĻ�·
        if (!v1[x]) //�����x����֮ǰ���������ʹ���ͼ�
        {
            length = 0; //����һ��ans�����𰸣�length�Ǵ𰸵ĳ��ȡ�
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
��һ�����ݣ�
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
