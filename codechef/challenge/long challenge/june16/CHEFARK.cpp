#include<bits/stdc++.h>
#include<string.h>
#define mod 1000000007
using namespace std;
#include<vector> 
long long int fact[100005]={0};
int gcdExtended(int a, int b, int *x, int *y); 
// Function to find modulo inverse of a
int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    //if (g != 1)
       // cout << "Inverse doesn't exist";
    //else
    {
        // m is added to handle negative x
        int res = (x%m + m) % m;
        //cout << "Modular multiplicative inverse is " << res;
    	return res;
    }
}
 
// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
long long int C(int n,int r,int MOD)
{
	long long int ans=fact[n];
	long long int den=(fact[r]*fact[n-r])%MOD;
	if(ans%den==0) 
	{
		ans/=den;
	}
	else
	{
		ans*=(modInverse(den,MOD)%MOD);
	}
	if(ans>=mod) ans%=mod;
	return ans;
}
long long int sigma(int n,int kmin,int kmax)
{
	long long int ans=0;
	for(int i=kmin;i<=kmax;i+=2)
	{
		//cout<<C(n,i,mod)<<endl;
		ans+=C(n,i,mod);
		if(ans>=mod) ans%=mod;
		//cout<<ans<<endl;
	}
	return ans;
}
long long int sigma2(int n,int kmin,int kmax)
{
	long long int ans=0;
	for(int i=kmin;i<=kmax;i++)
	{
		//cout<<C(n,i,mod)<<endl;
		ans+=C(n,i,mod);
		if(ans>=mod) ans%=mod;
	}
	return ans;
}
int main()
{
	fact[0]=1;
	for(int i=1;i<100005;i++)
	{
		fact[i]=i*fact[i-1];
		if(fact[i]>=mod) fact[i]%=mod;
	}
	//for(int i=0;i<=100;i++) cout<<i<<" "<<C(100,i,mod)<<endl;
	int t; scanf("%d",&t);
	int a;
	long long int twopow[100005]; 
	twopow[0]=1;
	for(int i=1;i<100005;i++)
	{
		twopow[i]=twopow[i-1]*2;
		if(twopow[i]>=mod) twopow[i]%=mod;
	}
	while(t>0)
	{
		long long int n,k;
		scanf("%lld%lld",&n,&k);
		int countzero=0,one=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(a==0) countzero++;
		//	if(a>0) one++;
		}
		if(countzero==0)
		{
			if(k==1)
			{
				printf("%lld\n",n);
			}
			else if(k>=n) 
			{
				printf("%lld\n",twopow[n-1]);
			}
			else
			{
				long long int kmin,kmax;
				kmax=k;
				if(k%2==0) kmin=0;
				else kmin=1;
				if(kmin==1 && kmax==n-1) printf("%lld\n",twopow[n-1]);
				else
				{	
					long long int answer=sigma(n,kmin,kmax);
					printf("%lld\n",answer);
				}
			}
		}
		else
		{
			long long int nval=n-countzero;
			if(k==1)
			{
				printf("%lld\n",nval+1);
			}
			else if(k>=nval) 
			{
				printf("%lld\n",twopow[nval]);
			}
			else
			{
				long long int kmin,kmax;
				kmin=0;
				kmax=k;
				if(kmin==0 && kmax==nval) printf("%lld\n",twopow[nval]);
				else
				{	
					long long int answer=sigma2(nval,kmin,kmax);
					if(answer>=mod) answer%=mod;
					printf("%lld\n",answer);
				}
			}
		}
		t--;
	}
	return 0;
}