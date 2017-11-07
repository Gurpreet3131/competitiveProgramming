#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
 {
	
	int m,n,t;
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d%d",&m,&n);
		int flag=1;		
		for(int i=m;i<=n;i++)
		{
			int flag=1;					
			if(i==1) continue;			
			for(int j=2;j<=sqrt(i);j++)
			{
				
				if(i%j==0) 
				{
					flag=0;
					break;
				}
			}
			if(flag==1) cout<<i<<endl;
		}
		t--;
	}
	return 0;
}
