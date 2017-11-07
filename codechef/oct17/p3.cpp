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
		/*
		for(int k = 0; k < n; k++)
		{
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					if(cost[i][k] + cost[k][j] < cost[i][j])
						cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
		*/
		int minh = 1e9, minnode = -1, numnode = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 1; j < n; j++)
			{
				if(H[i][j] < minh)
				{
					minh = H[i][j];
					minnode = i;
					numnode = j;
				}
			}
		}

		int selected[n] = {0}; int ct = 1;
		int eval[n] = {0};
		int u = minnode;
		selected[minnode] = 1; int num[n] = {0};
		
		while(ct < n)
		{
			//cout << " ct = " << ct << endl;
			
			eval[u]  = 1;
			while(numnode > 0 && ct < n)
			{
				//cout << "enter\n";
				//cout << "numnode = " << numnode << endl;
				int mincost = 1e9, minind = -1;
				for(int i = 0; i < n; i++)
				{
					if(u == i  || selected[i] == 1 || node[u][i] == 1) continue;
					if(cost[u][i] < mincost)
					{
						mincost = cost[u][i];
						minind = i;
					}
				}	
				//cout << "mincost = " << mincost << endl;
				//cout << "midin = " << minind << endl;				
				if(minind == -1) break;
				cost[u][minind] = 1e8;
				cost[u][minind] = 1e8;
				node[u][minind] = 1;
				node[minind][u] = 1;
				if(selected[minind] == 0) ct++;
				selected[minind] = 1;
				num[minind]++; num[u]++;
				numnode--;
				//ct++;
			}		
			if(ct >= n) break;
			//cout << ct << endl;
			minh = 1e9;
			for(int i = 0; i < n; i++)
			{
				if(eval[i] == 1) continue;
				if(selected[i] == 1)
				{
					for(int j = num[i]; j < n; j++)
					{
						if(H[i][j] < minh)
						{
							minh = H[i][j];
							minnode = i;
							numnode = j - num[i];
						}
					}
				}	
			}
			u = minnode;
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
