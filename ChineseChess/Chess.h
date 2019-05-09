#pragma once
#include"pch.h"
using namespace std;
class Chess
{
private:
	vector<vector<int>>chessBoard;
	vector<vector<vector<int>>> chessRecord; //���v����table
	vector<string> chessStep; //����
	int whoseTurn;
public:
	Chess(string filename);
	vector<int> selectedChess();
	vector<int> moveChess();
	void readBoard(string fileName);
	void saveBoard(string fileName);
};
