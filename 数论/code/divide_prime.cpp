#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e6+10;

void divide_prime(int n)
{
    for(int i=2;i<=n/i;i++)
    {   
        int s=0;
        if(n%i==0)
        {    
            int s=0;
            while(n%i==0)
            {
                n/=i;
                s++;
            }
        }
        cout<<i<<' '<<s<<endl;

    }
    if(n>1)cout<<n<<' '<<1<<endl;

}


int main()
{
   int n;cin>>n;
    while(n--)
    {
        int x;cin>>x;divide_prime(x);
    }

   return 0;
}