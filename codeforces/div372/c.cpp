#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; scanf("%d",&n);
	int curl=1;
	long long int x=2,ct=0;
	while(curl!=n+1)
	{
		double sq= sqrt(x);
		long long int k=curl+1;
		if(sq == (int)sq)
		{
			long long int ssq=(int)sq;
			if(ssq%k==0)
			{
				x = sqrt(x);
				curl++;
				cout<<ct<<endl;
				ct=0;
			}
			else ct++,x+=curl;
		} 
		else ct++,x+=curl;
	}	
	return 0;
}