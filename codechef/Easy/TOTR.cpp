#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
   	//int t;  
	char letter[]="qwertyuiopasdfghjklzxcvbnm",allalpha[52];
	//scanf("%d%s",&t,letter);
	for(int i=0;i<26;i++)
	{
		allalpha[i]=letter[i];
		allalpha[i+26]=letter[i]-32;
	}
	char str[102];
	scanf("%s",str);
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]>96 && str[i]<123) str[i]=allalpha[(int)str[i]-97];
		else if(str[i]>64 && str[i]<91) str[i]=allalpha[(int)str[i]-65+26];
		else if(str[i]=='_') str[i]=' ';
	}		
	printf("%s\n",str);		
	return 0;
}
