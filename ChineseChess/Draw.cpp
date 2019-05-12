#include"pch.h"
#include"chess.h"
#include"Draw.h"

vector<vector<int>> Chess::chessBoard = {};

void Draw::renewChessPart()
{
	// 一行一行去重做一個 String.
	// Ex: 第一行的第一列為 0，則 append "╔*═*"  (*代表 空白)
	vector<string>rowString(10);
	chessPart = intialBoard(chessPart);
	string temp;
	for (int i = 0; i < Chess::chessBoard.size(); i++)
	{
		temp = "";
		for (int j = 0; j < Chess::chessBoard[i].size(); j++)
		{
			// 討論各行狀況 (p.s. 這裡用很多重複的code，如果這個 function 之後還會用的到，再來修改，來減少行數)
			if (i == 0)
			{
				if (j == 8)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("╗ ");
						break;
					case 1:
						temp.append("將");
						break;
					case 2:
						temp.append("士");
						break;
					case 3:
						temp.append("象");
						break;
					case 4:
						temp.append("車");
						break;
					case 5:
						temp.append("馬");
						break;
					case 6:
						temp.append("包");
						break;
					case 7:
						temp.append("卒");
						break;
					case 8:
						temp.append("帥");
						break;
					case 9:
						temp.append("仕");
						break;
					case 10:
						temp.append("相");
						break;
					case 11:
						temp.append("車");
						break;
					case 12:
						temp.append("傌");
						break;
					case 13:
						temp.append("炮");
						break;
					case 14:
						temp.append("兵");
						break;
					}
				}
				else if (j == 0)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("╔ ═ ");
						break;
					case 1:
						temp.append("將═ ");
						break;
					case 2:
						temp.append("士═ ");
						break;
					case 3:
						temp.append("象═ ");
						break;
					case 4:
						temp.append("車═ ");
						break;
					case 5:
						temp.append("馬═ ");
						break;
					case 6:
						temp.append("包═ ");
						break;
					case 7:
						temp.append("卒═ ");
						break;
					case 8:
						temp.append("帥═ ");
						break;
					case 9:
						temp.append("仕═ ");
						break;
					case 10:
						temp.append("相═ ");
						break;
					case 11:
						temp.append("車═ ");
						break;
					case 12:
						temp.append("傌═ ");
						break;
					case 13:
						temp.append("炮═ ");
						break;
					case 14:
						temp.append("兵═ ");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("═ ═ ");
						break;
					case 1:
						temp.append("將═ ");
						break;
					case 2:
						temp.append("士═ ");
						break;
					case 3:
						temp.append("象═ ");
						break;
					case 4:
						temp.append("車═ ");
						break;
					case 5:
						temp.append("馬═ ");
						break;
					case 6:
						temp.append("包═ ");
						break;
					case 7:
						temp.append("卒═ ");
						break;
					case 8:
						temp.append("帥═ ");
						break;
					case 9:
						temp.append("仕═ ");
						break;
					case 10:
						temp.append("相═ ");
						break;
					case 11:
						temp.append("車═ ");
						break;
					case 12:
						temp.append("傌═ ");
						break;
					case 13:
						temp.append("炮═ ");
						break;
					case 14:
						temp.append("兵═ ");
						break;
					}
				}
			}
			else if (i == 4)
			{
				if (j == 8)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("║ ");
						break;
					case 1:
						temp.append("將");
						break;
					case 2:
						temp.append("士");
						break;
					case 3:
						temp.append("象");
						break;
					case 4:
						temp.append("車");
						break;
					case 5:
						temp.append("馬");
						break;
					case 6:
						temp.append("包");
						break;
					case 7:
						temp.append("卒");
						break;
					case 8:
						temp.append("帥");
						break;
					case 9:
						temp.append("仕");
						break;
					case 10:
						temp.append("相");
						break;
					case 11:
						temp.append("車");
						break;
					case 12:
						temp.append("傌");
						break;
					case 13:
						temp.append("炮");
						break;
					case 14:
						temp.append("兵");
						break;
					}
				}
				else if (j == 0)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("║ ─ ");
						break;
					case 1:
						temp.append("將─ ");
						break;
					case 2:
						temp.append("士─ ");
						break;
					case 3:
						temp.append("象─ ");
						break;
					case 4:
						temp.append("車─ ");
						break;
					case 5:
						temp.append("馬─ ");
						break;
					case 6:
						temp.append("包─ ");
						break;
					case 7:
						temp.append("卒─ ");
						break;
					case 8:
						temp.append("帥─ ");
						break;
					case 9:
						temp.append("仕─ ");
						break;
					case 10:
						temp.append("相─ ");
						break;
					case 11:
						temp.append("車─ ");
						break;
					case 12:
						temp.append("傌─ ");
						break;
					case 13:
						temp.append("炮─ ");
						break;
					case 14:
						temp.append("兵─ ");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("┴ ─ ");
						break;
					case 1:
						temp.append("將─ ");
						break;
					case 2:
						temp.append("士─ ");
						break;
					case 3:
						temp.append("象─ ");
						break;
					case 4:
						temp.append("車─ ");
						break;
					case 5:
						temp.append("馬─ ");
						break;
					case 6:
						temp.append("包─ ");
						break;
					case 7:
						temp.append("卒─ ");
						break;
					case 8:
						temp.append("帥─ ");
						break;
					case 9:
						temp.append("仕─ ");
						break;
					case 10:
						temp.append("相─ ");
						break;
					case 11:
						temp.append("車─ ");
						break;
					case 12:
						temp.append("傌─ ");
						break;
					case 13:
						temp.append("炮─ ");
						break;
					case 14:
						temp.append("兵─ ");
						break;
					}
				}
			}
			else if (i == 5)
			{
				if (j == 0)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("║ ─ ");
						break;
					case 1:
						temp.append("將─ ");
						break;
					case 2:
						temp.append("士─ ");
						break;
					case 3:
						temp.append("象─ ");
						break;
					case 4:
						temp.append("車─ ");
						break;
					case 5:
						temp.append("馬─ ");
						break;
					case 6:
						temp.append("包─ ");
						break;
					case 7:
						temp.append("卒─ ");
						break;
					case 8:
						temp.append("帥─ ");
						break;
					case 9:
						temp.append("仕─ ");
						break;
					case 10:
						temp.append("相─ ");
						break;
					case 11:
						temp.append("車─ ");
						break;
					case 12:
						temp.append("傌─ ");
						break;
					case 13:
						temp.append("炮─ ");
						break;
					case 14:
						temp.append("兵─ ");
						break;
					}
				}
				else if (j == 8)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("║ ");
						break;
					case 1:
						temp.append("將");
						break;
					case 2:
						temp.append("士");
						break;
					case 3:
						temp.append("象");
						break;
					case 4:
						temp.append("車");
						break;
					case 5:
						temp.append("馬");
						break;
					case 6:
						temp.append("包");
						break;
					case 7:
						temp.append("卒");
						break;
					case 8:
						temp.append("帥");
						break;
					case 9:
						temp.append("仕");
						break;
					case 10:
						temp.append("相");
						break;
					case 11:
						temp.append("車");
						break;
					case 12:
						temp.append("傌");
						break;
					case 13:
						temp.append("炮");
						break;
					case 14:
						temp.append("兵");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("┬ ─ ");
						break;
					case 1:
						temp.append("將─ ");
						break;
					case 2:
						temp.append("士─ ");
						break;
					case 3:
						temp.append("象─ ");
						break;
					case 4:
						temp.append("車─ ");
						break;
					case 5:
						temp.append("馬─ ");
						break;
					case 6:
						temp.append("包─ ");
						break;
					case 7:
						temp.append("卒─ ");
						break;
					case 8:
						temp.append("帥─ ");
						break;
					case 9:
						temp.append("仕─ ");
						break;
					case 10:
						temp.append("相─ ");
						break;
					case 11:
						temp.append("車─ ");
						break;
					case 12:
						temp.append("傌─ ");
						break;
					case 13:
						temp.append("炮─ ");
						break;
					case 14:
						temp.append("兵─ ");
						break;
					}
				}
			}
			else if (i == 9)
			{
				if (j == 0)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("╚ ═ ");
						break;
					case 1:
						temp.append("將═ ");
						break;
					case 2:
						temp.append("士═ ");
						break;
					case 3:
						temp.append("象═ ");
						break;
					case 4:
						temp.append("車═ ");
						break;
					case 5:
						temp.append("馬═ ");
						break;
					case 6:
						temp.append("包═ ");
						break;
					case 7:
						temp.append("卒═ ");
						break;
					case 8:
						temp.append("帥═ ");
						break;
					case 9:
						temp.append("仕═ ");
						break;
					case 10:
						temp.append("相═ ");
						break;
					case 11:
						temp.append("車═ ");
						break;
					case 12:
						temp.append("傌═ ");
						break;
					case 13:
						temp.append("炮═ ");
						break;
					case 14:
						temp.append("兵═ ");
						break;
					}
				}
				else if (j == 8)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("╝ ");
						break;
					case 1:
						temp.append("將");
						break;
					case 2:
						temp.append("士");
						break;
					case 3:
						temp.append("象");
						break;
					case 4:
						temp.append("車");
						break;
					case 5:
						temp.append("馬");
						break;
					case 6:
						temp.append("包");
						break;
					case 7:
						temp.append("卒");
						break;
					case 8:
						temp.append("帥");
						break;
					case 9:
						temp.append("仕");
						break;
					case 10:
						temp.append("相");
						break;
					case 11:
						temp.append("車");
						break;
					case 12:
						temp.append("傌");
						break;
					case 13:
						temp.append("炮");
						break;
					case 14:
						temp.append("兵");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("═ ═ ");
						break;
					case 1:
						temp.append("將═ ");
						break;
					case 2:
						temp.append("士═ ");
						break;
					case 3:
						temp.append("象═ ");
						break;
					case 4:
						temp.append("車═ ");
						break;
					case 5:
						temp.append("馬═ ");
						break;
					case 6:
						temp.append("包═ ");
						break;
					case 7:
						temp.append("卒═ ");
						break;
					case 8:
						temp.append("帥═ ");
						break;
					case 9:
						temp.append("仕═ ");
						break;
					case 10:
						temp.append("相═ ");
						break;
					case 11:
						temp.append("車═ ");
						break;
					case 12:
						temp.append("傌═ ");
						break;
					case 13:
						temp.append("炮═ ");
						break;
					case 14:
						temp.append("兵═ ");
						break;
					}
				}
			}
			else if (1 <= i <= 3 || 6 <= i <= 8)
			{
				if (j == 8)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("║ ");
						break;
					case 1:
						temp.append("將");
						break;
					case 2:
						temp.append("士");
						break;
					case 3:
						temp.append("象");
						break;
					case 4:
						temp.append("車");
						break;
					case 5:
						temp.append("馬");
						break;
					case 6:
						temp.append("包");
						break;
					case 7:
						temp.append("卒");
						break;
					case 8:
						temp.append("帥");
						break;
					case 9:
						temp.append("仕");
						break;
					case 10:
						temp.append("相");
						break;
					case 11:
						temp.append("車");
						break;
					case 12:
						temp.append("傌");
						break;
					case 13:
						temp.append("炮");
						break;
					case 14:
						temp.append("兵");
						break;
					}
				}
				else if (j == 0)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("║ ─ ");
						break;
					case 1:
						temp.append("將─ ");
						break;
					case 2:
						temp.append("士─ ");
						break;
					case 3:
						temp.append("象─ ");
						break;
					case 4:
						temp.append("車─ ");
						break;
					case 5:
						temp.append("馬─ ");
						break;
					case 6:
						temp.append("包─ ");
						break;
					case 7:
						temp.append("卒─ ");
						break;
					case 8:
						temp.append("帥─ ");
						break;
					case 9:
						temp.append("仕─ ");
						break;
					case 10:
						temp.append("相─ ");
						break;
					case 11:
						temp.append("車─ ");
						break;
					case 12:
						temp.append("傌─ ");
						break;
					case 13:
						temp.append("炮─ ");
						break;
					case 14:
						temp.append("兵─ ");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("┼ ─ ");
						break;
					case 1:
						temp.append("將─ ");
						break;
					case 2:
						temp.append("士─ ");
						break;
					case 3:
						temp.append("象─ ");
						break;
					case 4:
						temp.append("車─ ");
						break;
					case 5:
						temp.append("馬─ ");
						break;
					case 6:
						temp.append("包─ ");
						break;
					case 7:
						temp.append("卒─ ");
						break;
					case 8:
						temp.append("帥─ ");
						break;
					case 9:
						temp.append("仕─ ");
						break;
					case 10:
						temp.append("相─ ");
						break;
					case 11:
						temp.append("車─ ");
						break;
					case 12:
						temp.append("傌─ ");
						break;
					case 13:
						temp.append("炮─ ");
						break;
					case 14:
						temp.append("兵─ ");
						break;
					}
				}
			}
		}
		// 把每行讀進暫存的 vector <string>
		rowString[i] = temp;
	}
	// 把 rowString 讀進基數行的 chessBoard
	for (int i = 0; i < 10; i++)
	{
		Draw::chessPart[2 * i + 1] = rowString[i];
	}
	renewCarOrder();
}

