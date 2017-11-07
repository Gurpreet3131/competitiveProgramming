#include <bits/stdc++.h>
using namespace std;
const int n = 5;
int me,you; 
int maxd=2, more2=0;
int surct[n+1][n+1];
int rflag=0;
int sc[6][6]={0};
struct chain
{
    int pl[n+1][n+1];
    int amt[n+1][n+1]; 
    //int turn;
	void print_board();
    pair<int, int> movegen(int turn);
	int minimax(int pl[n+1][n+1], int amt[n+1][n+1],int turn, int depth);	// minimax(board,turn,depth)
	int win(int pl[n+1][n+1], int amt[n+1][n+1], int depth); // win(board)
	int evaluatescore(int pl[n+1][n+1], int amt[n+1][n+1], int turn, int depth); // evalutescore(board,depth)
};

void chain::print_board()
{
	cout<<"BOARD: \n\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(pl[i][j] == 1 || pl[i][j]==0) printf("%d",pl[i][j]);
			else printf("2");
			printf("%d ",amt[i][j]);
		}
		cout<<endl;
	}
}

void reaction(int pl[n+1][n+1], int amt[n+1][n+1], int i, int j, int who)
{
	int amtleft = amt[i][j]%surct[i][j], pass = amt[i][j]/surct[i][j];
	amt[i][j] = amtleft; if(amtleft == 0) pl[i][j] =0;
	int up = i-1, down = i+1, left = j-1, right = j+1;
	int mect=0, youct=0;
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=n;y++)
		{
			if(pl[x][y] == you) 
			{
				youct+= amt[x][y];
			}
			else if(pl[x][y] == me) 
			{
				mect+= amt[x][y];
			}
		}
	}
	if(youct==0 || mect==0) return;
	if(pass>0)
	{
		if(up>0) pl[up][j] = who, amt[up][j]+=pass;
		if(down<=n) pl[down][j] = who; amt[down][j]+= pass;
   		if(left>0) pl[i][left] = who; amt[i][left]+= pass;
   		if(right<=n) pl[i][right] = who; amt[i][right]+= pass;
   		// now use recursion for chain reaction
   		if(up>0) reaction(pl,amt,up,j,who);
   		if(down<=n) reaction(pl,amt,down,j,who);
   		if(left>0) reaction(pl,amt,i,left,who);
   		if(right<=n) reaction(pl,amt,i,right,who);
	}
}
void print_temp(int pl[n+1][n+1], int amt[n+1][n+1])
{
	cout<<"TEMP BOARD: \n\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(pl[i][j] == 1 || pl[i][j]==0) printf("%d",pl[i][j]);
			else printf("2");
			printf("%d ",amt[i][j]);
		}
		cout<<endl;
	}
}
pair<int, int> chain::movegen(int turn)
{
    int maxscore = INT_MIN, minscore = INT_MAX;
    pair <int, int> p;
    int temppl[n+1][n+1],tempamt[n+1][n+1];
    for(int i=1; i<=n; i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		//if(i==5&& j==5) break; 

    		if(pl[i][j] ==0 || pl[i][j] == turn)
    		{
		    	//cout<<"move = "<<i<<" "<<j<<" "<<endl;
    			int flag = 0;
    			if(pl[i][j] == 0) flag=1; // emtpy cell
    			pl[i][j] = turn; amt[i][j]++;
    			for(int k=1;k<=n;k++)
    			{
    				for(int l=1;l<=n;l++)
    				{
    					temppl[k][l] = pl[k][l];
    					tempamt[k][l] = amt[k][l];
    				}
    			}
    			// make the move and then pass copy of the final board
		    	//print_temp(temppl, tempamt);

    			if(amt[i][j] >=surct[i][j]) reaction(temppl,tempamt,i,j,turn);
    			//cout<<"After reaction\n";
		    	//print_temp(temppl, tempamt);

    			int tempscore = minimax(temppl,tempamt, -turn, 1);                   
    			if(tempscore > maxscore)
    			{
    				maxscore = tempscore; p.first = i; p.second = j;
    			}
    			else if(tempscore == maxscore)
    			{
    				if(surct[p.first][p.second]>surct[i][j])
    				{
    					p.first = i; p.second = j;
    				}
    			}
    			if(tempscore<minscore)	minscore = tempscore;
    			if(flag==1) 
    			{
    				pl[i][j] = 0; amt[i][j] = 0;
    			}
    			else amt[i][j]--;
    			sc[i-1][j-1] = tempscore;
    			//cout<<"score = "<<i-1<<" "<<j-1<<" "<<tempscore<<endl;
    		}
    	}
    }
    /*if(maxscore == minscore)
    {
    	//cout<<"random\n";
        while(1)
        {
            int x, y;
            x = 1 + rand() % n;
            y = 1 + rand() % n;
            if(pl[x][y] ==0 || pl[x][y] == turn)
            {
                p.first = x;
                p.second = y;
                rflag=1;
                break;
            }
        }
    }*/
    return p;
}
int temppl[n+1][n+1],tempamt[n+1][n+1];
int chain::minimax(int pl[n+1][n+1], int amt[n+1][n+1], int turn, int depth)
{	
	//cout<<"in minimax()"<<endl;

	int result = win(pl, amt,depth);
	//cout<< "wineval "<<result<<endl; 
	if(result!=0)
	{
		//return 0;
		//print_board();
		return evaluatescore(pl,amt,turn, depth);
	}
	if(depth>=maxd)
	{
		return evaluatescore(pl,amt, turn,depth);
	} 
	//cout<<"depth = "<<depth<<endl;
	int maxscore = INT_MIN, minscore = INT_MAX;

   	for(int i=1; i<=n; i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		if(pl[i][j] == turn || pl[i][j] == 0)
    		{
    			int flag = 0;
    			if(pl[i][j] == 0) flag=1; // emtpy cell
    			pl[i][j] = turn; amt[i][j]++;
    			for(int k=1;k<=n;k++)
    			{
    				for(int l=1;l<=n;l++)
    				{
    					temppl[k][l] = pl[k][l];
    					tempamt[k][l] = amt[k][l];
    				}
    			}
    			// make the move and then pass copy of the final board
    			if(amt[i][j] >=surct[i][j]) reaction(temppl,tempamt,i,j,turn);
    			//cout<<i<<" "<<j<< " "<<turn<<" "<<"reaction\n";
    			int tempscore = minimax(temppl,tempamt,turn*(-1), depth+1);                   
    			//cout<<i<<" "<<j<< " "<<turn <<" "<<"after minimax in minimax\n";
    			if(tempscore > maxscore)
    			{
    				maxscore = tempscore; 
    				//p.first = i; p.second = j;
    			}
    			if(tempscore<minscore)	minscore = tempscore;
    			if(flag==1) 
    			{
    				pl[i][j] = 0; amt[i][j] = 0;
    			}
    			else amt[i][j]--;
    		}
    	}
    }
	if(turn == you) return minscore;
	else return maxscore;
}

