#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;
int a[N],f[N];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    
    int len=1;
    f[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]>f[len])f[++len]=a[i];
        else
        {
            int l=1,r=len;
            while(l<r)
            {
                int mid=l + r>>1;
                if(f[mid]>=a[i])r=mid;
                else l=mid+1;
            }
            f[l]=a[i];
        }
    }
    cout<<len<<endl;
    return 0;
}