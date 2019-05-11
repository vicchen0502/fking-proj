#ifndef CHESS_H
#define CHESS_H

using namespace std;
class Chess
{
private:
	static vector<vector<int>>chessBoard;
	vector<vector<vector<int>>> chessRecord; //���v����table
	vector<string> chessStep; //����
	int whoseTurn;

public:
	friend class Draw;
	Chess(string filename);
	vector<int> selectedChess();
	vector<int> moveChess();
	void readBoard(string fileName);
	void saveBoard(string fileName);
};


#endif // CHESS_H