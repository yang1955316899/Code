#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a=0,b=1,c=1,n;
    cin>>n;//����n
    for(int i=1;i<=n;i++)
    {
        a=b;
        b=c;
        c=a+b;
    }
    cout<<c;//������ս�� 
    return 0;
}