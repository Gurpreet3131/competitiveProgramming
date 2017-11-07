#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main() 
{
	long long int n,q,max=0,maxpos=0,topspeed=0,change=0,mx=0;
	scanf("%lld%lld",&n,&q);
	long long int speed[50009]={0},pos[50009]={0},cyca[50002]={0},cycfound[50002]={0},index=0,ttime[50002]={0};
	while(q>0)
	{
		long long int type,time,cyc,ns;
	    scanf("%lld",&type);
	    if(type==1)
	    {
	    	scanf("%lld%lld%lld",&time,&cyc,&ns);
			pos[cyc]+=speed[cyc]*(time-ttime[cyc]);
			ttime[cyc]=time;
			speed[cyc]=ns;	
            if(cycfound[cyc]==1)
            {
                if(speed[cyc]<topspeed)
                {
                    cycfound[cyc]=2;
                }
            }	
            else if(cycfound[cyc]==2)
            {
                if(speed[cyc]>topspeed)
                {
                    cycfound[cyc]=1;
                }
            }	
			if(cycfound[cyc]==0 && speed[cyc]>topspeed) 
			{
				cyca[index]=cyc; index++;
				cycfound[cyc]=1;       
			}			
			if(change==0) change=1;
	    }
	    else
	    {
	    	scanf("%lld",&time);
			int temptopspeed=0;	       	
			if(change==1)
			{			
				for(int i=0;i<index;i++)
		       	{
					int dif=time-ttime[cyca[i]];	       	  	
					pos[cyca[i]]+=speed[cyca[i]]*dif;
					ttime[cyca[i]]=time;
	       	    	if(max<pos[cyca[i]]) 
					{	
						max=pos[cyca[i]];			
						temptopspeed=speed[cyca[i]];					
                        maxpos=cyca[i];
					}
		       	}
				change=2;
			}
			else
			{
				for(int i=0;i<index;i++)
	       		{
                    if(cycfound[cyca[i]]==2) continue;					
                    if(speed[cyca[i]]<topspeed)
                    {
                        cycfound[cyca[i]]=2;                     
                        continue;									
                    }
                    int dif=time-ttime[cyca[i]];	       	  	
					pos[cyca[i]]+=speed[cyca[i]]*dif;
					ttime[cyca[i]]=time;
	       	    	if(max<pos[cyca[i]]) 
					{	
						max=pos[cyca[i]];			
						temptopspeed=speed[cyca[i]];					
                        maxpos=cyca[i];
					}
								
	       		}
			}
			topspeed=temptopspeed;
	       	printf("%lld\n",max); 	
	    }
	    q--;
	}
	return 0;
}  
