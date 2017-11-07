#include <bits/stdc++.h>
using namespace std;
const int n = 26;
int graph[26][26] = {0};
int cycle[26] = {0};

void dfsutil(int node, int visited[])
{
	//cout << "visiting" <<node<<"\n";
	visited[node] = 1;
	for(int i = 0; i < n; i++)
	{
		if(graph[node][i] == 1)
		{
			if(visited[i] == 0) //not a cycle
			{
				dfsutil(i, visited);
			}
			else 
			{

	//			cout << "Maing "<< i << endl;
				cycle[i] = 1;
			}
			visited[i] = 0;
		}
	}
}
void dfs(int node)
{
	int visited[26] = {0};
	dfsutil(node, visited);
}
int main()
{
	string s;
	while(cin >> s)
	{
		graph[s[0] - 'A'][s[2] - 'A'] = 1;
	}
	for(int i = 0; i < 26; i++)
	{
		dfs(i);
	}
	for(int i = 0; i < n; i++)
	{
		if(cycle[i] == 1) cout << (char)(i+'A');
	}
	cout << endl;
	return 0;
}