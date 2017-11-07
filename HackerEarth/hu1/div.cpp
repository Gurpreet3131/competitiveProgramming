#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m; cin>>n>>m;
	long long int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		//if(a[i] == 0) continue;
		//if(184889%a[i]==0) cout<<a[i]<<endl;
	}
	m=3;
	while(m--)
	{
		int ind; scanf("%d",&ind);
		long long int mini = a[ind];
		cout<<m<<" here"<<endl;
		cout<<a[ind]<<endl;
		for(int i=1;i<=n;i++)
		{
			if(a[i] == 1 || a[i] == 0) continue;
			if(a[ind]%a[i] == 0) 
			{
				if(a[i] <mini)
				{
					mini = a[i];
					cout<<"mini changed = "<<mini<<endl;
				}
			}
		}
		if(m%100000==0) cout<<m<<endl;
		if(mini == a[ind]) printf("-1\n");
		else printf("%lld\n",mini);
	}
	return 0;
}