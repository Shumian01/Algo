### Dijkstra算法:

**Dijkstra**是一种求解 非负权图 上单源最短路径的算法。
**思路**:将所有结点分为两个集合:已经确定最短路径的点(**S**)和未确定最短路长度的点集(**T**),开始时所有点都属于T
初始化dist[s]=0,其他点dist都为 +&infin;
然后重复操作:

1. 在T集合中找到离源点最近的点u加入S
2. 点u进行松弛操作(用u更新其他点的距离)(dis[j]=(dis[j]>dis[u]+w)?dis[u]+w:dis[j])
3. 直到T集合为空 结束
**实现**
1.朴素做法O(n^2^)
2.优先队列版O(mlogm)

#### 朴素版Dijkstra

用的邻接矩阵存的图

遍历dist数组 找到没用确定最短路距离源点最近的点 u 用u更新其他点

```c++
int	g[N][N],dist[N];
bool st[N];
void dijkstra()
{
    memset(dist,0x3f,sizeof d)//每个点先初始化为无穷远
    for(int i=1;i<=n;i++)//遍历n个点
    {
        int u=0;
        for(int j=1;j<=n;j++)//遍历dist数组 找到未确定最短路距离源点最近的点 u
        {
            if(!st[j]&&(u==0||d[j]<d[u]))
            t=j;
    	}
    //找到u
    st[u]=true;
   		for(int i=1;i<=n;i++)//用u这个点更新其他点离源点的距离
    	{
        	dist[i]=min(dist[i],dist[u]+g[u][i]);
    	}
	}
    
  
}
```

时间复杂度:O(N^2^)



#### 堆优化版Dijkstra

priority_queue<PII,vector<PII>,greater<PII>>heap;//小根堆

```c++
int e[N],ne[N],h[N],W[N],idx;
int dist[N];
booo st[N];
void add(int a,int b,int c)
{
	w[idx]=c,e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}



void Dijkstra()
{
	memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    priority_queue<PII,vector<PII>,greater<PII>>heap;//小根堆
    heap.push({0,1});//距离 编号
    while(heap.size())
    {
        auto u=heap.top();//未确定最短距离 离源点最近的点
        heap.pop();
        int distance=u.first,id=u.second;
        if(st[id])continue;
        st[id]=true;
        for(int i=h[id];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(d[j]>distance+w[i])
            {
                d[j]=distance+w[i];
                heap.push(d[j],j);
            } 
        }
            
        
    }
}
int main()
{
	memset(h,-1,sizeof h);
	cin>>n>>m;
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
	}

	return 0;
}




```

时间复杂度:mlog^m^

思想政治理论实践课
