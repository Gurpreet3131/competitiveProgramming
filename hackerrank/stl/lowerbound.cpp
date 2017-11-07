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
	vector<int>::iterator low;
	int q; scanf("%d",&q);
	while(q-->0)
	{
		int value; scanf("%d",&value);
		low=lower_bound(v.begin(),v.end(),value);
		if(v[low-v.begin()]==value)	printf("Yes %d\n",low-v.begin()+1);
		else printf("No %d\n",low-v.begin()+1);
	}
	return 0;
}