#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,m,p;
int w[N];
struct node{
    int l,r;
    int sum,add,mul;
}tr[N<<2];
void pushup(int u)
{
    tr[u].sum=(tr[u<<1|1].sum+tr[u<<1].sum)%p;
}
void go(node &root,int add,int mul)
{
    root.sum=(1LL*root.sum*mul%p+1LL*(root.r-root.l+1)*add)%p;
    root.mul=1LL*root.mul*mul%p;
    root.add=(1LL*root.add*mul+add)%p;
}
void pushdown(int u)
{
    go(tr[u<<1],tr[u].add,tr[u].mul);
    go(tr[u<<1|1],tr[u].add,tr[u].mul);
    tr[u].add = 0, tr[u].mul = 1;
}
void build(int u, int l, int r)
{
    if (l == r)
    {
        tr[u] = {l, r, w[r], 0, 1};
        return;
    }
        tr[u] = {l, r, 0, 0, 1};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    
}
void modify(int u,int l,int r,int add,int mul)
{
    if(tr[u].l>=l&&tr[u].r<=r)
    {
        go(tr[u],add,mul);
        return;
    }
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if(l<=mid)modify(u<<1,l,r,add,mul);
    if(r>mid) modify(u<<1|1,l,r,add,mul);
    pushup(u);
}
int query(int u,int l,int r)
{
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u].sum%p;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int res=0;
    if(l<=mid)res=query(u<<1,l,r);
    if(r>mid)res=(res+query(u<<1|1,l,r))%p;
    return res;
}


int main()
{

    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);
    build(1, 1, n);

    scanf("%d", &m);
    while (m -- )
    {
        int t, l, r, d;
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1)
        {
            scanf("%d", &d);
            modify(1, l, r, 0, d);
        }
        else if (t == 2)
        {
            scanf("%d", &d);
            modify(1, l, r, d, 1);
        }
        else cout<<query(1, l, r)<<endl;
    }

    return 0;
}

