#include <iostream>
#include <stdio.h>
#include <map>
#include <cmath>
#define mod 1000000007
using namespace std;
int main()
{
	int n,k,actual=0,chrg;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		int cost; scanf("%d",&cost);
		if(i!=k) actual+=cost;
	}
	actual/=2;
	scanf("%d",&chrg);
	if(chrg==actual) printf("Bon Appetit\n");
	else printf("%d\n",chrg-actual);
	return 0;
}