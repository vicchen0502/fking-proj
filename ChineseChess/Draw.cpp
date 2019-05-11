#include"pch.h"
#include"chess.h"
#include"Draw.h"

vector<vector<int>> Chess::chessBoard = {};

void Draw::renewOutput()
{

	// �@��@��h�����@�� String.
	// Ex: �Ĥ@�檺�Ĥ@�C�� 0�A�h append "��*��*"  (*�N�� �ť�)
	vector<string>rowString(10);
	chessPart = intialBoard(chessPart);
	string temp;
	for (int i = 0; i < Chess::chessBoard.size(); i++)
	{
		temp = "";
		for (int j = 0; j < Chess::chessBoard[i].size(); j++)
		{
			// �Q�צU�檬�p (p.s. �o�̥Ϋܦh���ƪ�code�A�p�G�o�� function �����ٷ|�Ϊ���A�A�ӭק�A�Ӵ�֦��)
			if (i == 0)
			{
				if (j == 8)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� ");
						break;
					case 1:
						temp.append("�N");
						break;
					case 2:
						temp.append("�h");
						break;
					case 3:
						temp.append("�H");
						break;
					case 4:
						temp.append("��");
						break;
					case 5:
						temp.append("��");
						break;
					case 6:
						temp.append("�]");
						break;
					case 7:
						temp.append("��");
						break;
					case 8:
						temp.append("��");
						break;
					case 9:
						temp.append("�K");
						break;
					case 10:
						temp.append("��");
						break;
					case 11:
						temp.append("��");
						break;
					case 12:
						temp.append("�X");
						break;
					case 13:
						temp.append("��");
						break;
					case 14:
						temp.append("�L");
						break;
					}
				}
				else if (j == 0)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� �� ");
						break;
					case 1:
						temp.append("�N�� ");
						break;
					case 2:
						temp.append("�h�� ");
						break;
					case 3:
						temp.append("�H�� ");
						break;
					case 4:
						temp.append("���� ");
						break;
					case 5:
						temp.append("���� ");
						break;
					case 6:
						temp.append("�]�� ");
						break;
					case 7:
						temp.append("���� ");
						break;
					case 8:
						temp.append("���� ");
						break;
					case 9:
						temp.append("�K�� ");
						break;
					case 10:
						temp.append("���� ");
						break;
					case 11:
						temp.append("���� ");
						break;
					case 12:
						temp.append("�X�� ");
						break;
					case 13:
						temp.append("���� ");
						break;
					case 14:
						temp.append("�L�� ");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� �� ");
						break;
					case 1:
						temp.append("�N�� ");
						break;
					case 2:
						temp.append("�h�� ");
						break;
					case 3:
						temp.append("�H�� ");
						break;
					case 4:
						temp.append("���� ");
						break;
					case 5:
						temp.append("���� ");
						break;
					case 6:
						temp.append("�]�� ");
						break;
					case 7:
						temp.append("���� ");
						break;
					case 8:
						temp.append("���� ");
						break;
					case 9:
						temp.append("�K�� ");
						break;
					case 10:
						temp.append("���� ");
						break;
					case 11:
						temp.append("���� ");
						break;
					case 12:
						temp.append("�X�� ");
						break;
					case 13:
						temp.append("���� ");
						break;
					case 14:
						temp.append("�L�� ");
						break;
					}
				}
			}
			else if (i == 4)
			{
				if (j == 8)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� ");
						break;
					case 1:
						temp.append("�N");
						break;
					case 2:
						temp.append("�h");
						break;
					case 3:
						temp.append("�H");
						break;
					case 4:
						temp.append("��");
						break;
					case 5:
						temp.append("��");
						break;
					case 6:
						temp.append("�]");
						break;
					case 7:
						temp.append("��");
						break;
					case 8:
						temp.append("��");
						break;
					case 9:
						temp.append("�K");
						break;
					case 10:
						temp.append("��");
						break;
					case 11:
						temp.append("��");
						break;
					case 12:
						temp.append("�X");
						break;
					case 13:
						temp.append("��");
						break;
					case 14:
						temp.append("�L");
						break;
					}
				}
				else if (j == 0)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� �w ");
						break;
					case 1:
						temp.append("�N�w ");
						break;
					case 2:
						temp.append("�h�w ");
						break;
					case 3:
						temp.append("�H�w ");
						break;
					case 4:
						temp.append("���w ");
						break;
					case 5:
						temp.append("���w ");
						break;
					case 6:
						temp.append("�]�w ");
						break;
					case 7:
						temp.append("��w ");
						break;
					case 8:
						temp.append("�Ӣw ");
						break;
					case 9:
						temp.append("�K�w ");
						break;
					case 10:
						temp.append("�ۢw ");
						break;
					case 11:
						temp.append("���w ");
						break;
					case 12:
						temp.append("�X�w ");
						break;
					case 13:
						temp.append("���w ");
						break;
					case 14:
						temp.append("�L�w ");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�r �w ");
						break;
					case 1:
						temp.append("�N�w ");
						break;
					case 2:
						temp.append("�h�w ");
						break;
					case 3:
						temp.append("�H�w ");
						break;
					case 4:
						temp.append("���w ");
						break;
					case 5:
						temp.append("���w ");
						break;
					case 6:
						temp.append("�]�w ");
						break;
					case 7:
						temp.append("��w ");
						break;
					case 8:
						temp.append("�Ӣw ");
						break;
					case 9:
						temp.append("�K�w ");
						break;
					case 10:
						temp.append("�ۢw ");
						break;
					case 11:
						temp.append("���w ");
						break;
					case 12:
						temp.append("�X�w ");
						break;
					case 13:
						temp.append("���w ");
						break;
					case 14:
						temp.append("�L�w ");
						break;
					}
				}
			}
			else if (i == 5)
			{
				if (j == 0)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� �w ");
						break;
					case 1:
						temp.append("�N�w ");
						break;
					case 2:
						temp.append("�h�w ");
						break;
					case 3:
						temp.append("�H�w ");
						break;
					case 4:
						temp.append("���w ");
						break;
					case 5:
						temp.append("���w ");
						break;
					case 6:
						temp.append("�]�w ");
						break;
					case 7:
						temp.append("��w ");
						break;
					case 8:
						temp.append("�Ӣw ");
						break;
					case 9:
						temp.append("�K�w ");
						break;
					case 10:
						temp.append("�ۢw ");
						break;
					case 11:
						temp.append("���w ");
						break;
					case 12:
						temp.append("�X�w ");
						break;
					case 13:
						temp.append("���w ");
						break;
					case 14:
						temp.append("�L�w ");
						break;
					}
				}
				else if (j == 8)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� ");
						break;
					case 1:
						temp.append("�N");
						break;
					case 2:
						temp.append("�h");
						break;
					case 3:
						temp.append("�H");
						break;
					case 4:
						temp.append("��");
						break;
					case 5:
						temp.append("��");
						break;
					case 6:
						temp.append("�]");
						break;
					case 7:
						temp.append("��");
						break;
					case 8:
						temp.append("��");
						break;
					case 9:
						temp.append("�K");
						break;
					case 10:
						temp.append("��");
						break;
					case 11:
						temp.append("��");
						break;
					case 12:
						temp.append("�X");
						break;
					case 13:
						temp.append("��");
						break;
					case 14:
						temp.append("�L");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�s �w ");
						break;
					case 1:
						temp.append("�N�w ");
						break;
					case 2:
						temp.append("�h�w ");
						break;
					case 3:
						temp.append("�H�w ");
						break;
					case 4:
						temp.append("���w ");
						break;
					case 5:
						temp.append("���w ");
						break;
					case 6:
						temp.append("�]�w ");
						break;
					case 7:
						temp.append("��w ");
						break;
					case 8:
						temp.append("�Ӣw ");
						break;
					case 9:
						temp.append("�K�w ");
						break;
					case 10:
						temp.append("�ۢw ");
						break;
					case 11:
						temp.append("���w ");
						break;
					case 12:
						temp.append("�X�w ");
						break;
					case 13:
						temp.append("���w ");
						break;
					case 14:
						temp.append("�L�w ");
						break;
					}
				}
			}
			else if (i == 9)
			{
				if (j == 0)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� �� ");
						break;
					case 1:
						temp.append("�N�� ");
						break;
					case 2:
						temp.append("�h�� ");
						break;
					case 3:
						temp.append("�H�� ");
						break;
					case 4:
						temp.append("���� ");
						break;
					case 5:
						temp.append("���� ");
						break;
					case 6:
						temp.append("�]�� ");
						break;
					case 7:
						temp.append("���� ");
						break;
					case 8:
						temp.append("���� ");
						break;
					case 9:
						temp.append("�K�� ");
						break;
					case 10:
						temp.append("���� ");
						break;
					case 11:
						temp.append("���� ");
						break;
					case 12:
						temp.append("�X�� ");
						break;
					case 13:
						temp.append("���� ");
						break;
					case 14:
						temp.append("�L�� ");
						break;
					}
				}
				else if (j == 8)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� ");
						break;
					case 1:
						temp.append("�N");
						break;
					case 2:
						temp.append("�h");
						break;
					case 3:
						temp.append("�H");
						break;
					case 4:
						temp.append("��");
						break;
					case 5:
						temp.append("��");
						break;
					case 6:
						temp.append("�]");
						break;
					case 7:
						temp.append("��");
						break;
					case 8:
						temp.append("��");
						break;
					case 9:
						temp.append("�K");
						break;
					case 10:
						temp.append("��");
						break;
					case 11:
						temp.append("��");
						break;
					case 12:
						temp.append("�X");
						break;
					case 13:
						temp.append("��");
						break;
					case 14:
						temp.append("�L");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� �� ");
						break;
					case 1:
						temp.append("�N�� ");
						break;
					case 2:
						temp.append("�h�� ");
						break;
					case 3:
						temp.append("�H�� ");
						break;
					case 4:
						temp.append("���� ");
						break;
					case 5:
						temp.append("���� ");
						break;
					case 6:
						temp.append("�]�� ");
						break;
					case 7:
						temp.append("���� ");
						break;
					case 8:
						temp.append("���� ");
						break;
					case 9:
						temp.append("�K�� ");
						break;
					case 10:
						temp.append("���� ");
						break;
					case 11:
						temp.append("���� ");
						break;
					case 12:
						temp.append("�X�� ");
						break;
					case 13:
						temp.append("���� ");
						break;
					case 14:
						temp.append("�L�� ");
						break;
					}
				}
			}
			else if (1 <= i <= 3 || 6 <= i <= 8)
			{
				if (j == 8)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� ");
						break;
					case 1:
						temp.append("�N");
						break;
					case 2:
						temp.append("�h");
						break;
					case 3:
						temp.append("�H");
						break;
					case 4:
						temp.append("��");
						break;
					case 5:
						temp.append("��");
						break;
					case 6:
						temp.append("�]");
						break;
					case 7:
						temp.append("��");
						break;
					case 8:
						temp.append("��");
						break;
					case 9:
						temp.append("�K");
						break;
					case 10:
						temp.append("��");
						break;
					case 11:
						temp.append("��");
						break;
					case 12:
						temp.append("�X");
						break;
					case 13:
						temp.append("��");
						break;
					case 14:
						temp.append("�L");
						break;
					}
				}
				else if (j == 0)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� �w ");
						break;
					case 1:
						temp.append("�N�w ");
						break;
					case 2:
						temp.append("�h�w ");
						break;
					case 3:
						temp.append("�H�w ");
						break;
					case 4:
						temp.append("���w ");
						break;
					case 5:
						temp.append("���w ");
						break;
					case 6:
						temp.append("�]�w ");
						break;
					case 7:
						temp.append("��w ");
						break;
					case 8:
						temp.append("�Ӣw ");
						break;
					case 9:
						temp.append("�K�w ");
						break;
					case 10:
						temp.append("�ۢw ");
						break;
					case 11:
						temp.append("���w ");
						break;
					case 12:
						temp.append("�X�w ");
						break;
					case 13:
						temp.append("���w ");
						break;
					case 14:
						temp.append("�L�w ");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�q �w ");
						break;
					case 1:
						temp.append("�N�w ");
						break;
					case 2:
						temp.append("�h�w ");
						break;
					case 3:
						temp.append("�H�w ");
						break;
					case 4:
						temp.append("���w ");
						break;
					case 5:
						temp.append("���w ");
						break;
					case 6:
						temp.append("�]�w ");
						break;
					case 7:
						temp.append("��w ");
						break;
					case 8:
						temp.append("�Ӣw ");
						break;
					case 9:
						temp.append("�K�w ");
						break;
					case 10:
						temp.append("�ۢw ");
						break;
					case 11:
						temp.append("���w ");
						break;
					case 12:
						temp.append("�X�w ");
						break;
					case 13:
						temp.append("���w ");
						break;
					case 14:
						temp.append("�L�w ");
						break;
					}
				}
			}
		}
		// ��C��Ū�i�Ȧs�� vector <string>
		rowString[i] = temp;
	}
	// �� rowString Ū�i��Ʀ檺 chessBoard
	for (int i = 0; i < 10; i++)
	{
		Draw::chessPart[2 * i + 1] = rowString[i];
	}
	for (int i = 0; i < 21; i++)
	{
		cout << Draw::chessPart[i] << endl;
	}
}

