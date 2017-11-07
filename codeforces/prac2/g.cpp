#include <bits/stdc++.h>
using namespace std;
int a[600004]={0},num;
int main()
{	
	int n,k,i1,i2; scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&num);
		a[num]=i;
	}
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) continue;
		int val=i;
		for(int j=2;i*j<=n;j++)
		{
			if(a[i*j]!=0)
			{
				i1=a[i*j];
				i2=a[i];
				flag=1;
				break;
			}			
		}
		if(flag==1) break;
	}
	if(flag==1) printf("%d %d\n",i1,i2);
	else printf("0 0\n");
	return 0;
}
