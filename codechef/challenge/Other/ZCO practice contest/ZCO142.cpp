#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	
	int n,time[200001],ttime[200001];
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&time[i]);
	ttime[1]=time[1];
	ttime[2]=time[2];
	ttime[3]=time[3];
	int mini;
	if(n<3)
	{
		if(n==1) printf("%d\n",time[1]);
		else 
		{
		 	mini=time[1]<time[2]?time[1]:time[2];
			printf("%d\n",mini);
		}
		return 0;
	}
	for(int i=4;i<=n;i++)
	{
		mini=ttime[i-1]<ttime[i-2]?ttime[i-1]:ttime[i-2];
		mini=mini<ttime[i-3]?mini:ttime[i-3];
		ttime[i]=time[i]+mini;
	}
 	mini=ttime[n]<ttime[n-1]?ttime[n]:ttime[n-1];
	mini=mini<ttime[n-2]?mini:ttime[n-2];
	printf("%d\n",mini);	
	
	return 0;
}
