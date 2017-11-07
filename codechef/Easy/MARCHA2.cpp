#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
      	long long int k,stemcount=1;
		long long int leave;
		scanf("%lld",&k);
		for(int i=1;i<=k;i++)
		{
			scanf("%lld",&leave);
			if(k<7)
			{
				stemcount-=leave;
				stemcount*=2;
			}
			else if(leave>=0 && leave<=stemcount && k>6)
			{
				stemcount-=leave;
				stemcount*=2;
			}			
			else break;
		}
		if(stemcount==0) printf("Yes\n");
		else printf("No\n");
       	t--;
	}
	return 0;
}
