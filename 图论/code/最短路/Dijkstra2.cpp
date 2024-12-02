#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 150010;
typedef pair<int,int> PII;
bool st[N];
int n,m;
int h[N],e[N],ne[N],idx,w[N],d[N];
void add(int a,int b,int c)
{
    w[idx]=c,e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dijkstra()
{
    memset(d,0x3f,sizeof d);
    d[1]=0;
    priority_queue<PII,vector<PII>,greater<PII>>q;//小根堆
    q.push({0,1});
    while(q.size())
    {
        auto t=q.top();
        q.pop();

        int id=t.second,dis=t.first;

        if(st[id])continue;
        st[id]=true;

        for(int i=h[id];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(d[j]>dis+w[i])
            {
                d[j]=dis+w[i];
                q.push({d[j],j});
            }
        }

    }
    if(d[n]==0x3f3f3f3f)return -1;

    return d[n];
}

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    int t=dijkstra();
    cout<<t<<endl;

   return 0;
}
