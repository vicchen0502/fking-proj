#ifndef DRAW_H
#define DRAW_H

//#include"pch.h"
//#include"chess.h"

using namespace std;
class Draw
{
private:
	vector<int>carList;
	vector<string>chessPart;
	vector<string>leftPart;
	vector<string>rightPart;
public:
	friend class Chess;
	void showOutput();			// show ��� + �Ԫp + �ѽL + �����¬���U�� + �ާ@���ܡC
	void showHint(vector<vector<int>>legalList);
	void renewChess(vector<int>start, vector<int>end)
	{
		// ��s chessboard �� ��s chessStep�C
		// �P�_���S���N�x�A�C�����S������
	};

	void renewRight();
	void renewLeft();
	void renewChessPart();
	void renewCarOrder();
};

#endif // DRAW_H

