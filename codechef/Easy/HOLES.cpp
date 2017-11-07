#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
    int main()
    {
        int t;scanf("%d",&t);
        while(t>0)
        {
            char *s;
			s=new char[100];
			scanf("%s",s);
			int holes=0;
            for(int i=0;i<strlen(s);i++)
            {
                if(s[i]=='B') holes+=2;
                else if(s[i]=='A' || s[i]=='D' || s[i]=='O' || s[i]=='P' || s[i]=='Q' || s[i]=='R')
                {
                    holes++;
                }
            }
            printf("%d\n",holes);
            t--;    
        }
	return 0;
    }


