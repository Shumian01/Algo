#include<bits/stdc++.h>
using namespace std;

const int N=1010;
int dp[N][N];
int main()
{
    int n,m;cin>>n>>m;
    vector<int>v(n+1),w(n+1);
    multiset<int>st;
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
        {      dp[i][j]=dp[i-1][j];
                if(j>=v[i])
                dp[i][j]=max(dp[i-1][j],dp[i][j-v[i]]+w[i]);
        }
    cout<<dp[n][m]<<endl;
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// const int N=1010;
// int dp[N][N];
// int main()
// {
//     int n,m;cin>>n>>m;
//     vector<int>v(n+1),w(n+1);
//     for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++)
//         {   
//             dp[i][j]=dp[i-1][j];
//             for(int k=0;k*v[i]<=j;k++)
//                 dp[i][j]=max(dp[i][j],dp[i-1][j-k*v[i]]+k*w[i]);
//         }
//     cout<<dp[n][m]<<endl;
//     return 0;
// }