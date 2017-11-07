#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin>>n;
	string s; cin>>s;
	int pcount=0, maxword=0;
	int popen = 0, wlen=0, pwc=0;
	for(int i=0;i<n;i++)
	{
		if(popen == 1)
		{
			if(s[i] == '_')
			{
				if(wlen>>0) pwc++;
				wlen = 0; 
			}
			else if(s[i]==')')
			{
				if(wlen>0)
				{
					pwc++;
				}
				wlen = 0;
				popen=0;
			}
			else wlen++;
		}
		else if(s[i] == '(')
		{
			popen=1;
			if(wlen > 0) 
			{
				if(wlen>maxword) maxword = wlen;
			}
			wlen = 0;
		}
		else if(i == 0)
		{
			if(s[i]!='_') wlen++;
		}
		else if(i == n-1) 
		{
			if(s[i]!= '_') wlen++;
			if(wlen>0 && wlen>maxword) maxword=wlen;
			wlen = 0;
		}
		else if(s[i] == '_')
		{
			if(wlen>0 && wlen>maxword) maxword=wlen;
			wlen = 0;
		}
		else wlen++;
	}
	if(wlen>0 && wlen>maxword) maxword=wlen; 
	printf("%d %d\n",maxword,pwc);
	return 0;
}