#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	char s[200];
	scanf("%s",s);
	int length=strlen(s),flag=0,power=0,eindex,iindex;
	for(int i=0;i<length;i++)
	{
		if(s[i]=='e') flag=1,eindex=i;
		//cout<<flag<<endl;
		if(flag==0 || s[i]=='e') continue;
		int dig=s[i]-'0';
		power=10*power+dig; 
	}
	if(power==0)
	{
		//cout<<"power=0\n";
		flag=0;
		for(int i=0;i<length;i++)
		{
			if(flag==0)
			{
				if(s[i]=='e') break;
				if(s[i]=='.') flag=1;
				else printf("%c",s[i]);
			} 
			else if(flag==1)
			{
				if(s[i]=='e') break;
				else if(s[i]!='0') printf("%c%c",s[i-1],s[i]),flag=2;
				else if(s[i]=='0' && i+1<length)
				{
					int nzero=0;
					for(int j=i+1;j<length;j++)
					{
						if(s[j]=='e') break;
						else if(s[j]!='0') 
						{
							nzero=j; break;
						}
					}
					if(nzero!=0) printf("%c%c",s[i-1],s[i]),flag=2;
					else break;
				} 
			}
			else if(flag==2)
			{
				int last=eindex;
				for(int j=last-1;j>=i;j--)
				{
					if(s[j]!='0') {last=j; break; }
				}
				if(last>=i && last!=eindex)
				{
					for(int j=i;j<=last;j++)
					{
						printf("%c",s[j]);
					}
				}
				break;
			}
		}
		cout<<endl;
	}
	else
	{
		flag=0;
		for(int i=0;i<length;i++)
		{
			if(flag==0)
			{
				if(s[i]=='e')
				{
					while(power>0)
					{
						printf("0");
						power--;
					}
					break;
				}
				if(s[i]=='.') flag=1;
				else printf("%c",s[i]);
			} 
			else if(flag==1)
			{
				if(power>0)
				{
					if(s[i]=='e')
					{
						s[i+1]='e'; eindex=i+1;
						length++;
						s[i]='.';
						printf("0");
						power--;
						//cout<<"power="<<power<<endl;
					}
					else
					{
						char temp=s[i-1];
						s[i-1]=s[i]; s[i]=temp;
						printf("%c",s[i-1]);
						power--;
					}
				}
				if(power==0) flag=2;
				//cout<<"flag="<<flag<<endl;
			}
			else if(flag==2)
			{
				if(s[i]=='e') break;
				else if(s[i]!='0') printf("%c%c",s[i-1],s[i]),flag=3;
				else if(s[i]=='0' && i+1<length)
				{
					int nzero=0;
					for(int j=i+1;j<length;j++)
					{
						if(s[j]=='e') break;
						else if(s[j]!='0') 
						{
							nzero=j; break;
						}
					}
					if(nzero!=0) printf("%c%c",s[i-1],s[i]),flag=3;
					else break;
				} 
			}
			else if(flag==3)
			{
				int last=eindex;
				for(int j=last-1;j>=i;j--)
				{
					if(s[j]!='0') {last=j; break; }
				}
				if(last>=i && last!=eindex)
				{
					for(int j=i;j<=last;j++)
					{
						printf("%c",s[j]);
					}
				}
				break;
			}
		}
		cout<<endl;
	}
	return 0;
}