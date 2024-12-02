#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
unordered_map<int,int>S;
int p[N];
struct node{
    int x,y,e;
}query[N];
int find(int x)
{
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
int cnt;//离散化数量
int get(int x)
{
    if(!S.count(x))S[x]=++cnt;
    return S[x];
}


int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T=1;cin>>T;
    S.clear();
    while(T--)
    {   
         S.clear();//清空哈希表进行下一个问题
        cnt=0;//重置哈希长度
        int n;cin>>n;
        int x,y,e;
        for (int i = 0; i <n; i ++ )
        {
            cin>>x>>y>>e;
            query[i]={get(x),get(y),e};
        }
        for (int i = 1; i <=cnt; i ++ )p[i]=i;
        //合并
        for (int i = 0; i < n; i ++ )
        {
            int pa=find(query[i].x),pb=find(query[i].y);
            if(query[i].e==1)
            {
                p[pa]=pb;
            }
        }
         bool flag = false;
        for (int i = 0; i < n; i ++ )
            if (query[i].e == 0)
            {
                int pa = find(query[i].x), pb = find(query[i].y);
                if (pa == pb)
                {
                    flag = true;
                    break;
                }
            }

        if (flag)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    
    return 0;
}