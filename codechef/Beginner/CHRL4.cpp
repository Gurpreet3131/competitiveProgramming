#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
  	int n,k; scanf("%d%d",&n,&k);
   	long long int value[100001]={0};
    double minv[100001]={0};
   	for(int i=0;i<n;i++)
   	{
   		scanf("%lld",&value[i]);
   	}
   	long long int product[100001]={0};
   	product[0]=value[0];
   	minv[0]=log(value[0]);
    long long int mini=0;
   	for(int i=1;i<k;i++)
   	{
   		minv[i]=log(value[i])+minv[0];
  		product[i]=(product[0]*value[i])%mod;
    }
   	for(int i=k;i<n;i++)
   	{
   		product[i]=(product[mini]*value[i])%mod;
        minv[i]=minv[mini]+log(value[i]);
   		if(minv[mini]>minv[i]) mini=i;
   		else if(i-k==mini)
   		{
   			mini=i;
   			for(int j=i;j>i-k;j--)
   			{
   				if(minv[mini]>minv[j]) mini=j;
   			}
   		}
   	}
   	printf("%lld\n",product[n-1]);   
  	return 0;
} 