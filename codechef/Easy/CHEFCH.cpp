#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		char s[100001];		
		scanf("%s",s);
		int count1=0,count2=0,length=strlen(s);
		char ch='-',ch2='+';
		for(int i=0;i<length;i++)
		{
			if(i%2==0)
			{
				if(s[i]==ch2) count1++;
				if(s[i]==ch) count2++;
			}
			else
			{
				if(s[i]==ch) count1++;
				if(s[i]==ch2) count2++;
			}
		}
		int min=count1<count2?count1:count2;
		printf("%d\n",min);
		t--;
	}
	
	return 0;
}
