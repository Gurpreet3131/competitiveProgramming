#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t, n=4;
	scanf("%d",&t);
	while(t--)
	{
		string s[4],s2[4];
		int flag[4] = {0};
		for(int i=0;i<n;i++) cin>>s[i];
		for(int i=0;i<n;i++) cin>>s2[i];
		int ct=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(flag[j] == 0)
				{
					if(s[i].compare(s2[j]) == 0) ct++, flag[j] = 1;
				}
			}
		}
		if(ct>=2) printf("similar\n");
		else printf("dissimilar\n");
	}
	return 0;
}