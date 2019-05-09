#pragma once
#include"pch.h"
#include"Chess.h"
using namespace std;
class Draw
{
private:
	vector<string>chessPart;
	vector<string>leftPart;
	vector<string>rightPart;
public:
	friend Chess;
	void showHint(vector<int>pos);
	void renewChess(vector<int>pos)
	{
		// modify Chess.chessBoard
		renewOutput();
		// 判斷有沒有將軍，遊戲有沒有結束
		// push back stack
		// show 棋譜
	};
	void renewOutput();
};