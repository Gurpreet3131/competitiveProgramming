#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	long long int a[100001]={0};
	while(t>0)
	{
		int n; cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int count=1;
		for(int i=0;i<n;i++)
		{
			if(count>1)
			{
				count--;
				cout<<count<<" ";
				continue;
			}
			count=1;
			for(int j=i;j<n-1;j++)
			{
				if(a[j]*a[j+1]<0) count++;
				else break;
			}
			cout<<count<<" ";
		}
		cout<<endl;
		t--;
	}
}