#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{
	int t; char c; scanf("%d%c",&t,&c);
	while(t>0)
	{
	    char s[11]; 
        cin.getline(s,11);
        if(strlen(s)!=5)
        {
            printf("Error\n");
        }        
        else
        {
            if(s[0]>='a' && s[0]<='h' && s[1]>='1' && s[1]<='8' && s[2]=='-' && s[3]>='a' && s[3]<='h' && s[4]>='1' && s[4]<='8')
            {
                if(fabs(s[0]-s[3])==1 && fabs(s[1]-s[4])==2) printf("Yes\n");
                else if(fabs(s[0]-s[3])==2 && fabs(s[1]-s[4])==1) printf("Yes\n");
                else printf("No\n");
                
            }
            else printf("Error\n");            
        }
        t--;
	}
	return 0;
}
