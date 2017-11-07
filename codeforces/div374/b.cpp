#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	int ct[110]={0};
	scanf("%d%d",&n,&k);
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		ct[s.length()]++;
	}
	cin>>s;
	int ansl=s.length(), best,worst,tt=0,con=0;
	for(int i=1;i<101;i++)
	{
		while(ct[i]>0)
		{
			if(i<ansl)
			{
				ct[i]--; tt++; con++;
			}
			else if(i == ansl) break;
			if(con==k)
			{
				tt+=5; con=0;
			}
		}
		if(i==ansl) break;
	}
	best = tt+1;
	while(ct[ansl]>0)
	{
		ct[ansl]--; tt++; con++;
		if(ct[ansl]==0) break;
		if(con==k)
		{
			tt+=5;
			con=0;
		}
	}
	worst=tt;
	printf("%d %d\n",best,worst);
	return 0;
}