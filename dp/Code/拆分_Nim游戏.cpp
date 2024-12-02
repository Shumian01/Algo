#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N =110;

int f[N];

int sg(int x)
{
    if(f[x]!=-1)return f[x];
    unordered_set<int>st;
    for(int i=0;i<x;i++)
        for(int j=0;j<=i;j++)
            st.emplace(sg(i)^sg(j));
    for(int i=0;;i++)
        if(st.find(i)==st.end())return f[x]=i;



}

int main()
{
    int n;
    cin >> n;
    int res = 0;
    memset(f,-1,sizeof f);
    while (n--)
    {
        int x;cin>>x;
        res^=sg(x);
    }
    if(res)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
