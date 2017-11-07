#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	char s[1004];
	scanf("%s",s);
	int length=strlen(s),flag=1;
	for(int i=0,j=length-1;i<=j;i++,j--)
	{
		if(s[i]=='A' || s[i]=='H' || s[i]=='I' || s[i]=='M' ||
			s[i]=='O' || s[i]=='T' || s[i]=='U' ||
			s[i]=='V' || s[i]=='W' || s[i]=='X' || s[i]=='Y') 
		{
			if(s[j]!=s[i]) { flag=0; break; } 
		}	
		else if(s[i]=='o' || s[i]=='v' || s[i]=='w' || s[i]=='x')
		{
			if(s[j]!=s[i]) { flag=0; break; }
		}
		else if(s[i]=='b')
		{
			if(s[j]!='d') { flag=0; break; }
		}
		else if(s[i]=='p')
		{
			if(s[j]!='q') { flag=0; break; }
		}
		else if(s[i]=='d')
		{
			if(s[j]!='b') { flag=0; break; }
		}
		else if(s[i]=='q')
		{
			if(s[j]!='p') { flag=0; break; }
		}
		else { flag=0; break; }		
	}
	if(flag==1) printf("TAK\n");
	else printf("NIE\n");
	return 0;
}