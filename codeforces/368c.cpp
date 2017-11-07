#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <cmath>
using namespace std;
int main()
{
	long long int n; scanf("%lld",&n);
	long long int c,b;
	if(n%2==0)
	{
		b = ((n*n)/4)-1; c=b+2;
	}
	else
	{
		b = ((n*n)-1)/2; c=b+1;
	}
	if(n>0 && b>0 && c>0)
	{
		printf("%lld %lld",b,c);
	}
	else printf("-1\n");
	return 0;
}