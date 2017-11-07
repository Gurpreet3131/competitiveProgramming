void shootfar()
{
	int distance=0,tempdistance=0,direction=0;
	//diagonal
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
				if(wrong==0) shootpos(i,j);
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
				shootpos(endi,j);
			}		
			else
			{
				if(j<endj) checkhorizontalclearpath(j,endj-1,endi);
				else checkhorizontalclearpath(endj+1,j,endi);
				if(wrong==0) shootpos(endi,j); 
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
				shootpos(i,endj);
			}		
			else
			{
				if(i<endi) checkverticalclearpath(i,endi-1,endj);
				else checkverticalclearpath(endi+1,i,endj);
				if(wrong==0) shootpos(i,endj); 
			}	
		}		
	}
}
