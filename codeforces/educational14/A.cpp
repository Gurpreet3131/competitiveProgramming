#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n,but,zero=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&but);
		if(but==0) zero++;
	}
	if(n==1)
	{
		if(zero==0) printf("YES\n");
		else printf("NO\n");
	}
	else if(zero==1) printf("YES\n");
	else printf("NO\n");
	return 0;
}