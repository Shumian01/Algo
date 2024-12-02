#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;
int a[N],c[N];
int n,m;
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int k)
{
    while(x<=n)
    {
        c[x]+=k;
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int res=0;
    while(x>0)
    {
        res+=c[x];
        x-=lowbit(x);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)add(i,a[i]-a[i-1]);//构建差分数组

    while(m--)//m次指令
    {
        char op;int l,r,k;
        cin>>op>>l;
        if(op=='C')//区间修改操作
        {   
            cin>>r>>k;
            add(l,k),add(r+1,-k);
        }
        else//单点查询a[] 以为c是差分数组 c的前缀和就是a
        {
            cout<<sum(l)<<endl;
        }
    }

    return 0;
}