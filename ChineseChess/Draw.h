#pragma once
#include"pch.h"
#include"Chess.h"
using namespace std;
class Draw
{
private:
	vector<string>chessBoard;
	vector<string>leftPart;
	vector<string>rightPart;
public:
	friend Chess;
	void showHint(vector<int>pos);
	void renewChess(vector<int>pos);
};