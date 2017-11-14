#include <bits/stdc++.h>
using namespace std;
long long int a[502][52][52];
int sel[52][52] = {0};
vector<pair<int, int> >aa, b;
long long int maxi, maxj, maxval = -1;
long long int max2i, max2j, maxval2 = -1;
int n, m;
long long int tempmax = -1, tempi, tempj;
void input()
{
	int init = n;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			for(int k = 1; k <=n; k++)
			{
				scanf("%lld", &a[i][j][k]);
				if(i == 1 && j == init)
				{
					if(a[i][j][k] > maxval)
					{
						maxval = a[i][j][k];
						maxi = j; maxj = k;
					}
				}
				if(i == 1 && j == 1)
				{
					if(a[i][j][k] > maxval2)
					{
						maxval2 = a[i][j][k];
						max2i = j; max2j = k;
					}
				}
			}
		}
	}
}

long long int calc(int t, int curi, int sj, int ej)
{
	long long int tempmax = -1;
	for(int j = sj; j <= ej; j++)
	{
		if(a[t][curi][j] >= tempmax)
		{
			tempmax = a[t][curi][j];
			tempi = curi; tempj = j;
		}		
	}
	return tempmax;
}

int main()
{
	cin >> n >> m;	
	input();
	long long int curi = maxi, curj = maxj, flag = 1,rem = m - 1;
	sel[curi][curj] = 1;
	int s1 = 0, s2 = 0;
	//cout << curi << " " << curj << endl;
	aa.push_back(make_pair(curi,curj));
	s1 += a[1][curi][curj];
	int change = -1, ff = 0;
	int t;
	for(t = 2; t <= m; t++)
	{
		tempmax = -1;
		/*if(rem <= n - curi)
		{
			curi++;
			if(curi > n) break;
			flag = 1; curj = 0;
		}*/
		/*
		if(rem <= (2 * (curi - 1)) && ff == 0)
		{
			curi--;
			if(curi < 1) break;
			flag = 1; curj = 0; ff = 1;
		}*/
		if(rem <= curi - 1 && ff == 0)
		{
			curi--;
			if(curi < 1) break;
			flag = 1; curj = 0;
		}
		if(flag == 1)
		{
			if(curj > 1)
			{
				tempmax = calc(t, curi, 1, curj - 1);
				if(tempmax > 0) flag = 2;
			}
			if(curj < n)
			{
				long long int temp = calc(t, curi, curj + 1, n);
				if(temp > tempmax) flag = 3, tempmax = temp;
				else tempmax = calc(t, curi, 1, curj - 1);
			}
		}
		else if(flag == 2)
		{
			if(curj > 1)
			{
				tempmax = calc(t, curi, 1, curj - 1);
				if(tempmax > 0) flag = 2;
			}
			else
			{
				curi += change;
				if(curi > n || curi < 1) break;
				tempmax = calc(t, curi, 1, n);
				if(tempmax > 0) flag = 1;
			}
			ff = 0;
		}
		else if(flag == 3)
		{
			if(curj < n)
			{
				tempmax = calc(t, curi, curj + 1, n);
				if(tempmax > 0) flag = 3;
			}
			else
			{
				curi +=change;
				if(curi > n || curi < 1) break;
				tempmax = calc(t, curi, 1, n);
				if(tempmax > 0) flag = 1;
			}
			ff = 0;
		}
		curi = tempi; curj = tempj; 
		sel[curi][curj] = 1;
		if(tempmax < 0) break;
		s1+= a[t][curi][curj];
		aa.push_back(make_pair(curi,curj));
		//cout << curi << " " << curj << endl;
		rem--;
		//cout << tempmax << endl;		
		//cout << tempi << " temp " << tempj << endl;
	}
	aa.push_back(make_pair(-1,-1));


	curi = max2i; curj = max2j; flag = 1;rem = m - 1;
	sel[curi][curj] = 1;
	//cout << curi << " " << curj << endl;
	b.push_back(make_pair(curi,curj));
	s2+= a[t][curi][curj];
	change = 1; ff = 0;
	
	for(t = 2; t <= m; t++)
	{
		tempmax = -1;
		/*if(rem <= n - curi)
		{
			curi++;
			if(curi > n) break;
			flag = 1; curj = 0;
		}*/
		/*
		if(rem <= (2 * (curi - 1)) && ff == 0)
		{
			curi--;
			if(curi < 1) break;
			flag = 1; curj = 0; ff = 1;
		}*/
		if(rem <= n - curi)
		{
			curi++;
			if(curi < 1 || curi > n) break;
			flag = 1; curj = 0;
		}
		if(flag == 1)
		{
			if(curj > 1)
			{
				tempmax = calc(t, curi, 1, curj - 1);
				if(tempmax > 0) flag = 2;
			}
			if(curj < n)
			{
				long long int temp = calc(t, curi, curj + 1, n);
				if(temp > tempmax) flag = 3, tempmax = temp;
				else tempmax = calc(t, curi, 1, curj - 1);
			}
		}
		else if(flag == 2)
		{
			if(curj > 1)
			{
				tempmax = calc(t, curi, 1, curj - 1);
				if(tempmax > 0) flag = 2;
			}
			else
			{
				curi += change;
				if(curi > n || curi < 1) break;
				tempmax = calc(t, curi, 1, n);
				if(tempmax > 0) flag = 1;
			}
			ff = 0;
		}
		else if(flag == 3)
		{
			if(curj < n)
			{
				tempmax = calc(t, curi, curj + 1, n);
				if(tempmax > 0) flag = 3;
			}
			else
			{
				curi +=change;
				if(curi > n || curi < 1) break;
				tempmax = calc(t, curi, 1, n);
				if(tempmax > 0) flag = 1;
			}
			ff = 0;
		}
		curi = tempi; curj = tempj; 
		sel[curi][curj] = 1;
		if(tempmax < 0) break;
		b.push_back(make_pair(curi,curj));
		s2+= a[t][curi][curj];
		//cout << curi << " " << curj << endl;
		rem--;
		//cout << tempmax << endl;		
		//cout << tempi << " temp " << tempj << endl;
	}
	b.push_back(make_pair(-1,-1));
	if(s1 >= s2)
	{		
		for(int i = 0; i < aa.size(); i++)
		{
			cout << aa[i].first << " " << aa[i].second << endl;
		}
	}
	else
	{
		for(int i = 0; i < b.size(); i++)
		{
			cout << b[i].first << " " << b[i].second << endl;
		}	
	}
}