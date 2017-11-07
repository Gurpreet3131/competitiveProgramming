#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
    	long long int n,m;
    	scanf("%lld%lld",&n,&m);
    	if( n == 1) 
    	{
    		if(m>=1) printf("YES\n");
    		else printf("NO\n");
    		continue;
    	}
        double lg = log2(n);
        int answer = lg;
        if(lg - (int)lg != 0.0)
            answer = (int)lg + 1;
    	if(m>=answer) printf("YES\n");
    	else printf("NO\n");
    }
    return 0;
}
