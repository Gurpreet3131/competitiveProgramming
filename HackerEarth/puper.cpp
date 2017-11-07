#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#define mod 1000000007
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		long long int l,r; scanf("%lld%lld",&l,&r);
		long long int sumall=0,suml=0,sumr=0;
		sumr = r%mod;
		sumr= (sumr * ((r+1)%mod)) %mod;
		sumr = ((sumr * ((2*r+1)%mod))/6) %mod;

		suml = l%mod;
		suml= (suml * ((l+1)%mod)) %mod;
		suml = ((suml * ((2*l+1)%mod))/6) %mod;

		sumall = sum
 		printf("%lld\n",minop);
	}
	return 0;
}