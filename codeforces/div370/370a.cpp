#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main()
{
	int n;
	long long int b[100004]={0},a[100004]={0};
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
	}
	long long int p=1;
	for(int i=1;i<=n;i++)
	{
		if(i==n) a[i]=b[i];
		else a[i]=b[i]+b[i+1];
		cout<<a[i]<<" ";
	}

	return 0;
}