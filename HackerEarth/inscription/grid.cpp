#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main()
{
	int n,m; scanf("%d%d",&n,&m);
	string s[502];
	for(int i=0;i<n;i++) cin>>s[i];
	long long int ct=0;
	for(int i=0;i<n-1;i++)
	{
		long long int zero=0;
		for(int j=i+1;j<n;j++)
		{
			zero=0;
			for(int k=0;k<m;k++)
			{
				if(s[i][k] == '0' && s[j][k] == '0') zero++;
			}
			zero--;
			ct+=(zero*(zero+1))/2;
		}
	}
	//cout<<ct<<endl;
	long long int num1,num2,den1,den2;
	if(ct == 0)
	{
		printf("1 1\n");
	}
	else
	{
		num1=ct-1; den1=ct;
		num2 = 5; den2 = 6*ct;
		int lcm = gcd(num2,den2);
		num2/=lcm; den2/=lcm;

		lcm = gcd(den1,den2);
		lcm = (den1)/lcm;
		lcm *=den2;
		
		num1*= lcm/den1;
		num2*= lcm/den2;
		num1 = num1+num2;
		den1 = lcm;
		lcm = gcd(num1,den1);
		num1/=lcm; den1/=lcm;
		printf("%lld %lld\n",num1,den1);
	}
	
	return 0;
}