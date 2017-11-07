#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector< vector<int> > ad;
vector< vector< int > > ticketk;
vector< vector< long long int > > ticketw;
vector<int> row;
vector<int> trowk;
vector<long long int> troww;
long long int segtree[400001]={0};
long long int mincost[100001]={0};
int parent[100001]={0},depth[100001]={0};

int n,m;
long long int big=10000000000000000;
void buildsegtree(int s,int e,int nodenum)
{
	if(s==e)
	{
		segtree[nodenum]=big;
		return;
	}
	int mid=(s+e)/2;
	buildsegtree(s,mid,nodenum*2);
	buildsegtree(mid+1,e,nodenum*2+1);
	segtree[nodenum]= big;
}
void rangeUpdate(int l,int r,long long int newval,int s,int e,int nodenum)
{
	if(s>r || e<l) return;
	else if(s>=l && e<=r && s==e)
	{
		segtree[nodenum] = newval;;
	} 
	else
	{
		int mid=(s+e)/2;
		rangeUpdate(l,r,newval,s,mid,nodenum*2);
		rangeUpdate(l,r,newval,mid+1,e,nodenum*2+1);
		segtree[nodenum]=min(segtree[nodenum*2],segtree[nodenum*2+1]);
	}
}

long long int query(int l,int r,int s,int e,int nodenum)
{
	if(s>r || e<l) return big;
	else if(s>=l && e<=r) return segtree[nodenum];
	else
	{
		int mid=(s+e)/2;
		return min(query(l,r,s,mid,nodenum*2),query(l,r,mid+1,e,nodenum*2+1));
	}

}


void DFSUtil(int v, bool visited[])
{
    visited[v] = true;
	for(int i=0;i<ad[v].size();i++)
	{
		if(visited[ad[v][i]]==0)
		{
			int node=ad[v][i];
			depth[node]=depth[v]+1;
			for(int j=0;j<ticketk[node].size();j++)
			{
				long long int k= ticketk[node][j];
				long long int cost=ticketw[node][j];
				long long int addcost=big;
				if(depth[node]-1<=k) //
				{
					addcost=0;
				}
				else
				{
					addcost=query(depth[node]-k,depth[node]-1,1,n,1);
				}
				cost+=addcost;
				if(cost<mincost[node]) mincost[node]=cost;
			}
			rangeUpdate(depth[node],depth[node],mincost[node],1,n,1);
            DFSUtil(ad[v][i], visited);			
		}
		
	} 
	rangeUpdate(depth[v]+1,depth[v]+1,big,1,n,1);   
}
 
void DFS(int v)
{
    bool *visited = new bool[n+1];
    for (int i = 0; i <= n; i++)
        visited[i] = false;
 	
 	rangeUpdate(1,1,0,1,n,1);
    DFSUtil(v, visited);
}
int main()
{
	depth[1]=1; 
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++) mincost[i]=big;
	mincost[1]=0;
	for(int i=0;i<=n;i++) ad.push_back(row);
	for(int i=0;i<=n;i++) ticketk.push_back(trowk);
	for(int i=0;i<=n;i++) ticketw.push_back(troww);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		ad[v].push_back(u);
		parent[u]=v;
	}
	for(int i=1;i<=m;i++)
	{
		int v,k; long long int w;
		scanf("%d%d%lld",&v,&k,&w);
		ticketk[v].push_back(k);
		ticketw[v].push_back(w);
	}
	buildsegtree(1,n,1);
	DFS(1);
	int q; scanf("%d",&q);
	while(q-->0)
	{
		int city; scanf("%d",&city);
		printf("%lld\n",mincost[city]);
	}
	return 0;
}