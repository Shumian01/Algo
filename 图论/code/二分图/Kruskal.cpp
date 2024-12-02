#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int M = 2e5+10;
const int N=1e5+10;
int p[N];
struct edge
{
    int a,b,w;
    bool operator <(const edge&W)const
    {return w<W.w;}
}e[M];

int find(int x)
{
    if(x!=p[x])p[x]=find(p[x]);
    return p[x];
}

int n,m;

int main()
{
   cin>>n>>m;
   for(int i=1;i<=n;i++)p[i]=i;
   for(int i=1;i<=m;i++)
   {
        int u,v,w;cin>>u>>v>>w;
        e[i]={u,v,w};
   }
   sort(e+1,e+m+1);
   int ans=0;
   int cnt=0;
    for(int i=1;i<=m;i++)
    {
        int a=e[i].a,b=e[i].b,w=e[i].w;
        int fa=find(a),fb=find(b);
        if(fa!=fb)
        {
            cnt++;
            ans+=w;
            p[fa]=fb;
        }

    }
    if(cnt<n-1)cout<<"impossible"<<endl;
    else cout<<ans<<endl;

   return 0;
}
