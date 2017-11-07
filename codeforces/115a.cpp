#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int pred[2001]={0},parent[2001]={0};
int main()
{
	int n,maxd=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&pred[i]);
		if(pred[i]!=-1)
		{
			parent[pred[i]]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(parent[i]==0)
		{
			int node=i,dep=0;
			while(pred[node]!=-1)
			{
				dep++;
				node=pred[node];
			}
			if(dep>maxd) maxd=dep;
		}
	}
	printf("%d\n",maxd+1);
	return 0;
}