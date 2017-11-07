#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		string l1,l2,l3;
		long long int ind =0,n,flag=0;		
		cin>>l1>>l2>>l3>>n;
		int c1=0,c2=0,c3=0;
		for(int i=l3.size()-1;i>=0;i--)
		{
			 if(l3[i] == '0') flag =3; 
			 else c3++;
		}
		for(int i=l2.size()-1;i>=0;i--) 
			if(l2[i] == '1') c2++; 

		for(int i=l1.size()-1;i>=0;i--) 
			if(l1[i] == '1') c1++;

		if(flag == 0)
		{
			for(int i=l2.size()-1;i>=0;i--)
			{	
				if(l2[i] == '0')
				{
					flag =2; break;
				}	
			}		
		}
		if(flag==0)
		{
			for(int i=l1.size()-1;i>=0;i--)
			{
				if(l1[i] == '0')
				{
				 	flag =1; break;
			 	}	
			}	
		}
		int ct=0,f=0;

		if(flag == 3)
		{
			ct += c1+(c2*n);
			for(int i=l3.size()-1;i>=0;i--)
			{
				if(f==0)
				{
					if(l3[i]=='0') f=1;
				}
				else
				{
					if(l3[i]=='1') ct++;
				}
			}
		}		
		else if(flag==2)
		{
			ct += c1+(c2*(n-1));
			for(int i=l2.size()-1;i>=0;i--)
			{
				if(f==0)
				{
					if(l2[i]=='0') f=1;
				}
				else
				{
					if(l2[i]=='1') ct++;
				}
			}
		}
		else if(flag==1)
		{
			for(int i=l1.size()-1;i>=0;i--)
			{
				if(f==0)
				{
					if(l1[i]=='0') f=1;
				}
				else
				{
					if(l1[i]=='1') ct++;
				}
			}
		}
		printf("%d\n",ct+1);
	}
	return 0;
}