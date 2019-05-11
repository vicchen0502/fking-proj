#include"pch.h"
#include"chess.h"
#include"Draw.h"

vector<vector<int>> Chess::chessBoard = {};

void Draw::renewOutput()
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
	for (int i = 0; i < 21; i++)
	{
		cout << Draw::chessPart[i] << endl;
	}
}

