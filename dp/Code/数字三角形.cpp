#include<bits/stdc++.h>
using namespace std;

const int N=510;
const int INF=0x3f3f3f3f;

int a[N][N],f[N][N];
int n,m;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i+1;j++)
            f[i][j]=-INF;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>a[i][j];

    f[1][1]=a[1][1];

    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
            f[i][j]=max(f[i-1][j-1]+a[i][j],f[i-1][j]+a[i][j]);

    int res=-INF;
    for(int i=1;i<=n;i++)res=max(res,f[n][i]);

    cout<<res;


    return 0;
}