#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,s;
	cin >> n >> s;
	string smin = "", smax="";
	int maxsum = n*9;
	if(maxsum<s) cout<<"-1 -1\n";
	else if(n>1 && s == 0) cout<<"-1 -1\n";
	else if(s == 0) cout<<"0 0\n";
	else 
	{
		int temp = s, tempn=n, ct=0;
		while(tempn-->0)
		{
			if(temp > 9)
			{
				temp-=9; smax+= '9';
			}
			else
			{
				smax+= (char)temp+'0'; temp = 0;
				if(smax[smax.length()-1] == '0') ct++;
			}
		}
		if(ct > 0)
		{
			smin+='1';
			temp =s-1; n--;
			while(n>0)
			{
				int dig = (temp/9), r=temp%9;
				if(r!=0) dig++;
				if(n>dig) smin+='0';
				else
				{
					if(r == 0) smin+='9',temp-=9;
					else smin+=(char)r+'0', temp-=r;
				}
				n--;
			}
		}
		else
		{
			for(int i=smax.length()-1;i>=0;i--)
			{
				smin+= smax[i];
			}
		}
	}
	cout<<smin<<" "<<smax<<endl; 
	return 0;
}