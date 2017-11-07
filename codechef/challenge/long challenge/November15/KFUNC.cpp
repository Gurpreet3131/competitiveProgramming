// 40 points.. ai too small to hold big values
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		long long int l,r,ai,a,d,terms=0,mul=0;
		cin>>a>>d>>l>>r;
		long long int digs[9],mulsum=0,types=0;	
		ai=a+(l-2)*d;
		long long int sum=0;
		for(int i=0;i<9;i++)
		{
			int flag=1;			
			ai+=d;
			digs[i]=ai%9;			
			if(digs[i]==0) digs[i]=9;			
			for(int j=0;j<i;j++)
			{
				if(digs[i]==digs[j])
				{
					flag=0; break;
				}
			}
			
			if(flag==0)
			{								
				break;
			}
			types++;
			mulsum+=digs[i];
		}
		terms=r-l+1;	
		if(types==1)
		{
			sum=(digs[0]*terms);
			cout<<sum<<endl;
			t--; continue;
		}	
		mul=terms/types;
		terms=terms%types;
		sum+=(mulsum*mul);
		for(int i=0;i<terms;i++)
		{					
			sum+=digs[i];
			//cout<<i<<" "<<s<<" "<<sum<<"  "<<endl;
		}
		cout<<sum<<endl;
		t--;	
	}
	return 0;
}
