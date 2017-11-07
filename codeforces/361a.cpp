#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,ct=0;
	scanf("%d",&n);
    char s[10];
    scanf("%s",s);
    if(n==1) ct=0;
    else
    {
        ct=0;
        for(int i=0;i<10;i++)
        {
            int x,y;
            if(i==0) x=3,y=1;
            else if(i==1) x=0,y=0;
            else if(i==2) x=0,y=1;
            else if(i==3) x=0,y=2;
            else if(i==4) x=1,y=0;
            else if(i==5) x=1,y=1;
            else if(i==6) x=1,y=2;
            else if(i==7) x=2,y=0;
            else if(i==8) x=2,y=1;
            else if(i==9) x=2,y=2;
            //cout<<"i= "<<i<<endl;
            int flag2=1;
            for(int j=1;j<n;j++)
            {
                int tx,ty,ox,oy;
                if(s[j]=='0') tx=3,ty=1;
                else if(s[j]=='1') tx=0,ty=0;
                else if(s[j]=='2') tx=0,ty=1;
                else if(s[j]=='3') tx=0,ty=2;
                else if(s[j]=='4') tx=1,ty=0;
                else if(s[j]=='5') tx=1,ty=1;
                else if(s[j]=='6') tx=1,ty=2;
                else if(s[j]=='7') tx=2,ty=0;
                else if(s[j]=='8') tx=2,ty=1;
                else if(s[j]=='9') tx=2,ty=2;
                
                if(s[j-1]=='0') ox=3,oy=1;
                else if(s[j-1]=='1') ox=0,oy=0;
                else if(s[j-1]=='2') ox=0,oy=1;
                else if(s[j-1]=='3') ox=0,oy=2;
                else if(s[j-1]=='4') ox=1,oy=0;
                else if(s[j-1]=='5') ox=1,oy=1;
                else if(s[j-1]=='6') ox=1,oy=2;
                else if(s[j-1]=='7') ox=2,oy=0;
                else if(s[j-1]=='8') ox=2,oy=1;
                else if(s[j-1]=='9') ox=2,oy=2;
                int difx=tx-ox,dify=ty-oy;
                int newx=x+difx,newy=y+dify;
                //cout<<newx<<" "<<newy<<endl;
                if( ( (newx<3 && newx>=0) && (newy>=0 && newy<3) ) || (newx==3 && newy==1) )
                {
                    x=newx; y=newy;
                }
                else
                {
                    flag2=0;
                    break;
                }
            }
            if(flag2==1) ct++;
            //cout<<ct<<endl;
        }   
    }
    if(ct==1) printf("YES\n");
    else printf("NO\n"); 
    return 0;
}
