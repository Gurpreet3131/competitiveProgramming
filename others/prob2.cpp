#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin >> n;
	int a[n];
	for(int i= 0; i <n; i++)
		cin >> a[i];
	int limit; cin >> limit; //21
	sort(a, a+n);
	int sum = 0, len= 0, ind = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		if(sum > limit) break;
		sum += a[i];
		ind = i;
	}
	if(sum <= limit)
	{
		cout <<"NO such subarray exist\n";
	}
	else
	{
		cout << "length of subarray = " << n - ind << endl;
		cout << "Elements of sub array = \n";
		for(int i = n - 1; i >= ind; i--)
			cout << a[i] << " ";

		cout << endl;
	}

	return 0;
}