#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define mod 1000000007
using namespace std;
int main()
{
    int n; scanf("%d",&n);
    long long int a[100001]={0},b[100001]={0},c=0;
    long long int sum=0,suma=0,sumb=0;    
    long long int maxsum[100001]={0},maxa[100001]={0},maxb[100001]={0};
//,maxatill[100001]={0},maxbtill[100001]={0};    
    for(int i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);
		a[i]+=i;
		//maxatill[i]=max(maxatill[i-1],a[i]);	
		suma+=a[i]; if(suma>=mod) suma%=mod;
	}
    for(int j=1;j<=n;j++) 
	{
		scanf("%lld",&b[j]);
		b[j]+=j;	
		//maxbtill[j]=max(maxbtill[j-1],b[j]);
		sumb+=b[j]; if(sumb>=mod) sumb%=mod;
	}
	maxsum[1]=(suma*sumb); if(maxsum[1]>=mod) maxsum[1]%=mod;
	printf("%lld ",maxsum[1]);	
	suma=0; sumb=0;	
	for(int i=1;i<=n-1;i++)
	{
		maxa[i-1]=max(a[i],a[i+1]);
		suma+=maxa[i-1];
		if(suma>=mod) suma%=mod;
		maxb[i-1]=max(b[i],b[i+1]);
		sumb+=maxb[i-1];
		if(sumb>=mod) sumb%=mod;
	}
	maxsum[2]=(suma*sumb)%mod;
	printf("%lld ",maxsum[2]);
	int k=3;
	while(k<=n)
	{
		suma=0; sumb=0;	
		for(int i=0;i<=n-k;i++)
		{
			maxa[i]=max(maxa[i],maxa[i+1]);
			suma+=maxa[i];
			if(suma>=mod) suma%=mod;
			maxb[i]=max(maxb[i],maxb[i+1]);
			sumb+=maxb[i];
			if(sumb>=mod) sumb%=mod;
		}
		maxsum[k+1]=(suma*sumb)%mod;
		printf("%lld ",maxsum[k+1]);		
		k++;
	}
    return 0;    
}
