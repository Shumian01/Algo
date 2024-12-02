#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 10;
// 节点数据结构
struct node {
    int l, r;
    int val;
    int lazy;
} t[4 * maxn + 2];

// 记录原始数据
int a[maxn + 2];

// 建树
void build(int u, int l, int r) {
    t[u]={l,r};
    if (l == r)//叶结点返回
    {
        t[u].val = a[l];
        return;
    }
    int mid = (l + r) / 2;//不是叶结点继续分裂 向左右递归
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
    pushup(u);
}
// 单点修改
void modify(int u, int x,int y) {  // u为节点编号，x为要修改的位置，y为要修改的值
    if (t[u].l == t[u].r) 
    {
        t[u].val = y;
        return;
    }
    int mid = (t[u].l + t[u].r) / 2;
    if (x <= mid)
        modify(u * 2, x, y);
    else
        modify(u * 2 + 1, x, y);
    pushup(u);
}
// 更新子节点
void pushdown(int u) {
    // 将lazy标记向下传给左右孩子节点
    t[u * 2].lazy += t[u].lazy;
    t[u * 2 + 1].lazy += t[u].lazy;
    // 更新左右孩子节点的值，为lazy标记×孩子节点表示的区间长度，记得减1
    t[u * 2].val += t[u].lazy * (t[u * 2].r - t[u * 2].l + 1);
    t[u * 2 + 1].val += t[u].lazy * (t[u * 2 + 1].r - t[u * 2 + 1].l + 1);
    // 清除该节点的lazy标记，防止重复更新
    t[u].lazy = 0;
}

// 更新父节点
void pushup(int u) { t[u].val = t[u * 2].val + t[u * 2 + 1].val; }

// 区间修改
void modify2(int u, int l, int r, int x)// x为要求区间修改的值
{  
    // 找到子区间，则不需要向下寻找
    if (l <= t[u].l && t[u].r <= r) {
        t[u].lazy += x;
        t[u].val += x * (t[u].r - t[u].l + 1);
        return;
    }
    // 若区间分布在节点表示的区间两侧，则分别查找左右孩子表示的区间
    int mid = (t[u].l + t[u].r) / 2;
    // 需要查找孩子节点，要将lazy标记向下传递
    pushdown(u);
    if (l <= mid) modify2(u * 2, l, r, x);
    if (mid < r) modify2(u * 2 + 1, l, r, x);
    // 修改完成后要记得更新父节点的值
    pushup(u);
}
// 区间查询
int query(int u, int L, int R) {
    // 若不在节点表示的区间内，则找不到
    if (t[u].l > R || t[u].r < L) return 0;
    // 若节点正好是要查询的子区间，则直接返回该节点的值
    if (t[u].l >= L && t[u].r <= R) return t[u].val;
    // 若要查找的区间分布在节点表示的区间两侧，则递归分别查找
    // 记得传递lazy标记，更新孩子节点的值
    pushdown(u);
    return query(u * 2, L, R) + query(u * 2 + 1, L, R);
}
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
        int op = 0;
        cin >> op;
        if (op == 1) {
            int L, R, X;
            cin >> L >> R >> X;
            modify2(1, L, R, X);
        } else {
            int L, R;
            cin >> L >> R;
            cout << query(1, L, R)<<endl;
        }
    }
    
}