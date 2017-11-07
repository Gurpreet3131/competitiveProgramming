#include <bits/stdc++.h>
using namespace std;
const int n = 6, m = 7;
int me,you,maxd=2; 
vector< vector< pair <int,int> > > adj(50);
vector< vector <pair <int, int> > > jump(50);
int tried = 0;

struct hx
{
	void print_board(int board[n][m]);
    void movegen(int board[n][m],int turn, int totalmoves);
	int minimax(int board[n][m],int turn,int totalmoves, int depth, int alpha, int beta);	// minimax(board,turn,depth)
	int win(int board[n][m], int turn, int totalmoves, int depth); // win(board)
	int evaluatescore(int board[n][m],int turn,int totalmoves, int depth); // evalutescore(board,depth)
};

void hx::print_board(int board[n][m])
{
	cout<<"BOARD: \n\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(board[i][j] == -1) printf("2 ");
			else printf("%d ",board[i][j]);
		}
		printf("\n");
	}
}
void invertadj(int board[n][m], int turn, int si, int sj)
{
	int ind = si*m+sj;
	for(int i=0;i<adj[ind].size();i++)
	{
		int ai = adj[ind][i].first, aj = adj[ind][i].second;
		if(board[ai][aj] == -turn) board[ai][aj] = turn;
	}
}
int sti,stj,endi,endj;
int mx=0;
void hx::movegen(int board[n][m], int turn, int totalmoves)
{
    int maxscore = INT_MIN, minscore = INT_MAX;
	int tempboard[n][m];
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		if(board[i][j] == turn)
    		{
    			//cout<<"from= "<<i<< " "<<j<<endl;
    			int ind = i*m+j;
   		 		for(int k=0;k<adj[ind].size();k++)
	    		{
    				int si = adj[ind][k].first, sj = adj[ind][k].second;
	    			if(board[si][sj] == 0)
	    			{
	    				for(int ii = 0; ii<n;ii++)
	    				{
    						for(int jj=0;jj<m;jj++)
    						{
		    					tempboard[ii][jj] = board[ii][jj];
    						}
    					}
    					///cout<<"bd\n"; print_board(board);
    					tempboard[si][sj] = turn;
						invertadj(tempboard,turn,si,sj);
						//cout<<"tempbd\n"; print_board(tempboard);
	    				int tempscore = minimax(tempboard,-turn,totalmoves+1,1,INT_MIN,INT_MAX);
	    				if(tempscore > maxscore)
	    				{
	    					maxscore = tempscore; sti = i; stj=j;
	    					endi = si; endj = sj;
	    				}
	    				//cout<< si << " "<<sj<<"  score = "<< tempscore<<endl;
	    				//equality condition pending
	    			}
    			}

	    		for(int k=0;k<jump[ind].size();k++)
    			{
					int si = jump[ind][k].first, sj = jump[ind][k].second;
	    			if(board[si][sj] == 0)
	    			{
	    				for(int ii = 0; ii<n;ii++)
	    				{
    						for(int jj=0;jj<m;jj++)
    						{
		    					tempboard[ii][jj] = board[ii][jj];
    						}
    					}
    					//cout<<"bd\n"; print_board(board);
    					tempboard[i][j] = 0;
    					tempboard[si][sj] = turn;
						invertadj(tempboard,turn,si,sj);

						//cout<<"tempbd\n"; print_board(tempboard);
	    				int tempscore = minimax(tempboard,-turn,totalmoves+1,1,INT_MIN,INT_MAX);
	    				if(tempscore > maxscore)
	    				{
	    					maxscore = tempscore; sti = i; stj=j;
	    					endi = si; endj = sj;
                        }
	    				//cout<< si << " "<<sj<<"  score = "<< tempscore<<endl;

	    				//equality condition pending
	    			
	    			}
    			}	
    		}
    	}
    }		
    mx = maxscore;
}
int hx::minimax(int board[n][m], int turn, int totalmoves, int depth,int alpha, int beta)
{	
	//cerr<< "minimax\n";
	int result = win(board, turn, totalmoves, depth);
	if(result!=0)
	{
		int score = evaluatescore(board,turn,totalmoves, depth);
		return score;
	}
	if(depth>=maxd || totalmoves>=100)
	{
		int score = evaluatescore(board,turn,totalmoves, depth);
		return score;
	} 
	//cout<<"depth = "<<depth<<endl;
	int maxscore = INT_MIN, minscore = INT_MAX;

    int score; 
    if(turn == me) score = INT_MIN;
    else score = INT_MAX;
 	int tempboard[n][m];
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		if(board[i][j] == turn)
    		{
                //for(int h=1;h<=depth;h++)
                {
                //    cout<<"     ";
                }                
    			//cout<<depth<<" from = "<<i<<" "<<j<<endl;
                int ind = i*m+j;
   		 		for(int k=0;k<adj[ind].size();k++)
	    		{
    				int si = adj[ind][k].first, sj = adj[ind][k].second;
	    			if(board[si][sj] == 0)
	    			{
	    				for(int ii = 0; ii<n;ii++)
	    				{
    						for(int jj=0;jj<m;jj++)
    						{
		    					tempboard[ii][jj] = board[ii][jj];
    						}
    					}
    					tempboard[si][sj] = turn;
						invertadj(tempboard,turn,si,sj);
	    				int tempscore = minimax(tempboard,-turn,totalmoves+1,depth+1,alpha,beta);
	    				if(tempscore > maxscore) maxscore = tempscore;
	    				if(tempscore < minscore) minscore = tempscore;
                      //  cout<< si << " "<<sj<<"  score = "<< tempscore<<endl;

	    				if(turn == me) score = max(score,tempscore);
						else score = min(score,tempscore);				
						if(beta <= alpha) break;
	    			}
    			}

	    		for(int k=0;k<jump[ind].size();k++)
    			{
					int si = jump[ind][k].first, sj = jump[ind][k].second;
	    			if(board[si][sj] == 0)
	    			{
	    				for(int ii = 0; ii<n;ii++)
	    				{
    						for(int jj=0;jj<m;jj++)
    						{
		    					tempboard[ii][jj] = board[ii][jj];
    						}
    					}
    					tempboard[i][j] = 0;
    					tempboard[si][sj] = turn;
						invertadj(tempboard,turn,si,sj);
	    				int tempscore = minimax(tempboard,-turn,totalmoves+1,depth+1,alpha,beta);
	    				if(tempscore > maxscore) maxscore = tempscore; 
	    				if(tempscore < minscore) minscore = tempscore;
	    			//	cout<< si << " "<<sj<<"  score = "<< tempscore<<endl;

                        //equality condition pending
	    				if(turn == me) score = max(score,tempscore);
						else score = min(score,tempscore);				
						if(beta <= alpha) break;
	    			}
    			}
    			if(beta <= alpha) break;	
    		}
    		if(beta <= alpha) break;
    	}
    }
    return score;
}

