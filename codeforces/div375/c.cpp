#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,ct[2001]={0},a[2002];
	scanf("%d%d",&n,&m);
	queue<int> q;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>m) q.push(i);
		else ct[a[i]]++;
	}
	int mini= 5000, minindex=0, val = n/m,ch=0,flag=0;
	while(!q.empty())
	{
		mini = 5000;
		for(int i=1;i<=m;i++)
		{
			if(mini > ct[i] && ct[i]<val)
			{
				mini = ct[i];
				minindex=i;
			}	
		}
		int ind = q.front(); q.pop();
		if(mini == 5000)
		{
			flag=1; break;
		}
		ct[minindex]++;
		a[ind] = minindex;
		ch++;
	}
	if(flag==0)
	{
		vector<int>b;
		vector <int>s;
		for(int i=1;i<=m;i++)
		{
			if(ct[i]>val) b.push_back(i);
			else if( (ct[i]) < val) s.push_back(i);
		}
		for(int i=0;i<s.size();i++)
		{
			while(ct[s[i]]<val)
			{
				int maxct=0,maxind;
				for(int j=0;j<b.size();j++)
				{
					if(ct[b[j]] > maxct)
					{
						maxct = ct[b[j]];
						maxind = b[j];
					}
				}
				ct[maxind]--;
				ct[s[i]]++;
				for(int j=0;j<n;j++)
				{
					if(a[j] == maxind)
					{
						a[j] = s[i];
						break;
					}
				}
				ch++;
			}	
		}
	}
	int minval = 5000;
	for(int i=1;i<=m;i++) if(ct[i]<minval) minval=ct[i];
	printf("%d %d\n",minval,ch);
	for(int i=0;i<n;i++) printf("%d ",a[i]);
	cout<<endl;
	return 0;
}