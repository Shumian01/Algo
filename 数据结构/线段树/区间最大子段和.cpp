#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N];
struct node
{
    int l,r;
    int sum,lmax,rmax,tmax;
}tr[4*N];
void pushup(node &u,node &l,node &r)
{
    u.sum = l.sum + r.sum;
    u.lmax = max(l.lmax, l.sum + r.lmax);
    u.rmax = max(r.rmax, r.sum + l.rmax);
    u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);
}
void pushup(int u)
{
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}
void build(int u,int l,int r)
{
    if(l==r)
    {
        tr[u]={l,r,a[r],a[r],a[r],a[r]};
        return;   
    }
    tr[u]={l,r};
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    pushup(u);
}
void modify(int u,int x,int v)
{
    int l=tr[u].l,r=tr[u].r;
    if(l==x&&r==x)
    {
        tr[u]={x,x,v,v,v,v};
        return;
    }
    int mid =l+r>>1;
    if(x<=mid)modify(u<<1,x,v);
    else modify(u<<1|1,x,v);
    pushup(u);
}

node query(int u,int l,int r)
{
     if(tr[u].l>=l&&tr[u].r<=r)return tr[u];
     int mid =tr[u].l+tr[u].r>>1;
     if(mid>=r)return query(u<<1,l,r);
     else if(mid<l)return query(u<<1|1,l,r);
     else
     {
        auto left = query(u << 1, l, r);
        auto right = query(u << 1 | 1, l, r);
        node res;
        pushup(res, left, right);
        return res;
     }
}


int main()
{   
    int n,m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    build(1, 1, n);

    int k, x, y;
    while (m -- )
    {
        scanf("%d%d%d", &k, &x, &y);
        if (k == 1)
        {
            if (x > y) swap(x, y);
            printf("%d\n", query(1, x, y).tmax);
        }
        else modify(1, x, y);
    }
    return 0;
}