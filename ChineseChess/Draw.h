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
	void showOutput();			// show 邊框 + 戰況 + 棋盤 + 提醒黑紅方下棋 + 操作提示。
	void showHint(vector<vector<int>>legalList);
	void renewChess(vector<int>start, vector<int>end)
	{
		// 更新 chessboard 跟 更新 chessStep。
		// 判斷有沒有將軍，遊戲有沒有結束
	};

	void renewRight();
	void renewLeft();
	void renewChessPart();
	void renewCarOrder();
};

#endif // DRAW_H

