#include<bits/stdc++.h>
#define mod 1000000007
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
int main()
{
	long long int twop[100001]={0};
	twop[0]=1; 
	for(int i=1;i<100001;i++)
	{
		twop[i]=twop[i-1]*2;
		if(twop[i]>=mod) twop[i]%=mod;
		//printf("%lld\n",twop[i]);
	}
	int t; scanf("%d",&t);
	int pre[100001]={0};
	while(t>0)
	{
		long long int n,q,ways=1,res=0,totalres=0;
		scanf("%lld%lld",&n,&q);
		int u,v;
		int count=n-1;
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d",&u,&v);
			pre[v]=u;
		}

		for(int i=0;i<q;i++)
		{
			int x;
			scanf("%d%d%d",&u,&v,&x);
			int temp=v,flag=0; res=0; 
			while(temp!=u)
			{
				


			/*	if(pre[temp]!=pre2[temp] && pre[temp]==u);				
				else if(pre[temp]==u)
				{
					if(flag==0) 
					{
						res++; flag=1;
					}
				}
				else
				{
					res++;
				}
			*/	
				res++; 
				totalres++;
				int node=temp;
				temp=pre[temp];
				pre[node]=pre[u];
				ways*=twop[res-1];
				if(ways>=mod) ways%=mod;
			}
		}	
		ways*=twop[n-1-totalres];
		if(ways>=mod) ways%=mod;
		printf("%lld\n",ways);
		t--;
	}
	return 0;    
}
