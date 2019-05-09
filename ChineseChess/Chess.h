#pragma once
#include"pch.h"
using namespace std;
class Chess
{
private:
	vector<vector<int>>chessBoard();
public:
	vector<int> selectedChess();
	vector<int> moveChess();
};
