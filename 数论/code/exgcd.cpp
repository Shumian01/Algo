int exgcd(int a,int b,int &x,int &y)
{
    if(b)
    {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=1LL *a/b*x;
    return d;
}