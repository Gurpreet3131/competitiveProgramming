#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    int t; scanf("%d",&t);
	while(t>0)
	{
		int n,score=0;
		char name[101][21],vote[101];
		scanf("%d",&n);
		for(int i=0;i<n;i++)	
		{
			cin>>name[i]>>vote[i];
			//scanf("%s%c",name[i],&vote[i]);			
			for(int j=i-1;j>=0;j--)
			{
				if(strcmp(name[i],name[j])==0)
				{
					if(vote[j]=='+') score--;
					else score++;
					break;
				}
			}
			if(vote[i]=='+') score++;
			else score--;
		}
		printf("%d\n",score);
       	t--;
	}
	return 0;
}
