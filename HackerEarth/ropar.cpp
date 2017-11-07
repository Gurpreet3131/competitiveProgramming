#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int t; scanf("%d",&t);

	while(t>0)
	{
		int n; cin>>n;
		int ra[2*n][2];
		//int ra2[n][2]={0};
		int count=0;		
		for(int i=0;i<n;i++)
		{
			int l,r;
			cin>>l>>r;
			ra[i][0]=l;ra[i][1]=r;
			count++;
			if(i==0) continue;
			int si=i;
			for(int j=0;j<si;j++)
			{
				if(l<=ra[j][0])
				{
					if(r<=ra[j][1] && ra[j][0]<=r)
					{
						ra[j][0]=r+1;
						if(ra[j][0]>ra[j][1]) count--;
						//cout<<i<<"one "<<count<<endl;
					}
					else if(r>=ra[j][1])
					{
						ra[j][1]=r+1;	
						count--;
						//cout<<i<<"two "<<count<<endl;
					}
				}
				else if(l>ra[j][0] && l<=ra[j][1])
				{
					
					if(r>=ra[j][1])
					{
						ra[j][0]=l-1;
						if(ra[j][0]>ra[j][1]) count--;	
	//cout<<i<<"three "<<count<<endl;
					}
					else if(r<ra[j][i])
					{
						ra[i+1][0]=r+1;ra[i+1][1]=ra[j][1]; 
						ra[j][1]=l-1;						
						i++;					
					}
				}				
			}
			
		}	
		cout<<count<<endl;
		t--;
	}
	return 0;
}
