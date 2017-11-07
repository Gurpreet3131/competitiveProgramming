//#include<iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
int count=0,me,other;
int marked[9]={0};
int computerturn();
int main()
{
	srand(time(NULL));
	count=0;
	for(int i=0;i<9;i++) 
	{
		scanf("%d",&marked[i]);
		if(marked[i]!=0) count++;
	}
	scanf("%d",&me);
	if(me==1) other=2;
	else other=1;
	int index=computerturn();
	int x,y;
	y=index/3;
	x=index%3;
	//cout<<x<<" "<<y<<endl;
	printf("%d %d\n",x,y);
	return 0;
}
int computerturn()
    {
        int index=0;
        int random=rand()%9;
        if(count==0 && marked[4]==0) index=4;
        else if(count==1 && marked[4]==0)   index=4;
        else if(count==1 && marked[4]==other) 
        {
            random=rand()%4;
            if(random==0 && marked[0]==0) index=0;
            else if(random==1 && marked[2]==0 ) index=2;
            else if(random==2 && marked[6]==0) index=6;
            else if(random==3 && marked[8]==0) index=8;
        }
       
         
        else if(marked[0]==me && marked[1]==me && marked[2]==0) index=2;
        else if(marked[0]==me && marked[2]==me && marked[1]==0 ) index=1;
        else if(marked[1]==me && marked[2]==me && marked[0]==0) index=0;
        else if(marked[3]==me && marked[4]==me && marked[5]==0) index=5;
        else if(marked[3]==me && marked[5]==me && marked[4]==0) index=4;
        else if(marked[4]==me && marked[5]==me && marked[3]==0) index=3;
        else if(marked[6]==me && marked[7]==me && marked[8]==0) index=8;
        else if(marked[6]==me && marked[8]==me && marked[7]==0) index=7;
        else if(marked[7]==me && marked[8]==me && marked[6]==0) index=6;
        
        else if(marked[0]==me && marked[3]==me && marked[6]==0) index=6;
        else if(marked[0]==me && marked[6]==me && marked[3]==0) index=3;
        else if(marked[3]==me && marked[6]==me && marked[0]==0) index=0;
        else if(marked[1]==me && marked[4]==me && marked[7]==0) index=7;
        else if(marked[1]==me && marked[7]==me && marked[4]==0) index=4;
        else if(marked[4]==me && marked[7]==me && marked[1]==0) index=1;
        else if(marked[2]==me && marked[5]==me && marked[8]==0) index=8;
        else if(marked[2]==me && marked[8]==me && marked[5]==0) index=5;
        else if(marked[5]==me && marked[8]==me && marked[2]==0) index=2;
        
        else if(marked[0]==me && marked[4]==me && marked[8]==0) index=8;
        else if(marked[0]==me && marked[8]==me && marked[4]==0) index=4;
        else if(marked[4]==me && marked[8]==me && marked[0]==0) index=0;
        else if(marked[2]==me && marked[4]==me && marked[6]==0) index=6;
        else if(marked[2]==me && marked[6]==me && marked[4]==0) index=4;
        else if(marked[4]==me && marked[6]==me && marked[2]==0) index=2;
        //other winning
        else if(marked[0]==other && marked[1]==other && marked[2]==0) index=2;
        else if(marked[0]==other && marked[2]==other && marked[1]==0 ) index=1;
        else if(marked[1]==other && marked[2]==other && marked[0]==0) index=0;
        else if(marked[3]==other && marked[4]==other && marked[5]==0) index=5;
        else if(marked[3]==other && marked[5]==other && marked[4]==0) index=4;
        else if(marked[4]==other && marked[5]==other && marked[3]==0) index=3;
        else if(marked[6]==other && marked[7]==other && marked[8]==0) index=8;
        else if(marked[6]==other && marked[8]==other && marked[7]==0) index=7;
        else if(marked[7]==other && marked[8]==other && marked[6]==0) index=6;
        
        else if(marked[0]==other && marked[3]==other && marked[6]==0) index=6;
        else if(marked[0]==other && marked[6]==other && marked[3]==0) index=3;
        else if(marked[3]==other && marked[6]==other && marked[0]==0) index=0;
        else if(marked[1]==other && marked[4]==other && marked[7]==0) index=7;
        else if(marked[1]==other && marked[7]==other && marked[4]==0) index=4;
        else if(marked[4]==other && marked[7]==other && marked[1]==0) index=1;
        else if(marked[2]==other && marked[5]==other && marked[8]==0) index=8;
        else if(marked[2]==other && marked[8]==other && marked[5]==0) index=5;
        else if(marked[5]==other && marked[8]==other && marked[2]==0) index=2;
        
        else if(marked[0]==other && marked[4]==other && marked[8]==0) index=8;
        else if(marked[0]==other && marked[8]==other && marked[4]==0) index=4;
        else if(marked[4]==other && marked[8]==other && marked[0]==0) index=0;
        else if(marked[2]==other && marked[4]==other && marked[6]==0) index=6;
        else if(marked[2]==other && marked[6]==other && marked[4]==0) index=4;
        else if(marked[4]==other && marked[6]==other && marked[2]==0) index=2;
        
        else if(count==3) 
        {
            while(marked[random]!=0)
            {
                random=rand()%4;
                if(random==0) random=1;
                else if(random==1) random=3;
                else if(random==2) random=5;
                else if(random==3) random=7;
                //System.out.println("random number generated"+random);
            }
             index=random;
        }
        else
        {
        	//cout<<"here\n";
        	//cout<<random<<endl;
            while(marked[random]!=0)
            {
                random=rand()%9;
                //cout<<random<<endl;
            }
            index=random;
        }
        //cout<<index<<endl;
        return index;
    }