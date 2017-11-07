#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
long long int adj[1004][1004],cp[1001]={0};
int n,ct=0;
bool Bipartite(int src)
{
    int colorArr[n+2];
    for (int i = 1; i<=n; ++i)
        colorArr[i] = -1;
    colorArr[src] = 1;
    queue <int> q;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v = 1; v <=n; ++v)
        {
        	if(u==v) continue;
            if (adj[u][v] && colorArr[v] == -1)
            {
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
            else if (adj[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }
    return true;
}
void comp(int wt)
{
	int visited[n+2]={0},visc=0;
	for(int i=1;i<=n;i++) cp[i]=0;
	while(visc<n)
	{
		queue <int> q;
		for(int i=1;i<=n;i++)
		{
			if(visited[i]==0)
			{
				q.push(i);
				visc++; visited[i]=1;
				cp[i]=ct+1;
				break;
			}
		}
    	while (!q.empty())
    	{
        	int u = q.front();
        	q.pop();
 
	        for (int v = 1; v <=n; ++v)
    	    {
        		if(u==v) continue;
            	if (adj[u][v]==wt && visited[v] == 0)
    	        {
        	        visited[v] = 1;
        	        cp[v]=ct+1;
        	        visc++;
            	    q.push(v);
    	        }
        	}
    	}
    	ct++;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int m;
		ct=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				adj[i][j]=1;
			}
		}
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			adj[u][v]=0; adj[v][u]=0;
		}
		comp(0); 
		bool ans;
		//cout<<"count="<<ct<<endl;
		if(n<=2) ans=true;
		else if(ct>2) ans=false;
		else 
		{
			comp(1);
			int done[1001]={0};
			for(int i=1;i<=n;i++)
			{
				if(done[cp[i]]==1) continue;
				ans=Bipartite(i);
				done[cp[i]]=1;
				//cout<<i<<endl;
				if(ans==false) break;
			}
		}
		if(ans==true) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}