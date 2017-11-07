#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		long long int r,g,b,k,ans=0; 
		scanf("%lld%lld%lld%lld",&r,&g,&b,&k);
		long long int mini=min(r,min(g,b));
		long long int maxi=max(r,max(g,b));
		long long int mid;
		if(maxi==r) mid=max(g,b);
		else if(maxi==g) mid=max(r,b);
		else if(maxi==b) mid=max(r,g);
		if(r==g && g==b)
		{
			if(k==1) ans=1;
			else ans=3*(k-1)+1;
		}
		else if(k<=mini)
		{
			ans=3*(k-1)+1;
		}
		else if(k<=maxi && k<=mid && k>mini)
		{
			ans=(2*(k-1))+mini+1;
		}
		else if(k<=maxi && k>=mid && k>mini)
		{
			ans=mid+mini+(k);
		}
		else ans=r+g+b;
		printf("%lld\n",ans);
		t--;
	}
	return 0;
}