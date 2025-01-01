#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e5+10;
int dfn[N],low[N],idx;
vector<int>adj[N];
int cut,edges;
vector<int>cuts(N,0);
void dfs(int x,int fa)
{
    low[x]=dfn[x]=++idx;
    int child =0;//独立儿子数量
    for(const auto &y:adj[x])
    {
        if(y==fa)continue;
        if(!dfn[y])
        {
            dfs(y,x);
            low[x]=min(low[x],low[y]);
            edges+=low[y]>dfn[x];
            cnt+=low[y]>=dfn[x];
        }else low[x]=min(low[x],dfn[y]);
    }
    if((fa==0&&child>1)||(fa&&child>=1))cuts[x]=1;
}
int main()
{
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++)if(!dfn[i])dfs(i,0);
    cut =std::count(cuts.begin(), cuts.end(), 1);
    cout<<cut<<' '<<edges;
    return 0;
}