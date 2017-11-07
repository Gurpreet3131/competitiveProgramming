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
	long long int pair=0;
	int js=n-1;
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=js;j>i;j--)
		{
			if(a[i]+a[j]<k)
			{
				pair+=j-i;
				js=j;				
				break;
			}
		}
		if(js<i) break;
	}
	printf("%lld\n",pair);
	
	return 0;
}
