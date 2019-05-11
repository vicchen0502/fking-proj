#ifndef CHESS_H
#define CHESS_H

using namespace std;
class Chess
{
private:
	static vector<vector<int>>chessBoard;
	vector<vector<vector<int>>> chessRecord; //¾ú¥v¬ö¿ýtable
	vector<string> chessStep; //´ÑÃÐ
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