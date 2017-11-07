#include <bits/stdc++.h>
using namespace std;
int n;
const int size = 2501;
int sum1[size * size], sum2[size * size];
int a[4][size];
int main()
{
	scanf("%d",&n);
	//unordered_map<int, int> m;
	for(int i = 0; i < n; i++) 
	{
		for(int j = 0; j < 4; j++)
		{
			scanf("%d",&a[j][i]);
		}
	}		
	int ind = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{	
			sum1[ind] = a[0][i] + a[1][j];
			sum2[ind++] = a[2][i] + a[3][j];
		}
	}
	sort(sum1, sum1 + ind);
	sort(sum2, sum2 + ind);
	int i = 0, j = ind - 1;
	long long int fi = 1, fj = 1, ct = 0;
	while(i < ind && j >= 0)
	{
		//cout << i << " " << j << endl;
		long long int sum = 0;
		sum = sum1[i] + sum2[j];
		while(i + 1 < ind && sum1[i] == sum1[i+1])
		{
			fi++; i++;
		}
		while(j - 1 >= 0 && sum2[j] == sum2[j - 1])
		{
			fj++; j--;
		}
		if(sum == 0) ct += fi * fj, i++, j--, fi = 1, fj = 1;
		else if(sum > 0) j--, fj = 1;
		else i++, fi = 1;
	}

	printf("%lld\n", ct);
	return 0;
}