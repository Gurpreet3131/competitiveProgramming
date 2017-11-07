    #include<bits/stdc++.h>
    #include<string.h>
    #define mod 1000000007
    using namespace std;
    long long int p[1000001]={0};
    long long int prime[70001]={0};
    long long int sum[100001]={0};
    long long int good[100001]={0};
    int g[40000];
    int ind;
    void sandc(long long int num)
    {
    	sum[num]=1+num; 
    	int ct=0;
    	
    	if(p[num]!=0)
    	{
    		int numsq=sqrt(num);
    		for(int i=2;i<=numsq;i++)
    		{
    			if(num%i==0)
    			{
    				if(i*i==num) sum[num]+=i;
    				else
    				{
    					sum[num]+=i+num/i;
    				}
    			}
    		}
    	}
    	if(p[sum[num]]==0)
    	{
    		ct=1;
    	}
    	else
    	{
    		long long int s=sum[num];
    		int i=0,previ=-1,flag=0;
    		while(s!=1)
    		{
                flag=0;
    			if(p[s]==0)
    			{
    				//if(i>previ) 
                    ct++;
    				s=1;
    			}	
    			else 
    			{
    				while(s%prime[i]==0)
    				{
    					if(flag==0)
    					{	
    					   ct++;
    					   flag=1;
                        } 
    					s/=prime[i];
    				}
    			}
    			i++;
    //			if(num<10) cout<<"s= "<<s<<endl;
    		}
    	}
    //	if(num<10) cout<<"insdie:\n";
    //	if(num<10) cout<<"sum= "<<sum[num]<<" c= "<<ct<<endl;
    	if(p[ct]==0) good[num]=1;
    	else good[num]=0;
     
    	//if(num<10) cout<<"goodnum= "<<good[num]<<endl;
    }
     
    int main()
    {
    	int index=0; p[1]=1;
    	int sumindex=0;
    	for(int i=2;i<1000001;i++)
    	{
    		if(p[i]==0)
    		{
    			prime[index++]=i;
    			for(int j=2;i*j<1000001;j++)
    			{
    				p[i*j]=1;
    			}
    		}	
    	}
    	//cout<<index<<endl;
    	//for(int i=0;i<100;i++) cout<<prime[i]<<endl;
    	sum[1]=1; good[1]=0; ind=index;
    	int cc=0;
    	for(int i=2;i<100001;i++)
    	{
    		int flag=1;
    		if(p[i]==0)
    		{
    			sandc(i);
    		}
    		else
    		{
    			int sq=sqrt(i);
    			for(int j=2;j<=sq;j++)
    			{
    				if(i%(j*j)==0) 
    				{
    					flag=0; break;
    				}
    			}
    			if(flag==1) sandc(i);
    			else good[i]=0;
    		}
    		//if(good[i]==1) cc++;
    		//if(i%10000==0) cout<<i<<". good= "<<good[i]<<"  sum= "<<sum[i]<<endl;
    	}
    	for(int i=1;i<100001;i++)
    	{
    		if(good[i]==1) g[cc++]=i;
    	}
    	//cout<<"cc= "<<cc<<endl;
    	//cerr<<"here\n";
    	//for(int i=1;i<100001;i++)
    //	{
    //		if(good[i]==1) cout<<i<<endl;
    //	}
        for(int i=0;i<cc;i++)
        {
           cout<<i+1<<". "<<g[i]<<"  "<<sum[g[i]]<<endl;
        }
        return 0;
    	int t; scanf("%d",&t);
    	while(t>0)
    	{
    		int l,r;
    		scanf("%d%d",&l,&r);
    		long long int sumans=0; 
    		for(int i=0;i<cc;i++)
    		{
    			if(g[i]<=r && g[i]>=l) sumans+=sum[g[i]];
    			if(g[i]>r) break;
    		}
    		printf("%lld\n",sumans);			
    		t--;
    	}
    	return 0;
    } 