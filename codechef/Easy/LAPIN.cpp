#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
    while(t>0)
    {
		char *s;
		s=new char[1001];		
		int *pos;
		scanf("%s",s);
		int first[27]={0},second[27]={0},length=strlen(s);
		bool result=true;		
		for(int i=0;i<length/2;i++)
		{
			first[s[i]-96]++;
			second[s[i+((length+1)/2)]-96]++;
		}
		for(int i=1;i<27;i++)
		{
			if(first[i]!=second[i])
			{
				result=false;
				break;
			}
		}
		if(result==true) printf("YES\n");
		else printf("NO\n");
		t--;
	}
	return 0;        
}


