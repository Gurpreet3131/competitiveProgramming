#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,k,*a;
	scanf("%d%d",&n,&k);
	a=new int[n];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	long long int count=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(fabs(a[i]-a[j])>=k)
			{
				count+=n-j;
				break;
			}
		}
	}
	printf("%lld\n",count);
	
	return 0;
}
