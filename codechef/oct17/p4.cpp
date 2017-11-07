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

const int MX = 1000;

int C[MX][MX];
int H[MX][MX];
int node[MX][MX], cost[MX][MX];
int main() {
	srand(time(NULL));
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int n, Cmax, Hmax;
		scanf("%d %d %d", &n, &Cmax, &Hmax);
		for (int i = 0; i < n; i++) {
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

		int selected[n] = {0}; int ct = 1;
		selected[0] = 1;
		vector<int> sel;
		sel.push_back(0);
		while(ct < n)
		{
			int len = sel.size();
			int ind = rand() % len;
			int u = sel[ind];
			//cout << ind << endl;
			vector<int> non;
			for(int i = 0; i < n; i++)
			{
				if(selected[i] == 0) non.push_back(i);
			}
			len = non.size();
			ind = rand() % len;
			int v = non[ind];
			selected[v] = 1;
			sel.push_back(v);
			node[u][v] = 1; node[v][u] = 1;
			//cout << i << " " << minind << endl;
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
