#include <bits/stdc++.h>
using namespace std;
void computeLPSArray(char *pat, int M, int *lps);
int flag=0;
int lps[1000001]={0};
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int j  = 0;  // index for pat[]
    computeLPSArray(pat, M, lps);
    int i = 0;  // index for txt[]
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
        printf("YES at index %d\n", i-j);
        flag=1;
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
    int len = 0;  // length of the previous longest prefix suffix
    int i;
 
    lps[0] = 0; // lps[0] is always 0
    i = 1;
 
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
	int t; scanf("%d",&t);
    char big[1000001],small[1000001];	
    while(t--)
	{
		scanf("%s",big);
        scanf("%s",small);
		flag=0;
		for(int i=0;i<strlen(small);i++)
		{
			if(small[i]=='T') small[i]='A';
			else if(small[i]=='A') small[i]='T';
			else if(small[i]=='C') small[i]='G';
			else if(small[i]=='G') small[i]='C';
		}
		//cout<<big<<endl<<small<<endl;
		if(strlen(small)<= strlen(big)) KMPSearch(small,big);
		if(flag==0)
		{
			printf("NO\n");
		}
	}
	return 0;
}