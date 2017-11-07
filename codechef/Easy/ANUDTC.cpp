#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t>0)
	{
		int n; cin>>n;
		if(360%n==0)
		{
			cout<<"y"<<" ";
		}
		else cout<<"n"<<" ";
		if(n<=360) cout<<"y"<<" ";
		else cout<<"n"<<" ";
		if(n<27) cout<<"y"<<" "<<endl;
		else cout<<"n"<<" "<<endl;
		t--;
	}
	return 0;
}
