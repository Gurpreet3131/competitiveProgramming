#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#define big 1000000007
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	long long int rangex[2],rangey[2],index=0;
	while(t-->0)
	{
		int n;
		unsigned long long int h[13]={0},m[13]={0},curtime=0;
		scanf("%d",&n);
		int alt=-1;
		for(int i=0;i<n;i++)
		{
			scanf("%lld%lld",&h[i],&m[i]);
		}
		if(n==1)
		{
			printf("1\n0 Inf\n");
			continue;
		}
		int state=1,count=0; //zigzag
		index=0;
		while(true)
		{
			//cerr<<"curtime= "<<curtime<<endl;
			//cout<<"alt\n";
			//for(int i=1;i<n;i++) cerr<<alt[i]<<" ";
			//cout<<endl;
			state=1; alt=-1;
			for(int i=1;i<n;i++)
			{
				if(i==1)
				{
					if(h[i]>h[i-1]) alt=1;
					else if(h[i]<h[i-1]) alt=0;
					else { alt=2; state=0; break; }
				}
				else if(alt==1)
				{
					if(h[i]<h[i-1]) alt=0;
					else {state=0; break; }
				}
				else if(alt==0)
				{
					if(h[i]>h[i-1]) alt=1;
					else { state=0; break; }
				}
			}
			//cout<<"state= "<<state<<endl;		
			if(state==1)
			{
				count++;
				rangex[index]=curtime;
			}
			// find time when variation will occur
			unsigned long long int mintime=0,tt,found=0;
			for(int i=1;i<n;i++)
			{
			//	cout<<"i= "<<i<<endl;
				if(h[i-1]<h[i])
				{
					if(m[i-1]>m[i])
					{
						tt=ceil( ((double)(h[i]-h[i-1])) / ((double)(m[i-1]-m[i])) );
						if(found==0) mintime=tt,found=1;
						else if(tt<mintime) mintime=tt;
					}
				}
				else if(h[i-1]>h[i])
				{
					if(m[i]>m[i-1])
					{
						tt=ceil( ((double)(h[i-1]-h[i])) / ((double)(m[i]-m[i-1])) );
						if(found==0) mintime=tt,found=1;
						else if(tt<mintime) mintime=tt;
					}
				}
				else 
				{
					if(m[i]!=m[i-1]) 
					{
						tt=1;
						if(found==0) mintime=tt,found=1;
						else if(tt<mintime) mintime=tt;
					}
				}
			//	cout<<"tt= "<<tt<<endl;
			}
			//cout<<"mintime= "<<mintime<<endl;
			if(found==0)
			{
				//state will never change now
				if(state==1)	rangey[index++]=-1; //goes to inf
				break;
			}
			else
			{
				if(state==1) 
				{
					rangey[index++]=curtime+mintime-1;
				}
				curtime+=mintime;
				for(int i=0;i<n;i++)
				{
					h[i]+=m[i]*mintime;
				}
				//break;
			}
		}
		if(count>1)
		{
			for(int i=1;i<index;i++)
			{
				if(rangey[i-1]+1==rangex[i])
				{
					rangey[i-1]=rangey[i];
					for(int j=i;j<index-1;j++)
					{
						rangex[j]=rangex[j+1];
						rangey[j]=rangey[j+1];
					}
					index--;
					count--;
					i--;
				}
			}
		}
		printf("%d\n",count);
		for(int i=0;i<count;i++)
		{
			if(rangey[i]==-1) printf("%lld Inf\n",rangex[i]);
			else printf("%lld %lld\n",rangex[i],rangey[i]);
		}
	}
	return 0;
}
