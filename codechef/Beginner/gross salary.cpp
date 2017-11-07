#include<iostream>
using namespace std;
int main()
{
    int t,salary=0; cin>>t;
        while(t>0)
        {
 		cin>>salary;                 
	      	if(salary<1500) cout<<(salary+(0.1)*salary+(0.9)*salary)<<endl;
            	else cout<<(salary+500+(0.98)*salary)<<endl;
            t--;
        }
       return 0; 
    
}


