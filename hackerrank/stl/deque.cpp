#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <deque>
using namespace std;
int n,k,a[10001];
void findmax()
{
	deque<int> dqueue;
	int i;
	for(i=0;i<k;i++)
	{
		while((!dqueue.empty()) && a[i]>=a[dqueue.back()])
			dqueue.pop_back();

		dqueue.push_back(i);
	}	
	printf("%d ",a[dqueue.front()]);
	for(;i<n;i++)
	{
		while((!dqueue.empty()) && dqueue.front()<=i-k)
			dqueue.pop_front();

		while((!dqueue.empty()) && a[i]>=a[dqueue.back()])
			dqueue.pop_back();

		dqueue.push_back(i);
		printf("%d ",a[dqueue.front()]);
	}
	printf("\n");
}
int main()
{
	int t; scanf("%d",&t);
	//map<string,int>::iterator itr;		
	while(t-->0)
	{
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		findmax();
	}
	return 0;
}