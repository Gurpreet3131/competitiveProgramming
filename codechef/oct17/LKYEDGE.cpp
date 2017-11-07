#include <bits/stdc++.h>
using namespace std;
int ui[5002], vi[5002];
vector<vector<int> > adj;
vector<int> row;
int n = 10000, cycle = 0;
vector<vector<int> > mno;
vector<int> mrow;
int gmin, maxnode, bfsct = 0;
int vis[10001] = {0};

void dfsutil2(int u, int vis[], int ind, int minm, int maxm)
{
	if(u == ui[ind])
	{
		cycle = 1;
		//gmin = min(gmin, maxind);
		return;
	}
	vis[u] = bfsct;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		int mval = mno[u][i];
//		cout << "v = " << v << " mval = " << mval << endl;
		if(vis[v] < bfsct && mval >= minm && mval != ind && mval <= maxm)
		{
			//if(mval > maxind) maxind = mval;
			dfsutil2(v, vis, ind, minm, maxm);
			if(cycle == 1) return;
			//if(gmin <= ind + 1) return;
			//vis[v] = bfsct - 1;
		}
	}
}

void dfs(int ind, int minm, int maxm)
{
	int maxind = ind;
	dfsutil2(vi[ind], vis, ind, minm, maxm);
}
int main()
{
	int t; scanf("%d", &t);

	while(t--)
	{
		int m; scanf("%d", &m);
		int ans[m+1];
		maxnode = -1;
		for(int i = 1; i <= m; i++)
		{
			ans[i] = 0;
			scanf("%d%d", &ui[i], &vi[i]);
			maxnode = max(maxnode, max(ui[i], vi[i]));
		}
		adj.clear(); mno.clear();
		for(int i = 0; i <= maxnode; i++) 
			adj.push_back(row), mno.push_back(mrow);

		for(int i = 1; i <= m; i++)
		{
			int u = ui[i], v = vi[i];
			adj[u].push_back(v);
			mno[u].push_back(i);
			adj[v].push_back(u);
			mno[v].push_back(i);
		}

		for(int i = 1; i <= m; i++)
		{
			for(int j = i; j <= m; j++)
			{	
				// 1, j se start
				//cout << "start = " << i << ", " << j << endl;
				cycle = 0;
				for(int k = j; k <= m; k++)
				{
					bfsct++;
					dfs(j, i, k);
					if(cycle == 1) 
					{
						ans[j] += m + 1 - k;
						break;
					}
				}
				//if(cycle == 0) break;
				//gmin = m + 1;
				//bfsct++;
				//dfs(j, i);
				//ans[j] += m + 1 - gmin;
				//for(int l = 1; l <= m; l++) cout << ans[l] << " ";
				//	cout << endl;
			}
		}
		for(int i = 1; i <=m; i++)
		{
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
}