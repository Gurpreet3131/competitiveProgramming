#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int starti,startj,endi,endj,shooti,shootj;
int wrong=0,done=0,mei,mej,yoi,yoj,dif=0;
int a[10][10],pi[3][4],pj[3][4],me=0,you=0,clrstatus=0;
int index1=0,index2=0,countyou[4]={0},countme[4]={0},order[4]={0},orderrescue[4]={0};
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
void shootpos(int ti,int tj)
{
	shooti=ti; shootj=tj; done=1;
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
    	
		if(a[row][k]!=0 )
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
void shootfar()
{
	int distance=0,tempdistance=0,direction=0;
	//diagonal
	//a[starti][startj]=0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			tempdistance=fabs(endi-i);			
			if(fabs(endi-i)==fabs(endj-j) && a[i][j]==0 && tempdistance>distance)
			{
				if(i<endi && j<endj) direction=2;
				else if(i<endi && j>endj) direction=1;
				else if(i>endi && j<endj) direction=3;
				else if(i>endi && j>endj) direction=4;				
				diagonalclear(endi,endj,i,j,direction);
				if(wrong==0) {shootpos(i,j); distance=tempdistance; }
			}
		}
	}
	//horizontal	
	for(int j=0;j<10;j++)
	{
		if(endj==j) continue;	
		tempdistance=fabs(endj-j);	
		if(a[endi][j]==0 && tempdistance>distance)
		{
			if(tempdistance==1)
			{
				shootpos(endi,j); distance=tempdistance;
			}		
			else
			{
				if(j<endj) checkhorizontalclearpath(j,endj-1,endi);
				else checkhorizontalclearpath(endj+1,j,endi);
				if(wrong==0) { shootpos(endi,j);  distance=tempdistance;}  
			}	
		}		
	}
	//vertical
	for(int i=0;i<10;i++)
	{
		if(endi==i) continue;	
		tempdistance=fabs(endi-i);	
		if(a[i][endj]==0 && tempdistance>distance)
		{
			if(tempdistance==1)
			{
				shootpos(i,endj); distance=tempdistance;
			}		
			else
			{
				if(i<endi) checkverticalclearpath(i,endi-1,endj);
				else checkverticalclearpath(endi+1,i,endj);
				if(wrong==0) { shootpos(i,endj); distance=tempdistance;}  
			}	
		}		
	}
	if(done==0) shootstart();
	a[starti][startj]=me;
}
void randommove()
{
	if(mej<5) //if me behind middle
	{
		if(mei<5)//above middle
		{
			//2nd quadrant
			if(a[mei+1][mej+1]==0) {	movedownright(); shootfar();	}
			else if(a[mei][mej+1]==0) {	moveright(); shootfar();	}
			else if(a[mei+1][mej]==0) {	movedown(); shootfar();	}
			else if(a[mei-1][mej+1]==0 && mei!=0) {	moveupright(); shootfar();	}
			else if(a[mei+1][mej-1]==0 && mej!=0) {	movedownleft(); shootfar();	}
			else if(a[mei-1][mej]==0 && mei!=0) {	moveup(); shootfar();	}
			else if(a[mei][mej-1]==0 && mej!=0) {	moveleft(); shootfar();	}
			else if(a[mei-1][mej-1]==0 && mei!=0 && mej!=0) {	moveupleft(); shootfar();	}		
		}
		else //below middle
		{
			//3rd quadrant
			if(a[mei-1][mej+1]==0) {	moveupright(); shootfar();	}
			else if(a[mei-1][mej]==0) {	moveup(); shootfar();	}
			else if(a[mei][mej+1]==0) {	moveright(); shootfar();	}
			else if(a[mei-1][mej-1]==0 && mej!=0) {	moveupleft(); shootfar();	}
			else if(a[mei+1][mej+1]==0 && mei!=9) {	movedownright(); shootfar();	}
			else if(a[mei][mej-1]==0 && mej!=0) {	moveleft(); shootfar();	}	
			else if(a[mei+1][mej]==0 && mei!=9) {	movedown(); shootfar();	}
			else if(a[mei+1][mej-1]==0 && mej!=0 && mei!=9) {	movedownleft(); shootfar();	}
		}
 	}
	else	// me ahead middle
	{
		if(mei<5)//above middle
		{
			//1st quadrant
			if(a[mei+1][mej-1]==0) {	movedownleft(); shootfar();	}
			else if(a[mei][mej-1]==0) {	moveleft(); shootfar();	}
			else if(a[mei+1][mej]==0) {	movedown(); shootfar();	}
			else if(a[mei-1][mej-1]==0 && mei!=0) {	moveupleft(); shootfar();	}
			else if(a[mei+1][mej+1]==0 && mej!=9) {	movedownright();shootfar();	}
			else if(a[mei-1][mej]==0 && mei!=0) {	moveup(); shootfar();	}
			else if(a[mei][mej+1]==0 && mej!=9) {	moveright(); shootfar();	}
			else if(a[mei-1][mej+1]==0 && mei!=0 && mej!=9) {	moveupright(); shootfar();	}
		}
		else //below middle
		{
			//4th quadrant
			if(a[mei-1][mej-1]==0) {	moveupleft(); shootfar();	}
			else if(a[mei-1][mej]==0) {	moveup(); shootfar();	}
			else if(a[mei][mej-1]==0) {	moveleft(); shootfar();	}
			else if(a[mei-1][mej+1]==0 && mej!=9) {	moveupright(); shootfar();	}
			else if(a[mei+1][mej-1]==0 && mei!=9) {	movedownleft(); shootfar();	}
			else if(a[mei][mej+1]==0 && mej!=9) {	moveright(); shootfar(); }
			else if(a[mei+1][mej]==0 && mei!=9) {	movedown(); shootfar();	}
			else if(a[mei+1][mej+1]==0 && mej!=9 && mei!=9) {	movedownright(); shootfar();	}
		}
	}
}////////////// 
int countarrow(int i,int j)
{
	int count=0;
	if(a[i-1][j-1]!=0 || i==0 || j==0) count++;
	if(a[i-1][j]!=0 || i==0) count++;
	if(a[i-1][j+1]!=0 || i==0 || j==9) count++;
	if(a[i][j-1]!=0 || j==0) count++;
	if(a[i][j+1]!=0 || j==9) count++;
	if(a[i+1][j-1]!=0 || i==9 || j==0) count++;
	if(a[i+1][j]!=0 || i==9) count++;
	if(a[i+1][j+1]!=0 || i==9 || j==9) count++;
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
	int yes=0,tyes=0,tendi,tendj,tstarti,tstartj;	
	//diagonal
	int minarrowcount=10,tempmincount=0;
	for(int i=3;i>=0;i--)
	{
		mei=pi[me][i]; mej=pj[me][i];
		starti=mei; startj=mej;
		//a[starti][startj]=0;		
		int direction=1;
		if(direction==1)
		{
			int j=tj+1;			
			for(int i=ti-1;i>=0 && j<10;i--,j++)
			{												
				if(ti==i && tj==j) continue;
				tempmincount=countarrow(i,j);
				if(a[i][j]==0 && tempmincount<minarrowcount)
				{
					diagonalclear(ti,tj,i,j,direction);
					if(wrong==0)
					{						
						yes=reachpos(i,j);
						if(yes==1) { minarrowcount=tempmincount; tyes=1; tendi=endi; tendj=endj; tstarti=starti; tstartj=startj; }					
					}
					else break;
				}
				
			}
			direction++;
		}
		if(direction==2)
		{
			int j=tj-1;			
			for(int i=ti-1;i>=0 && j>=0;i--,j--)
			{								
				if(ti==i && tj==j) continue;
				tempmincount=countarrow(i,j);
				if(a[i][j]==0 && tempmincount<minarrowcount)
				{
					diagonalclear(ti,tj,i,j,direction);
					if(wrong==0)
					{
						yes=reachpos(i,j);
						if(yes==1) {minarrowcount=tempmincount; tyes=1; tendi=endi; tendj=endj; tstarti=starti; tstartj=startj;}
					}
					else break;
				}
			}
			direction++;
		}
		if(direction==3)
		{
			int j=tj-1;			
			for(int i=ti+1;i<10 && j>=0;i++,j--)
			{								
				if(ti==i && tj==j) continue;
				tempmincount=countarrow(i,j);
				if(a[i][j]==0 && tempmincount<minarrowcount)
				{
					diagonalclear(ti,tj,i,j,direction);
					if(wrong==0)
					{
						yes=reachpos(i,j);
						if(yes==1) {minarrowcount=tempmincount; tyes=1; tendi=endi; tendj=endj; tstarti=starti; tstartj=startj;}
					}
					else break;
				}
			}
			direction++;
		}
		if(direction==4)
		{
			int j=tj+1;			
			for(int i=ti+1;i<10 && j<10;i++,j++)
			{								
				if(ti==i && tj==j) continue;
				tempmincount=countarrow(i,j);
				if(a[i][j]==0 && tempmincount<minarrowcount)
				{
					diagonalclear(ti,tj,i,j,direction);
					if(wrong==0)
					{
						yes=reachpos(i,j);
						if(yes==1) { minarrowcount=tempmincount; tyes=1; tendi=endi; tendj=endj; tstarti=starti; tstartj=startj;}
					}
					else break;
				}
			}
			direction++;
		}
		a[starti][startj]=me;
	}
	//horizontal
	for(int i=3;i>=0;i--)
	{
		mei=pi[me][i]; mej=pj[me][i];
		starti=mei; startj=mej;
		//a[starti][startj]=0;		
		for(int j=0;j<10;j++)
		{
			if(j==tj) continue;	
			tempmincount=countarrow(ti,j);		
			if(a[ti][j]==0 && tempmincount<minarrowcount)
			{
				dif=fabs(j-tj);
				if(dif==1)
				{
					yes=reachpos(ti,j);
					if(yes==1) { minarrowcount=tempmincount; tyes=1; tendi=endi; tendj=endj; tstarti=starti; tstartj=startj;}
				}
				else
				{
					if(j<tj) checkhorizontalclearpath(j+1,tj-1,ti);
					else checkhorizontalclearpath(tj+1,j-1,ti);
					if(wrong==0)
					{
						yes=reachpos(ti,j);
						if(yes==1) { minarrowcount=tempmincount; tyes=1; tendi=endi; tendj=endj; tstarti=starti; tstartj=startj;}
					}
				}	
			}
			
		}
		a[starti][startj]=me;
	}
	//vertical
	for(int i=3;i>=0;i--)
	{
		mei=pi[me][i]; mej=pj[me][i];
		starti=mei; startj=mej;
		//a[starti][startj]=0;
		for(int ii=0;ii<10;ii++)
		{
			if(ii==ti) continue;	
			tempmincount=countarrow(ii,tj);			
			if(a[ii][tj]==0 && tempmincount<minarrowcount)
			{
				dif=fabs(ii-ti);
				if(dif==1)
				{
					yes=reachpos(ii,tj);
					if(yes==1) { minarrowcount=tempmincount; tyes=1; tendi=endi; tendj=endj; tstarti=starti; tstartj=startj;}
				}
				else
				{
					if(ii<ti) checkverticalclearpath(ii+1,ti-1,tj);
					else checkverticalclearpath(ti+1,ii-1,tj);
					if(wrong==0)
					{
						yes=reachpos(ii,tj);
						if(yes==1) { minarrowcount=tempmincount; tyes=1; tendi=endi; tendj=endj; tstarti=starti; tstartj=startj;}	
					}
				}	
			}
		}
		a[starti][startj]=me;
	}
	endi=tendi; endj=tendj;
	starti=tstarti; startj=tstartj;
	return tyes;
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
int shootposafterrescue(int i,int j)
{
	int yespos=0,direction=0;
	//horizontal check
	//a[starti][startj]=0;
	if(endi==i)
	{		
		if(fabs(endj-j)==1) yespos=1;
		else
		{
			if(endj<j) checkhorizontalclearpath(endj+1,j,endi);
			else checkhorizontalclearpath(j,endj-1,endi);
			if(wrong==0) yespos=1;
		}		
	}
	if(yespos==1) return yespos;
	//vertical check
	if(endj==j)
	{
		if(fabs(endi-i)==1) yespos=1;		
		else
		{
			if(endi<i) checkverticalclearpath(endi+1,i,endj);
			else checkverticalclearpath(i,endi-1,endj);
			if(wrong==0) yespos=1;
	
		}
	}
	if(yespos==1) return yespos;
	//diagonal check
	if(fabs(endi-i)==fabs(endj-j))
	{
		if(i<endi && j<endj) direction=2;
		else if(i<endi && j>endj) direction=1;
		else if(i>endi && j<endj) direction=3;
		else if(i>endi && j>endj) direction=4; 		
		diagonalclear(endi,endj,i,j,direction);
		if(wrong==0) yespos=1;
	}
	a[starti][startj]=me;
	return yespos;	
}
void shootafterrescue()
{
	 for(int i=0;i<4;i++)
	{
		yoi=pi[you][order[i]]; yoj=pj[you][order[i]];
		int per=0;	//a[starti][startj]=0;
		if(yoj<5) //if you behind middle
		{
			if(yoi<5)//above middle
			{
				//2nd quadrant
				if((a[yoi+1][yoj+1]==0 || (starti==yoi+1 && startj==yoj+1)) && (endi!=yoi+1 || endj!=yoj+1 )) {	per=shootposafterrescue(yoi+1,yoj+1); if(per==1) shootdownright(); 	}
				if((a[yoi+1][yoj]==0 || (starti==yoi+1 && startj==yoj)) && done==0 && (endi!=yoi+1 || endj!=yoj)) {	per=shootposafterrescue(yoi+1,yoj); if(per==1) shootdown();	}
				if((a[yoi][yoj+1]==0 || (starti==yoi && startj==yoj+1)) && done==0&& (endi!=yoi || endj!=yoj+1)) {	per=shootposafterrescue(yoi,yoj+1); if(per==1) shootright();	}
				if((a[yoi+1][yoj-1]==0 || (starti==yoi+1 && startj==yoj-1)) && yoj!=0 && done==0 && (endi!=yoi+1 || endj!=yoj-1)) {	per=shootposafterrescue(yoi+1,yoj-1); if(per==1) shootdownleft();	}
				if((a[yoi-1][yoj+1]==0 || (starti==yoi-1 && startj==yoj+1)) && yoi!=0 && done==0 && (endi!=yoi-1 || endj!=yoj+1))  {	per=shootposafterrescue(yoi-1,yoj+1); if(per==1) shootupright();	}
				if((a[yoi][yoj-1]==0 || (starti==yoi && startj==yoj-1))&& yoj!=0 && done==0 && (endi!=yoi || endj!=yoj-1)) {	per=shootposafterrescue(yoi,yoj-1); if(per==1) shootleft();}
				if((a[yoi-1][yoj]==0 || (starti==yoi-1 && startj==yoj)) && yoi!=0 && done==0 && (endi!=yoi-1 || endj!=yoj)) {	per=shootposafterrescue(yoi-1,yoj); if(per==1) shootup();	}
				if((a[yoi-1][yoj-1]==0 || (starti==yoi-1 && startj==yoj-1)) && yoi!=0 && yoj!=0 && done==0 && (endi!=yoi-1 || endj!=yoj-1)) {	per=shootposafterrescue(yoi-1,yoj-1); if(per==1) shootupleft();	}		
			}
			else //below middle
			{
				//3rd quadrant
				if((a[yoi-1][yoj+1]==0 || (starti==yoi-1 && startj==yoj+1)) && (endi!=yoi-1 || endj!=yoj+1)) {	per=shootposafterrescue(yoi-1,yoj+1); if(per==1) shootupright();	}
				if((a[yoi-1][yoj]==0 || (starti==yoi-1 && startj==yoj)) && done==0 && (endi!=yoi-1 || endj!=yoj)) {	per=shootposafterrescue(yoi-1,yoj); if(per==1) shootup();	}
				if((a[yoi][yoj+1]==0 || (starti==yoi && startj==yoj+1)) && done==0&& (endi!=yoi || endj!=yoj+1)) {	per=shootposafterrescue(yoi,yoj+1); if(per==1) shootright();}
				if((a[yoi-1][yoj-1]==0 || (starti==yoi-1 && startj==yoj-1)) && yoj!=0 && done==0 && (endi!=yoi-1 || endj!=yoj-1)) {	per=shootposafterrescue(yoi-1,yoj-1); if(per==1) shootupleft();	}
				if((a[yoi+1][yoj+1]==0 || (starti==yoi+1 && startj==yoj+1)) && yoi!=9 && done==0 && (endi!=yoi+1 || endj!=yoj+1)) {	per=shootposafterrescue(yoi+1,yoj+1); if(per==1) shootdownright(); 	}
				if((a[yoi][yoj-1]==0 || (starti==yoi && startj==yoj-1)) && yoj!=0 && done==0 && (endi!=yoi || endj!=yoj-1)) {	per=shootposafterrescue(yoi,yoj-1); if(per==1) shootleft();	}	
				if((a[yoi+1][yoj]==0 || (starti==yoi+1 && startj==yoj)) && yoi!=9 && done==0 && (endi!=yoi+1 || endj!=yoj)) {	per=shootposafterrescue(yoi+1,yoj); if(per==1) shootdown();	}
				if((a[yoi+1][yoj-1]==0 || (starti==yoi+1 && startj==yoj-1)) && yoj!=0 && yoi!=9 && done==0 && (endi!=yoi+1 || endj!=yoj-1)) {	per=shootposafterrescue(yoi+1,yoj-1); if(per==1) shootdownleft();	}
			}
	 	}
		else	// you ahead middle
		{
			if(yoi<5)//above middle
			{
				//1st quadrant
				if((a[yoi+1][yoj-1]==0 || (starti==yoi+1 && startj==yoj-1)) && (endi!=yoi+1 || endj!=yoj-1)) {	per=shootposafterrescue(yoi+1,yoj-1); if(per==1) shootdownleft();	}
				if((a[yoi+1][yoj]==0 || (starti==yoi+1 && startj==yoj)) && done==0 && (endi!=yoi+1 || endj!=yoj)) {	per=shootposafterrescue(yoi+1,yoj); if(per==1) shootdown();	}
				if((a[yoi][yoj-1]==0 || (starti==yoi && startj==yoj-1)) && done==0 && (endi!=yoi || endj!=yoj-1)) {	per=shootposafterrescue(yoi,yoj-1); if(per==1) shootleft();	}
				if((a[yoi+1][yoj+1]==0 || (starti==yoi+1 && startj==yoj+1)) && yoj!=9 && done==0 && (endi!=yoi+1 || endj!=yoj+1)) {	per=shootposafterrescue(yoi+1,yoj+1); if(per==1) shootdownright(); 	}
				if((a[yoi-1][yoj-1]==0 || (starti==yoi-1 && startj==yoj-1)) && yoi!=0 && done==0 && (endi!=yoi-1 || endj!=yoj-1)) {	per=shootposafterrescue(yoi-1,yoj-1); if(per==1) shootupleft();	}
				if((a[yoi][yoj+1]==0 || (starti==yoi && startj==yoj+1)) && yoj!=9 && done==0 && (endi!=yoi || endj!=yoj+1)) {	per=shootposafterrescue(yoi,yoj+1); if(per==1) shootright();	}
				if((a[yoi-1][yoj]==0 || (starti==yoi-1 && startj==yoj)) && yoi!=0 && done==0 && (endi!=yoi-1 || endj!=yoj)) {	per=shootposafterrescue(yoi-1,yoj); if(per==1) shootup();	}
				if((a[yoi-1][yoj+1]==0 || (starti==yoi-1 && startj==yoj+1)) && yoi!=0 && yoj!=9 && done==0 && (endi!=yoi-1 || endj!=yoj+1)) {	per=shootposafterrescue(yoi-1,yoj+1); if(per==1) shootupright();	}
			}
			else //below middle
			{
				//4th quadrant
				if((a[yoi-1][yoj-1]==0 || (starti==yoi-1 && startj==yoj-1)) && (endi!=yoi-1 || endj!=yoj-1)) {	per=shootposafterrescue(yoi-1,yoj-1); if(per==1) shootupleft();	}
				if((a[yoi-1][yoj]==0 || (starti==yoi-1 && startj==yoj)) && done==0 && (endi!=yoi-1 || endj!=yoj)) {	per=shootposafterrescue(yoi-1,yoj); if(per==1) shootup();	}
				if((a[yoi][yoj-1]==0 || (starti==yoi && startj==yoj-1))&& done==0 && (endi!=yoi || endj!=yoj-1)) {	per=shootposafterrescue(yoi,yoj-1); if(per==1) shootleft();	}
				if((a[yoi-1][yoj+1]==0 || (starti==yoi-1 && startj==yoj+1)) && yoj!=9 && done==0 && (endi!=yoi-1 || endj!=yoj+1)) {	per=shootposafterrescue(yoi-1,yoj+1); if(per==1) shootupright();	}
				if((a[yoi+1][yoj-1]==0 || (starti==yoi+1 && startj==yoj-1))&& yoi!=9 && done==0 && (endi!=yoi+1 || endj!=yoj-1)) {	per=shootposafterrescue(yoi+1,yoj-1); if(per==1) shootdownleft();	}
				if((a[yoi][yoj+1]==0 || (starti==yoi && startj==yoj+1)) && yoj!=9 && done==0 && (endi!=yoi || endj!=yoj+1)) {	per=shootposafterrescue(yoi,yoj+1); if(per==1) shootright();	}
				if((a[yoi+1][yoj]==0 || (starti==yoi+1 && startj==yoj))&& yoi!=9 && done==0 && (endi!=yoi+1 || endj!=yoj)) {	per=shootposafterrescue(yoi+1,yoj); if(per==1) shootdown();	}
				if((a[yoi+1][yoj+1]==0 || (starti==yoi+1 && startj==yoj+1)) && yoj!=9 && yoi!=9 && done==0 && (endi!=yoi+1 || endj!=yoj+1)) {	per=shootposafterrescue(yoi+1,yoj+1); if(per==1) shootdownright(); 	}
			}
		}			
    }
	if(done==0)  shootfar();
	a[starti][startj]=me;
}
int rescue()
{
	int yesrescue=0;
	//diagonal
	int direction=1,minarrowcount=9,tempendi,tempendj;
	if(direction==1)
	{
		tempendi=starti; tempendj=startj;		minarrowcount=countarrow(mei,mej);		
		while(tempendi>0 && tempendj<9)
		{
			if(a[tempendi-1][tempendj+1]==0 && countarrow(tempendi-1,tempendj+1)<minarrowcount)
			{
				tempendi--; tempendj++;					
				endi=tempendi; endj=tempendj;
				minarrowcount=countarrow(endi,endj);
				yesrescue=1;
			}
			else if(a[tempendi-1][tempendj+1]==0)
			{
				tempendi--; tempendj++;
			} 
			else break;
		}
		direction++; 
	}
	if(direction==2)
	{
		yesrescue=0;	tempendi=starti; tempendj=startj;		
		while(tempendi>0 && tempendj>0)
		{
			if(a[tempendi-1][tempendj-1]==0	&& countarrow(tempendi-1,tempendj-1)<minarrowcount)
			{
				tempendi--; tempendj--;					
				endi=tempendi; endj=tempendj;
				minarrowcount=countarrow(endi,endj);
				yesrescue=1;
			}
			else if(a[tempendi-1][tempendj-1]==0)
			{
				tempendi--; tempendj--;
			} 
			else break;
		}
		direction++; 
	}
	if(direction==3)
	{
		yesrescue=0;	tempendi=starti; tempendj=startj;	
		while(tempendi<9 && tempendj>0 )
		{
			if(a[tempendi+1][tempendj-1]==0 && countarrow(tempendi-1,tempendj-1)<minarrowcount)
			{
				tempendi++; tempendj--;					
				endi=tempendi; endj=tempendj;
				minarrowcount=countarrow(endi,endj);
				yesrescue=1;
			}
			else if(a[tempendi+1][tempendj-1]==0)
			{
				tempendi++; tempendj--;
			} 
			else break;
		}
		direction++; 
	}
	if(direction==4)
	{
		yesrescue=0;	tempendi=starti; tempendj=startj;	
		while(tempendi<9 && tempendj<9)
		{
			if(a[tempendi+1][tempendj+1]==0 && countarrow(tempendi+1,tempendj+1)<minarrowcount)
			{
				tempendi++; tempendj++;					
				endi=tempendi; endj=tempendj;
				minarrowcount=countarrow(endi,endj);
				yesrescue=1;
			}
			else if(a[tempendi+1][tempendj+1]==0)
			{
				tempendi++; tempendj++;
			} 
			else break;
		}
		direction++; 
	}
	//horizontal
	for(int j=0;j<10;j++)
	{
		if(j==startj) continue;	
		if(j<startj) checkhorizontalclearpath(startj-1,j,starti);		
		else 	checkhorizontalclearpath(startj+1,j,starti);	
		if(a[starti][j]==0 && countarrow(starti,j)<minarrowcount && wrong==0)
		{
			endi=starti; endj=j;
            minarrowcount=countarrow(endi,endj);
			yesrescue=1;			
		}
	}
	//vertical
	for(int i=0;i<10;i++)
	{
		if(i==starti) continue;
		if(i<starti) checkverticalclearpath(starti-1,i,startj);		
		else 	checkverticalclearpath(starti+1,i,startj);	
		if(a[i][startj]==0 && countarrow(i,startj)<minarrowcount && wrong==0)
		{
			endi=i; endj=startj;
            minarrowcount=countarrow(endi,endj);
			yesrescue=1;			
		}
	}
	return yesrescue;					
}
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
    for(int i=0;i<4;i++)
	{
		yoi=pi[you][i]; yoj=pj[you][i];			
		countyou[i]=countarrow(yoi,yoj);
        mei=pi[me][i]; mej=pj[me][i];
        countme[i]=countarrow(mei,mej);		
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
		int maxarrow=0,maxpos=0;			
		for(int j=0;j<4;j++)
		{
	    	if(countme[j]>maxarrow)
			{
	    		maxarrow=countme[j];
				maxpos=j;	
			}
		}
		orderrescue[i]=maxpos;
		countme[maxpos]=0;
	}	
    for(int i=0;i<4;i++) //rescue
	{
        mei=pi[me][orderrescue[i]]; mej=pj[me][orderrescue[i]];
        countme[i]=countarrow(mei,mej);
        starti=mei; startj=mej;
		//a[starti][startj]=0;
        int yesr=0;
        if(countarrow(starti,startj)<5) continue;
		yesr=rescue();
        if(yesr==1) shootafterrescue();
		a[starti][startj]=me;
        if(done==1) break;		
    }
    if(done==0)
	{
		for(int i=0;i<4;i++)
		{
			yoi=pi[you][order[i]]; yoj=pj[you][order[i]];
			shootpossible();
			if(done==1) break;
		}
	}
	if(done==0)
	{
		for(int i=0;i<4;i++)
		{
			mei=pi[me][i]; mej=pj[me][i];
			starti=mei; startj=mej;		
			a[starti][startj]=0;	
			randommove(); //shootfar
			a[starti][startj]=me;	
			if(done==1) break;
		}		
	}
	printf("%d %d\n",starti,startj);
	printf("%d %d\n",endi,endj);
	printf("%d %d\n",shooti,shootj);	
	return 0;
}