int chain::win(int pl[n+1][n+1], int amt[n+1][n+1], int depth)
{
	int mect=0, youct=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(pl[i][j] == you) youct+= amt[i][j];
			else if(pl[i][j] == me) mect+= amt[i][j];
		}
	}
	if(mect+youct>2)
	{	
		if(mect == 0) return you;
		else if(youct==0) return me;
		else return 0; 
	}
	else return 0;
}

int chain::evaluatescore(int pl[n+1][n+1], int amt[n+1][n+1], int turn,int depth)
{
	int result = win(pl, amt,depth), score=0;
	int mect=0, youct=0;
	int me3=0,me2=0,me1=0,u1=0,u2=0,u3=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(pl[i][j] == you) 
			{
				//if(amt[i][j] == surct[i][j]-1) youct++;
				youct+= amt[i][j];
				/*if(i-1>0) if(amt[i-1][j] == surct[i-1][j]-1 && pl[i-1][j]==me) if(turn == you) youct++;
				if(i+1<=n) if(amt[i+1][j] == surct[i+1][j]-1 && pl[i-1][j]==me) if(turn == you) youct++;
				if(j-1>0) if(amt[i][j-1] == surct[i][j-1]-1 && pl[i-1][j]==me) if(turn == you) youct++;
				if(j+1<=n) if(amt[i][j+1] == surct[i][j+1]-1 && pl[i-1][j]==me) if(turn == you) youct++;
	*/			if(amt[i][j] == 3) u3++;
				else if(amt[i][j]==2) u2++;
				else if(amt[i][j]==1) u1++;
			}
			else if(pl[i][j] == me) 
			{
				//if(amt[i][j] == surct[i][j]-1) mect++;
				mect+= amt[i][j];
	/*			if(i-1>0) if(amt[i-1][j] == surct[i-1][j]-1 && pl[i-1][j]==you) if(turn == me) mect++;
				if(i+1<=n) if(amt[i+1][j] == surct[i+1][j]-1 && pl[i+1][j]==you) if(turn == me) mect++;
				if(j-1>0) if(amt[i][j-1] == surct[i][j-1]-1 && pl[i][j-1]==you) if(turn == me) mect++;
				if(j+1<=n) if(amt[i][j+1] == surct[i][j+1]-1 && pl[i][j+1]==you) if(turn == me) mect++;
	*/			
				if(amt[i][j] == 3) me3++;
				else if(amt[i][j]==2) me2++;
				else if(amt[i][j]==1) me1++;
			}
		}
	}

	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int ct=0;
			if(pl[i][j] == me && amt[i][j]>0)
			{
				if(i-1>0)
				{
					if(amt[i-1][j] == surct[i-1][j]-1 && pl[i-1][j]==you)	score-= (5-surct[i-1][j]), ct++;;

				} 
				if(i+1<=n) if(amt[i+1][j] == surct[i+1][j]-1 && pl[i+1][j]==you) score-= (5-surct[i+1][j]),ct++;
				if(j-1>0) if(amt[i][j-1] == surct[i][j-1]-1 && pl[i][j-1]==you) score-= (5-surct[i][j-1]),ct++;
				if(j+1<=n) if(amt[i][j+1] == surct[i][j+1]-1 && pl[i][j+1]==you) score-= (5-surct[i][j+1]),ct++;
			}
			else if(pl[i][j] == you && amt[i][j]>0)
			{
				if(i-1>0) if(amt[i-1][j] == surct[i-1][j]-1 && pl[i-1][j]==me) score-= (5-surct[i-1][j]),ct++;
				if(i+1<=n) if(amt[i+1][j] == surct[i+1][j]-1 && pl[i+1][j]==me) score-= (5-surct[i+1][j]),ct++;
				if(j-1>0) if(amt[i][j-1] == surct[i][j-1]-1 && pl[i][j-1]==me) score-= (5-surct[i][j-1]),ct++;
				if(j+1<=n) if(amt[i][j+1] == surct[i][j+1]-1 && pl[i][j+1]==me) score-= (5-surct[i][j+1]),ct++;
			
			}
			if(ct == 0) 
			{
				if(surct[i][j] == 2) score+=3;
				else if(surct[i][j]==3) score+=2;
				if(amt[i][j] == surct[i][j]-1) score+=2;
			}
		}
	}*/

	int score2;
	if(result == me) score = 10000;
	else if(result == you) score = -10000;
	else 
	{
		int th=100,tw=50,oo=1;
		int mes = me3+ tw*me2+ th*me1;
		int us = th*u3+ tw*u2+u1;
		//score = (mes + us);
		//if(turn == me) score = mect;
		//else score = youct;
		//if(turn == me) score+= mect;
		//else score-= youct;
		score = mect- youct;		
	}
	return score;
}

