#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#define mod 1000000007
using namespace std;
int main()
{
	int t; scanf("%d",&t);    	
	int q[1000001]={0};    
	while(t>0)
	{
        long long int n,m;
		scanf("%lld%lld",&n,&m);
		int a[n][m],maxnum=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
		}
		for(int i=0;i<n;i++)
		{			
			for(int j=0;j<m;j++)
			{
				int index=0;				
				for(int k=0;k<m;k++)
				{
					q[index++]=a[i][k];
				}
				for(int k=0;k<n;k++)
				{
					if(k==i) continue;					
					q[index++]=a[k][j];
				}
				//for(int i=0;i<index;i++) cout<<q[i]<<" ";
				sort(q,q+index);
				//cout<<endl;
				//for(int i=0;i<index;i++) cout<<q[i]<<" ";
				//cout<<endl;
				int tempcount=0,maxcount=0,left=m+n;
				for(int k=0;k<index;k++)
				{
					if(k==0) tempcount++;
					else
					{
						if(q[k]==q[k-1]) tempcount++;						
						else tempcount=1;
					}
					left--;
					if(tempcount>maxcount) maxcount=tempcount;
					if((tempcount+left)<maxcount) break;				
				}
				if(maxcount>maxnum) maxnum=maxcount;
			}			
		}
		printf("%d\n",maxnum);
		t--;
	}
	return 0;
}
