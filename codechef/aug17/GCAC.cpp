#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	long long int minSalary[1002],offSal[1002], maxJobs[1002];
	char qual[1002][1002];
	while(t--)
	{
		int n, m; scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++) scanf("%lld",&minSalary[i]);

		for(int i=1;i<=m;i++) scanf("%lld%lld",&offSal[i], &maxJobs[i]);

		for(int i=1;i<=n;i++)
		{
			for(int j=1; j<=m; j++)
			{
				cin>>qual[i][j];
				//scanf("%c",&qual[i][j]);
			}
		}
		int gotjob = 0, hire[1002] = {0};
		long long int totalsal = 0;
		for(int i=1;i<=n;i++)
		{
			long long int mx = -1, maxj = 0;
			for(int j=1; j<=m; j++)
			{
				if(qual[i][j] == '1' && hire[j] < maxJobs[j])
				{
					if(offSal[j] > mx)
					{
						mx = offSal[j];
						maxj = j;
					}
				}
			}
			if(mx >= minSalary[i])
			{
				gotjob++; hire[maxj]++; totalsal+=mx; 
			}
		}
		int nohire = 0;
		for(int i=1;i<=m;i++)
		{
			if(hire[i] == 0) nohire++;
		}
		printf("%d %lld %d\n", gotjob, totalsal, nohire);
	}
	return 0;	
}