#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#define inf 1000000009
using namespace std;
unsigned long long int adj[31][513][513]={0},ans[513]={0};
unsigned long long int adjrow[31][513][10]={0},adjcol[31][10][513]={0};
unsigned long long int ansrow[10]={0},temparr[513]={0};
int main()
{
	unsigned long long int twopow[64]={0};
	twopow[0]=1;
	for(int i=1;i<64;i++) twopow[i]=2*twopow[i-1];
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++)
			{
				scanf("%lld",&adj[0][i][j]);
			}
	int col,row;
	unsigned long long int dec=0;
	for(int i=1;i<=512;i++)
	{
		col=1;
		for(int j=1;j<=512;j+=64)
		{
			dec=0; row=63;
			for(int k=j;k<=j+63;k++)
			{
				if(adj[0][i][k]==1) dec+=twopow[row];
				row--; 
			}
			adjrow[0][i][col]=dec; 
			col++;
		}
	}
	for(int j=1;j<=512;j++)
	{
		row=1;
		for(int i=1;i<=512;i+=64)
		{
			dec=0; col=63;
			for(int k=i;k<=i+63;k++)
			{
				if(adj[0][k][j]==1) dec+=twopow[col];
				col--; 
			}
			adjcol[0][row][j]=dec; row++;
		}
	}
	for(int p=1;p<31;p++)
	{
		for (int i=1;i<=512;i++)
    	{
        	for (int j=1;j<=512;j++)
        	{
            	adj[p][i][j] = 0;
            	for (int k=1;k<=8;k++)
                {
                	unsigned long long int kk=adjrow[p-1][i][k]&adjcol[p-1][k][j];
                	if(kk!=0) {adj[p][i][j]=1; break;}
        		}
        	}
    	}
		for(int i=1;i<=512;i++)
		{
			col=1;
			for(int j=1;j<=512;j+=64)
			{
				dec=0; row=63;
				for(int k=j;k<=j+63;k++)
				{
					if(adj[p][i][k]==1) dec+=twopow[row];
					row--; 
				}
				adjrow[p][i][col]=dec; col++;
			}
		}
		for(int j=1;j<=512;j++)
		{
			row=1;
			for(int i=1;i<=512;i+=64)
			{
				dec=0; col=63;
				for(int k=i;k<=i+63;k++)
				{
					if(adj[p][k][j]==1) dec+=twopow[col];
					col--; 
				}
				adjcol[p][row][j]=dec; row++;
			}
		}
	}	
	int m;	scanf("%d",&m);
	for(int z=1;z<=m;z++)
	{
		int k,x;
		scanf("%d%d",&k,&x);
		int temp=k,count=0;
		int msgcount=0;
		if(k==0) 
		{
			printf("1\n%d\n",x);
		}
		else
		{
			int flag=0;
			while(temp>0)
			{
				int r=temp%2; temp/=2;
				if(r==1) 
				{	
					if(flag==0)
					{
						flag=1;
						for(int i=1;i<=8;i++)
						{
							ansrow[i]=adjrow[count][x][i];
						}
						for(int i=1;i<=512;i++)
						{
							ans[i]=adj[count][x][i];
						}
					}
					else {
					for (int i=1;i<=512;i++)
    				{
    					temparr[i]=0;
        				for (int j=1;j<=8;j++)
        				{
        					temparr[i]+=ansrow[j]&adjcol[count][j][i];
       						if(temparr[i]!=0) {temparr[i]=1; break;}
        				}
    				}
    				col=1;
    				for(int i=1;i<=512;i+=64)
    				{
    					dec=0; row=63;
    					for(int j=i;j<=i+63;j++)
    					{
    						if(temparr[j]==1) dec+=twopow[row];
    						ans[j]=temparr[j];
    						row--;
    					}
   						ansrow[col]=dec; col++;
    				}
    				}
				}
				count++;
			}
			for(int i=1;i<=n;i++)
			{
				if(ans[i]!=0) msgcount++;
			}
			printf("%d\n",msgcount);
			if(msgcount==0) printf("-1\n");
			else
			{
				for(int i=1;i<=n;i++)
				{
					if(ans[i]!=0) printf("%d ",i);
				}
				printf("\n");
			}
		}
	}
	return 0;
}