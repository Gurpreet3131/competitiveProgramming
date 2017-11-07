#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	double c;
	cin>>c;
	double a[300]={0}; a[0]=0;
	for(int i=1;i<300;i++)
	{
		a[i]=a[i-1]+(1/(double)(i+1));
		//cout<<a[i]<<endl;
	}
	while(c!=0.00)
	{
		int pos=0;
		for(int i=1;i<300;i++)
		{
			if(a[i]>c)
			{
				pos=i; break;	
			} 
		}
		printf("%d card(s)\n",pos);
		cin>>c;
	}
}