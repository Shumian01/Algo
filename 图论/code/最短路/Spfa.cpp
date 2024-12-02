#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int INF = 0x3f3f3f3f;
int n, m;
vector<vector<pair<int, int>>> adj; // 使用vector数组表示邻接表
vector<int> dist;
vector<bool> st;

void add(int a, int b, int c) {
    adj[a].emplace_back(b, c); // 在邻接表中添加边
}

int spfa() {
    dist.assign(n + 1, INF); // 初始化距离数组
    st.assign(n + 1, false); // 初始化访问标记数组
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    st[1] = true;

    while (!q.empty()) {   
        int u = q.front();
        q.pop();
        st[u] = false;

        for (auto &[j, w] : adj[u]) { // 遍历邻接点
            if (dist[j] > dist[u] + w) {   
                dist[j] = dist[u] + w;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return dist[n] == INF ? INF : dist[n];
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1); // 调整邻接表大小
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    int result = spfa();
    if (result == INF) cout << "impossible" << endl;
    else cout << result << endl;

    return 0;
}




/*#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e5+10;
int n,m;
int dist[N],e[N],ne[N],h[N],w[N];
int idx;
bool st[N];
void add(int a,int b,int c)
{
    w[idx]=c,e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int spfa()
{
    memset(dist,0x3f,sizeof dist);
    queue<int>q;
    dist[1]=0;
    q.push(1);
    st[1]=true;
    while(q.size())
    {   
        auto u= q.front();
        q.pop();
        st[u]=false;
        for(int i=h[u];i!=-1;i=ne[i])
        {
            int j =e[i];
            if(dist[j]>dist[u]+w[i])
            {   
                dist[j]=dist[u]+w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }

    if(dist[n]>0x3f3f3f3f)return 0x3f3f3f3f;
    else return dist[n];


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
    if(spfa()==0x3f3f3f3f)cout<<"impossible"<<endl;
    else cout<<spfa()<<endl;



   return 0;
}
*/