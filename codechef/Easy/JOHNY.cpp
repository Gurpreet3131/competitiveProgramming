#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
    while(t>0)
    {
		int n,k,*pos;
		scanf("%d",&n);
		pos=new int[n];
		int u;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&pos[i]);
		}	
		scanf("%d",&k);
		u=pos[k-1];
		sort(pos,pos+n);
		for(int i=0;i<n;i++)
		{
			if(pos[i]==u) 
			{
				printf("%d\n",(i+1));
				break;
			}
		}
		t--;
	}
	return 0;        
}


