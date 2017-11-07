#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#define min(a,b) a<b?a:b
using namespace std;
int main()
{
	int n,mis=0,chris=0,one,two;	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&one,&two);
		if(one>two) mis++;
		else if(one<two) chris++;
	}
	if(mis>chris) printf("Mishka\n");
	else if(mis<chris) printf("Chris\n");
	else printf("Friendship is magic!^^\n");
	return 0;
}