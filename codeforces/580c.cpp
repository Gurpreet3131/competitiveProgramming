#include <iostream>
#include <cstdio>
using namespace std;
int cat[100001]={0};
int pred[100001]={0},parent[100001]={0};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&cat[i]);	
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		pred[v]=u;
		parent[u]=1;
	}
	int count=0,cats=0;
	if(n==1) printf("1\n");
	else
	{	
		for(int i=1;i<=n;i++)
		{
			if(parent[i]==0)
			{
				int node=i,flag=1;
				while(node!=0)
				{		
					if(cat[node]==1) cats++;
					else cats=0;					
					node=pred[node];
					if(cats>m) { flag=0; break; }
				}			
				if(flag==1) count++;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}