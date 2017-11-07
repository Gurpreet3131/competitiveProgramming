#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	long long int a[501]={0};
	while(t>0)
	{
		int n,xorr=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			xorr=xorr^a[i];
		}
		if(xorr==0 || n%2==0)	cout<<"First\n";
		else cout<<"Second\n";
		//cout<<xorr<<endl;
		t--;
	}
}