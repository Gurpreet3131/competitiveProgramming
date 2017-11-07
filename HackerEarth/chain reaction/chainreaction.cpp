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

void reaction(int temppl[n+1][n+1], int tempamt[n+1][n+1], int i, int j, int who)
{
	int amtleft = tempamt[i][j]%surct[i][j], pass = tempamt[i][j]/surct[i][j];
	tempamt[i][j] = amtleft; if(amtleft == 0) temppl[i][j] =0;
	int up = i-1, down = i+1, left = j-1, right = j+1;
	int mect=0, youct=0;
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=n;y++)
		{
			if(temppl[x][y] == you) 
			{
				youct+= tempamt[x][y];
			}
			else if(temppl[x][y] == me) 
			{
				mect+= tempamt[x][y];
			}
		}
	}
	if(youct==0 || mect==0) return;
	if(pass>0)
	{
		if(up>0) temppl[up][j] = who, tempamt[up][j]+=pass;
		if(down<=n) temppl[down][j] = who; tempamt[down][j]+= pass;
   		if(left>0) temppl[i][left] = who; tempamt[i][left]+= pass;
   		if(right<=n) temppl[i][right] = who; tempamt[i][right]+= pass;
   		// now use recursion for chain reaction
   		if(up>0) reaction(temppl,tempamt,up,j,who);
   		if(down<=n) reaction(temppl,tempamt,down,j,who);
   		if(left>0) reaction(temppl,tempamt,i,left,who);
   		if(right<=n) reaction(temppl,tempamt,i,right,who);
	}
}
void print_temp(int temppl[n+1][n+1], int tempamt[n+1][n+1])
{
	cout<<"TEMP BOARD: \n\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(temppl[i][j] == 1 || temppl[i][j]==0) printf("%d",temppl[i][j]);
			else printf("2");
			printf("%d ",tempamt[i][j]);
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
    			else if(amt[i][j]>0) amt[i][j]--;
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
//int ff =0;
int ff =0;

int chain::minimax(int temppl[n+1][n+1], int tempamt[n+1][n+1], int turn, int depth)
{	
	//cout<<"in minimax()"<<endl;

	int result = win(temppl, tempamt,depth);
	//cout<< "wineval "<<result<<endl; 
	if(result!=0)
	{
		//return 0;
		//print_board();
		//ff++;
		int sc = evaluatescore(temppl,tempamt,turn, depth);
		return sc;
	}
	if(depth>=maxd)
	{
		return evaluatescore(temppl,tempamt, turn,depth);
	} 
	//cout<<"depth = "<<depth<<endl;
	int maxscore = INT_MIN, minscore = INT_MAX;
	int tpl[6][6], tamt[6][6];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			tpl[i][j] = temppl[i][j];
			tamt[i][j] = tempamt[i][j];
		}
	}
   	for(int i=1; i<=n; i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		if(tpl[i][j] == turn || tpl[i][j] == 0)
    		{
    			int flag = 0;
    			if(tpl[i][j] == 0) flag=1; // emtpy cell
    			
    			/*if(ff == 0 || ff == 1)
    			{
    				cout<<" move == "<<i<<" "<<j<<endl;
    				cout<<"before move = "<<endl;
    				print_temp(tpl,tamt);
    				cout<<"print temp= \n";
    				print_temp(temppl,tempamt);
    			}*/
    			tpl[i][j] = turn; tamt[i][j]++;
    			for(int k=1;k<=n;k++)
    			{
    				for(int l=1;l<=n;l++)
    				{
    					temppl[k][l] = tpl[k][l];
    					tempamt[k][l] = tamt[k][l];
    				}
    			}
    			/*if(ff == 0 || ff ==1)
    			{
    				cout<<"after move = "<<endl;
					print_temp(tpl,tamt);
    				cout<<"print temp= \n";
    				print_temp(temppl,tempamt);
    			}*/
    			// make the move and then pass copy of the final board
    			if(tempamt[i][j] >=surct[i][j]) reaction(temppl,tempamt,i,j,turn);
    			//cout<<i<<" "<<j<< " "<<turn<<" "<<"reaction\n";
    			/*if(ff == 0 || ff == 1)
    			{
    				cout<<"after reaction = "<<endl;
    				print_temp(tpl,tamt);
    				cout<<"print temp= \n";
    				print_temp(temppl,tempamt);
    				ff++;
    			}*/
    			int tempscore = minimax(temppl,tempamt,turn*(-1), depth+1);                   
    			//cout<<i<<" "<<j<< " "<<turn <<" "<<"after minimax in minimax\n";
    			/*if(ff == 2)
    			{
    				cout<<"after minimax = "<<endl;
    				print_temp(tpl,tamt);
    				cout<<"print temp= \n";
    				print_temp(temppl,tempamt);
    				ff++;
    			}
    			*/
    			if(tempscore > maxscore)
    			{
    				maxscore = tempscore; 
    				//p.first = i; p.second = j;
    			}
    			if(tempscore<minscore)	minscore = tempscore;
    			if(flag==1) 
    			{
    				tpl[i][j] = 0; tamt[i][j] = 0;
    			}
    			else if(tamt[i][j]>0) tamt[i][j]--;
    		}
    	}
    }
	if(turn == you) return minscore;
	else return maxscore;
}

