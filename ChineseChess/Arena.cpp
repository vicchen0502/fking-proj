#include "pch.h"
#include "Arena.h"
using namespace std;

void Arena::readInShowingMap()
{
	fstream fin;
	fin.open("chessBoard.txt");
	if (!fin.is_open())
		cout << "fail" << endl;
	for(int j = 0;j < 21;j++)
	{
		char lines[1000];
		fin.getline(lines,1000);
		showingMap.push_back(lines);
	}
	
}
void Arena::showMap()
{
	for (int i = 0; i < showingMap.size(); i++)
	{
		for (int j = 0; j < showingMap[i].size(); j++)
		{

			wcout << showingMap[i][j];
		}
		cout << endl;
	}
}

void Arena::readInMap(string loadGame)
{
	ifstream fin(loadGame);
	for (int i = 0; i < 10; i++)
	{
		vector<Chess>row(9);
		for (int j = 0; j < 9; j++)
		{
			int inputData = 0;
			fin >> inputData;
			cout << inputData << " ";
			switch (inputData)
			{
			case 1:
			{
				King c(inputData, true, i, j);
				row.push_back(c);
				break;
			}
			case 2:
			{
				Counselor c(inputData, true, i, j);
				row.push_back(c);
				break;
			}
			case 3:
			{
				Elephant c(inputData, true, i, j);
				row.push_back(c);
				break;
			}
			case 4:
			{
				Car c(inputData, true, i, j);
				row.push_back(c);
				break;
			}
			case 5:
			{
				Horse c(inputData, true, i, j);
				row.push_back(c);
				break;
			}
			case 6:
			{
				Cannon c(inputData, true, i, j);
				row.push_back(c);
				break;
			}
			case 7:
			{
				Soldier c(inputData, true, i, j);
				row.push_back(c);
				break;
			}
			case 8:
			{
				King c(inputData, true, i, j);
				row.push_back(c);
				break;
			}
			case 9:
			{
				Counselor c(inputData, true, i, j);
				row.push_back(c);
				break;
			}
			case 10:
			{
				Elephant c(inputData, true, i, j);
				row.push_back(c);
				break;
			}
			case 11:
			{
				Car c(inputData, true, i, j);
				row.push_back(c);
				break;
			}
			case 12:
			{
				Horse c(inputData, true, i, j);
				row.push_back(c);
				break;
			}
			case 13:
			{
				Cannon c(inputData, true, i, j);
				row.push_back(c);
				break;
			}
			case 14:
			{
				Soldier c(inputData, true, i, j);
				row.push_back(c);
				break;
			}
			default:
				Chess c(0, false, i, j);
				row.push_back(c);
				break;
			}
		}
		cout << endl;
		map.push_back(row);
	}
}