#include "pch.h"
#include "Chess.h"

// 利用巨集先定義 上,下,左,右,ESC
#define ESC	27
#define DIRECTION_KEYBOARD	224
#define UP     72
#define DOWN   80
#define LEFT   75
#define RIGHT  77
#define ENTER 13

using namespace std;

void gotoxy(int x, int y);
void SetCursorVisible(BOOL _bVisible, DWORD _dwSize);
//class Chess
Chess::Chess(string filename)
{
	filename = "Initial.txt";
	ifstream fin(filename);
	for (int i = 0; i < 10; i++)
	{
		vector<int> temp;
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
	while (1)
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
				coordInData.Y -= 1;
				break;
			case DOWN:
				if (Y == 19)
					break;
				Y = Y + 2;
				gotoxy(X, Y);
				coordInData.Y += 1;
				break;
			case LEFT:
				if (X == 0)
					break;
				X = X - 4;
				gotoxy(X, Y);
				coordInData.X -= 1;
				break;
			case RIGHT:
				if (X == 32)
					break;
				X = X + 4;
				gotoxy(X, Y);
				coordInData.X += 1;
				break;
			}

		}
		else if (ch1 == ENTER)
		{
			func = ENTER;

			break;
		}
	}
	vector<int> position = { -1,-1 };
	switch (func)
	{
	case ESC:
		return position;
		break;
	case ENTER:
		position[0] = coordInData.X;
		position[1] = coordInData.Y;
		return position;
		break;
	default:
		return position;
		break;
	}
	
}


// 游標移動 "至" (x, y)  
void gotoxy(int x, int y)
{
	COORD point;
	point.X = x; point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

// 設定游標的樣式
void SetCursorVisible(BOOL _bVisible, DWORD _dwSize)
{
	CONSOLE_CURSOR_INFO CCI;
	CCI.bVisible = _bVisible;
	CCI.dwSize = _dwSize;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CCI);
}