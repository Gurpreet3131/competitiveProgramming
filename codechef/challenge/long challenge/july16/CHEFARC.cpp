#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#include <list>
int qx[10001],qy[10001],front=0,rear=0;
int main()
{
    int t; scanf("%d",&t);
    int mat[101][101],dist1[101][101],dist2[101][101];
    while(t>0)
    {
        int n,m,k1,k2,vert=0,start=1,end;
        scanf("%d%d%d%d",&n,&m,&k1,&k2);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&mat[i][j]);
                if(i==0 && j==0) dist1[i][j]=0;
                else if(mat[i][j]==0) dist1[i][j]=-2;
                else
                {
                    dist1[i][j]=-mat[i][j];
                }
                if(i==0 && j==m-1) dist2[i][j]=0;
                else if(mat[i][j]==0) dist2[i][j]=-2;
                else
                {
                    dist2[i][j]=-mat[i][j];
                }
            }
        }
        int ans=100000;
        int tempmin=100000;
        if(m==1) ans=0;
        else if(k1==0 && k2==0) ans=-1;
        else if(m==2) ans=1;
        else if(k1>=m-1 || k2>=m-1) ans=1;
        else
        {
            front=0; rear=0;
            qx[rear]=0; qy[rear++]=0;
            if(k1!=0)
            {
                while(front<rear)
                {
                    int i=qx[front];
                    int j=qy[front];
                    for(int x=max(i-k1,0);x<=min(i+k1,n-1);x++)
                    {
                        for(int y=max(j-k1,0);y<=min(j+k1,m-1);y++)
                        {
                            if(x==0 && y==0) continue;
                            if(mat[x][y]==1) continue;
                            int distance=fabs(x-i)+fabs(y-j);
                            if(distance>k1) continue;
                            if(dist1[x][y]==-2) 
                            {
                                dist1[x][y]=dist1[i][j]+1;
                                qx[rear]=x; qy[rear++]=y;
                            }   
                        }
                    }
                    //for(int i=0;i<rear;i++) cout<<"cord"<<qx[i]<<" "<<qy[i]<<endl;
                    front++;
                }
            }
            front=0; rear=0;
            qx[rear]=0; qy[rear++]=m-1;
            if(k2!=0)
            {
                while(front<rear)
                {
                    int i=qx[front];
                    int j=qy[front];
                    for(int x=max(i-k2,0);x<=min(i+k2,n-1);x++)
                    {
                        for(int y=min(j+k2,m-1);y>=max(j-k2,0);y--)
                        {
                            if(x==0 && y==m-1) continue;
                            if(mat[x][y]==1) continue;
                            int distance=fabs(x-i)+fabs(y-j);
                            if(distance>k2) continue;
                            if(dist2[x][y]==-2) 
                            {
                                dist2[x][y]=dist2[i][j]+1;
                                qx[rear]=x; qy[rear++]=y;
                            }
                        }
                    }
                    front++;
                }
            }/*
            cout<<"dist1\n";
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cout<<dist1[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<"dist2\n";
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cout<<dist2[i][j]<<" ";
                }
                cout<<endl;
            }*/
            if(dist1[0][m-1]!=-2 || dist2[0][0]!=-2)
            {
                if(k1==0)
                {
                    if(dist2[0][0]==-2)
                    {
                        ans=-1;
                    }
                    else
                    {
                        ans=dist2[0][0];
                    }
                }
                else if(k2==0)
                {
                    if(dist1[0][m-1]==-2) ans=-1;
                    else ans=dist1[0][m-1];
                }
                else
                {
                    for(int i=0;i<n;i++)
                    {
                        for(int j=0;j<m;j++)
                        {   
                            if(dist1[i][j]>=0 && dist2[i][j]>=0)
                            {
                                tempmin=max(dist1[i][j],dist2[i][j]);
                                if(tempmin<ans) ans=tempmin;
                            }  
                        }
                    } 
                }
                if(ans==100000) ans=-1;
            }
            else ans=-1;
        }
        printf("%d\n",ans);
        t--;
    }
    return 0;
}
