#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n; scanf("%d",&n);
	int max=0,len=0,a;	
	while(n>0)
	{
	    scanf("%d",&a);
    	if(a==0)
		{
			if(len>max) max=len; 
			len=0;
		}
		else 
		{
			len++;
		}
		n--;
	}
	if(len>max) max=len;
	printf("%d\n",max);
	return 0;
}
