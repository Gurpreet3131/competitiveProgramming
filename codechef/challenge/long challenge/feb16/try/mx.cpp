#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int arr[100001],brr[100001],crr[100001],drr[100001],ans[100001];
int main()
{
	long long int n;
	scanf("%lld",&n);
	long long int i,j,k,sum1=0,sum2=0,l1=0,l2=0;
	for(i=1; i<=n;i++)
	{
		scanf("%lld",&k);
		arr[i]=i+k;
		sum1=((sum1%mod) +(arr[i]%mod) )%mod;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		brr[i]=i+k;
		sum2=((sum2%mod) +(brr[i]%mod) )%mod;
	}
	for(i=1;i<n;i++)
	{
		if(arr[i]<arr[i+1]) crr[i-1]=arr[i+1];
		else crr[i-1]=arr[i];
		l1+=crr[i-1];

		if(brr[i]<brr[i+1]) drr[i-1]=brr[i+1];
		else drr[i-1]=brr[i];
		l2+=drr[i-1];				
	}
	ans[1]=((l1%mod)*(l2%mod))%mod;
	
	for(i=1;i<n-2;i++)
	{
		if(crr[i]>=crr[i+1] && crr[i]>=crr[i-1]) crr[i-1]=crr[i];
		if(drr[i]>=drr[i+1] && drr[i]>=drr[i-1]) drr[i-1]=drr[i];
	}
	long long int temp1=0,temp2=0;
	j=n-1;
	ans[0]=((sum1%mod)*(sum2%mod))%mod;
	sort(crr,crr+(n-1));
	sort(drr,drr+(n-1));
	for(i=n-2;i>=0;i--)
	{
		temp1=((temp1%mod)+(crr[i]%mod));
		temp2=((temp2%mod)+(drr[i]%mod));
		ans[j--]=( (temp1%mod)* (temp2%mod))%mod;	
	}
	for(j=0;j<n;j++) printf("%lld ",(ans[j]%mod));
	return 0;
}
