#ifndef CHESS_H
#define CHESS_H

using namespace std;
class Chess
{
public:
	static vector<vector<int>>chessBoard;
private:
	vector<vector<vector<int>>> chessRecord; //���v����table
	static vector<string> chessStep; //����
	vector<vector<int>> legalMoveSpace;
	static int whoseTurn ;
	static int stepNumber ;
	static void recordChessStep(vector<int>ori, vector<int>des);
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