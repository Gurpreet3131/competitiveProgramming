#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int power(long long int x, unsigned long long int y, int p)
{
    long long int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}
int main()
{
	int t; cin>>t;
	while(t--)
	{
		long long int n; scanf("%lld",&n);
		long long int ans = power(2,n,mod);
		if(n%2 == 0) ans+= power(3,n/2);
		else ans+= power(3,n/2)*();
	} 
}