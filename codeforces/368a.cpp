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
	int n,m; scanf("%d%d",&n,&m);
	char c;
	int flag=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>c;
			if(c=='C' || c=='Y' || c=='M') flag=1;			
		}
	if(flag==1) printf("#Color");
	else printf("#Black&White");
	return 0;
}