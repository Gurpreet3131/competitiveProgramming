#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#define min(a,b) a<b?a:b
using namespace std;
long long int beauty[100002]={0};
long long int capital[100002]={0};
int main()
{
	int n,k;
	long long int sum=0;	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&beauty[i]);
		sum+=beauty[i];
	}
	for(int i=1;i<=k;i++)
	{
		int cap;
		scanf("%d",&cap);
		capital[cap]=1;
	}
	long long int answer=0;
	for(int i=1;i<=n;i++)
	{
		if(i==n)
		{
			if(capital[i]==0)
			{
				if(capital[1]==0)
				{
					answer+=beauty[i]*beauty[1];
				}
			}
			else
			{
				answer+=beauty[i]*(sum-beauty[i]);
			}
		}
		else
		{
			if(capital[i]==0)
			{
				if(capital[i+1]==0)
				{
					answer+=beauty[i]*beauty[i+1];
				}
			}
			else
			{
				answer+=beauty[i]*(sum-beauty[i]);
				sum-=beauty[i];
			}	
		}
	}
	printf("%lld\n",answer);
	return 0;
}