#ifndef CHESS_H
#define CHESS_H

using namespace std;
class Chess
{
public:
	static vector<vector<int>>chessBoard;
private:
	vector<vector<vector<int>>> chessRecord; //¾ú¥v¬ö¿ýtable
	vector<string> chessStep; //´ÑÃÐ
	vector<vector<int>> legalMoveSpace;
	int whoseTurn = 0;
	int stepNumber = 0;
	void recordChessStep(vector<int>ori, vector<int>des);
public:
	friend class Draw;
	Chess(string filename);
	vector<int> selectedChess();
	vector<vector<int>> whereCanGO(vector<int> pos);
	vector<int> moveChess(vector<int> pos);
	void readBoard(string fileName);
	void saveBoard(string fileName);
	void nextPlayer();
};


#endif // CHESS_H