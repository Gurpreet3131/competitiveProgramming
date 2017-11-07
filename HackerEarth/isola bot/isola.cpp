#include <bits/stdc++.h>
using namespace std;
const int n = 6;
int me,you,maxd=1; 
int rflag=0, cxct=0;
int sur[7][7]={0};
struct isola
{
    int board[n+1][n+1];
	void print_board();
    void movegen(int turn);
	int minimax(int board[n+1][n+1],int turn, int depth, int alpha, int beta);	// minimax(board,turn,depth)
	int win(int board[n+1][n+1], int turn, int depth); // win(board)
	int evaluatescore(int board[n+1][n+1],int turn, int depth); // evalutescore(board,depth)
	int calcadj(int board[n+1][n+1], int turn, int pi,int pj);
};

void isola::print_board()
{
	cout<<"BOARD: \n\n";
	cout<<"  ";
	for(int i=0;i<=n;i++) cout<<i<<" ";
	cout<<endl;
	for(int i=0;i<=n;i++)
	{
		cout<<i<<" ";
		for(int j=0;j<=n;j++)
		{
			if(board[i][j] == 1) printf("1 ");
			else if(board[i][j] == -1) printf("2 ");
			else if(board[i][j] == -2) printf("X ");
			else printf("0 ");			
		}
		cout<<endl;
	}
}
/*void pt(int board[n+1][n+1])
{
	cout<<"pt BOARD: \n\n";
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}*/
pair<int,int> p;
pair<int,int> cross;
int mx=0,mn=0;
void isola::movegen(int turn)
{
	//print_board();
	//pt(board);
    int maxscore = INT_MIN, minscore = INT_MAX;
    vector< pair< int, int > > moves, cx;
    int pi=-1,pj=-1, found=0, ui,uj, fl=0;
    for(int i=0; i<=n; i++)
    {
    	for(int j=0;j<=n;j++)
    	{
			if(board[i][j] == turn) pi=i, pj=j;
			if(board[i][j] == -turn) ui=i,uj=j;
			if(fl==0 && board[i][j] == 0 && cxct>5)
			{
				fl=1; cx.push_back(make_pair(i,j));
			}
    	}
    }
    //cout<<pi<<" "<<pj<<endl;
    if(pi-1>=0 && pj-1>=0) // up-left 
    	if(board[pi-1][pj-1]==0) moves.push_back(make_pair(pi-1,pj-1)); 
    if(pi-1>=0 && pj>=0) // up 
    	if(board[pi-1][pj]==0) moves.push_back(make_pair(pi-1,pj)); 
    if(pi-1>=0 && pj+1<=n) // up-right 
    	if(board[pi-1][pj+1]==0) moves.push_back(make_pair(pi-1,pj+1)); 
    if(pi>=0 && pj-1>=0) // left 
    	if(board[pi][pj-1]==0) moves.push_back(make_pair(pi,pj-1)); 
    if(pi>=0 && pj+1<=n) // right 
    	if(board[pi][pj+1]==0) moves.push_back(make_pair(pi,pj+1)); 
    if(pi+1<=n && pj-1>=0) // down-left 
    	if(board[pi+1][pj-1]==0) moves.push_back(make_pair(pi+1,pj-1)); 
    if(pi+1<=n && pj>=0) // down 
    	if(board[pi+1][pj]==0) moves.push_back(make_pair(pi+1,pj)); 
    if(pi+1<=n && pj+1<=n) // down-right 
    	if(board[pi+1][pj+1]==0) moves.push_back(make_pair(pi+1,pj+1));

    int val = -2;
    if(ui-1>=0 && uj-1>=0) // up-left 
    	if(board[ui-1][uj-1]!=val) cx.push_back(make_pair(ui-1,uj-1)); 
    if(ui-1>=0 && uj>=0) // up 
    	if(board[ui-1][uj]!=val) cx.push_back(make_pair(ui-1,uj)); 
    if(ui-1>=0 && uj+1<=n) // up-right 
    	if(board[ui-1][uj+1]!=val) cx.push_back(make_pair(ui-1,uj+1)); 
    if(ui>=0 && uj-1>=0) // left 
    	if(board[ui][uj-1]!=val) cx.push_back(make_pair(ui,uj-1)); 
    if(ui>=0 && uj+1<=n) // right 
    	if(board[ui][uj+1]!=val) cx.push_back(make_pair(ui,uj+1)); 
    if(ui+1<=n && uj-1>=0) // down-left 
    	if(board[ui+1][uj-1]!=val) cx.push_back(make_pair(ui+1,uj-1)); 
    if(ui+1<=n && uj>=0) // down 
    	if(board[ui+1][uj]!=val) cx.push_back(make_pair(ui+1,uj)); 
    if(ui+1<=n && uj+1<=n) // down-right 
    	if(board[ui+1][uj+1]!=val) cx.push_back(make_pair(ui+1,uj+1));

   	cx.push_back(make_pair(pi,pj));
   // cout<<"maxscore = " << maxscore<<endl;
    for(int m=0;m<moves.size();m++)
    {
    //	cout<<"maxscore = " << maxscore<<endl;
    	int ii = moves[m].first, jj = moves[m].second;
		board[ii][jj] = turn; board[pi][pj] = 0;
		for(int cc = 0; cc< cx.size(); cc++)
		{
			int i = cx[cc].first, j = cx[cc].second;
			if(board[i][j] == 0)
			{
			//	cout<<"try move= "<<ii<<" "<<jj<<" "<<i<<" "<<j<<endl;
				board[i][j] = -2;
			//	cout<<"before\n"; print_board();
				int tempscore = minimax(board, -turn, 1, INT_MIN, INT_MAX);		
				if(tempscore > maxscore)
    			{
    				maxscore = tempscore; p.first = ii; p.second = jj;
    				cross.first =i; cross.second = j;
	    		}
	    		else if(tempscore == maxscore)
	    		{
	    			if(sur[i][j]>sur[cross.first][cross.second])
	    			{
	    				p.first = ii; p.second = jj;
	    				cross.first = i; 
	    				cross.second = j;
	    			}
	    		}
				if(tempscore<minscore)	minscore = tempscore;		
			//	cout<<"after\n"; print_board();
				board[i][j] = 0;
				//cerr<<"move = "<<ii<<" "<<jj<<" ";
				//cout<<i<<" "<<j<<"  scire= "<<tempscore<<endl;
				//cout<<"##############################\n";
				//cout<<maxscore<<endl;
			}
		}

		/*for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(board[i][j] == 0)
				{
					//cout<<ii<<" "<<jj<<" "<<i<<" "<<j<<endl;
					board[i][j] = -2;
					int tempscore = minimax(board, -turn, 1);		
					if(tempscore > maxscore)
    				{
    					maxscore = tempscore; p.first = ii; p.second = jj;
    					cross.first =i; cross.second = j;
	    			}
					if(tempscore<minscore)	minscore = tempscore;		
					board[i][j] = 0;
					cerr<<"score = "<<ii<<" "<<jj<<" "<<endl;
					cout<<i<<" "<<j<<" "<<tempscore<<endl;
					//cout<<maxscore<<endl;
				}
			}
		}*/
		board[ii][jj] = 0; board[pi][pj] = turn;    	
		
    }
    mx = maxscore;  mn = minscore;
    //cout<<"mx = "<<maxscore<<endl;
    /*if(maxscore == minscore)
    {
        int ran = rand()%(moves.size());
        rflag = 1; p.first = moves[ran].first; p.second = moves[ran].second; 
    }*/
}
int ff=0;
int isola::minimax(int board[n+1][n+1], int turn, int depth,int alpha, int beta)
{	
	//cerr<<"IN MINImax\n";
	int result = win(board, turn, depth);
	if(result!=0)
	{
		//cerr<<"some one won\n";
		// print_board(); 
		int score = evaluatescore(board,turn, depth);
		return score;
	}
	if(depth>=maxd)
	{
		//print_board();
		//cerr<<"maxd reached=\n"; 
		//print_board();
		int score = evaluatescore(board,turn,depth);
		if(ff==0)
		{
			//print_board();
			//cout<<score<<endl;
			ff++;
		}
		return score;
	} 
	//cout<<"depth = "<<depth<<endl;
	int maxscore = INT_MIN, minscore = INT_MAX;
	vector< pair< int, int > > moves, cx;
    int pi=-1,pj=-1, found=0, ui,uj,fl=0;
    for(int i=0; i<=n; i++)
    {
    	for(int j=0;j<=n;j++)
    	{
			if(board[i][j] == turn) pi=i, pj=j;
			if(board[i][j] == -turn) ui=i,uj=j;
    		if(fl==0 && board[i][j] == 0 && cxct>5)
			{
				fl=1; cx.push_back(make_pair(i,j));
			}
    	}
    }
    //cout<<pi<<" "<<pj<<endl;
    if(pi-1>=0 && pj-1>=0) // up-left 
    	if(board[pi-1][pj-1]==0) moves.push_back(make_pair(pi-1,pj-1)); 
    if(pi-1>=0 && pj>=0) // up 
    	if(board[pi-1][pj]==0) moves.push_back(make_pair(pi-1,pj)); 
    if(pi-1>=0 && pj+1<=n) // up-right 
    	if(board[pi-1][pj+1]==0) moves.push_back(make_pair(pi-1,pj+1)); 
    if(pi>=0 && pj-1>=0) // left 
    	if(board[pi][pj-1]==0) moves.push_back(make_pair(pi,pj-1)); 
    if(pi>=0 && pj+1<=n) // right 
    	if(board[pi][pj+1]==0) moves.push_back(make_pair(pi,pj+1)); 
    if(pi+1<=n && pj-1>=0) // down-left 
    	if(board[pi+1][pj-1]==0) moves.push_back(make_pair(pi+1,pj-1)); 
    if(pi+1<=n && pj>=0) // down 
    	if(board[pi+1][pj]==0) moves.push_back(make_pair(pi+1,pj)); 
    if(pi+1<=n && pj+1<=n) // down-right 
    	if(board[pi+1][pj+1]==0) moves.push_back(make_pair(pi+1,pj+1));

    int val = -2;
    if(ui-1>=0 && uj-1>=0) // up-left 
    	if(board[ui-1][uj-1]!=val) cx.push_back(make_pair(ui-1,uj-1)); 
    if(ui-1>=0 && uj>=0) // up 
    	if(board[ui-1][uj]!=val) cx.push_back(make_pair(ui-1,uj)); 
    if(ui-1>=0 && uj+1<=n) // up-right 
    	if(board[ui-1][uj+1]!=val) cx.push_back(make_pair(ui-1,uj+1)); 
    if(ui>=0 && uj-1>=0) // left 
    	if(board[ui][uj-1]!=val) cx.push_back(make_pair(ui,uj-1)); 
    if(ui>=0 && uj+1<=n) // right 
    	if(board[ui][uj+1]!=val) cx.push_back(make_pair(ui,uj+1)); 
    if(ui+1<=n && uj-1>=0) // down-left 
    	if(board[ui+1][uj-1]!=val) cx.push_back(make_pair(ui+1,uj-1)); 
    if(ui+1<=n && uj>=0) // down 
    	if(board[ui+1][uj]!=val) cx.push_back(make_pair(ui+1,uj)); 
    if(ui+1<=n && uj+1<=n) // down-right 
    	if(board[ui+1][uj+1]!=val) cx.push_back(make_pair(ui+1,uj+1));

   	cx.push_back(make_pair(pi,pj));
   // cout<<"maxscore = " << maxscore<<endl;
    //cout<<"sizes= "<<moves.size()<<" "<<cx.size()<<endl;
    int score; 
    if(turn == me) score = INT_MIN;
    else score = INT_MAX;
    for(int m=0;m<moves.size();m++)
    {
    	//cout<<"maxscore = " << maxscore<<endl;
    	int ii = moves[m].first, jj = moves[m].second;
		board[ii][jj] = turn; board[pi][pj] = 0;
		for(int cc = 0; cc< cx.size(); cc++)
		{
			int i = cx[cc].first, j = cx[cc].second;
			if(board[i][j] == 0)
			{
				//cout<<"mini try move"<<ii<<" "<<jj<<" "<<i<<" "<<j<<endl;
				//cout<<"depth= "<<depth<<endl;
				//cout<<"turn = "<<turn<<endl; 

				board[i][j] = -2;
				if(ff == 0) 
				{
					//cout<<"mini try board\n";						
					//print_board();
				}
				//print_board();
				int tempscore = minimax(board, -turn, depth+1, alpha, beta);		
				if(tempscore > maxscore) maxscore = tempscore;
				if(tempscore<minscore) minscore = tempscore;		
				if(turn == me) score = max(score,tempscore);
				else score = min(score,tempscore);
				
				//cout<<"mini try after board\n";
				//print_board();
				board[i][j] = 0;
				//cout<<"last turn = "<<turn<<endl;
				//cerr<<"mini move = "<<ii<<" "<<jj<<" ";
				//cout<<i<<" "<<j<<" score= "<<tempscore<<endl;
				//cout<<maxscore<<endl;
				//cout<<"depth= "<<depth<<endl;
				//if(depth == 1)   cout<<"	score= "<<tempscore<<endl;
				//if(depth == 2)   cout<<"		score= "<<tempscore<<endl;
				//if(depth == 3)   cout<<"			score= "<<tempscore<<endl;
				//if(depth == 4)   cout<<"				score= "<<tempscore<<endl;
				if(beta <= alpha) break;
			}
			
		}

		/*for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(board[i][j] == 0)
				{
					//cout<<ii<<" "<<jj<<" "<<i<<" "<<j<<endl;
					board[i][j] = -2;
					int tempscore = minimax(board, -turn, 1);		
					if(tempscore > maxscore)
    				{
    					maxscore = tempscore; p.first = ii; p.second = jj;
    					cross.first =i; cross.second = j;
	    			}
					if(tempscore<minscore)	minscore = tempscore;		
					board[i][j] = 0;
					cerr<<"score = "<<ii<<" "<<jj<<" "<<endl;
					cout<<i<<" "<<j<<" "<<tempscore<<endl;
					//cout<<maxscore<<endl;
				}
			}
		}*/
		board[ii][jj] = 0; board[pi][pj] = turn;
		if(beta<=alpha) break;    	
		
    }
    //out<<"coming out\n";
    return score;
	//if(turn == you) return minscore;
	//else return maxscore;
}

