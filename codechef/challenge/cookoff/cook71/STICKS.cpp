#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	int a[1001]={0};
	while(t>0)
	{
		int n,flag=0,ct[1001]={0},mxct=0,area=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			ct[a[i]]++;
			if(ct[a[i]]>mxct) mxct=ct[a[i]];
		}
		if(mxct<2) area=-1;
		else
		{
			int one=-1,two=-1,posone=0;
			for(int i=1;i<1001;i++)
			{
				if(ct[i]>=2)
				{
					if(i>one) 
					{
						one=i;
						//posone=i;
					}
				}
			}
			//cout<<one<<endl;
			ct[one]-=2;
			for(int i=1;i<1001;i++)
			{
				if(ct[i]>=2)
				{
					if(i>two) 
					{
						two=i;
						//posone=i;
					}
				}
			}
			//cout<<two<<endl;
			if(one==-1 || two==-1) area=-1;
			else area=one*two;
		}
		printf("%d\n",area);
		t--;
	}
    return 0;
}