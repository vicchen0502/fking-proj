#include"pch.h"
#include"chess.h"
#include"Draw.h"

vector<vector<int>> Chess::chessBoard = {};

void Draw::renewChessPart()
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
	renewCarOrder();
}

void Draw::renewLeft()
{
	leftPart = initialSituation(leftPart);
	//int i
}

void Draw::renewRight()
{
	rightPart = initialRight(rightPart);
	// �᭱�A�����s
}

void Draw::renewCarOrder()
{
	carList.clear();
	for (int i = 0; i < Chess::chessBoard.size(); i++)
	{
		for (int j = 0; j < Chess::chessBoard[i].size(); j++)
		{
			if (Chess::chessBoard[i][j] == 4)
			{
				carList.push_back(0);
			}
			else if (Chess::chessBoard[i][j] == 11)
			{
				carList.push_back(1);
			}
		}
	}
}

void Draw::showOutput()
{
	string wordBlack = "�N�h�H���]��";
	string wordRed = "�ӥK���X���L";
	string car = "��";
	int count = 0;

	system("color 0f");
	cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� " << endl;
	for (int i = 0; i < 21; i++)
	{
		SetColor(15);
		cout << "�� " << leftPart[i] << "�@";
		// �ѽL����
		SetColor(240);
		for (int j = 0; j < chessPart[i].size(); j++)
		{
			if (i == 0 || i == 20)
			{
				SetColor(253);
				cout << chessPart[i][j];
			}
			else
			{
				if (find(wordRed.begin(), wordRed.end(), chessPart[i][j]) != wordRed.end())
				{
					SetColor(124);
					cout << chessPart[i][j];
				}
				else if (find(wordBlack.begin(), wordBlack.end(), chessPart[i][j]) != wordBlack.end())
				{
					SetColor(112);
					cout << chessPart[i][j];
				}
				else if (find(car.begin(), car.end(), chessPart[i][j]) != car.end())
				{
					if (carList[count] == 0)
					{
						SetColor(112);
						cout << chessPart[i][j];
						count++;
					}
					else if (carList[count] == 1)
					{
						SetColor(124);
						cout << chessPart[i][j];
						count++;
					}
				}
				else
				{
					SetColor(240);
					cout << chessPart[i][j];
				}
			}
		}
		SetColor(15);
		cout << "�@" << rightPart[i] << "�@�� " << endl;
	}
	cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� " << endl;
}

void Draw::showHint(vector<vector<int>>legalList)
{
	SetColor(208);
	for (int i = 0; i < legalList.size(); i++)
	{
		string word = "�N�h�H���]��ӥK���X���L��";
		//string sign = "�q�r�s������������";

		int x = legalList[i][0];
		int y = legalList[i][1];

		int X = (y * 4) + 30;
		int Y = (x * 2) + 2;

		gotoxy(X, Y);
		if (Chess::chessBoard[x][y] == 0 && y == 0)
		{
			if (x == 0)
			{
				cout << "�� " << endl;
			}
			else if (x == 9)
			{
				cout << "�� " << endl;
			}
			else
			{
				cout << "�� " << endl;
			}
		}
		else if (Chess::chessBoard[x][y] == 0 && y == 8)
		{
			if (x == 0)
			{
				cout << "�� " << endl;
			}
			else if (x == 9)
			{
				cout << "�� " << endl;
			}
			else
			{
				cout << "�� " << endl;
			}
		}
		else if (Chess::chessBoard[x][y] == 0)
		{
			cout << "�q " << endl;
		}
		else
		{
			switch (Chess::chessBoard[x][y])
			{
			case 1:
				cout << "�N" << endl;
				break;
			case 2:
				cout << "�h" << endl;
				break;
			case 3:
				cout << "�H" << endl;
				break;
			case 4:
				cout << "��" << endl;
				break;
			case 5:
				cout << "��" << endl;
				break;
			case 6:
				cout << "�]" << endl;
				break;
			case 7:
				cout << "��" << endl;
				break;
			case 8:
				cout << "��" << endl;
				break;
			case 9:
				cout << "�K" << endl;
				break;
			case 10:
				cout << "��" << endl;
				break;
			case 11:
				cout << "��" << endl;
				break;
			case 12:
				cout << "�X" << endl;
				break;
			case 13:
				cout << "��" << endl;
				break;
			case 14:
				cout << "�L" << endl;
				break;
			}
		}
	}
}
