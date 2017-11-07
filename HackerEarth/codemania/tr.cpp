#include <bits/stdc++.h>

using namespace std;
int main()
{
	int a[10004];
	while(1)
	{
		int n;
		long long int sum=0,dif=0;
		scanf("%d",&n);
		if(n==-1) break;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum%n==0)
		{
			int avg=sum/n;
			for(int i=0;i<n;i++)
			{
				dif+=abs(a[i]-avg);
			}
			printf("%lld\n",dif/2);
		}
		else printf("-1\n");
	}
	return 0;
}