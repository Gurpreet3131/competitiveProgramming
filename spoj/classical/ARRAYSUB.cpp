#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int k; cin >> k;
	int queue[n]; 
	int front = 0, rear = 0, mx = 0;
	for(int i = 0; i < n; i++)
	{
		if(i < k)
		{
			if(front < rear)
			{
				int pre = rear - 1;
				while(front < rear && a[queue[pre]] < a[i])
				{
					rear--; pre--;
				}
				queue[rear++] = i;
			}
			else queue[rear++] = i;
		}
		else
		{
			printf("%d ", a[queue[front]]);
			while (queue[front] < i - k + 1) front++;
			if(front < rear)
			{
				int pre = rear - 1;
				while(front < rear && a[queue[pre]] < a[i])
				{
					rear--; pre--;
				}
				queue[rear++] = i;
			}
			else queue[rear++] = i;
		}
	}
	printf("%d\n", a[queue[front]]);
	return 0;
}