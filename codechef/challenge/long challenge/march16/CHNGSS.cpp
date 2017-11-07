#include<bits/stdc++.h>
#define mod 1000000007
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
int tempc=0,co=0;
int guess(int i,int j)
{
	int r;
	printf("1 %d %d %d %d %d %d\n",i,i,j,j,1,25);fflush(stdout);scanf("%d",&r); co++;
	if(r==1) //1-25
	{
		printf("1 %d %d %d %d %d %d\n",i,i,j,j,1,13);fflush(stdout);scanf("%d",&r); co++;
		if(r==1) //1-13
		{
			if(tempc>0)
			{
				printf("1 %d %d %d %d %d %d\n",i,i,j,j,1,7);fflush(stdout);scanf("%d",&r); co++;
				tempc--;
				if(r==1) return 4; 
				else return 13;
			}
			else return 7;
		}		
		else //14-25
		{
			if(tempc>0)
			{
				printf("1 %d %d %d %d %d %d\n",i,i,j,j,14,19);fflush(stdout);scanf("%d",&r); co++;
				tempc--;
				if(r==1) return 17; 
				else return 23;
			}
			else return 20; 
		} 
	}
	else //26-50
	{
		printf("1 %d %d %d %d %d %d\n",i,i,j,j,26,38);fflush(stdout);scanf("%d",&r); co++;
		if(r==1) //26-38
		{
			if(tempc>0)
			{
				printf("1 %d %d %d %d %d %d\n",i,i,j,j,26,32);fflush(stdout);scanf("%d",&r); co++;
				tempc--;
				if(r==1) return 29; 
				else return 35;
			}
			else return 32;
		} 
		else //39-50
		{
			if(tempc>0)
			{
				printf("1 %d %d %d %d %d %d\n",i,i,j,j,39,44);fflush(stdout);scanf("%d",&r); co++;
				tempc--;
				if(r==1) return 42; 
				else return 47;
			}
			else return 44;
		}
	}
}
int main()
{
	long long int n,m,c,total,sum=0; 
	int a[250002]={0};
	scanf("%lld%lld%lld",&n,&m,&c);
	total=n*m;
	tempc=c;
	for(int i=1;i<=n;i++)
	{
		sum=0;
		for(int j=1;j<=m;j++)
		{
			int num=((i-1)*m)+j;
			if(co>=500000)
			{
				a[num]=25; continue;
			}
			if(c>0)
			{
				printf("2 %d %d %d %d\n",i,i,j,j); co++;
				fflush(stdout);
				int sumrow;
				scanf("%d",&sumrow);
			//	a[num]=sumrow-sum;
				a[num]=sumrow;
				c--;
			}
			else a[num]=guess(i,j);
			//sum+=a[num];
			//printf("i and j=%d %d\n",i,j);
			//printf("val=%d\n",a[num]);
		}
	}
	printf("3\n");
	fflush(stdout);
	int count=0;
	for(int i=1;i<=total;i++)
	{
		printf("%d",a[i]);
		count++;
		if(count==m)
		{
			printf("\n");
			count=0;
		}
		else printf(" ");
	}
	return 0;    
}
