// tle without segment tree
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

long long int mincost[100001]={0};
int parent[100001]={0},depth[100001]={0};
int n,m;
long long int big=10000000000000000;
void solve()
{
	queue<int> qu;
	mincost[1]=0;
	for(int i=0;i<ad[1].size();i++)
	{
		qu.push(ad[1][i]);
		depth[ad[1][i]]=depth[1]+1;
	}
	while(!qu.empty())
	{
		
		int node = qu.front();
		//cout<<node<<endl;
		qu.pop();
		long long int cost; 
		for(int i=0;i<ticketk[node].size();i++)
		{
			long long int k= ticketk[node][i];
			long long int cost=ticketw[node][i];
			long long int addcost=big;
			if(depth[node]<=k)
			{
				addcost=0;
			}
			else
			{
				long long int count=0,temp=node;
				while(count<k)
				{
					temp=parent[temp];
					//cout<<temp<<" "<<mincost[temp]<<endl;
					if(mincost[temp]<addcost) addcost=mincost[temp];
					//cout<<addcost<<endl;
					count++;
				}
			}
			cost+=addcost;
			//cout<<cost<<endl;
			if(cost<mincost[node]) mincost[node]=cost;
		}
		for(int i=0;i<ad[node].size();i++)
		{
			qu.push(ad[node][i]);
			depth[ad[node][i]]=depth[node]+1;
		}
	} 
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++) mincost[i]=big;
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
	solve();
	//for(int i=1;i<=n;i++) cout<<i<<" "<<mincost[i]<<endl;
	int q; scanf("%d",&q);
	while(q-->0)
	{
		int city; scanf("%d",&city);
		printf("%lld\n",mincost[city]);
	}
	return 0;
}