#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,*a;
	scanf("%d",&n);
	a=new int[n];
	int brac=0,depth=0,depst=0,msymb=0,symbs=0,maxdepth=0,maxsym=0;
	int tempsymbs=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)
		{
			if(brac==0) 
			{
				tempsymbs=i+1;
			}			
			msymb++;
			brac++;			
			
		}
		else
		{		
			brac--;
			msymb++;
			
		}
		if(maxdepth<brac)
		{
				maxdepth=brac;depst=i+1;
		}
		if(brac==0)
		{
			if(msymb>maxsym)
			{
				maxsym=msymb; 
				symbs=tempsymbs;
			}
			msymb=0;
		}
	}
	printf("%d %d %d %d\n",maxdepth,depst,maxsym,symbs);
	return 0;
}
