#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;
int gcd(int a, int b) 
{
    return (b != 0)? gcd(b, a % b): a;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int num=9*m,den=8*n+m;
		int g=gcd(num,den);
		num/=g; den/=g;
 		printf("%d/%d\n",num,den);
	}
	return 0;
}