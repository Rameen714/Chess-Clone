//CODE BY CODE DIVAS
//20L-1283 RAMEEN AMIR
//20L-1035 VALEENA AFZAL
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include "GameData.cpp"
#include "GameData.h"
//#include "Player.cpp"

using namespace std;

int T1=0,T2=0;

struct Chess
{
    GameData GameState;
    string PlayerNames[2];
    bool GameActive = false;
}
Game;

string getPlayerinfo()
{
    string Name="";
    cout<< "\nEnter Player Name\n";
    do
	{
        cin.clear();
        fflush(stdin);
        getline(cin, Name);
    }
	while(Name.length() == 0);

	return Name;
}

int SaveGame()
{
	if(!Game.GameActive)
	{
		cout<<"No Active Game Available For Save\n";
		return -1;
	}

	string FileName;
	do
	{
		cout<<"Enter File Name";
		cin.clear();
		fflush(stdin);
		getline (cin, FileName);
	}
	while(FileName.length() == 0);
	ofstream F (FileName.c_str());
	if(!F)
	{
		cout<<"Unable to Open File\n";
		return -2;
	}
//


    F<<Game.PlayerNames[0]<<endl<<Game.PlayerNames[1]<<endl;

    F<<Game.GameState.TurningPlayer<<endl;

    F<<T1<<endl;F<<T2<<endl;

	for(int r = 0; r< 8; r++)
	    for(int c = 0; c< 8; c++)
	        F<<Game.GameState.Board[r][c].PieceColor<<" "<<Game.GameState.Board[r][c].MoveCount<<" "<<Game.GameState.Board[r][c].Code<<endl;

    F.close();

	return 0;
}

int LoadGame()
{
	string FileName;
	do
	{
		cout<<"Enter File Name";
		cin.clear();
		fflush(stdin);
		getline (cin, FileName);
	}
	while(FileName.length() == 0);

	ifstream F (FileName.c_str());

	if(!F)
	{
		cout<<"Unable to Open File\n";
		return -2;
    }

    F>>Game.PlayerNames[0]>>Game.PlayerNames[1];

	int val=Game.GameState.TurningPlayer;
	F>>val;
	F>>T1;F>>T2;
	for(int r = 0; r< 8; r++)
	    for(int c = 0; c< 8; c++)
	    {
	    	int v,a,l;
	    	F>>v>>a>>l;

			Color P =static_cast<Color>(v);
			PieceType T=static_cast<PieceType>(l);

	    	Game.GameState.Board[r][c].PieceColor=P;
			Game.GameState.Board[r][c].MoveCount=a;
			Game.GameState.Board[r][c].Code=T;
		}

	Game.GameActive=true;

    F.close();

    return 0;
}

void ShowGame()
{
	system("color 03");
    cout<<"\t\t\t"<< Game.PlayerNames[1]<<"\tvs\t"<<Game.PlayerNames[0]<<"\t"<<endl;
    cout<<right<<setw(100)<<setfill(' ')<<"GAME DATA"<<endl;
    cout<<right<<setw(90)<<setfill(' ')<<""<<"Player 1 Total Turns :  "<< T1<<endl;
    cout<<right<<setw(90)<<setfill(' ')<<""<<"Player 2 Total Turns :  "<< T2;
    for(int r = 0; r < 8; r++ )
	{
        cout<<endl<<r;

        for(int c = 0; c < 8; c++)
		{
            switch(Game.GameState.Board[r][c].Code)
			{

                case NONE:
                    cout<<"\t..";
                break;
                default:
                    cout<<"\t";
                    if(Game.GameState.Board[r][c].PieceColor == BLACK)
                    	{
                    		system("color 03");
                            cout<<"B";
						}
                    else
                    {
                    	system("color 03");
                        cout<<"W";
					}


                    switch(Game.GameState.Board[r][c].Code)
					{
                    case PAWN:
                        cout<<"Pawn";
                    break;

                    case ROOK:
                        cout<<"Rook";
                    break;

                    case KNIGHT:
                        cout<<"Knight";
                    break;

                    case BISHOP:
                        cout<<"Bishop";
                    break;

                    case QUEEN:
                        cout<<"Queen";
                    break;

                    case KING:
                        cout<<"King";
                    break;
                    }
                break;
            }
        }
        cout<<endl<<endl;
    }
    cout<<endl;
    for(int c = 0; c< 8; c++)
        cout<<"\t"<<c;
    cout<<"\n\n";
}

void initNewGame()
{
    cout<<"Enter First(WHITE) Player's Info"<<endl;
    Game.PlayerNames[1] = getPlayerinfo();
    cout<<"\n\nEnter Second(BLACK) Player's Info"<<endl;
    Game.PlayerNames[0] = getPlayerinfo();
    initGame(Game.GameState);
}

int PlayGame()
{
    chessMove Move;
    ShowGame();
    while(!isCheckmate(Game.GameState, Game.GameState.TurningPlayer) )
	{
        cout<<Game.PlayerNames[Game.GameState.TurningPlayer];
        if(Game.GameState.TurningPlayer == WHITE)
        {
        	cout<<" :(WHITE) Turn To Make a Move";
        	T1++;
		}

        else
        {
        	cout<<" :(BLACK) Turn To Make a Move";
        	T2++;
		}


        cout<<"\n\n"<<"Enter your Move [Format: FROM (Row# Column#) TO (Row# Column#)] "<<endl;
		cout<<"\nEnter Negative Value to move to the Main Menu\n"<<endl;

		Game.GameActive=true;
        cin >> Move.FromRow>>Move.FromColumn;
        cin>>Move.ToRow>>Move.ToColumn;

        if(Move.FromRow < 0 || Move.FromColumn < 0 || Move.ToColumn < 0 || Move.ToRow < 0)
		{
            cout<< "Moving to Main Menu \n";
            return 0;
        }
        if(Move.FromRow < 0 || Move.FromColumn < 0 || Move.ToColumn < 0 || Move.ToRow < 0 ||Move.FromRow > 7 || Move.FromColumn > 7 || Move.ToColumn > 7 || Move.ToRow > 7 )
		{
            cout<< "Invalid Move \n";
            cout<< "Start over Again \n";
            return 0;
        }

        MakeMove(Game.GameState, Move);
        ShowGame();
    }

    return 0;

}


int main()
{
    int choice = 0;
    do
	{
        do
		{
            cout<<"1. New Game\n2. Restart Game\n3. Save Game\n4. Load Game\n5. Exit\n\n Enter Your Choice(1-5) ";
            cin>>choice;
        }
		while(choice< 1 || choice > 5);

        switch(choice)
		{
	        case 1:
	            initNewGame();
	            PlayGame();
	        break;
	        case 2:
	        	initGame(Game.GameState);
	            PlayGame();
	        break;
	        case 3:
	            SaveGame();
	        break;
	        case 4:
	            LoadGame();
	            PlayGame();
	        break;
	        case 5:
	            return 0;
	        break;
        }
    }
	while(1);

    return 0;
}
