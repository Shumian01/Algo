# 解决多源汇最短路问题

#### Floyd算法

```c++
#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 210;
int n,m,q;
int d[N][N];

void floyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);




}

int main()
{
   cin>>n>>m>>q;
   for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(j==i)d[i][j]=0;
            else d[i][j]=0x3f3f3f3f;

    while(m--)
    {   
        int a,b,w;
        cin>>a>>b>>w;
        d[a][b]=min(d[a][b],w);
    }
    floyd();
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(d[x][y]>0x3f3f3f3f/2)cout<<"impossible"<<endl;
        else cout<<d[x][y]<<endl;


    }
   return 0;
}

```

