#include<bits/stdc++.h>
std::vector<int>minp,primes;

void sieve(int n)
{   

    primes.clear();
    minp.assign(n+1,0);
    for(int i=2;i<=n;i++)
    {
        if(minp[i]==0)
        {
            minp[i]=i;
            primes.push_back(i);
        }
        for(auto p:primes)
        {
            if(i*p>n)break;
            minp[i*p]=p;
            if(minp[i]==p)break;
        }
    }
}