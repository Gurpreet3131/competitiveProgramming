#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
   	int t;  scanf("%d",&t);
    while(t>0)
    {
        char j[101],s[101];
		int containj[52]={0},count=0;
		scanf("%s%s",j,s);
		for(int i=0;i<strlen(j);i++)
		{
			if(j[i]>96) containj[j[i]-'a']=1;
			else
			{
				containj[j[i]-'A'+26]=1;
			}
		}
		
		for(int i=0;i<strlen(s);i++)
		{
			if(s[i]>96) 
			{
				if(containj[s[i]-'a']==1) count++;
			}
			else
			{
				if(containj[s[i]-'A'+26]==1) count++;
			}		
		}
		printf("%d\n",count);
        t--;
    }
	return 0;
}
