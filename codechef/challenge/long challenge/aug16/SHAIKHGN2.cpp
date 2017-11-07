#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#define inf 1000000009
using namespace std;
int adj[31][502][502]={0},temparr[502]={0},ans[502]={0};
//int row[31][502]={0},col[31][502]={0};
//int rowend[31][502]={0},colend[31][502]={0};
int rowq[31][502][502]={0},colq[31][502][502]={0};
int rowindex[31][502]={0},colindex[31][502]={0},endq[502]={0};
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++)
			{
				scanf("%d",&adj[0][i][j]);
				if(adj[0][i][j]==1)	rowq[0][i][rowindex[0][i]++]=j;
				if(adj[0][i][j]==1) colq[0][j][colindex[0][j]++]=i;
			}


	for(int p=1;p<31;p++)
	{
		for (int i=1;i<=n;i++)
    	{
    		int state=0;
    		//int kval=1,kend=n,tempkval=1,tempend=n;
           	if(rowindex[p-1][i]==0) continue;
           	//else kval=rowq[p-1][i][0],kend=rowq[p-1][i][rowindex[p-1][i]-1];
           	//tempkval=kval; tempend=kend;
        	for (int j=1;j<=n;j++)
        	{
        		//kval=tempkval;
        		//kend=tempend;
            	adj[p][i][j] = 0;
               	if(colindex[p-1][j]==0) {adj[p][i][j]=0; continue;}
            	//else kval=max(kval,col[p-1][j]),kend=min(kend,colend[p-1][j]);
            	if(rowindex[p-1][i]<=colindex[p-1][j])
            	{
            		state=1;
            	}
            	else state=2;
            	if(state==1)
            	{
            		for (int l=0;l<rowindex[p-1][i];l++)
                	{
                		int k=rowq[p-1][i][l];
                		adj[p][i][j] += adj[p-1][i][k]*adj[p-1][k][j];
        				if(adj[p][i][j]!=0) {adj[p][i][j]=1; break; }
        			}
            	}
            	else
            	{
            		for (int l=0;l<colindex[p-1][j];l++)
                	{
                		int k=colq[p-1][j][l];
                		adj[p][i][j] += adj[p-1][i][k]*adj[p-1][k][j];
        				if(adj[p][i][j]!=0) {adj[p][i][j]=1; break; }
        			}	
            	}
        	}
    	}
    	for(int i=1;i<=n;i++) 
			for(int j=1;j<=n;j++)
			{
				if(adj[p][i][j]==1)	rowq[p][i][rowindex[p][i]++]=j;
				if(adj[p][i][j]==1) colq[p][j][colindex[p][j]++]=i;
			}

    	/*cout<<p<<" : "<<endl;
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=1;j<=n;j++)
    		{
    			cout<<adj[p][i][j]<<" ";
	    	}
    		cout<<endl;
    	}*/
	}	
	int m;	scanf("%d",&m);
	for(int z=1;z<=m;z++)
	{
		int k,x;
		scanf("%d%d",&k,&x);
		int temp=k,count=0;;
		int msgcount=0;
		if(k==0) 
		{
			printf("1\n%d\n",x);
		}
		else
		{
			int flag=0,onecount=0,endindex=0;
			while(temp>0)
			{
				int r=temp%2; temp/=2;
				if(r==1) 
				{	
					if(flag==0)
					{
						flag=1;
						for(int i=1;i<=n;i++)
						{
							ans[i]=adj[count][x][i];
							if(onecount==0)
							{
								if(ans[i]!=0) onecount=i;
							}
							if(ans[i]!=0) endq[endindex++]=i;
						}
					}
					else 
					{
						if(onecount==0) break;
					for (int i=1;i<=n;i++)
    				{
    					temparr[i]=0;
    					int state=0;
    					//int jval=1,jend=n;
    					if(onecount==0) continue;
    					//else jval=onecount,jend=end;
    					if(endindex<=colindex[count][i]) state=1;
    					else state=2;
    					if(state==1)
    					{
    						for (int l=0;l<endindex;l++)
        					{
        						int j=endq[l];
    	    					if(colindex[count][i]==0) {temparr[i]=0; break; }
        						temparr[i]+=ans[j]*adj[count][j][i];
       							if(temparr[i]!=0) {temparr[i]=1; break; } 
        					}
    					}
    					else
    					{
    						for (int l=0;l<colindex[count][i];l++)
        					{
        						int j=colq[count][i][l];
        						if(colindex[count][i]==0) {temparr[i]=0; break; }
        						temparr[i]+=ans[j]*adj[count][j][i];
       							if(temparr[i]!=0) {temparr[i]=1; break; } 
        					}
    					}
    				}
    				onecount=0; endindex=0;
    				for(int i=1;i<=n;i++)
    				{
   						ans[i]=temparr[i];
   						if(onecount==0)
						{
							if(ans[i]!=0) onecount=i;
						}
						if(ans[i]!=0) endq[endindex++]=i;
						temparr[i]=0; 
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