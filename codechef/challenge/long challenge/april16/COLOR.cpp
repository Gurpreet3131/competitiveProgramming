#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	char s[100001];
	while(t>0)
	{
		int n; cin>>n;
		scanf("%s",s);
		int r=0,g=0,b=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='R') r++;
			else if(s[i]=='G') g++;
			else if(s[i]=='B') b++;
		}
		int total=r+g+b;
		int ans=max(r,max(g,b));
		ans=total-ans;
		printf("%d\n",ans);
		t--;
	}
	return 0;
}