#include<bits/stdc++.h>
typedef long long int LL;
using namespace std;
#define MOD 1000000007
LL dp1[5009][5009]={};
char per[1000001];
int main()
{
    LL i,j,sum;
    LL fac[5009]={};
    fac[0]=1;
    for(i=1; i<=5000; i++)
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
            if(dp1[i][j]>=MOD) dp1[i][j]%=MOD;
        }
    int t; cin>>t;
    char s[100001]; 
    while(t>0)
    {
        cin>>s;
        int count[26]={0},flag=0;
        for(int i=0;i<26;i++)
        {
            count[s[i]-'a']++;
        }
        int n=strlen(s),dist=0;
        long long int totalpairs=fac[n]; //3628800    //
        for(int i=0;i<26;i++)       //226800                  sjdkajsdkf      823011840000
        {
            if(count[i]>0) dist++;
            if(count[i]>1) 
            {
                flag=1;
                totalpairs/=fac[count[i]];
            }
        }
        long long int similar=totalpairs,sim=0;
       // if(totalpairs>=MOD) totalpairs%=MOD;
        if(flag==0)
        {
            if(n<=2) sim=fac[n];
           else sim=dp1[n][3];
        }
        else
        {
            if(n<=2) sim=fac[n];
            else 
            {
                sim=dp1[dist][3];
                for(int i=0;i<26;i++)       //226800                  sjdkajsdkf      823011840000
                {
                    if(count[i]>1) 
                    {
                        sim*=count[i];
                    }
                }
            }
        }
      //  for(int i=0;i<26;i++)
     //   {
       //     if(count[i]>1) similar/=fac[count[i]];   //207748800
      //  }
        totalpairs=totalpairs-sim;
        if(totalpairs>=MOD) totalpairs%=MOD;
        long long int answer=similar*totalpairs;
       // if(similar>=MOD) similar%=MOD;
        //long long int answer=totalpairs-similar;
        if(answer>=MOD) answer%=MOD;
        printf("%lld\n",answer);  //822804091200
        t--;
    }
    
    return 0;
}
