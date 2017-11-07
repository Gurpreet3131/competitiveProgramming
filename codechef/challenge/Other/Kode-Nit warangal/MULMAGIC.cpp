#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
		int t;scanf("%d",&t);
		while(t>0)
		{
			int n;
			long long int sum=0,maxsum=0;	
			scanf("%d",&n);		
			int *a;
			a=new int[n+1];		
			for(int i=1;i<=n;i++) 
			{
				scanf("%d",&a[i]);
			}
			for(int i=2;i<=n;i++)
			{
				sum=0;
				for(int j=i;j<=n;j+=i)
				{
						sum+=a[j];
				}
				//printf("%d %d\n",i,sum);
				if(sum>maxsum) maxsum=sum;
			}
			
			printf("%lld\n",maxsum);
			t--;
		}
		
	return 0;
}
