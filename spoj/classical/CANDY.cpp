#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,a[10001]={0};
	while(1)
	{
		scanf("%d",&n);
		if(n==-1) break;
		int sum=0,moves=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum%n==0)
		{
			int average=sum/n;
			sort(a,a+n);
			int last=n-1;
			for(int i=0;a[i]<average;i++)
			{
				moves+=(average-a[i]);
			}
			printf("%d\n",moves);
		}
		else printf("-1\n");
	}
	return 0;
}