#include <bits/stdc++.h>
using namespace std;
long long int n,m,a,b,maxv=0;
void dfs(int s)
{
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int value = q.front();
		if(value>maxv) maxv=value;
		q.pop();
		if(value +a <=n) q.push(value+a);
		if(value+b<=n) q.push(value+b); 
	}
}
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&m,&n,&a,&b);
		maxv=0;
		long long int dp[2][n+1]={0};
		dp[0][0]=0; dp[1][0]=0;
		for(int i=1;i<=n;i++)
		{
			long long int val = dp[0][i-1]+a;
			//cout<<i<<" "<<val<<endl;
			if(val<=i) dp[0][i] = val;
			else dp[0][i] = dp[0][i-1]; 
		}
		for(int i=1;i<=n;i++)
		{
			long long int val = dp[1][i-1]+b;
			if(val<=i) dp[1][i] = max(dp[0][i],val);
			else dp[1][i] = max(dp[1][i-1], dp[0][i]);
		}
		for(int i=0;i<=n;i++) cout<<i<<" ";
			cout<<endl;
		for(int i=0;i<=n;i++) cout<<dp[0][i]<<" ";
			cout<<endl;
		for(int i=0;i<=n;i++) cout<<dp[1][i]<<" ";
			cout<<endl;
		
		maxv= dp[1][n];
//		dfs(0);
		long long int bag = m/maxv,left = m%maxv;
		if(left>0) bag++;
		printf("%lld\n",bag);
	}
	return 0;
}