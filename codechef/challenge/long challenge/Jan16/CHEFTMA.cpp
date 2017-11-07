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
		int n,k,m; scanf("%d%d%d",&n,&k,&m);
		int a[100001],b[100001],c[100001],d[100001],dif[100001];
		long long int left=0;		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
			dif[i]=a[i]-b[i];
			left+=dif[i];		
		}
		sort(dif,dif+n);
		for(int i=0;i<k;i++)
		{
			scanf("%d",&c[i]);
		}
 		for(int i=0;i<m;i++)
		{
			scanf("%d",&d[i]);
		}
		sort(c,c+k); sort(d,d+m);
		int white=k-1,black=m-1,mx=0;
		for(int i=n-1;i>=0;i--)
		{
			if(dif[i]==0) continue;			
			while(true)
			{				
				if(c[white]<=dif[i] && d[black]<=dif[i])
				{
					mx=max(c[white],d[black]);					
					left-=mx;
					dif[i]-=mx; 
					if(mx==c[white])
					{
						c[white]=0;						 
						if(white>0) white--; 
					}
					else 
					{
						d[black]=0; if(black>0) black--;																		
					}
					break;
				}			
				else if(c[white]<=dif[i] && d[black]>dif[i])
				{
					if(black>0) black--;
					else
					{
						mx=c[white];						
						left-=mx;
						dif[i]-=mx;
						c[white]=0; 
						if(white==0) break;
						else white--;						
					}
				}
				else if(c[white]>dif[i] && d[black]<=dif[i])
				{
					if(white>0) white--;
					else
					{
						mx=d[black];						
						left-=mx;
						dif[i]-=mx;
						d[black]=0; 
						if(black==0) break;
						else black--;						
					}
				}
				else if(c[white]>dif[i] && d[black]>dif[i])
				{
					if(white==0 && black==0) break;					
					if(white>0) white--;
					if(black>0) black--;
				}	
			}
		}		
		printf("%lld\n",left);
		t--;
	}
	return 0;
}
