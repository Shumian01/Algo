#include<bits/stdc++.h>
using namespace std;
const int N =2e5+10;
int n,m,p;
struct node{
    int l,r;
    int val;
}tr[4*N];

void pushup(int u)
{
    tr[u].val=max(tr[u<<1].val,tr[u<<1|1].val);
}

void build(int u,int l,int r)
{
    tr[u]={l,r};
    if(l==r)//叶节点
    {
        return;
    }
    int mid =l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    pushup(u);    
}
void modify(int u,int x,int v)
{
    int l=tr[u].l,r=tr[u].r;
    if(r==x&&l==x)
    {
        tr[u].val=v;
        return;
    }
    int mid =l+r>>1;
    if(x<=mid)modify(u<<1,x,v);
    else modify(u<<1|1,x,v);
    pushup(u);
}
int query(int u,int l,int r)
{
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u].val;
    int mid =tr[u].l+tr[u].r>>1;
    int res=0;
    if(l<=mid)res=query(u<<1,l,r);
    if(r>mid)res=max(res,query(u<<1|1,l,r));
    return res;
}

int main()
{
    n=0;int last=0;
    cin>>m>>p;
    build(1,1,m);
    char op;int x;
    while(m--)
    {
        cin>>op>>x;
        if(op=='Q')
        {
            last=query(1,n-x+1,n);
            cout<<last<<endl;
        }
        else
        {
            modify(1,n+1,(1LL*last + x) % p);
            n++;  
        }

    }
    return 0;
}
