#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		long long int n,m;
		int flag=0;
		scanf("%lld%lld",&n,&m);
		if(n==1)
		{
			if(m==2) flag=1;
			else flag=0;	
		}
		else if(m==1)
		{
			if(n==2) flag=1;
			else flag=0;
		}
		else
		{
			if(m%2==0 || n%2==0) flag=1;
			else flag=0;
		}
		if(flag==1) printf("Yes\n");
		else printf("No\n");
		t--;
	}
	return 0;
}