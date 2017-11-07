#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> > tree;
vector <int> row;
long long int top[200001];
long long int val[200001];
void dfs(int node, int visited[])
{
	visited[node] = 1;

	for(int i = 0; i < tree[node].size(); i++)
	{
		int newnode = tree[node][i];
		if(visited[newnode] == 0)
		{
			dfs(newnode, visited);
			val[node] ^= val[newnode];
		}	
	}
}

void dfsutil(int root)
{
	int visited[n];
	for(int i = 0; i < n; i++) visited[i] = 0;
	dfs(root, visited);	
}
int main()
{
	int q; scanf("%d%d",&n, &q);
	
	for(int i = 0; i <n; i++)
		tree.push_back(row);

	for(int i = 0; i < n - 1; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%lld", &val[i]);
		top[i] = val[i]; //comment it
	}
	top[0] = val[0];
	long long int qval[q], maxq = 0;
	for(int i = 0; i < q; i++)
	{
		scanf("%lld", &qval[i]);
		if(qval[i] > maxq) maxq = qval[i];
	}

	for(int i = 1; i < 20; i++)
	{
		for(int j = 0; j < n; j++)
		{
			val[j] = top[j];
		}
		for(int j = 1; j <= i; j++) dfsutil(0);
		//cout << "d= " << i << endl;
		for(int j = 0; j < n; j++) cout << val[j] <<" ";
		cout << endl;
	}
	for(int i = 1; i <= maxq; i++)
	{
		dfsutil(0);
		top[i] = val[0];
	}
	for(int i = 0; i < q; i++)
		printf("%lld\n", top[qval[i]]);

	return 0;
}