#include<bits/stdc++.h>
using namespace std;

const int N=1010;
int dp[N];
int main()
{
    int n,m;cin>>n>>m;
    vector<int>v(n+1),w(n+1);
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];

    for(int i=1;i<=n;i++)
        for(int j=m;j>=v[i];j--)
        {
            if(j>=v[i])
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    
    cout<<dp[m]<<endl;
    return 0;
}