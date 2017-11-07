#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ipair; 
vector<ipair> mind;
int lps[301][301] = {0};
int n1, n2, m1, m2;
void computeLps(string pat, int m, int ind)
{
	lps[ind][0] = 0;
	int i = 1, len = 0;

	while(i < m)
	{
		if(pat[i] == pat[len])
		{
			lps[ind][i] = len + 1;
			len++; i++;
		}
		else
		{
			if(len != 0) len = lps[ind][len - 1];
			else 
			{
				lps[ind][i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(string pat, string txt, int row)
{
	int n = txt.length(), m = pat.length();

	int i = 0, j = 0;
	while(i < n)
	{
		if(pat[j] == txt[i])
		{
			i++; j++;
		}
		
		if(j == m)
		{
			mind.push_back(make_pair(row, i - j));
			j = lps[0][j - 1];
		}
		else if(i < n && pat[j] != txt[i])
		{
			if(j != 0) j = lps[0][j - 1];
			else i++;
		}
	}
}

int KMP2(string pat, string txt, int colval, int row)
{
	int n = txt.length(), m = pat.length();

	int i = colval, j = 0;
	while(i < n)
	{
		if(pat[j] == txt[i])
		{
			i++; j++;
		}
		
		if(j == m)
		{
			return 1;
			j = lps[row][j - 1];
		}
		else if(i < n && pat[j] != txt[i])
		{
			if(j != 0) j = lps[row][j - 1];
			else i++;
		}

		if(i >= colval + n2) break;
	}

	return 0;
}
int main()
{
	cin >> n1 >> n2;
	string pat[n1];
	for(int i = 0; i < n1; i++)
		cin >> pat[i];

	cin >> m1 >> m2;
	string s[m1];
	for(int i = 0; i < m1; i++)
		cin >> s[i];
	
	for(int i = 0; i < n1; i++)
		computeLps(pat[i], pat[i].length(), i);
	
	for(int i = 0; i <= m1 - n1; i++)
	{
		KMPSearch(pat[0], s[i], i);
	}
	for(int i = 0; i < mind.size(); i++)
	{
		//vec.erase(vec.begin() + ind);
		int ival = mind[i].first, jval = mind[i].second;
		for(int j = ival + 1; j < ival + n1; j++)
		{
			int res = KMP2(pat[j - ival], s[j], jval, j - ival);
			if(res == 0)
			{
				mind[i].first = -1; mind[i].second = -1;
				break;
			}
		}
	}
	int ct = 0;
	for(int i = 0; i < mind.size(); i++)
	{
		int ival = mind[i].first, jval = mind[i].second;
		if(ival < 0) continue;
		else
		{
			printf("(%d,%d)\n",ival + 1, jval + 1);
			ct++;			
		} 
	}
	if(ct == 0) printf("NO MATCH FOUND...\n");
	return 0;
}