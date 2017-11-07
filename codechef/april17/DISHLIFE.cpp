#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a[100002]={0};
		int n,k; cin>>n>>k;
		int ct = 0, flag = 0;
		for(int i=0;i<n;i++)
		{
			int p; scanf("%d",&p);
			for(int j=0;j<p;j++)
			{
				int val; scanf("%d",&val);
				a[val]++;
				if(a[val] == 1) ct++;
			}
			if(ct == k && i<n-1) flag = 1; 
		}
		//cout<<flag <<endl;
		int zflag = 0;
		for(int i=1;i<=k;i++)
		{
			if(a[i] == 0)
			{
				zflag = 1; break;
			}
		}
		if(zflag == 1) printf("sad\n");
		else if(flag == 1) printf("some\n");
		else printf("all\n");

	}
	return 0;
}