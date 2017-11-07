#include <bits/stdc++.h>
using namespace std;
int main()
{
	char s[50004];
	cin>>s;
	int length=strlen(s);
	int flag=1;
	if(length<26)
	{
		flag=0;
	}
	else
	{
		for(int i=0;i<=length-26;i++)
		{
			flag=1;
			int ct[26]={0};
			for(int j=i;j<i+26;j++)
			{
				if(s[j]!='?') ct[s[j]-'A']++;
			}
			for(int j=0;j<26;j++)
			{
				if(ct[j]>1)
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				for(int j=0;j<length;j++)
				{
					if(j>=i && j<i+26)
					{
						if(s[j]=='?')
						{
							for(int k=0;k<26;k++)
							{
								if(ct[k]==0)
								{
									s[j]=(char)('A'+k);
									ct[k]++;
									break;
								}
							}
						}
					}
					else 
					{
						if(s[j]=='?') s[j]='A';
					}
				}
			}
			if(flag==1) break;
		}
	}
	if(flag==1) cout<<s<<endl;
	else printf("-1\n");
		
	return 0;
}