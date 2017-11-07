#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <cmath>
#define inf 1000000009
using namespace std;
int storage[100001]={0},mindist[100001]={0};
int u[100001],v[100001],l[100001];
int main()
{
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=n;i++) mindist[i]=inf;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&l[i]);		
	}
	for(int i=0;i<k;i++)
	{
		int st; 
		scanf("%d",&st);
		storage[st]=1;
	}
	if(k==0)
	{
		printf("-1\n");
	}
	else
	{
		for(int i=0;i<m;i++)
		{
			if(storage[u[i]]==1 || storage[v[i]]==1)
			{
				if(storage[u[i]]==1 && storage[v[i]]==1) continue;
				if(storage[u[i]]==1)
				{
					if(l[i]<mindist[u[i]]) mindist[u[i]]=l[i];
				}		
				else if(storage[v[i]]==1)
				{
					if(l[i]<mindist[v[i]]) mindist[v[i]]=l[i];
				}		
			}
		}
		long long int mini=inf;
		for(int i=1;i<=n;i++)
		{
			if(storage[i]==1)
			{
				if(mindist[i]<mini) mini=mindist[i];
			}
		}
		if(mini>=inf) printf("-1\n");
		else printf("%lld\n",mini);
	}
	return 0;
}