#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		int k,ascii=97; 		scanf("%d",&k);
		char s[105];
		for(int i=0;i<=k;i++)
            	{
                	s[i]=(char)ascii;
			ascii++;
			if(ascii==123) 
                	{
                    		if(i==k) break;
                    		ascii=97;
                    		i++;k++;
                    		s[i]=(char)ascii;
                    		ascii++;
                	}
            	}
            	for(int i=k;i>=0;i--) printf("%c",s[i]);
            	printf("\n");
   		t--;
	}
	return 0;
}
