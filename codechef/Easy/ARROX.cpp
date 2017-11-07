#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
	    long long int k,r;
		long long int q=103993/33102;
		scanf("%lld",&k);
		printf("%lld",q); 	
		if(k!=0)
		{
			printf(".");
			r=103993-(q*33102);
			for(int i=1;i<=k;i++)
			{
				r=r*10;
				q=r/33102;
				printf("%lld",q);
				r=r-(q*33102);
			}
		}
		printf("\n");
		t--;
	}
	return 0;
}
