#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <cmath>
using namespace std;
int main()
{
	int t,k[10001]; 
	scanf("%d",&t);
	while(t-->0)
	{
		int n; scanf("%d",&n);
		int count=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&k[i]);
			if(k[i]>1) count++;
		}

	}

	return 0;
}