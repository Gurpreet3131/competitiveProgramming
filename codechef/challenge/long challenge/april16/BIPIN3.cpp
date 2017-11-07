#include<bits/stdc++.h>
using namespace std;
//#define mod 1000000007
int mod=1000000007;
long long int NoPowMod( int x, int y, int mod )
{
    long long int a = x % mod;
    long long int t = 1;
    while( y > 0 )
    {
        // Y is odd
        if( y & 1 )
        {
            t = (t * a) % mod;
        }
        y >>= 1;
        a = (a * a) % mod;
    }
    return(t);
}
int main()
{
    int t; 
    scanf("%d",&t);
    while(t>0)
    {
        long long int n,k;
        scanf("%lld%lld",&n,&k);
        long long int ways=k,p;
        p=NoPowMod(k-1,n-1,mod);
        ways*=p;
        if(ways>=mod) ways%=mod;
        printf("%lld\n",ways);
        t--;
    }
    return 0;
}