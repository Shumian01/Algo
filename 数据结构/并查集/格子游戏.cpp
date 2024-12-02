#include<bits/stdc++.h>
using namespace std;

const int N = 210;
int p[N*N];
int n,m;
int find(int x)
{
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
int get(int x,int y)
{
    return x*n+y;
}
int main()
{
    cin>>n>>m;
    for (int i = 1; i <= n*n; i ++ )p[i]=i;
    for (int i = 1; i <= m; i ++ )
    {
       int x,y;char op;
       cin>>x>>y>>op;
       x--;y--;
       int a=get(x,y);
       int b=0;
       if(op=='D')b=get(x+1,y);
       else b=get(x,y+1);
       int pa=find(a),pb=find(b);
       if(pa==pb)
       {
           cout<<i<<endl;
           return 0;
       }
        p[pa]=p[b];
    }
    
    cout<<"draw"<<endl;
    return 0;
}