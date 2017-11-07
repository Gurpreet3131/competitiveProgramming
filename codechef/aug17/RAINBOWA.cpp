#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	int a[200];	
	while(t--)
	{
		int n; scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int flag = 1, cur = 1, ct[8] = {0};
		for(int i=0, j=n-1; i<=j; i++, j--)
		{	
			if(a[i] == a[j])
			{
				ct[a[i]]++;
				if(a[i] == cur) continue;
				else if(a[i] == cur+1 && cur<7 && ct[cur] > 0) cur++; 
				else 
				{
					flag = 0; break;
				}				
			}
			else
			{
				flag = 0; break;
			}
		}
		sort(a,a+n);
		if(flag == 1)
		{
			if(a[n-1] != 7) flag = 0; 
		}
		if(flag == 1) printf("yes\n");
		else printf("no\n");
	}
	return 0;	
}