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
		// �P�_���S���N�x�A�C�����S������
		// push back stack
		// show ����
	};
	void renewOutput();
};