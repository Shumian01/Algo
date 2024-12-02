#include<bits/stdc++.h>
using namespace std;
using LL =long long;
const int N=1e5+10;
int sx[N];

/*离散化分为两种：

1、需要保持原来的序列顺序的（大的数离散化后的数也大,小的小）

这时候要用 排序 判重 二分

2、不需要保持原来的序列顺序( 最大的数离散化后也有可能排第一位）

这时候只需要使用 map 哈希表 */


//1.保序离散化
//设sx[N]为离散化数组,cnt为离散化的数量

int get(LL x)//二分法求离散化后数的位置下标
{
    int l=1,r=cnt;
    while(l<r)
    {
        int mid=l+r>>1;
        if(sx[mid]>=x)r=mid;
        else l=mid+1;
    }
    return l;
}
/*
for(int i=1;i<=n;i++)//离散化存储
{
        sx[++cnt]=a[i];
}

sort(sx+1,sx+1+cnt);//离散化排序
cnt=unique(sx+1,sx+1+cnt)-sx-1;//离散化去重
*/



//2.不保序离散化
unordered_map<int,int> S;//哈希表离散化
int cnt=0;//离散化数量
int get(int x)
{
    if(!S.count(x))S[x]=++cnt;
    return S[x];
}