#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int l1,r1,l2,r2,k;
	cin>>l1>>r1>>l2>>r2>>k;
	long long int tt=0;
	if(l2>r1) tt=0;
	else if(r2<l1) tt=0;
	else
	{
		tt= min(r1,r2)-max(l1,l2)+1;
		if(k<=min(r1,r2) && k>=max(l1,l2)) tt--;
	}
	cout<<tt<<endl;
	return 0;
}