#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 5e4*42;
typedef pair<int,int> PII;
bool st[N];
int n,m,k;
int h[N],e[N],ne[N],idx,w[N],d[N];
int s,t;
void add(int a,int b,int c)
{
    w[idx]=c,e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dijkstra()
{
    memset(d,0x3f,sizeof d);
    d[s]=0;
    priority_queue<PII,vector<PII>,greater<PII>>heap;//小根堆
    heap.push({0,s});
    while(heap.size())
    {
        auto t=heap.top();
        heap.pop();

        int ver=t.second,distance=t.first;

        if(st[ver])continue;
        st[ver]=true;

        for(int i=h[ver];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(d[j]>distance+w[i])
            {
                d[j]=distance+w[i];
                heap.push({d[j],j});
            }
        }

    }

}

int main()
{
    cin>>n>>m>>k;

    cin>>s>>t;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        for(int i=0;i<=k;i++)
        {
            add(u+i*n,v+i*n,w);
            add(v+i*n,u+i*n,w);      
            if(i!=k)
            {
                add(u + i * n, v + (i + 1) * n, 0);
                add(v + i * n, u + (i + 1) * n, 0);
            }
            
        }
        
        
        
        
        
    }
    dijkstra();
    int ans=0x3f3f3f3f;
    for(int i=0;i<=k;i++)
        ans=min(ans,d[t+i*n]);
        
    cout<<ans<<endl;

   return 0;
}
