#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d", &t);
	int a[100002] = {0};
	while(t--)
	{
		int n; scanf("%d",&n);
		for(int i = 1; i <= n; i++)
		{
			if(i%2 == 0) a[i] = i - 1;
			else a[i] = i+1;
		}
		if(n % 2 == 1)
		{
			a[n]--;
			swap(a[n-1], a[n]);
		}
		for(int i = 1; i <= n; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}