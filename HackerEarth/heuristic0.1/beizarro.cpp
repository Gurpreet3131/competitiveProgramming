#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k; cin>>n>>k;
	int a[n+1],present[1000003]={0};
	long long int ct=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		present[a[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int sum = a[i]+a[j];
			if(sum<k)
			{
				if(present[k-sum]>0) ct+= present[k-sum];
			}
		}
	}
	printf("%lld\n",ct);
	return 0;
}