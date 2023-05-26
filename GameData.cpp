//CODE BY CODE DIVAS
//20L-1283 RAMEEN AMIR
//20L-1035 VALEENA AFZAL
#include "GameData.h"

int R=0,C=0,I=-1,J=-1;

bool castling(GameData& Game,Color Player,int FR,int FC, int TR, int TC)
{

	if(Game.Board[0][4].MoveCount==0 && Game.Board[0][7].MoveCount==0 && Player==BLACK)
	{
		if(Game.Board[0][5].Code==NONE && Game.Board[0][6].Code==NONE)// If Black King never moved a single time It must be AT Board[0][4]
		{
			Game.Board[0][5].Code=Game.Board[0][7].Code;
			Game.Board[0][5].PieceColor =Game.Board[0][7].PieceColor;
   			Game.Board[0][7].Code = NONE;
			return true;
		}
		else
			return false;
	}
	if(Game.Board[7][4].MoveCount==0 && Game.Board[7][7].MoveCount==0 && Player==WHITE)
	{
		if (Game.Board[7][5].Code==NONE && Game.Board[7][6].Code==NONE)// If White King never moved a single time It must be AT Board[7][4]
		{
			Game.Board[7][5].Code=Game.Board[7][7].Code;
			Game.Board[7][5].PieceColor =Game.Board[7][7].PieceColor;
   			Game.Board[7][7].Code = NONE;
			return true;
		}
		else
			return false;
	}
	else
		return false;

}
bool En_passant(GameData& Game,Color Player,int FR,int FC, int TR, int TC)
{
	Game.Board[TR][TC].Code=PAWN;
	Game.Board[TR][TC].PieceColor=Player;
	Game.Board[FR][TC].Code=NONE;
	Game.Board[FR][FC].Code=NONE;
	Game.Board[FR][TC].PieceColor=Player;
}
bool Knight(GameData &Game, int FR, int FC, int TR, int TC)
{
    if(TR==FR+2 && TC==FC+1)
		return true;
	if(TR==FR+2 && TC==FC-1)
		return true;
	if(TR==FR-2 && TC==FC+1)
		return true;
	if(TR==FR-2 && TC==FC-1)
		return true;
	if(TC==FC+2 && TR==FR+1)
		return true;
	if(TC==FC+2 && TR==FR-1)
		return true;
	if(TC==FC-2 && TR==FR+1)
		return true;
	if(TC==FC-2 && TR==FR-1)
		return true;
	else
		return false;


}
bool King(GameData &Game, int FR,int FC,int TR,int TC)
{
	if(isfacingCheck && I!=-1 && J!=-1)
	{
		if(TR==I)
		{
			if(TR==(FR-1) && TC==FC )
				return false;
			if(TR==(FR+1) && TC==FC)
				return false;
			if(TC==(FC+1) && TR==FR)
				return true;
			if(TC==(FC-1) && TR==FR)
				return true;
			if(TC==(FC+1) && TR==(FR-1))
				return true;
			if(TC==(FC-1) && TR==(FR+1))
				return true;
			if(TR==(FR+1) && TC==(FC+1))
				return true;
			if(TR==(FR-1) && TC==(FC-1))
				return true;
			else
				return false;
		}
		if(TC==J)
		{
			if(TC==(FC+1) && TR==FR)
				return false;
			if(TC==(FC-1) && TR==FR)
				return false;
			if(TR==(FR-1) && TC==FC )
				return true;
			if(TR==(FR+1) && TC==FC)
				return true;
			if(TC==(FC+1) && TR==(FR-1))
				return true;
			if(TC==(FC-1) && TR==(FR+1))
				return true;
			if(TR==(FR+1) && TC==(FC+1))
				return true;
			if(TR==(FR-1) && TC==(FC-1))
				return true;
			else
				return false;


		}
		if((I+J)==(TR+TC))
		{
			if(TC==(FC+1) && TR==(FR-1))
				return false;
			if(TC==(FC-1) && TR==(FR+1))
				return false;
			if(TC==(FC+1) && TR==FR)
				return true;
			if(TC==(FC-1) && TR==FR)
				return true;
			if(TR==(FR-1) && TC==FC )
				return true;
			if(TR==(FR+1) && TC==FC)
				return true;
			if(TR==(FR+1) && TC==(FC+1))
				return true;
			if(TR==(FR-1) && TC==(FC-1))
				return true;
			else
				return false;
		}
		if(abs(I-J)==abs(TR=TC))
		{
			if(TR==(FR+1) && TC==(FC+1))
				return false;
			if(TR==(FR-1) && TC==(FC-1))
				return false;
			if(TC==(FC+1) && TR==(FR-1))
				return true;
			if(TC==(FC-1) && TR==(FR+1))
				return true;
			if(TC==(FC+1) && TR==FR)
				return true;
			if(TC==(FC-1) && TR==FR)
				return true;
			if(TR==(FR-1) && TC==FC )
				return true;
			if(TR==(FR+1) && TC==FC)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	if(TR==(FR-1) && TC==FC )
		return true;
	if(TR==(FR+1) && TC==FC)
		return true;
	if(TC==(FC+1) && TR==FR)
		return true;
	if(TC==(FC-1) && TR==FR)
		return true;
	if(TR==(FR+1) && TC==(FC+1))
		return true;
	if(TC==(FC+1) && TR==(FR-1))
		return true;
	if(TR==(FR-1) && TC==(FC-1))
		return true;
	if(TC==(FC-1) && TR==(FR+1))
		return true;
	if((TC==6 && TR==0)||(TC==6 && TR==7))
	{
		if(castling(Game,Game.TurningPlayer,FR,FC,TR,TC))
			return true;
		else
			return false;
	}
	else
		return false;

}
bool Rook(GameData &Game,Color Player, int FR, int FC, int TR, int TC)
{
    //cout<<"\nhere i am\n";
	int counter=0;
	if(Game.Board[TR][TC].PieceColor==Player || Game.Board[TR][TC].Code==NONE)
	{
        //cout<<"\nhere IIIII am\n";
		if (FR!=TR && FC!=TC)
            return false;
        if(FR==TR)
        {
            if (FC<TC)
            {
                for(int r=FC+1; r<TC ; r++)
                {
                    if(Game.Board[FR][r].Code==NONE)
                    counter++;

                }
                cout<<"counter+1"<<counter+1<<"TC-FC"<<TC-FC;
                if ((counter+1)==abs(TC-FC))
                 return true;
            }
            counter=0;
            if (FC>TC)
            {
                for (int r=FC-1; r> TC ; r--)
                {
                    if(Game.Board[FR][r].Code==NONE)
						counter++;
                }
                cout<<"counter+1"<<counter+1<<"FC-TC"<<FC-TC;
                if((counter+1)==abs(FC-TC))
                	return true;
                else
                	return false;
            }
            else
            	return false;
        }
        if(FC==TC)
        {
            counter=0;
			if(FR<TR)
            {
                for(int r=FR+1; r< TR ;r++)
                {
                    if(Game.Board[r][TC].Code==NONE)
                        counter++;
                }
                cout<<"counter+1"<<counter+1<<"TR-FR"<<TR-FR;
                if((counter+1)==abs(TR-FR))
                	return true;
            }
            counter=0;
            if (FR>TR)
            {
                for (int r=FR-1; r>TR; r--)
                {
                    if(Game.Board[r][TC].Code==NONE)
                        counter++;
                }
                cout<<"counter+1"<<counter+1<<"FR-TR"<<FR-TR;
                if((counter+1)==abs(FR-TR))
                	return true;
                else
                	return false;
            }
            else
            	return false;
        }
        else
        	return false;
    }
	else
		return false;
}
bool Bishop(GameData &Game,Color Player, int FR, int FC, int TR, int TC)
{
	int rr=0,cc=0,baba=0;
	//cout<<endl<<FR<<FC<<TR<<TC<<"valeena ki galtiyan"<<endl;
	if(Game.Board[TR][TC].PieceColor==Player || Game.Board[TR][TC].Code==NONE)
    {
            //cout<<"\n\t\tis problem here\n";
            if( abs(FR-FC)!=abs(TR-TC) && (FR+FC)!=(TR+TC) )
            {
                //cout<<endl<<endl<<"\t\t1"<<endl<<endl;
                return false;

            }

            // for checking main diagonal
            //else if(abs(FR-FC)==abs(TR-TC))
            //{


                if (FR>TR && FC>TC)                                      // for checking upper part of main diagonal
                {
                    //cout<<endl<<endl<<"\t\t2 "<<endl<<endl;
                    rr=FR-1,cc=FC-1;
                    //cout<<"\n\t start: "<<rr<<cc;
                    // for checking lower part
                    do{

                        //cout<<endl<<endl<<"rr"<<rr<<"\tcc"<<cc<<endl<<endl;
                        if(Game.Board[rr][cc].Code==NONE)
                         {
	                         baba++;
	                         //cout<<endl<<endl<<"\t\t3.1"<<endl<<endl;
                         }
                         rr--;cc--;


                    }while(rr>TR && cc>TC);
                    //cout<<r<<c<<baba;
                    //cout<<endl<<endl<<"\t\tnow this is cheating"<<endl<<endl;

                }
                //cout<<"\n\there commes another one\t baba:"<<baba<<" TR:"<<TR<<" FR:"<<FR<<" TR-FR-1 "<<TR-FR-1<<endl;
                if( abs(baba+1)==abs(TR-FR) )
				{
                	//cout<<"the debugger";
					return true;
				}

				baba=0,rr=0,cc=0;
                if (FR<TR && FC<TC)
                {
                    //cout<<endl<<endl<<"\t\t3 agee vi das"<<endl<<endl;
                    rr=FR+1,cc=FC+1;
                    //cout<<endl<<endl<<"\t\t huhhhhhhhhhhh"<<endl<<endl;
                    //cout<<"\n\t start: "<<rr<<cc;
                    // for checking lower part
                    do{

                        //cout<<endl<<endl<<"rr"<<rr<<"\tcc"<<cc<<endl<<endl;
                        if(Game.Board[rr][cc].Code==NONE)
                         {
	                         baba++;
	                         //cout<<endl<<endl<<"\t\t3.1"<<endl<<endl;
                         }
                         rr++;cc++;


                    }while(rr<TR && cc<TC);
                    //cout<<r<<c<<baba;
                    //cout<<endl<<endl<<"\t\tnow this is cheating"<<endl<<endl;

                }
                //cout<<"\n\there commes another one\t baba:"<<baba<<" TR:"<<TR<<" FR:"<<FR<<" TR-FR-1 "<<TR-FR-1<<endl;
                if( abs(baba+1)==abs(TR-FR) )
				{
                	//cout<<"the debugger";
					return true;
				}
            //}

            // for checking secondary diagonal
            //else if ((FR+FC)==(TR+TC))
            //{
 				baba=0,rr=0,cc=0;
                if (FR>TR && FC<TC )
                {
                    //cout<<endl<<endl<<"\t\t4 "<<endl<<endl;
                    rr=FR-1,cc=FC+1;
                    //cout<<"\n\t start: "<<rr<<cc;
                    																// for checking upeer prt of secondary diagonal
                    do{

                        //cout<<endl<<endl<<"rr"<<rr<<"\tcc"<<cc<<endl<<endl;
                        if(Game.Board[rr][cc].Code==NONE)
                         {
	                         baba++;
	                         //cout<<endl<<endl<<"\t\t4.1"<<endl<<endl;
                         }
                         rr--;cc++;


                    }while(rr>TR && cc<TC);
                    //cout<<r<<c<<baba;
                    //cout<<endl<<endl<<"\t\tnow this is cheating"<<endl<<endl;

                }
                //cout<<"\n\there commes another one\t baba:"<<baba<<" TR:"<<TR<<" FR:"<<FR<<" TR-FR-1 "<<TR-FR-1<<endl;
                if( abs(baba+1)==abs(FR-TR) )
				{
                	//cout<<"the debugger";
					return true;
				}

				baba=0,rr=0,cc=0;
				if (FR<TR && FC > TC )
                {
                    //cout<<endl<<endl<<"\t\t5 "<<endl<<endl;
                    rr=FR+1,cc=FC-1;
                    //cout<<"\n\t start: "<<rr<<cc;
                    																// for checking lower part
                    do{
                        //cout<<endl<<endl<<"rr"<<rr<<"\tcc"<<cc<<endl<<endl;
                        if(Game.Board[rr][cc].Code==NONE)
                         {
	                         baba++;
	                         //cout<<endl<<endl<<"\t\t5.1"<<endl<<endl;
                         }
                         rr++,cc--;

	                }while(rr<TR && cc>TC);
	                    //cout<<r<<c<<baba;
	                    //cout<<endl<<endl<<"\t\tnow this is cheating"<<endl<<endl;

                }
                //cout<<"\n\there commes another one\t baba:"<<baba<<" TR:"<<TR<<" FR:"<<FR<<" TR-FR-1 "<<TR-FR-1<<endl;
                if( abs(baba+1)==abs(TR-FR) )
				{
                	//cout<<"the debugger";
					return true;
				}

	            else
	            {
	                //cout<<endl<<endl<<"\t\tmnhoos"<<endl<<endl;
	                return false;
	            }


	}
	else if(Game.Board[TR][TC].PieceColor==Player || Game.Board[TR][TC].Code!=NONE)
    {
        //cout<<"asal maslaaaaaaaaaaaaaaaaaaaaa";
        return false;
    }
}
bool Queen(GameData &Game, int FR, int FC, int TR, int TC)
{
	if (Rook(Game,Game.TurningPlayer,FR,FC,TR,TC) )
		return true;
	if (Bishop(Game,Game.TurningPlayer,FR,FC,TR,TC))
		return true;
	else
		return false;

}
void PromotePawn(GameData &Game,PieceType P, int TR, int TC)
{
	//Move.PawnPromotedTo=P;
	if(P==ROOK)
		Game.Board[TR][TC].Code=ROOK;
	if(P==BISHOP)
		Game.Board[TR][TC].Code=BISHOP;
	if(P==KNIGHT)
		Game.Board[TR][TC].Code=KNIGHT;
	if(P==QUEEN)
		Game.Board[TR][TC].Code=QUEEN;
	Game.Board[TR][TC].PieceColor= Game.TurningPlayer;

}
bool Pawn(GameData& Game, int FR, int FC, int TR, int TC)
{
	if( Game.Board[FR][FC].PieceColor == WHITE)
	{
		if(FR == 6 && TR == 4 && FC == TC && Game.Board[TR][TC].Code == NONE && Game.Board[FR-1][FC].Code == NONE )
			return true;
		if(FR == 6 && TR == (FR-1) && FC == TC && Game.Board[TR][TC].Code == NONE  )
			return true;
		if(Game.Board[TR][TC].Code==NONE  && FC==TC  && TR==(FR-1) && TR!=0 && FR!=1 )
			return true;
		if(TR == (FR-1) && TC == (FC+1)&& Game.Board[TR][TC].PieceColor != Game.TurningPlayer && Game.Board[TR][TC].Code!=NONE )
			return true;
		if(TR == (FR-1) && TC == (FC-1)&& Game.Board[TR][TC].PieceColor != Game.TurningPlayer && Game.Board[TR][TC].Code!=NONE )
			return true;
		if( (TR==0 && FC==TC && FR==1 && Game.Board[TR][TC].Code==NONE  )|| ( TR==0 && TC==FC+1 && FR==1 && Game.Board[TR][TC].PieceColor==BLACK  )|| ( TR==0 && TC==FC-1 && FR==1 && Game.Board[TR][TC].PieceColor==BLACK  ) )
		{
			int Piece;
			cout<<"What piece will you promote to?"<<endl;
			cout<<"1. ROOK\t\t2. BISHOP\t\t3.KNIGHT\t\t4.QUEEN"<<endl;
			cin>>Piece;
			PieceType P = static_cast<PieceType>(Piece);
			PromotePawn(Game, P, 0, TC);
			return true;
		}
		else return false;
	}
	if(Game.TurningPlayer == BLACK)
		{
			if(FR == 1 && TR == 3  && FC == TC && Game.Board[TR][TC].Code == NONE && Game.Board[FR + 1][FC].Code == NONE)
				return true;
			if(FR == 1 && TR == (FR+1) && FC == TC && Game.Board[TR][TC].Code == NONE )
				return true;
			if(Game.Board[TR][TC].Code==NONE  && FC==TC  && TR==(FR+1) && TR!=7 && FR!=6  )
				return true;
			if(TR == (FR+1) && TC == (FC+1) && Game.Board[TR][TC].PieceColor != Game.TurningPlayer && Game.Board[TR][TC].Code!=NONE )
				return true;
			if(TR == (FR+1) && TC == (FC-1) && Game.Board[TR][TC].PieceColor != Game.TurningPlayer && Game.Board[TR][TC].Code!=NONE )
				return true;
				if(
					(TR==7 && FC==TC && FR==6 && Game.Board[TR][TC].Code==NONE)
					|| ( TR==7 && TC==FC+1 && FR==6 && Game.Board[TR][TC].PieceColor==WHITE)
					|| ( TR==7 && TC==FC-1 && FR==6 && Game.Board[TR][TC].PieceColor==WHITE)
			      )
					{
						int Piece;
						cout<<"What piece will you promote to?"<<endl;
						cout<<"1. ROOK\t\t2. BISHOP\t\t3.KNIGHT\t\t4.QUEEN"<<endl;
						cin>>Piece;
						PieceType P = static_cast<PieceType>(Piece);
						PromotePawn(Game, P, 7, TC);
						return true;
					}
			else return false;
		}
	else return false;
}
/*int  AfterCheck (GameData Game, Color Player,chessMove Move, int FR,int FC,int TR,int TC)
{
    Game.Board[TR][TC].Code = Game.Board[FR][FC].Code;// Makes move on the Board

    Game.Board[TR][TC].PieceColor =Game.Board[FR][FC].PieceColor;

    Game.Board[FR][FC].Code = NONE;

    if(isfacingCheck(Game,Player)==1)// after Making move by tuning player if the still there is check ..it reverses the above move
    {
        cout<<"MSLAAAAAAAAAA";
		Game.Board[FR][FC].Code=Game.Board[TR][TC].Code;// whatever the problem is ... its here
    	Game.Board[FR][FC].PieceColor=Game.Board[TR][TC].PieceColor;
    	Game.Board[TR][TC].Code = NONE;
    	return 0;
	}

    if(Game.TurningPlayer == BLACK)
        Game.TurningPlayer = WHITE;
    else
        Game.TurningPlayer = BLACK;
    if(isfacingCheck(Game,Game.TurningPlayer))
        return 0;
    return 1;

}
*/
bool isValidMove(GameData& Game, chessMove Move)
{
	int FR, FC, TR,TC;
    FR = Move.FromRow;
    FC = Move.FromColumn;
    TR = Move.ToRow;
    TC = Move.ToColumn;
    //Move.PieceCaptured
    // For Black player
	if(Game.Board[FR][FC].PieceColor==BLACK && Game.TurningPlayer==BLACK)
	{
		//MOVES FOR PAWN
		if (Game.Board[FR][FC].Code==PAWN)
		{
			if(Pawn(Game,FR,FC,TR,TC))
			{
				Game.Board[TR][TC].MoveCount++;
				return true;
			}

			else
				return false;
    	}
    	//MOVES FOR KING
    	if (Game.Board[FR][FC].Code==KING)
		{
			if ((Game.Board[TR][TC].Code==NONE) || (Game.Board[TR][TC].PieceColor==WHITE ))
			{
				if(King(Game, FR, FC, TR, TC))
				{
					Game.Board[TR][TC].MoveCount++;
					return true;
				}
					//return true;
	   	 		else
	        		return false;
	    	}
		 }
		// moves for knight
		if(Game.Board[FR][FC].Code==KNIGHT)
		{
			if((Game.Board[TR][TC].Code==NONE) || (Game.Board[TR][TC].PieceColor==WHITE))
			{
				if (Knight(Game,FR,FC,TR,TC))
				{
					Game.Board[TR][TC].MoveCount++;
					return true;
				}

				else
					return false;
			}
		}
		//MOVES FOR ROOK
		if(Game.Board[FR][FC].Code==ROOK)
		{
			if((Game.Board[TR][TC].Code==NONE || Game.Board[TR][TC].PieceColor==WHITE  ))
			{
				if(Rook(Game,WHITE, FR, FC, TR, TC))
				{
					Game.Board[TR][TC].MoveCount++;
					return true;
				}

				else
					return false;
			}
		}
		// Moves For Bishops
		if(Game.Board[FR][FC].Code==BISHOP)
		{
			if((Game.Board[TR][TC].Code==NONE || Game.Board[TR][TC].PieceColor==WHITE  ))
			{
				if(Bishop(Game,WHITE,  FR, FC, TR, TC))
				{
					Game.Board[TR][TC].MoveCount++;
					return true;
				}

				else
					return false;

			}
		}
		//Moves for Queen
		if(Game.Board[FR][FC].Code==QUEEN)
		{
			//if((Game.Board[TR][TC].Code==NONE || Game.Board[TR][TC].PieceColor==WHITE  ))
			//{
				if( Rook(Game,WHITE, FR, FC, TR, TC) || Bishop(Game,WHITE,  FR, FC, TR, TC) )
				{
					Game.Board[TR][TC].MoveCount++;
					return true;
				}
				else
					return false;
			//}

		}
		else
			return false;

	}
	else if (Game.Board[FR][FC].PieceColor==WHITE && Game.TurningPlayer==WHITE)
	{
		//MOVES FOR PAWN
		if (Game.Board[FR][FC].Code==PAWN)
		{
			if(Pawn(Game,FR,FC,TR,TC))
			{
				Game.Board[TR][TC].MoveCount++;
				return true;
			}
			else
				return false;

		}
		//MOVES FOR KING
    	if(Game.Board[FR][FC].Code==KING)
		{
			if ((Game.Board[TR][TC].Code==NONE) || (Game.Board[TR][TC].PieceColor==BLACK ))
			{
				if(King(Game, FR, FC, TR, TC))
				{
					Game.Board[TR][TC].MoveCount++;
					return true;
				}
	   	 		else
	        		return false;
			}
		}
		// moves for knight
		if(Game.Board[FR][FC].Code==KNIGHT)
		{
			if ((Game.Board[TR][TC].Code==NONE) || (Game.Board[TR][TC].PieceColor==BLACK))
			{
				if (Knight(Game,FR,FC,TR,TC)==true)
				{
					Game.Board[TR][TC].MoveCount++;
					return true;
				}
				else
					return false;
			}
		}
		//MOVES FOR ROOK
		if(Game.Board[FR][FC].Code==ROOK )
		{
			if ((Game.Board[TR][TC].Code==NONE || Game.Board[TR][TC].PieceColor==BLACK  ))
			{
				if(Rook(Game,BLACK, FR, FC, TR, TC))
				{
					Game.Board[TR][TC].MoveCount++;
					return true;
				}
				else
					return false;
			}
		}
		// Moves For Bishops
		if(Game.Board[FR][FC].Code==BISHOP)
		{
			if((Game.Board[TR][TC].Code==NONE || Game.Board[TR][TC].PieceColor==BLACK  ))
			{
				if(Bishop(Game,BLACK,  FR, FC, TR, TC))
				{
					Game.Board[TR][TC].MoveCount++;
					return true;
				}
				else
					return false;

			}
		}
		//Moves for Queen
		if(Game.Board[FR][FC].Code==QUEEN)
		{
			if((Game.Board[TR][TC].Code==NONE || Game.Board[TR][TC].PieceColor==BLACK  ))
			{
				if( Rook(Game,BLACK, FR, FC, TR, TC) || Bishop(Game,BLACK,  FR, FC, TR, TC))
				{
						Game.Board[TR][TC].MoveCount++;
						return true;
				}
				else
					return false;
			}

		}
		else
			return false;
	}
}
int  MakeMove(GameData& Game, chessMove Move)
{
    //0 false
    //1 true
    //Function to make a move on the board
    // It will return 0 if the move is valid and a code of error to specify why the move is not valid otherwise

	// Follwoing is a very simple move example. Your code will support all types of moves including pawn promotion, castling and En Passant etc. Furthermore i must also add the move in the vector of moves used for keeping history.

	if(!isValidMove(Game, Move))
        return 0;
   	//if(PromotePawn(Game,PawnPromotedTo,TR,TC))

    int FR, FC, TR,TC;
    FR = Move.FromRow;
    FC = Move.FromColumn;
    TR = Move.ToRow;
    TC = Move.ToColumn;
    /*if(isfacingCheck(Game,Game.TurningPlayer))// in the first turn when white enters moves this condition is invalid so no entry
    {
    	// in next turn if black faced checked accrding to isfacing below
    	// when black enters a move this condtion works
    	// the moves entered by the black are checked to see if it gets it out of check
    	// if it removes check then the after check function must return without executing the remaining part of make move
    	// bcz the move has already been made
    	// the after check must automatically change the turning player
    	if(AfterCheck (Game,Game.TurningPlayer,Move,FR,FC,TR,TC)==0)
            return 0;
        else
           goto finish;
    }
    finish:*/
    Game.Board[TR][TC].Code = Game.Board[FR][FC].Code;// here it performs move

    Game.Board[TR][TC].PieceColor =Game.Board[FR][FC].PieceColor;

    Game.Board[FR][FC].Code = NONE;



    if(Game.TurningPlayer == BLACK)// change player
        Game.TurningPlayer = WHITE;
    else
        Game.TurningPlayer = BLACK;

    //if(isCheckmate(Game,Game.TurningPlayer))
    //	return 1;
 	if(isfacingCheck(Game,Game.TurningPlayer))
    {
    //this statement here means when for example a black piece has reached a position from where it can capture whiteking
    //the function isfacingcheck should display CHECK on screen
    	return 0;
    }

    // this function will return true if the move specified by the Move parameter is a valid move
    // You might make more functions to breakdown the task of this function into subtasks
    return 1;
}
void initGame(GameData& Game)
{

    for(int r = 0; r < 2; r++)
        for(int c= 0; c < 8; c++ )
            Game.Board[r][c].PieceColor = BLACK;

    for(int r = 2; r < 6; r++)
        for(int c= 0; c < 8; c++ )
            Game.Board[r][c].Code = NONE;

    for(int r = 6; r < 8; r++)
        for(int c= 0; c < 8; c++ )
            Game.Board[r][c].PieceColor = WHITE;


    Game.Board[0][0].Code = Game.Board[0][7].Code = ROOK;
    Game.Board[7][0].Code = Game.Board[7][7].Code = ROOK;

    Game.Board[0][1].Code = Game.Board[0][6].Code = KNIGHT;
    Game.Board[7][1].Code = Game.Board[7][6].Code = KNIGHT;

    Game.Board[0][2].Code = Game.Board[0][5].Code = BISHOP;
    Game.Board[7][2].Code = Game.Board[7][5].Code = BISHOP;

    Game.Board[0][3].Code = Game.Board[7][3].Code = QUEEN;
    Game.Board[0][4].Code = Game.Board[7][4].Code = KING;

    for(int c= 0; c < 8; c++ )
        Game.Board[1][c].Code = Game.Board[6][c].Code = PAWN;

    Game.TurningPlayer = WHITE;

    Game.MoveHistory = vector<chessMove>(1);
    return;
}
bool isfacingCheck(GameData& Game, Color Player)
{
	int i,j;
	for(int r=0; r<8 ;r++)
	{
		for(int c=0; c<8 ;c++)
		{
			if(Game.Board[r][c].Code==KING && Game.Board[r][c].PieceColor==Player)// To find the position of Turning Player's  King
			{
				R=r;
				C=c;
			}
		}
	}
	if(Game.Board[R][C].Code==KING && Game.Board[R][C].PieceColor==Player)
	{
        for(int r=0; r<8 ;r++)
        {
            for(int c=0; c<8 ;c++)
            {
                if(Game.Board[r][c].Code!=NONE && Game.Board[r][c].PieceColor!=Player)// To Find Opponent's pieces position
                {

                    i=r;
                    j=c;
                    if(Game.Board[i][j].Code==PAWN && Game.Board[R][C].PieceColor==Player)
                        if(Pawn(Game,i,j,R,C))
                            {
                                 cout<<"\nCheck Because of Pawn\n"<<  "Row"<< i<<  "Col"<< j;
                                 I=i;
                                 J=j;

                                 return true;
                            }
                    if(Game.Board[i][j].Code==KING && Game.Board[R][C].PieceColor==Player)
                        if(King(Game,i,j,R,C))
                            {
                            	 //cout<<"\n\n\t"<<i<<"\t"<<j<<"\t"<<R<<"\t"<<C;
                                 cout<<"\nCheck Because of King\n"<<  "Row"<< i<<  "Col"<< j;
                                 I=i;
                                 J=j;

                                 return true;
                            }
                    if(Game.Board[i][j].Code==BISHOP && Game.Board[R][C].PieceColor==Player)
                        {
                            //cout<<"\n\n\t"<<i<<"\t"<<j<<"\t"<<R<<"\t"<<C;
                            if(Bishop(Game,Player,i,j,R,C))
                                {
                                     cout<<"\nCheck Because of Bishop\n"<<  "Row"<< i<<  "Col"<< j;
	                                 I=i;
	                                 J=j;

                                     return true;
                                }
                        }
					if(Game.Board[i][j].Code==QUEEN && Game.Board[R][C].PieceColor==Player)
                        {
                        if(Rook(Game,Player,i,j,R,C) || Bishop(Game,Player,i,j,R,C))
                            {
                                 cout<<"\nCheck Because of Queen\n"<<  "Row"<< i<<  "Col"<< j;
                                 I=i;
                                 J=j;

                                 return true;
                            }
                        }
                    if(Game.Board[i][j].Code==KNIGHT && Game.Board[R][C].PieceColor==Player)
                        if(Knight(Game,i,j,R,C))
                            {
                                 cout<<"\nCheck Because of Knight\n" <<  "Row"<< i<<  "Col"<< j;
                                 I=i;
                                 J=j;
                                 return true;
                            }
                    if(Game.Board[i][j].Code==ROOK && Game.Board[R][C].PieceColor==Player)
                        if(Rook(Game,Player,i,j,R,C))
                            {
                                 cout<<"\nCheck Because of Rook\n"<<  "Row"<< i<<  "Col"<< j;
                                 I=i;
                                 J=j;
                                 return true;
                            }
					//else
					//return false;
                }

            }
        }
	}
	else
	{
        //cout<<"mei hon mslaaaaaaaaaaaaaaaaaaa";
        return false;
	}
}
bool isCheckmate(GameData& Game, Color Player)
{
    // This function must return true if player having Color Player is facing a checkmate
	//	if ((Game.TurningPlayer==Player ))
	//	{
	int RR,CC;
	for(int r=0; r<8 ;r++)
	{
		for(int c=0; c<8 ;c++)
		{
			if(Game.Board[r][c].Code==KING && Game.Board[r][c].PieceColor==Player)
			{
				RR=r;
				CC=c;
			}
		}
	}

	for(int r=RR-1; r<=RR+1 ;r++)
		for(int c=CC-1; c<=CC+1 ;c++)
			if ((Game.Board[r][c].Code==NONE) || (Game.Board[r][c].PieceColor!=Player ))
					if(King(Game, RR, CC, r, c))
	 					return false;
	 		else
	 			return true;

    /*
  	chessMove Move;
    if (Game.Board[RR][CC].Code=KING)
        if (!isValidMove(Game,Move))
            if(isfacingCheck(Game,Player))
				return true;
			else
				return false;
    */
}

