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
	vector<vector<int>>legalList;
	if (whoseTurn == 0)
	{
		vector<int>temp(2);
		switch (chessBoard[pos[0]][pos[1]])
		{

		case 1:  //將
		{
			for (int i = max(pos[0] - 1, 0); i <= min(pos[0] + 1, 2); i++)
			{
				for (int j = max(pos[1] - 1, 3); j <= min(pos[1] + 1, 5); j++)
				{
					if (chessBoard[i][j] == 0 ||
						(chessBoard[i][j] >= 8 && chessBoard[i][j] <= 14))
					{
						legalList.push_back({ i,j });
					}
				}
			}
			break;
		}
		case 2:  //士
		{
			if (pos[0] == 0)
			{
				if (chessBoard[1][4] == 0 ||
					(chessBoard[1][4] >= 8 && chessBoard[1][4] <= 14))
				{
					legalList.push_back({ 1, 4 });
				}
			}
			else if (pos[0] == 1)
			{
				if (chessBoard[0][3] == 0 ||
					(chessBoard[0][3] >= 8 && chessBoard[0][3] <= 14))
				{
					legalList.push_back({ 0, 3 });
				}
				if (chessBoard[0][5] == 0 ||
					(chessBoard[0][5] >= 8 && chessBoard[0][5] <= 14))
				{
					legalList.push_back({ 0, 5 });
				}
				if (chessBoard[2][3] == 0 ||
					(chessBoard[2][3] >= 8 && chessBoard[2][3] <= 14))
				{
					legalList.push_back({ 2, 3 });
				}
				if (chessBoard[2][5] == 0 ||
					(chessBoard[2][5] >= 8 && chessBoard[2][5] <= 14))
				{
					legalList.push_back({ 2, 5 });
				}
			}
			else if (pos[0] == 2)
			{
				if (chessBoard[1][4] == 0 ||
					(chessBoard[1][4] >= 8 && chessBoard[1][4] <= 14))
				{
					legalList.push_back({ 1, 4 });
				}
			}
			break;
		}
		case 3:  //象
		{
			for (int i = max(pos[0] - 2, 0); i <= min(pos[0] + 2, 4); i += 2)
			{
				for (int j = max(pos[1] - 2, 0); j <= min(pos[1] + 2, 8); j += 2)
				{
					if ((chessBoard[i][j] == 0 ||
						(chessBoard[i][j] >= 8 && chessBoard[i][j] <= 14)))
					{
						if (i < pos[0] && j < pos[1])
						{
							if (chessBoard[i + 1][j + 1] == 0)
							{
								legalList.push_back({ i,j });
							}
						}
						else if (i < pos[0] && j > pos[1])
						{
							if (chessBoard[i + 1][j - 1] == 0)
							{
								legalList.push_back({ i,j });
							}
						}
						else if (i > pos[0] && j < pos[1])
						{
							if (chessBoard[i - 1][j + 1] == 0)
							{
								legalList.push_back({ i,j });
							}
						}
						else if (i > pos[0] && j > pos[1])
						{
							if (chessBoard[i - 1][j - 1] == 0)
							{
								legalList.push_back({ i,j });
							}
						}
					}
				}
			}
			break;
		}
		case 4:	 //車
		{
			int i = pos[1], j = pos[2];
			while (i >= 0)
			{
				if (legalList[i][j] >= 1 && legalList[i][j] <= 7)
					break;
				else if (legalList[i][j] >= 8 && legalList[i][j] <= 14)
				{
					legalList.push_back({ i,j });
					break;
				}
				else
				{
					legalList.push_back({ i,j });
				}
				i--;
			}
			while (i <= 9)
			{
				if (legalList[i][j] >= 1 && legalList[i][j] <= 7)
					break;
				else if (legalList[i][j] >= 8 && legalList[i][j] <= 14)
				{
					legalList.push_back({ i,j });
					break;
				}
				else
				{
					legalList.push_back({ i,j });
				}
				i++;
			}
			while (i <= 9)
			{
				if (legalList[i][j] >= 1 && legalList[i][j] <= 7)
					break;
				else if (legalList[i][j] >= 8 && legalList[i][j] <= 14)
				{
					legalList.push_back({ i,j });
					break;
				}
				else
				{
					legalList.push_back({ i,j });
				}
				i++;
			}
			while (j >= 0)
			{
				if (legalList[i][j] >= 1 && legalList[i][j] <= 7)
					break;
				else if (legalList[i][j] >= 8 && legalList[i][j] <= 14)
				{
					legalList.push_back({ i,j });
					break;
				}
				else
				{
					legalList.push_back({ i,j });
				}
				j--;
			}
			while (j <= 9)
			{
				if (legalList[i][j] >= 1 && legalList[i][j] <= 7)
					break;
				else if (legalList[i][j] >= 8 && legalList[i][j] <= 14)
				{
					legalList.push_back({ i,j });
					break;
				}
				else
				{
					legalList.push_back({ i,j });
				}
				j++;
			}
			break;
		}
		case 5:  //馬
		{
			if (pos[0] - 1 >= 1 && chessBoard[pos[0] - 1][pos[1]] == 0)
			{
				if (chessBoard[pos[0] - 2][pos[1] - 1] == 0 ||
					(chessBoard[pos[0] - 2][pos[1] - 1] >= 8 && chessBoard[pos[0] - 2][pos[1] - 1] <= 14))
				{
					legalList.push_back({ pos[0] - 2,pos[1] - 1 });
				}
				if (chessBoard[pos[0] - 2][pos[1] + 1] == 0 ||
					(chessBoard[pos[0] - 2][pos[1] + 1] >= 8 && chessBoard[pos[0] - 2][pos[1] + 1] <= 14))
				{
					legalList.push_back({ pos[0] - 2,pos[1] + 1 });
				}
			}
			if (pos[0] + 1 <= 8 && chessBoard[pos[0 + 1]][pos[1]] == 0)
			{
				if (chessBoard[pos[0] + 2][pos[1] - 1] == 0 ||
					(chessBoard[pos[0] + 2][pos[1] - 1] >= 8 && chessBoard[pos[0] + 2][pos[1] - 1] <= 14))
				{
					legalList.push_back({ pos[0] + 2,pos[1] - 1 });
				}
				if (chessBoard[pos[0] + 2][pos[1] + 1] == 0 ||
					(chessBoard[pos[0] + 2][pos[1] + 1] >= 8 && chessBoard[pos[0] + 2][pos[1] + 1] <= 14))
				{
					legalList.push_back({ pos[0] + 2,pos[1] + 1 });
				}
			}
			if (pos[1] - 1 >= 1 && chessBoard[pos[0]][pos[1] - 1] == 0)
			{
				if (chessBoard[pos[0] - 1][pos[1] - 2] == 0 ||
					(chessBoard[pos[0] - 1][pos[1] - 2] >= 8 && chessBoard[pos[0] - 1][pos[1] - 2] <= 14))
				{
					legalList.push_back({ pos[0] - 1,pos[1] - 2 });
				}
				if (chessBoard[pos[0] + 1][pos[1] - 2] == 0 ||
					(chessBoard[pos[0] + 1][pos[1] - 2] >= 8 && chessBoard[pos[0] + 1][pos[1] - 2] <= 14))
				{
					legalList.push_back({ pos[0] + 1,pos[1] - 2 });
				}
			}
			if (pos[1] + 1 <= 7 && chessBoard[pos[0]][pos[1] + 1] == 0)
			{
				if (chessBoard[pos[0] - 1][pos[1] + 2] == 0 ||
					(chessBoard[pos[0] - 1][pos[1] + 2] >= 8 && chessBoard[pos[0] - 1][pos[1] + 2] <= 14))
				{
					legalList.push_back({ pos[0] - 1,pos[1] + 2 });
				}
				if (chessBoard[pos[0] + 1][pos[1] + 2] == 0 ||
					(chessBoard[pos[0] + 1][pos[1] + 2] >= 8 && chessBoard[pos[0] + 1][pos[1] + 2] <= 14))
				{
					legalList.push_back({ pos[0] + 1,pos[1] + 2 });
				}
			}
			break;
		}
		case 6:  //包
		{
			// 向左走
			int x = pos[0];
			int y = pos[1];
			y -= 1;
			while (true)
			{
				// 當第一次遇到 != 0，停止。
				if (chessBoard[x][y] != 0)
				{
					break;
				}
				// 當第一次遇到邊界，停止。
				else if (y == 0)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				// 繼續走，並加入到legalList。
				else
				{
					temp = { x, y };
					legalList.push_back(temp);
					y--;
				}
			}
			// 如果不是邊界則繼續找可以吃的棋子。
			if (y != 0)
			{
				while (true)
				{
					y--;
					// 如果是紅色方則可以吃，停止
					if (chessBoard[x][y] >= 8 && chessBoard[x][y] <= 14)
					{
						temp = { x, y };
						legalList.push_back(temp);
						break;
					}
					// 如果遇到邊界都沒有，停止
					else if (y == 0)
					{
						break;
					}
				}
			}

			// 向右走
			x = pos[0];
			y = pos[1];
			y += 1;
			while (true)
			{
				if (chessBoard[x][y] != 0)
				{
					break;
				}
				else if (y == 8)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else
				{
					temp = { x, y };
					legalList.push_back(temp);
					y++;
				}
			}
			if (y != 8)
			{
				while (true)
				{
					y++;
					if (chessBoard[x][y] >= 8 && chessBoard[x][y] <= 14)
					{
						temp = { x, y };
						legalList.push_back(temp);
						break;
					}
					else if (y == 8)
					{
						break;
					}
				}
			}

			// 向上走
			x = pos[0];
			y = pos[1];
			x -= 1;
			while (true)
			{
				if (chessBoard[x][y] != 0)
				{
					break;
				}
				else if (x == 0)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else
				{
					temp = { x, y };
					legalList.push_back(temp);
					x--;
				}
			}
			if (x != 0)
			{
				while (true)
				{
					x--;
					if (chessBoard[x][y] >= 8 && chessBoard[x][y] <= 14)
					{
						temp = { x, y };
						legalList.push_back(temp);
						break;
					}
					else if (x == 0)
					{
						break;
					}
				}
			}

			// 向下走
			x = pos[0];
			y = pos[1];
			x += 1;
			while (true)
			{
				// 當第一次遇到 != 0，停止。
				if (chessBoard[x][y] != 0)
				{
					break;
				}
				// 當第一次遇到邊界，停止。
				else if (x == 9)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				// 繼續走
				else
				{
					temp = { x, y };
					legalList.push_back(temp);
					x++;
				}
			}
			// 如果不是邊界則繼續找可以吃的棋子。
			if (x != 9)
			{
				while (true)
				{
					x++;
					// 如果是紅色方則可以吃，停止
					if (chessBoard[x][y] >= 8 && chessBoard[x][y] <= 14)
					{
						temp = { x, y };
						legalList.push_back(temp);
						break;
					}
					// 如果遇到邊界都沒有，停止
					else if (x == 9)
					{
						break;
					}
				}
			}
			break;
		}
		case 7:  //卒
		{
			// 有過河
			if (pos[0] >= 5)
			{
				if (pos[0] + 1 <= 9)
				{
					temp = { pos[0] + 1,pos[1] };
					legalList.push_back(temp);
				}
				if (pos[1] - 1 >= 0)
				{
					temp = { pos[0],pos[1] - 1 };
					legalList.push_back(temp);
				}
				if (pos[1] + 1 >= 8)
				{
					temp = { pos[0],pos[1] + 1 };
					legalList.push_back(temp);
				}
				break;
			}
			else if (pos[0] <= 4)
			{
				temp = { pos[0] - 1,pos[1] };
				legalList.push_back(temp);
				break;
			}
		}
		default:
			break;
		}
	}
	else if (whoseTurn == 1)
	{
	vector<int>temp(2);
	switch (chessBoard[pos[0]][pos[1]]-7)
	{

	case 1:  //帥
	{
		for (int i = max(pos[0] - 1, 7); i <= min(pos[0] + 1, 9); i++)
		{
			for (int j = max(pos[1] - 1, 3); j <= min(pos[1] + 1, 5); j++)
			{
				if (chessBoard[i][j] == 0 ||
					(chessBoard[i][j] >= 1 && chessBoard[i][j] <= 7))
				{
					legalList.push_back({ i,j });
				}
			}
		}
		break;
	}
	case 2:  //仕
	{
		if (pos[0] == 9)
		{
			if (chessBoard[8][4] == 0 ||
				(chessBoard[8][4] >= 1 && chessBoard[8][4] <= 7))
			{
				legalList.push_back({ 8, 4 });
			}
		}
		else if (pos[0] == 8)
		{
			if (chessBoard[9][3] == 0 ||
				(chessBoard[9][3] >= 1 && chessBoard[9][3] <= 7))
			{
				legalList.push_back({ 9, 3 });
			}
			if (chessBoard[9][5] == 0 ||
				(chessBoard[9][5] >= 1 && chessBoard[9][5] <= 7))
			{
				legalList.push_back({ 9, 5 });
			}
			if (chessBoard[7][3] == 0 ||
				(chessBoard[7][3] >= 1 && chessBoard[7][3] <= 7))
			{
				legalList.push_back({ 7, 3 });
			}
			if (chessBoard[7][5] == 0 ||
				(chessBoard[7][5] >= 1 && chessBoard[7][5] <= 7))
			{
				legalList.push_back({ 7, 5 });
			}
		}
		else if (pos[0] == 7)
		{
			if (chessBoard[8][4] == 0 ||
				(chessBoard[8][4] >= 1 && chessBoard[8][4] <= 7))
			{
				legalList.push_back({ 8, 4 });
			}
		}
		break;
	}
	case 3:  //相
	{
		for (int i = max(pos[0] - 2, 5); i <= min(pos[0] + 2, 9); i += 2)
		{
			for (int j = max(pos[1] - 2, 0); j <= min(pos[1] + 2, 8); j += 2)
			{
				if ((chessBoard[i][j] == 0 ||
					(chessBoard[i][j] >= 1 && chessBoard[i][j] <= 7)))
				{
					if (i < pos[0] && j < pos[1])
					{
						if (chessBoard[i + 1][j + 1] == 0)
						{
							legalList.push_back({ i,j });
						}
					}
					else if (i < pos[0] && j > pos[1])
					{
						if (chessBoard[i + 1][j - 1] == 0)
						{
							legalList.push_back({ i,j });
						}
					}
					else if (i > pos[0] && j < pos[1])
					{
						if (chessBoard[i - 1][j + 1] == 0)
						{
							legalList.push_back({ i,j });
						}
					}
					else if (i > pos[0] && j > pos[1])
					{
						if (chessBoard[i - 1][j - 1] == 0)
						{
							legalList.push_back({ i,j });
						}
					}
				}
			}
		}
		break;
	}
	case 4:	 //俥
	{
		int i = pos[1], j = pos[2];
		while (i >= 0)
		{
			if (legalList[i][j] >= 8 && legalList[i][j] <= 14)
				break;
			else if (legalList[i][j] >= 1 && legalList[i][j] <= 7)
			{
				legalList.push_back({ i,j });
				break;
			}
			else
			{
				legalList.push_back({ i,j });
			}
			i--;
		}
		while (i <= 9)
		{
			if (legalList[i][j] >= 8 && legalList[i][j] <= 17)
				break;
			else if (legalList[i][j] >= 1 && legalList[i][j] <= 7)
			{
				legalList.push_back({ i,j });
				break;
			}
			else
			{
				legalList.push_back({ i,j });
			}
			i++;
		}
		while (i <= 9)
		{
			if (legalList[i][j] >= 8 && legalList[i][j] <= 14)
				break;
			else if (legalList[i][j] >= 1 && legalList[i][j] <= 7)
			{
				legalList.push_back({ i,j });
				break;
			}
			else
			{
				legalList.push_back({ i,j });
			}
			i++;
		}
		while (j >= 0)
		{
			if (legalList[i][j] >= 8 && legalList[i][j] <= 14)
				break;
			else if (legalList[i][j] >= 1 && legalList[i][j] <= 7)
			{
				legalList.push_back({ i,j });
				break;
			}
			else
			{
				legalList.push_back({ i,j });
			}
			j--;
		}
		while (j <= 9)
		{
			if (legalList[i][j] >= 8 && legalList[i][j] <= 14)
				break;
			else if (legalList[i][j] >= 1 && legalList[i][j] <= 7)
			{
				legalList.push_back({ i,j });
				break;
			}
			else
			{
				legalList.push_back({ i,j });
			}
			j++;
		}
		break;
	}
	case 5:  //傌
	{
		if (pos[0] - 1 >= 1 && chessBoard[pos[0] - 1][pos[1]] == 0)
		{
			if (chessBoard[pos[0] - 2][pos[1] - 1] == 0 ||
				(chessBoard[pos[0] - 2][pos[1] - 1] >= 1 && chessBoard[pos[0] - 2][pos[1] - 1] <= 7))
			{
				legalList.push_back({ pos[0] - 2,pos[1] - 1 });
			}
			if (chessBoard[pos[0] - 2][pos[1] + 1] == 0 ||
				(chessBoard[pos[0] - 2][pos[1] + 1] >= 1 && chessBoard[pos[0] - 2][pos[1] + 1] <= 7))
			{
				legalList.push_back({ pos[0] - 2,pos[1] + 1 });
			}
		}
		if (pos[0] + 1 <= 8 && chessBoard[pos[0 + 1]][pos[1]] == 0)
		{
			if (chessBoard[pos[0] + 2][pos[1] - 1] == 0 ||
				(chessBoard[pos[0] + 2][pos[1] - 1] >= 1 && chessBoard[pos[0] + 2][pos[1] - 1] <= 7))
			{
				legalList.push_back({ pos[0] + 2,pos[1] - 1 });
			}
			if (chessBoard[pos[0] + 2][pos[1] + 1] == 0 ||
				(chessBoard[pos[0] + 2][pos[1] + 1] >= 1 && chessBoard[pos[0] + 2][pos[1] + 1] <= 7))
			{
				legalList.push_back({ pos[0] + 2,pos[1] + 1 });
			}
		}
		if (pos[1] - 1 >= 1 && chessBoard[pos[0]][pos[1] - 1] == 0)
		{
			if (chessBoard[pos[0] - 1][pos[1] - 2] == 0 ||
				(chessBoard[pos[0] - 1][pos[1] - 2] >= 1 && chessBoard[pos[0] - 1][pos[1] - 2] <= 7))
			{
				legalList.push_back({ pos[0] - 1,pos[1] - 2 });
			}
			if (chessBoard[pos[0] + 1][pos[1] - 2] == 0 ||
				(chessBoard[pos[0] + 1][pos[1] - 2] >= 1 && chessBoard[pos[0] + 1][pos[1] - 2] <= 7))
			{
				legalList.push_back({ pos[0] + 1,pos[1] - 2 });
			}
		}
		if (pos[1] + 1 <= 7 && chessBoard[pos[0]][pos[1] + 1] == 0)
		{
			if (chessBoard[pos[0] - 1][pos[1] + 2] == 0 ||
				(chessBoard[pos[0] - 1][pos[1] + 2] >= 1 && chessBoard[pos[0] - 1][pos[1] + 2] <= 7))
			{
				legalList.push_back({ pos[0] - 1,pos[1] + 2 });
			}
			if (chessBoard[pos[0] + 1][pos[1] + 2] == 0 ||
				(chessBoard[pos[0] + 1][pos[1] + 2] >= 1 && chessBoard[pos[0] + 1][pos[1] + 2] <= 7))
			{
				legalList.push_back({ pos[0] + 1,pos[1] + 2 });
			}
		}
		break;
	}
	case 6:  //炮
	{
		// 向左走
		int x = pos[0];
		int y = pos[1];
		y -= 1;
		while (true)
		{
			// 當第一次遇到 != 0，停止。
			if (chessBoard[x][y] != 0)
			{
				break;
			}
			// 當第一次遇到邊界，停止。
			else if (y == 0)
			{
				temp = { x, y };
				legalList.push_back(temp);
				break;
			}
			// 繼續走，並加入到legalList。
			else
			{
				temp = { x, y };
				legalList.push_back(temp);
				y--;
			}
		}
		// 如果不是邊界則繼續找可以吃的棋子。
		if (y != 0)
		{
			while (true)
			{
				y--;
				// 如果是黑色方則可以吃，停止
				if (chessBoard[x][y] >= 1 && chessBoard[x][y] <= 7)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				// 如果遇到邊界都沒有，停止
				else if (y == 0)
				{
					break;
				}
			}
		}

		// 向右走
		x = pos[0];
		y = pos[1];
		y += 1;
		while (true)
		{
			if (chessBoard[x][y] != 0)
			{
				break;
			}
			else if (y == 8)
			{
				temp = { x, y };
				legalList.push_back(temp);
				break;
			}
			else
			{
				temp = { x, y };
				legalList.push_back(temp);
				y++;
			}
		}
		if (y != 8)
		{
			while (true)
			{
				y++;
				if (chessBoard[x][y] >= 1 && chessBoard[x][y] <= 7)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else if (y == 8)
				{
					break;
				}
			}
		}

		// 向上走
		x = pos[0];
		y = pos[1];
		x -= 1;
		while (true)
		{
			if (chessBoard[x][y] != 0)
			{
				break;
			}
			else if (x == 0)
			{
				temp = { x, y };
				legalList.push_back(temp);
				break;
			}
			else
			{
				temp = { x, y };
				legalList.push_back(temp);
				x--;
			}
		}
		if (x != 0)
		{
			while (true)
			{
				x--;
				if (chessBoard[x][y] >= 1 && chessBoard[x][y] <= 7)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else if (x == 0)
				{
					break;
				}
			}
		}

		// 向下走
		x = pos[0];
		y = pos[1];
		x += 1;
		while (true)
		{
			// 當第一次遇到 != 0，停止。
			if (chessBoard[x][y] != 0)
			{
				break;
			}
			// 當第一次遇到邊界，停止。
			else if (x == 9)
			{
				temp = { x, y };
				legalList.push_back(temp);
				break;
			}
			// 繼續走
			else
			{
				temp = { x, y };
				legalList.push_back(temp);
				x++;
			}
		}
		// 如果不是邊界則繼續找可以吃的棋子。
		if (x != 9)
		{
			while (true)
			{
				x++;
				// 如果是黑色方則可以吃，停止
				if (chessBoard[x][y] >= 1 && chessBoard[x][y] <= 7)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				// 如果遇到邊界都沒有，停止
				else if (x == 9)
				{
					break;
				}
			}
		}
		break;
	}
	case 7:  //卒
	{
		// 有過河
		if (pos[0] <= 4)
		{
			if (pos[0] + 1 >= 0)
			{
				temp = { pos[0] + 1,pos[1] };
				legalList.push_back(temp);
			}
			if (pos[1] - 1 >= 0)
			{
				temp = { pos[0],pos[1] - 1 };
				legalList.push_back(temp);
			}
			if (pos[1] + 1 >= 8)
			{
				temp = { pos[0],pos[1] + 1 };
				legalList.push_back(temp);
			}
			break;
		}
		else if (pos[0] >= 5)
		{
			temp = { pos[0] - 1,pos[1] };
			legalList.push_back(temp);
			break;
		}
	}
	default:
		break;
	}
	}
	else
	{
		cout << "Can't find player" << endl;
	}
	return legalList;
}