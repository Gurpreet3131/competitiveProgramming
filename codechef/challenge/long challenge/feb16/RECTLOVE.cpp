#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define mod 1000000007
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		long long int n,m,k,heart,x,y; 
		scanf("%lld%lld%lld",&n,&m,&k);
		double prob=0,p;	
		long long int sum=0;	
		for(int i=1;i<=k;i++)
		{
			scanf("%lld",&heart);
			y=heart%m; 
			x=(heart/m)+1;
			if(y==0) 
			{
				x--; y=m;
			}		
			p=((double)(x*(n-x+1))/(double)(n*(n+1)));
			prob+=(double)(p*(y*(m-y+1)))/(double)(m*(m+1));
		}	
		prob*=4;		
		printf("%.18lf\n",prob);		
		t--;
	}    
    return 0;    
}
