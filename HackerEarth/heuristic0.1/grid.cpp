#include <bits/stdc++.h>
using namespace std;
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
	if(ct == 0) printf("-1\n");
	else printf("%lld\n",ct);	
	return 0;
}