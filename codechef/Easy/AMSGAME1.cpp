#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main()
{
	int t,a[1005]; scanf("%d",&t);
	while(t>0)
	{
       	int n,hcf;
		scanf("%d",&n); 
		for(int i=0;i<n;i++) 
		{
			scanf("%d",&a[i]);
			if(i==0) hcf=a[i];			
			if(i>0)
			{
				hcf=gcd(hcf,a[i]);
			}
		}
		printf("%d\n",hcf);
       	t--;
	}
	return 0;
}
