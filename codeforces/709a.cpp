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
	int n,b,d,count=0,waste=0; scanf("%d%d%d",&n,&b,&d);
	for(int i=1;i<=n;i++)
	{
		int size; scanf("%d",&size);
		if(size>b) continue;
		else waste+=size;
		if(waste>d) waste=0,count++; 
	}
	printf("%d\n",count);
	return 0;
}