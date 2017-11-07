#include <iostream>
#include <stdio.h>
#include <map>
#include <cmath>
#define mod 1000000007
using namespace std;
int main()
{
	int old[5],nw[5],op=0;
	for(int i=0;i<5;i++) scanf("%d",&old[i]);
	for(int i=0;i<5;i++) scanf("%d",&nw[i]);
	for(int i=0;i<5;i++)
	{
		int diff1,diff2;
		if(old[i]<nw[i]) 
		{
			diff1=nw[i]-old[i];
			diff2= old[i]+10-nw[i];
			op+=min(diff1,diff2);
		}
		else if(old[i]>nw[i])
		{
			diff1= old[i]-nw[i];
			diff2= 10-old[i]+nw[i];
			op+=min(diff1,diff2);
		}
	}
	printf("%d\n",op);
	return 0;
}