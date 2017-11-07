#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
//#include <unordered_map>

using namespace std;
/*
 * Complete the function below.
 */
vector < int > wordz(vector < string > w) {
    vector < int > ans;
    for(int i=0;i<w.size();i++)
    {
        string s = w[i], s2;
        int li = -1,len = w[i].size(), turn = 1;
        while(1)
        {
        	s2="";
            int mini = s[li+1], maxi= s[li+1], ind=li+1;
            for(int j=li+1;j<s.size();j++)
            {
                if(turn == 1)
                {
                    if(s[j]<mini) ind = j; 
                	break;
                }
                else 
                {
                    if(s[j]>maxi) ind = j;
     				break;
                }
                
            }
            //if(turn == 1) 
            {
            	s2 = s.substr(0,ind)+s.substr(ind+1,s.size()); 
            	s = s2;
            }
            if(turn == 1) turn =2;
            else turn =1;
            //cout<<s<<endl;
            li = ind-1;
            int len = s.size();
            if(li==len-1) break;
        }
        int flag=0;
        for(int j=0;j<s.size();j++)
        {
        	if(s[j]> w[i][j])
        	{
        		flag=1; break;
        	}
        	else if(s[j]<w[i][j])
        	{
        		flag=2; break;
        	}
        }
         if(flag==0 || flag==1) ans.push_back(1);
        else if(flag==2 || s.size() == 0) ans.push_back(2);
    	//cout<<ans[i]<<endl;
    }
    return ans;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    vector < int > res;
    
    int _w_size = 0;
    cin >> _w_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _w;
    string _w_item;
    for(int _w_i=0; _w_i<_w_size; _w_i++) {
        getline(cin, _w_item);
        _w.push_back(_w_item);
    }
    
    res = wordz(_w);
    for(int res_i=0; res_i < res.size(); res_i++) {
    	fout << res[res_i] << endl;;
    }
    
    fout.close();
    return 0;
}