int isola::win(int board[n+1][n+1], int turn, int depth)
{
	int pi,pj,found=0, mpos=0;
    for(int i=0; i<=n; i++)
    {
    	for(int j=0;j<=n;j++)
    	{
			if(board[i][j] == turn)
			{
				pi=i; pj=j; found=1; break;	
			}    		
    	}
    	if(found == 1) break;
    }
    if(pi-1>=0 && pj-1>=0) // up-left 
    	if(board[pi-1][pj-1]==0)  mpos++;
    if(pi-1>=0 && pj>=0) // up 
    	if(board[pi-1][pj]==0) mpos++;
    if(pi-1>=0 && pj+1<=n) // up-right 
    	if(board[pi-1][pj+1]==0) mpos++;
    if(pi>=0 && pj-1>=0) // left 
    	if(board[pi][pj-1]==0) mpos++;
    if(pi>=0 && pj+1<=n) // right 
    	if(board[pi][pj+1]==0) mpos++;
    if(pi+1<=n && pj-1>=0) // down-left 
    	if(board[pi+1][pj-1]==0) mpos++;
    if(pi+1<=n && pj>=0) // down 
    	if(board[pi+1][pj]==0) mpos++;
    if(pi+1<=n && pj+1<=n) // down-right 
    	if(board[pi+1][pj+1]==0) mpos++;

    if(mpos == 0) return -turn;
    else return 0;
    //if(mpos == 0 && turn == me) return you;
	//else if(mpos == 0 && turn == you) return me;
	//else return 0;
}
int isola::calcadj(int board[n+1][n+1], int turn,int pi,int pj)
{
	int ct=0;
    if(pi-1>=0 && pj-1>=0)
    	if(board[pi-1][pj-1] == 0) ct+= sur[pi-1][pj-1];
	if(pi-1>=0) 
		if(board[pi-1][pj] == 0) ct+= sur[pi-1][pj];
	if(pi-1>=0 && pj+1<=n) 
		if(board[pi-1][pj+1] == 0) ct+= sur[pi-1][pj+1];
	if(pj-1>=0) 
		if(board[pi][pj-1] == 0) ct+= sur[pi][pj-1];
	if(pj+1<=n) 
		if(board[pi][pj+1] == 0) ct+= sur[pi][pj+1];
	if(pi+1<=n && pj-1>=0) 
		if(board[pi+1][pj-1] == 0) ct+= sur[pi][pj-1];
	if(pi+1<=n)
		if(board[pi+1][pj] == 0) ct+= sur[pi+1][pj];
	if(pi+1<=n && pj+1<=n) 
		if(board[pi+1][pj+1] == 0) ct+= sur[pi+1][pj+1];  

	return ct;
}
int isola::evaluatescore(int board[n+1][n+1], int turn,int depth)
{
	int result = win(board,turn, depth), score=0, mul = maxd - depth+1;
	int mesc=0, usc=0;
	if(result == me) return 10000*mul;
	else if(result == you) return -10000*mul;
	else 
	{
		int pi,pj,ui,uj,found=0;
		for(int i=0; i<=n; i++)
    	{
    		for(int j=0;j<=n;j++)
	    	{
				if(board[i][j] == me)	pi=i, pj=j;
				else if(board[i][j] == -turn) ui=i,uj=j; 		
    		}
	    }
		mesc+= calcadj(board,me,pi,pj);
		usc+= calcadj(board,you,ui,uj);

		if(cxct<2 || cxct>5)
    	{
		if(pi-1>=0 && pj-1>=0) // up-left 
	    	if(board[pi-1][pj-1]==0) mesc+=calcadj(board,me,pi-1,pj-1); 
    	if(pi-1>=0 && pj>=0) // up 
    		if(board[pi-1][pj]==0) mesc+=calcadj(board,me,pi-1,pj); 
	    if(pi-1>=0 && pj+1<=n) // up-right 
    		if(board[pi-1][pj+1]==0) mesc+=calcadj(board,me,pi-1,pj+1); 
	    if(pi>=0 && pj-1>=0) // left 
    		if(board[pi][pj-1]==0) mesc+=calcadj(board,me,pi,pj-1); 
	    if(pi>=0 && pj+1<=n) // right 
    		if(board[pi][pj+1]==0) mesc+=calcadj(board,me,pi,pj+1); 
	    if(pi+1<=n && pj-1>=0) // down-left 
    		if(board[pi+1][pj-1]==0) mesc+=calcadj(board,me,pi+1,pj-1); 
	    if(pi+1<=n && pj>=0) // down 
    		if(board[pi+1][pj]==0) mesc+=calcadj(board,me,pi+1,pj); 
	    if(pi+1<=n && pj+1<=n) // down-right 
    		if(board[pi+1][pj+1]==0) mesc+=calcadj(board,me,pi+1,pj+1);

    	
    		if(ui-1>=0 && uj-1>=0) // up-left 
    		if(board[ui-1][uj-1]==0) usc+=calcadj(board,you,ui-1,uj-1); 
    	if(ui-1>=0 && uj>=0) // up 
    		if(board[ui-1][uj]==0) usc+=calcadj(board,you,ui-1,uj); 
    	if(ui-1>=0 && uj+1<=n) // up-right 
    		if(board[ui-1][uj+1]==0) usc+=calcadj(board,you,ui-1,uj+1); 
    	if(ui>=0 && uj-1>=0) // left 
    		if(board[ui][uj-1]==0) usc+=calcadj(board,you,ui,uj-1); 
    	if(ui>=0 && uj+1<=n) // right 
    		if(board[ui][uj+1]==0) usc+=calcadj(board,you,ui,uj+1); 
    	if(ui+1<=n && uj-1>=0) // down-left 
    		if(board[ui+1][uj-1]==0) usc+=calcadj(board,you,ui+1,uj-1); 
    	if(ui+1<=n && uj>=0) // down 
    		if(board[ui+1][uj]==0) usc+=calcadj(board,you,ui+1,uj); 
    	if(ui+1<=n && uj+1<=n) // down-right 
    		if(board[ui+1][uj+1]==0) usc+=calcadj(board,you,ui+1,uj+1);
		
    	}
	    
		//cout<<"mes = "<<mesc<<"  usc= "<<usc<<endl; 
		score = mesc - usc;
		return score;
	}
}

