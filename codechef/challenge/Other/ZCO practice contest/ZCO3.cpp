#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	long long int a[500000]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	long long int max=a[0]*n;
	long long int m=0;	
	for(int i=1;i<n;i++)
	{		
		m=a[i]*(n-i);
		if(m>max) max=m;
	}
	printf("%lld\n",max);
	return 0;
}
