#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> v;
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int val; scanf("%d",&val);
		v.push_back(val);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++) 
	{
		printf("%d ",v[i]);
	}
	return 0;
}