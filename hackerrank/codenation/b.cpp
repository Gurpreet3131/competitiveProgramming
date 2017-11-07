/*#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
*/
#include<bits/stdc++.h>
using namespace std;
int main() 
{
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n,l;
	long long int mod = 1000000007;
	int m[103],f[103];
	scanf("%d%d",&n,&l);
	for(int i=0;i<n;i++) scanf("%d",&m[i]);
	for(int i=0;i<n;i++) scanf("%d",&f[i]);
	sort(m,m+n); sort(f,f+n);
	int ctm[103]={0},ctf[103]={0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(m[i]*f[j]<l) ctm[i]++;
		}
	}
	int flag=0;
	for(int i=0;i<n;i++) 
	{
		if(ctm[i]==0) 
		{
			flag=1; break;
		}
	}
	//for(int i=0;i<n;i++) cout<<ctm[i]<<endl;
	long long int ways=ctm[n-1], num =1;
	if(flag==1) printf("0\n");
	else
	{
		for(int i=n-2;i>=0;i--)
		{
			ways*= ctm[i]-num;
			num++;
			if(ways>=mod) ways%=mod;
		}
		printf("%lld\n",ways);
	}
	
return 0;
}