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
int node[MX][MX], temp[MX][MX];
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


void printH()
{
	cout << "costnode = \n";
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << H[i][j] << " ";
		}
		cout << endl;
	}
}

void copytotemp()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			temp[i][j] = node[i][j];
		}
	}
}

void copytonode()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			node[i][j] = temp[i][j];
		}
	}
}

void dij(int initu)
{
	//printcost();
	//printH();
	int deg[n] = {0}, per[n] = {0};
	long long int concost[n] = {0};
	for(int i = 0; i < n; i++) concost[i] = H[i][0];
	vector<int> sel; int ct = 1;
	per[initu] = 1;
	sel.push_back(initu); 
	while(ct < n)
	{
		vector<int> non;
		for(int i = 0; i < n; i++)
		{
			if(per[i] == 0) non.push_back(i);
		}

		long long int mincost = 1e18;
		int uper = -1, vper = -1;
		for(int i = 0; i < sel.size(); i++)
		{
			int u = sel[i], v;
			for(int j = 0; j < non.size(); j++)
			{
				v = non[j];
				long long int pathcost;
				//pathcost = cost[u][v] + concost[u] + concost[v];
				pathcost = cost[u][v];
				pathcost += H[u][deg[u] + 1] + H[v][deg[v] + 1];
				pathcost -= H[u][deg[u]] + H[v][deg[v]];
				//cout << u << " -> " << v << " = " << pathcost << endl;
				if(pathcost < mincost)
				{
					mincost = pathcost;
					uper = u; vper = v;
				}
			}
		}

		concost[uper] += cost[uper][vper] + H[uper][deg[uper] + 1];
		concost[uper] -= H[uper][deg[uper]]; 
		concost[vper] += cost[uper][vper] + H[vper][deg[vper] + 1];
		concost[vper] -= H[vper][deg[vper]]; 

		per[vper] = 1; sel.push_back(vper);
		deg[uper]++; deg[vper]++;
		node[uper][vper] = 1; node[vper][uper] = 1;
		ct++;
	}

	long long int totalcost = 0;
	for(int i = 0; i < n; i++)
	{
		totalcost += concost[i];	
	}
	copytotemp();
	ct = 0;
	while(ct < 100)
	{
		long long int mincost = 1e18;
		int uper = -1, vper = -1;
		for(int i = 0; i < n; i++)
		{
			int u = i, v;
			for(int j = 0; j < n; j++)
			{
				v = j;
				if(u == v || temp[u][v] == 1) continue; 
				long long int pathcost;
				//pathcost = cost[u][v] + concost[u] + concost[v];
				pathcost = cost[u][v];
				pathcost += H[u][deg[u] + 1] + H[v][deg[v] + 1];
				pathcost -= H[u][deg[u]] + H[v][deg[v]];
				//cout << u << " -> " << v << " = " << pathcost << endl;
				if(pathcost < mincost)
				{
					mincost = pathcost;
					uper = u; vper = v;
				}
			}
		}
		concost[uper] += cost[uper][vper] + H[uper][deg[uper] + 1];
		concost[uper] -= H[uper][deg[uper]]; 
		concost[vper] += cost[uper][vper] + H[vper][deg[vper] + 1];
		concost[vper] -= H[vper][deg[vper]]; 
		deg[uper]++; deg[vper]++;
		temp[uper][vper] = 1; temp[vper][uper] = 1;
		long long int tempcost = 0;
		for(int i = 0; i < n; i++)
		{
			tempcost += concost[i];
		}
		if(tempcost < totalcost) copytonode();
		ct++;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) 
	{
		int Cmax, Hmax;
		costnode.clear();
		scanf("%d %d %d", &n, &Cmax, &Hmax);
		for (int i = 0; i < n; i++) {
			costnode.push_back(row);
			C[i][i] = 0;
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = i + 1; j < n; j++) {
				C[i][j] = C[j][i] = xorshift128plus() % (Cmax + 1);
				cost[i][j] = C[i][j];
				cost[j][i] = C[j][i];
				node[i][j] = 0; node[j][i] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = 0; j < n; j++) {
				H[i][j] = xorshift128plus() % (Hmax + 1);
			}
		}
		dij(0);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				printf("%d",node[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
