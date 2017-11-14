#include <bits/stdc++.h>
using namespace std;
vector<int > adj[100001];
int bank[100001] = {0};
int vis[100001] = {0}, visct = 1;
int max1 = -1, max2 = -1, ans = -1;
void dfs(int u, int flag)
{
	//cout << "u = " << u << endl;
	if(flag == 1)
	{
		if(u > max1)
		{
			max2 = max1; max1 = u;
		}
		else if(u > max2)
		{
			max2 = u;
		}	
	}
	vis[u] = visct;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(vis[v] == visct) continue;
		if(bank[v] == 1)
		{
			dfs(v, 1);
		}
		else dfs(v, flag);
	}
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n, m; scanf("%d%d",&n,&m);
		memset(bank, 0, sizeof(bank));
		memset(vis, 0, sizeof(vis));
		visct = 1;
		for(int i = 1; i <= n; i++)
		{
			adj[i].clear();
		}
		for(int i = 0; i < n - 1; i++)
		{
			int u, v; scanf("%d%d",&u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i = 0; i < m; i++)
		{
			int type,c; scanf("%d%d", &type, &c);
			if(type == 1)
			{
				bank[c] = 1;
			}
			else
			{
				max1 = -1; max2 = -1; ans = -1;
				if(bank[c] == 1)
				{
					ans = n - 1;
				}
				else
				{
					dfs(c, 0); visct++;
					ans = min(max1, max2);
				}
				//cout << max1 << " " << max2 << endl;
				printf("%d\n",ans);	
			}
		}
	}
}