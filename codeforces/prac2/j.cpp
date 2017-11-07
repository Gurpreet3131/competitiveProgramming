#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin>>n;
	long long int odd,even,ans=0;
	even=n/2;
	if(n%2==0) odd=n/2;
	else odd=n/2+1;
	if(n<=2) ans=0;
	else 
	{
		ans=(odd*(odd-1))/2;
		ans*=even;
		if(n>5)
		{
			ans+=(even*(even-1)*(even-2))/6;
		}
	}
	cout<<ans<<endl;
	return 0;
}
