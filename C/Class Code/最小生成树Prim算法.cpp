#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int g[101][101]; //�ڽӾ���
int minn[101];   //minn[i]�������i��׵���������С��Ȩ
bool u[101];     //u[i]=True����ʾ����i��δ���뵽��������
                 //u[i]=False����ʾ����i�Ѽ��뵽��������
int n, i, j;
int main()
{
    // freopen("wire.in","r",stdin);
    // freopen("wire.out","w",stdout);
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> g[i][j];
    memset(minn, 0x7f, sizeof(minn)); //��ʼ��Ϊmaxint
    minn[1] = 0;
    memset(u, 1, sizeof(u)); //��ʼ��ΪTrue����ʾ���ж���Ϊ����
    for (i = 1; i <= n; i++)
    {
        int k = 0;
        for (j = 1; j <= n; j++) //��һ����׵�������Ȩֵ��С������k
            if (u[j] && (minn[j] < minn[k]))
                k = j;
        u[k] = false;            //����k���������������Ϊ�׵�
        for (j = 1; j <= n; j++) //�޸���k��������������
            if (u[j] && (g[k][j] < minn[j]))
                minn[j] = g[k][j];
    }
    int total = 0;
    for (i = 1; i <= n; i++) //�ۼ�Ȩֵ
        total += minn[i];
    cout << total << endl;
    return 0;
}
