#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int n,square; scanf("%d",&n);
	while(n!=0)
	{
		square=(n*(n+1)*(2*n+1))/6;
		printf("%d\n",square);
		scanf("%d",&n);
	}
	return 0;
}