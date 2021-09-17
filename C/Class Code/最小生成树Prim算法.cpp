#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int g[101][101]; //邻接矩阵
int minn[101];   //minn[i]存放蓝点i与白点相连的最小边权
bool u[101];     //u[i]=True，表示顶点i还未加入到生成树中
                 //u[i]=False，表示顶点i已加入到生成树中
int n, i, j;
int main()
{
    // freopen("wire.in","r",stdin);
    // freopen("wire.out","w",stdout);
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> g[i][j];
    memset(minn, 0x7f, sizeof(minn)); //初始化为maxint
    minn[1] = 0;
    memset(u, 1, sizeof(u)); //初始化为True，表示所有顶点为蓝点
    for (i = 1; i <= n; i++)
    {
        int k = 0;
        for (j = 1; j <= n; j++) //找一个与白点相连的权值最小的蓝点k
            if (u[j] && (minn[j] < minn[k]))
                k = j;
        u[k] = false;            //蓝点k加入生成树，标记为白点
        for (j = 1; j <= n; j++) //修改与k相连的所有蓝点
            if (u[j] && (g[k][j] < minn[j]))
                minn[j] = g[k][j];
    }
    int total = 0;
    for (i = 1; i <= n; i++) //累加权值
        total += minn[i];
    cout << total << endl;
    return 0;
}
