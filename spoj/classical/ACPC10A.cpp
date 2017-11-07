#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	long long int a,b,c,value=0;
	char prog[2]; scanf("%lld%lld%lld",&a,&b,&c);
	while(a!=0 || b!=0 || c!=0)
	{
		if((b-a)==(c-b)) 
		{
			prog[0]='A'; prog[1]='P';
			value=c+(b-a);
		}
		else if((b*b)==(a*c))
		{
			prog[0]='G'; prog[1]='P';	
			value=c*(b/a);
		}
		printf("%c%c %lld\n",prog[0],prog[1],value);
		scanf("%lld%lld%lld",&a,&b,&c);
	}
	return 0;
}