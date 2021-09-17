#include <iostream>
#include <cstring>
using namespace std;
#define maxn 101
int g[maxn][maxn]; //��ͼ���ڽӾ���洢
int du[maxn];      //��¼ÿ����Ķȣ����������ıߵ���Ŀ
int circuit[maxn]; //������¼�ҵ���ŷ��·��·��
int n, e, circuitpos, i, j, x, y, start;
void find_circuit(int i)
{ //�����������ȱ�������Ѱ��ŷ��·
   int j;
   for (j = 1; j <= n; j++)
      if (g[i][j] == 1) //������һ�����������ĵ����
      {
         g[j][i] = g[i][j] = 0;
         find_circuit(j);
      }
   circuit[++circuitpos] = i; //��¼��·��
}
int main()
{
   memset(g, 0, sizeof(g));
   cin >> n >> e;
   for (i = 1; i <= e; i++)
   {
      cin >> x >> y;
      g[y][x] = g[x][y] = 1;
      du[x]++; //ͳ��ÿ����Ķ�
      du[y]++;
   }
   start = 1;               //�������㣬�ʹ���㿪ʼѰ�ң������ҵ��ľ���
   for (i = 1; i <= n; i++) //ŷ��·��û�����ʹ�����㿪ʼ
      if (du[i] % 2 == 1)   //�����ҵ��ľ���ŷ����·��(��Ϊÿһ���㶼��ż��)
         start = i;
   circuitpos = 0;
   find_circuit(start);
   for (i = 1; i <= circuitpos; i++)
      cout << circuit[i] << ' ';
   cout << endl;
   return 0;
}
/*  
13 16
1 4
4 7
7 6
6 5
5 4
4 3
3 13
12 13
11 12
3 11
2 3
2 8
2 10
9 10
8 9
1 2
1 4 7 6 5 4 3 13 12 11 3 2 10 9 8 2 1 

5 5
1 2
2 3
3 4
4 5
5 1
1 5 4 3 2 1 */
