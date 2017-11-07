	#include <bits/stdc++.h>
	using namespace std;
	int main()
	{
		int t; scanf("%d",&t);
		long long int a[100002];	
		while(t--)
		{
			int n;
			long long int d; scanf("%d%lld",&n,&d);
			long long int sum = 0;
			for(int i=0;i<n;i++)
			{
				scanf("%lld",&a[i]);
				sum += a[i];
			}
			int flag = 1, ct = 0;
			if(sum%n == 0)
			{
				long long int avg = sum/n;	
				for(int i=0; i<n;i++)
				{
					if(i+d < n)
					{
						int dif = fabs(a[i] - avg);
						if(a[i]>avg) a[i+d]+= dif;
						else a[i+d]-= dif;
						a[i] = avg; ct+=dif;
					}
					else if(a[i] != avg)
					{
						flag =0; break;
					}
				}
			}
			else flag = 0;
			if(flag == 1) printf("%d\n",ct);
			else printf("-1\n");
		}
		return 0;	
	}