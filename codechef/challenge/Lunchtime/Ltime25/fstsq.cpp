#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		int n,d;
		scanf("%d%d",&n,&d);
		
		long double num=0,sum=0,sq2=0,count=0,sq=0;		
		while(n>0)
		{
			num=num*10+d;
			n--;
		}		
		
		sq=num*num;
		sq2=sq;
		
		while(sq2>0)
		{
			count++; sq2=floor(sq2/10);
		}
		
		for(int i=count-1;i>=0;i--)
		{
			sum+=pow(23,i)*(sq%10);
			if(sum>=1000000007)sum%=1000000007;
			sq=sq/10;
		}	
		cout<<sum<<endl;
		t--;
	}
	return 0;
}
