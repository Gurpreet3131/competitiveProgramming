#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; scanf("%d",&n);
		unsigned int val = 1e5;
		unsigned int sum = val;
		long long int bigsum = val;
		for(int i = 0; i < n; i++)
		{
			//cout << sum << endl;
			if(sum == bigsum)
			{
				printf("%d ", val);
				sum += val; bigsum += val;
			}
			else printf("1 ");
		}
		printf("\n");
	}
	return 0;
}