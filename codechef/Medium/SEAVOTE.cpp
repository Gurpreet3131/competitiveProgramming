#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		int n;
        long long int a[10000],sum=0,sum2=0; scanf("%d",&n);
		int count=0;		
		for(int i=0;i<n;i++)  
		{
			scanf("%lld",&a[i]);
			sum+=a[i];
			if(a[i]==0) count++;
		}        
		if(sum<100 || (sum-n+count)>=100) printf("NO\n");
		else printf("YES\n");
        t--;
	}
	return 0;
}
