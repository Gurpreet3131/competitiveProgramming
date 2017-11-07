#include <iostream>
#include <stdio.h>
#include <math.h>
#define mod 1000000007
using namespace std;
int a[50002]={0};
int func[50002]={0};
int main()
{
	int n,c,q;
	scanf("%d%d%d",&n,&c,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<=n;i++)
	{
		scanf("%d",&func[i]);
	}

	long long int prod=1;
	for(int i=1;i<=q;i++)
	{
		int l,r,count=0;
		scanf("%d%d",&l,&r);
		for(int j=l;j<=r;j++)
		{
			if(a[j]==i) count++;
		}
		prod*=func[count];
		if(prod>=mod) prod%=mod;
	}
	printf("%lld\n",prod);
	return 0;
}