#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
#define MOD 1000000007ll
#define assn(n,a,b) assert(n<=b && n>=a)
LL dp[5009][5009]={};
LL dp1[5009][5009]={};
int main()
{
    LL i,j,sum;
    dp[1][0] = 1;
    for(i = 2; i < 5001; ++i)
        for(j = sum = 0; j < 5001; ++j)
        {
            sum+=dp[i-1][j];
            if(sum>=MOD)sum-=MOD;
            if(j>=i)sum-=dp[i-1][j-i];
            if(sum<0)sum+=MOD;
            dp[i][j]=sum;
        }
    LL fac[5009]={};
    fac[0]=1;
    for(i=1; i<=5000ll; i++)
        fac[i]=(fac[i-1]*i)%MOD;
    for(i=1; i<=5000; i++)
    {
        dp1[i][1]=1;
        dp1[i][i]=fac[i];
    }
    for(i=2; i<5001; ++i)
        for(j=2; j<i; ++j)
        {
            dp1[i][j]=((i-1)*dp1[i-1][j-1])%MOD;
            dp1[i][j] += dp1[i-1][j];
            if(dp1[i][j]>=MOD)dp1[i][j]-=MOD;
        }
        for(int i=1;i<20;i++) cout<<i<<"="<<dp1[i][3]<<endl;
    int n,k;
    cin >> n >> k;
    assn(n,1,5000);
    assn(k,1,5000);
    LL ans=0;
    for(i=0; i<=k; i++)
        if((i&1)==(k&1))
        {
            ans += dp[n][i];
            if(ans >= MOD)ans-=MOD;
        }
    cout << ans << " " ;
    if(k>=n)cout << fac[n] << endl;
    else
        cout << dp1[n][k+1] << endl;
    return 0;
}