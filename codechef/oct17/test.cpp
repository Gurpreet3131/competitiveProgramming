#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d", &t);
	while(t--)
	{
		vector<unsigned int> a;
		int n; scanf("%d",&n);
		for(int i = 0; i < n; i++)
		{
			unsigned int val; cin >> val;
			a.push_back(val);
		}
		vector<unsigned int> prefSum(n), sufSum(n);
		prefSum[0] = a[0];
		for (int i = 1; i < n; i++) {
			prefSum[i] = prefSum[i - 1] + a[i];
		}
		sufSum[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			sufSum[i] = sufSum[i + 1] + a[i];
		}
		unsigned int mn = prefSum[0] + sufSum[0];
		int where = 1;
		for (int i = 1; i < n; i++) {
			unsigned int val = prefSum[i] + sufSum[i];
			if (val < mn) {
				mn = val;
				where = i + 1;
			}
		}
		for(int i = 0; i < n; i++) cout << prefSum[i] << " ";
			cout << endl;
		for(int i = 0; i < n; i++) cout << sufSum[i] << " ";
			cout << endl;

		printf("%d\n",where);
	}
	return 0;
}