void Draw::renewLeft()
{
	leftPart = initialSituation(leftPart);
	//int i
}

void Draw::renewRight()
{
	rightPart = initialRight(rightPart);
	// 後面再持續更新
}

void Draw::renewCarOrder()
{
	carList.clear();
	for (int i = 0; i < Chess::chessBoard.size(); i++)
	{
		for (int j = 0; j < Chess::chessBoard[i].size(); j++)
		{
			if (Chess::chessBoard[i][j] == 4)
			{
				carList.push_back(0);
			}
			else if (Chess::chessBoard[i][j] == 11)
			{
				carList.push_back(1);
			}
		}
	}
}

void Draw::showOutput()
{
	string wordBlack = "將士象馬包卒";
	string wordRed = "帥仕相傌炮兵";
	string car = "車";
	int count = 0;

	system("color 0f");
	cout << "╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗ " << endl;
	for (int i = 0; i < 21; i++)
	{
		SetColor(15);
		cout << "║ " << leftPart[i] << "　";
		// 棋盤部分
		SetColor(240);
		for (int j = 0; j < chessPart[i].size(); j++)
		{
			if (i == 0 || i == 20)
			{
				SetColor(253);
				cout << chessPart[i][j];
			}
			else
			{
				if (find(wordRed.begin(), wordRed.end(), chessPart[i][j]) != wordRed.end())
				{
					SetColor(124);
					cout << chessPart[i][j];
				}
				else if (find(wordBlack.begin(), wordBlack.end(), chessPart[i][j]) != wordBlack.end())
				{
					SetColor(112);
					cout << chessPart[i][j];
				}
				else if (find(car.begin(), car.end(), chessPart[i][j]) != car.end())
				{
					if (carList[count] == 0)
					{
						SetColor(112);
						cout << chessPart[i][j];
						count++;
					}
					else if (carList[count] == 1)
					{
						SetColor(124);
						cout << chessPart[i][j];
						count++;
					}
				}
				else
				{
					SetColor(240);
					cout << chessPart[i][j];
				}
			}
		}
		SetColor(15);
		cout << "　" << rightPart[i] << "　║ " << endl;
	}
	cout << "╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝ " << endl;
}

