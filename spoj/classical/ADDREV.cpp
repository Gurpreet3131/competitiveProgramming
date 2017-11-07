#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		char a[31]={'0'},b[31]={'0'};
        int result[32]={'0'},carry=0;
		int a2[31]={0},b2[31]={0};      
		scanf("%s",a);
        scanf("%s",b);
        int l1=strlen(a);
        int l2=strlen(b);
		int index=30,startb2=30,starta2;
		for(int i=0;i<l1;i++)
		{
			a2[index]=a[i]-'0';
			index--;
		}
		starta2=index+1;
		index=30;
		for(int i=0;i<l2;i++)
		{
			b2[index]=b[i]-'0';
			index--;
		}
		startb2=index+1;
		int stop=starta2<startb2?starta2:startb2;  
		int constop=stop;      
        for(int i=30;i>=stop;i--)
        {
            result[i+1]=a2[i]+b2[i]+carry;
			carry=0;
            if(result[i+1]>9)
            {
                carry=(result[i+1]/10);
                result[i+1]=result[i+1]%10;
            } 
			//cout<<i+1<<"  "<<result[i+1]<<endl; 
            if(i==stop && carry!=0)
			{
				result[i]=carry;
				constop--;
				//cout<<i<<"  "<<result[i]<<endl; 
			}
			
        }
		
		int set=0;
		int st=31,en=31,fin=31;
        for(int i=31;i>constop;i--)
        {
        	if(set==0)	
			{
				if(result[i]!=0) 
				{set=1; st=i;}
				else continue; 
			}    
			if(set==1)
			{
				if(result[i]!=0) en=i;
			}
       	}
		for(int i=st;i>=en;i--) cout<<result[i];
        cout<<endl;		
		t--;
	}
	return 0;
}