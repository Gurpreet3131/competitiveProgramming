#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		int n; scanf("%d",&n);
		int num,count[100001]={0},countnum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num);
			if(i==0) 
			{
				countnum++;
				count[num]++;
				continue;
			}			
			if(count[num]==0)
			{
				countnum++;
				count[num]++;
			}
		}
		printf("%d\n",countnum);
   		t--;
	}
	return 0;
}
