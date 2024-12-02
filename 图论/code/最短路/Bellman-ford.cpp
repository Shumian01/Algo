#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 510;
const int M =10010;
int n,m,k;
int dist[N],backup[N];
struct edge
{
   int a,b,w;
}edges[M];

int bellman_ford()
{
   memset(dist,0x3f,sizeof dist);
   dist[1]=0;
   for(int i=1;i<=k;i++)
   {
      memcpy(backup,dist,sizeof dist);
      for(int j=1;j<=m;j++)
      {
         int a=edges[j].a,b=edges[j].b,w=edges[j].w;
         dist[b]=min(dist[b],backup[a]+w);

      }

   }
   
   if(dist[n]>0x3f3f3f3f /2)return 0;
    else return dist[n];



}

int main()
{
   cin>>n>>m>>k;
   for(int i=1;i<=m;i++)
   {   
      int a,b,c;
      cin>>a>>b>>c;
      edges[i]={a,b,c};
   }

   int t =bellman_ford();
    if(t)cout<<t<<endl;
    else
    cout << "impossible"<<endl;

   return 0;
}
