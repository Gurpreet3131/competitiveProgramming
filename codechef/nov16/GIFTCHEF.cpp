#include <bits/stdc++.h>
using namespace std;
void computeLPSArray(char *pat, int M, int *lps);
int st[300003],end[300003], flen,slen,ind;
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    computeLPSArray(pat, M, lps);
    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
        	st[ind] = i-j;
        	end[ind++] = i-j+flen-1;
            j = lps[j-1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}
void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            if (len != 0)
            {
                len = lps[len-1];
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int main()
{
	int t;
	scanf("%d",&t);
	char *s,*f;
	s = new char[300003];
	f = new char[300003];
	while(t--)
	{
		cin>>s>>f;
		ind = 0;
		slen = strlen(s);
		flen = strlen(f);
		KMPSearch(f,s);
		long long int ways=ind;
		for(int i=2;i<ind;i++)
		{
			// i is for members in the tuple
		}

	}	
	return 0;
}