#include <bits/stdc++.h>
using namespace std;
int R,C;
char grid[1001][1001];
int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
bool search2D(int row, int col, string word)
{
    if (grid[row][col] != word[0])
      return false;
 
    int len = word.length();
    for (int dir = 0; dir < 8; dir++)
    {
        int k, rd = row + x[dir], cd = col + y[dir];
        for (k = 1; k < len; k++)
        {
            if (rd >= R || rd < 0 || cd >= C || cd < 0)
                break;
            if (grid[rd][cd] != word[k])
                break;
            rd += x[dir], cd += y[dir];
        }
        if (k == len)
            return true;
    }
    return false;
}
int patternSearch(string word)
{
    int flag=0;
    for (int row = 0; row < R; row++)
    {
        for (int col = 0; col < C; col++)
        {
            if (search2D(row, col, word))
            {
                flag=1; break;
            }  
        }
        if(flag==1) break;
    }
    return flag;
}   
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    R=m; C=n;
    string ss,word;
    cin>>ss; int ind=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            grid[i][j]=ss[ind++];
        }
    }
    cin>>word;
    int f= patternSearch(word);
    if(f==1) printf("True\n");
    else printf("False\n");
    return 0;
}