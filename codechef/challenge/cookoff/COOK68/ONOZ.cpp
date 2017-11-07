#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	long long int a[100001]={0};
	while(t>0)
	{
		int h,m;
		cin>>h>>m;
		long long int count=0;
		if(h<=10)
		{
			count=min(m,h);
			if(m>11 && h>1) count++;
			if(m>22 && h>2) count++;
			if(m>33 && h>3) count++;
			if(m>44 && h>4) count++;
			if(m>55 && h>5) count++;
			if(m>66 && h>6) count++;
			if(m>77 && h>7) count++;
			if(m>88 && h>8) count++;
			if(m>99 && h>9) count++;
		}
		else
		{
			if(m<=10) 
			{
				count=m;
				if(h>11 && m>1) count++;
				if(h>22 && m>2) count++;
				if(h>33 && m>3) count++;
				if(h>44 && m>4) count++;
				if(h>55 && m>5) count++;
				if(h>66 && m>6) count++;
				if(h>77 && m>7) count++;
				if(h>88 && m>8) count++;
				if(h>99 && m>9) count++;
			}
			else 
			{
				count=10;
			if(h>11 && m>11) count+=3;
			else if(m>11 && h<12) count+=1;
			else if(h>11 && m<12) count+=1;

			if(h>22 && m>22) count+=3;
			else if(m>22 && h<23) count+=1;
			else if(h>22 && m<23) count+=1;

			if(h>33 && m>33) count+=3;
			else if(m>33 && h<34) count+=1;
			else if(h>33 && m<34) count+=1;

			if(h>44 && m>44) count+=3;
			else if(m>44 && h<45) count+=1;
			else if(h>44 && m<45) count+=1;

			if(h>55 && m>55) count+=3;
			else if(m>55 && h<56) count+=1;
			else if(h>55 && m<56) count+=1;

			if(h>66 && m>66) count+=3;
			else if(m>66 && h<67) count+=1;
			else if(h>66 && m<67) count+=1;

			if(h>77 && m>77) count+=3;
			else if(m>77 && h<78) count+=1;
			else if(h>77 && m<78) count+=1;

			if(h>88 && m>88) count+=3;
			else if(m>88 && h<89) count+=1;
			else if(h>88 && m<89) count+=1;

			if(h>99 && m>99) count+=3;
			else if(m>99 && h<100) count+=1;
			else if(h>99 && m<100) count+=1;
			}
		}
		cout<<count<<endl;
		t--;
	}
}