#include<bits/stdc++.h>
using namespace std;
int main()
{
	int fact[101][200],index[101]={0};
	fact[0][0]=1; index[0]=1;
	for(int i=1;i<101;i++)
	{
		long long int temp=0,num=i,pos=0;
		for(int j=0;j<index[i-1];j++)
		{
			
			temp=fact[i-1][j]*num+temp;
			fact[i][j]=temp%10;
			temp/=10;
			index[i]++;
			pos=j;
		}
		while(temp>0)
		{
			fact[i][++pos]=temp%10;
			temp/=10;
			index[i]++;
		}
	}
	int t; scanf("%d",&t);
	while(t>0)
	{
		int n; scanf("%d",&n);
		//cout<<index[n]<<endl;
		for(int i=index[n]-1;i>=0;i--)
		{
			printf("%d",fact[n][i]);
		}
		printf("\n");
		t--;
	}
	return 0;
}