int main()
{
	// human - denotes human number  - 1 
	// bot - denotes bot number - -1
    srand(time(NULL));
	chain ch;
    pair <int, int> move;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		if(i-1>0) surct[i][j]++;
    		if(i+1<=n) surct[i][j]++;
    		if(j-1>0) surct[i][j]++;
    		if(j+1<=n) surct[i][j]++;
    	}
    }
    string in;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		ch.pl[i][j]=0; ch.amt[i][j]=0;
    		cin>>in;
    		ch.pl[i][j] = in[0]-'0';
    		ch.amt[i][j] = in[1]-'0';
    		if(ch.pl[i][j] == 2) ch.pl[i][j] =-1;
    		more2+= ch.amt[i][j];
    	}
    }
    int turn;
	//cout<<"Your turn(1 or 2): "; 
	cin>>me;
	if(me == 1) you=-1, turn = me;
	else you = 1, me=-1, turn = you;
	turn = me;
	// 1- red , and 2- -1 - blue
	
	//ch.print_board();
	int xi, yj;
	maxd = 4;
	/*while(1)
	{
		cout<<"enter"<<endl;
		move = ch.movegen(turn);
		cerr<< "movegenerated\n";
		xi = move.first; yj = move.second;
		cout<<xi<< " " << yj<<endl;
		ch.pl[xi][yj] = turn; ch.amt[xi][yj]++;
		reaction(ch.pl, ch.amt, xi,yj, turn);
		turn *=-1;
		ch.print_board();
		int v;
		cout<<"enter v"; cin>>v;

	}*/

	move = ch.movegen(turn);
	xi = move.first; yj = move.second;	
	xi --; yj--;
	cout<<xi<< " " << yj<<endl;
	cout<<rflag<<endl;
	if(rflag==0) cout<<sc[xi][yj]<<endl;
	for(int i=0;i<n;i++)
	{

		for(int j=0;j<n;j++)
		{
			//cout<<i<<" "<<j<<"= "<<sc[i][j]<<endl;
		}
	}
	return 0;
}
