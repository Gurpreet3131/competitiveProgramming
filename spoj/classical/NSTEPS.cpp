#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		int x,y,value;
		scanf("%d%d",&x,&y);
		if(y==x) 
		{
			if(y%2==0) value=2*y;
			else value=(2*y)-1;
			printf("%d\n",value);
		}
		else if(x==y+2)
		{
			if(y%2==0) value=2*y+2;
			else value=(2*y)+1;
			printf("%d\n",value);
		}
		else 
		{
			printf("No Number\n");
		}
		
		t--;
	}
	return 0;
}