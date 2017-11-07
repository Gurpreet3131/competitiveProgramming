#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n, k, num = 210001;
		scanf("%d%d",&n,&k);
		int ct[num] = {0};
		for(int i = 0; i < n; i++)
		{
			int val; scanf("%d",&val);
			ct[val] = 1;
		}
		int minval = 0;
		for(int i = 0; i < num;i++)
		{
			if(ct[i] == 0)
			{
				if(k > 0) k--;
				else 
				{
					minval = i; break;
				}
			}
		}
		printf("%d\n", minval);
	}
	return 0;
}