void Draw::showHint(vector<vector<int>>legalList)
{
	SetColor(208);
	for (int i = 0; i < legalList.size(); i++)
	{
		string word = "將士象馬包卒帥仕相傌炮兵車";
		//string sign = "┼┴┬╔╗╚╝═║";

		int x = legalList[i][0];
		int y = legalList[i][1];

		int X = (y * 4) + 30;
		int Y = (x * 2) + 2;

		gotoxy(X, Y);
		if (Chess::chessBoard[x][y] == 0 && y == 0)
		{
			if (x == 0)
			{
				cout << "╔ " << endl;
			}
			else if (x == 9)
			{
				cout << "╚ " << endl;
			}
			else
			{
				cout << "║ " << endl;
			}
		}
		else if (Chess::chessBoard[x][y] == 0 && y == 8)
		{
			if (x == 0)
			{
				cout << "╗ " << endl;
			}
			else if (x == 9)
			{
				cout << "╝ " << endl;
			}
			else
			{
				cout << "║ " << endl;
			}
		}
		else if (Chess::chessBoard[x][y] == 0)
		{
			cout << "┼ " << endl;
		}
		else
		{
			switch (Chess::chessBoard[x][y])
			{
			case 1:
				cout << "將" << endl;
				break;
			case 2:
				cout << "士" << endl;
				break;
			case 3:
				cout << "象" << endl;
				break;
			case 4:
				cout << "車" << endl;
				break;
			case 5:
				cout << "馬" << endl;
				break;
			case 6:
				cout << "包" << endl;
				break;
			case 7:
				cout << "卒" << endl;
				break;
			case 8:
				cout << "帥" << endl;
				break;
			case 9:
				cout << "仕" << endl;
				break;
			case 10:
				cout << "相" << endl;
				break;
			case 11:
				cout << "車" << endl;
				break;
			case 12:
				cout << "傌" << endl;
				break;
			case 13:
				cout << "炮" << endl;
				break;
			case 14:
				cout << "兵" << endl;
				break;
			}
		}
	}
}
