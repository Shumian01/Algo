#include<bits/stdc++.h>
 using namespace std;
 const int N =1010;
 
int main()
{
    int n,l,r;
    cin>>n>>l>>r;
    multiset<int>st;
    for (int i = 0; i < n; i ++ ){int x;cin>>x;st.emplace(x);}

    for(auto x:st)cout<<x<<' ';
    
    
    return 0;
}