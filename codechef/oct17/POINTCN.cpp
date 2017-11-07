#include <bits/stdc++.h>
using namespace std;

unsigned long long s[2];
unsigned long long xorshift128plus() {
	unsigned long long x = s[0];
	const unsigned long long y = s[1];
	x ^= x << 23;
	s[1] = x ^ y ^ (x >> 17) ^ (y >> 26);
	return s[0] = y;
}

bool comp(const pair<long long int, int> & l, const pair<long long int, int> & r)
{
	return l.first < r.first;
}

const int MX = 1000;
long long int inf = 1e18;
int n;
long long int C[MX][MX];
long long int H[MX][MX];
long long int cost[MX][MX];
int node[MX][MX];
vector<vector<pair<long long int, int> > > costnode;
vector<pair<long long int, int> > row;

void printC()
{
	cout << "C = \n";
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
}

void printcost()
{
	cout << "cost = \n";
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << cost[i][j] << " ";
		}
		cout << endl;
	}
}


void printcostnode()
{
	cout << "costnode = \n";
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n - 1; j++)
		{
			cout << costnode[i][j].first << " ";
		}
		cout << endl;
	}
}



int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int Cmax, Hmax;
		costnode.clear();
		scanf("%d %d %d", &n, &Cmax, &Hmax);
		for (int i = 0; i < n; i++) {
			costnode.push_back(row);
			C[i][i] = 0;
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = i + 1; j < n; j++) {
				C[i][j] = C[j][i] = xorshift128plus() % (Cmax + 1);
				node[i][j] = 0; node[j][i] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = 0; j < n; j++) {
				H[i][j] = xorshift128plus() % (Hmax + 1);
			}
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cost[i][j] = C[i][j];
			}
		}

		//for(int k = 0; k < n; k++)
		{
		//	for(int i = 0; i < n; i++)
			{
		//		for(int j = 0; j < n; j++)
				{
		//			if(cost[i][k] + cost[k][j] < cost[i][j])
		//				cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
//		printC();
//		printcost();
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(i == j) continue;
				costnode[i].push_back(make_pair(cost[i][j], j));
			}
			sort(costnode[i].begin(), costnode[i].end(), comp);
		}
//		printcostnode();


		// solve
		int selected[n] = {0}, num[n] = {0};
		int costind[n] = {0};
		vector<int> con;
		int ct = 1; 
		con.push_back(0); selected[0] = 1;
		while(ct < n)
		{
			int mincost = 1e9, minnode = -1;
			int parentnode = -1;
			for(int i = 0; i < con.size(); i++)
			{
				int u = con[i]; //already added node
				int v = -1;
				while(costind[u] < costnode[u].size())
				{
					int j = costind[u];
					v = costnode[u][j].second;
					if(selected[v] == 1)
					{
						costind[u]++;
						v = -1; 
					}
					else break;
				}
				if(v < 0) continue;

				//minimum cost element index to addednode
				int ind = costind[u];
				long long int cst = costnode[u][ind].first;
				int nextnode = costnode[u][ind].second;
				int nextconnum = num[u], nextnodeconnum = num[nextnode];
				int totalcost = cst + H[u][nextconnum] + H[nextnode][nextnodeconnum];
				if(nextconnum > 0) totalcost -= H[u][nextconnum - 1];
				if(nextnodeconnum > 0) totalcost -= H[nextnode][nextnodeconnum - 1];
				if(totalcost < mincost && selected[nextnode] == 0)
				{
					mincost = totalcost;
					minnode = nextnode;
					parentnode = u;
				}
			}
			node[parentnode][minnode] = 1;
			node[minnode][parentnode] = 1;
			con.push_back(minnode);
			selected[minnode] = 1;

			num[parentnode]++; num[minnode]++;
			costind[parentnode]++;
			ct++;
		}

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cout << node[i][j];
			}
			cout << endl;
		}

	}
	
	return 0;
}
