#ifndef DRAW_H
#define DRAW_H

//#include"pch.h"
//#include"chess.h"

using namespace std;
class Draw
{
private:
	vector<string>chessPart;
	vector<string>leftPart;
	vector<string>rightPart;
public:
	//friend class Chess;
	void showHint(vector<vector<int>>legalMove);
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

#endif // DRAW_H