int hx::win(int board[n][m], int turn, int totalmoves, int depth)
{
	int ct = 0, ctme =0, ctyou = 0;
    for(int i=0; i<n; i++)
    {
    	for(int j=0;j<m;j++)
    	{
			if(board[i][j] == -turn) ctyou++;  
			else if(board[i][j] == turn)
			{
				ctme++;
				int ind = i*m+j;
   		 		for(int k=0;k<adj[ind].size();k++)
	    		{
    				int si = adj[ind][k].first, sj = adj[ind][k].second;
    				if(board[si][sj] == 0) ct++;
    			}
	    		for(int k=0;k<jump[ind].size();k++)
    			{
					int si = jump[ind][k].first, sj = jump[ind][k].second;
	    			if(board[si][sj] == 0) ct++;
	    		}
			}    		
    	}
    }
    if(totalmoves>100)
    {
    	if(ctme - ctyou > 0) return turn;
    	else if(ctme- ctyou<0) return -turn;
    	else return 2;
    }
    else if(ct == 0 && ctme<ctyou) return -turn;
    else if(ct == 0 && ctme>ctyou) return turn; 
    else if(ct == 0) return 2;
    else return 0;
}
int hx::evaluatescore(int board[n][m], int turn, int totalmoves,int depth)
{
	int ct = 0, ctme =0, ctyou = 0,ext=0;
	int result = win(board, turn,totalmoves, depth);
    if(result ==0 || result ==2 )
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == you) ctyou++;  
                else if(board[i][j] == me) ctme++;
                else if(board[i][j] == 12)
                {
                    if(j%2 == 0) // even column
                    {
                        if(i-1>=0) ext-= board[i-1][j];
                        if(i-1>=0 && j-1>=0) ext-= board[i-1][j-1]; 
                        if(i-1>=0 && j+1<m) ext-= board[i-1][j+1]; 
                        if(j-1>=0) ext-= board[i][j-1]; 
                        if(j+1<m) ext-= board[i][j+1]; 
                        if(i+1<n) ext-= board[i+1][j]; 
                    }
                    else
                    {
                        if(i-1>=0) ext-= board[i-1][j]; 
                        if(j-1>=0) ext-= board[i][j-1]; 
                        if(j+1<m) ext-= board[i][j+1]; 
                        if(i+1<n && j-1>=0) ext-= board[i+1][j-1]; 
                        if(i+1<n) ext-= board[i+1][j]; 
                        if(i+1<n && j+1<m) ext-= board[i+1][j+1];
                    }
                }
            }
        }
    }
    int score;
    if(result == me) score = (maxd+1- depth)*1000; 
 	else if(result == you) score = (maxd+1-depth)*1000*-1;
    else score = (4*ctme - 2*ctyou );
    return score;
}

