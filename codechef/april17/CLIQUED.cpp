#include <bits/stdc++.h>
using namespace std;
typedef pair<long long int , int> ipair;
int main()
{
	int t; scanf("%d",&t);
	long long int inf = 100000000000000000;
	while(t--)
	{
		int n,m,s;
		long long int x,k;
		scanf("%d%lld%lld%d%d",&n,&k,&x,&m,&s);
		int vis[n+1] = {0}, kdone = 0;


		priority_queue< ipair, vector<ipair>, greater<ipair> >pq;
		vector<long long int> dist(n+1,inf);
		vector< vector< pair<int, long long int> > > adj(100002);
		
		pq.push(make_pair(0,s));
		dist[s] = 0;

		for(int i=0;i<m;i++)
		{
			int u,v;
			long long int w;
			scanf("%d%d%lld",&u,&v,&w);
			adj[u].push_back(make_pair(v,w));
			adj[v].push_back(make_pair(u,w));
		} 
		while(!pq.empty())
		{
			int u = pq.top().second;
			pq.pop();
			vis[u] = 1;
			if(u<=k && kdone == 0)
			{
				for(int j=1; j<=k; j++)
				{
					if(dist[j] > dist[u] + x && vis[j] == 0)
					{
						dist[j] = dist[u] + x;
						pq.push(make_pair(dist[j],j));
					}	
				}
				kdone = 1;
			}
			for(int j=0;j<adj[u].size();j++)
			{
				int v = adj[u][j].first;
				long long int w = adj[u][j].second;
				
				if(dist[v] > dist[u] + w && vis[v] == 0)
				{
					dist[v] = dist[u] + w;	
					pq.push(make_pair(dist[v],v));					
				}
			}		
		}
		for(int i=1;i<=n;i++)
		{
			printf("%lld ",dist[i]);
		}
		printf("\n");
	}
	return 0;
}