#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int fact[204]={0};
int main()
{
	fact[0]=1;
	for(int i=1;i<202;i++)
	{
		fact[i]= i*fact[i-1];
		if(fact[i]>=mod) fact[i]%=mod;
	}
	int t; scanf("%d",&t);
	while(t--)
	{
		long long int x,y;
		scanf("%lld%lld",&x,&y);
		long long int ans = fact[x+y]/(fact[x]*fact[y]);
		printf("%lld\n",ans);
	}
	return 0;
}