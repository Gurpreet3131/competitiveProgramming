#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int a[26]={0};
	for(int i=0;i<s.length();i++) a[s[i] - 'a']++;
	int ct=0;
	for(int i=0;i<26;i++) if(a[i]%2!=0) ct++;
	if(ct%2 ==0) cout<<"Shukla 2 wins\n";
	else cout<<"Shukla 1 wins\n";

	return 0;
}