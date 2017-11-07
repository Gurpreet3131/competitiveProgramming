#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <time.h>
using namespace std;
long long int a[501][501],rowsum[501]={0},colsum[501];
int mark[503]={0},n;
long long int big=100000000000000000;
long long int minmax(int rc)
{
	srand(time(NULL));
	long long int minsc=big,minsc2=big,bestindex=0;
	int q[505]={0},qind=0;
	for(int i=0;i<=n;i++)
	{
		if(mark[i]==1) q[qind++]=i;
	}
	for(int i=1;i<n;i++)
	{
		if(mark[i]==1) continue;
		long long int sc=-1;
		//cout<<i<<":\n";
		int mx[503]={0},mind=0;
		for(int j=0;j<qind-1;j++)
		{
			long long int tempsc=0,tt=0;
			int start=q[j],end=q[j+1];
			if(i>start && i<end)
			{
				for(int k=start;k<end;k++)
				{
					if(rc==1)
					{
						if(k<i) tempsc+=rowsum[k];
						else tt+=rowsum[k];
					}
					else 
					{
						if(k<i) tempsc+=colsum[k];
						else tt+=colsum[k];
					}
				}
			//	cout<<start<<" -> "<<i<<" = "<<tempsc<<endl;
			//	cout<<i<<" -> "<<end<<" = "<<tt<<endl;
				mx[mind++]=tempsc; mx[mind++]=tt;
				tempsc=max(tempsc,tt);
			}
			else
			{ 
				for(int k=start;k<end;k++)
				{
					if(rc==1) tempsc+=rowsum[k];
					else tempsc+=colsum[k];
				}
				mx[mind++]=tempsc;
			//	cout<<start<<" -> "<<end<<" = "<<tempsc<<endl;
			}
			//if(tempsc>sc) sc=tempsc;
		}
		long long int max2=-1,mm=0;
		for(int z=0;z<mind;z++)
		{
			if(mx[z]>sc) sc=mx[z],mm=z;
		}
		mx[mm]=0;
		for(int z=0;z<mind;z++)
		{
			if(mx[z]>max2) max2=mx[z];
		}
		if(sc<minsc) minsc=sc,bestindex=i,minsc2=max2;
		else if(sc==minsc)
		{
			if(max2<minsc2)
			{
				minsc2=max2; bestindex=i;
			}
		}
	}
	mark[bestindex]=1;
	//cout<<bestindex<<" "<<minsc<<endl;
	return bestindex;
}
int main()
{
	int p;
	scanf("%d%d",&n,&p);
	mark[0]=1; mark[n]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%lld",&a[i][j]);	
			rowsum[i]+=a[i][j];		
			colsum[j]+=a[i][j];
		}
	}
	/*for(int i=0;i<n;i++) cout<<rowsum[i]<<" ";
		cout<<endl;
	for(int i=0;i<n;i++) cout<<colsum[i]<<" ";
*/
	//cout<<"row= "<<endl;
	for(int i=1;i<=p-1;i++)
	{
	//	cout<<"p= "<<i<<endl;
		minmax(1);
	}
	//cout<<endl;
	for(int i=1;i<n;i++) 
	{
		if(mark[i]==1) printf("%d ",i);
	}
	printf("\n");

	for(int i=1;i<n;i++) mark[i]=0;
	for(int i=1;i<=p-1;i++)
	{
		minmax(0);
	}
	for(int i=1;i<n;i++) 
	{
		if(mark[i]==1) printf("%d ",i);
	}	
	printf("\n");
	return 0;
}