#include <bits/stdc++.h>
using namespace std;
long long int trib[40];
int main()
{
	trib[0]=0; trib[1]=0; trib[2]=1;
	for(int i=3;i<=30;i++)
	{
		trib[i] = trib[i-1]+trib[i-2]+trib[i-3];
	}
	int t; cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<trib[n]<<endl;
	}
	return 0;
}