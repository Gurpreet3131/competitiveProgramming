#include <bits/stdc++.h>
using namespace std;
char a[58][58];
int val[58][58];
int n,m,k;
int ct[10000]={0};
void lakenum(int i,int j,char lake)
{
	a[i][j]=lake;
	if(i-1>=0 && a[i-1][j]=='.') lakenum(i-1,j,lake);
	if(i+1<n && a[i+1][j]=='.') lakenum(i+1,j,lake);
	if(j-1>=0 && a[i][j-1]=='.') lakenum(i,j-1,lake);
	if(j+1<m && a[i][j+1]=='.') lakenum(i,j+1,lake);
}
void lakeint(int i,int j,int lake)
{
	val[i][j]=lake;
	ct[lake]++;
	if(i-1>=0 && val[i-1][j]==-1) lakeint(i-1,j,lake);
	if(i+1<n && val[i+1][j]==-1) lakeint(i+1,j,lake);
	if(j-1>=0 && val[i][j-1]==-1) lakeint(i,j-1,lake);
	if(j+1<m && val[i][j+1]==-1) lakeint(i,j+1,lake);
}
void printa()
{
	//cout<<"a=\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<a[i][j];
		}	
		cout<<endl;
	}
	cout<<endl;
}
void printv()
{
	cout<<"v=\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<val[i][j]<<" ";
		}	
		cout<<endl;
	}
	cout<<endl;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i][0] == '.') lakenum(i,0,'O');
		if(a[i][m-1]=='.') lakenum(i,m-1,'O');
	}
	for(int j=0;j<m;j++)
	{
		if(a[0][j] =='.') lakenum(0,j,'O');
		if(a[n-1][j]=='.') lakenum(n-1,j,'O');
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='*' || a[i][j]=='O') val[i][j]=0; 
			else val[i][j]=-1;
		}
	}


	//
	int lake=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(val[i][j]==-1)
			{
				lakeint(i,j,lake);
				lake++;
			}
		}
	}
	int tempk=lake-1,steps=0;
	while(tempk>k)
	{
		int minlake=5000,minnum;
		for(int i=1;i<lake;i++)
		{
			if(ct[i]<minlake)
			{
				minlake=ct[i];
				minnum=i;
			}
		}
		int flag=0; steps+=ct[minnum];
		ct[minnum]=5000;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(val[i][j] == minnum)
				{
					lakenum(i,j,'*');
					flag=1;
					break;
				}
			}
			if(flag==1) break;
		}

		tempk--;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(a[i][j]=='O') a[i][j]='.';


	printf("%d\n",steps);
	printa();
	return 0;
}