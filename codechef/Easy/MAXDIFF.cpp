#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
       	int n,k,a[101],sum=0,sum2=0; 
		scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		sum2=sum;
		sort(a,a+n);
		for(int i=0;i<k;i++)
		{
			sum-=(2*a[i]);
		}
		sum=fabs(sum);
		for(int i=n-1;i>n-k-1;i--)
		{
			sum2-=(2*a[i]);
		}
		sum2=fabs(sum2);
		if(sum2>sum) sum=sum2;
		printf("%d\n",sum);
       	t--;
	}
	return 0;
}
