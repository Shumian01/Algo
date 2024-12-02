#include <bits/stdc++.h>
using namespace std;

const int N =1e5+10;
int a[N],c[N];
int n; //
int lowbit(int x)
{
    return x & -x;
}
void add(int i, int k) // 单点修改
{
    while (i <= n)
    {
        c[i] += k;
        i += lowbit(i);
    }
}

int sum(int x)//1~x的前缀和
{
    int res=0;
    while(x>0)
    {
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}

int getrange(int l,int r)
{
    return sum(r)-sum(l-1);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {   
        cin>>a[i];
        add(i,a[i]);//构建c数组
    }

    return 0;
}