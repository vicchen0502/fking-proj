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
	vector<COORD> leagelMoveSpace;
	int whoseTurn = 0;

public:
	friend class Draw;
	Chess(string filename);
	vector<int> selectedChess();
	vector<vector<int>> whereCanGO(vector<int> pos);
	vector<int> moveChess();
	void readBoard(string fileName);
	void saveBoard(string fileName);
};


#endif // CHESS_H