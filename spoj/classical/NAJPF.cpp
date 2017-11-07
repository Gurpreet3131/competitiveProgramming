#include <bits/stdc++.h>
using namespace std;
int st[1000001] = {0};
int ct = 0, ind = 0;
void computeLps(string pat, int m, int lps[])
{
	lps[0] = 0;
	int i = 1, len = 0;
	while(i < m)
	{
		if(pat[i] == pat[len])
		{
			lps[i] = len + 1;
			len++; i++;
		}
		else
		{
			if(len != 0) len = lps[len - 1];
			else 
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPsearch(string pat, string txt)
{
	int n = txt.length(), m = pat.length();

	int lps[m];

	computeLps(pat, m, lps);
	int i = 0, j = 0;
	while(i < n)
	{
		if(pat[j] == txt[i])
		{
			i++; j++;
		}

		if(j == m)
		{
			//cout << "String matched at index " << i - j << endl;
			ct++;
			st[ind++] = i - j;
			j = lps[j - 1];
		}
		else if(i < n && pat[j] != txt[i])
		{
			if(j != 0) j = lps[j - 1];
			else i++; 

		}
	}

}


int main()
{
	int t; cin >> t;
	while(t--)
	{
		string a, b;
		cin >> a >> b;
		ind = 0; ct = 0;
		KMPsearch(b, a);
		if(ct == 0) printf("Not Found\n");
		else
		{
			printf("%d\n", ct);
			for(int i = 0; i < ind; i++)
			{
				printf("%d ", st[i] + 1);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}