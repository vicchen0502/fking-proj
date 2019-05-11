#include "pch.h"
#include "chess.h"

// 利用巨集先定義 上,下,左,右,ESC
#define ESC	27
#define DIRECTION_KEYBOARD	224
#define UP     72
#define DOWN   80
#define LEFT   75
#define RIGHT  77
#define ENTER 13

using namespace std;

//class Chess
Chess::Chess(string filename)
{
	ifstream fin(filename);
	for (int i = 0; i < 10; i++)
	{
		vector<int> temp = {};
		for (int j = 0; j < 9; j++)
		{
			int chess;
			fin >> chess;
			temp.push_back(chess);
		}
		chessBoard.push_back(temp);
	}
	fin >> whoseTurn;
	fin.close();
}


vector<int> Chess::selectedChess()
{
	// 游標移動 "至" (x, y)  
	void gotoxy(int x, int y);
	
	// 設定游標的樣式
	void SetCursorVisible(BOOL _bVisible, DWORD _dwSize);
	
	// 以下程式碼是移動游標
	unsigned short int ch1, ch2;
	unsigned short int X = 0, Y = 0;

	// 200 是變成橫向游標  (你可以試試看	SetCursorVisible(TRUE, 100);)
	SetCursorVisible(TRUE, 200);
	gotoxy(0, 1);
	X = 0;
	Y = 1;
	COORD coordInData;
	coordInData = { 0, 0 };
	int func;
	beforeSelect:
	while (true)
	{
		ch1 = _getch();
		if (ch1 == ESC)
		{
			func = ESC;
			break;
		}
		else if (ch1 == DIRECTION_KEYBOARD)
		{
			ch2 = _getch();
			switch (ch2)
			{
			case UP:
				if (Y == 1)
					break;
				Y = Y - 2;
				gotoxy(X, Y);
				coordInData.X -= 1;
				break;
			case DOWN:
				if (Y == 19)
					break;
				Y = Y + 2;
				gotoxy(X, Y);
				coordInData.X += 1;
				break;
			case LEFT:
				if (X == 0)
					break;
				X = X - 4;
				gotoxy(X, Y);
				coordInData.Y -= 1;
				break;
			case RIGHT:
				if (X == 32)
					break;
				X = X + 4;
				gotoxy(X, Y);
				coordInData.Y += 1;
				break;
			case ENTER:
				func = ENTER;
				goto afterselect;
				break;
			}

		}
		else if (ch1 == ENTER)
		{
			func = ENTER;
			goto afterselect;
		}
	}
	
afterselect:
	vector<int> position = { -1,-1 };
	switch (func)
	{
	case ESC:
		return position;
		break;
	case ENTER:
		if (whoseTurn == 0)
		{
			if (chessBoard[coordInData.X][coordInData.Y] >= 1 && chessBoard[coordInData.X][coordInData.Y] <= 7)
			{
				position[0] = coordInData.X;
				position[1] = coordInData.Y;
			}
			else
			{
				goto beforeSelect;
			}
		}
		else if (whoseTurn == 1)
		{
			if(chessBoard[coordInData.X][coordInData.Y] >= 8 && chessBoard[coordInData.X][coordInData.Y] <= 14)
			{
				position[0] = coordInData.X;
				position[1] = coordInData.Y;
			}
			else goto beforeSelect;
		}
		else selectedChess();

		return position;
		break;
	default:
		goto beforeSelect;
		break;
	}
	
}

vector<vector<int>> Chess::whereCanGO(vector<int>pos)
{
	vector<vector<int>>leagelList;
	if (whoseTurn == 0)
	{
		switch (chessBoard[pos[0]][pos[1]])
		{
		case 1://將
			for (int i = max(pos[0]-1,0); i <= min(pos[0]+1,2); i++)
			{
				for (int j = max(pos[1]-1,4); j <= min(pos[1]+1,6); j++)
				{
					if (chessBoard[i][j] == 0 ||
						(chessBoard[i][j] >= 8 && chessBoard[i][j] <= 14))
					{
						leagelList.push_back({ i,j });
					}
				}
			}
			break;
		case 2://士
			if (pos[0] == 0)
			{
				if (chessBoard[1][5] == 0 ||
					(chessBoard[1][5] >= 8 && chessBoard[1][5] <= 14))
				{
					leagelList.push_back({ 1, 5 });
				}
			}
			else if (pos[0] == 1)
			{
				if (chessBoard[0][4] == 0 ||
					(chessBoard[0][4] >= 8 && chessBoard[0][4] <= 14))
				{
					leagelList.push_back({ 0, 4 });
				}
				if (chessBoard[0][6] == 0 ||
					(chessBoard[0][6] >= 8 && chessBoard[0][6] <= 14))
				{
					leagelList.push_back({ 0, 6 });
				}
				if (chessBoard[2][4] == 0 ||
					(chessBoard[2][4] >= 8 && chessBoard[2][4] <= 14))
				{
					leagelList.push_back({ 2, 4 });
				}
				if (chessBoard[2][6] == 0 ||
					(chessBoard[2][6] >= 8 && chessBoard[2][6] <= 14))
				{
					leagelList.push_back({ 2, 6 });
				}
			}
			else if (pos[0] == 2)
			{
				if (chessBoard[1][5] == 0 ||
					(chessBoard[1][5] >= 8 && chessBoard[1][5] <= 14))
				{
					leagelList.push_back({ 1, 5 });
				}
			}
			break;
		default:
			break;
		}
	}
	else if (whoseTurn == 1)
	{

	}
	else
	{
		cout << "Can't find player" << endl;
	}
	return leagelList;
}