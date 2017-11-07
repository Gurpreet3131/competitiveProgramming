#include <iostream>
#include <stdio.h>
#include <map>
#include <cmath>
#define mod 1000000007
using namespace std;
long long int row[501]={0},col[501]={0},d1=0,d2=0;
int main()
{
	int n,posi,posj; scanf("%d",&n);
	long long int a[501][501];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%lld",&a[i][j]);
			row[i]+=a[i][j];
			col[j]+=a[i][j];
			if(i==j) d1+=a[i][j];
			if(i+j==n-1) d2+=a[i][j];
			if(a[i][j]==0)
			{
				posi=i; posj=j;
			}
		}
	}
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	int flag=1,p;
	if(posi==0) p=1;
	else p=0;
	for(int i=0;i<n;i++)
	{
		if(i== posi) continue;
		if(row[i]!=row[p])
		{
			flag=0; break;
		}
	}
	if(flag==1)
	{
		for(int j=0;j<n;j++)
		{
			if(j==posj) continue;
			if(col[j]!=row[p])
			{
				flag=0; break;
			}
		}
	}
	//cout<<flag<<endl;
	if(flag==1)
	{
		//cout<<d1<<" "<<row[p]<<endl;
		if(posi!=posj)
		{
			if(d1!=row[p]) flag=0;
		}
		//cout<<flag<<endl;
		if(posi+posj!=n-1)
		{
			if(d2!=row[p]) flag=0;
		}
		//cout<<flag<<endl;
	}
	//cout<<flag<<endl;
	if(flag==1)
	{
		if(row[p]-row[posi] != row[p]-col[posj]) flag=0;
		else
		{
			if(posi==posj)
			{
				if(row[p]-d1!=row[p]-row[posi]) flag=0;
			}
			if(posi+posj==n-1)
			{
				if(row[p]-d2!=row[p]-row[posi]) flag=0;
			}
		}
	}
	//cout<<flag<<endl;
	if(flag==1)
	{
		long long int dif=row[p]-row[posi];
		if(dif>=1 && dif<=1000000000000000000)
		{
			printf("%lld\n",dif);
		}
		else printf("-1\n");
	}
	else printf("-1\n");
	//cout<<flag<<endl;
	
	return 0;
}