#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b)
{
	if(b== 0) return a;
	else return gcd(b,a%b);
}

int main()
{
	int t;
	scanf("%d",&t);
	long long int a[502];
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		long long int mini = 1e18+10;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				long long int temp;
				temp = (a[i]*a[j])/gcd(a[i],a[j]);
				if(temp<mini) mini = temp;
			}
		}
		printf("%lld\n",mini);
	}	
	return 0;
}