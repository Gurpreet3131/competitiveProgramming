#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int starti,startj,endi,endj,shooti,shootj;
int wrong=0,done=0,mei,mej,yoi,yoj,dif=0;
int a[10][10],pi[3][4],pj[3][4],me=0,you=0,clrstatus=0;
int index1=0,index2=0,countyou[4]={0},countme[4]={0},order[4]={0};
void shootupleft()
{
	shooti=yoi-1; shootj=yoj-1; done=1;
}
void shootup()
{
	shooti=yoi-1; shootj=yoj; done=1;
}
void shootupright()
{
	shooti=yoi-1; shootj=yoj+1; done=1;
}
void shootleft()
{
	shooti=yoi; shootj=yoj-1; done=1;
}
void shootright()
{
	shooti=yoi; shootj=yoj+1; done=1;
}
void shootdownleft()
{
	shooti=yoi+1; shootj=yoj-1; done=1;
}
void shootdown()
{
	shooti=yoi+1; shootj=yoj; done=1;
}
void shootdownright()
{
	shooti=yoi+1; shootj=yoj+1; done=1;
}
void shootstart()
{
	shooti=starti; shootj=startj; done=1;
}
void moveupleft()
{
	endi=mei-1; endj=mej-1;
}
void moveup()
{
	endi=mei-1; endj=mej;
}
void moveupright()
{
	endi=mei-1; endj=mej+1;
}
void moveleft()
{
	endi=mei; endj=mej-1;
}
void moveright()
{
	endi=mei; endj=mej+1;
}
void movedownleft()
{
	endi=mei+1; endj=mej-1;
}
void movedown()
{
	endi=mei+1; endj=mej;
}
void movedownright()
{
	endi=mei+1; endj=mej+1;
}
void checkhorizontalclearpath(int start,int end,int row)
{
	wrong=0;	
	for(int k=min(start,end);k<=max(start,end);k++) // check for a clear path
    {
    	if(a[row][k]!=0)
        {
        	wrong=1; break;            
        }
    }
}
void checkverticalclearpath(int start,int end,int col)
{
	wrong=0;	
	for(int k=min(start,end);k<=max(start,end);k++) // check for a clear path
    {
    	if(a[k][col]!=0)
        {
        	wrong=1; break;            
        }
    }
}
void diagonalclear(int sti,int stj,int eni,int enj,int dir)
{
	wrong=0;
	int value=0;	
	if(dir==1)
	{				
		for(int i=sti-1;i>eni;i--)
		{
			value++;			
			if(a[i][stj+value]!=0)
			{
				wrong=1;
				break;
			}
		}
	}
	else if(dir==2)
	{
		for(int i=sti-1;i>eni;i--)
		{
			value++;			
			if(a[i][stj-value]!=0)
			{
				wrong=1;
				break;
			}
		}
	}
	else if(dir==3)
	{
		for(int i=sti+1;i<eni;i++)
		{
			value++;			
			if(a[i][stj-value]!=0)
			{
				wrong=1;
				break;
			}
		}
	}
	else if(dir==4)
	{
		for(int i=sti+1;i<eni;i++)
		{
			value++;			
			if(a[i][stj+value]!=0)
			{
				wrong=1;
				break;
			}
		}
	}
}
void randommove()
{
	if(mej<5) //if me behind middle
	{
		if(mei<5)//above middle
		{
			//2nd quadrant
			if(a[mei+1][mej+1]==0) {	movedownright(); shootstart();	}
			else if(a[mei][mej+1]==0) {	moveright(); shootstart();	}
			else if(a[mei+1][mej]==0) {	movedown(); shootstart();	}
			else if(a[mei-1][mej+1]==0 && mei!=0) {	moveupright(); shootstart();	}
			else if(a[mei+1][mej-1]==0 && mej!=0) {	movedownleft(); shootstart();	}
			else if(a[mei-1][mej]==0 && mei!=0) {	moveup(); shootstart();	}
			else if(a[mei][mej-1]==0 && mej!=0) {	moveleft(); shootstart();	}
			else if(a[mei-1][mej-1]==0 && mei!=0 && mej!=0) {	moveupleft(); shootstart();	}		
		}
		else //below middle
		{
			//3rd quadrant
			if(a[mei-1][mej+1]==0) {	moveupright(); shootstart();	}
			else if(a[mei-1][mej]==0) {	moveup(); shootstart();	}
			else if(a[mei][mej+1]==0) {	moveright(); shootstart();	}
			else if(a[mei-1][mej-1]==0 && mej!=0) {	moveupleft(); shootstart();	}
			else if(a[mei+1][mej+1]==0 && mei!=9) {	movedownright(); shootstart();	}
			else if(a[mei][mej-1]==0 && mej!=0) {	moveleft(); shootstart();	}	
			else if(a[mei+1][mej]==0 && mei!=9) {	movedown(); shootstart();	}
			else if(a[mei+1][mej-1]==0 && mej!=0 && mei!=9) {	movedownleft(); shootstart();	}
		}
 	}
	else	// me ahead middle
	{
		if(mei<5)//above middle
		{
			//1st quadrant
			if(a[mei+1][mej-1]==0) {	movedownleft(); shootstart();	}
			else if(a[mei][mej-1]==0) {	moveleft(); shootstart();	}
			else if(a[mei+1][mej]==0) {	movedown(); shootstart();	}
			else if(a[mei-1][mej-1]==0 && mei!=0) {	moveupleft(); shootstart();	}
			else if(a[mei+1][mej+1]==0 && mej!=9) {	movedownright(); shootstart();	}
			else if(a[mei-1][mej]==0 && mei!=0) {	moveup(); shootstart();	}
			else if(a[mei][mej+1]==0 && mej!=9) {	moveright(); shootstart();	}
			else if(a[mei-1][mej+1]==0 && mei!=0 && mej!=9) {	moveupright(); shootstart();	}
		}
		else //below middle
		{
			//4th quadrant
			if(a[mei-1][mej-1]==0) {	moveupleft(); shootstart();	}
			else if(a[mei-1][mej]==0) {	moveup(); shootstart();	}
			else if(a[mei][mej-1]==0) {	moveleft(); shootstart();	}
			else if(a[mei-1][mej+1]==0 && mej!=9) {	moveupright(); shootstart();	}
			else if(a[mei+1][mej-1]==0 && mei!=9) {	movedownleft(); shootstart();	}
			else if(a[mei][mej+1]==0 && mej!=9) {	moveright(); shootstart();	}
			else if(a[mei+1][mej]==0 && mei!=9) {	movedown(); shootstart();	}
			else if(a[mei+1][mej+1]==0 && mej!=9 && mei!=9) {	movedownright(); shootstart();	}
		}
	}
}
int countarrowyou()
{
	int count=0;
	if(a[yoi-1][yoj-1]!=0 || yoi==0 || yoj==0) count++;
	if(a[yoi-1][yoj]!=0 || yoi==0) count++;
	if(a[yoi-1][yoj+1]!=0 || yoi==0 || yoj==9) count++;
	if(a[yoi][yoj-1]!=0 || yoj==0) count++;
	if(a[yoi][yoj+1]!=0 || yoj==9) count++;
	if(a[yoi+1][yoj-1]!=0 || yoi==9 || yoj==0) count++;
	if(a[yoi+1][yoj]!=0 || yoi==9) count++;
	if(a[yoi+1][yoj+1]!=0 || yoi==9 || yoj==9) count++;
	return count;     
}
int reachpos(int ri,int rj)
{
	int yesreach=0;	
	endi=ri; endj=rj;
	//diagonal
	if(starti!=endi && startj!=endj && fabs(starti-endi)==fabs(startj-endj))
	{
		int direction=0;			
		if(starti<endi && startj<endj) direction=4;
		else if(starti<endi && startj>endj) direction=3;
		else if(starti>endi && startj<endj) direction=1;
		else if(starti>endi && startj>endj) direction=2;
		diagonalclear(starti,startj,endi,endj,direction);
		if(wrong==0)
		{
			yesreach=1;
		}
	}
	if(yesreach==1) return yesreach;
	
	//horizontal
	if(starti==endi)
	{
		if((startj!=endj)) 
		{
			if(a[endi][endj]==0)
			{
				dif=fabs(startj-endj);
				if(dif==1)
				{
					yesreach=1;
				}
				else
				{
					if(startj<endj) checkhorizontalclearpath(startj+1,endj-1,endi);
					else checkhorizontalclearpath(endj+1,startj-1,endi);
					if(wrong==0)
					{	
						yesreach=1;
					}
				}	
			}
		}
	}
	if(yesreach==1) return yesreach;
	//vertical	
	if(startj==endj)
	{
		if(starti!=endi) 
		{
			if(a[endi][endj]==0)
			{
				dif=fabs(starti-endi);
				if(dif==1)
				{
					yesreach=1;
				}
				else
				{
					if(starti<endi) checkverticalclearpath(starti+1,endi-1,endj);
					else checkverticalclearpath(endi+1,starti-1,endj);
					if(wrong==0)
					{
						yesreach=1;
					}
				}		
			}
		}
	}
	return yesreach;
}
int shootfrom(int ti,int tj)
{
	int yes=0;	
	//diagonal
	for(int i=3;i>=0;i--)
	{
		mei=pi[me][i]; mej=pj[me][i];
		starti=mei; startj=mej;
		int direction=1,value=0;
		if(direction==1)
		{
			int j=tj+1;			
			for(int i=ti-1;i>=0 && j<10;i--,j++)
			{								
				if(a[i][j]==0)
				{
					diagonalclear(ti,tj,i,j,direction);
					if(wrong==0)
					{
						yes=reachpos(i,j);
					}
					else break;
				}
				if(yes==1) break;
			}
			if(done==0) direction++;
		}
		if(direction==2)
		{
			int j=tj-1;			
			for(int i=ti-1;i>=0 && j>=0;i--,j--)
			{								
				if(a[i][j]==0)
				{
					diagonalclear(ti,tj,i,j,direction);
					if(wrong==0)
					{
						yes=reachpos(i,j);
					}
					else break;
				}
				if(yes==1) break;
			}
			if(done==0) direction++;
		}
		if(direction==3)
		{
			int j=tj-1;			
			for(int i=ti+1;i<10 && j>=0;i++,j--)
			{								
				if(a[i][j]==0)
				{
					diagonalclear(ti,tj,i,j,direction);
					if(wrong==0)
					{
						yes=reachpos(i,j);
					}
					else break;
				}
				if(yes==1) break;
			}
			if(done==0) direction++;
		}
		if(direction==4)
		{
			int j=tj+1;			
			for(int i=ti+1;i<10 && j<10;i++,j++)
			{								
				if(a[i][j]==0)
				{
					diagonalclear(ti,tj,i,j,direction);
					if(wrong==0)
					{
						yes=reachpos(i,j);
					}
					else break;
				}
				if(yes==1) break;
			}
			if(done==0) direction++;
		}
		if(yes==1) break;
	}
	if(yes==1) return yes;
	//horizontal
	for(int i=3;i>=0;i--)
	{
		mei=pi[me][i]; mej=pj[me][i];
		starti=mei; startj=mej;
		for(int j=0;j<10;j++)
		{
			if(j==tj) continue;			
			if(a[ti][j]==0)
			{
				dif=fabs(j-tj);
				if(dif==1)
				{
					yes=reachpos(ti,j);
				}
				else
				{
					if(j<tj) checkhorizontalclearpath(j+1,tj-1,ti);
					else checkhorizontalclearpath(tj+1,j-1,ti);
					if(wrong==0)
					{
						yes=reachpos(ti,j);
					}
				}	
			}
			if(yes==1) break;
		}
		if(yes==1) break;
	}
	if(yes==1) return yes;
	//vertical
	for(int i=3;i>=0;i--)
	{
		mei=pi[me][i]; mej=pj[me][i];
		starti=mei; startj=mej;
		for(int ii=0;ii<10;ii++)
		{
			if(ii==ti) continue;			
			if(a[ii][tj]==0)
			{
				dif=fabs(ii-ti);
				if(dif==1)
				{
					yes=reachpos(ii,tj);
				}
				else
				{
					if(ii<ti) checkverticalclearpath(ii+1,ti-1,tj);
					else checkverticalclearpath(ti+1,ii-1,tj);
					if(wrong==0)
					{
						yes=reachpos(ii,tj);
					}
				}	
			}
			if(yes==1) break;
		}
		if(yes==1) break;
	}
	return yes;
}
void shootpossible()
{
	int per=0;	
	if(yoj<5) //if you behind middle
	{
		if(yoi<5)//above middle
		{
			//2nd quadrant
			if(a[yoi+1][yoj+1]==0) {	per=shootfrom(yoi+1,yoj+1); if(per==1) shootdownright(); 	}
			if(a[yoi+1][yoj]==0 && done==0) {	per=shootfrom(yoi+1,yoj); if(per==1) shootdown();	}
			if(a[yoi][yoj+1]==0 && done==0) {	per=shootfrom(yoi,yoj+1); if(per==1) shootright();	}
			if(a[yoi+1][yoj-1]==0 && yoj!=0 && done==0) {	per=shootfrom(yoi+1,yoj-1); if(per==1) shootdownleft();	}
			if(a[yoi-1][yoj+1]==0 && yoi!=0 && done==0) {	per=shootfrom(yoi-1,yoj+1); if(per==1) shootupright();	}
			if(a[yoi][yoj-1]==0 && yoj!=0 && done==0) {	per=shootfrom(yoi,yoj-1); if(per==1) shootleft();}
			if(a[yoi-1][yoj]==0 && yoi!=0 && done==0) {	per=shootfrom(yoi-1,yoj); if(per==1) shootup();	}
			if(a[yoi-1][yoj-1]==0 && yoi!=0 && yoj!=0 && done==0) {	per=shootfrom(yoi-1,yoj-1); if(per==1) shootupleft();	}		
		}
		else //below middle
		{
			//3rd quadrant
			if(a[yoi-1][yoj+1]==0) {	per=shootfrom(yoi-1,yoj+1); if(per==1) shootupright();	}
			if(a[yoi-1][yoj]==0 && done==0) {	per=shootfrom(yoi-1,yoj); if(per==1) shootup();	}
			if(a[yoi][yoj+1]==0 && done==0) {	per=shootfrom(yoi,yoj+1); if(per==1) shootright();}
			if(a[yoi-1][yoj-1]==0 && yoj!=0 && done==0) {	per=shootfrom(yoi-1,yoj-1); if(per==1) shootupleft();	}
			if(a[yoi+1][yoj+1]==0 && yoi!=9 && done==0) {	per=shootfrom(yoi+1,yoj+1); if(per==1) shootdownright(); 	}
			if(a[yoi][yoj-1]==0 && yoj!=0 && done==0) {	per=shootfrom(yoi,yoj-1); if(per==1) shootleft();	}	
			if(a[yoi+1][yoj]==0 && yoi!=9 && done==0) {	per=shootfrom(yoi+1,yoj); if(per==1) shootdown();	}
			if(a[yoi+1][yoj-1]==0 && yoj!=0 && yoi!=9 && done==0) {	per=shootfrom(yoi+1,yoj-1); if(per==1) shootdownleft();	}
		}
 	}
	else	// you ahead middle
	{
		if(yoi<5)//above middle
		{
			//1st quadrant
			if(a[yoi+1][yoj-1]==0) {	per=shootfrom(yoi+1,yoj-1); if(per==1) shootdownleft();	}
			if(a[yoi+1][yoj]==0 && done==0) {	per=shootfrom(yoi+1,yoj); if(per==1) shootdown();	}
			if(a[yoi][yoj-1]==0 && done==0) {	per=shootfrom(yoi,yoj-1); if(per==1) shootleft();	}
			if(a[yoi+1][yoj+1]==0 && yoj!=9 && done==0) {	per=shootfrom(yoi+1,yoj+1); if(per==1) shootdownright(); 	}
			if(a[yoi-1][yoj-1]==0 && yoi!=0 && done==0) {	per=shootfrom(yoi-1,yoj-1); if(per==1) shootupleft();	}
			if(a[yoi][yoj+1]==0 && yoj!=9 && done==0) {	per=shootfrom(yoi,yoj+1); if(per==1) shootright();	}
			if(a[yoi-1][yoj]==0 && yoi!=0 && done==0) {	per=shootfrom(yoi-1,yoj); if(per==1) shootup();	}
			if(a[yoi-1][yoj+1]==0 && yoi!=0 && yoj!=9 && done==0) {	per=shootfrom(yoi-1,yoj+1); if(per==1) shootupright();	}
		}
		else //below middle
		{
			//4th quadrant
			if(a[yoi-1][yoj-1]==0) {	per=shootfrom(yoi-1,yoj-1); if(per==1) shootupleft();	}
			if(a[yoi-1][yoj]==0 && done==0) {	per=shootfrom(yoi-1,yoj); if(per==1) shootup();	}
			if(a[yoi][yoj-1]==0 && done==0) {	per=shootfrom(yoi,yoj-1); if(per==1) shootleft();	}
			if(a[yoi-1][yoj+1]==0 && yoj!=9 && done==0) {	per=shootfrom(yoi-1,yoj+1); if(per==1) shootupright();	}
			if(a[yoi+1][yoj-1]==0 && yoi!=9 && done==0) {	per=shootfrom(yoi+1,yoj-1); if(per==1) shootdownleft();	}
			if(a[yoi][yoj+1]==0 && yoj!=9 && done==0) {	per=shootfrom(yoi,yoj+1); if(per==1) shootright();	}
			if(a[yoi+1][yoj]==0 && yoi!=9 && done==0) {	per=shootfrom(yoi+1,yoj); if(per==1) shootdown();	}
			if(a[yoi+1][yoj+1]==0 && yoj!=9 && yoi!=9 && done==0) {	per=shootfrom(yoi+1,yoj+1); if(per==1) shootdownright(); 	}
		}
	}
}
void horizontal() //horizontal for all
{
	//start is already set
	if(yoj<5) //behind middle
	{		
		if(yoi<5) //above middle
		{
			//2nd quadrant
			if(mej<yoj) //if me behind you
			{
				if(dif==1) //if dif is 1
				{
					if(a[mei+1][yoj]==0)//go one down you
					{
						endi=mei+1; endj=yoj;
						if(a[yoi+1][yoj+1]==0)  shootdownright();	//shoot down right of you				
						else if(a[yoi][yoj+1]==0)	 shootright();  //shoot right of you				
						else if(a[yoi+1][yoj-1]==0)	 shootdownleft();	// shoot down left of you		
						else shootstart(); // shoot left of you
					}
					//else continue
				}
				else //if dif is more than one 	
				{
					checkhorizontalclearpath(mej+1,yoj+1,mei+1); //check down row clear
					if(wrong==0) //if clear
					{				
						endi=mei+1; endj=mej+1; 
						shootdownright();	 //shoot right down of you	
					}
					else //if not clear
					{
						checkhorizontalclearpath(mej+1,yoj-1,mei); //check current row clear
						if(wrong==0) //clear
						{
							endi=yoi; endj=yoj-1; 
							if(a[yoi+1][yoj-1]==0) shootdownleft(); //shoot down left of you
							else 
							{
								if(yoi!=0)
								{
									if(a[yoi-1][yoj]==0) shootup(); //shoot up of you
									else if(a[yoi-1][yoj-1]==0) shootupleft(); //shoot up left of you
									else shootstart(); 
								}								
								else shootstart();
							}
						}
						//else contninue; 
					}
				}
			}
			else //if me ahead you
			{
				if(dif==1) //if dif is 1
				{
					if(a[yoi+1][yoj]==0)//go one down you
					{
						endi=yoi+1; endj=yoj;
						if(a[yoi+1][yoj+1]==0)	shootdownright();  //shoot downright of you			
						else shootstart(); //shoot right of you
					}
					else if(a[yoi+1][yoj+1]==0)// go one right down of you
					{
						endi=yoi+1; endj=yoj+1; 
						shootstart(); //shoot right of you
					}
					//else continue
				}
				else if(dif==2)
				{
					if(a[yoi][yoj+1]==0) //move right of you
					{
						endi=yoi; endj=yoj+1;
						if(a[yoi+1][yoj+1]==0) shootdownright(); //shoot downright of you
						else if(a[yoi-1][yoj+1]==0 && yoi!=0) shootupright(); //shoot upright of you
						else if(a[yoi-1][yoj]==0 && yoi!=0) shootup(); //shoot up of you
						else if(a[yoi+1][yoj]==0) shootdown(); //shoot down of you 
						else shootstart();					
					}
					else if(a[yoi+1][yoj+1]==0) //move to down right of you
					{
						endi=yoi+1; endj=yoj+1;
						if(a[yoi+1][yoj]==0) shootdown(); //shoot down of you
						else shootstart();
					}
					else if(a[yoi-1][yoj+1]==0 && a[yoi+1][yoj]!=0 && yoi!=0)// move to up right of you
					{	
						endi=yoi-1; endj=yoj+1;						
						if(a[yoi-1][yoj]==0) shootup(); //shoot up of you
						else shootstart();
					}
					//else contninue
				}
				else //if dif is more than one 	
				{
					checkhorizontalclearpath(mej-1,yoj+1,mei+1); //check down row clear
					if(wrong==0) //if clear
					{
						endi=yoi+1; endj=mej-1; 
						shootdownright(); //shoot down right of you
					}
					else //if not clear 
					{
						checkhorizontalclearpath(mej-1,yoj+1,mei); //check current row clear
						if(wrong==0) //if clear
						{
							endi=yoi; endj=yoj+1; 
							if(a[yoi+1][yoj+1]==0) shootdownright(); //shoot down right of you
							else if(a[yoi-1][yoj+1]==0 && yoi!=0) shootupright(); //shoot up right of you
							else if(a[yoi-1][yoj]==0 && yoi!=0) shootup(); //shoot up of you
							else if(a[yoi+1][yoj]==0) shootdown(); //shoot down of you
							else shootstart(); 						
						}
						//else continue
					}
				}
			}			
		}
		else //below middle
		{
			//3rd quadrant
			if(mej<yoj) //if me behind you
			{
				if(dif==1) //if dif is 1
				{
					if(a[mei-1][yoj]==0)//go one up you
					{
						endi=mei-1; endj=yoj;
						if(a[yoi-1][yoj+1]==0)  shootupright();	//shoot up right of you				
						else if(a[yoi][yoj+1]==0)	 shootright();  //shoot right of you				
						else if(a[yoi-1][yoj-1]==0)	 shootupleft();	// shoot up left of you		
						else shootstart(); // shoot left of you
					}
					//else continue
				}
				else //if dif is more than one 	
				{
					checkhorizontalclearpath(mej+1,yoj+1,mei-1); //check up row clear
					if(wrong==0) //if clear
					{				
						endi=mei-1; endj=mej+1; 
						shootupright();	 //shoot upright of you	
					}
					else //if not clear
					{
						checkhorizontalclearpath(mej+1,yoj-1,mei); //check current row clear
						if(wrong==0) //clear
						{
							endi=yoi; endj=yoj-1; 
							if(a[yoi-1][yoj-1]==0) shootupleft(); //shoot up left of you
							else 
							{
								if(a[yoi+1][yoj]==0 && yoi!=9 ) shootdown(); //shoot down of you
								else if(a[yoi+1][yoj-1]==0 && yoi!=9) shootdownleft(); //shoot down left of you
								else shootstart(); 
							}
						}
						//else contninue; 
					}
				}
			}
			else //if me ahead you
			{
				if(dif==1) //if dif is 1
				{
					if(a[yoi-1][yoj]==0)//go one up you
					{
						endi=yoi-1; endj=yoj;
						if(a[yoi-1][yoj+1]==0)	shootupright();  //shoot upright of you			
						else shootstart(); //shoot right of you
					}
					else if(a[yoi-1][yoj+1]==0)// go one right up of you
					{
						endi=yoi-1; endj=yoj+1; 
						shootstart(); //shoot right of you
					}
					//else continue
				}
				else if(dif==2)
				{
					if(a[yoi][yoj+1]==0) //move right of you
					{
						endi=yoi; endj=yoj+1;
						if(a[yoi-1][yoj+1]==0) shootupright(); //shoot upright of you
						else if(a[yoi+1][yoj+1]==0 && yoi!=9) shootdownright(); //shoot downright of you
						else if(a[yoi+1][yoj]==0 && yoi!=0) shootdown(); //shoot down of you
						else if(a[yoi-1][yoj]==0) shootup(); //shoot up of you 
						else shootstart();					
					}
					else if(a[yoi-1][yoj+1]==0) //move to up right of you
					{
						endi=yoi-1; endj=yoj+1;
						if(a[yoi-1][yoj]==0) shootup(); //shoot up of you
						else shootstart();
					}
					else if(a[yoi+1][yoj+1]==0 && a[yoi-1][yoj]!=0 && yoi!=9)// move to down right of you
					{	
						endi=yoi+1; endj=yoj+1;
						if(a[yoi+1][yoj]==0) shootdown(); //shoot down of you
						else shootstart();
					}
					//else contninue
				}
				else //if dif is more than one 	
				{
					checkhorizontalclearpath(mej-1,yoj+1,mei-1); //check up row clear
					if(wrong==0) //if clear
					{
						endi=yoi-1; endj=mej-1; 
						shootupright(); //shoot up right of you
					}
					else //if not clear 
					{
						checkhorizontalclearpath(mej-1,yoj+1,mei); //check current row clear
						if(wrong==0) //if clear
						{
							endi=yoi; endj=yoj+1; 
							if(a[yoi-1][yoj+1]==0) shootupright(); //shoot up right of you
							else if(a[yoi+1][yoj+1]==0 && yoi!=9) shootdownright(); //shoot down right of you
							else if(a[yoi+1][yoj]==0 && yoi!=9) shootdown(); //shoot down of you
							else if(a[yoi-1][yoj]==0) shootup(); //shoot up of you
							else shootstart(); 						
						}
						//else continue
					}
				}
			}
		}
	}
	else //ahead middle
	{
		if(yoi<5) //above middle
		{
			//1st quadrant
			if(mej<yoj) //if me behind you
			{
				if(dif==1) //if dif is 1
				{
					if(a[yoi+1][yoj]==0)//go one down you
					{
						endi=yoi+1; endj=yoj;
						if(a[yoi+1][yoj-1]==0)	shootdownleft();  //shoot downleft of you			
						else shootstart(); //shoot left of you
					}
					else if(a[yoi+1][yoj-1]==0)// go one left down of you
					{
						endi=yoi+1; endj=yoj-1; 
						shootstart(); //shoot left of you
					}
					//else continue
				}
				else if(dif==2)
				{
					if(a[yoi][yoj-1]==0) //move left of you
					{
						endi=yoi; endj=yoj-1;
						if(a[yoi+1][yoj-1]==0) shootdownleft(); //shoot downleft of you
						else if(a[yoi-1][yoj-1]==0 && yoi!=0) shootupleft(); //shoot upleft of you
						else if(a[yoi-1][yoj]==0 && yoi!=0) shootup(); //shoot up of you
						else if(a[yoi+1][yoj]==0) shootdown(); //shoot down of you 
						else shootstart();					
					}
					else if(a[yoi+1][yoj-1]==0) //move to down left of you
					{
						endi=yoi+1; endj=yoj-1;
						if(a[yoi+1][yoj]==0) shootdown(); //shoot down of you
						else shootstart();
					}
					else if(a[yoi-1][yoj-1]==0 && a[yoi+1][yoj]!=0 && yoi!=0)// move to up left of you
					{	
						endi=yoi-1; endj=yoj-1;						
						if(a[yoi-1][yoj]==0) shootup(); //shoot up of you
						else shootstart();
					}
					//else contninue
				}
				else //if dif is more than one 	
				{
					checkhorizontalclearpath(mej+1,yoj-1,mei+1); //check down row clear
					if(wrong==0) //if clear
					{
						endi=yoi+1; endj=mej+1; 
						shootdownleft(); //shoot down left of you
					}
					else //if not clear 
					{
						checkhorizontalclearpath(mej+1,yoj-1,mei); //check current row clear
						if(wrong==0) //if clear
						{
							endi=yoi; endj=yoj-1; 
							if(a[yoi+1][yoj-1]==0) shootdownleft(); //shoot down left of you
							else if(a[yoi-1][yoj-1]==0 && yoi!=0) shootupleft(); //shoot up left of you
							else if(a[yoi-1][yoj]==0 && yoi!=0) shootup(); //shoot up of you
							else if(a[yoi+1][yoj]==0) shootdown(); //shoot down of you
							else shootstart(); 						
						}
						//else continue
					}
				}
			}
			else //if me ahead you
			{
				if(dif==1) //if dif is 1
				{
					if(a[mei+1][yoj]==0)//go one down you
					{
						endi=mei+1; endj=yoj;
						if(a[yoi+1][yoj-1]==0)  shootdownleft();	//shoot down left of you				
						else if(a[yoi][yoj-1]==0)	 shootleft();  //shoot left of you				
						else if(a[yoi+1][yoj+1]==0)	 shootdownright();	// shoot down right of you		
						else shootstart(); // shoot right of you
					}
					//else continue
				}
				else //if dif is more than one 	
				{
					checkhorizontalclearpath(mej-1,yoj-1,mei+1); //check down row clear
					if(wrong==0) //if clear
					{				
						endi=mei+1; endj=mej-1; 
						shootdownleft();	 //shoot left down of you	
					}
					else //if not clear
					{
						checkhorizontalclearpath(mej-1,yoj+1,mei); //check current row clear
						if(wrong==0) //clear
						{
							endi=yoi; endj=yoj+1; 
							if(a[yoi+1][yoj+1]==0) shootdownright(); //shoot down right of you
							else if(a[yoi-1][yoj]==0 && yoi!=0) shootup(); //shoot up of you
							else if(a[yoi-1][yoj+1]==0 && yoi!=0)  shootupright(); //shoot up right of you
							else shootstart(); 				
						}
						//else contninue; 
					}
				}
			}
		}
		else //below middle
		{
			//4th quadrant
			if(mej<yoj) //if me behind you
			{
				if(dif==1) //if dif is 1
				{
					if(a[yoi-1][yoj]==0)//go one above you
					{
						endi=yoi-1; endj=yoj;
						if(a[yoi-1][yoj-1]==0)	shootupleft();  //shoot upleft of you			
						else shootstart(); //shoot left of you
					}
					else if(a[yoi-1][yoj-1]==0)// go one left up of you
					{
						endi=yoi-1; endj=yoj-1; 
						shootstart(); //shoot left of you
					}
					//else continue
				}
				else if(dif==2)
				{
					if(a[yoi][yoj-1]==0) //move left of you
					{
						endi=yoi; endj=yoj-1;
						if(a[yoi-1][yoj-1]==0) shootupleft(); //shoot upleft of you
						else if(a[yoi+1][yoj-1]==0 && yoi!=9) shootdownleft(); //shoot downleft of you
						else if(a[yoi+1][yoj]==0 && yoi!=9) shootdown(); //shoot down of you
						else if(a[yoi-1][yoj]==0) shootup(); //shoot up of you 
						else shootstart();					
					}
					else if(a[yoi-1][yoj-1]==0) //move to down left of you
					{
						endi=yoi-1; endj=yoj-1;
						if(a[yoi-1][yoj]==0) shootup(); //shoot up of you
						else shootstart();
					}
					else if(a[yoi+1][yoj-1]==0 && a[yoi-1][yoj]!=0 && yoi!=9)// move to down left of you
					{	
						endi=yoi+1; endj=yoj-1;						
						if(a[yoi+1][yoj]==0) shootdown(); //shoot down of you
						else shootstart();
					}
					//else contninue
				}
				else //if dif is more than one 	
				{
					checkhorizontalclearpath(mej+1,yoj-1,mei-1); //check up row clear
					if(wrong==0) //if clear
					{
						endi=yoi-1; endj=mej+1; 
						shootupleft(); //shoot up left of you
					}
					else //if not clear 
					{
						checkhorizontalclearpath(mej+1,yoj-1,mei); //check current row clear
						if(wrong==0) //if clear
						{
							endi=yoi; endj=yoj-1; 
							if(a[yoi-1][yoj-1]==0) shootupleft(); //shoot up left of you
							else if(a[yoi+1][yoj-1]==0 && yoi!=9) shootdownleft(); //shoot down left of you
							else if(a[yoi+1][yoj]==0 && yoi!=0) shootdown(); //shoot down of you
							else if(a[yoi-1][yoj]==0) shootup(); //shoot up of you
							else shootstart(); 						
						}
						//else continue
					}
				}
			}
			else //if me ahead you
			{
				if(dif==1) //if dif is 1
				{
					if(a[mei-1][yoj]==0)//go one up you
					{
						endi=mei-1; endj=yoj;
						if(a[yoi-1][yoj-1]==0)  shootupleft();	//shoot up left of you				
						else if(a[yoi][yoj-1]==0)	 shootleft();  //shoot left of you				
						else if(a[yoi-1][yoj+1]==0)	 shootupright();	// shoot up right of you		
						else shootstart(); // shoot right of you
					}
					//else continue
				}
				else //if dif is more than one 	
				{
					checkhorizontalclearpath(mej-1,yoj-1,mei-1); //check up row clear
					if(wrong==0) //if clear
					{				
						endi=mei-1; endj=mej-1; 
						shootupleft();	 //shoot left up of you	
					}
					else //if not clear
					{
						checkhorizontalclearpath(mej-1,yoj+1,mei); //check current row clear
						if(wrong==0) //clear
						{
							endi=yoi; endj=yoj+1; 
							if(a[yoi-1][yoj+1]==0) shootupright(); //shoot up right of you
							else if(a[yoi+1][yoj]==0 && yoi!=9) shootdown(); //shoot down of you
							else if(a[yoi+1][yoj+1]==0 && yoi!=9)  shootdownright(); //shoot down right of you
							else shootstart(); 				
						}
						//else contninue; 
					}
				}
			}
		}
	}
}
void vertical() //vertical for all
{
	//start is already set
	if(yoj<5) //behind middle
	{		
		if(yoi<5) //above middle
		{
			//2nd quadrant
			if(mei<yoi) //if me above you
			{
				if(dif==1) //if dif is 1
				{
					if(a[yoi][yoj+1]==0)//go one right you
					{
						endi=yoi; endj=yoj+1;
						if(a[yoi+1][yoj+1]==0)  shootdownright();	//shoot down right of you				
						else if(a[yoi+1][yoj]==0)	 shootdown();  //shoot down of you				
						else if(a[yoi-1][yoj+1]==0)	 shootupright();	// shoot up right of you		
						else shootstart(); // shoot left of you
					}
					//else continue
				}//check
				else //if dif is more than one 	
				{
					checkverticalclearpath(mei+1,yoi+1,mej+1); //check right col clear
					if(wrong==0) //if clear
					{				
						endi=mei+1; endj=mej+1; 
						shootdownright();	 //shoot right down of you	
					}
					else //if not clear
					{
						checkverticalclearpath(mei+1,yoi-1,mej); //check current col clear
						if(wrong==0) //clear
						{
							endi=yoi-1; endj=yoj; 
							if(a[yoi-1][yoj+1]==0) shootupright(); //shoot up right of you
							else 
							{
								if(yoj!=0)
								{
									if(a[yoi][yoj-1]==0) shootleft(); //shoot left of you
									else if(a[yoi-1][yoj-1]==0) shootupleft(); //shoot up left of you
									else shootstart(); 
								}								
								else shootstart();
							}
						}
						//else contninue; 
					}
				}
			}//check
			else //if me below you
			{
				if(dif==1) //if dif is 1
				{
					if(a[yoi][yoj+1]==0)//go one right you
					{
						endi=yoi; endj=yoj+1;
						if(a[yoi+1][yoj+1]==0)	shootdownright();  //shoot downright of you			
						else shootstart(); //shoot down of you
					}
					else if(a[yoi+1][yoj+1]==0)// go one right down of you
					{
						endi=yoi+1; endj=yoj+1; 
						shootstart(); //shoot down of you
					}
					//else continue
				}//check
				else if(dif==2)
				{
					if(a[yoi+1][yoj]==0) //move down of you
					{
						endi=yoi+1; endj=yoj;
						if(a[yoi+1][yoj+1]==0) shootdownright(); //shoot downright of you
						else if(a[yoi+1][yoj-1]==0 && yoj!=0) shootdownleft(); //shoot downleft of you
						else if(a[yoi][yoj-1]==0 && yoj!=0) shootleft(); //shoot left of you
						else if(a[yoi][yoj+1]==0) shootright(); //shoot right of you 
						else shootstart();					
					}
					else if(a[yoi+1][yoj+1]==0) //move to down right of you
					{
						endi=yoi+1; endj=yoj+1;
						if(a[yoi][yoj+1]==0) shootright(); //shoot right of you
						else shootstart();
					}
					else if(a[yoi+1][yoj-1]==0 && a[yoi][yoj+1]!=0 && yoj!=0)// move to down left of you
					{	
						endi=yoi+1; endj=yoj-1;						
						if(a[yoi][yoj-1]==0) shootleft(); //shoot left of you
						else shootstart();
					}
					//else contninue
				}//check
				else //if dif is more than one 	
				{
					checkverticalclearpath(mei-1,yoi+1,mej+1); //check right col clear
					if(wrong==0) //if clear
					{
						endi=mei-1; endj=mej+1;
						shootdownright(); //shoot down right of you
					}
					else //if not clear 
					{
						checkverticalclearpath(mei-1,yoi+1,mej); //check current col clear
						if(wrong==0) //if clear
						{
							endi=yoi+1; endj=yoj; 
							if(a[yoi+1][yoj+1]==0) shootdownright(); //shoot down right of you
							else if(a[yoi+1][yoj-1]==0 && yoj!=0) shootdownleft(); //shoot downleft of you
							else if(a[yoi][yoj-1]==0 && yoj!=0) shootleft(); //shoot left of you
							else if(a[yoi][yoj+1]==0) shootright(); //shoot right of you
							else shootstart(); 						
						}
						//else continue
					}
				}
			}			
		}//check
		else //below middle
		{
			//3rd quadrant
			if(mei>yoi) //if me below you
			{
				if(dif==1) //if dif is 1
				{
					if(a[yoi][yoj+1]==0)//go one right you
					{
						endi=yoi; endj=yoj+1;
						if(a[yoi-1][yoj+1]==0)  shootupright();	//shoot up right of you				
						else if(a[yoi-1][yoj]==0)	 shootup();  //shoot up of you				
						else if(a[yoi+1][yoj+1]==0)	 shootdownright();	// shoot down right of you		
						else shootstart(); // shoot down of you
					}
					//else continue
				}//check
				else //if dif is more than one 	
				{
					checkverticalclearpath(mei-1,yoi-1,mej+1); //check right col clear
					if(wrong==0) //if clear
					{				
						endi=mei-1; endj=mej+1; 
						shootupright();	 //shoot upright of you	
					}
					else //if not clear
					{
						checkverticalclearpath(mei-1,yoi+1,mej); //check current col clear
						if(wrong==0) //clear
						{
							endi=yoi+1; endj=yoj; 
							if(a[yoi+1][yoj+1]==0) shootdownright(); //shoot downright of you
							else 
							{
								if(a[yoi][yoj-1]==0 && yoj!=0 ) shootleft(); //shoot left of you
								else if(a[yoi+1][yoj-1]==0 && yoj!=0) shootdownleft(); //shoot down left of you
								else shootstart(); 
							}
						}
						//else contninue; 
					}
				}
			}//check
			else //if me above you
			{
				if(dif==1) //if dif is 1
				{
					if(a[yoi][yoj+1]==0)//go one right you
					{
						endi=yoi; endj=yoj+1;
						if(a[yoi-1][yoj+1]==0)	shootupright();  //shoot upright of you			
						else shootstart(); //shoot up of you
					}
					else if(a[yoi-1][yoj+1]==0)// go one right up of you
					{
						endi=yoi-1; endj=yoj+1; 
						shootstart(); //shoot up of you
					}
					//else continue
				}//check
				else if(dif==2)
				{
					if(a[yoi-1][yoj]==0) //move up of you
					{
						endi=yoi-1; endj=yoj;
						if(a[yoi-1][yoj+1]==0) shootupright(); //shoot upright of you
						else if(a[yoi-1][yoj-1]==0 && yoj!=0) shootupleft(); //shoot upleft of you
						else if(a[yoi][yoj-1]==0 && yoj!=0) shootleft(); //shoot left of you
						else if(a[yoi][yoj+1]==0) shootright(); //shoot right of you 
						else shootstart();					
					}
					else if(a[yoi-1][yoj+1]==0) //move to up right of you
					{
						endi=yoi-1; endj=yoj+1;
						if(a[yoi][yoj+1]==0) shootright(); //shoot right of you
						else shootstart();
					}
					else if(a[yoi-1][yoj-1]==0 && a[yoi][yoj+1]!=0 && yoj!=0)// move to up left of you
					{	
						endi=yoi-1; endj=yoj-1;
						if(a[yoi][yoj-1]==0) shootleft(); //shoot left of you
						else shootstart();
					}
					//else contninue
				}//check
				else //if dif is more than one 	
				{
					checkverticalclearpath(mei+1,yoi-1,mej+1); //check right col clear
					if(wrong==0) //if clear
					{
						endi=mei+1; endj=mej+1; 
						shootupright(); //shoot up right of you
					}
					else //if not clear 
					{
						checkverticalclearpath(mei+1,yoi-1,mej); //check current col clear
						if(wrong==0) //if clear
						{
							endi=yoi-1; endj=yoj; 
							if(a[yoi-1][yoj+1]==0) shootupright(); //shoot up right of you
							else if(a[yoi-1][yoj-1]==0 && yoj!=0) shootupleft(); //shoot upleft of you
							else if(a[yoi][yoj-1]==0 && yoi!=0) shootleft(); //shoot left of you
							else if(a[yoi][yoj+1]==0) shootright(); //shoot right of you
							else shootstart(); 						
						}
						//else continue
					}
				}
			}
		}
	}//check
	else //ahead middle
	{
		if(yoi<5) //above middle
		{
			//1st quadrant
			if(mei>yoi) //if me below you
			{
				if(dif==1) //if dif is 1
				{
					if(a[yoi][yoj-1]==0)//go one left you
					{
						endi=yoi; endj=yoj-1;
						if(a[yoi+1][yoj-1]==0)	shootdownleft();  //shoot downleft of you			
						else shootstart(); //shoot down of you
					}
					else if(a[yoi+1][yoj-1]==0)// go one left down of you
					{
						endi=yoi+1; endj=yoj-1; 
						shootstart(); //shoot left of you
					}
					//else continue
				}//check
				else if(dif==2)
				{
					if(a[yoi+1][yoj]==0) //move down of you
					{
						endi=yoi+1; endj=yoj;
						if(a[yoi+1][yoj-1]==0) shootdownleft(); //shoot downleft of you
						else if(a[yoi+1][yoj+1]==0 && yoj!=9) shootdownright(); //shoot downright of you
						else if(a[yoi][yoj+1]==0 && yoi!=9) shootright(); //shoot right of you
						else if(a[yoi][yoj-1]==0) shootleft(); //shoot left of you 
						else shootstart();					
					}
					else if(a[yoi+1][yoj-1]==0) //move to down left of you
					{
						endi=yoi+1; endj=yoj-1;
						if(a[yoi][yoj-1]==0) shootleft(); //shoot left of you
						else shootstart();
					}
					else if(a[yoi+1][yoj+1]==0 && a[yoi][yoj-1]!=0 && yoj!=9)// move to downright of you
					{	
						endi=yoi+1; endj=yoj+1;						
						if(a[yoi][yoj+1]==0) shootright(); //shoot right of you
						else shootstart();
					}
					//else contninue
				}//check
				else //if dif is more than one 	
				{
					checkverticalclearpath(mei-1,yoi+1,mej-1); //check left col clear
					if(wrong==0) //if clear
					{
						endi=mei-1; endj=mej-1; 
						shootdownleft(); //shoot down left of you
					}
					else //if not clear 
					{
						checkverticalclearpath(mei-1,yoi+1,mej); //check current col clear
						if(wrong==0) //if clear
						{
							endi=yoi+1; endj=yoj; 
							if(a[yoi+1][yoj-1]==0) shootdownleft(); //shoot down left of you
							else if(a[yoi+1][yoj+1]==0 && yoj!=9) shootdownright(); //shoot downright of you
							else if(a[yoi][yoj+1]==0 && yoi!=9) shootright(); //shoot right of you
							else if(a[yoi][yoj-1]==0) shootleft(); //shoot left of you
							else shootstart(); 						
						}
						//else continue
					}
				}
			}//check
			else //if me above you
			{
				if(dif==1) //if dif is 1
				{
					if(a[yoi][yoj-1]==0)//go one left you
					{
						endi=yoi; endj=yoj-1;
						if(a[yoi+1][yoj-1]==0)  shootdownleft();	//shoot down left of you				
						else if(a[yoi+1][yoj]==0)	 shootdown();  //shoot down of you				
						else if(a[yoi-1][yoj-1]==0)	 shootupleft();	// shoot upleft of you		
						else shootstart(); // shoot up of you
					}
					//else continue
				}//check
				else //if dif is more than one 	
				{
					checkverticalclearpath(mei+1,yoi+1,mej-1); //check left col clear
					if(wrong==0) //if clear
					{				
						endi=mei+1; endj=mej-1; 
						shootdownleft();	 //shoot left down of you	
					}
					else //if not clear
					{
						checkverticalclearpath(mei+1,yoi-1,mej); //check current col clear
						if(wrong==0) //clear
						{
							endi=yoi-1; endj=yoj; 
							if(a[yoi-1][yoj-1]==0) shootupleft(); //shoot upleft of you
							else if(a[yoi][yoj+1]==0 && yoj!=9) shootright(); //shoot right of you
							else if(a[yoi-1][yoj+1]==0 && yoj!=9)  shootupright(); //shoot up right of you
							else shootstart(); 				
						}
						//else contninue; 
					}
				}
			}
		}//check
		else //below middle
		{
			//4th quadrant
			if(mei<yoi) //if me above you
			{
				if(dif==1) //if dif is 1
				{
					if(a[yoi][yoj-1]==0)//go one left you
					{
						endi=yoi; endj=yoj-1;
						if(a[yoi-1][yoj-1]==0)	shootupleft();  //shoot upleft of you			
						else shootstart(); //shoot up of you
					}
					else if(a[yoi-1][yoj-1]==0)// go one left up of you
					{
						endi=yoi-1; endj=yoj-1; 
						shootstart(); //shoot up of you
					}
					//else continue
				}//check
				else if(dif==2)
				{
					if(a[yoi-1][yoj]==0) //move above of you
					{
						endi=yoi-1; endj=yoj;
						if(a[yoi-1][yoj-1]==0) shootupleft(); //shoot upleft of you
						else if(a[yoi-1][yoj+1]==0 && yoj!=9) shootupright(); //shoot upright of you
						else if(a[yoi][yoj+1]==0 && yoj!=9) shootright(); //shoot right of you
						else if(a[yoi][yoj-1]==0) shootleft(); //shoot left of you 
						else shootstart();					
					}
					else if(a[yoi-1][yoj-1]==0) //move to up left of you
					{
						endi=yoi-1; endj=yoj-1;
						if(a[yoi][yoj-1]==0) shootleft(); //shoot left of you
						else shootstart();
					}
					else if(a[yoi-1][yoj+1]==0 && a[yoi][yoj-1]!=0 && yoj!=9)// move to upright of you
					{	
						endi=yoi-1; endj=yoj+1;						
						if(a[yoi][yoj+1]==0) shootright(); //shoot right of you
						else shootstart();
					}
					//else contninue
				}//check
				else //if dif is more than one 	
				{
					checkverticalclearpath(mei+1,yoi-1,mej-1); //check left col clear
					if(wrong==0) //if clear
					{
						endi=mei+1; endj=mej-1; 
						shootupleft(); //shoot up left of you
					}
					else //if not clear 
					{
						checkverticalclearpath(mei+1,yoi-1,mej); //check current col clear
						if(wrong==0) //if clear
						{
							endi=yoi-1; endj=yoj; 
							if(a[yoi-1][yoj-1]==0) shootupleft(); //shoot up left of you
							else if(a[yoi-1][yoj+1]==0 && yoj!=9) shootupright(); //shoot upright of you
							else if(a[yoi][yoj+1]==0 && yoj!=9) shootright(); //shoot right of you
							else if(a[yoi][yoj-1]==0) shootleft(); //shoot left of you
							else shootstart(); 						
						}
						//else continue
					}
				}
			}//check
			else //if me below you
			{
				if(dif==1) //if dif is 1
				{
					if(a[yoi][yoj-1]==0)//go one left you
					{
						endi=yoi; endj=yoj-1;
						if(a[yoi-1][yoj-1]==0)  shootupleft();	//shoot up left of you				
						else if(a[yoi-1][yoj]==0)	 shootup();  //shoot up of you				
						else if(a[yoi+1][yoj-1]==0)	 shootdownleft();	// shoot downl left of you		
						else shootstart(); // shoot down of you
					}
					//else continue
				}//check
				else //if dif is more than one 	
				{
					checkverticalclearpath(mei-1,yoi-1,mej-1); //check left col clear
					if(wrong==0) //if clear
					{				
						endi=mei-1; endj=mej-1; 
						shootupleft();	 //shoot left up of you	
					}
					else //if not clear
					{
						checkverticalclearpath(mei-1,yoi+1,mej); //check current col clear
						if(wrong==0) //clear
						{
							endi=yoi+1; endj=yoj; 
							if(a[yoi+1][yoj-1]==0) shootdownleft(); //shoot down left of you
							else if(a[yoi][yoj+1]==0 && yoj!=9) shootright(); //shoot right of you
							else if(a[yoi+1][yoj+1]==0 && yoj!=9)  shootdownright(); //shoot down right of you
							else shootstart(); 				
						}
						//else contninue; 
					}
				}
			}
		}
	}
}//check

