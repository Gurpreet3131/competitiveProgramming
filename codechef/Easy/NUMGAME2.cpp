#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
  	int t; cin>>t;
   	while(t>0)
   	{
   		int n; cin>>n;
   		if((n-1)%4==0) printf("ALICE\n");
   		else printf("BOB\n");
   		t--;
   	}
   	return 0;
} 
