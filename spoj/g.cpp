#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ipair;
vector<vector<pair<int, int> > > graph;
vector<pair<int, int> > row;
int ct = 0, inf = 1110000010;
int n, m,s, l;
int mark[1000000] = {0}, vis[1000000] = {0}, dist[1000000] = {0};
void dij2(int s)
{
	priority_queue<ipair, vector <ipair>, greater<ipair> > pq;
	for(int i = 1; i <= n; i++) dist[i] = inf;
	pq.push(make_pair(0, s));
	dist[s] = 0;

	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		for(int i = 0; i < graph[u].size(); i++)
		{
			int v = graph[u][i].first;
			int w = graph[u][i].second;
			if(dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}

void dij(int s)
{
	priority_queue<ipair, vector <ipair>, greater<ipair> > pq;
	for(int i = 1; i <= n; i++) dist[i] = inf;
	pq.push(make_pair(0, s));
	dist[s] = 0;

	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		vis[u] = 1;
		//cout << u << "  " << ct <<  endl;
		for(int i = 0; i < graph[u].size(); i++)
		{
			int v = graph[u][i].first;
			int w = graph[u][i].second;
			//cout << v << " "<< w << endl;
			//if(vis[v] == 1) continue;
			if(dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				if(dist[v] < l) pq.push(make_pair(dist[v], v));
			}
			if(dist[u] + w < l && vis[v] == 0)
			{
				pq.push(make_pair(dist[u] + w, v));
			}			
			else if(dist[u] + w == l && mark[v] == 0 && vis[v] == 0)
			{
				//cout << "node marked\n";
				//ct++;  
				mark[v] = 1;
			}
			else if(dist[u] + w > l) 
			{
				//cout << "creating node\n";
				graph.push_back(row);
				n++; mark[n] = 1; dist[n] = l;
				//cout << "adding " << u << " " << n << " " << v << endl;
    	   		graph[u].push_back(make_pair(n,l - dist[u]));
       			graph[n].push_back(make_pair(u, l - dist[u]));

       			graph[v].push_back(make_pair(n, dist[u] + w - l));
    	   		graph[n].push_back(make_pair(v,dist[u] + w - l));

       			vector<ipair>::iterator it;
       			it = find(graph[u].begin(), graph[u].end(), make_pair(v, w));
       			int pos = it - graph[u].begin();
       			graph[u].erase(graph[u].begin() + pos);
       			it = find(graph[v].begin(), graph[v].end(), make_pair(u, w));
       			pos = it - graph[v].begin();
       			graph[v].erase(graph[v].begin() + pos);
       			i--;
       			//ct++; 
			}
			
		}
	}
}

int main()
{
    cin >> n >> m >> s;
    for(int i = 0; i <= 4*n; i++) graph.push_back(row);
    for(int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    cin >> l;
    dij(s);
    dij2(s);
    for(int i = 1; i <= n; i++)
    {
    	//cout << i << " " << dist[i] << endl;
    	if(dist[i] == l) ct++;
    }
    cout << ct << endl;
    return 0;
}
