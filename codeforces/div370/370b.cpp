#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main()
{
	int u=0,d=0,l=0,r=0;
	char s[100004];
	scanf("%s",s);
	int length=strlen(s);
	if(length%2!=0)
	{
		printf("-1");
	}
	else
	{
		for(int i=0;i<length;i++)
		{
			if(s[i]=='U') u++;
			else if(s[i]=='D') d++;
			else if(s[i]=='L') l++;
			else if(s[i]=='R') r++;
		}
		int move=0,n=length,cc=0,ext=0;
		move+= min(l,r);
		l-=move; r-=move;
		int temp=min(u,d);
		move+=temp;
		u-=temp; d-=temp;
		if(max(l,r)%2==0) ext=0,cc+=max(l,r)/2;
		else ext=1,cc+=(max(l,r)-1)/2;
		if(max(u,d)%2==0 && ext==0)
		{
			cc+=max(u,d)/2;
		}
		else if(max(u,d)%2!=0 && ext==1)
		{
			cc+=(max(u,d)-1)/2;
			cc+=1;
		}
		printf("%d",cc); 

	}
	
	return 0;
}