int main()
{
    srand(time(NULL));
	isola is;
    for(int i=0;i<=n;i++)
    {
    	for(int j=0;j<=n;j++)
    	{
    		scanf("%d",&is.board[i][j]);
			if(is.board[i][j] == 2) is.board[i][j] = -1;
			else if(is.board[i][j] == -1) is.board[i][j] = -2;  
			if(i-1>=0 && j-1>=0) sur[i][j]++;
			if(i-1>=0) sur[i][j]++;
			if(i-1>=0 && j+1<=n) sur[i][j]++;
			if(j-1>=0) sur[i][j]++;
			if(j+1<=n) sur[i][j]++;
			if(i+1<=n && j-1>=0) sur[i][j]++;
			if(i+1<=n) sur[i][j]++;
			if(i+1<=n && j+1<=n) sur[i][j]++;
			if(sur[i][j] == 3) sur[i][j] =10;
			else if(sur[i][j] == 5) sur[i][j] = 20;
			else sur[i][j] = 30;  
			if(is.board[i][j] == -2) cxct++;
    	}
    }
	maxd =4;
    int turn; cin>>me;
	if(me == 1) you=-1, turn = me;
	else you = 1, me=-1, turn = you;
	turn = me;
	//is.print_board();

	/*int xi,yj,ci,cj;
	while(true)
	{
		if(turn == me) 
		{
			is.movegen(turn);
			xi = p.first; yj = p.second; ci = cross.first; cj = cross.second;	
		}
		else 
		{
			cout<<"enter turn = "; cin>>xi>>yj>>ci>>cj;
		}
		cout<<xi<<" "<<yj<<endl;
		cout<<ci<<" "<<cj<<endl; cout<<mx<<" "<<mn<<endl;
		int pi=-1,pj=-1;
	    for(int i=0; i<=n; i++)
    	{
    		for(int j=0;j<=n;j++)
   	 		{
				if(is.board[i][j] == turn) pi=i, pj=j;
    		}
    	}
		is.board[pi][pj] = 0; is.board[xi][yj]=turn;
		is.board[ci][cj] = -2;
		turn*=-1;
		is.print_board();
		int result = is.win(is.board,turn,1);
		if(result !=0)
		{
			cout<<"turn = "<<result<<" won the game.\n";
			break;
		}
	}*/
	
	int xi,yj,ci,cj;
	is.movegen(turn);
	xi = p.first; yj = p.second; ci = cross.first; cj = cross.second;	
	cout<<xi<<" "<<yj<<endl;
	cout<<ci<<" "<<cj<<endl;
//	printf("%d %d\n%d %d\n",xi,yj,ci,cj);
	cout<<" "<<mx<<" "<<mn<<endl;

	return 0;
}
