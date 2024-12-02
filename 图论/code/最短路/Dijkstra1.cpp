#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 510;
int g[N][N],d[N];
bool st[N];
int n,m;

int dijkstra()
{
    memset(d,0x3f,sizeof d);
    d[1]=0;
    for(int i=1;i<=n;i++)//遍历 dist 数组，找到没有确定最短路径的节点中距离源点最近的点t
    {
        int t=0;
        for(int j=1;j<=n;j++)
        {
            if(!st[j]&&(t==-1||d[j]<d[t]))//d[t]是上一个距离源点最近的点且已经确定最短路
            t=j;
        }

        st[t]=true;

        for(int j=1;j<=n;j++)
            d[j]=min(d[j],d[t]+g[t][j]);
    }
    if(d[n]==0x3f3f3f3f)return -1;
    return d[n];

}

int main()
{
    cin>>n>>m;
    memset (g,0x3f,sizeof g);
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);
    }

    cout<<dijkstra()<<endl;

   return 0;
}
