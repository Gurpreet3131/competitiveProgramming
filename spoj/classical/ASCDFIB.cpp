#include <bits/stdc++.h>
using namespace std;
const int n = 1100001, mod = 1e5;
long long int fib[n] = {0};
int main()
{
	int t; cin >> t;
	fib[2] = 1;
	for(int i = 3; i < n; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		if(fib[i] >= mod) fib[i] %= mod;
	}
	for(int tt = 1; tt <= t; tt++)
	{
		priority_queue<int, vector<int>, greater<int> >pq;
		
		int a, b; scanf("%d%d", &a , &b);
		for(int i = a; i <= a+b; i++) pq.push(fib[i]);
		printf("Case %d: ", tt); int ct = 0;
		while(!pq.empty())
		{
			printf("%d ", pq.top()); pq.pop();
			ct++; if(ct >= 100) break;
		}
		printf("\n");
	}
	return 0;
}