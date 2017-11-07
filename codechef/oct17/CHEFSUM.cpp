#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d", &t);
	long long int a[100002] = {0}, pre[100002] = {0}, suf[100002] = {0};
	long long int sum = 0; 
	while(t--)
	{
		int n; scanf("%d",&n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
			sum += a[i];
		}
		long long int mini = sum + a[1], ind = 1;
		for(int i = 1; i <= n; i++)
		{
			if(sum + a[i] < mini)
			{
				mini = sum + a[i];
				ind = i;
			}
		}
		printf("%lld\n",ind);
		/*long long int sum = 0;
		for(int i = 1; i <= n; i++)
		{
			pre[i] = 0; 
			pre[i] = a[i] + pre[i-1];
			sum += a[i];
		}
		for(int i = 1; i <= n; i++)
		{
			suf[i] = 0;
			suf[i] = sum;
			sum -= a[i];
		}
		long long int mini = 100000000000000;
		int ind = -1;
		for(int i = 1; i <=n; i++)
		{
			//cout << pre[i] << " " << suf[i] << endl;
			if( (pre[i] + suf[i]) < mini)
			{
				mini = pre[i] + suf[i];
				ind = i;
			}
		}*/
		//printf("%d\n", ind);
	}
	return 0;
}