int chain::win(int temppl[n+1][n+1], int tempamt[n+1][n+1], int depth)
{
	int mect=0, youct=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(temppl[i][j] == you) youct+= tempamt[i][j];
			else if(temppl[i][j] == me) mect+= tempamt[i][j];
		}
	}
	//if(ff == 0) cout<<"count = "<<mect<<" "<<youct<<endl, print_temp(temppl,tempamt);
	if(mect+youct>2)
	{	
		if(mect == 0) return you;
		else if(youct==0) return me;
		else return 0; 
	}
	else return 0;
}
int cont(int temppl[n+1][n+1],int tempamt[n+1][n+1], int turn)
{
	int co=0;
	for(int i=1;i<=n;i++)
	{
		int ct=0;
		for(int j=1;j<=n;j++)
		{
			if(temppl[i][j] == turn && tempamt[i][j] == surct[i][j]-1) ct++;
//			else if(temppl[i][j] == -turn && tempamt[i][j] == surct[i][j]-1) ct--;
			else
			{
				co+=ct; ct=0;
			}
		}
	}
	for(int j=1;j<=n;j++)
	{
		int ct=0;
		for(int i=1;i<=n;i++)
		{
			if(temppl[i][j] == turn && tempamt[i][j] == surct[i][j]-1) ct++;
//			else if(temppl[i][j] == -turn && tempamt[i][j] == surct[i][j]-1) ct--;
			else
			{	
				co+=ct; ct=0;
			}
		}
		
	}
	return 2*co;
}
int chain::evaluatescore(int temppl[n+1][n+1], int tempamt[n+1][n+1], int turn,int depth)
{
	int result = win(temppl, tempamt,depth), score=0;
	int mect=0, youct=0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int ct=0;
			
			if(temppl[i][j] == me && tempamt[i][j]>0)
			{

				mect+= tempamt[i][j];
				if(i-1>0) if(tempamt[i-1][j] == surct[i-1][j]-1 && temppl[i-1][j]==you)	mect-= (5-surct[i-1][j]), ct++;
				if(i+1<=n) if(tempamt[i+1][j] == surct[i+1][j]-1 && temppl[i+1][j]==you) mect-= (5-surct[i+1][j]), ct++;
				if(j-1>0) if(tempamt[i][j-1] == surct[i][j-1]-1 && temppl[i][j-1]==you) mect-= (5-surct[i][j-1]), ct++;
				if(j+1<=n) if(tempamt[i][j+1] == surct[i][j+1]-1 && temppl[i][j+1]==you) mect-= (5-surct[i][j+1]), ct++;
				if(ct == 0) 
				{	
					if(surct[i][j] == 2) mect+=3;
					else if(surct[i][j]==3) mect+=2;
					if(tempamt[i][j] == surct[i][j]-1) mect+=2;
				}
			}
			else if(temppl[i][j] == you && tempamt[i][j]>0)
			{
				youct+=tempamt[i][j];
				if(i-1>0) if(tempamt[i-1][j] == surct[i-1][j]-1 && temppl[i-1][j]==me) youct-= (5-surct[i-1][j]),ct++;
				if(i+1<=n) if(tempamt[i+1][j] == surct[i+1][j]-1 && temppl[i+1][j]==me) youct-= (5-surct[i+1][j]),ct++;
				if(j-1>0) if(tempamt[i][j-1] == surct[i][j-1]-1 && temppl[i][j-1]==me) youct-=(5-surct[i][j-1]),ct++;
				if(j+1<=n) if(tempamt[i][j+1] == surct[i][j+1]-1 && temppl[i][j+1]==me) youct-= (5-surct[i][j+1]),ct++;
				if(ct == 0) 
				{
					if(surct[i][j] == 2) youct+=3;
					else if(surct[i][j]==3) youct+=2;
					if(tempamt[i][j] == surct[i][j]-1) youct+=2;
				}
			}
		}
	}
	mect+= cont(temppl,tempamt,me);
	//youct+= cont(temppl,tempamt,you);
	if(result == me) score = 10000;
	else if(result == you) score = -10000;
	else 
	{
		score = mect;	
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
	maxd =4;
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
			cout<<sc[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
