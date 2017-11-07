#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n; scanf("%d",&n);
	int a[1001]={0},stack[1001]={0};
	while(n!=0)
	{
		int next=1,top=0,flag=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=next)
			{
				if(top==0) stack[top++]=a[i];
				else if(top>0)
				{
					if(stack[top-1]==next)
					{
						i--; top--;
						next++;
					}
					else
					{
						stack[top++]=a[i];
					}
				}
				else 
				{
					flag=0; break;
				}
				if(top>1)
				{
					if(stack[top-1]>stack[top-2])
					{
						flag=0; break;
					}
				}
			}
			else next++;
		}
		if(flag==0) printf("no\n");
		else printf("yes\n");
		scanf("%d",&n);
	}
	return 0;
}