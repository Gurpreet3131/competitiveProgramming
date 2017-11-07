#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	long long int n,m,a; 
	scanf("%lld%lld%lld",&n,&m,&a);
	long long int x=n/a,y=m/a;
	if(n%a!=0) x++; if(m%a!=0) y++;
	printf("%lld\n",x*y);
}