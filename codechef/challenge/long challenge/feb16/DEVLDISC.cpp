#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#define mod 1000000007
using namespace std;
int main()
{
    	int t; scanf("%d",&t);
    	while(t>0)
    	{
			int n;
			scanf("%d",&n);
			if(n>6)
			{
				printf("%d\n",n);
				printf("1 2\n"); printf("2 3\n");
				printf("3 4\n"); printf("4 5\n");
				printf("2 6\n"); printf("4 6\n");				
				int count=6,s=6,e=7;
				while(count!=n)
				{
					printf("%d %d\n",s,e); e++;
					count++;					
				}
				printf("3\n");
				
			}
			else
			{
				printf("-1\n");
			}			    		
			t--;
    	}
    	return 0;
    } 


