#include <bits/stdc++.h>
using namespace std;


int longestPalSubstr(string str)
{
    int maxLength = 1;  // The result (length of LPS)

    int start = 0;
    int len = str.length();
 
    int low, high;
    for (int i = 1; i < len; ++i)
    {
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
 
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
    return maxLength;
}
void gen(int n)
{
    string s = "";
    for(int i = 0; i < n; i++) s+= 'a';

    int ind = n - 1;
    while(1)
    {
        int maxper = longestPalSubstr(s);
        if(maxper <= 4)cout << maxper << " " << s << endl;

        s[ind]++;
        int flag = 0;
        while(s[ind] > 'b' && ind >= 0)
        {
            s[ind] = 'a';
            if(ind - 1 >= 0) s[ind-1]++;
            ind--;
            if(ind < 0)
            {
                flag =1; break;
            }
        }
        if(flag == 1) break;
        ind = n - 1;
    }
}

void gen2(int n)
{
    string s = "aaaa";
    if(n < 9) return;
    int flag = 0;
    for(int i = 4; i < n; i++)
    {
        if(flag == 0) s += 'b', flag = 1;
        else if(flag == 1) s+='a', flag = 2;
        else if(flag == 2) s+='b', flag = 3;
        else if(flag == 3) s+='b', flag = 4;
        else if(flag == 4) s+='a', flag = 5;
        else if(flag == 5) s+='a', flag = 0;
    }
    int m = longestPalSubstr(s);
    cout << m << endl;
}

int main()
{
    int n; cin >> n;
    gen2(n);
    return 0;
}