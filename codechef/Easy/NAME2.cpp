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
        char m[25002],w[25002];
		int result=0,index=0;
		scanf("%s%s",m,w);
		if(strlen(m)>strlen(w))
		{
			for(int i=0;i<strlen(m);i++)
			{
				if(m[i]==w[index]) index++;
				if(index==strlen(w)) break;
			}    
			if(index==strlen(w)) result=1;
		}
		else
		{
			for(int i=0;i<strlen(w);i++)
			{	
				if(w[i]==m[index]) index++;
				if(index==strlen(m)) break;
			}    
			if(index==strlen(m)) result=1;
		}
		if(result==1) printf("YES\n");
		else printf("NO\n");
        t--;
    }
	return 0;
}