int main() 
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==1)
			{
				pi[1][index1]=i;
				pj[1][index1]=j;
				index1++;
			}
			else if(a[i][j]==2)
			{
				pi[2][index2]=i;
				pj[2][index2]=j;
				index2++;
			}
		}
	}
    cin>>me;
    if(me==1) you=2;
    else if(me==2) you=1;		
	if(done==0)
	{
		for(int i=0;i<4;i++)
		{
			yoi=pi[you][i]; yoj=pj[you][i];			
			countyou[i]=countarrowyou();
		}
		for(int i=0;i<4;i++)
		{
			int maxarrow=0,maxpos=0;			
			for(int j=0;j<4;j++)
			{
				if(countyou[j]>maxarrow)
				{
					maxarrow=countyou[j];
					maxpos=j;	
				}
			}
			order[i]=maxpos;
			countyou[maxpos]=0;
		}
		for(int i=0;i<4;i++)
		{
			yoi=pi[you][order[i]]; yoj=pj[you][order[i]];
			shootpossible();
			if(done==1) break;
		}
	}
	if(done==0) {
	for(int i=0;i<4;i++)
    {
    	for(int j=0;j<4;j++)
        {
    	    if(pi[me][i]==pi[you][j])// horizontal
            {
    	        mei=pi[me][i];mej=pj[me][i];yoi=pi[you][j];yoj=pj[you][j];           
                dif=fabs(mej-yoj);       
                starti=mei; startj=mej;
				horizontal(); //on any row                
    	    }   
			else if(pj[me][i]==pj[you][j])
			{
				mei=pi[me][i]; mej=pj[me][i]; yoi=pi[you][j]; yoj=pj[you][j];
				dif=fabs(mei-yoi);
				starti=mei; startj=mej;
				vertical();
			}
			if(done==1) break;
    	}
		if(done==1) break;
    }
	}
	if(done==0)
	{
		for(int i=0;i<4;i++)
		{
			mei=pi[me][i]; mej=pj[me][i];
			starti=mei; startj=mej;			
			randommove();
			if(done==1) break;
		}		
	}
	printf("%d %d\n",starti,startj);
	printf("%d %d\n",endi,endj);
	printf("%d %d\n",shooti,shootj);	
	return 0;
}
