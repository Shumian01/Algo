#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e6+10;


vector<long long>phi;
vector<int>primes,minp;
void sieve(int n)
{
    phi.assign(n+1,0);
    minp.assign(n+1,0);
    primes.clear();
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(minp[i]==0)
        {
            minp[i]=i;
            phi[i]=i-1;
            primes.push_back(i);
        }
        for(auto p:primes)
        {
           if(p*i>n)break;
            minp[p*i]=p;
            if(minp[i]==p)
            {
                phi[p*i]=phi[i]*p;
                break;
            }
            else
            {
                phi[p*i]=phi[i]*(p-1);
            }
        }
    }
}

int main()
{
   


   
   return 0;
}
