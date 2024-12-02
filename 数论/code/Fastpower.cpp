#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e6+10;
const int MOD =1e9+7;
int fastpower(int a,int k,int p)
{
    int res=1;
    while(k)
    {
        if(k&1)res=1LL *res *a %p;
        k>>=1;
        a=1LL *a*a%p;
    }
    return res;
}

int main()
{
   LL a;

   return 0;
}
