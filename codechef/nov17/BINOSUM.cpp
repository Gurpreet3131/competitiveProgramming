#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int size = 10000001;
//long long int ans[size];
long long int fact[size], dcl[size];
long long int dpa[size], dpd[size];

long long int powermod(lli a, lli n, lli mod)
{
	lli result = 1;
	while(n > 0)
	{
		if(n % 2 == 1)
			result = (result * a) % mod;
		a = (a * a) % mod;
		n = n / 2;
	}
	return result;
}

long long int ncr(lli n, lli r, lli mod)
{
	lli ans = powermod(fact[n - r],mod - 2, mod) * powermod(fact[r], mod - 2, mod);
	if(ans >= mod) ans %= mod;
	ans = (ans * fact[n]) % mod;
	return ans;
}

int main()
{
	long long int k, a, p, q;
	scanf("%lld%lld%lld%lld", &k, &a, &p, &q);
	fact[0] = 1;
	for(long long int i = 1; i < size; i++)
	{
		fact[i] = (fact[i - 1] * i) % p;
	}
	if(k == 2)
	{
		while(q--)
		{
			long long int l,d ,t;
			scanf("%lld%lld%lld",&l,&d,&t);
			long long int sumdcl = 0, answer;
			long long int dd = d + t, ll = l + 1;
			sumdcl = ncr(dd, ll, p);
			dd = d; ll = l + 1;
			if(dd >= ll) sumdcl -= ncr(dd, ll, p);
			sumdcl += p;
			if(sumdcl >= p) sumdcl %= p;
			printf("%lld\n",answer);
		}
	}
	while(q--)
	{
		long long int l,d ,t;
		scanf("%lld%lld%lld",&l,&d,&t);
		long long int sumdcl = 0, answer;

		dpa[t - 1] = a; dpd[t - 1] = d;
		
		for(int i = t - 2; i >= 0; i++)
		{
			dpa[i] = (a * (dpa[i + 1] + dpd[i+1])) % p;
			dpd[i] = (d * (dpa[i + 1])) % p;
		}	
		for(long long int i = 0; i < t; i++)
		{
			if(i == 0)
			{
				dcl[i] = powermod(fact[d - l],p - 2, p) * powermod(fact[l], p - 2, p);
				if(dcl[i] >= p) dcl[i] %= p;
				dcl[i] = (dcl[i] * fact[d]) % p;
			}
			else
			{
				dcl[i] = (d + i) * (powermod(d + i - l, p - 2, p));
				if(dcl[i] >=p) dcl[i] %= p;
				dcl[i] = (dcl[i] * dcl[i - 1]) % p;
			}		
			sumdcl += dcl[i];
			if(sumdcl >= p) sumdcl %= p;
		}
		//cout << sumdcl << endl;
		if(k == 1)
		{
			answer = sumdcl;
		}
		else
		{

		}
		printf("%lld\n",answer);
	}
	return 0;
}