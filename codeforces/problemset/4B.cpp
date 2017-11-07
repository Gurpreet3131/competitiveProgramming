#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	int d,sumtime,minsum=0,maxsum=0;
	cin>>d>>sumtime;
	int mint[30]={0},maxt[30]={0},time[30]={0};
	for(int i=0;i<d;i++)
	{
		cin>>mint[i]>>maxt[i];
		minsum+=mint[i]; 
		maxsum+=maxt[i];
	}
	if(sumtime>=minsum && sumtime<=maxsum)
	{
		printf("YES\n");
		for(int i=0;i<d;i++)
		{
			time[i]=mint[i];
		}	
		int left=sumtime-minsum;
		while(left!=0)
		{
			for(int i=0;i<d;i++)
			{
				if(left==0) break;
				if(time[i]<maxt[i])
				{
					time[i]++; left--;
				}
			}
		}
		for(int i=0;i<d;i++)
		{
			printf("%d ",time[i]);
		}
		printf("\n");
	} 
	else printf("NO\n");

	
}