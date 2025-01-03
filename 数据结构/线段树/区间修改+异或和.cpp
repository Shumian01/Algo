#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 2e5+10;

int n, m;
int w[N];
struct Node
{
    int l, r;
    LL sum, add;
}tr[N * 4];

void update(int u,int add)
{   
    int l=tr[u].l,r=tr[u].r;
    tr[u].add^=add;
    tr[u].sum^=((r-l+1)&1)?add:0;

}
void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum ^tr[u << 1 | 1].sum;
}

void pushdown(int u)
{
    if(tr[u].add)
    {   
        int add=tr[u].add;
        update(u<<1,add),update(u<<1|1,add);
        tr[u].add=0;
    }
}

void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, w[r], 0};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int d)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].sum ^= ((tr[u].r - tr[u].l + 1)&1)?d:0;
        tr[u].add ^= d;
    }
    else    // 一定要分裂
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, d);
        if (r > mid) modify(u << 1 | 1, l, r, d);
        pushup(u);
    }
}

LL query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    LL sum = 0;
    if (l <= mid) sum ^= query(u << 1, l, r);
    if (r > mid) sum ^= query(u << 1 | 1, l, r);
    return sum;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);

    build(1, 1, n);

    int op;
    int l, r, d;

    while (m -- )
    {
        cin>>op>>l>>r;
        if (op ==1)
        {
            cin>>d;
            modify(1, l, r, d);
        }
        else printf("%lld\n", query(1, l, r));
    }

    return 0;
}