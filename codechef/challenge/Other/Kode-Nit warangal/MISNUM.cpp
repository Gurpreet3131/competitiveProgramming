#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
		int q;scanf("%d",&q);
		int two[3500]={0};
		int index=0,p=1;
		for(int i=2;i<31623;i++)  //31623
		{
			p=1;			
			for(int j=2;j<=sqrt(i);j++)
			{
				if(i%j==0) 
				{
					p=0;
					break;
				}
			}
			if(p==1)
			{				
				two[index]=(i*i);
				index++;			
			}
		}
		while(q>0)
		{
			int l,r,count=0;
			scanf("%d%d",&l,&r);	
			for(int i=0;i<index;i++)
			{
				if(two[i]>=l && two[i]<=r) count++;
			}	
			printf("%d\n",count);
			q--;
		}
		
	return 0;
}
