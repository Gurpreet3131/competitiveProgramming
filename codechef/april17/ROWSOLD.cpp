#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		int dp[100005]={0}, flag = 1;
		int n = s.length();
		int onect=0;
		for(int i=n-1;i>=0;i--)
		{
			if(s[i] == '1') onect++;
			if(flag == 1)
			{
				if(s[i] == '0')
				{
					dp[i] = dp[i+1] + 1;
					flag = 0;
				}
				else dp[i] = dp[i+1];
			}
			else
			{
				if(s[i] == '1') flag = 1;
				dp[i] = dp[i+1];
			}
		}
		int cur = n-1;
		long long int ans = 0;
		for(int i=n-1;i>=0;i--)
		{
			if(s[i] == '1')
			{
				ans+= cur - i;
				ans+= dp[i];
				cur--;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}