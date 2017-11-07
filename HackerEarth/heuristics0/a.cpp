#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,maxi=0,mini=10000000;
		int a;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(a>maxi) maxi=a;
			if(a<mini) mini=a;
		}
		printf("%d\n",maxi-mini);
	}
	return 0;
}