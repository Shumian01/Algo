#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 510;
int g[N][N],dist[N];
int n,m;
bool st[N];
int prime()
{
    memset(dist,0x3f,sizeof dist);
    int res=0;
    for(int i=0;i<n;i++)
    {
        int u=-1;
        for(int j=1;j<=n;j++)
        {
            if(!st[j]&&(u==-1||dist[u]>dist[j]))
            u=j;
        }
    if(i&&dist[u]==0x3f3f3f3f)return 0x3f3f3f3f;
    if(i)res+=dist[u];
    st[u]=true;
    for(int j=1;j<=n;j++)dist[j]=min(dist[j],g[u][j]);
    }

    return res;
}

int main()
{
   cin>>n>>m;
   memset(g,0x3f,sizeof g);
   while(m--)
   {
        int u,v,w;
        cin>>u>>v>>w;
        g[u][v]=g[v][u]=min(g[u][v],w);
   }
    int t=prime();
    if(t==0x3f3f3f3f)cout<<"impossible"<<endl;
    else cout<<t<<endl;



   return 0;
}