int main()
{
    srand(time(NULL));
	hx hex;
	int board[n][m] = {0};
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		int ind = i*m+j;
    		if(j%2 == 0) // even column
    		{
    			if(i-1>=0) adj[ind].push_back(make_pair(i-1,j));
    			if(i-1>=0 && j-1>=0) adj[ind].push_back(make_pair(i-1,j-1));
    			if(i-1>=0 && j+1<m) adj[ind].push_back(make_pair(i-1,j+1));
    			if(j-1>=0) adj[ind].push_back(make_pair(i,j-1));
    			if(j+1<m) adj[ind].push_back(make_pair(i,j+1));
    			if(i+1<n) adj[ind].push_back(make_pair(i+1,j));
    		}
    		else
    		{
    			if(i-1>=0) adj[ind].push_back(make_pair(i-1,j));
    			if(j-1>=0) adj[ind].push_back(make_pair(i,j-1));
    			if(j+1<m) adj[ind].push_back(make_pair(i,j+1));
    			if(i+1<n && j-1>=0) adj[ind].push_back(make_pair(i+1,j-1));
    			if(i+1<n) adj[ind].push_back(make_pair(i+1,j));
    			if(i+1<n && j+1<m) adj[ind].push_back(make_pair(i+1,j+1));	
    		}

    		if(j%2 == 0)
    		{
    			if(i-2>=0) jump[ind].push_back(make_pair(i-2,j));
    			if(i-2>=0 && j-1>=0) jump[ind].push_back(make_pair(i-2,j-1));
    			if(i-2>=0 && j+1<m) jump[ind].push_back(make_pair(i-2,j+1));
    			if(i-1>=0 && j-2>=0) jump[ind].push_back(make_pair(i-1,j-2));
    			if(i-1>=0 && j+2<m) jump[ind].push_back(make_pair(i-1,j+2));
    			if(j-2>=0) jump[ind].push_back(make_pair(i,j-2));
    			if(j+2<m) jump[ind].push_back(make_pair(i,j+2));
    			if(i+1<n && j-2>=0) jump[ind].push_back(make_pair(i+1,j-2));
    			if(i+1<n && j+2<m) jump[ind].push_back(make_pair(i+1,j+2));
    			if(i+1<n && j-1>=0) jump[ind].push_back(make_pair(i+1,j-1));
    			if(i+1<n && j+1<m) jump[ind].push_back(make_pair(i+1,j+1));
    			if(i+2<n) jump[ind].push_back(make_pair(i+2,j));
    		}
    		else
    		{
    			if(i-2>=0) jump[ind].push_back(make_pair(i-2,j));
    			if(i-1>=0 && j-1>=0) jump[ind].push_back(make_pair(i-1,j-1));
    			if(i-1>=0 && j+1<m) jump[ind].push_back(make_pair(i-1,j+1));
    			if(i-1>=0 && j-2>=0) jump[ind].push_back(make_pair(i-1,j-2));
    			if(i-1>=0 && j+2<m) jump[ind].push_back(make_pair(i-1,j+2));
    			if(j-2>=0) jump[ind].push_back(make_pair(i,j-2));
    			if(j+2<m) jump[ind].push_back(make_pair(i,j+2));
    			if(i+1<n && j-2>=0) jump[ind].push_back(make_pair(i+1,j-2));
    			if(i+1<n && j+2<m) jump[ind].push_back(make_pair(i+1,j+2));
    			if(i+2<n && j-1>=0) jump[ind].push_back(make_pair(i+2,j-1));
    			if(i+2<n && j+1<m) jump[ind].push_back(make_pair(i+2,j+1));
    			if(i+2<n) jump[ind].push_back(make_pair(i+2,j));
    		}
    		if(ind == 0 || ind == 41)
    		{
    			//cout<< ind<<endl;	
    			//for(int k = 0; k<adj[ind].size();k++)
    			{
    				//cout<<adj[ind][k].first<<" "<<adj[ind][k].second<<endl;
    				//cout<<jump[ind][k].first<<" "<<jump[ind][k].second<<endl;   		
    			}	
    			//cout<<"done\n";
    		}
    		
    	}
    }
    int zct = 0;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		scanf("%d",&board[i][j]);
    		if(board[i][j] == 2) board[i][j] = -1;
    	   if(board[i][j] == 0) zct++;
        }
    }

	maxd =3;
    //if(zct<5) maxd=5;
    int turn, totalmoves;
    cin>> totalmoves;  
    cin>>me;
	if(me == 1) you=-1, turn = me;
	else you = 1, me=-1, turn = you;
	turn = me;
	
	//hex.print_board(board);
	//cerr<< "movegen\n";

	hex.movegen(board,turn,totalmoves);
	//cerr<< "after movegen\n";
	cout<<sti<<" "<<stj<<endl;
	cout<<endi<<" "<<endj<<endl;
	cout<<mx<<endl;
    cout<<maxd<<endl;
//	printf("%d %d\n%d %d\n",xi,yj,ci,cj);
	//cout<<" "<<mx<<" "<<mn<<endl;
	return 0;
}
