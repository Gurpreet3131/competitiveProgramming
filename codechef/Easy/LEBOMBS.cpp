#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
       	int n,count=0; char s[1004];
		scanf("%d%s",&n,s); 
        if(n==1) 
        {
            if(s[0]=='0') count++;
        }
        else
        {
		    for(int i=0;i<n;i++)
            {
                if(i==0)
                {
                    if(s[i]=='0' && s[i+1]=='0') count++;
                }
                else if(i==n-1)
                {
                    if(s[i]=='0' && s[i-1]=='0') count++;
                }
                else
                {
                    if(s[i]=='0' && s[i+1]=='0' && s[i-1]=='0') count++;    
                }
            }       
         }
		printf("%d\n",count);
       	t--;
	}
	return 0;
}
