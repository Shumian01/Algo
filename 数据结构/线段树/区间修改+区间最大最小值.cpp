    #include<bits/stdc++.h>
    using namespace std;
    const int N = 2e5 + 10;
    using ll = long long;
    int w[N];  // 定义 w 数组，用于存储输入的数值
    struct node {
        int l, r;
        ll mi, mx, add;
    } tr[N << 2];

    void pushup(int u) {
        tr[u].mi = min(tr[u << 1].mi, tr[u << 1 | 1].mi);
        tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
    }

    void update(int u, ll x) {
        tr[u].mi += x;
        tr[u].mx += x;
        tr[u].add += x;
    }

    void pushdown(int u) {
        if (tr[u].add) {
            update(u << 1, tr[u].add);
            update(u << 1 | 1, tr[u].add);
            tr[u].add = 0;
        }
    }

    void build(int u, int l, int r) {
        if (l == r) {
            tr[u] = {l, r, w[l], w[r], 0};
            return;
        }
        tr[u] = {l, r};
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void modify(int u, ll x, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            update(u, x);
            return;
        }
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) modify(u << 1, x, l, r);
        if (r > mid) modify(u << 1 | 1, x, l, r);
        pushup(u);
    }

    ll query1(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u].mx;
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        ll res = -2e18;
        if (l <= mid) res = max(res, query1(u << 1, l, r));
        if (r > mid) res = max(res, query1(u << 1 | 1, l, r));
        return res;
    }

    ll query2(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u].mi;
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        ll res = 2e18;
        if (l <= mid) res = min(res, query2(u << 1, l, r));
        if (r > mid) res = min(res, query2(u << 1 | 1, l, r));
        return res;
    }

    int main() {                
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> w[i];

        build(1, 1, n);

        while (m--) {
            int op, l, r;
            ll d;
            cin >> op >> l >> r;
            if (op == 1) {
                cin >> d;
                modify(1, d, l, r);
            } else {
                cout << query1(1, l, r) << " ";
                cout << query2(1, l, r) << endl;
            }
        }

        return 0;
    }
