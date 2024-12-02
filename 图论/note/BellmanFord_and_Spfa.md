**上个文章讲了Dijkstra算法但是Dijkstra算法只能解决单源汇非负边权的最短路问题这次文章来讲单源汇存在负边权的解决方法Bellmanforda和spfa算法**



**二者适用场景区别**:

一般来说使用spfa就能解决大部分的问题,但问题出现不超过k条边的时候应当使用Bellmanford算法



#### BellmanFord：

随意存图这里用结构体存



```c++
struct edge
{
   int a,b,w;
}edges[M];
```



   dist[N]存距离 dist初始化为无穷大 dist[1]=0 backup备份dist

for (n)      **这里的n是不超过n条边,如果题目要求不超过k条边最外层循环k次!**

​	memcpy(backup,dist)**用backup备份上一次的dist防止串联**

​	for(n)遍历所有边 a,b,w      a–>b

​	{	

​		int a=edge[i].a,b=edge[i].b,w=edge[i].w;

​		memcpy(backup,dist)**用backup备份上一次的dist防止串联**

​		松弛操作 dist[b]=min(dist[b],backup[a]+w)

​	}

if dist[n]>0x3f3f3f3f/2 return 0x3f3f3f3f **无法到达**

else return dist [n]

```c++
int dist[N],backup[N];
struct edge
{
   int a,b,w;
}edges[M];

int bellman_ford
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for(int i=1;i<=k;i++)
    {
        memcpy(backup,dist,sizeof dist);
        for(int j=1;j<=n;j++)
        {
            int a=e[j].a,b=e[j].b,w=e[j].w;
            dist[b]=min(dist[b],backup[a]+w);
        }
        
    }
    if(dist[n]>0x3f3f3f3f/2)return 0x3f3f3f3f;
    else return dist[n];
}




```



**注意**: bellmanford算法最核心的就是松弛操作 还要记得存dist的备份防止串联

时间复杂度:O(n*m)



#### Spfa: 

Spfa:找到dist变小的节点(这些节点都存在队列q中) 取出对头 u然后弹出队列标记为未变短的点

用对其他点进行松弛操作

成功进行松弛操作的点(距离变短的点)存入q st[j]=true;



起点1 —>q (起点1入队) st[1]=true;

while(q.size())

1. 取出对头 u<——q.front() 弹出对头q.pop() st[u]=false;

2. 用u对其他点进行松弛操作 更新u的出边

	 如果j点被成功更新 j点入队 q.push(j),st[j]=true

```c++
const int N=510;
int idx,e[N],ne[N],h[N],w[N]
int dist[N];
bool st[N];
int spfa()
{
    memset(dist,0x3f3f3f3f,sizeof dist);
    queue<int>q;
    q.push(1);
    dist[1]=0;
    st[1]=true;
    while(q.size())
    {
        int u=q.front(),q.pop();
        st[u]=false;
        
        for(int i=h[u];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[u]+w[i])
            {
                dist[j]=dist[u]+w[i];
                if(!st[j])
                {
                    st[j]=true;
                    q.push(j);
                }
            }            
        }

    }
	if(dist[n]>0x3f3f3f3f/2)return 0x3f3f3f3f;
    else return dist[n];
}

int main()
{
    cin>>n>>m;
    while(m--)
    {
        int a,b,w;
        add(a,b,w);
    }
    int t=spfa();
    
    
}

```

时间复杂度:一般 O(M)最坏O(N*M)

#### Spfa求负环

初始化所有点都进q

dist[x]:1到x的最短距离

cnt[x]:1到x的边数

dist[x]=dist[t]+w[i];

cnt[x]=cnt[t]+1;



如果中途cnt[x]>=n  至少经过n+1个点 根据抽屉原理有两个点必相同 存在负环直接return

**代码如下**:

```c++
#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 150010;
typedef pair<int,int> PII;
bool st[N];
int n,m;
int dist[N],cnt[N];
int h[N],e[N],ne[N],idx,w[N],d[N];
void add(int a,int b,int c)
{
    w[idx]=c,e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    queue<int>q;
    for (int i = 1; i <= n; i ++ )
    {
        q.push(i);
        st[i]=true;
    }
    
    
    
    while(q.size())
    {
        auto t=q.front();
        q.pop();
        st[t]=false;
        
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int u=e[i];
            if(dist[u]>dist[t]+w[i])
            {
                dist[u]=dist[t]+w[i];
                cnt[u]=cnt[t]+1;
                if(cnt[u]>=n)return true;
                if(!st[u])
                {
                    q.push(u);
                    st[u]=true;
                    
                }
                
            }
            
        }
        
        
        
    }
    
    
    
    
    return false;
}

int main()
{
    	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    auto t =spfa();
    if(spfa())cout<<"Yes"<<endl;
    else cout << "No"<<endl;

   return 0;
}

```

