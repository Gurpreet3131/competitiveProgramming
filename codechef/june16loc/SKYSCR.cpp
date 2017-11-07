#include<bits/stdc++.h>
#include<string.h>
#define mod 1000000007
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		long long int n,m;
		scanf("%lld%lld",&n,&m);
		long long int ans=fabs(n-m);
		printf("%lld\n",ans);			
		t--;
	}
	return 0;
}