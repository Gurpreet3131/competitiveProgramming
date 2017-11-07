#include <bits/stdc++.h>
using namespace std;
const int size = 300005;
int x[size], p[size];
int bsize, buckets, n;
int sum[size], bmax[1000][1000];


void setsum()
{
	for(int i = 0; i <= buckets; i++)
	{
		int ind = i * bsize;
		for(int j = 1; j <= bsize; j++)
		{
			ind = i * bsize + j;
			if(ind > n) break;
			sum[ind] = x[ind] + min(p[ind], ind - 1);
			//if(sum[ind] > tempmax) tempmax = sum[ind];
			if(j == 1) bmax[i][j] = sum[ind];
			else bmax[i][j] = max(bmax[i][j - 1], sum[ind]);
		}
		//bmax[i] = tempmax;
		if(ind > n) break;
	}
}

int main()
{
	int q;
	scanf("%d%d",&n, &q);
	for(int i = 1; i <= n; i++) scanf("%d",&x[i]);
	for(int i = 1; i <= n; i++) scanf("%d",&p[i]);
	bsize = sqrt(n);
	buckets = n / bsize;
	if(n % bsize == 0) buckets--; 
	buckets++;
	setsum();
	//for(int i = 1; i <= n; i++) cout << sum[i] << " ";
	//	cout << endl;
	//for(int i = 0; i <= buckets; i++) cout << bmax[i] << " ";
	//	cout << endl;
	//buildsegtree(1, n, 1);
	while(q--)
	{

		int type, a, b; scanf("%d%d%d",&type,&a,&b);
		int tempmax = INT_MIN, temp = 0;
		int bstart = a / bsize, bend = b / bsize;
		if(a % bsize == 0) bstart--;
		if(b % bsize == 0) bend--;
		if(type == 1)
		{
			x[a] = b;
			sum[a] = x[a] + min(p[a], a - 1);
			//bmax[bstart] = INT_MIN;
			int start = a % bsize;
			if(start == 0) start = bsize;
			for(int i = start; i <= bsize; i++)
			{
				int ind = bstart * bsize + i;
				if(ind > n) break;
				//if(sum[ind] > bmax[bstart]) bmax[bstart] = sum[ind];
				if(i == 1) bmax[bstart][i] = sum[ind];
				else bmax[bstart][i] = max(bmax[bstart][i - 1], sum[ind]);
			}
		}
		else if(type == 2) 
		{
			p[a] = b; 
			sum[a] = x[a] + min(p[a], a - 1);
			//bmax[bstart] = INT_MIN;
			int start = a % bsize;
			if(start == 0) start = bsize;
			for(int i = start; i <= bsize; i++)
			{
				int ind = bstart * bsize + i;
				if(ind > n) break;
				//if(sum[ind] > bmax[bstart]) bmax[bstart] = sum[ind];
				if(i == 1) bmax[bstart][i] = sum[ind];
				else bmax[bstart][i] = max(bmax[bstart][i - 1], sum[ind]);
			}
		}
		else
		{
			//for(int i = bstart; i <= bend; i++)
			for(int i = bend; i >= bstart; i--)
			{
				if(bmax[i][bsize] > tempmax)
				{
					//for(int j = 1; j <= bsize; j++)
					for(int j = bsize; j >= 1; j--)
					{
						int ind = bsize * i + j;
						if(ind < a) break;
						if(ind > b) continue;
						if(bmax[i][j] <= tempmax) break;
						temp = x[ind] + min(p[ind], ind - a);
						if(temp > tempmax) tempmax = temp;
					}
				}
			}
			printf("%d\n", tempmax);
		}
	}
	return 0;
}