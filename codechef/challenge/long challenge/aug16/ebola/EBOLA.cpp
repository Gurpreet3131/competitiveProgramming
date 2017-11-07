#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <stdlib.h>
#define inf 1000000009
int w[10001]={0};
int adj[10001][10001]={0};
int totaladj[10001]={0};
int main()
{
	srand(time(NULL));
	int n,m,k,s;
	scanf("%d%d%d%d",&n,&m,&k,&s);
	int tempk=k;
	for(int i=1;i<=n;i++) 
		scanf("%d",&w[i]);

	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u][totaladj[u]++]=v;
		adj[v][totaladj[v]++]=u;
		//adj[u][v]=1;
		//adj[v][u]=1;
	}
	int vac[505]={0},queue[100001]={0};
	int rear=0;
	int stack[100001]={0}, top=0;
	queue[rear++]=s; 
	int vdone[10001]={0},aff[10001]={0};
	aff[s]=1;
	for(int i=1;i<=k;i++)
	{
		int pos=rand()%n;
		if(pos==0) pos=n;
		int node,flag=0;
		long long int maxsum=0;
		for(int z=0;z<rear;z++) 
		{
			node = queue[z];
			for(int j=0;j<totaladj[node];j++)
			{
				int nn=adj[node][j];
				if(vdone[nn]==0 && aff[nn]==0)
				{
					long long int tempsum=0;
					for(int k=0;k<totaladj[nn];k++)
					{
						tempsum+=w[adj[nn][k]];
					}
					if(tempsum>maxsum)
					{
						maxsum=tempsum;
						//pos=nn;flag=1;
					}
				}
			}
		}
		/*if(flag==1)
		{
			vac[i]=pos;  vdone[pos]=1;
			for(int z=0;z<rear;z++) 
			{
				node = queue[z];
				for(int j=0;j<totaladj[node];j++)
				{
					int nn=adj[node][j];
					if(vdone[nn]==0 && aff[nn]==0)
					{
						stack[top++]=nn;
						aff[nn]=1;
					}
				}
			}
			for(int z=0;z<top;z++)
			{
				queue[z]=stack[z];
			}
			rear=top;
		}
		//*/
		vac[i]=pos,vdone[pos]=1;
	}
	printf("%d\n",k);
	for(int i=1;i<=k;i++)
	{
		printf("%d ",vac[i]);
	}
	return 0;
}