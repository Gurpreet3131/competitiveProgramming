#include<bits/stdc++.h>
#define mod 1000000007
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		char s1[1001],s2[1001];
		int count1[26]={0},count2[26]={0};
		scanf("%s%s",s1,s2);
		for(int i=0;i<strlen(s1);i++) count1[s1[i]-'a']++;
		for(int i=0;i<strlen(s2);i++) count2[s2[i]-'a']++;
		int found=0;		
		for(int i=0;i<26;i++)
		{
			if(count1[i]>0 && count2[i]>0) 
			{
				found=1; break;
			}
		}
		if(found==1) printf("Yes\n");
		else printf("No\n");
		t--;
	}	
	return 0;    
}
