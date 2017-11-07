#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define mod 786433
long long int ans[786434];
long long int pow2[786434]={0};
int occur[786434]={0};
int main()
{
    
    pow2[1]=10;
    occur[10]=1;
    for(int i=2;i<786433;i++)
    {
        pow2[i]=(10*(pow2[i-1]))%mod;
        //if(i<50) cout<<i<<" "<<pow2[i]<<endl;
        occur[pow2[i]]++;
    }
    for(int i=0;i<786433;i++)
    {
       if(occur[i]!=1) 
        cout<<i<<" "<<occur[i]<<endl;
    }
    return 0;

	long long int cof[250005]={0},sumall=0;
    int n,q;
	scanf("%d",&n);
    for(int i=0;i<=n;i++)
	{
	    scanf("%lld",&cof[i]);
       sumall+=cof[i];
    }
	long long int x,value,sq=sqrt(786433);
    for(int i=0;i<786433;i++) ans[i]=-1;
    ans[0]=cof[0];
    ans[1]=sumall;
    cout<<0<<" "<<ans[0]<<endl;
    cout<<1<<" "<<ans[1]<<endl;
    for(int i=2;i<=887;i++)
    {
        if(ans[i]==-1)
        {
            for(int j=n-1;j>=0;j--)
            {
                for(int k=1;i*k<786433;k++)
                {   
                    x=i*k;
                    if(j==n-1) ans[x]=cof[n];
                    ans[x]*=x;
                    if(ans[x]>=mod) ans[x]%=mod;
                    ans[x]+=cof[j];
                   // if(x==7) cout<<x<<" "<<ans[x]<<endl;
                    if(ans[x]>=mod) ans[x]%=mod;
                } 
            }
        }
        if(i<100) cout<<i<<" "<<ans[i]<<endl;
    }
	scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%lld",&x);
        if(ans[x]==-1)
        {
            value=cof[n];
            for(int j=n-1;j>=0;j--)
            {
                value*=x;
                if(value>=mod) value%=mod;
                value+=cof[j];
                if(value>=mod) value%=mod;
            }
            ans[x]=value;
        }
        printf("%lld\n",ans[x]);
    }
    return 0;
}

