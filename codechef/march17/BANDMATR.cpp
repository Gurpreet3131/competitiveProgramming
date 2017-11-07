#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,a,ct = 0;
		int dif[500] = {0};
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&a);
				if(a == 1) ct++;
				int ind = fabs(i-j);
				dif[ind]++;
			}
		}
		//for(int i=0;i<n;i++) cout<<dif[i]<<endl;
		int ans = 0;
		if(ct == 0) ans = 0;
		else
		{
			while(ct>0)
			{	
				if(ct>dif[ans])
				{
					ct-= dif[ans];
					ans++;
				}
				else ct = 0;
			}		
		}
		

		//if(ct%n == 0)
		{
		//	ans = ct/n; if(ans>0) ans--;
		}
		//else ans = ct/n;
		printf("%d\n",ans);
	}
	return 0;
}