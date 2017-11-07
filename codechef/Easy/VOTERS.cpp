#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int n1,n2,n3; scanf("%d%d%d",&n1,&n2,&n3);
	int count[1000009]={0},e,max=0,cv=0;
	for(int i=0;i<n1;i++)
	{
		cin>>e; count[e]++;
		if(e>max) max=e;
	}
	for(int i=0;i<n2;i++)
	{
		cin>>e; count[e]++;
		if(e>max) max=e;
		if(count[e]==2) cv++;
	}
	for(int i=0;i<n3;i++)
	{
		cin>>e; count[e]++;
		if(e>max) max=e;
		if(count[e]==2) cv++;
	}
	cout<<cv<<endl;
	for(int i=1;i<=max;i++)
	{
		if(count[i]>1) cout<<i<<endl;
	}
	return 0;
}
