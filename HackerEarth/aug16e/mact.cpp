#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int pred[100001]={0};
int col[100001]={0};
int main()
{
	int n,c;
	pred[0]=-1;
	scanf("%d%d",&n,&c);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&pred[i]);
		pred[i]--;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&col[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(i==0) printf("-1 ");
		else
		{
			int cl=col[i],node=i,flag=0;
			while(node!=0)
			{
				node=pred[node];
				if(col[node]==cl)
				{
					flag=1; break;
				}
			}
			if(flag==1) printf("%d ",node+1);
			else printf("-1 ");

		}
	}
	cout<<endl;
	return 0;
}