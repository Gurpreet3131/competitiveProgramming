#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	string s;
	cin>>s;
	int ct=0,length[110]={0};
	int st=0,len=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='W')
		{
			if(len>0) length[ct++]=len;
			len=0;
		}
		else if(s[i]=='B') len++;
	}
	if(len>0) length[ct++]=len;

	printf("%d\n",ct);
	for(int i=0;i<ct;i++)
	{
		printf("%d ",length[i]);
	}
	return 0;
}