#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#define min(a,b) a<b?a:b
using namespace std;
int main()
{
	int n,k1,k2;
	int fact[12]={0},q1[100000]={0},q2[100000]={0};	
	int f1=0,r1=-1,f2=0,r2=-1;
	fact[0]=1; fact[1]=1;
	for(int i=2;i<=11;i++)
	{
		fact[i]=fact[i-1]*i;
	}
	scanf("%d",&n);
	scanf("%d",&k1);
	for(int i=0;i<k1;i++)
	{
		scanf("%d",&q1[++r1]);
	}
	scanf("%d",&k2);
	for(int i=0;i<k2;i++)
	{
		scanf("%d",&q2[++r2]);
	}
	int one=q1[0],two=q2[0],count=0,win=0;
	f1=1;f2=1;
	while(true)
	{
		if(one>two)
		{
			q1[++r1]=two;
			q1[++r1]=one;
			count++;
			one = q1[f1++];
			if(f2<=r2) two = q2[f2++];
			else 
			{
				win=1; break;
			}
		}
		else
		{
			q2[++r2]=one;
			q2[++r2]=two;
			count++;
			if(f1<=r1) one = q1[f1++];
			else
			{
				win=2; break;
			}
			two = q2[f2++];
		}
		if(count>2000)
		{
			win=0; break;
		}
	}
	if(win==0) printf("-1\n");
	else
	{
		printf("%d %d\n",count,win);
	}
	return 0;
}