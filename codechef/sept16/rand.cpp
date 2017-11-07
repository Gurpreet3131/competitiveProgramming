#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000000
#define mod2 100
int main()
{
	srand(time(NULL));
	int n=40,p=2+rand()%(n-1);
	printf("%d %d\n",n,p);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int val=1+rand()%mod2;
			printf("%d ",val);
		}
		printf("\n");
	}
}
