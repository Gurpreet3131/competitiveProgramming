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
		int n,*a; cin>>n;
		a=new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}	
		sort(a,a+n);
		int count=0,diff=0,add=0;			
		int zero=a[0];	
		for(int i=n-1;i>0;i--)
			{				
				a[i]+=add;				
				diff=(a[i])-zero;				
				add+=diff;							
				count+=diff;
				zero+=diff;
			}
		
		cout<<count<<endl;
		t--;
	}
	return 0;
}
