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
//long long int C[MX][MX];
long long int H[MX][MX];
long long int cost[MX][MX];
int node[MX][MX], temp[MX][MX];


void printC()
{
	cout << "C = \n";
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			//cout << C[i][j] << " ";
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

void solve()
{
	// 10^5 edges are present add them one by one
	int setno[n] = {0}, deg[n] = {0};
	int per[n] = {0};
	for(int i = 0; i < n; i++) setno[i] = 1e5 + i;
	int ct = 0; // no.of set 1 elements
	int curset = 1; 
	int e = 0, emax = 500;
	//per[0] = 1; setno[0] = 1;
	while(ct < n && e < emax)
	{
		ct = 0; e++;
		long long int mincost = 1e18;
		int u = -1, v = -1;
		for(int i = 0; i < n; i++)
		{
			//if(per[i] == 0) continue;
			for(int j = i + 1; j < n; j++)
			{
				if(i == j || node[i][j] == 1) continue;
				//if(per[j] == 1 && per[i] == 1) continue;
				if(per[i] == 1 && per[j] == 1 && setno[i] == setno[j]) continue;
				// /cout << i << " " << j << endl;
				
				long long int edgecost = cost[i][j];
				edgecost += H[i][deg[i] + 1] + H[j][deg[j] + 1];
				edgecost = edgecost - (H[i][deg[i]] + H[j][deg[j] + 1]); 
				if(edgecost < mincost)
				{
					mincost = edgecost;
					u = i; v = j;
				}
			}
		}		
		//cout << u << " " << v << endl;
		node[u][v] = 1; node[v][u] = 1;
		deg[u]++; deg[v]++;
		if(per[u] == 0 && per[v] == 0)
		{
			per[u] = 1; per[v] = 1;
			setno[u] = curset; setno[v] = curset;
			curset++;
		}
		else
		{
			int minset = min(setno[u], setno[v]);
			int maxset = max(setno[u], setno[v]);
			if(per[u] == 1 && per[v] == 1)
			{
				for(int i = 0; i < n; i++)
				{
					if(setno[i] == maxset) setno[i] = minset; 
					
				}	
			}
			else setno[u] = minset, setno[v] = minset;
			per[u] = 1; per[v] = 1;
		}
		for(int i = 0; i < n; i++)
		{
			if(setno[i] == 1) ct++;
			//cout << setno[i] << " ";
		}
		//cout << endl;
		//cout << ct << endl;
	}
	if(e >= emax)
	{
		int u = 0, v, sval;
		for(int i = 1; i < n; i++)
		{
			int v = i, u = i - 1;
			if(setno[u] != setno[v])
			{
				int minset = min(setno[u], setno[v]);
				int maxset = max(setno[u], setno[v]);
				for(int j = i; j < n; j++)
				{
					if(setno[j] == maxset) 
						setno[j] = minset;
				}
			}
			else continue;
			node[u][v] = 1; node[v][u] = 1;
		}
	}

}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) 
	{
		int Cmax, Hmax;
		scanf("%d %d %d", &n, &Cmax, &Hmax);
		for (int i = 0; i < n; i++) {
			cost[i][i] = 0;
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = i + 1; j < n; j++) {
				cost[i][j] = cost[j][i] = xorshift128plus() % (Cmax + 1);
				node[i][j] = 0; node[j][i] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = 0; j < n; j++) {
				H[i][j] = xorshift128plus() % (Hmax + 1);
			}
		}
		solve();
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
