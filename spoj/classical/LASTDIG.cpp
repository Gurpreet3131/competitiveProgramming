#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int t,count[10]={0},num; 
	for(int i=2;i<10;i++)
	{
		count[i]++;
		num=i%10;
		for(int j=1;j<10;j++)
		{
			num=num*i;
			if(num%10==i%10) break;
			num=num%10;
			count[i]++;
		}
	}
	scanf("%d",&t);
	while(t>0)
	{
		long long int a,b;
		int dig=0;
		scanf("%lld%lld",&a,&b);
		a=a%10;
		if(a==0) dig=0;
		else if(b==0) dig=1;
		else if(a==1) dig=1;
		else
		{
			b=b%count[a];
			if(b==0) b=count[a];
			dig=pow(a,b);
			dig%=10;
		}
		printf("%d\n",dig);
		t--;
	}
	return 0;
}