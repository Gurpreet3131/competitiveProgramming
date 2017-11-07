#include<bits/stdc++.h>
#include<string.h>
#define big 1000000005
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	long long int powfive[20]={0};
	powfive[0]=1;
	for(int i=1;i<20;i++)
	{
		powfive[i]=powfive[i-1]*5;
		//cout<<powfive[i]<<endl;
	}
	while(t>0)
	{
		long long int k,dig=1;
		scanf("%lld",&k);
		for(int i=1;i<20;i++)
		{
			if(k>powfive[i])
			{
				dig++;
			}
			else break;
		}
		//cout<<"dig= "<<dig<<endl;
		int num[20]={0},index=0;
		for(int i=1;i<=dig;i++)
		{
			long long int temp;
			temp=((k-1)/powfive[i-1])%5;
			//cout<<"temp= "<<temp<<endl;
			num[index++]=2*temp;
		}
		for(int i=index-1;i>=0;i--) printf("%d",num[i]);
		cout<<endl;
		t--;
	}
	return 0;
}