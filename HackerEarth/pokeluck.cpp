#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <cmath>
using namespace std;
int main()
{
	int a,b; 
	int adj[1001][1001]={0},luck[1001]={0},index[1001]={0};
	luck[1]=0;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u][index[u]++]=v;
		adj[v][index[v]++]=u;
	}
	int queue[1001],rear=0,front=0;
	queue[rear++]=1;
	while(front<rear)
	{
		int node=queue[front++];
		for(int i=0;i<index[node];i++)
		{
			int nod=adj[node][i];
			if(luck[nod]==0) luck[nod]=luck[node]+1,queue[rear++]=nod;
			else
			{
				luck[nod]=min(luck[nod],luck[node]+1);
			}
		}
	}
	for(int i=2;i<=a;i++) printf("%d\n",luck[i]);
	return 0;
}