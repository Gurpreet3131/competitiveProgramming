#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	char s[201]={0};
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		scanf("%s",s);
		int length=strlen(s);
		for(int i=0;i<n;i++)
		{
			printf("%c",s[i]);
			int j=2*n;
			while(j<=length)
			{
				if(j-i-1<length) printf("%c",s[j-i-1]);
				if(j+1<length) printf("%c",s[j+i]);
				j+=2*n;
			}
		}
		printf("\n");
	}
	return 0;
}