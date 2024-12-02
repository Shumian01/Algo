#include<bits/stdc++.h>
using namespace std;

const int N =10010;
int s[N],F[N];
int k;

int sg(int x)
{
    if(F[x]!=-1)return F[x];
    unordered_set<int>st;//存x可以到的所有局面
    for(int i=0;i<k;i++)
    {
        int sum=s[i];
        if(x>=sum)st.emplace(sg(x-sum));
    }
    for(int i=0;;i++)
    if(!st.count(i))return F[x]=i;


}

int main()
{   

    cin>>k;
    for(int i=0;i<k;i++)cin>>s[i];
    int n;
    cin>>n;
    int res=0;
    memset(F,-1,sizeof F);
    while(n--)
    {
        int x;cin>>x;
        res^=sg(x);
    }
    if(res)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}