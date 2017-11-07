#include <bits/stdc++.h>
using namespace std;
const int size = 2001;
int a[size], maxindex;

void binarySearch(int l, int r, int sum)
{
	if(l <= r)
	{
		int mid = (l + r) >> 1;
		if(sum >= a[mid]) 
		{
			maxindex = max(maxindex, mid);
			l = mid + 1;
		}
		else r = mid - 1;
		binarySearch(l, r, sum);
	}
}

int main()
{
	int n; scanf("%d", &n);
	while(n != 0)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a, a+n);
		int l = 0, r = n - 1, ct = 0;
		for(int i = 0; i < n - 2; i++)
		{
			for(int j = i + 1; j < n - 1; j++)
			{
				maxindex = j;
				l = min(j+1, n - 1); 
				r = n - 1;
				binarySearch(l, r, a[i] + a[j]);
				ct += n - 1 - maxindex;
			}
		}
		printf("%d\n",ct);
		scanf("%d", &n);
	}
	return 0;
}