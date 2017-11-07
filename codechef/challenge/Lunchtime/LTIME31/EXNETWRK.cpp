#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cstring>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		int n,m;		
		scanf("%d%d",&n,&m);
		if(n<5)
		{
			if(n==2)
			{
				cout<<"1 2\n";
			}
			else
			{
				if(m!=n) cout<<"-1 -1\n";
				else
				{
					for(int i=1;i<=n;i++)
					{
						if(i==n) cout<<i<<" 1"<<endl;						
						else cout<<i<<" "<<i+1<<endl;
					}
				}
			}
			
		}
		else
		{
			if(m!=n) cout<<"-1 -1\n";
				else
				{
					for(int i=1;i<=n;i++)
					{
						if(i==n) cout<<i<<" 1"<<endl;						
						else cout<<i<<" "<<i+1<<endl;
					}
				}
		}
		t--;
	}
	
	return 0;
}
