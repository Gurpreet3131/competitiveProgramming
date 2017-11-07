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
		long long int n,num;
		scanf("%lld",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&num);
		}	
		num=(n*(n-1))/2;
		printf("%lld\n",num);
       	t--;
	}
	return 0;
}
