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
	int n,s,a[100001]={0},mindist=1000000000; 
	scanf("%d%d",&n,&s);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	if(n==1) mindist=0;
	else if(n==2)
	{
		mindist=min( abs(s-a[0]), abs(s-a[1]) );
	}
	else
	{
		int dist,left=a[0],right=a[n-1],nl=a[1],nr=a[n-2];
		if(s<=left)
		{		
			dist= abs(s-nr);
			mindist=min(mindist,dist);	
		}
		else if(s<=nl)
		{
			dist = min(abs(s-right), abs(s-nr)+nr-left );
			mindist=min(mindist,dist);
			dist = abs(s-left)+nr-left;
			mindist=min(mindist,dist);		
		}
		else if(s>=right)
		{		
			dist= abs(s-nl);
			mindist=min(mindist,dist);	
		}
		else if(s>=nr)
		{
			dist = min( abs(s-left) , abs(s-nl)+right-nl);
			mindist=min(mindist,dist);
			dist=abs(s-right)+right-nl;
			mindist=min(mindist,dist);		
		}
		else
		{
			dist = min( abs(s-left)+nr-left, abs(s-right)+right-nl);	
			mindist=min(mindist,dist);
			dist = min( abs(s-nl)+right-nl, abs(s-nr)+nr-left );		
			mindist=min(mindist,dist);
		}
	}
	printf("%d\n",mindist);
	return 0;
}