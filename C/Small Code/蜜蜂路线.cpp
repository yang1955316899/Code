#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
int b[10001];
using namespace std;
int main()
{
    int n;
    int m;
    cin>>m>>n;int l=n-m;
    b[1]=1;
    b[2]=1;
    for(int i=3;i<=l+1;i++)
    {
        b[i]=b[i-1]+b[i-2];
    }
    cout<<b[l+1];
    return 0;
}
