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
	int a,b;
	scanf("%d",&a);
	v.erase(v.begin()+a-1);
	scanf("%d%d",&a,&b);
	v.erase(v.begin()+a-1,v.begin()+b-1);
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++)
	{
		printf("%d ",v[i]);
	}
	return 0;
}