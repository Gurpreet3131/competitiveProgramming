#include <bits/stdc++.h>
using namespace std;
int dist[15][15],en[15][15];
int n,m,totale,flag=0;
int visited[15]={0},mindist=1000000000;
void dfs(int start, int visited[], int visc, int eleft,int dd)
{
	int f=0;
	if(dd>mindist) return;
	if(visited[start]==0)
	{
		f=1;
		visited[start]=1; visc++;
	}
	if(visc==n) 
	{
		if(dd<mindist)
		{
			mindist=dd; flag=1;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(dist[start][i]>0 && en[start][i]<=eleft)
		{
			dfs(i,visited,visc,eleft-en[start][i],dd+dist[start][i]);
		}
	}
	if(f==1)
	{
		visc--; visited[start]=0;
	} 
}
int k()
{
	int mind[n+1][totale+1];

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dist[i][j] == 0) mind[i][j]=mindist;
			else if(en[i][j]<=totale)
				mind[i][j] = 
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&totale);
	for(int i=0;i<m;i++)
	{
		int u,v,d,e;
		scanf("%d%d%d%d",&u,&v,&d,&e);
		dist[u][v]=d; dist[v][u]=d;
		en[u][v]=e; en[v][u]=e;
	}

	dfs(1,visited,0,totale,0);
	if(flag==0) printf("-1\n");
	else printf("%d\n",mindist);
	return 0;
}