#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		int n;
		scanf("%d",&n);
		int five=0,two=0,total=0,val;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&val);
			total+=val;
			if(val==2) two++;
			if(val==5) five++;
		}
		double avg=((double)(total))/n;
		if(avg>=4.0 && five>0 && two==0) printf("Yes\n");
		else printf("No\n");
		t--;
	}
    return 0;
}