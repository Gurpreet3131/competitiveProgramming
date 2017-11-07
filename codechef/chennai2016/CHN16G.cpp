#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d", &t);
	while(t--)
	{
		int n; scanf("%d", &n);
		int ct[101] = {0}, fake = 0;
		for(int i = 0; i < n; i++)
		{
			int a; scanf("%d", &a);
			ct[a]++;
		}
		for(int i = 0; i < 101; i++)
		{
			if(ct[i] > 0) fake += ct[i] - 1;
		}
		printf("%d\n", fake);
	}
}