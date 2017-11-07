#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	long long int a[100001]={0},a2[100001],a5[100001];
	while(t--)
	{
		int n,m; cin>>n>>m;
		long long int ans=0,ans2=0,ans5=0;
		for(int i=1;i<=n;i++)
		{
			a2[i]=0; a5[i]=0;
			scanf("%lld",&a[i]);
			long long int temp = a[i];
			while(temp%2==0)
			{
				a2[i]++; temp/=2;
			}
			while(temp%5==0)
			{
				a5[i]++; temp/=5;
			}
			cout<<i<<" "<<a2[i]<<" "<<a5[i]<<endl;
		}
		for(int i=1;i<=m;i++)
		{
			int type,l,r;
			scanf("%d%d%d",&type,&l,&r);
			if(type==1)
			{
				long long int x; scanf("%lld",&x);
				long long int c2=0,c5=0,temp=x;
				while(temp%2==0)
				{
					c2++; temp/=2;
				}
				while(temp%5==0)
				{
					c5++; temp/=5;
				}
				cout<<"x= "<<c2<<" "<<c5<<endl;
				for(int i=l;i<=r;i++)
				{
					a2[i]+=c2; a5[i]+=c5;
				}

			}
			else if(type==2)
			{
				long long int y; scanf("%lld",&y);
				long long int c2=0,c5=0,temp=y;
				while(temp%2==0)
				{
					c2++; temp/=2;
				}
				while(temp%5==0)
				{
					c5++; temp/=5;
				}
				cout<<"y= "<<c2<<" "<<c5<<endl;
				for(int i=l;i<=r;i++)
				{
					long long c2i=0,c5i=0,temp = i-l+1;
					while(temp%2==0)
					{
						c2i++; temp/=2;
					}
					while(temp%5==0)
					{
						c5i++; temp/=5;
					}
					a2[i]=c2+c2i; a5[i]=c5+c5i;
				}
			}
			else 
			{
				ans2=0; ans5=0;
				for(int i=l;i<=r;i++)
				{
					ans2+=a2[i]; ans5+=a5[i];
				}
				ans+=min(ans2,ans5);
				cout<<"ans= "<<ans<<endl;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}