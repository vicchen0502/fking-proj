#pragma once
#include"pch.h"
using namespace std;
class Chess
{
private:
	vector<vector<int>>chessBoard;
	vector<vector<vector<int>>> chessRecord; //¾ú¥v¬ö¿ýtable
	vector<string> chessStep; //´ÑÃÐ
	int whoseTurn;
public:
	Chess(string filename);
	vector<int> selectedChess();
	vector<int> moveChess();
	void readBoard(string fileName);
	void saveBoard(string fileName);
};
