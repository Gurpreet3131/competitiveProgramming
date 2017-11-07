#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#define big 1000000009
using namespace std;
long long int operation(long long int num,long long int x)
{
	long long int count=0;
	while(num!=x)
	{
//		cout<<num<<" ";
		if(num<x) 
		{
			count+=x-num;
			break;
		}
		else 
		{
			if(num/2 >= x)
			{
				num/=2; count++;
			}
			else
			{
				long long int op1=1,op2=1,temp=num;
				temp/=2;
				op1+=x-temp;
				temp=num; 
				op2+=2*x-temp;
				if(op1<op2) count+=op1;
				else count+=op2;
				num=x;
			}
		}
	}
	return count;
}
int main()
{
	int t;
	long long int a[100003];
	scanf("%d",&t);
	while(t-->0)
	{
		int n; scanf("%d",&n);
		long long int mx=0;
		for(int i=0;i<n;i++) 
		{
			scanf("%lld",&a[i]);
			if(a[i]>mx) mx=a[i];
		}	
		long long int start=0,end=mx;
		long long int minop=big,x=(start+end)/2,op,l,r;
		if(n==1) minop=0;
		else
		{
			while(1)
			{
				//cout<<x<<endl;
				op=0; l=0; r=0;
				for(int i=0;i<n;i++)
				{	
					op+=operation(a[i],x);
					l+=operation(a[i],x-1);
					r+=operation(a[i],x+1);		
				}
				//cout<<"left= "<<l<<" op= "<<op<<" right= "<<r<<endl;
				minop=min(minop,min(op,min(l,r)));
				if(l<=op && op<=r)
				{
					end=x;
					x=(start+end)/2;
				}				
				else if(l>=op && op>=r)
				{
					start=x; x=(start+end)/2;
				}
				else if(op<=l && op<=r)
				{
					if(l<r) end=x;
					else start=x;
					x=(start+end)/2;
				} 
				//cout<<start<<" "<<end<<endl;
				if(end-start<=1) break;
			}
		}
 		printf("%lld\n",minop);
	}
	return 0;
}