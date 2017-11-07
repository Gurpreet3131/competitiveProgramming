#include <bits/stdc++.h>
using namespace std;
const int size = 101;
int a[size];
unordered_map<int, int> m;
//map<int, int> m;
int main()
{
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				int val = a[i] * a[j] + a[k];
				m[val]++;
			}
		}
	}
	long long int ct = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == 0) continue;
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				int val = a[i] * (a[j] + a[k]);
				ct += m[val];
			}
		}
	}
	printf("%lld\n", ct);
	return 0;
}