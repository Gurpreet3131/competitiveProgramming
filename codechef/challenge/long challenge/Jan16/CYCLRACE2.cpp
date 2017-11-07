#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main() 
{
	long long int n,q,max=0;
	scanf("%lld%lld",&n,&q);
	long long int speed[50009]={0},pos[50009]={0},curtime=0,cyca[50002]={0},cycfound[50002]={0},index=0;
	while(q>0)
	{
		long long int type,time,cyc,ns,dif=0;
	    scanf("%lld",&type);
	    if(type==1)
	    {
	    	scanf("%lld%lld%lld",&time,&cyc,&ns);
			dif=time-curtime;
	        if(dif>0)
	        {
	        	for(int i=0;i<index;i++)
	            {
	            	pos[cyca[i]]+=speed[cyca[i]]*dif;
	                if(max<pos[cyca[i]]) max=pos[cyca[i]];
	            }
	            curtime=time;
	        }
			
			if(cycfound[cyc]==0) 
			{
				cyca[index]=cyc; index++;
				cycfound[cyc]=1;       
			}
			speed[cyc]=ns;
	    }
	    else
	    {
	    	scanf("%lld",&time);
	        if(time<=curtime)
	       	{
	        	printf("%lld\n",max);
	       	}
	       	else 
	       	{
				dif=time-curtime;
	        	if(dif>0)
	        	{
	        		for(int i=0;i<index;i++)
	        	    {
	        	    	pos[cyca[i]]+=speed[cyca[i]]*dif;
	        	        if(max<pos[cyca[i]]) max=pos[cyca[i]];
	        	    }
	        	    curtime=time;
	        	}
	        	printf("%lld\n",max);
	       	}
	    }
	    q--;
	}
	return 0;
}
