#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
int p[N],w[N],v[N];
int val,n,m;
int f[N];
int find(int x)  // 并查集
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{   
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin>>n>>m>>val;
    for (int i = 1; i <= n; i ++ )p[i]=i;
    for (int i = 1; i <= n; i ++ )cin>>v[i]>>w[i];
    for (int i = 1; i <= m; i ++ )
    {
        int a,b;cin>>a>>b;
        int pa=find(a),pb=find(b);
        if(pa!=pb)
        {
            v[pb]+=v[pa];
            w[pb]+=w[pa];
            p[pa]=pb;
        }
        
    }
    for(int i=1;i<=n;i++)
        if(p[i]==i)
        for (int j =val ;j>=v[i]; j--)
            f[j]=max(f[j],f[j-v[i]]+w[i]);
            
    cout<<f[val]<<endl;
    
    return 0;
}