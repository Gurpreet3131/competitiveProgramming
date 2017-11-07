#include<bits/stdc++.h>
#define mod 1000000007
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
int main()
{
	long long int fact[100001]={0};
	fact[0]=1;
	for(int i=1;i<100001;i++)
	{
		fact[i]=fact[i-1]*i;
		if(fact[i]>=mod) fact[i]%=mod;
	}
	int t; scanf("%d",&t);
	while(t>0)
	{
		long long int sum=0;
		int count[26]={0};
		char s[100001];
		scanf("%s",s);
		long long int length=strlen(s);
		if(length==2)
		{
			if(s[0]==s[1])
			{
				printf("0\n");
			}
			else printf("2\n");
			t--;
			continue;
		}
		for(int i=0;i<length;i++)
		{
			count[s[i]-'a']++;
		}
		sum=length*(length-1);
		if(sum>=mod) sum%=mod;
		sum*=length;  if(sum>=mod) sum%=mod;
		sum*=(length-1); 
		for(int i=0;i<26;i++)
		{
			if(count[i]==0) continue;
			else 
			{
				sum/=fact[count[i]];
			}
		}
		if(sum>=mod) sum+=mod;
		printf("%lld\n",sum);
		t--;
	}
	return 0;    
}
