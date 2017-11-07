#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	
	int n,money[200001],tmoney[200001];
	scanf("%d",&n);
	long long int sum=0;
	for(int i=1;i<=n;i++)
	{
		 scanf("%d",&money[i]);
		 sum+=money[i];
	}
	tmoney[0]=0;
	tmoney[1]=money[1];
	tmoney[2]=money[2];
	tmoney[3]=money[3];
	int mini;
	for(int i=4;i<=n;i++)
	{
		mini=tmoney[i-1]<tmoney[i-2]?tmoney[i-1]:tmoney[i-2];
		mini=mini<tmoney[i-3]?mini:tmoney[i-3];
		tmoney[i]=money[i]+mini;
	}
 	mini=tmoney[n]<tmoney[n-1]?tmoney[n]:tmoney[n-1];
	mini=mini<tmoney[n-2]?mini:tmoney[n-2];
	printf("%lld\n",sum-mini);	
	
	return 0;
}
