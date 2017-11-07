#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,x,k; cin>>n>>x>>k;
	long long int a[n], maxind, mx = INT_MIN;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; 
		if(a[i] > mx)
		{
			mx = a[i]; maxind = i;
		}
	}
	for(int i=0;i<k;i++) mx*=x;
	a[maxind] = mx;
	for(int i=0;i<n;i++) mx = a[i] | mx;
	cout<<mx<<endl;
	return 0;
}