#include <bits/stdc++.h>
using namespace std;
vector<vector<long long int> > a;
vector<long long int> row;

vector<vector<long long int> > dp;
vector<long long int> dprow;
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		a.clear();
		dp.clear();
		int maxm = 0;
		for(int i = 0; i < n; i++)
		{
			a.push_back(row);
			dp.push_back(dprow);
			int m; scanf("%d",&m);
			maxm = max(maxm, m);
			for(int j = 0; j < m; j++)
			{
				long long int val; scanf("%lld",&val);
				a[i].push_back(val);
				dp[i].push_back(0);
				dp[i].push_back(0);
			}
		}
		dp.push_back(dprow);
		long long int i = n - 2;		
		long long int minr = 1e7, maxr = 0;
		for(int j = 0; j < a[i + 1].size(); j++)
		{
			if(a[i + 1][j] > maxr) maxr = a[i + 1][j];
			if(a[i + 1][j] < minr) minr = a[i + 1][j];
		}

		int num = a[i].size();
		//cout << maxl << "  " << minl << endl;
		for(int j = 0; j < num; j++)
		{
			long long int dif1 = fabs(maxr - a[i][j]) * (i + 1), dif2 = fabs(minr - a[i][j]) * (i + 1);
			dp[i][j] = max(dif1, dif2);
			// i subarray and jth element
		}
		i--;

		while(i >= 0)
		{

			maxr = 0; minr = 1e7;
			for(int j = 0; j < a[i].size(); j++)
			{
				if(a[i][j] > maxr) maxr = a[i][j];
				if(a[i][j] < minr) minr = a[i][j];
			}
			int len = a[i+1].size();
			long long int tempmin =  -1;
			for(int k = 0; k < len; k++)
			{
				long long int dif1 = fabs(maxr - a[i+1][k]) * (i+1);
				long long int dif2 = fabs(minr - a[i+1][k]) * (i+1);
				long long int maxdif = max(dif1, dif2);
				int rindex = (k - 1 + len) % len;
				if(maxdif + dp[i+1][rindex] < tempmin) continue;
				tempmin = dp[i][0];
				for(int j = 0; j < a[i].size(); j++)
				{
					long long int dif = fabs(a[i+1][k] - a[i][j]) * (i+1);
					if(dif + dp[i + 1][rindex] > dp[i][j])
					{
						dp[i][j] = dif + dp[i + 1][rindex];
					}
					if(dp[i][j] < tempmin) tempmin = dp[i][j];
				}
			}
			i--;
		}
		long long int answer = 0;
		num = a[0].size();
		for(int j = 0; j < num; j++)
		{
			if(dp[0][j] > answer)
				answer = dp[0][j];
		}
		printf("%lld\n",answer);
	}
	return 0;
}