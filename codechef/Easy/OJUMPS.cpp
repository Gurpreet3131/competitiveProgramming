#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	long long int a; cin>>a;
	if(a%3==0 || (a-1)%6==0) 	printf("yes\n");
	else printf("no\n");
	return 0;
}
