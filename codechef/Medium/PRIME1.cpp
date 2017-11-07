#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		int n,m;
		scanf("%d%d",&m,&n);
		if((m==2 || m==1) && n>=2)
		{
			printf("2\n");
			m=3;
		}		
		if(m%2==0) m++;
		int p=1;		
		for(int i=m;i<=n;i+=2)
		{		
			p=1;
			for(int j=3;j<=sqrt(i);j+=2)
			{
				if(i%j==0)
				{
					p=0 ; break;
				}
			}
			if(p==1) printf("%d\n",i); 
		}
		printf("\n");
		t--;
	}
	
	return 0;
}
