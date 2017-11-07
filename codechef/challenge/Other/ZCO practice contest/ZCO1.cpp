#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,*a;
	scanf("%d",&n);
	a=new int[n];
	long long int sum=0,sum2=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);		
		sum+=a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
	{
		sum-=a[i];
		sum2+=sum-(a[i]*(n-i-1));
	}
	printf("%lld\n",sum2);
	return 0;
}
