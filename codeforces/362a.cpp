#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t,s,x;
	scanf("%d%d%d",&t,&s,&x);
	int flag=1;
	if(x<t) flag=0;
	else if(x==t) flag=1;
	else
	{
		int temp=(x-t)/s;
		if(temp==0)
		{
			flag=0; 
		}
		else{
		temp=t+temp*s;
		if(temp==x || temp+1==x) flag=1;
		else flag=0;
		}
	}	
	if(flag==1) printf("YES\n");
	else printf("NO\n");
	return 0;
}