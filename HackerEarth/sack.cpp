#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int max(int a,int b)
{
	return (a>b)?a:b;
}
int knapsack(int W,int wt[], int val[],int n)
{
 	int i,w;
	int k[n+1][W+1];
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			if(i==0|| w==0) k[i][w]=0;
			else if(wt[i-1]<=w) k[i][w]=max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
			else k[i][w]=k[i-1][w];
		}
	}
	return k[n][W];
}
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		int n,W;
		cin>>n>>W;
		int val[n],wt[n];
		for(int i=0;i<n;i++)
		{
			cin>>val[i]>>wt[i];
		}
		cout<<knapsack(W,wt,val,n)<<endl;
		t--;
	}
	return 0;
}
