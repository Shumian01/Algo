#include<bits/stdc++.h>
using namespace std;
const int N =3e4+10;
int p[N];
int sz[N],d[N];
int find(int x)
{
    if (p[x] != x)
    {
        int root = find(p[x]);
        d[x] += d[p[x]];
        p[x] = root;
    }
    return p[x];
}
void un(int x,int y)
{
    int px=find(x),py=find(y);
    if(px!=py)
    {
        d[px] = sz[py];
        sz[py] += sz[px];
        p[px] = py;
    }
    
}
int get(int x,int y)
{
    int px=find(x),py=find(y);
    if(px!=py)return -1;
    else
    return max(0,abs(d[x]-d[y])-1);
}


int main()
{   
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int T;cin>>T;
    for (int i = 1; i <N; i ++ )
    {
        p[i]=i;
        sz[i]=1;
    }
    
    while(T--)
    {
        char op;int x,y;
        cin>>op>>x>>y;
        if(op=='M')
        un(x,y);
        else
        {
            cout<<get(x,y)<<endl;
        }
    }
    return 0;
}
