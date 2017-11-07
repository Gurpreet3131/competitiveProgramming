#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		int n; scanf("%d",&n);
		int min;		
		for(int i=sqrt(n);i>0;i--)
		{
			if(n%i==0)
			{
				min=(n/i)-i;
				break;
			}
		}
		printf("%d\n",min);
		t--;
	}
	return 0;
}
