#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	char light[100005];
	int cord[100005];
	int lg[100005]={0};
	while(t>0)
	{
		int n,first,last,flag=0,indx=0;
		scanf("%d%s",&n,light);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&cord[i]);
			if(light[i]=='1') 
			{
				lg[indx++]=i;
			}
		}
		last=lg[indx-1];
		first=lg[0];
		//for(int i=0;i<indx;i++) cout<<lg[i]<<" ";
		//	cout<<endl;
		long long int minlength=0;
		if(indx==1)
		{
			minlength+=cord[first]-cord[0];
			minlength+=cord[n-1]-cord[last];
		}
		else if(indx==n) minlength=0;
		else
		{
			minlength+=cord[first]-cord[0];
			minlength+=cord[n-1]-cord[last];
			int ind=2;
			int left=0,cur=first,next=lg[1];
			for(int i=1;i<indx;i++)
			{
				cur=lg[i-1]; next=lg[i];
				while(cur<next)
				{
					if(light[cur+1]=='1' || light[next-1]=='1')
					{
						if(light[cur+1]=='1') cur++;
						if(light[next-1]=='1') next--;
					}
					else
					{
						int l1=cord[cur+1]-cord[cur];
						int l2=cord[next]-cord[next-1];
						if(l1<=l2)
						{
							minlength+=l1;
							light[cur+1]='1';
							cur++;
						}
						else
						{
							minlength+=l2;
							light[next-1]='1';
							next--;
						}
					}

				}
			}
		}	
		printf("%lld\n",minlength);
		t--;
	}
    return 0;
}